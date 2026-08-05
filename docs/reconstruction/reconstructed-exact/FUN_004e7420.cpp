// =============================================================================
// FUN_004e7420  (alias of RbTree_InitEmptyHeader_Node1c)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7420
// Address:   0x004e7420–0x004e744a  (autoassault.exe, image base 0x400000)
// System:    containers / RB-tree empty header (0x1c-node flavor)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W23-M)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - __thiscall: ECX = header*; plain ret; returns header* in EAX.
 * - FUN_005ae2b0() → node at header+4; node+0x19=1; self-link +0/+4/+8; size header+8=0.
 * - Completes empty map after 0x1c node factory FUN_005ae2b0.
 * - Named: RbTree_InitEmptyHeader_Node1c (role-sealed INFERRED).
 * - Sibling FUN_004e7450 / RbTree_InitEmptyHeader uses 0x18 factory / +0x15 flag.
 */

#include <cstdint>

extern "C" int FUN_005ae2b0(void);

int __fastcall FUN_004e7420(int param_1 /*ECX header*/)
{
  int iVar1;

  iVar1 = FUN_005ae2b0();
  *(int *)(param_1 + 4) = iVar1;
  *(uint8_t *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(uint32_t *)*(uint32_t *)(param_1 + 4) = *(uint32_t *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(uint32_t *)(param_1 + 8) = 0;
  return param_1;
}
