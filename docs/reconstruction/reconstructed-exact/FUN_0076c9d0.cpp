// =============================================================================
// FUN_0076c9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c9d0
// Address:   0x0076c9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c9d0 @ 0x0076c9d0
// Stable ID: aa_0076c9d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0076c9d0×2.
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

void __fastcall FUN_0076c9d0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0x40);

  iVar1 = *(int *)(param_1 + 0x44);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  for (; iVar2 != iVar1; iVar2 = iVar2 + 4) {

    FUN_0076c9d0();

  }

  return;

}
