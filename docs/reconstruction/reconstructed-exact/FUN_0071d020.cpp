// =============================================================================
// FUN_0071d020
// -----------------------------------------------------------------------------
// Stable ID: aa_0071d020
// Address:   0x0071d020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071d020 @ 0x0071d020
// Stable ID: aa_0071d020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, for×2, return×1.
//  - Notable callees: FUN_0071cc40×2, CONCAT11, CONCAT21, CONCAT31, FUN_0071d020.
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

uint32_t /* width from decompiler */ FUN_0071d020(uint32_t /* width from decompiler */ *param_1,int param_2,short param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint *puVar3;

  uint *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int local_8;

  int local_4;

  

  puVar3 = &DAT_00afa9c0;

  puVar4 = param_1 + 0x400;

  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  puVar1 = &DAT_00afaa08;

  puVar5 = param_1;

  for (iVar2 = 0x400; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = *puVar1;

    puVar1 = puVar1 + 1;

    puVar5 = puVar5 + 1;

  }

  iVar6 = (int)param_3;

  iVar2 = 0;

  local_8 = 0x12;

  puVar3 = param_1 + 0x400;

  do {

    iVar2 = (int)(short)iVar2;

    *puVar3 = *puVar3 ^ CONCAT31(CONCAT21(CONCAT11(*(uint8_t *)(iVar2 + param_2),

                                                   *(uint8_t *)((iVar2 + 1) % iVar6 + param_2)),

                                          *(uint8_t *)((iVar2 + 2) % iVar6 + param_2)),

                                 *(uint8_t *)((iVar2 + 3) % iVar6 + param_2));

    iVar2 = (iVar2 + 4) % iVar6;

    local_8 = local_8 + -1;

    puVar3 = puVar3 + 1;

  } while (local_8 != 0);

  param_1 = param_1 + 0x401;

  iVar2 = 9;

  do {

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_0071cc40();

    param_1[-1] = 0;

    *param_1 = 0;

    param_1 = param_1 + 2;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  local_4 = 4;

  do {

    iVar2 = 0x80;

    do {

      FUN_0071cc40();

      *puVar1 = 0;

      puVar1[1] = 0;

      puVar1 = puVar1 + 2;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  return 0;

}
