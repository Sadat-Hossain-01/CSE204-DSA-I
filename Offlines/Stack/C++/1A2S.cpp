#include <iostream>
#include <climits>
#include "Arr.hpp"
#include "LL.hpp"
using namespace std;

#define endl "\n"

class Event
{
public:
    int person_idx;
    int pushed_time;
    int course_idx;
    int finish_time;
    Event(int pi = -1, int pt = -1, int ci = -1, int ft = -1)
    {
        person_idx = pi;
        pushed_time = pt;
        course_idx = ci;
        finish_time = ft;
    }
};

template <typename T>
void printCommaSeparatedStack(Stack<T> &stc)
{
    bool isFirst = true;
    while (stc.length() > 0)
    {
        if (!isFirst)
            cout << ",";
        else
            isFirst = false;
        cout << stc.pop();
    }
    return;
}

int main()
{
    int invitees, courses;
    cin >> invitees >> courses;
    int *courseTimes = new int[courses + 1];
    int *cnt = new int[invitees + 1];
    for (int i = 1; i <= courses; i++)
    {
        cin >> courseTimes[i];
    }

    AStack<int> completingPeople;
    //    LLStack<int> completingPeople;

    Event *allEvents = new Event[20];
    int sz = 20;
    int len = 0;
    int dish_count = 0;

    int last_completed_time = -1;
    while (true)
    {
        int friend_index, current_time, course_idx;
        cin >> friend_index >> current_time >> course_idx;
        if (friend_index == 0)
            break;
        dish_count++;
        Event latest(friend_index, current_time, course_idx);
        cnt[friend_index]++;
        if (cnt[friend_index] == courses)
            completingPeople.push(friend_index);
        if (len < sz)
        {
            allEvents[len++] = latest;
        }
        else
        {
            sz *= 2;
            Event *tempArr = new Event[sz];
            for (int i = 0; i < len; i++)
            {
                tempArr[i] = allEvents[i];
            }
            tempArr[len++] = latest;
            delete[] allEvents;
            allEvents = tempArr;
        }
    }

    Event *arrToPass = new Event[invitees * courses];

    AStack<Event> dirtyStack(0, invitees * courses, arrToPass, 1);
    AStack<Event> cleanStack(0, invitees * courses, arrToPass, -1);

    int cur_time = 0;
    int event_idx = 0;
    int cleaned = 0;
    int next_finish = -1;
    bool isCleaningOn = false;
    while (cleaned < dish_count)
    {
        if (event_idx < dish_count)
        {
            int pt = allEvents[event_idx].pushed_time;

            if (pt == cur_time)
            {
                dirtyStack.push(allEvents[event_idx++]);
            }
        }

        if (!isCleaningOn && dirtyStack.length() > 0)
        {
            auto to_clean = dirtyStack.pop();
            next_finish = cur_time + courseTimes[to_clean.course_idx] - 1;
            to_clean.finish_time = next_finish;
            cleanStack.push(to_clean);
            cout << "Time: " << cur_time << " Cleaning Started."
                 << " " << to_clean.person_idx << " " << to_clean.pushed_time << " " << to_clean.course_idx << " ";
            isCleaningOn = true;
        }

        if (isCleaningOn && cur_time == next_finish)
        {
            cout << "Cleaning Finished. Time: " << cur_time << endl;
            cleaned++;
            isCleaningOn = false;
        }
        auto min_val = min(next_finish, (event_idx < dish_count ? allEvents[event_idx].pushed_time : INT_MAX));
        if (min_val <= cur_time)
            cur_time++;
        else
            cur_time = min_val;
    }

    cout << cleanStack.topValue().finish_time << endl;
    AStack<int> temp;
    //    LLStack<int> temp;
    while (cleanStack.length() > 0)
    {
        temp.push(cleanStack.pop().finish_time);
    }
    printCommaSeparatedStack(temp);
    cout << endl
         << (completingPeople.length() == invitees ? "Y" : "N") << endl;
    printCommaSeparatedStack(completingPeople);

    //    delete[] arrToPass;
    delete[] allEvents;
    delete[] cnt;
    delete[] courseTimes;

    return 0;
}
