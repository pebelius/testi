/*
 * BGP-FSM.cpp
 *
 *  Created on: Feb 9, 2011
 *      Author: pebe
 */
#include <iostream>
#include "BGP-FSM.h"
#include "ProtocolFunctions.h"

namespace sc = boost::statechart;

/*
sc::result State::react( const ManualStart & ) {
	;
}
sc::result State::react( const ManualStop & ) {
	;
}
sc::result State::react( const ConnectRetryTimer_Expires & ) {
	;
}
sc::result State::react( const HoldTimer_Expires & ) {
	;
}
sc::result State::react( const KeepaliveTimer_Expires & ) {
	;
}
sc::result State::react( const Tcp_CR_Acked & ) {
	;
}
sc::result State::react( const TcpConnectionConfirmed & ) {
	;
}
sc::result State::react( const TcpConnectionFails & ) {
	;
}
sc::result State::react( const BGPOpen & ) {
	;
}
sc::result State::react( const BGPHeaderErr & ) {
	;
}
sc::result State::react( const BGPOpenMsgErr & ) {
	;
}
sc::result State::react( const NotifMsgVerErr & ) {
	;
}
sc::result State::react( const NotifMsg & ) {
	;
}
sc::result State::react( const KeepAliveMsg & ) {
	;
}
sc::result State::react( const UpdateMsg & ) {
	;
}
sc::result State::react( const UpdateMsgErr & ) {
	;
}
*/

sc::result Idle::react( const ManualStart & ) {
	initializeResources();
	//setConnectRetryCounter(0);
	std::cout << "startConnectRetryTimer(ConnectRetryTime)\n";
	std::cout << "initTCPConnection()\n";
	std::cout << "listen TCP Connections\n";
	return transit< Connect >();
}
sc::result Idle::react( const ConnectRetryTimer_Expires & ) {
	return transit< Idle >();
}
sc::result Idle::react( const HoldTimer_Expires & ) {
	return transit< Idle >();
}
sc::result Idle::react( const KeepaliveTimer_Expires & ) {
	return transit< Idle >();
}
sc::result Idle::react( const Tcp_CR_Acked & ) {
	return transit< Idle >();
}
sc::result Idle::react( const TcpConnectionConfirmed & ) {
	return transit< Idle >();
}
sc::result Idle::react( const TcpConnectionFails & ) {
	return transit< Idle >();
}
sc::result Idle::react( const BGPOpen & ) {
	return transit< Idle >();
}
sc::result Idle::react( const BGPHeaderErr & ) {
	return transit< Idle >();
}
sc::result Idle::react( const BGPOpenMsgErr & ) {
	return transit< Idle >();
}
sc::result Idle::react( const NotifMsgVerErr & ) {
	return transit< Idle >();
}
sc::result Idle::react( const NotifMsg & ) {
	return transit< Idle >();
}
sc::result Idle::react( const KeepAliveMsg & ) {
	return transit< Idle >();
}
sc::result Idle::react( const UpdateMsg & ) {
	return transit< Idle >();
}
sc::result Idle::react( const UpdateMsgErr & ){
	return transit< Idle >();
}


sc::result Connect::react( const ManualStop & ) {
	std::cout << "dropTCPConnection()\n";
	std::cout << "releaseResources()\n";
	std::cout << "setConnectRetryCounter(0)\n";
	std::cout << "stopConnectRetryTimer()\n";
	std::cout << "setConnectRetryTimer(0)\n";
	return transit< Idle >();
}
sc::result Connect::react( const ConnectRetryTimer_Expires & ) {
	std::cout << "dropTCPConnection()\n";
	std::cout << "startConnectRetryTimer(ConnectRetryTime)\n";
	std::cout << "initTCPConnection()\n";
	std::cout << "continue to listen TCP Connections\n";
	return transit< Connect >();
}
sc::result Connect::react( const HoldTimer_Expires & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const KeepaliveTimer_Expires & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const Tcp_CR_Acked & ) {
	std::cout << "stopConnectRetryTimer()\n";
	std::cout << "setConnectRetryTimer(0)\n";
	std::cout << "completeBGPInit()/n";
	std::cout << "sendOPENMsg()\n";
	std::cout << "setHoldTimer(240\)n";
	return transit< Connect >();
}
sc::result Connect::react( const TcpConnectionConfirmed & ) {
	std::cout << "stopConnectRetryTimer()\n";
	std::cout << "setConnectRetryTimer(0)\n";
	std::cout << "completeBGPInit()n";
	std::cout << "sendOPENMsg()\n";
	std::cout << "setHoldTimer(240)\n";
	return transit< OpenSent >();
}
sc::result Connect::react( const TcpConnectionFails & ) {
	std::cout << "stopConnectRetryTimer()\n";
	std::cout << "setConnectRetryTimer(0)\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "releaseResources()\n";
	return transit< Idle >();
}
sc::result Connect::react( const BGPOpen & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const BGPHeaderErr & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const BGPOpenMsgErr & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const NotifMsgVerErr & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const NotifMsg & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const KeepAliveMsg & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const UpdateMsg & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}
sc::result Connect::react( const UpdateMsgErr & ) {
	std::cout << "if(connectRetryTimerIsRunning) {\n";
	std::cout << "\tstopConnectRetryTimer()\n";
	std::cout << "\tsetConnectRetryTimer(0)\n";
	std::cout << "}\n";
	std::cout << "releaseResources()\n";
	std::cout << "dropTCPConnection()\n";
	std::cout << "connectRetryCounter++\n";
	return transit< Idle >();
}


sc::result Active::react( const ManualStop & ) {
	;
}
sc::result Active::react( const ConnectRetryTimer_Expires & ) {
	;
}
sc::result Active::react( const HoldTimer_Expires & ) {
	;
}
sc::result Active::react( const KeepaliveTimer_Expires & ) {
	;
}
sc::result Active::react( const Tcp_CR_Acked & ) {
	;
}
sc::result Active::react( const TcpConnectionConfirmed & ) {
	;
}
sc::result Active::react( const TcpConnectionFails & ) {
	;
}
sc::result Active::react( const BGPOpen & ) {
	;
}
sc::result Active::react( const BGPHeaderErr & ) {
	;
}
sc::result Active::react( const BGPOpenMsgErr & ) {
	;
}
sc::result Active::react( const NotifMsgVerErr & ) {
	;
}
sc::result Active::react( const NotifMsg & ) {
	;
}
sc::result Active::react( const KeepAliveMsg & ) {
	;
}
sc::result Active::react( const UpdateMsg & ) {
	;
}
sc::result Active::react( const UpdateMsgErr & ) {
	;
}


sc::result OpenSent::react( const ManualStart & ) {
	;
}
sc::result OpenSent::react( const ManualStop & ) {
	;
}
sc::result OpenSent::react( const ConnectRetryTimer_Expires & ) {
	;
}
sc::result OpenSent::react( const HoldTimer_Expires & ) {
	;
}
sc::result OpenSent::react( const KeepaliveTimer_Expires & ) {
	;
}
sc::result OpenSent::react( const Tcp_CR_Acked & ) {
	;
}
sc::result OpenSent::react( const TcpConnectionConfirmed & ) {
	;
}
sc::result OpenSent::react( const TcpConnectionFails & ) {
	;
}
sc::result OpenSent::react( const BGPOpen & ) {
	;
}
sc::result OpenSent::react( const BGPHeaderErr & ) {
	;
}
sc::result OpenSent::react( const BGPOpenMsgErr & ) {
	;
}
sc::result OpenSent::react( const NotifMsgVerErr & ) {
	;
}
sc::result OpenSent::react( const NotifMsg & ) {
	;
}
sc::result OpenSent::react( const KeepAliveMsg & ) {
	;
}
sc::result OpenSent::react( const UpdateMsg & ) {
	;
}
sc::result OpenSent::react( const UpdateMsgErr & ) {
	;
}

int main()
{
  FSM myMachine;
  myMachine.initiate();
  myMachine.process_event(ManualStart());
  myMachine.process_event(TcpConnectionConfirmed());
  //myMachine.process_event(ReceiveOPENmessage());
  //myMachine.process_event(ReceiveKEEPALIVEmessage());
  //myMachine.process_event(ReceiveUPDATEmessages());
  return 0;
}

