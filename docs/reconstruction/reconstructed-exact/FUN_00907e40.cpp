// =============================================================================
// FUN_00907e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00907e40
// Address:   0x00907e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907e40 @ 0x00907e40
// Stable ID: aa_00907e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00790730, FUN_00907e40.
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

uint32_t /* width from decompiler */ __thiscall FUN_00907e40(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_1[0x1c6] != 0)) {

    cVar1 = (**(code **)(*(int *)param_1[0x1c6] + 0x378))(param_2,param_3);

    if (cVar1 != '\0') {

      return 1;

    }

  }

  uVar2 = FUN_00790730(param_2,param_3);

  return uVar2;

}
