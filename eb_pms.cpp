# include "eb_pms.h"
using namespace boost::property_tree;
using namespace std;

using namespace EBPMS;


/*
    developer: Vikas Bhandari
    date: 5/20/2018
    purpose: the main entry function. 
*/

int main(){ //int args, char* argv
    std::cout << "Entered in the program" << std::endl;


    //VB: bind the port 
    HttpServer server;
    server.config.port = 8081;



    //calling the bindURL function to bind it with

    bindUrls(&server);

    //start server
    thread server_thread([&server]() {
    // Start server
        std::cout << "Starting server" << std::endl;
        server.start();
  });

  

    std::cout << "Code to start server" << std::endl;
  server_thread.join();

}

/*
    developer: Vikas Bhandari
    date: 5/20/2018
    purpose: Will bind the Urls to request. 
*/

void bindUrls(HttpServer *server){
    //URLBinder c;
    Binder binder; //will create object of binder. 
                    //Somehow I don't understand this concept. Declaring it will create an object? Really?

    binder.bindURL_string(server);
    binder.bindURL_postData(server);
    binder.bindURL_putData(server);
    binder.bindURL_deleteData(server);


}


/**
#add_library(EB url_binder.cpp)
##target_link_libraries (POC EB)
*/