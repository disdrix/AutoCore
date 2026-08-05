// =============================================================================
// FUN_00455b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00455b10
// Address:   0x00455b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00455b10 @ 0x00455b10
// Stable ID: aa_00455b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00453070, FUN_00455b10.
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

void FUN_00455b10(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  *unaff_ESI = *in_EAX;

  unaff_ESI[1] = in_EAX[1];

  unaff_ESI[2] = in_EAX[2];

  unaff_ESI[3] = in_EAX[3];

  unaff_ESI[4] = in_EAX[4];

  unaff_ESI[5] = in_EAX[5];

  unaff_ESI[6] = in_EAX[6];

  unaff_ESI[7] = in_EAX[7];

  unaff_ESI[8] = in_EAX[8];

  unaff_ESI[9] = in_EAX[9];

  unaff_ESI[10] = in_EAX[10];

  FUN_00453070(unaff_ESI + 0xb);

  return;

}
