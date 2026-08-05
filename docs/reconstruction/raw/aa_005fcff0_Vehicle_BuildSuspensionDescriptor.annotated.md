# Annotated low-level: Vehicle_BuildSuspensionDescriptor

| Field | Value |
|---|---|
| Stable ID | `aa_005fcff0` |
| VA | `0x005fcff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fcff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void Vehicle_BuildSuspensionDescriptor(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  int local_28;
  uint local_24;
  undefined4 local_14;
  
  cVar4 = FUN_004f5560();
  iVar9 = (int)cVar4;
  if ((int)(param_3[0xb] & 0x7fffffffU) < iVar9) {
    iVar7 = (param_3[0xb] & 0x7fffffffU) * 2;
    if (iVar7 <= iVar9) {
      iVar7 = iVar9;
    }
    FUN_005b3300(param_3 + 9,iVar7,4);
  }
  param_3[10] = iVar9;
  cVar4 = FUN_004f5560();
  iVar9 = (int)cVar4;
  if ((int)(param_3[0xe] & 0x7fffffffU) < iVar9) {
    iVar7 = (param_3[0xe] & 0x7fffffffU) * 2;
    if (iVar7 <= iVar9) {
      iVar7 = iVar9;
    }
    FUN_005b3300(param_3 + 0xc,iVar7,4);
  }
  param_3[0xd] = iVar9;
  cVar4 = FUN_004f5560();
  iVar9 = (int)cVar4;
  if ((int)(param_3[0x11] & 0x7fffffffU) < iVar9) {
    iVar7 = (param_3[0x11] & 0x7fffffffU) * 2;
    if (iVar7 <= iVar9) {
      iVar7 = iVar9;
    }
    FUN_005b3300(param_3 + 0xf,iVar7,4);
  }
  param_3[0x10] = iVar9;
  cVar4 = FUN_004f5560();
  iVar9 = (int)cVar4;
  if ((int)(param_3[2] & 0x7fffffffU) < iVar9) {
    iVar7 = (param_3[2] & 0x7fffffffU) * 2;
    if (iVar7 <= iVar9) {
      iVar7 = iVar9;
    }
    FUN_005b3300(param_3,iVar7,0x10);
  }
  param_3[1] = iVar9;
  cVar4 = FUN_004f5560();
  iVar9 = (int)cVar4;
  if ((int)(param_3[5] & 0x7fffffffU) < iVar9) {
    iVar7 = (param_3[5] & 0x7fffffffU) * 2;
    if (iVar7 <= iVar9) {
      iVar7 = iVar9;
    }
    FUN_005b3300(param_3 + 3,iVar7,0x10);
  }
  param_3[4] = iVar9;
  cVar4 = FUN_004f5560();
  iVar9 = (int)cVar4;
  if ((int)(param_3[8] & 0x7fffffffU) < iVar9) {
    iVar7 = (param_3[8] & 0x7fffffffU) * 2;
    if (iVar7 <= iVar9) {
      iVar7 = iVar9;
    }
    FUN_005b3300(param_3 + 6,iVar7,4);
  }
  param_3[7] = iVar9;
  bVar8 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 0xac +
                                     *(int *)(param_1 + 600)) + 0x3c) + 0x4cc);
  uVar10 = 0;
  if ('\0' < (char)bVar8) {
    local_28 = 0;
    uVar10 = (uint)bVar8;
    iVar7 = 0;
    iVar9 = 0;
    local_24 = uVar10;
    do {
      *(undefined4 *)(iVar9 + param_3[6]) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x55c
            );
      *(undefined4 *)(iVar9 + param_3[9]) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x564
            );
      *(undefined4 *)(iVar9 + param_3[0xc]) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x56c
            );
      *(undefined4 *)(iVar9 + param_3[0xf]) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x574
            );
      iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
      puVar6 = (undefined4 *)(iVar3 + 0x514 + local_28);
      uVar1 = *(undefined4 *)(iVar3 + 0x518 + local_28);
      uVar2 = *(undefined4 *)(iVar3 + 0x51c + local_28);
      local_28 = local_28 + 0xc;
      puVar5 = (undefined4 *)(*param_3 + iVar7);
      *puVar5 = *puVar6;
      puVar5[1] = uVar1;
      puVar5[2] = uVar2;
      uVar1 = DAT_00aaa668;
      puVar5[3] = local_14;
      puVar6 = (undefined4 *)(param_3[3] + iVar7);
      iVar9 = iVar9 + 4;
      iVar7 = iVar7 + 0x10;
      local_24 = local_24 - 1;
      *puVar6 = 0;
      puVar6[1] = uVar1;
      puVar6[2] = 0;
      puVar6[3] = local_14;
    } while (local_24 != 0);
  }
  cVar4 = FUN_004f5560();
  if ((char)uVar10 < cVar4) {
    do {
      iVar7 = (int)(char)uVar10;
      *(undefined4 *)(param_3[6] + iVar7 * 4) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x560
            );
      *(undefined4 *)(param_3[9] + iVar7 * 4) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x568
            );
      *(undefined4 *)(param_3[0xc] + iVar7 * 4) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x570
            );
      *(undefined4 *)(param_3[0xf] + iVar7 * 4) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x578
            );
      iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
      uVar1 = *(undefined4 *)(iVar9 + 0x518 + iVar7 * 0xc);
      uVar2 = *(undefined4 *)(iVar9 + 0x51c + iVar7 * 0xc);
      puVar6 = (undefined4 *)(*param_3 + iVar7 * 0x10);
      *puVar6 = *(undefined4 *)(iVar9 + 0x514 + iVar7 * 0xc);
      puVar6[1] = uVar1;
      puVar6[2] = uVar2;
      uVar1 = DAT_00aaa668;
      puVar6[3] = local_14;
      puVar6 = (undefined4 *)(param_3[3] + iVar7 * 0x10);
      *puVar6 = 0;
      puVar6[1] = uVar1;
      puVar6[2] = 0;
      puVar6[3] = local_14;
      bVar8 = (char)uVar10 + 1;
      uVar10 = (uint)bVar8;
      cVar4 = FUN_004f5560();
    } while ((char)bVar8 < cVar4);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
