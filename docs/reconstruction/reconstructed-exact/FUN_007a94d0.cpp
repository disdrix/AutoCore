// =============================================================================
// FUN_007a94d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a94d0
// Address:   0x007a94d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a94d0 @ 0x007a94d0
// Stable ID: aa_007a94d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: block×32, FUN_007a94d0, SysFreeString.
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

/* WARNING: Removing unreachable block (ram,0x007a9526) */

/* WARNING: Removing unreachable block (ram,0x007a9548) */

/* WARNING: Removing unreachable block (ram,0x007a9550) */

/* WARNING: Removing unreachable block (ram,0x007a9588) */

/* WARNING: Removing unreachable block (ram,0x007a9624) */

/* WARNING: Removing unreachable block (ram,0x007a96ab) */

/* WARNING: Removing unreachable block (ram,0x007a9720) */

/* WARNING: Removing unreachable block (ram,0x007a978f) */

/* WARNING: Removing unreachable block (ram,0x007a97fe) */

/* WARNING: Removing unreachable block (ram,0x007a986b) */

/* WARNING: Removing unreachable block (ram,0x007a98d8) */

/* WARNING: Removing unreachable block (ram,0x007a9945) */

/* WARNING: Removing unreachable block (ram,0x007a99b2) */

/* WARNING: Removing unreachable block (ram,0x007a9a1f) */

/* WARNING: Removing unreachable block (ram,0x007a9a8c) */

/* WARNING: Removing unreachable block (ram,0x007a9a32) */

/* WARNING: Removing unreachable block (ram,0x007a99c5) */

/* WARNING: Removing unreachable block (ram,0x007a9958) */

/* WARNING: Removing unreachable block (ram,0x007a98eb) */

/* WARNING: Removing unreachable block (ram,0x007a987e) */

/* WARNING: Removing unreachable block (ram,0x007a9811) */

/* WARNING: Removing unreachable block (ram,0x007a97a2) */

/* WARNING: Removing unreachable block (ram,0x007a9733) */

/* WARNING: Removing unreachable block (ram,0x007a96be) */

/* WARNING: Removing unreachable block (ram,0x007a9637) */

/* WARNING: Removing unreachable block (ram,0x007a95a1) */

/* WARNING: Removing unreachable block (ram,0x007a960d) */

/* WARNING: Removing unreachable block (ram,0x007a9615) */

/* WARNING: Removing unreachable block (ram,0x007a9aa3) */

/* WARNING: Removing unreachable block (ram,0x007a9ac2) */

/* WARNING: Removing unreachable block (ram,0x007a9ac3) */

/* WARNING: Removing unreachable block (ram,0x007a954b) */



void FUN_007a94d0(int *param_1)



{

  BSTR unaff_EDI;

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aba29;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x30))();

  SysFreeString(unaff_EDI);

  ExceptionList = pvStack_14;

  return;

}
