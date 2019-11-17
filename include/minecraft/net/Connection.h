#pragma once
#include<string>
using std::string;
class Certificate;
class ConnectionRequest;
class LoginPacket{
public:
//char filler[40];
std::unique_ptr<ConnectionRequest,std::default_delete<ConnectionRequest> >* getRq(){return (std::unique_ptr<ConnectionRequest,std::default_delete<ConnectionRequest> >*)((char*)this+40);}
};
class ConnectionRequest{
	public:
	string toString();
	Certificate* getCertificate() const;
	string getDeviceOS();
};
class ExtendedCertificate{
	public:
	static string getIdentityName(Certificate const&);
	static string getXuid(Certificate const&);
};
