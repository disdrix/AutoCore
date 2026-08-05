// =============================================================================
// FUN_00636f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00636f00
// Address:   0x00636f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636f00 @ 0x00636f00
// Stable ID: aa_00636f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~231 non-empty decompiler lines.
//  - Control keywords: if×16, for×3, do×1, while×1, return×1.
//  - Notable callees: BitStream_readBits×4, CONCAT31×2, free×2, BitStream_readFlag, EMSG_Sector_Damage_Unpack, FUN_0042b250, FUN_0042b270, FUN_0042b3a0.
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

uint32_t /* width from decompiler */ * EMSG_Sector_Damage_Unpack(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  bool bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ **ppuVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  ushort local_17c [2];

  uint32_t /* width from decompiler */ *local_178;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ local_170;

  int local_16c;

  int local_168;

  uint32_t /* width from decompiler */ *local_164 [4];

  uint8_t local_154;

  uint local_14c;

  uint32_t /* width from decompiler */ *local_148;

  undefined **local_144;

  void *local_138;

  char local_130;

  uint local_12c;

  uint8_t local_128;

  uint local_118;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a8cf5;

  local_c = ExceptionList;

  local_170 = 0;

  local_4 = 1;

  local_164[0] = (uint32_t /* width from decompiler */ *)0x2023;

  ExceptionList = &local_c;

  FUN_0042b3a0(param_2[3],param_2[4]);

  local_4 = CONCAT31(local_4._1_3_,2);

  BitStream_readBits(0x40,&local_178);

  BitStream_readFlag(local_17c);

  local_164[2] = local_178;

  local_154 = (uint8_t)local_17c[0];

  local_164[3] = (uint32_t /* width from decompiler */ *)local_174;

  BitStream_readBits(0x10,local_17c);

  uVar6 = (uint)local_17c[0];

  puVar5 = (uint32_t /* width from decompiler */ *)(uVar6 * 0x20);

  local_178 = puVar5;

  local_14c = uVar6;

  local_148 = operator_new__((uint)puVar5);

  if (uVar6 != 0) {

    piVar8 = local_148 + 4;

    do {

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)(piVar8 + 1) = bVar1;

      BitStream_readBits(0x10,local_17c);

      *piVar8 = (int)(short)local_17c[0];

      BitStream_readBits(0x40,&local_16c);

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      piVar8[-4] = local_16c;

      piVar8[-3] = local_168;

      *(bool *)(piVar8 + -2) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)((int)piVar8 + 0xb) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)(piVar8 + 3) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)((int)piVar8 + 0xd) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)((int)piVar8 + 5) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)((int)piVar8 + 6) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)((int)piVar8 + 7) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)(piVar8 + 2) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)((int)piVar8 + 9) = bVar1;

      if (local_118 < local_12c) {

        local_128 = 1;

        bVar1 = false;

      }

      else {

        bVar1 = (*(byte *)((local_12c >> 3) + (int)local_138) & (byte)(1 << ((byte)local_12c & 7)))

                != 0;

        local_12c = local_12c + 1;

      }

      *(bool *)((int)piVar8 + 10) = bVar1;

      piVar8 = piVar8 + 8;

      uVar6 = uVar6 - 1;

    } while (uVar6 != 0);

  }

  puVar5 = puVar5 + 7;

  puVar2 = malloc((size_t)puVar5);

  ppuVar7 = local_164;

  puVar3 = puVar2;

  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar3 = *ppuVar7;

    ppuVar7 = ppuVar7 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar3 = local_148;

  puVar9 = puVar2 + 7;

  for (uVar6 = (uint)local_178 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *puVar9 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar9 = puVar9 + 1;

  }

  for (uVar6 = (uint)local_178 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint8_t *)puVar9 = *(uint8_t *)puVar3;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

  }

  operator_delete__(local_148);

  puVar3 = operator_new(0x18);

  local_4 = CONCAT31(local_4._1_3_,3);

  local_178 = puVar3;

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0042b250();

    *puVar3 = &PTR_LAB_009d7b00;

    puVar3[4] = puVar5;

    puVar3[3] = puVar2;

    *(uint8_t *)(puVar3 + 5) = 0;

  }

  if (*(char *)(puVar3 + 5) != '\0') {

    *(uint8_t *)(puVar3 + 5) = 0;

    free((void *)puVar3[3]);

  }

  puVar3[4] = puVar5;

  puVar3[3] = puVar2;

  *(uint8_t *)(puVar3 + 5) = 1;

  *param_1 = puVar3;

  puVar3[2] = puVar3[2] + 1;

  local_170 = 1;

  local_4._0_1_ = 1;

  local_144 = &PTR_LAB_009d7b00;

  if (local_130 != '\0') {

    free(local_138);

  }

  FUN_0042b270();

  piVar8 = param_2 + 2;

  *piVar8 = *piVar8 + -1;

  local_4 = (uint)local_4._1_3_ << 8;

  if (*piVar8 == 0) {

    (**(code **)(*param_2 + 8))();

  }

  ExceptionList = local_c;

  return param_1;

}
