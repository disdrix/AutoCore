// =============================================================================
// FUN_00747880
// -----------------------------------------------------------------------------
// Stable ID: aa_00747880
// Address:   0x00747880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00747880 @ 0x00747880
// Stable ID: aa_00747880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_0044c3c0, FUN_00746d00, FUN_00747880.
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

uint32_t /* width from decompiler */ __fastcall FUN_00747880(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar1;

  

  if ((0 < param_1) && (in_EAX != (uint32_t /* width from decompiler */ *)0x0)) {

    FUN_0044c3c0(0,0);

    puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

    for (param_1 = param_1 * 2; param_1 != 0; param_1 = param_1 + -1) {

      *puVar1 = *in_EAX;

      in_EAX = in_EAX + 1;

      puVar1 = puVar1 + 1;

    }

    FUN_00746d00();

    return 0;

  }

  return 0xffffffff;

}
