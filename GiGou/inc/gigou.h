#ifndef GIGOU_H
#define GIGOU_H

#include "gigou_config.h"
#include "gigou_platform.h"
#include "gigou_macro.h"
#include "gigou_compiler.h"
#include "gigou_const.h"
#include "gigou_flags.h"
#include "gigou_uuid.h"

/* KERNEL */
#include "gigou_kernel.h"
    /* MEM */
#   include "gigou_kernel_mem_pool.h"
#   include "gigou_kernel_mem_tas.h"
#   include "gigou_kernel_mem_pile.h"
    /* THREAD */
#   include "gigou_kernel_thread.h"

#endif