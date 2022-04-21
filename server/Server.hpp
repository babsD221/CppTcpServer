#ifndef SERVER
#define SERVER


#include <sys/types.h> 
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <vector>


class Server 
{
    public:
    Server(std::string ip_adress,int port);
    ~Server();
    void init();
    void listenToClients(int maxNumberOfClients);
    void acceptClients();
    void closeConnection();
    void sendMessage(int clientSocket,std::string msg);
    void clearBuffer();
    int receiveFromClient(char * msg);

private:
    void createSocket();
    void doBinding();


    private:
    struct sockaddr_in m_serverAddress;
    struct sockaddr_in m_clientAddress;

    int m_socket;
    int m_clientSocket;
    std::string m_ip_adress;
    int m_port;
};
#endif