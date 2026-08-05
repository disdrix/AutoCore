// =============================================================================
// FUN_006c5d80
// -----------------------------------------------------------------------------
// Stable ID: aa_006c5d80
// Address:   0x006c5d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c5d80 @ 0x006c5d80
// Stable ID: aa_006c5d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005ffdb0, FUN_006c5c90, FUN_006c5d80.
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

void __fastcall FUN_006c5d80(uint32_t /* width from decompiler */ *param_1)



{

  short *psVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *param_1 = &PTR_FUN_00a0d348;

  FUN_006c5c90();

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[3];

  *param_1 = &PTR_FUN_00a0d314;

  psVar1 = (short *)((int)puVar2 + 6);

  *psVar1 = *psVar1 + -1;

  if (*psVar1 == 0) {

    (**(code **)*puVar2)(1);

  }

  *param_1 = &PTR_FUN_009d81e8;

  if ((short)*(ushort *)(param_1 + 1) < 0) {

    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;

    FUN_005ffdb0(0);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
