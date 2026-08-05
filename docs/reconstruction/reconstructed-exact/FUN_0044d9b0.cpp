// =============================================================================
// FUN_0044d9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d9b0
// Address:   0x0044d9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044d9b0 @ 0x0044d9b0
// Stable ID: aa_0044d9b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_0044d9b0.
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

void FUN_0044d9b0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EDI;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 8);

  puVar3 = param_1;

  puVar2 = param_1;

  while (puVar2 = puVar2 + 1, puVar2 != puVar1) {

    if (puVar3 != puVar2) {

      *puVar3 = *puVar2;

    }

    puVar3 = puVar3 + 1;

  }

  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + -4;

  *in_EAX = param_1;

  return;

}
