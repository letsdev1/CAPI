#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

#include "logger.h"




    void Logger::log()
    {
        openlog("ebpsm log: ", LOG_PID|LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "%s" ,"hello the log is here");
        closelog();
    }


  // 1. Define a private static attribute

