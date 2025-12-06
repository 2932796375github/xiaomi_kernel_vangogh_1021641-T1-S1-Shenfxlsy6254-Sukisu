/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * seccomp_types.h - seccomp system call type definitions and constants
 *
 * This file contains type definitions and constants that are used by the
 * seccomp system call interface. It is intended to be included by both
 * kernel code and userspace applications.
 */

#ifndef _LINUX_SECCOMP_TYPES_H
#define _LINUX_SECCOMP_TYPES_H

#include <linux/types.h>

/* Definitions for seccomp filter operations */
#define SECCOMP_RET_KILL_PROCESS 0x800000U
#define SECCOMP_RET_KILL_THREAD  0x000000U
#define SECCOMP_RET_KILL         SECCOMP_RET_KILL_THREAD
#define SECCOMP_RET_TRAP         0x0030000U
#define SECCOMP_RET_ERRNO        0x00050000U
#define SECCOMP_RET_USER_NOTIF   0x7fc00000U
#define SECCOMP_RET_TRACE        0x7ff00000U
#define SECCOMP_RET_LOG          0x7ffc0000U
#define SECCOMP_RET_ALLOW        0x7fff0000U

#define SECCOMP_RET_ACTION_FULL  0xffff0000U
#define SECCOMP_RET_ACTION       0x7fff0000U

/* Valid operations for seccomp() syscall */
#define SECCOMP_SET_MODE_STRICT		0
#define SECCOMP_SET_MODE_FILTER		1

/* Flags for seccomp event logging */
#define SECCOMP_FILTER_FLAG_TSYNC		(1UL << 0)
#define SECCOMP_FILTER_FLAG_LOG			(1UL << 1)
#define SECCOMP_FILTER_FLAG_SPEC_ALLOW		(1UL << 2)
#define SECCOMP_FILTER_FLAG_NEW_LISTENER	(1UL << 3)

/* Data structure for seccomp filter */
struct seccomp_data {
	int nr;
	__u32 arch;
	__u64 instruction_pointer;
	__u64 args[6];
};

/* Structure for user notifications */
struct seccomp_notif {
	__u64 id;
	__u32 pid;
	__u32 flags;
	__u64 syscall_arch;
	__u64 syscall_num;
	__u64 orig_args[6];
	__u64 data;
};

struct seccomp_notif_resp {
	__u64 id;
	__s64 val;
	__s32 error;
	__u32 flags;
};

struct seccomp_notif_addfd {
	__u64 id;
	__u32 flags;
	__u32 srcfd;
	__s32 newfd;
};

#endif /* _LINUX_SECCOMP_TYPES_H */