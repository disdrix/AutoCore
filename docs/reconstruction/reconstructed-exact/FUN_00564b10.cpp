// =============================================================================
// FUN_00564b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00564b10
// Address:   0x00564b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00564b10 @ 0x00564b10
// Stable ID: aa_00564b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00563fe0, FUN_00564b10, FUN_00581c70, Object_GetRootRaceId.
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

void __thiscall FUN_00564b10(int param_1,int param_2)



{

  uint *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  RACE_ID_INFERRED RVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int local_28;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

  local_20 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84 + param_2);

  iVar3 = iVar3 + 0x84 + param_2;

  local_1c = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

  local_18 = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

  local_14 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);

  FUN_00563fe0(&local_20);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x9c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = uVar2;

  FUN_00581c70(uVar2);

  *(uint8_t *)(param_1 + 0xa8) = *(uint8_t *)(param_2 + 0xa8);

  *(uint8_t *)(param_1 + 0xa9) = *(uint8_t *)(param_2 + 0xa9);

  *(uint8_t *)(param_1 + 0xb1) = *(uint8_t *)(param_2 + 0xb1);

  *(uint8_t *)(param_1 + 0xb2) = *(uint8_t *)(param_2 + 0xb2);

  *(uint8_t *)(param_1 + 0xb3) = *(uint8_t *)(param_2 + 0xb3);

  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x180 + param_1);

  local_28 = 0xc;

  *puVar1 = *puVar1 ^ ((*(uint *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0x180 + param_2) >> 9 & 0xff

                       ) << 9 ^ *puVar1) & 0x200;

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0xec);

  do {

    puVar6 = (uint32_t /* width from decompiler */ *)((param_2 - param_1) + (int)puVar4);

    *puVar4 = *puVar6;

    puVar4[1] = puVar6[1];

    local_28 = local_28 + -1;

    puVar4[2] = puVar6[2];

    puVar4 = puVar4 + 3;

  } while (local_28 != 0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1b8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x84);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x80);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1a0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1a4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7c);

  *(uint8_t *)(param_1 + 0x1a9) = *(uint8_t *)(param_2 + 0x1a9);

  RVar5 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));

  *(RACE_ID_INFERRED *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x14 + param_1) = RVar5;

  *(uint8_t *)(param_1 + 0x1a8) = *(uint8_t *)(param_2 + 0x1a8);

  return;

}
