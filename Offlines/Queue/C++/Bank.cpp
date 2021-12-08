#include <cstdlib>
#include <iostream>

#include "Arr.hpp"
#include "LL.hpp"
using namespace std;

#define endl "\n"

const bool isCommentOn = false;
int current_time, idx, done;
int* enter_time;
int* service_time;

class Event;

class Event {
 public:
  int service_start_time;
  bool firstQueue;
  int index;
  Event(int index = -1, int service_start_time = -1, bool firstQueue = true) {
    this->index = index;
    this->service_start_time = service_start_time;
    this->firstQueue = firstQueue;
  }
  Event toggle() {
    firstQueue ^= 1;
    return *this;
  }
};

void startService(Queue<Event>& q, int& next_finish, bool& isOn, int which) {
  int id = q.frontValue().index;
  next_finish = current_time + service_time[id];
  isOn = true;
  if (isCommentOn) {
    cout << "Time " << current_time << ": Person " << id + 1
         << " has started taking service in queue " << which << endl;
  }
}

void finishService(Queue<Event>& my, Queue<Event>& other, int& lastTime,
                   bool& isOn, int which) {
  int id = my.dequeue().index;
  if (isCommentOn) {
    cout << "Time " << current_time << ": Person " << id + 1
         << " has finished from queue " << which << endl;
  }
  done++;
  lastTime = current_time;
  isOn = false;

  // checking queue switching
  while (other.length() - my.length() >= 2) {
    auto leave = other.leaveQueue();
    if (isCommentOn)
      cout << "Time " << current_time << ": Person " << leave.index + 1
           << " has switched to queue " << which << endl;
    my.enqueue(leave.toggle());
  }
}

int main() {
  int n;
  cin >> n;
  enter_time = new int[n];
  service_time = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> enter_time[i] >> service_time[i];
  }

  AQueue<Event> q1;
  //   LLQueue<Event> q1;
  AQueue<Event> q2;
  //   LLQueue<Event> q1;
  int q1_next = -1, q2_next = -1;
  int q1_last_time = -1, q2_last_time = -1;
  bool q1_on = false, q2_on = false;

  while (done < n) {
    if (idx < n) {
      if (current_time == enter_time[idx]) {
        Event e(idx);
        if (q1.length() <= q2.length()) {
          q1.enqueue(e);
          if (isCommentOn)
            cout << "Time " << current_time << ": Person " << idx + 1
                 << " has entered queue 1" << endl;
        } else {
          q2.enqueue(e.toggle());
          if (isCommentOn)
            cout << "Time " << current_time << ": Person " << idx + 1
                 << " has entered queue 2" << endl;
        }
        idx++;
      }
    }

    if (!q1_on && q1.length() > 0) startService(q1, q1_next, q1_on, 1);
    if (!q2_on && q2.length() > 0) startService(q2, q2_next, q2_on, 2);

    if (q1_on && current_time == q1_next) {
      finishService(q1, q2, q1_last_time, q1_on, 1);
      if (q1.length() > 0) startService(q1, q1_next, q1_on, 1);
    }

    if (q2_on && current_time == q2_next) {
      finishService(q2, q1, q2_last_time, q2_on, 2);
      if (q2.length() > 0) startService(q2, q2_next, q2_on, 2);
    }
    int min_val =
        min(min(q1_next, q2_next), (idx < n ? enter_time[idx] : INT_MAX));
    if (min_val > current_time)
      current_time = min_val;
    else
      current_time++;
  }

  cout << "Booth 1 finishes service at t=" << q1_last_time << endl;
  cout << "Booth 2 finishes service at t=" << q2_last_time << endl;

  delete[] service_time;
  delete[] enter_time;

  return 0;
}