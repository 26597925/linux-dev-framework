/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef  __MISC_UTILS_H__
#define  __MISC_UTILS_H__

#include   <stdint.h>

void nano_sleep(long sec, long nsec);
uint64_t get_cpu_freq();
int get_self_path(char *buf, int buf_len);
void print_time();
int genPIDfile(char *szPidFile);
int register_sighandler(int signum, void (*handler)(int));
int get_cmd_result_int(const char *cmd, int *result_code);
int get_cmd_result(char *buf, int buflen, const char *cmd);
int mem_addr_vir2phy(unsigned long vir, unsigned long *phy);
int fd_readable(int fd, int usec);


#endif

