#include "Server.hpp"
#include  <iostream>
#include <memory>


Server::Server(std::string ip_adress,int port)
    :m_ip_adress(ip_adress)
    ,m_port(port) 
{
}

void Server::createSocket() {
    m_socket = socket(AF_INET,SOCK_STREAM,0);
    if(m_socket == -1 ) {
        std::cerr<<"Can't create socket!"<<std::endl;
    }
}

void Server::doBinding(){
    m_serverAddress.sin_family = AF_INET;
    inet_pton(AF_INET, m_ip_adress.c_str(), (struct sockaddr*)&m_serverAddress.sin_addr);
    m_serverAddress.sin_port = htons(m_port);
    if(bind(m_socket,(struct sockaddr *)&m_serverAddress, sizeof(m_serverAddress)) == -1) {
        std::cerr<<"Can't bind IP/Port";
    }

}

void Server::listenToClients(int maxNumberOfClients) {
    bool listening = (listen(m_socket, maxNumberOfClients) !=-1);
    if(!listening)
    {
        std::cerr<<"Can't listen"<<std::endl;
    }
}

void Server::acceptClients() {
    fd_set rfds;
    struct timeval timeValue;
    int retValSelect;
    timeValue.tv_sec = 0;
    timeValue.tv_usec = 0;
    FD_ZERO(&rfds);
    FD_SET(m_socket,&rfds);
    retValSelect = select(m_socket+1, &rfds,nullptr,nullptr,&timeValue);
    if(FD_ISSET(m_socket,&rfds))
    {
        socklen_t clientSize = sizeof(m_clientAddress);
        m_clientSocket = accept(m_socket,(struct sockaddr*)&m_clientAddress,&clientSize);
        if(m_clientSocket == -1) {
        std::cerr << "Can't accept new client";
        }
    }


}

int Server::receiveFromClient(char *msg) {
    int receivedBytes = recv(m_clientSocket,msg,sizeof(msg),0);
    return receivedBytes;
}

void Server::clearBuffer() {
}

void Server::init() {
    createSocket();
    doBinding();
    //listenToClients(maxNumberOfclients);
    //acceptClients();
}

Server::~Server() {
}

void Server::closeConnection() {
    int closed = close(m_socket);    
}

