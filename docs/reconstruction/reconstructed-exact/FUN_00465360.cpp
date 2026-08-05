// =============================================================================
// FUN_00465360
// -----------------------------------------------------------------------------
// Stable ID: aa_00465360
// Address:   0x00465360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00465360 @ 0x00465360
// Stable ID: aa_00465360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00465360, FUN_004653e0.
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

void FUN_00465360(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  

  if ((*(char *)(in_EAX + 0x1c8) != '\0') && (*(char *)(in_EAX + 0x1d0) == '\0')) {

    FUN_004653e0();

    *(int *)(in_EAX + 0xdc) = *(int *)(in_EAX + 0xdc) + 1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x200) = in_XMM0_Da;

    *(uint8_t *)(in_EAX + 0x1d0) = 1;

  }

  return;

}
