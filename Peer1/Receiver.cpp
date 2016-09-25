///////////////////////////////////////////////////////////////////
// Receiver.cpp -Package for receiving messages through Sockets		//
// version 1.0													//
// Language:    Visual C++, Visual Studio 2013                   //
// Platform:    Lenovo V570, Core i5, Windows 7 SP2	              //
// Application: Object Oriented Design,Project-3 2015             //
// Author:      Tanmay Fadnavis, Syracuse University				//
//				315-560-3370, tfadnavi@syr.edu						//
////////////////////////////////////////////////////////////////////// 
///////////////////////////////////////////////////////////////////

#include"Receiver.h"
#include"ClientHandler.h"
#include <condition_variable>
#include <mutex>
#include <thread>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include <thread>

using namespace ApplicationHelpers;


//--------------<The parameterized constructor for receiver. It takes the port number as input and initiates
//				 ClientHandler>---------------------------------------------------------------------------
Receiver::Receiver(int port)
{
	std::cout << "Receiver starting for port" << port;
	Verbose v(true);
	//SocketSystem ss;
	//SocketListener sl(port, Socket::IP4);
	
	sl = new SocketListener(port, Socket::IP6);

	sl->start(cp);

	std::thread dispatcher(&Receiver::receiverMessage, this);
	dispatcher.detach();

}

void Receiver::receiverMessage()
{
	//Main Dispatcher which would be highly used in Pr#4.
	//Verbose::show("MESSAGE TESTING");

}

void Receiver::enqueue(MessageInterpreter msg)
{
	receiverQue.enQ(msg);
}

#ifdef TEST_RECEIVER
int main()
{
	Receiver r(9080);

}


#endif