#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <vector>
#include "Request.h"
#define MAX_CONNECTIONS 10
class Webserver
{
private:
    int serverID;                  // what server is this
    std::vector<Request> requests; // requests to be done
public:
    Webserver(int id);
    void work();                    // does 1 cycle of work
    void acceptRequest(Request rq); // needs parameter since we're accepting a request object
    int connections();              // returns current number of connections
};

#endif