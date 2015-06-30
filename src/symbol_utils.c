/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */




#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <dlfcn.h>
#include "debug.h"


static  void *handle;
int init_symbol()
{
    handle = dlopen(NULL, RTLD_NOW);
    if (!handle) 
    {
        DBG_PRINT("%s\n", dlerror());
        exit(1);
    }
}
int var_value(const char *name)
{
    int *pint = dlsym(handle, name);
    if (pint)
        DBG_PRINT("var %s = %d\n", name, *pint);
    else
        DBG_PRINT("dlsym %s failed, %s\n", name, dlerror());


    return 0;
}


typedef  void (*func_type)(int64_t para1, ...);
int exec_func(const char *input)
{
    char *func_name;
    func_type pfunc;
    int para1, para2;
    char *p_tmp;
    char buf[128];
    
    strcpy(buf, input);
    func_name = buf;
    p_tmp = strchr(buf, ')');
    *p_tmp = 0;
    p_tmp = strchr(buf, '(');
    *p_tmp = 0;
    p_tmp++;
    para1 = strtol(p_tmp,NULL,10);
    p_tmp = strchr(p_tmp, ',');
    p_tmp++;
    para2 = strtol(p_tmp,NULL,10);
    
    pfunc = dlsym(handle, func_name);
    pfunc(para1, para2);
    return 0;
}


