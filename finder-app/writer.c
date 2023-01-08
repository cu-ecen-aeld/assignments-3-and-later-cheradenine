#include <syslog.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int write_content(const char* file_path, const char* content) {
    syslog(LOG_DEBUG, "Writing %s to %s", content, file_path);
    
    FILE* f = fopen(file_path, "w");

    if (f == NULL) {
        syslog(LOG_ERR, "Failed to open file %s, err=%d : %s", file_path, errno, strerror(errno));
        return 1;
    }

    if (fputs(content, f) < 0) {
        syslog(LOG_ERR, "Failed to write content to file, err=%d : %s", errno, strerror(errno));
        return 1;
    }
    if (fclose(f) != 0) {
        syslog(LOG_ERR, "Failed to close the file, err=%d : %s", errno, strerror(errno));
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: writer <file> <content>\n");
        return 1;
    }

    // Set up syslog.
    openlog("writer", 0, LOG_USER);

    const char* file_path = argv[1];
    const char* content = argv[2];
    return write_content(file_path, content);
}