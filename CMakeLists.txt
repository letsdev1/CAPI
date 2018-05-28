

#minimum version for cmake. 2.8.2 because Google tests require it
cmake_minimum_required (VERSION 2.8.2)


#set c++ standard here
set (CMAKE_CXX_STANDARD 11)


#the project name ==> POC for now until we finalize a good name, eh ;)
project (POC)

set (POC_VERSION_MAJOR 1)
set (POC_VERSION_MINOR 0)

#sending the variables to config file
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )




# include the http server
include_directories ("${PROJECT_SOURCE_DIR}/Simple-Web-Server")
add_subdirectory (Simple-Web-Server) 
set (EXTRA_LIBS ${EXTRA_LIBS} INTERFACE)

# include the RapidJSON 
include_directories ("${PROJECT_SOURCE_DIR}/rapidjson")
add_subdirectory (rapidjson) 
find_package(RapidJSON)

#add the namespace


add_executable (POC eb_pms.cpp url_binder.cpp  )

target_link_libraries (POC INTERFACE)

#find boost **not sure why we need boost library link here**

    find_package(Boost 1.53.0 COMPONENTS system thread REQUIRED)
    target_link_libraries(POC ${Boost_LIBRARIES})

