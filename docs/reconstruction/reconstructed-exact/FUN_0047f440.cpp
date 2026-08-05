// =============================================================================
// FUN_0047f440
// -----------------------------------------------------------------------------
// Stable ID: aa_0047f440
// Address:   0x0047f440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047f440 @ 0x0047f440
// Stable ID: aa_0047f440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0047f440.
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

void FUN_0047f440(void)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x16b4) == 0x10) {

    *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

         *(uint8_t *)(in_EAX + 0x16b0);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

         *(uint8_t *)(in_EAX + 0x16b1);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x16b4) = 0;

    *(uint16_t *)(in_EAX + 0x16b0) = 0;

    return;

  }

  if (7 < *(int *)(in_EAX + 0x16b4)) {

    *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

         *(uint8_t *)(in_EAX + 0x16b0);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(int *)(in_EAX + 0x16b4) = *(int *)(in_EAX + 0x16b4) + -8;

    *(ushort *)(in_EAX + 0x16b0) = (ushort)*(byte *)(in_EAX + 0x16b1);

  }

  return;

}
