// =============================================================================
// FUN_0073b160
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b160
// Address:   0x0073b160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b160 @ 0x0073b160
// Stable ID: aa_0073b160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0073b160.
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

void __fastcall FUN_0073b160(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[4];

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    (**(code **)(*param_1 + 0x20))(puVar2[5],puVar2 + 2);

  }

  return;

}
