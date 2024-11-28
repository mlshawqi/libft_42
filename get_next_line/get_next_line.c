#include "get_next_line.h"

char *get_next_line(int fd) {
    static char buf[1024];
    static ssize_t byte_read = 0;
    static ssize_t curr_pos = 0;
    char *savebuf = NULL;
    int nline;
    int o = 0;
    int j = 0;

    while (o == 0) {
        // If buffer is exhausted, read more data
        if (curr_pos >= byte_read) {
            byte_read = read(fd, buf, sizeof(buf) - 1);
            if (byte_read < 0) { // Handle read errors
                free(savebuf);
                return NULL;
            }
            if (byte_read == 0) { // Handle EOF
                if (savebuf)
                    return savebuf; // Return remaining data
                return NULL;
            }
            buf[byte_read] = '\0'; // Null-terminate safely
            curr_pos = 0;
        }

        // Find newline in the buffer
        nline = newline(buf + curr_pos);
        if (nline != -1)
            o++; // Mark if a newline is found

        // Handle the first iteration
        if (j == 0) {
            if (o > 0) {
                char *line = ft_strndup(buf + curr_pos, nline + 1);
                curr_pos += (nline + 1);
                return line;
            } else {
                savebuf = ft_strndup(buf + curr_pos, byte_read - curr_pos);
                curr_pos = byte_read; // Move to the end of the buffer
            }
        }
        // Handle subsequent iterations
        else {
            char *temp = savebuf;
            if (o > 0) {
                savebuf = ft_strjoin(savebuf, ft_strndup(buf + curr_pos, nline + 1));
                curr_pos += (nline + 1);
            } else {
                savebuf = ft_strjoin(savebuf, ft_strndup(buf + curr_pos, byte_read - curr_pos));
                curr_pos = byte_read;
            }
            free(temp);
        }
        j++;
    }

    return savebuf;
}


int main()
{
    int fd = open("text.txt", O_RDONLY);

    
    printf("\n%s\n", get_next_line(fd));
    //printf("\n%s\n", get_next_line(fd));
    //printf("\n%s\n", get_next_line(fd));
}