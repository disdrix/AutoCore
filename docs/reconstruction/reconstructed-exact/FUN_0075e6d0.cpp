// =============================================================================
// FUN_0075e6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e6d0
// Address:   0x0075e6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075e6d0 @ 0x0075e6d0
// Stable ID: aa_0075e6d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0075e6d0.
//  - Return sites: 3.

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

byte FUN_0075e6d0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  

  iVar1 = (**(code **)(*(int *)*in_EAX + 0xc))((int *)*in_EAX);

  if (iVar1 == -0x7789f7d9) {

    return 3;

  }

  if (iVar1 != -0x7789f798) {

    return (iVar1 != -0x7789f797) - 1U & 2;

  }

  return 1;

}
