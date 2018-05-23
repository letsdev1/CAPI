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

    std::string getComputerName(){
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

    std::string getRamSize(){
        std::string ramSize = "To-Do: Yet to be calculated";
        return ramSize;
    }


    /*
        developer: Vikas Bhandari
        date: 5/21/2018
        purpose: Binds the first URL, and returns the response with the device name and the Ram Size. 

    */


    void URLBinder::bindURL_string(){ //HttpServer *server

        std::cout << "Trying to log if it comes" << std::endl;

        // //VB: 5/20/2018 ==> url 1 will be http://localhost:<port>/api/r to return the computer name 
        // //                  and the Ram size


        // server->resource["^/api/r$"]["GET"] = 
        //         [](shared_ptr<HttpServer::Response> response, 
        //             shared_ptr<HttpServer::Request> request) {
        //     try {


        //         std::string computerName = getComputerName();
        //         std::string ramSize = getRamSize();
        //         std::string content = "The Device Name is : " + computerName;

        //         content.append("\n");
        //         content.append("The Ram Size is: " + ramSize);
        //         content.append("\n");

        //         *response << "HTTP/1.1 200 OK\r\n"
        //                 << "Content-Length: " << content.length() << "\r\n\r\n"
        //                 << content;
        //     }
        //     catch(const exception &e) {
        //         *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
        //                 << e.what();
        //     }

        // };
    }
}
