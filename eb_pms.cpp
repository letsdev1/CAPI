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
        server.start();
  });

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

    binder.bindURL_string();
}


/**
#add_library(EB url_binder.cpp)
##target_link_libraries (POC EB)
*/