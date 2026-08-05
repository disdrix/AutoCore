// =============================================================================
// FUN_0075d230
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d230
// Address:   0x0075d230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075d230 @ 0x0075d230
// Stable ID: aa_0075d230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043d5e0, FUN_0075d230.
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

uint32_t /* width from decompiler */ FUN_0075d230(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_0043d5e0();

  if (local_4 != *(int *)(unaff_EDI + 0x5c)) {

    uVar1 = (**(code **)(local_4 + 0x10))

                      (in_EAX + 4,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x14),param_1,

                       *(uint32_t /* width from decompiler */ *)(local_4 + 0x14));

    return uVar1;

  }

  return 0;

}
