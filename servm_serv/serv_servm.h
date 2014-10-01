#ifndef __SERV_SERVM_H__
#define __SERV_SERVM_H__

// 该服务的代码段起始地址
#define SERV_SERVM_CODE_SEG_BASE 0x31200000


// sys 服务数量的最大值
#define SERV_MAX_NUM 99


// 在 SYS 中的进程的几种状态
#define SERV_STATUS_READY 0
#define SERV_STATUS_RUNNING 1
#define SERV_STATUS_UNREADY 2
#define SERV_STATUS_EMPTY 3  // 该索引还没有注册进服务


// 描述一个在 sys 服务表中的表项
typedef struct serv_table
{
  WORD CODE_SEG_BASE;  // 代码段基地址
  WORD CODE_SEG_LIMIT; // 代码段长度
  WORD PARA_SEG_BASE;  // 共享数据段基地址，不用写共享数据段的长度，因为长度指定为 3 个WORD
  WORD SERV_STATUS;    // serv 当前的状态
}SERV_TABLE, *ptr_serv_table;

// 指向当前要执行的 sys 服务表项
ptr_serv_table PTR_SERV_TABLE;

#define SERV_TABLE_LEN 16 // 一个该结构体占 16 个字节


// 描述一个在共享数据区中的 sys 服务的表项
typedef struct serv_para
{
  WORD OPT_CODE;  // 操作码
  WORD PARA_BASE; // 参数列表的基地址
  WORD PARA_NUM;  // 参数的数量
}SERV_PARA, *ptr_serv_para;

// 指向当前要执行的 sys 服务参数表项
ptr_serv_para PTR_SERV_PARA;

#define SERV_PARA_LEN 12 // 一个该结构体占 12 个字节


// 注册了所有的 sys 服务的全局表
ptr_serv_table SERV_GLOBAL_TABLE;


// 下面即该服务提供的所有函数所对应的操作码
#define SERV_SERVM_INIT 0x1
#define SERV_SERVM_add_serv 0x2
#define SERV_SERVM_register_serv 0x3
#define SERV_SERVM_get_empty_idx 0x4

// 下面即该服务提供的所有函数
// 下面的函数全部出于 serv_servm_funcs.c
extern void serv_servm_init();
extern void serv_servm_add_serv(WORD* para_list, WORD para_num);
extern void serv_servm_register_serv(WORD* para_list, WORD para_num);
extern WORD serv_servm_get_empty_idx();


/* serv 服务的相关参数 */

#define SERV_REGISTER_TABLE_BASE 0x31100000
#define SERV_REGISRER_TABLE_LIMIT 0x00100000

#define SERV_CODE_BASE 0x31200000
#define SERV_CODE_LIMIT 0x00C00000

#define SERV_SHARE_RAM_BASE 0x31E00000
#define SERV_SHARE_RAM_LIMIT 0x00100000


#endif
