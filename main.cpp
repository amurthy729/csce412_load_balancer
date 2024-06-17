#include <iostream>
#include "LoadBalancer.h"

LoadBalancer lb;

int main()
{
    int servers, time;
    std::cout << "How many servers?: ";
    std::cin >> servers;
    std::cout << "How much time (clock cylces)?: ";
    std::cin >> time;
    std::cout << "Servers: " << servers << " Time: " << time << std::endl;
    // initialize servers
    for (int i = 0; i < servers; i++)
    {
        Webserver s = Webserver(i + 1);
        lb.addServer(s);
    }
    // generate a full queue
    for (int i = 0; i < servers * 10; i++)
    {
        Request r = Request();
        lb.addRequest(r);
    }
    // run for time amount of clock cycles
    for (int i = 0; i < time; i++)
    {
        int random = rand() % 4; // 1 in 4 chance to add a new request
        if (random == 0)
        {
            Request r = Request();
            lb.addRequest(r);
        }
        lb.assignRequest();
    }
    std::cout << "Requests Outstanding: " << lb.requestsRemaining() << std::endl;
    return 0;
}