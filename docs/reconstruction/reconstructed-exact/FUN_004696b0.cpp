// =============================================================================
// FUN_004696b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004696b0
// Address:   0x004696b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004696b0 @ 0x004696b0
// Stable ID: aa_004696b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004696b0.
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

int __fastcall FUN_004696b0(int param_1)



{

  int iVar1;

  

  if (*(char *)(param_1 + 0x10) != '\0') {

    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14),0);

    if (iVar1 < 0) {

      return -1;

    }

  }

  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),0);

  if (-1 < iVar1) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  }

  return iVar1;

}
