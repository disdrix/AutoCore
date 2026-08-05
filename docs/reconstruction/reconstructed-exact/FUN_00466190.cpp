// =============================================================================
// FUN_00466190
// -----------------------------------------------------------------------------
// Stable ID: aa_00466190
// Address:   0x00466190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00466190 @ 0x00466190
// Stable ID: aa_00466190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00466190, FUN_004661e0.
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

void FUN_00466190(uint8_t *param_1)



{

  uint8_t *in_EAX;

  uint8_t *unaff_EDI;

  

  for (; in_EAX != param_1; in_EAX = in_EAX + 0x24) {

    *in_EAX = *unaff_EDI;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 4);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc);

    in_EAX[0x10] = unaff_EDI[0x10];

    in_EAX[0x11] = unaff_EDI[0x11];

    FUN_004661e0();

  }

  return;

}
