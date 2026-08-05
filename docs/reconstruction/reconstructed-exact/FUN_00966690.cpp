// =============================================================================
// FUN_00966690
// -----------------------------------------------------------------------------
// Stable ID: aa_00966690
// Address:   0x00966690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00966690 @ 0x00966690
// Stable ID: aa_00966690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00966690.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00966690(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  float fVar1;

  float fVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  fVar2 = g_flLevelUpUiBase_Inferred;

  fVar1 = g_flMsToSeconds_Inferred;

  DAT_00d1f048 = param_2;

  param_2[5] = g_flMsToSeconds_Inferred;

  param_2[7] = fVar1;

  param_2[8] = DAT_00aaa688;

  *(uint8_t *)(param_2 + 4) = 1;

  *(uint8_t *)(param_2 + 0xd) = 1;

  param_2[0x10] = 1;

  param_2[10] = 0;

  fVar1 = g_flOne;

  *(uint8_t *)(param_2 + 3) = 0;

  *(uint8_t *)((int)param_2 + 0xd) = 0;

  *(uint8_t *)((int)param_2 + 0xe) = 0;

  *(uint8_t *)((int)param_2 + 0xf) = 0;

  *(uint8_t *)((int)param_2 + 0x11) = 0;

  *(uint8_t *)((int)param_2 + 0x12) = 0;

  param_2[9] = 0;

  *(uint8_t *)(param_2 + 0xb) = 0;

  *(uint8_t *)((int)param_2 + 0x2d) = 0;

  *(uint8_t *)((int)param_2 + 0x2e) = 0;

  *(uint8_t *)((int)param_2 + 0x2f) = 0;

  *(uint8_t *)((int)param_2 + 0x35) = 0;

  *(uint8_t *)((int)param_2 + 0x36) = 0;

  *(uint8_t *)((int)param_2 + 0x37) = 0;

  *(uint8_t *)(param_2 + 0xe) = 0;

  param_2[6] = fVar2;

  param_2[0xc] = fVar1;

  puVar4 = &DAT_00d0e128;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  puVar4 = &DAT_00d0e0e8;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  DAT_00d1a568 = 0;

  DAT_00d1a564 = 0;

  DAT_00d1a558 = 0;

  DAT_00d1a55c = 0;

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  param_2[0xf] = 0;

  return param_2;

}
