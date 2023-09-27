#ifndef PROTOCOL_ADAPTER_HPP
#define PROTOCOL_ADAPTER_HPP

#include "HttpHandler.hpp"
#include "FtpHandler.hpp"



class ProtocolAdapter: public HttpHandler, public FtpHandler
{
    public:

        ProtocolAdapter()
        {

        }

        ~ProtocolAdapter()
        {
            
        }

    private:


};


#endif
