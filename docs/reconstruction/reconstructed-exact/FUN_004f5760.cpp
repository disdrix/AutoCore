// =============================================================================
// FUN_004f5760
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5760
// Address:   0x004f5760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f5760 @ 0x004f5760
// Stable ID: aa_004f5760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004f5760, SQRT.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __fastcall FUN_004f5760(int param_1)



{

  int iVar1;

  int *piVar2;

  float fVar3;

  float10 fVar4;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_c = 0.0;

  if (*(int *)(param_1 + -0x668) != 0) {

    iVar1 = *(int *)(*(int *)(param_1 + -0x668) + 0x3c);

    fVar3 = SQRT(*(float *)(iVar1 + 0x48) * *(float *)(iVar1 + 0x48) +

                 *(float *)(iVar1 + 0x44) * *(float *)(iVar1 + 0x44) +

                 *(float *)(iVar1 + 0x40) * *(float *)(iVar1 + 0x40));

    if (fVar3 <= g_flVehicleHpTechCoeff) {

      local_c = 0.0;

    }

    else {

      local_c = fVar3 * _DAT_009cd1ec * 0.6931472;

    }

  }

  iVar1 = *(int *)(param_1 + -0x41c);

  local_8 = 0.0;

  if (iVar1 != 0) {

    local_8 = (float)*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) +

                                      0x3c) + 0x4c0);

  }

  piVar2 = *(int **)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1);

  if (piVar2 != (int *)0x0) {

    fVar3 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c4 + param_1

                                        ) + 0x3c) + 0x710);

    fVar4 = (float10)(**(code **)(*piVar2 + 0xd0))();

    return fVar4 + (float10)fVar3 + (float10)local_8 + (float10)local_c;

  }

  return (float10)local_8 + (float10)local_c + (float10)g_flOne;

}
