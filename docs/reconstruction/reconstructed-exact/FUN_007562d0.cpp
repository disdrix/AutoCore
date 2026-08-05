// =============================================================================
// FUN_007562d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007562d0
// Address:   0x007562d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007562d0 @ 0x007562d0
// Stable ID: aa_007562d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0076c4d0×2, FUN_00755db0, FUN_00755e80, FUN_007562d0.
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

void FUN_007562d0(void)



{

  char cVar1;

  int extraout_ECX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  *(uint8_t *)(unaff_ESI + 0x48) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40);

  FUN_0076c4d0();

  *(uint8_t *)(unaff_ESI + 0x48) = 1;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x34) = *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x30);

  FUN_0076c4d0();

  cVar1 = (**(code **)(**(int **)(unaff_ESI + 8) + 8))();

  if (cVar1 != '\0') {

    FUN_00755db0(unaff_EDI);

    FUN_00755e80(unaff_EDI);

  }

  if (unaff_EDI != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*unaff_EDI)(1);

  }

  return;

}
