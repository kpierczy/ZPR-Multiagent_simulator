/**
 * @file Listener.h
 * @author Wojtek Rokicki & Krzysiek Pierczyk
 * @brief Listener class' declaration
 * @version 0.1
 * @date 2020-01-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef HTTP_LISTENER_H
#define HTTP_LISTENER_H

#include <memory>
#include <string>
#include <boost/system/error_code.hpp>
#include <boost/asio.hpp>

#include "Server.h"

class ListenerTest;

/**
 * @brief Listener is designed to listen on the pointed socket and create new
 *        sessions when a new request aproaches
 */
class Server::Listener : public std::enable_shared_from_this<Listener>
{
// Constructors
public:
    Listener(Server& server);

// Interface
public:
    void run();

// Private Friends
private:
    friend class ListenerTest;

// Private members
private:
    /// Acceptor of the connection
    boost::asio::ip::tcp::acceptor __acceptor;

    /// Socket used by acceptor to connect to a new client
    boost::asio::ip::tcp::socket __socket;
    
    /// Server that created Listener
    Server& __server;

// Private member methods
private:
    void __on_accept(const boost::system::error_code& err_code);
    bool __fail(const boost::system::error_code& err_code, char const* what);
};

#endif