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

#include   "defs.h"

void nano_sleep(long sec, long nsec);
int genPIDfile(char *szPidFile);
int register_sighandler(int signum, void (*handler)(int));
int get_cmd_result_int(const char *cmd, int *result_code);
int get_cmd_result(char *buf, int buflen, const char *cmd);
#endif

