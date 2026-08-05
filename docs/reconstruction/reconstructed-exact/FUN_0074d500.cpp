// =============================================================================
// FUN_0074d500
// -----------------------------------------------------------------------------
// Stable ID: aa_0074d500
// Address:   0x0074d500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074d500 @ 0x0074d500
// Stable ID: aa_0074d500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0074d500.
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

void __fastcall FUN_0074d500(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[5];

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    puVar2[3] = puVar2[3] & 0xfffffffb;

    (**(code **)(*param_1 + 0x28))(puVar2[2],puVar2 + 3);

  }

  return;

}
