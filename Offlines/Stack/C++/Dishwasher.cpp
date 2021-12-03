#include <iostream>
#include <cstdlib>
#include "AStack.hpp"
#include "LLStack.hpp"
using namespace std;

#define endl "\n"

class Event
{
public:
    int person_idx;
    int pushed_time;
    int course_idx;
    Event(int pi=-1, int pt=-1, int ci=-1)
    {
        person_idx = pi;
        pushed_time = pt;
        course_idx = ci;
    }
};

int main()
{
    int invitees, courses;
    cin >> invitees >> courses;
    int* courseTimes = new int[courses + 1];
    int* cnt = new int[invitees + 1];
    for (int i=1; i<=courses; i++)
    {
        cin >> courseTimes[i];
    }

    Stack<int>* completingPeople = new AStack<int>();
//    Stack<int>* completingPeople = new LLStack<int>();

    Event* allEvents = new Event[20];
    int sz = 20;
    int len = 0;
    int event_cnt = 0;

    int last_completed_time = -1;
    while (true)
    {
        int friend_index, current_time, course_idx;
        cin >> friend_index >> current_time >> course_idx;
        if (friend_index == 0) break;
        event_cnt++;
        Event* latest = new Event(friend_index, current_time, course_idx);
        cnt[friend_index]++;
        if (cnt[friend_index] == courses) completingPeople->push(friend_index);
        if (len < sz)
        {
            allEvents[len++] = *latest;
        }
        else
        {
            sz *= 2;
            Event* temp = new Event[sz];
            for (int i=0; i<len; i++)
            {
                temp[i] = allEvents[i];
            }
            temp[len++] = *latest;
            delete[] allEvents;
            allEvents = temp;
        }
    }

    Stack<Event>* dirtyStack = new AStack<Event>();
//    Stack<Event>* dirtyStack = new LLStack<Event>();
    Stack<Event>* cleanStack = new AStack<Event>();
//    Stack<Event>* cleanStack = new LLStack<Event>();

    int cur_time = 0;
    int event_idx = 0;
    int next_finish = -1;
    bool isCleaningOn = false;
    while (cleanStack->length() < event_cnt)
    {
        if (event_idx < event_cnt)
        {
            int pt = allEvents[event_idx].pushed_time;
            int ci = allEvents[event_idx].course_idx;
            int pi = allEvents[event_idx].person_idx;

            if (pt == cur_time)
            {
                dirtyStack->push(allEvents[event_idx++]);
            }
        }

        if (!isCleaningOn && dirtyStack->length() > 0)
        {
            auto to_clean = dirtyStack->topValue();
            cout << "Cleaning Started. Time: " << cur_time << " Time to finish: " courseTimes[to_clean.course_idx] << " ";
            next_finish = cur_time + courseTimes[to_clean.course_idx] - 1;
            isCleaningOn = true;
        }

        if (cur_time == next_finish && dirtyStack->length() > 0)
        {
            auto last = dirtyStack->pop();
            cleanStack->push(last);
            cout << "Cleaning Finished. Time: " << cur_time << endl;
            isCleaningOn = false;
        }
        cur_time++;
    }



    delete cleanStack;
    delete dirtyStack;
    delete[] allEvents;
    delete completingPeople;
    delete[] cnt;
    delete[] courseTimes;

    return 0;
}
