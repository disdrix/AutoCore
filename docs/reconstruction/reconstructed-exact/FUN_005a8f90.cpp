// =============================================================================
// FUN_005a8f90
// -----------------------------------------------------------------------------
// Stable ID: aa_005a8f90
// Address:   0x005a8f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a8f90 @ 0x005a8f90
// Stable ID: aa_005a8f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: ABS, FUN_004b7550, FUN_004b8dc0, FUN_005a8f90.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_005a8f90(int param_1,int param_2,float param_3)



{

  int iVar1;

  float local_c [3];

  

  if (*(int *)(param_1 + 0x124) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2;

  }

  if (((param_2 < iVar1 + -1) && (*(int *)(param_2 * 4 + *(int *)(param_1 + 0x124)) != 0)) &&

     (_DAT_009d8718 < ABS(param_3))) {

    FUN_004b8dc0(1,0);

    local_c[0] = param_3 * DAT_00a0f70c;

    if ((float)g_nInferredThreatDefault < local_c[0]) {

      local_c[0] = (float)g_nInferredThreatDefault;

    }

    FUN_004b7550(local_c,2);

  }

  return;

}
