#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

////////////////////////////////////////////////////////////////////////////////////
// ClientHandler.h -Package for Client Handler which is sent as a functor to socket //
// Ver 1.0                                                      //
// Language:    Visual C++, Visual Studio 2013					//
// Platform:    Lenovo V570, Core i5, Windows 7 SP2	           //
// Application: Object Oriented Design,Project-3 2015          //
// Author:      Tanmay Fadnavis, Syracuse University		   //
//				315-560-3370, tfadnavi@syr.edu				  //
// Date: 13/04/2015											//
///////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package is intended to receive messges and receive files.
*
* Required Files:
* ---------------
*   MessageInterpreter.h Sockets.h ClientHandler.h
*	ClientHandler.cpp
*
* Public Interfaces:
* -----------------
*	void operator()(Socket& socket_);
*	MessageInterpreter receiveHeader(Socket& socket_);
*	bool receiveFile(MessageInterpreter msg,Socket& socket_);
*
* Build Process:
* --------------
*   devenv Peer1.sln /debug rebuild
*
* Maintenance History:
* --------------------
*
* Ver 1.0 : 13 April 15
* - first release
*/

#include"Sockets.h"
#include"MessageInterpreter.h"



class ClientHandler
{
	public:
		void operator()(Socket& socket_);
		MessageInterpreter receiveHeader(Socket& socket_);
		bool receiveFile(MessageInterpreter msg,Socket& socket_);

};


#endif