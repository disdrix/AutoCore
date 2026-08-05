// =============================================================================
// FUN_008834e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008834e0
// Address:   0x008834e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008834e0 @ 0x008834e0
// Stable ID: aa_008834e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_007916e0, FUN_008829d0, FUN_008834e0.
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

void __thiscall FUN_008834e0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  

  FUN_007916e0(param_2);

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && ((char)param_2 != '\0')) {

    if (param_1[0x149] != 0) {

      (**(code **)(*(int *)param_1[0x149] + 0xcc))(0);

    }

    FUN_008829d0(1);

    if (param_1[0x154] != 0) {

      (**(code **)(*(int *)param_1[0x154] + 0xcc))(0);

    }

    if (param_1[0x155] != 0) {

      (**(code **)(*(int *)param_1[0x155] + 0xcc))(0);

    }

    if (param_1[0x156] != 0) {

      (**(code **)(*(int *)param_1[0x156] + 0xcc))(0);

    }

    if (param_1[0x14c] != 0) {

      (**(code **)(*(int *)param_1[0x14c] + 0xcc))(0);

    }

    if (param_1[0x14d] != 0) {

      (**(code **)(*(int *)param_1[0x14d] + 0xcc))(0);

    }

    if (param_1[0x157] != 0) {

      (**(code **)(*(int *)param_1[0x157] + 0xcc))(0);

    }

    (**(code **)(*param_1 + 0x448))();

  }

  return;

}
