#include "Webserver.h"

Webserver::Webserver(int id)
{
    serverID = id;
}

void Webserver::work()
{
    if (!requests.empty())
    {
        std::vector<int> completed;
        // first we should do one cycle of work on each request, keeping track of when a request completes
        int removed = 0;
        for (long unsigned int i = 0; i < requests.size(); i++)
        {
            requests[i].time_dec();
            if (requests[i].complete())
            {
                completed.push_back(i);
            }
        }
        // next, remove all the processes that completed
        for (int i : completed)
        {
            requests.erase(requests.begin() + i - removed);
            removed++; // we need to do this because, when we remove an element, the vector decreases by a size of 1, so indexes also decrease
        }
    }
}

void Webserver::acceptRequest(Request rq)
{
    requests.push_back(rq);
}

int Webserver::connections()
{
    return requests.size();
}
