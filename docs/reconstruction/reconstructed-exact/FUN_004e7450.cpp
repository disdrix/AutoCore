// =============================================================================
// FUN_004e7450  (alias of RbTree_InitEmptyHeader)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7450
// Address:   0x004e7450–0x004e747a  (autoassault.exe, image base 0x400000)
// System:    containers / RB-tree empty header
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W22-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - __thiscall: ECX = header*; plain ret; returns header* in EAX.
 * - FUN_00439770() → node at header+4; node+0x15=1; self-link +0/+4/+8; size header+8=0.
 * - Completes empty map after RbTree_AllocEmptyNode_Inferred (W18-S).
 * - Named: RbTree_InitEmptyHeader (role-sealed INFERRED).
 * - Sibling FUN_004e7420 uses different node factory / +0x19 flag — not this unit.
 */

#include <cstdint>

extern "C" int FUN_00439770(void);

int __fastcall FUN_004e7450(int param_1 /*ECX header*/)
{
  int iVar1;

  iVar1 = FUN_00439770();
  *(int *)(param_1 + 4) = iVar1;
  *(uint8_t *)(iVar1 + 0x15) = 1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(uint32_t *)*(uint32_t *)(param_1 + 4) = *(uint32_t *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(uint32_t *)(param_1 + 8) = 0;
  return param_1;
}
