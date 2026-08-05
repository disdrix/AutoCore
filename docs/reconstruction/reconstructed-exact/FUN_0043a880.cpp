// =============================================================================
// FUN_0043a880
// -----------------------------------------------------------------------------
// Stable ID: aa_0043a880
// Address:   0x0043a880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043a880 @ 0x0043a880
// Stable ID: aa_0043a880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00437b60, FUN_0043a090, FUN_0043a880.
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

int __fastcall FUN_0043a880(int param_1)



{

  int in_EAX;

  int unaff_EBX;

  

  for (; unaff_EBX != param_1; param_1 = param_1 + -0x28) {

    FUN_0043a090();

    *(uint32_t /* width from decompiler */ *)(in_EAX + -0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x18);

    *(uint32_t /* width from decompiler */ *)(in_EAX + -0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + -0x14);

    FUN_00437b60();

    in_EAX = in_EAX + -0x28;

  }

  return in_EAX;

}
