// =============================================================================
// FUN_004624b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004624b0
// Address:   0x004624b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004624b0 @ 0x004624b0
// Stable ID: aa_004624b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00462340, FUN_004624b0, FUN_004635a0.
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

void FUN_004624b0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int unaff_EBX;

  int iVar2;

  

  FUN_004635a0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),param_2,param_2);

  iVar1 = *(int *)(unaff_EBX + 8);

  for (iVar2 = iVar1 + -0x20; iVar2 != iVar1; iVar2 = iVar2 + 0x20) {

    FUN_00462340();

  }

  *(int *)(unaff_EBX + 8) = *(int *)(unaff_EBX + 8) + -0x20;

  *param_1 = param_2;

  return;

}
