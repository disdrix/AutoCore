// =============================================================================
// FUN_005b4d30
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4d30
// Address:   0x005b4d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4d30 @ 0x005b4d30
// Stable ID: aa_005b4d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005b4a30, FUN_005b4d30, FUN_0068a4d0, ROUND.
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

void __fastcall FUN_005b4d30(int param_1)



{

  int iVar1;

  

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),1,0xffffffff,0xffffffff,0xffffffff);

  if (g_flZero < *(float *)(*(int *)(param_1 + 0x50) + 0x38)) {

    FUN_005b4a30();

    (**(code **)(*DAT_00d1f610 + 0x1c))

              (DAT_00d1f610,0x18,(int)ROUND(*(float *)(*(int *)(param_1 + 0x50) + 0x38)));

    iVar1 = *(int *)(param_1 + 0x60);

    if (((iVar1 != 0) && (-1 < **(int **)(param_1 + 0x50))) &&

       (*(short *)(iVar1 + **(int **)(param_1 + 0x50) * 2) != 0)) {

      (**(code **)(*DAT_00b05340 + 0x148))

                (DAT_00b05340,5,0,0,(short)(*(int **)(param_1 + 0x50))[4],0,

                 *(ushort *)(iVar1 + **(int **)(param_1 + 0x50) * 2) - 2);

    }

  }

  return;

}
