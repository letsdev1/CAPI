#ifndef LOGGER_H
#define LOGGER_H

using namespace std;

class Logger{

  public: 
    static Logger *instance()
    {
        if (!inst)
            inst = new Logger();
        return inst;
    }
         void log();

  protected:
    // 4. Define all ctors to be protected
    Logger()
    {
        cout << ":ctor: ";
    } 

  private:
    static Logger *inst; 

};
#endif