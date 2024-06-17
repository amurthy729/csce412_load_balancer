#include <stdlib.h>
#include "Request.h"

/**
 * @brief Construct a new Request::Request object.
 *
 * Initializes the input and output IP addresses with random values between 0-255.
 * Sets the time to process the request to a random value between 5 and 1004.
 */
Request::Request()
{
    a1 = rand() % 256;
    a2 = rand() % 256;
    a3 = rand() % 256;
    a4 = rand() % 256;
    b1 = rand() % 256;
    b2 = rand() % 256;
    b3 = rand() % 256;
    b4 = rand() % 256;
    time = rand() % 1000 + 5; // between 5 and 1004 clock cycles
}

std::vector<int> Request::get_IP_in()
{
    std::vector<int> ip = {a1, a2, a3, a4};
    return ip;
}

std::vector<int> Request::get_IP_out()
{
    std::vector<int> ip = {b1, b2, b3, b4};
    return ip;
}

int Request::get_time()
{
    return time;
}

void Request::time_dec()
{
    time--;
}

bool Request::complete()
{
    return time <= 0;
}
