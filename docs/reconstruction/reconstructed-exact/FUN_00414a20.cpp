// =============================================================================
// FUN_00414a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00414a20
// Address:   0x00414a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00414a20 @ 0x00414a20
// Stable ID: aa_00414a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00414a20, FUN_00418700, FUN_00418790.
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

void FUN_00414a20(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int iVar2;

  int unaff_EBX;

  

  iVar1 = *(int *)(unaff_EBX + 4);

  iVar2 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),in_EAX);

  FUN_00418790();

  *(int *)(iVar1 + 4) = iVar2;

  **(int **)(iVar2 + 4) = iVar2;

  return;

}
