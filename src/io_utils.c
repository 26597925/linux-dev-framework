/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <stdarg.h>
#include <errno.h>
#include "debug.h"
int fd_readable(int fd, int sec, int usec)
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    tv.tv_sec = sec;
    tv.tv_usec = usec;

    retval = select(fd + 1, &rfds, NULL, NULL, &tv);
    if (retval == -1)
    {
       perror("select()");
       return 1;
    }
    if (retval)
    {
        return 1;
    }

    return 0;
}

int set_fd_nonblock(int fd)
{
    int ret;
    if((ret = fcntl(fd, F_GETFL,0))==-1)
    {   
        return ret;
    }

    ret |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, ret);
}

int write_reliable(int fd, const void *buf, size_t count)
{
    int ret;

TRY_AGAIN:
    ret = write(fd, buf, count);
    if (ret<0 && EINTR==errno)
        goto TRY_AGAIN;

    return ret;
}

int write_certain_bytes(int fd, const void *buf, size_t count)
{
    int ret, left=count, finished=0;

    while (left>0)
    {
        ret = write_reliable(fd, buf+finished, left);
        if (ret<0)
            return ret;

        finished+=ret;
        left-=ret;
    }

    return 0;
}

int read_reliable(int fd, void *buf, size_t count)
{
    int ret;

TRY_AGAIN:
    ret = read(fd, buf, count);
    if (ret<0 && EINTR==errno)
        goto TRY_AGAIN;

    return ret;
}

int read_certain_bytes(int fd, void *buf, size_t count)
{
    int ret, left=count, finished=0;

    while (left>0)
    {
        ret = read_reliable(fd, buf+finished, left);
        if (ret<0)
            return ret;

        finished+=ret;
        left-=ret;
    }

    return 0;
}

int printf_to_fd(int fd, const char *fmt, ...)
{
    int len;
    char buf[512];
    va_list ap;

    va_start(ap, fmt);
    len = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    return write_certain_bytes(fd, buf, len);
}

int get_temp_file(char *path)
{
    char file_name_template[] = "temp_XXXXXX";
    int ret;
TRY_AGAIN:
    ret=mkstemp(file_name_template);
    if (ret<0)
    {
        if (errno==EINTR)
            goto TRY_AGAIN;

        return ret;
    }

    close(ret);
    strcpy(path, file_name_template);
    return 0;
}
