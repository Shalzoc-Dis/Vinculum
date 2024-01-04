#pragma once
#include "Core.h"

namespace Vinculum {

    void consoleLog (std::string& message); // Only works with VEXcode V5 Pro for now.
    void fileLog (std::string& message);    // Print the message to a file. Only works if there is a SIM card in the V5 brain.
    // This is a function that logs messages to a file. It can take any datatype and any amount of them.
    template <typename T, typename... Args> // Declare typename T and typename... Args, any number of additional arguments
    void fileLog (T&& first, Args&&... args); // Declare the function. && is a reference qualifier that means the function can take both lvalue- and rvalue references.

    void clearLogFile (); // Clears the log file.

} // namespace Vinculum