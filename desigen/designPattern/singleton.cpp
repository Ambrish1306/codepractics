#include <iostream>
using namespace std;
#include <mutex>
class Logger {
	///static memeber.
	Logger(){  
          cout << "Logger instance created." << endl;
        }//private const
	Logger(const Logger&) = delete;//copy const unavailable  
    Logger& operator=(const Logger&) = delete;
public:
	//static function to use access of pravite member
	static Logger& getinstance(){
        static Logger instance;
        return instance;
    }
    void log(string msg) {
        cout << "Log: " << msg << endl;
    }
};
int main() {
    Logger& logger1 = Logger::getinstance();
    logger1.log("First log message.");

    Logger& logger2 = Logger::getinstance();
    logger2.log("Second log message.");

    cout << "Logger instances are the same: " << (&logger1 == &logger2) << endl;

    return 0;
}   
