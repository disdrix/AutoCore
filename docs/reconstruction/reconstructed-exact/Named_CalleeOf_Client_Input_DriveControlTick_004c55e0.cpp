// =============================================================================
// Named_CalleeOf_Client_Input_DriveControlTick_004c55e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c55e0  (alias of FUN_004c55e0)
// Callee of Client_Input_DriveControlTick (look-vector speed scale @ 00922eb3)
// Address:   0x004c55e0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B seal (see FUN_004c55e0.cpp)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A_aa_004c55e0_FUN_004c55e0.md + B_*
// =============================================================================

// PURPOSE: Speed-derived float scale. Early min(obj+0x110,obj+0x10c) when
//   this+0x250 set and comp+0xf5 clear; else (FUN_004c4e20±flags + 1)*this+0x1f0.
// Prefer canonical clean: FUN_004c55e0.cpp

// READABILITY (auto CF):
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004c4e20.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_Input_DriveControlTick
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

float10 __fastcall Named_CalleeOf_Client_Input_DriveControlTick_004c55e0(int param_1)



{

  int iVar1;

  uint uVar2;

  float10 fVar3;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 0x250);

  if ((iVar1 != 0) &&

     (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xf5) == '\0')) {

    if (*(float *)(iVar1 + 0x110) < *(float *)(iVar1 + 0x10c) ||

        *(float *)(iVar1 + 0x110) == *(float *)(iVar1 + 0x10c)) {

      return (float10)*(float *)(iVar1 + 0x110);

    }

    return (float10)*(float *)(iVar1 + 0x10c);

  }

  fVar3 = (float10)FUN_004c4e20();

  local_4 = (float)fVar3;

  uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb8 + param_1);

  if ((uVar2 & 0x1000) == 0) {

    if ((uVar2 & 0x4000) != 0) {

      local_4 = local_4 + DAT_00a0f70c;

    }

  }

  else {

    local_4 = local_4 - DAT_00a0f710;

  }

  return ((float10)local_4 + (float10)g_flOne) * (float10)*(float *)(param_1 + 0x1f0);

}
