// =============================================================================
// FUN_005536c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005536c0
// Address:   0x005536c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005536c0 @ 0x005536c0
// Stable ID: aa_005536c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT22, FUN_00552f50, FUN_005535c0, FUN_005536c0, Skill_ReevaluateForCurrentRank.
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

void __thiscall FUN_005536c0(void *param_1,uint32_t /* width from decompiler */ param_2)



{

  short sVar1;

  int iVar2;

  uint16_t extraout_var;

  

  sVar1 = *(short *)((int)param_1 + 0x174);

  iVar2 = FUN_00552f50(param_2);

  if ((0 < sVar1) && (iVar2 < (int)*(short *)((int)param_1 + 0x5f6) + (int)sVar1)) {

    FUN_005535c0(iVar2 - CONCAT22(extraout_var,*(short *)((int)param_1 + 0x5f6)),param_2);

    Skill_ReevaluateForCurrentRank(param_1);

  }

  return;

}
