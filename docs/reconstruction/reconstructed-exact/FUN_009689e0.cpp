// =============================================================================
// FUN_009689e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009689e0
// Address:   0x009689e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009689e0 @ 0x009689e0
// Stable ID: aa_009689e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_0075b3e0, FUN_0075cbd0, FUN_0076c3c0, FUN_0076c4d0, FUN_009689e0.
//  - Return sites: 4.

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

int __fastcall FUN_009689e0(int param_1)



{

  uint uVar1;

  int iVar2;

  

  if ((*(char *)(param_1 + 400) == '\0') ||

     (uVar1 = FUN_0076c3c0(), uVar1 < *(uint *)(param_1 + 0x184))) {

    return 0;

  }

  iVar2 = FUN_0075b3e0(param_1);

  if (iVar2 < 0) {

    return iVar2;

  }

  if (*(int *)(param_1 + 0x44) != 0) {

    iVar2 = FUN_0075cbd0(&DAT_00d1f024,3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x180);

    FUN_0076c4d0();

    return iVar2;

  }

  return -1;

}
