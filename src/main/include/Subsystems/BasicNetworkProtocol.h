// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef BASICNETWORKPROTOCOL_H
#define BASICNETWORKPROTOCOL_H

#define BNP_VER 1.0
#define PROT_VER 1
#define BN_PORT 663             //Default Port number
#define MAXDATASIZE 1024        //Max data in bytes
#define BN_AFIP AF_INET         //ipv4(inet) or ipv6(inet6)
#define BN_PROT SOCK_STREAM     //tcp(stream) or udp (dpack)

#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"

#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
/**
 *
 *
 * @author daggerwolf45
 */
class BasicNetworkProtocol: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	 //Data transfer
    int sendData(string type, string name, string data);
    int recvData(int sock);
    int putData(string data);
    
    //Compresion stuffs
    string compress(string data, int compresionAlg);
    string uncompress(string compressedData, int compresionAlg);
        
    //Encryption stuffs
    int genKey();
    int initHandshake(int sock);
    int recvHandshake(int sock);
    string encrypt(string data, int encryptionAlg);
    string decrypt(string encryptedData, int encryptionAlg);

public:
	BasicNetworkProtocol();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS


	//Basic setup
    int setupClient(string ServerAddr);
    int setupServer();
    int usePort(int port);
    void quit();
    int compressData(int compression, bool enable);
    int encryptData(int encryption, bool enable);
    void getInfo();
        
    //Send data
    int sendChar(string name, char data);
    int sendDouble(string name, double num);
    int sendFloat(string name, float num);
    int sendInt(string name, int num);
    int sendStr(string name, string str);
    //int sendOther();
        
    //Recive data
    char getChar(string name);
    double getDouble(string name);
    float getFloat(string name);
    int getInt(string name);
    string getStr(string name);

	//Fetching
	int GetSock();  //Returns connected socket or 0
	int GetSetup(); //Returns 0 for not connected, 1 for connecting, 2 for connected

	//Display On Dash
	void DisplayVars();
};

#endif
