// =============================================================================
// FUN_00477140
// -----------------------------------------------------------------------------
// Stable ID: aa_00477140
// Address:   0x00477140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477140 @ 0x00477140
// Stable ID: aa_00477140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00476d60×2, FUN_00477140.
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

void __fastcall FUN_00477140(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int in_EAX;

  

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x54) = param_1;

  if (in_EAX == 0) {

    *(uint8_t **)(param_2 + 0x50) = &LAB_00477100;

  }

  else {

    *(int *)(param_2 + 0x50) = in_EAX;

  }

  if (*(int *)(param_2 + 0x4c) != 0) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c) = 0;

    FUN_00476d60();

    FUN_00476d60();

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x14c) = 0;

  return;

}
