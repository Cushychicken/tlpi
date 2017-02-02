#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "error_functions.h"

int main(int argc, char *argv[])
{
    int outputFd, openFlags, filePerms, numRead;  
    int opt;
    char buf[BUFSIZ];

    if (argc < 2)
        usageErr("%s new-file\n", argv[0]);

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;

    while ( (opt = getopt(argc, argv, "a")) != -1 ) {
        switch (opt) {
            case 'a':
                openFlags = O_CREAT | O_WRONLY | O_APPEND;
                break;
            default: 
                fprintf(stderr, "Usage %s [-a] name\n", argv[0]);
        }
    }

    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
    outputFd = open(argv[optind], openFlags, filePerms);

    while ( (numRead = read(STDIN_FILENO, &buf, BUFSIZ)) > 0 ) {
        printf("%s", buf);
        write(outputFd, &buf, numRead); 
    }

    return 0;
}


