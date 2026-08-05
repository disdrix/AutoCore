// =============================================================================
// FUN_004b9270
// -----------------------------------------------------------------------------
// Stable ID: aa_004b9270
// Address:   0x004b9270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b9270 @ 0x004b9270
// Stable ID: aa_004b9270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004b9270, FUN_004ba7b0, FUN_006759b0.
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

void FUN_004b9270(uint *param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = DAT_00b03714;

  iVar2 = FUN_006759b0(DAT_00b03714,*(uint32_t /* width from decompiler */ *)(DAT_00b03714 + 4),&param_1);

  FUN_004ba7b0(1);

  *(int *)(iVar1 + 4) = iVar2;

  **(int **)(iVar2 + 4) = iVar2;

  *param_1 = *param_1 | 1;

  return;

}
