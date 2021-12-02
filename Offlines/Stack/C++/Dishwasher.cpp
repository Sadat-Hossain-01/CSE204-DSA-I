#include <iostream>
#include <cstdlib>
#include "AStack.hpp"
#include "LLStack.hpp"
using namespace std;

#define endl "\n"

class Event{
private:
    int person_idx;
    int pushed_time;
    int course_idx;
    public:
        Event(int pi=-1, int pt=-1, int ci=-1){
            person_idx = pi;
            pushed_time = pt;
            course_idx = ci;
        }
};

int main()
{
    int invitees, courses;
    cin >> invitees >> courses;
    int* time = new int[courses];
    int* cnt = new int[invitees];
    for (int i=0; i<courses; i++){
        cin >> time[i];
    }
    Stack<Event>* all = new AStack<Event>();
//    Stack<Event>* all = new LLStack();
    while (true){
        int friend_idx, time, course_idx;
        cin >> friend_idx >> time >> course_idx;
        cnt[friend_idx-1]++;
        auto now = new Event(friend_idx, time, course_idx);
        all->push(*now);
        delete now;
    }
    delete[] cnt;
    delete[] time;
    return 0;
}
