#ifndef REQUEST_H
#define REQUEST_H

#include <vector>

/**
 * @class Request
 * @brief Represents a network request with input and output IP addresses and processing time.
 */
class Request
{
private:
    int a1, a2, a3, a4; ///< IPv4 address (input) as four integers.
    int b1, b2, b3, b4; ///< IPv4 address (output) as four integers.
    int time;           ///< Time to process the request.

public:
    /**
     * @brief Construct a new Request object with random IP addresses and processing time.
     */
    Request();

    /**
     * @brief Get the input IP address.
     * @return A vector containing the four integers of the input IP address.
     */
    std::vector<int> get_IP_in();

    /**
     * @brief Get the output IP address.
     * @return A vector containing the four integers of the output IP address.
     */
    std::vector<int> get_IP_out();

    /**
     * @brief Get the remaining processing time.
     * @return The remaining processing time.
     */
    int get_time();

    /**
     * @brief Decrease the processing time by 1.
     */
    void time_dec();

    /**
     * @brief Check if the request is complete.
     * @return True if the request is complete, false otherwise.
     */
    bool complete();
};

#endif // REQUEST_H
