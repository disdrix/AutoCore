// =============================================================================
// FUN_006d11e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d11e0
// Address:   0x006d11e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d11e0 @ 0x006d11e0
// Stable ID: aa_006d11e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006d11e0.
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

void __thiscall

FUN_006d11e0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,float *param_4,float *param_5)



{

  int *piVar1;

  float10 fVar2;

  uint8_t local_110 [268];

  

  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 8) + 0x34))(*param_2,local_110);

  if (piVar1 != (int *)0x0) {

    fVar2 = (float10)(**(code **)(*piVar1 + 0x1c))(param_3);

    *param_5 = (float)fVar2;

    fVar2 = (float10)(**(code **)(*piVar1 + 0x1c))(&stack0xfffffed4);

    *param_4 = (float)-fVar2;

    return;

  }

  *param_4 = 0.0;

  *param_5 = 0.0;

  return;

}
