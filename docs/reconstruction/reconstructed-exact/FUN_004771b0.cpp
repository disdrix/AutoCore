// =============================================================================
// FUN_004771b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004771b0
// Address:   0x004771b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004771b0 @ 0x004771b0
// Stable ID: aa_004771b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004771b0.
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

void FUN_004771b0(byte param_1,int param_2)



{

  int in_EAX;

  

  *(byte *)(in_EAX + 0x71) = *(byte *)(in_EAX + 0x71) | 0x80;

  *(ushort *)(in_EAX + 0x12e) = (ushort)param_1;

  if (param_2 == 1) {

    *(byte *)(in_EAX + 0x6c) = *(byte *)(in_EAX + 0x6c) | 0x80;

  }

  else {

    *(byte *)(in_EAX + 0x6c) = *(byte *)(in_EAX + 0x6c) & 0x7f;

  }

  if (*(char *)(in_EAX + 0x126) == '\x02') {

    *(uint8_t *)(in_EAX + 299) = 4;

  }

  if ((*(char *)(in_EAX + 0x126) == '\0') && (7 < *(byte *)(in_EAX + 0x127))) {

    *(uint8_t *)(in_EAX + 299) = 2;

  }

  return;

}
