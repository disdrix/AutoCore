// =============================================================================
// FUN_00755fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00755fc0
// Address:   0x00755fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755fc0 @ 0x00755fc0
// Stable ID: aa_00755fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00755fc0, FUN_0076c4d0.
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

void FUN_00755fc0(void)



{

  int unaff_ESI;

  int unaff_EDI;

  undefined **local_8;

  

  *(uint8_t *)(unaff_ESI + 0x48) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40);

  FUN_0076c4d0();

  local_8 = &PTR_LAB_00a9f4d8;

  if (unaff_EDI != 0) {

    (**(code **)(**(int **)(unaff_ESI + 8) + 0x1c))(&local_8);

    (**(code **)(**(int **)(unaff_ESI + 8) + 0x14))();

    return;

  }

  (**(code **)(**(int **)(unaff_ESI + 8) + 0x20))(&local_8);

  (**(code **)(**(int **)(unaff_ESI + 8) + 0x14))();

  return;

}
