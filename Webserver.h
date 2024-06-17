#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <vector>
#include "Request.h"

#define MAX_CONNECTIONS 10 ///< Maximum number of connections the webserver can handle.

/**
 * @class Webserver
 * @brief A class to represent a web server that handles network requests.
 */
class Webserver
{
private:
    int serverID;                  ///< Identifier for the server.
    std::vector<Request> requests; ///< List of requests to be processed.

public:
    /**
     * @brief Construct a new Webserver object.
     *
     * @param id The identifier for the server.
     */
    Webserver(int id);

    /**
     * @brief Perform one cycle of work on the requests.
     *
     * Processes each request by decrementing its remaining time and removes completed requests.
     */
    void work();

    /**
     * @brief Accept a new request and add it to the request list.
     *
     * @param rq The request to be accepted.
     */
    void acceptRequest(Request rq);

    /**
     * @brief Get the current number of connections (requests being processed).
     *
     * @return The current number of connections.
     */
    int connections();
};

#endif // WEBSERVER_H
