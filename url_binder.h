


#include <boost/property_tree/json_parser.hpp> /*for reading JSON, if we will use boost json parser.*/
#include <boost/property_tree/ptree.hpp> /*for the shared pointer*/




# include <iostream>



/* for reading the computer name and the ram */
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* following block is for reading json data through rapidjson*/

#include "./include/rapidjson/document.h"
#include "./include/rapidjson/writer.h"
#include "./include/rapidjson/stringbuffer.h"

#include "./helpers/logger.h"

#include "server_http.hpp"


int gethostname(char *name, size_t len);


namespace EBPMS{
    class URLBinder{
        using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

        public: URLBinder();
        std::string getComputerName();
        std::string getRamSize();
        void bindURL_string(HttpServer *server); //
        void bindURL_postData(HttpServer *server); //
        void bindURL_putData(HttpServer *server); //
        void bindURL_deleteData(HttpServer *server); //
    }; // class url binder ends
} //namespace ends