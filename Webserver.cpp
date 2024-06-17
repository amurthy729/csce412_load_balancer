#include "Webserver.h"
#include <iostream>

/**
 * @brief Construct a new Webserver::Webserver object.
 *
 * @param id The identifier for the server.
 */
Webserver::Webserver(int id) : serverID(id) {}

/**
 * @brief Perform one cycle of work on the requests.
 *
 * Processes each request by decrementing its remaining time and removes completed requests.
 */
void Webserver::work()
{
    if (!requests.empty())
    {
        std::vector<int> completed;
        int removed = 0;

        for (long unsigned int i = 0; i < requests.size(); i++)
        {
            requests[i].time_dec();
            if (requests[i].complete())
            {
                completed.push_back(i);
            }
        }

        for (int i : completed)
        {
            requests.erase(requests.begin() + i - removed);
            removed++;
        }
    }
}

/**
 * @brief Accept a new request and add it to the request list.
 *
 * @param rq The request to be accepted.
 */
void Webserver::acceptRequest(Request rq)
{
    if (requests.size() < MAX_CONNECTIONS)
    {
        requests.push_back(rq);
        std::cout << "Webserver " << serverID << " accepted request of time " << rq.get_time() << std::endl;
        std::vector<int> IP = rq.get_IP_in();
        std::cout << "Incoming IP: " << IP[0] << "." << IP[1] << "." << IP[2] << "." << IP[3] << std::endl;
        IP = rq.get_IP_out();
        std::cout << "Outgoing IP: " << IP[0] << "." << IP[1] << "." << IP[2] << "." << IP[3] << std::endl;
    }
}

/**
 * @brief Get the current number of connections (requests being processed).
 *
 * @return The current number of connections.
 */
int Webserver::connections()
{
    return requests.size();
}
