/*
 * Copyright (c) 2017, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef UTIL_H
#define UTIL_H

#include <glib.h>
#include <sys/types.h>
#include <tpm20.h>

#include "control-message.h"

/* allocate read blocks in BUF_SIZE increments */
#define UTIL_BUF_SIZE 1024
/* stop allocating at BUF_MAX */
#define UTIL_BUF_MAX  8*UTIL_BUF_SIZE

#define prop_str(val) val ? "set" : "clear"
/*
#define TPM_CC_FROM_TPMA_CC(attrs) (attrs.val & 0x0000ffff)
#define TPMA_CC_RESERVED(attrs)    (attrs.val & 0x003f0000)
#define TPMA_CC_NV(attrs)          (attrs.val & 0x00400000)
#define TPMA_CC_EXTENSIVE(attrs)   (attrs.val & 0x00800000)
#define TPMA_CC_FLUSHED(attrs)     (attrs.val & 0x01000000)
#define TPMA_CC_CHANDLES(attrs)    (attrs.val & 0x02000000)
#define TPMA_CC_RHANDLES(attrs)    (attrs.val & 0x10000000)
#define TPMA_CC_V(attrs)           (attrs.val & 0x20000000)
#define TPMA_CC_RES(attrs)         (attrs.val & 0xc0000000)
*/

ssize_t     write_all                       (gint const        fd,
                                             void const       *buf,
                                             size_t const      size);
void        process_control_code            (ControlCode       code);
int         tpm_header_from_fd              (int               fd,
                                             uint8_t          *buf);
int         tpm_body_from_fd                (int               fd,
                                             uint8_t          *buf,
                                             size_t            body_size);
uint8_t*    read_tpm_command_from_fd        (int               fd,
                                             UINT32           *command_size);
int         read_data                       (int               fd,
                                             size_t           *index,
                                             uint8_t          *buf,
                                             size_t            count);
int         read_tpm_buffer                 (int               fd,
                                             size_t           *index,
                                             uint8_t          *buf,
                                             size_t            buf_size);
void        g_debug_bytes                   (uint8_t const    *byte_array,
                                             size_t            array_size,
                                             size_t            width,
                                             size_t            indent);
void        g_debug_tpma_cc                 (TPMA_CC           tpma_cc);

#endif /* UTIL_H */
