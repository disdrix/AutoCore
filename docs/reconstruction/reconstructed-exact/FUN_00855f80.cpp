// =============================================================================
// FUN_00855f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00855f80
// Address:   0x00855f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00855f80 @ 0x00855f80
// Stable ID: aa_00855f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00854f80, FUN_00855000, FUN_008555e0, FUN_00855f80.
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

void __fastcall FUN_00855f80(int *param_1)



{

  int iVar1;

  

  if (((int *)param_1[0x140] != (int *)0x0) &&

     (iVar1 = (**(code **)(*(int *)param_1[0x140] + 0x1dc))(), iVar1 != 0)) {

    param_1[0xa6] = *(int *)(iVar1 + 0x48);

    (**(code **)(*param_1 + 0x2ac))();

    (**(code **)(*param_1 + 0x48))();

    FUN_008555e0();

    FUN_00855000(iVar1);

    FUN_00854f80();

    if (param_1[0xa9] != 0) {

      *(uint32_t /* width from decompiler */ *)(param_1[0xa9] + 0x184) = 0;

    }

  }

  return;

}
