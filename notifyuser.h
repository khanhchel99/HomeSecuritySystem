#ifndef NOTIFYUSER_H
#define NOTIFYUSER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include "base64.h"
#include "para.h"
#include "time.h"
#include <iostream>
#include <string>

#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

class NotifyUser {

public:
	void emailUser(char* message);

private:
	int my_strlen(char *str);
	const char* GetIPAddress(const char* target_domain);
	int ConnectToServer(const char* server_address);
	char * MailHeader(const char* from, const char* to, const char* subject, const char* mime_type, const char* charset);

};

#endif
