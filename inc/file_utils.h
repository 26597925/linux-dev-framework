/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef  __UTILS_H__
#define  __UTILS_H__

#include   "defs.h"

#define    MAX_FILE_NAME_LEN    (128)
#define    MAX_ARGS_LEN         (128)
#define    MAX_VAR_NAME_LEN     (128)

#define    MAX_VAR_NUM          (50)
#define    MAX_VAR_VALUE_LEN    (MAX_PATH_LEN)

int parse_config_file(char *path_to_config_file, int need_update);
char * get_config_var(char *var_name);
#endif

