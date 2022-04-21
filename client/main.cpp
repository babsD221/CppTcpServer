#include <iostream>
#include "Client.hpp"


int main(int argc, char const *argv[])
{
    TcpClient client;
    client.init();
    std::string userInput;
    while(1)
    {
        std::cout <<" >";
        std::getline(std::cin,userInput);
        client.sendMessage(userInput);
    }
    client.closeConnection();
    return 0;
}
