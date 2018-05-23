
// include the reference to server

#include "server_http.hpp"
#include "client_http.hpp" //client for testing the API code


#include <boost/property_tree/ptree.hpp> /*for the shared pointer*/

#include "url_binder.h"


using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
using HttpClient = SimpleWeb::Client<SimpleWeb::HTTP>;

using Binder = EBPMS::URLBinder;

void bindUrls(HttpServer *server);


