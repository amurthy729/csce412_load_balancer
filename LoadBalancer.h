#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "Request.h"
#include "Webserver.h"
#include <queue>
#include <vector>

/**
 * @class LoadBalancer
 * @brief A class to manage the distribution of network requests to web servers.
 */
class LoadBalancer
{
private:
    std::queue<Request> requests;   ///< Queue of incoming requests.
    std::vector<Webserver> servers; ///< List of web servers.

public:
    /**
     * @brief Assign a request to the least busy server.
     */
    void assignRequest();

    /**
     * @brief Add a request to the requests queue.
     *
     * @param rq The request to be added.
     */
    void addRequest(Request rq);

    /**
     * @brief Add a web server to the server list.
     *
     * @param ws The web server to be added.
     */
    void addServer(Webserver ws);

    /**
     * @brief Get the number of requests remaining in the queue.
     *
     * @return The number of requests remaining.
     */
    int requestsRemaining();

    /**
     * @brief Command all servers to perform one cycle of work.
     */
    void work();
};

#endif // LOADBALANCER_H
