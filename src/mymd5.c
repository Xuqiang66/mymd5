#include <md5.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define READ_DATA_SIZE 1024
#define MD5_SIZE	16
#define MD5_STR_LEN	(MD5_SIZE * 2)

int MO_compute_file_md5(const char *file_path, char *md5_str)
{
    int i;
    int fd;
    int ret;
    unsigned char data[READ_DATA_SIZE];
    unsigned char md5_value[MD5_SIZE];
    MD5_CTX md5;

    fd = open(file_path, O_RDONLY);
    if (-1 == fd)
    {
        perror("open");
        return -1;
    }

    // init md5
    MD5_Init(&md5);

    while (1)
    {
        ret = read(fd, data, READ_DATA_SIZE);
        if (-1 == ret)
        {
            perror("read");
            return -1;
        }

        MD5_Update(&md5, data, ret);

        if (0 == ret || ret < READ_DATA_SIZE)
        {
            break;
        }
    }

    close(fd);

    MD5_Final(md5_value, &md5);

    for (i = 0; i < MD5_SIZE; i++)
    {
        snprintf(md5_str + i * 2, 2 + 1, "%02x", md5_value[i]);
    }
    md5_str[MD5_STR_LEN] = '\0'; // add end

    return 0;
}

int main(void)
{
	char filename[128] = "/home/nvidia/app-package/app_V1_1_8.tgz";
	char md5_str[MD5_STR_LEN + 1];

	MO_compute_file_md5(filename, md5_str);
	printf("filename=%s\n", filename);
	printf("md5=%s\n", md5_str);
}
