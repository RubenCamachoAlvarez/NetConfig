#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char * argv[]) {

    char * commandLineArguments[argc + 1];

    commandLineArguments[argc] = NULL;

    for(int argumentSubscript = 1; argumentSubscript < argc; argumentSubscript++)

        commandLineArguments[argumentSubscript] = argv[argumentSubscript];

    #ifdef _WIN32

        commandLineArguments[0] = "ipconfig";

        execvp("ipconfig", commandLineArguments);

    #elif defined(__unix__)

        commandLineArguments[0] = "ifconfig";

        execvp("ifconfig", commandLineArguments);

    #endif

    fprintf(stderr, "%s\n", strerror(errno));

    fprintf(stdout, "This program uses ipconfig command to get the network configurations in the Windows operating system, and uses ifconfig command to get the network information in UNIX-based systems, so please verify that the command is installed and it was added to system path before to retry\n");

    return 0;

}