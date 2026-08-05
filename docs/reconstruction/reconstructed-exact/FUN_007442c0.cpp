// =============================================================================
// FUN_007442c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007442c0
// Address:   0x007442c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007442c0 @ 0x007442c0
// Stable ID: aa_007442c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0041fa50, FUN_0044de90, FUN_007442c0, FUN_0076c500.
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

void FUN_007442c0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ local_38 [14];

  

  if (*(char *)(in_EAX + 0x2c) != '\0') {

    local_38[0] = 0;

    FUN_0076c500(1000000);

    iVar1 = *(int *)(in_EAX + 0x34);

    local_38[0] = param_1;

    iVar2 = FUN_0041fa50(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),local_38);

    FUN_0044de90();

    *(int *)(iVar1 + 4) = iVar2;

    **(int **)(iVar2 + 4) = iVar2;

  }

  return;

}
