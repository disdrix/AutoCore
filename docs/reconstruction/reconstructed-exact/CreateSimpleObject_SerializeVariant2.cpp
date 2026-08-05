// =============================================================================
// CreateSimpleObject_SerializeVariant2
// -----------------------------------------------------------------------------
// Stable ID: aa_005ca720
// Address:   0x005ca720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

uint32_t /* width from decompiler */ __thiscall CreateSimpleObject_SerializeVariant2(int param_1,uint *param_2)

{
  uint *puVar1;
  char cVar2;
  uint32_t /* width from decompiler */ *puVar3;
  uint32_t /* width from decompiler */ uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint32_t /* width from decompiler */ *puVar8;
  char *pcVar9;
  char *pcVar10;
  uint uVar11;
  ushort *puStack_4;
  
  puVar3 = param_2;
  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {
    return 0;
  }
  *param_2 = 0x2012;
  iVar5 = *(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + param_1 + -100);
  if (iVar5 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x34);
  }
  param_2[1] = uVar4;
  iVar5 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
  param_2[0x24] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x54 + param_1);
  param_2[0x25] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x58 + param_1);
  *(uint8_t *)(param_2 + 0x26) =
       *(uint8_t *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x5c + param_1);
  param_2[4] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x30);
  param_2[5] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c);
  param_2[0x21] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x28);
  *(uint8_t *)(param_2 + 0x22) = *(uint8_t *)(param_1 + -0x20);
  *(uint8_t *)((int)param_2 + 0x89) = *(uint8_t *)(param_1 + -0x1f);
  param_2[6] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x48 + param_1);
  param_2[7] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xfc + param_1);
  param_2[8] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x34);
  param_2[2] = 0xffffffff;
  param_2[3] = 0xffffffff;
  *(byte *)((int)param_2 + 0x8a) =
       (byte)((uint)*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 8)
       & 1;
  *(uint8_t *)((int)param_2 + 0xa3) = *(uint8_t *)(param_1 + -0x1e);
  *(uint8_t *)(param_2 + 0x29) = *(uint8_t *)(param_1 + -0x1d);
  *(uint8_t *)((int)param_2 + 0xa5) = *(uint8_t *)(param_1 + -0x1c);
  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1);
  *puVar1 = *puVar1 | 0x10;
  FUN_00512670();
  *(uint8_t *)((int)param_2 + 0xa6) = 1;
  *(uint8_t *)((int)param_2 + 0xa7) = 0;
  *(byte *)(param_2 + 0x2a) =
       (byte)(*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 2) & 1;
  *(uint8_t *)(param_2 + 0x28) = 0;
  *(uint8_t *)((int)param_2 + 0xa2) = 0;
  *(uint8_t *)((int)param_2 + 0xa1) = 0;
  *(byte *)((int)param_2 + 0xab) =
       (byte)(*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 0x14) & 1;
  *(uint16_t *)(param_2 + 0x2b) =
       *(uint16_t *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x74 + param_1);
  pcVar9 = (char *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xb + param_1);
  pcVar10 = (char *)((int)param_2 + 0xae);
  do {
    cVar2 = *pcVar9;
    *pcVar10 = cVar2;
    pcVar9 = pcVar9 + 1;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  *(uint8_t *)((int)param_2 + 0xbf) =
       *(uint8_t *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xc + param_1);
  *(uint8_t *)(param_2 + 0x30) = 0;
  param_2[9] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x44 + param_1);
  *(byte *)((int)param_2 + 0xa9) =
       (byte)(*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 0x13) & 1;
  *(byte *)((int)param_2 + 0xaa) =
       (byte)(*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 0xf) & 1;
  param_2[10] = 0xffffffff;
  param_2[0xb] = 0xffffffff;
  param_2[0xc] = 0xffffffff;
  param_2[0xd] = 0xffffffff;
  param_2[0xe] = 0xffffffff;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  *(uint16_t *)(param_2 + 0x16) = 0;
  uVar11 = 0;
  iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) + 0x60)
          )();
  if (iVar5 != 0) {
    puStack_4 = (ushort *)(param_2 + 0x14);
    param_2 = param_2 + 10;
    do {
      if (4 < (int)uVar11) break;
      iVar6 = FUN_005c9be0();
      iVar5 = *(int *)(iVar6 + 4);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar6 + 8) - iVar5 >> 2) <= uVar11)) goto LAB_005cac4c;
      *param_2 = (uint)*(ushort *)(iVar5 + uVar11 * 4);
      iVar6 = FUN_005c9be0();
      iVar5 = *(int *)(iVar6 + 4);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar6 + 8) - iVar5 >> 2) <= uVar11)) goto LAB_005cac4c;
      param_2 = param_2 + 1;
      *puStack_4 = (ushort)*(byte *)(iVar5 + 2 + uVar11 * 4);
      puStack_4 = puStack_4 + 1;
      uVar11 = uVar11 + 1;
      uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                          0x60))();
    } while (uVar11 < uVar7);
  }
  *(uint16_t *)((int)puVar3 + 0xc2) = *(uint16_t *)(param_1 + -0x38);
  puVar3[0x34] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x24);
  param_2 = puVar3 + 0xf;
  *param_2 = 0xffffffff;
  puVar3[0x10] = 0xffffffff;
  puVar3[0x11] = 0xffffffff;
  puVar3[0x12] = 0xffffffff;
  puVar3[0x13] = 0xffffffff;
  *(uint32_t /* width from decompiler */ *)((int)puVar3 + 0x5a) = 0;
  *(uint32_t /* width from decompiler */ *)((int)puVar3 + 0x5e) = 0;
  *(uint16_t *)((int)puVar3 + 0x62) = 0;
  uVar11 = 0;
  iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) + 0x80)
          )();
  if (iVar5 != 0) {
    puStack_4 = (ushort *)((int)puVar3 + 0x5a);
    do {
      if (4 < (int)uVar11) break;
      iVar6 = FUN_005c9c50();
      iVar5 = *(int *)(iVar6 + 4);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar6 + 8) - iVar5 >> 2) <= uVar11)) {
LAB_005cac4c:
                    /* WARNING: Subroutine does not return */
        FUN_004ccf30();
      }
      *param_2 = (uint)*(ushort *)(iVar5 + uVar11 * 4);
      iVar6 = FUN_005c9c50();
      iVar5 = *(int *)(iVar6 + 4);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar6 + 8) - iVar5 >> 2) <= uVar11)) goto LAB_005cac4c;
      param_2 = param_2 + 1;
      *puStack_4 = (ushort)*(byte *)(iVar5 + 2 + uVar11 * 4);
      puStack_4 = puStack_4 + 1;
      uVar11 = uVar11 + 1;
      uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                          0x80))();
    } while (uVar11 < uVar7);
  }
  iVar5 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
  iVar5 = (int)*(short *)(iVar5 + param_1 + -0x24) + (int)*(short *)(iVar5 + -0x22 + param_1);
  if (0x50 < iVar5) {
    iVar5 = 0x50;
  }
  *(short *)(puVar3 + 0x31) = (short)iVar5;
  *(uint16_t *)((int)puVar3 + 0xc6) =
       *(uint16_t *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x20 + param_1);
  *(uint16_t *)(puVar3 + 0x32) =
       *(uint16_t *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1e + param_1);
  *(uint16_t *)((int)puVar3 + 0xca) =
       *(uint16_t *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1c + param_1);
  *(uint16_t *)(puVar3 + 0x33) =
       *(uint16_t *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1a + param_1);
  if ((*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 5 & 1) != 0) {
    iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                        0x1c8))();
    if (*(int *)(iVar5 + 8) != 0) {
      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                          0x1c8))();
      puVar3[0x20] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xbc + iVar5);
      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                          0x1c8))();
      if (*(int *)(iVar5 + 8) == 0) {
        puVar8 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);
      }
      else {
        puVar8 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0xb0);
      }
      puVar3[0x19] = *puVar8;
      puVar3[0x1a] = puVar8[1];
      puVar3[0x1b] = puVar8[2];
      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                          0x1c8))();
      if (*(int *)(iVar5 + 8) != 0) {
        FUN_007971b0(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0x30);
        return 0xd8;
      }
      FUN_007971b0(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x94 + iVar5);
      return 0xd8;
    }
  }
  puVar3[0x20] = g_flOne;
  FUN_007971b0(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x7c + param_1);
  iVar6 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
  iVar5 = iVar6 + -0x8c + param_1;
  puVar3[0x19] = *(uint32_t /* width from decompiler */ *)(iVar6 + -0x8c + param_1);
  puVar3[0x1a] = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);
  puVar3[0x1b] = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);
  return 0xd8;
}
