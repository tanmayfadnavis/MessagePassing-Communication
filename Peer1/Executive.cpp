///////////////////////////////////////////////////////////////////
// Executive.cpp -Package for sending messages through sockets//
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
* This is the entry point for the application, Message Communication.
* It initiates a receiver, so that a peer can receive message.
* It initiates a sender and sendes message to another peer.
*
* Required Files:
* ---------------
*   MessageInterpreter.h Sender.h Receiver.h
*
* Public Interfaces:
* -----------------
*	int main(int argc,char *argv[])
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

#include"MessageInterpreter.h"
#include"Sender.h"
#include"Receiver.h"




int main(int argc,char *argv[])
{
	int port = std::stoi(argv[1]);
	//std::cout << "The port is" << port;
	Receiver r(port);

	//int sendTo = std::stoi(argv[2]);

	std::string path = "";

	if (std::stoi(argv[1]) == 9080)
	{
		//std::cout << "in 9080\n";
		path = "../ClientFile/Testing1.txt";
	}
		

	if (std::stoi(argv[1]) == 9081)
	{
		//std::cout << "In 9081\n";
		path = "../ClientFile/Testing2.txt";
	}



	MessageInterpreter msg("File_Upload", argv[1], argv[2], path);
	Sender *s=new Sender();
	s->send(msg);

	Verbose::show("press key to exit: ", always);
	std::cout.flush();
	std::cin.get();

	
}