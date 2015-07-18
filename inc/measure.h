/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef  __MEASURE_H__
#define  __MEASURE_H__

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#if defined( __i386) || defined( __x86_64)
static inline uint64_t rdtsc()
{
        uint32_t lo,hi;

        __asm__ __volatile__
        (
         "rdtsc":"=a"(lo),"=d"(hi)
        );
        return (uint64_t)hi<<32|lo;
}
#else
static inline uint64_t rdtsc()
{
        return 0;
}
#endif

typedef struct
{
    char     name[128];
    uint64_t total_cnt;
    uint64_t total_cycles;


    uint64_t one_time_begin;
    uint64_t one_time_end;
} t_measure;

int init_measure(int max_cnt);
void add_measure(void *pt_measure);
void report_measure();


#define   DECLAIRE_TIME_MEASURE(measure_var_name) \
   static  __thread   t_measure * ms_var_##measure_var_name=NULL


#define   INIT_TIME_MEASURE(measure_var_name) \
    do \
    { \
        if (ms_var_##measure_var_name==NULL) \
        { \
            ms_var_##measure_var_name=malloc(sizeof(t_measure)); \
            strcpy(ms_var_##measure_var_name->name, #measure_var_name); \
            ms_var_##measure_var_name->total_cnt = 0; \
            ms_var_##measure_var_name->total_cycles = 0; \
            add_measure(ms_var_##measure_var_name); \
        }\
    } while (0)




#define   TIME_MEASURE_BEGIN(measure_var_name) \
    do \
    { \
            ms_var_##measure_var_name->one_time_begin = rdtsc(); \
    } while (0)


#define   TIME_MEASURE_END(measure_var_name) \
    do \
    { \
            ms_var_##measure_var_name->one_time_end = rdtsc(); \
            ms_var_##measure_var_name->total_cnt++; \
            ms_var_##measure_var_name->total_cycles += ms_var_##measure_var_name->one_time_end - ms_var_##measure_var_name->one_time_begin; \
    } while (0)

#endif

