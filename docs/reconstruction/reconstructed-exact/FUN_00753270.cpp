// =============================================================================
// FUN_00753270
// -----------------------------------------------------------------------------
// Stable ID: aa_00753270
// Address:   0x00753270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753270 @ 0x00753270
// Stable ID: aa_00753270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00752a80, FUN_00752ba0, FUN_00753270.
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

int FUN_00753270(void)



{

  int in_EAX;

  int iVar1;

  int unaff_ESI;

  

  iVar1 = FUN_00752ba0();

  if (-1 < iVar1) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20);

    FUN_00752a80();

  }

  return iVar1;

}
