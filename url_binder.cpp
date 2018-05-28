# include "url_binder.h"
using namespace boost::property_tree;
using namespace std;

    /*
        developer: Vikas Bhandari
        date: 5/21/2018
        purpose: Will return the computer name. 
    */

namespace EBPMS{
    URLBinder::URLBinder()
    {
    //do nothing;
    }


    std::string URLBinder::getComputerName(){
        char hostname[100];
        int result;
        
        result = gethostname(hostname, 100);
        
        if (result)
        {
            perror("gethostname");
        }

        std::string computerName = "";
        computerName.append(hostname); 

        return computerName;
    }

    /*
        developer: Vikas Bhandari
        date: 5/21/2018
        purpose: Will return the RAM Size. 
    */

    std::string URLBinder::getRamSize(){
        std::string ramSize = "To-Do: Yet to be calculated";
        return ramSize;
    }


    /*
        developer: Vikas Bhandari
        date: 5/21/2018
        purpose: Binds the first URL, and returns the response with the device name and the Ram Size. 

    */


    void URLBinder::bindURL_string(HttpServer *server){ //


        //VB: 5/20/2018 ==> url 1 will be http://localhost:<port>/api/r to return the computer name 
        //                  and the Ram size

        
        server->resource["^/api/r$"]["GET"] = 
                [this](shared_ptr<HttpServer::Response> response, 
                    shared_ptr<HttpServer::Request> request) {
            try {


                std::string computerName = this->getComputerName();
                std::string ramSize = this->getRamSize();
                std::string content = "The Device Name is : " + computerName;

                content.append("\n");
                content.append("The Ram Size is: " + ramSize);
                content.append("\n");

                *response << "HTTP/1.1 200 OK\r\n"
                        << "Content-Length: " << content.length() << "\r\n\r\n"
                        << content;
            }
            catch(const exception &e) {
                *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                        << e.what();
            }

        };
    }


/*
* this function just logs the post data into SysLogs
*
*/
    void URLBinder::bindURL_postData(HttpServer *server){ 
        std::cout << "Trying to bind the sys logs here"<< std::endl;

        //Logger::instance()->log();

        server->resource["^/api/c$"]["POST"] = 
                [this](shared_ptr<HttpServer::Response> response, 
                    shared_ptr<HttpServer::Request> request) {
            try {


                std::string content = "The Post request received with data : " + request->content.string();

                *response << "HTTP/1.1 200 OK\r\n"
                        << "Content-Length: " << content.length() << "\r\n\r\n"
                        << content;
            }
            catch(const exception &e) {
                *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                        << e.what();
            }

        };        

    }


    void URLBinder::bindURL_putData(HttpServer *server){ 
        //Logger::instance()->log();

        server->resource["^/api/u/(.*)$"]["PUT"] = 
                [this](shared_ptr<HttpServer::Response> response, 
                    shared_ptr<HttpServer::Request> request) {
            try {

                std::string match = request->path_match[1].str();
                std::string content = "The put request received with data : " + match;

                *response << "HTTP/1.1 200 OK\r\n"
                        << "Content-Length: " << content.length() << "\r\n\r\n"
                        << content;
            }
            catch(const exception &e) {
                *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                        << e.what();
            }

        };        

    }

     void URLBinder::bindURL_deleteData(HttpServer *server){ 
        //Logger::instance()->log();

        server->resource["^/api/d/(.*)$"]["DELETE"] = 
                [this](shared_ptr<HttpServer::Response> response, 
                    shared_ptr<HttpServer::Request> request) {
            try {

                std::string match = request->path_match[1].str();
                std::string content = "The 'Delete' request received with data : " + match;

                *response << "HTTP/1.1 200 OK\r\n"
                        << "Content-Length: " << content.length() << "\r\n\r\n"
                        << content;
            }
            catch(const exception &e) {
                *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                        << e.what();
            }

        };        

    }



   




}
