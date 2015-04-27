/******************************************************************************
* Copyright (c) 2010, Mikae
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
* 3. All advertising materials mentioning features or use of this software
*    must display the following acknowledgement:
*    This product includes software developed by the Mikae.
* 4. Neither the name of Mikae nor the
*    names of its contributors may be used to endorse or promote products
*    derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mikae ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mikae BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************
*/

//Common routines, defines, prototypes and structs.
#include "pstdint.h"

struct RWBUFF
{
    uint8_t *origin_offset;
    uint8_t *offset;
    size_t   length;
    uint8_t  err;
};

// uint8_t bsf(uint32_t src);

// extern uint8_t pref_opcodes[];

uint8_t pref_opcodes[] =
{
    0x2E, //CS
    0x3E, //DS
    0x26, //ES
    0x36, //SS
    0x64, //FS
    0x65, //GS
    0x66, //OPSIZE
    0x67, //ADDRSIZE
    0xF2, //REPZ
    0xF3, //REPNZ
    0xF0  //LOCK
};

uint8_t bsf(uint32_t src)
{
    uint8_t res;

    for(res = 0; src; src >>= 0x1)
    {
        if (src & 0x1)
            break;
        res++;
    }

    return res;
}