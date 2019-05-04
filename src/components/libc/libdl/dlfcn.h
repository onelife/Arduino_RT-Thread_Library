/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Change Logs:
 * Date           Author      Notes
 * 2010-11-17     yi.qiu      first version
 */

#ifndef __DLFCN_H__
#define __DLFCN_H__

#define RTLD_LAZY       0x00000
#define RTLD_NOW        0x00001

#define RTLD_LOCAL      0x00000
#define RTLD_GLOBAL     0x10000

#define RTLD_DEFAULT    ((void*)1)
#define RTLD_NEXT       ((void*)2)

void *dlopen(const char *filename, int flag);
int dlclose (void *handle);
const char *dlerror(void);
void *dlsym(void *handle, const char *symbol);

#endif /* __DLFCN_H__ */
