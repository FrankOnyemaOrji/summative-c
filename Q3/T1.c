#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * Q3.
 *
 * S&T Suppliers is hiring for the new roles in the company, the details
 * are found in the this directoryLinks to an external site. You are
 * required to clone the repository and complete the tasks that follows:
 *
 * Task 1:
 * You are required to write a program that will iterate through the directory
 * and list all it contains:
 *
 * For every entry, it will display whether it is a file or a directory.
 * Along with the type, it will display the file name or directory name.
 * Along with the type and the name, it will present the size of each file/directory.
 * If there is any file/directory whose size is zero (0), make sure that you have it deleted.
 * The code to delete such file should be there.
 * Your code should keep an eye on .sh file and delete immediately without opening them.
 */


#define MAX_PATH 1024

void processEntry(const char *name);

int main(void) {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Failed to open directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        processEntry(entry->d_name);
    }

    closedir(dir);
    return EXIT_SUCCESS;
}

void processEntry(const char *name) {
    struct stat fileStat;
    if (stat(name, &fileStat) < 0) {
        perror("Failed to get file stats");
        return;
    }

    const char *type = S_ISDIR(fileStat.st_mode) ? "Directory" : "File";
    printf("%s: %s\nSize: %ld bytes\n", type, name, fileStat.st_size);

    // Check for deletion criteria
    if (fileStat.st_size == 0 || (S_ISREG(fileStat.st_mode) && strstr(name, ".sh") != NULL)) {
        printf("Deleting %s: %s\n", type, name);
        // Use 'remove' for files and directories. 'remove' works for directories if they are empty.
        if (remove(name) < 0) {
            perror("Failed to delete");
        }
    }
}
