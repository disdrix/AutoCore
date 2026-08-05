# Annotated low-level: CreateSimpleObject_SerializeVariant2

| Field | Value |
|---|---|
| Stable ID | a_005ca720 |
| VA | 0x005ca720 |
| System | inventory-transfer |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Same 0x2012 layout as Serialize; different object base offsets.

## Named callees (decompiler)

- CreateSimpleObject_SerializeVariant2
- FUN_00512670
- FUN_005c9be0
- FUN_005c9c50
- FUN_004ccf30
- FUN_007971b0

## Machine-level notes

- Source: raw capture for a_005ca720.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
undefined4 __thiscall CreateSimpleObject_SerializeVariant2(int param_1,uint *param_2)

{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  uint uVar11;
  ushort *puStack_4;
  
  puVar3 = param_2;
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  *param_2 = 0x2012;
  iVar5 = *(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + param_1 + -100);
  if (iVar5 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(undefined4 *)(iVar5 + 0x34);
  }
  param_2[1] = uVar4;
  iVar5 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
  param_2[0x24] = *(undefined4 *)(iVar5 + 0x54 + param_1);
  param_2[0x25] = *(undefined4 *)(iVar5 + 0x58 + param_1);
  *(undefined1 *)(param_2 + 0x26) =
       *(undefined1 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x5c + param_1);
  param_2[4] = *(undefined4 *)(param_1 + -0x30);
  param_2[5] = *(undefined4 *)(param_1 + -0x2c);
  param_2[0x21] = *(undefined4 *)(param_1 + -0x28);
  *(undefined1 *)(param_2 + 0x22) = *(undefined1 *)(param_1 + -0x20);
  *(undefined1 *)((int)param_2 + 0x89) = *(undefined1 *)(param_1 + -0x1f);
  param_2[6] = *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x48 + param_1);
  param_2[7] = *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xfc + param_1);
  param_2[8] = *(undefined4 *)(param_1 + -0x34);
  param_2[2] = 0xffffffff;
  param_2[3] = 0xffffffff;
  *(byte *)((int)param_2 + 0x8a) =
       (byte)((uint)*(undefined4 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 8)
       & 1;
  *(undefined1 *)((int)param_2 + 0xa3) = *(undefined1 *)(param_1 + -0x1e);
  *(undefined1 *)(param_2 + 0x29) = *(undefined1 *)(param_1 + -0x1d);
  *(undefined1 *)((int)param_2 + 0xa5) = *(undefined1 *)(param_1 + -0x1c);
  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1);
  *puVar1 = *puVar1 | 0x10;
  FUN_00512670();
  *(undefined1 *)((int)param_2 + 0xa6) = 1;
  *(undefined1 *)((int)param_2 + 0xa7) = 0;
  *(byte *)(param_2 + 0x2a) =
       (byte)(*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 2) & 1;
  *(undefined1 *)(param_2 + 0x28) = 0;
  *(undefined1 *)((int)param_2 + 0xa2) = 0;
  *(undefined1 *)((int)param_2 + 0xa1) = 0;
  *(byte *)((int)param_2 + 0xab) =
       (byte)(*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 0x14) & 1;
  *(undefined2 *)(param_2 + 0x2b) =
       *(undefined2 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x74 + param_1);
  pcVar9 = (char *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xb + param_1);
  pcVar10 = (char *)((int)param_2 + 0xae);
  do {
    cVar2 = *pcVar9;
    *pcVar10 = cVar2;
    pcVar9 = pcVar9 + 1;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  *(undefined1 *)((int)param_2 + 0xbf) =
       *(undefined1 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xc + param_1);
  *(undefined1 *)(param_2 + 0x30) = 0;
  param_2[9] = *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x44 + param_1);
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
  *(undefined2 *)(param_2 + 0x16) = 0;
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
  *(undefined2 *)((int)puVar3 + 0xc2) = *(undefined2 *)(param_1 + -0x38);
  puVar3[0x34] = *(undefined4 *)(param_1 + -0x24);
  param_2 = puVar3 + 0xf;
  *param_2 = 0xffffffff;
  puVar3[0x10] = 0xffffffff;
  puVar3[0x11] = 0xffffffff;
  puVar3[0x12] = 0xffffffff;
  puVar3[0x13] = 0xffffffff;
  *(undefined4 *)((int)puVar3 + 0x5a) = 0;
  *(undefined4 *)((int)puVar3 + 0x5e) = 0;
  *(undefined2 *)((int)puVar3 + 0x62) = 0;
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
  *(undefined2 *)((int)puVar3 + 0xc6) =
       *(undefined2 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x20 + param_1);
  *(undefined2 *)(puVar3 + 0x32) =
       *(undefined2 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1e + param_1);
  *(undefined2 *)((int)puVar3 + 0xca) =
       *(undefined2 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1c + param_1);
  *(undefined2 *)(puVar3 + 0x33) =
       *(undefined2 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x1a + param_1);
  if ((*(uint *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x70 + param_1) >> 5 & 1) != 0) {
    iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                        0x1c8))();
    if (*(int *)(iVar5 + 8) != 0) {
      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                          0x1c8))();
      puVar3[0x20] = *(undefined4 *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xbc + iVar5);
      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0x10c + param_1) +
                          0x1c8))();
      if (*(int *)(iVar5 + 8) == 0) {
        puVar8 = (undefined4 *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);
      }
      else {
        puVar8 = (undefined4 *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0xb0);
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
  puVar3[0x19] = *(undefined4 *)(iVar6 + -0x8c + param_1);
  puVar3[0x1a] = *(undefined4 *)(iVar5 + 4);
  puVar3[0x1b] = *(undefined4 *)(iVar5 + 8);
  return 0xd8;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
