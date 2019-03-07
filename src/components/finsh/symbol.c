/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-03-22     Bernard      first version
 */
 
#include "include\rtthread.h"

#ifdef RT_USING_FINSH

#include "finsh.h"

long hello(void);
long version(void);
long list(void);
long list_thread(void);
long list_sem(void);
long list_mutex(void);
long list_fevent(void);
long list_event(void);
long list_mailbox(void);
long list_msgqueue(void);
long list_mempool(void);
long list_timer(void);

#ifdef CONFIG_ARDUINO
#define CONVERT_TO_CMD(f) \
void f(void); \
long f##_(void) { \
    f(); \
    return 0; \
}
#define INSERT_CMD(f) {#f, f##_}

CONVERT_TO_CMD(list_mem);
#endif /* CONFIG_ARDUINO */

#ifdef FINSH_USING_SYMTAB
struct finsh_syscall *_syscall_table_begin  = NULL;
struct finsh_syscall *_syscall_table_end    = NULL;
struct finsh_sysvar *_sysvar_table_begin    = NULL;
struct finsh_sysvar *_sysvar_table_end      = NULL;
#else
struct finsh_syscall _syscall_table[] =
{
    {"hello", hello},
    {"version", version},
    {"list", list},
    {"list_thread", list_thread},
#ifdef RT_USING_SEMAPHORE
    {"list_sem", list_sem},
#endif
#ifdef RT_USING_MUTEX
    {"list_mutex", list_mutex},
#endif
#ifdef RT_USING_FEVENT
    {"list_fevent", list_fevent},
#endif
#ifdef RT_USING_EVENT
    {"list_event", list_event},
#endif
#ifdef RT_USING_MAILBOX
    {"list_mb", list_mailbox},
#endif
#ifdef RT_USING_MESSAGEQUEUE
    {"list_mq", list_msgqueue},
#endif
#ifdef RT_USING_MEMPOOL
    {"list_memp", list_mempool},
#endif
    {"list_timer", list_timer},
#ifdef CONFIG_ARDUINO
    INSERT_CMD(list_mem),
#endif
};
struct finsh_syscall *_syscall_table_begin = &_syscall_table[0];
struct finsh_syscall *_syscall_table_end   = &_syscall_table[sizeof(_syscall_table) / sizeof(struct finsh_syscall)];

struct finsh_sysvar *_sysvar_table_begin  = NULL;
struct finsh_sysvar *_sysvar_table_end    = NULL;
#endif

#endif /* RT_USING_FINSH */

