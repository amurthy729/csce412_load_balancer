#include <iostream>
#include "LoadBalancer.h"

/**
 * @brief Main function to simulate the load balancer and web servers.
 *
 * Prompts the user to input the number of servers and the amount of time (in clock cycles) for the simulation.
 * Initializes the servers and generates a full queue of requests.
 * Runs the simulation for the specified number of clock cycles, periodically adding new requests and
 * processing the existing ones.
 *
 * @return int Returns 0 upon successful execution.
 */
int main()
{
    LoadBalancer lb;
    int servers, time;

    std::cout << "How many servers?: ";
    std::cin >> servers;
    std::cout << "How much time (clock cycles)?: ";
    std::cin >> time;
    std::cout << "Servers: " << servers << " Time: " << time << std::endl;

    // Initialize servers
    for (int i = 0; i < servers; i++)
    {
        Webserver s = Webserver(i + 1);
        lb.addServer(s);
    }

    // Generate a full queue
    for (int i = 0; i < servers * 10; i++)
    {
        Request r = Request();
        lb.addRequest(r);
    }

    // Run for the specified amount of clock cycles
    for (int i = 0; i < time; i++)
    {
        int random = rand() % 25; // 1 in 25 chance to add a new request
        if (random == 0)
        {
            Request r = Request();
            lb.addRequest(r);
        }
        lb.assignRequest();
        lb.work();
    }

    std::cout << "Requests Outstanding: " << lb.requestsRemaining() << std::endl;
    return 0;
}
