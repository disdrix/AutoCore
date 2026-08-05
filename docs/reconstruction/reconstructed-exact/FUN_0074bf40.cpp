// =============================================================================
// FUN_0074bf40
// -----------------------------------------------------------------------------
// Stable ID: aa_0074bf40
// Address:   0x0074bf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074bf40 @ 0x0074bf40
// Stable ID: aa_0074bf40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0074bf40, FUN_00972fa0.
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

uint32_t /* width from decompiler */ FUN_0074bf40(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  int unaff_ESI;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_00972fa0(in_EAX);

  if ((((local_c <= *(float *)(unaff_ESI + 0x20)) && (*(float *)(unaff_ESI + 0x14) <= local_c)) &&

      (local_8 <= *(float *)(unaff_ESI + 0x24))) &&

     (((*(float *)(unaff_ESI + 0x18) <= local_8 && (local_4 <= *(float *)(unaff_ESI + 0x28))) &&

      (*(float *)(unaff_ESI + 0x1c) <= local_4)))) {

    return 1;

  }

  return 0;

}
