// =============================================================================
// FUN_0056cf00
// -----------------------------------------------------------------------------
// Stable ID: aa_0056cf00
// Address:   0x0056cf00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056cf00 @ 0x0056cf00
// Stable ID: aa_0056cf00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004ceba0, FUN_0056ce90, FUN_0056cf00.
//  - Return sites: 1.

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

float10 __thiscall FUN_0056cf00(int param_1,float param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  float10 fVar2;

  

  fVar2 = (float10)FUN_0056ce90(param_2);

  fVar2 = (float10)FUN_004ceba0((float)(int)*(short *)(param_1 + 0x10c) +

                                *(float *)(param_1 + 0x114),0,(float)fVar2,param_2,param_3,param_4);

  param_2 = (float)fVar2;

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x214))();

  if (iVar1 != 0) {

    param_2 = *(float *)(param_1 + 0x11c) + param_2;

  }

  return (float10)param_2;

}
