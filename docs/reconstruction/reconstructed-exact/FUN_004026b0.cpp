// =============================================================================
// FUN_004026b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004026b0
// Address:   0x004026b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004026b0 @ 0x004026b0
// Stable ID: aa_004026b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004026b0, FUN_00402ed0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004026b0; evidence only — no invented semantics):
//  - Entry: `void FUN_004026b0(void)`.
//  - Loops: for (iVar1 = 0x26; iVar1 != 0; iVar1 = iVar1 + -1).
//  - Calls: FUN_00402ed0().
//  - Returns (1 site(s)): `void`.




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

void FUN_004026b0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ auStack_138 [38];

  uint32_t /* width from decompiler */ local_98 [32];

  uint8_t local_18;

  uint8_t local_17;

  uint8_t local_16;

  uint8_t local_15;

  

  local_16 = 0xff;

  local_17 = 0xff;

  local_18 = 0xff;

  local_15 = 0xff;

  puVar2 = local_98;

  puVar3 = auStack_138;

  for (iVar1 = 0x26; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  FUN_00402ed0();

  return;

}
