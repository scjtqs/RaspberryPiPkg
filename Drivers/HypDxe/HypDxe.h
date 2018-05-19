/** @file
 *
 *  Copyright (c), 2018, Andrei Warkentin <andrey.warkentin@gmail.com>
 *
 *  This program and the accompanying materials
 *  are licensed and made available under the terms and conditions of the BSD License
 *  which accompanies this distribution.  The full text of the license may be found at
 *  http://opensource.org/licenses/bsd-license.php
 *
 *  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 *
 **/

#ifndef HYP_DXE_H
#define HYP_DXE_H

#include <Uefi.h>
#include <Chipset/AArch64.h>
#include <Protocol/DebugSupport.h>
#include <Library/DebugLib.h>
#include <Utils.h>

#define MMIO_EMU_START 0x80000000

extern void *ExceptionHandlersStart;

VOID SwitchStackAndEL(EFI_PHYSICAL_ADDRESS SPEL2);

EFI_STATUS
HypMmio(
  IN OUT EFI_SYSTEM_CONTEXT_AARCH64 *Context
  );

EFI_STATUS
HypMemInit(
  IN  EFI_HANDLE ImageHandle
  );

VOID *
HypMemAlloc(
  IN  UINTN Pages
  );

BOOLEAN
HypMemIsHyp2M(
  IN  EFI_PHYSICAL_ADDRESS A
  );

BOOLEAN
HypMemIsHypAddr(
  IN  EFI_PHYSICAL_ADDRESS A
  );

#endif /* HYP_DXE_H */