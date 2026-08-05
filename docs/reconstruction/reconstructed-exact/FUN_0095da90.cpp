// =============================================================================
// FUN_0095da90
// -----------------------------------------------------------------------------
// Stable ID: aa_0095da90
// Address:   0x0095da90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095da90 @ 0x0095da90
// Stable ID: aa_0095da90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_007633d0, FUN_007647c0, FUN_0095da90.
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

void FUN_0095da90(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar3 = DAT_00d1ef94;

  puVar1 = DAT_00d1ef84;

  for (puVar4 = DAT_00d1ef90; DAT_00d1ef84 = puVar1, puVar2 = DAT_00d1ef80, puVar4 != puVar3;

      puVar4 = puVar4 + 2) {

    FUN_007647c0(*puVar4);

    puVar1 = DAT_00d1ef84;

  }

  for (; puVar2 != puVar1; puVar2 = puVar2 + 2) {

    FUN_007633d0(unaff_EBX,*puVar2);

  }

  return;

}
