#include "LoadBalancer.h"

void LoadBalancer::assignRequest()
{
    if (!requests.empty())
    {
        int serverIndex = 0;
        int connections = servers.front().connections();
        for (long unsigned int i = 0; i < servers.size(); i++)
        {
            if (servers[i].connections() < connections)
            {
                serverIndex = i;
            }
        }
        if (servers[serverIndex].connections() < MAX_CONNECTIONS)
        {
            servers[serverIndex].acceptRequest(requests.front());
        }
    }
}

void LoadBalancer::addRequest(Request rq)
{
    requests.push(rq);
}

void LoadBalancer::addServer(Webserver ws)
{
    servers.push_back(ws);
}

int LoadBalancer::requestsRemaining()
{
    return requests.size();
}
