#include "Logger.h"

namespace Vinculum {

    void consoleLog (std::string& message) 
    {
        // Print the time since program start and the message to the console.
        std::cout << '[' << vex::timer::system() << ']' << message << "\n";
    }

    void fileLog (std::string message)
    {
        // Print the time since program start and the message to the console.
        std::ofstream logFile;
        logFile.open("log.txt", std::ios::app);
        logFile << '[' << vex::timer::system() << ']' << message << "\n";
        logFile.close();
    }

    template <typename T, typename... Args> // Declare typename T and typename... Args, any number of additional arguments
    void fileLog (T&& first, Args&&... args)
    {
        // Create a message string and append the first argument to it. std::forward is used to preserve the value category of the argument.
        std::string message = std::forward<T>(first);
        // Append the rest of the arguments to the string
        (message += ... += std::forward<Args>(args));
        // Write the string to file
        //fileLog(message); // Currently bugged and might not be needed
    }

    void clearLogFile ()
    {
        std::ofstream logFile;
        logFile.open("log.txt", std::ios::trunc); // Truncate the file, i.e. delete all contents
        logFile.close();
    }

} // namespace Vinculum