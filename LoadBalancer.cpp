#include "LoadBalancer.h"

/**
 * @brief Assign a request to the least busy server.
 *
 * Finds the server with the fewest connections and assigns the next request from the queue to that server,
 * if the server has capacity to handle more connections.
 */
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
                connections = servers[i].connections();
            }
        }
        if (servers[serverIndex].connections() < MAX_CONNECTIONS)
        {
            servers[serverIndex].acceptRequest(requests.front());
            requests.pop();
        }
    }
}

/**
 * @brief Add a request to the requests queue.
 *
 * @param rq The request to be added.
 */
void LoadBalancer::addRequest(Request rq)
{
    requests.push(rq);
}

/**
 * @brief Add a web server to the server list.
 *
 * @param ws The web server to be added.
 */
void LoadBalancer::addServer(Webserver ws)
{
    servers.push_back(ws);
}

/**
 * @brief Get the number of requests remaining in the queue.
 *
 * @return The number of requests remaining.
 */
int LoadBalancer::requestsRemaining()
{
    return requests.size();
}

/**
 * @brief Command all servers to perform one cycle of work.
 */
void LoadBalancer::work()
{
    for (auto &server : servers)
    {
        server.work();
    }
}
