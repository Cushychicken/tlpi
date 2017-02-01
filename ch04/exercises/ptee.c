#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "error_functions.h"

int main(int argc, char *argv[])
{
    int outputFd, openFlags, filePerms, numRead;  
    char buf[BUFSIZ];

    if (argc < 2)
        usageErr("%s new-file\n", argv[0]);

    if ( (argv[1][0] == '-') && (argv[1][1] == 'a') )
        openFlags = O_CREAT | O_WRONLY | O_APPEND;
    else
        openFlags = O_CREAT | O_WRONLY | O_TRUNC;

    filePerms = S_IRUSR | S_IWUSR; 
    outputFd = open(argv[1], openFlags, filePerms);

    while ( (numRead = read(STDIN_FILENO, &buf, BUFSIZ)) > 0 ) {
        printf("%s", buf);
        write(outputFd, &buf, numRead); 
    }

    return 0;
}


