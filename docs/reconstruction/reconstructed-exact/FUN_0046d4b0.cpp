// =============================================================================
// FUN_0046d4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046d4b0
// Address:   0x0046d4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046d4b0 @ 0x0046d4b0
// Stable ID: aa_0046d4b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0046d4b0.
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

void FUN_0046d4b0(void)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_ESI;

  

  if (*(void **)(unaff_ESI + 0x2c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x2c));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34) = 0;

                    /* WARNING: Could not recover jumptable at 0x0046d4d7. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(unaff_ESI);

  return;

}
