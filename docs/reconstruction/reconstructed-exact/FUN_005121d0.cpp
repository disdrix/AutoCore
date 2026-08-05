// =============================================================================
// FUN_005121d0 / IsPlayerTargetingLinkAndDestroy
// -----------------------------------------------------------------------------
// Stable ID: aa_005121d0
// Address:   0x005121d0  (autoassault.exe, image base 0x400000)
// Body:      0x005121d0–0x00512206 (leaf; ret 0xC @ 0x005121fe)
// System:    object / combat-target / HB
// Generated: 2026-07-23 scaffold; dual-sealed 2026-07-29 (W16-O)
// Exactness: Behavior-preserving rewrite of decompiler control flow + image ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// List-purge predicate for self-side targeting heartbeat objects.
// RTTI-downcast node to CVOGHBPlayerTargetingLink; on hit call vtbl+0x18(1,0)
// and return 1 (remove). Else return 0 (keep). Sole xref: Object_SetSelectedTarget
// predicate push @ 0x0051733b (entity HB list at +0xB0).

// ABI (image-sealed):
//   Not thiscall. Free function, ret 0xC (3 stack formals).
//   arg0 = node* (only used); arg1/arg2 unused list context (caller 0,0).
//   return AL 0/1.

// RTTI (read_memory):
//   CVOGHBBase::RTTI_Type_Descriptor            @ 0x00af8d98  ".?AVCVOGHBBase@@"
//   CVOGHBPlayerTargetingLink::RTTI_Type_Descriptor @ 0x00af1bb0  ".?AVCVOGHBPlayerTargetingLink@@"
//   __RTDynamicCast                               @ 0x004898A4

// READABILITY:
//  - Control: if×1, return×2.
//  - Callees: __RTDynamicCast; indirect vtbl+0x18.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory; dual A/B sealed 2026-07-29.
 * - Decompiler shows 1 formal; image ret 0xC requires 3 stack slots for ports.
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

// MSVC RTTI type descriptors (addresses sealed; full structs not retyped here)
extern "C" void *CVOGHBBase_RTTI_Type_Descriptor;              // 0x00af8d98
extern "C" void *CVOGHBPlayerTargetingLink_RTTI_Type_Descriptor; // 0x00af1bb0
extern "C" void *__cdecl __RTDynamicCast(void *in,
                                         long VfDelta,
                                         void *srcType,
                                         void *targetType,
                                         int isReference);

// stdcall / ret 0xC — keep three formals even if only arg0 is read
extern "C" uint32_t __stdcall FUN_005121d0(int *param_1,
                                           void * /*ctx1*/,
                                           void * /*ctx2*/)
{
  int iVar1;

  iVar1 = (int)__RTDynamicCast(
      param_1,
      0,
      &CVOGHBBase_RTTI_Type_Descriptor,
      &CVOGHBPlayerTargetingLink_RTTI_Type_Descriptor,
      0);
  if (iVar1 != 0) {
    // thiscall: (*(param_1->vtbl + 0x18))(param_1, 1, 0)
    (*(void (__thiscall **)(int *, int, int))(*param_1 + 0x18))(param_1, 1, 0);
    return 1;
  }
  return 0;
}

// Inferred product-facing alias (same body)
// uint32_t __stdcall IsPlayerTargetingLinkAndDestroy(void *node, void *ctx1, void *ctx2);
