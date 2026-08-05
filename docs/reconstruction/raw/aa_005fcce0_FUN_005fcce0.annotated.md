# Annotated low-level: FUN_005fcce0

| Field | Value |
|---|---|
| Stable ID | `aa_005fcce0` |
| VA | `0x005fcce0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fcce0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005fcce0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  float10 fVar9;
  uint local_1c;
  
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  uVar5 = *(uint *)(param_3 + 0xc) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300((int *)(param_3 + 4),iVar6,4);
  }
  *(int *)(param_3 + 8) = iVar8;
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  uVar5 = *(uint *)(param_3 + 0x18) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300((int *)(param_3 + 0x10),iVar6,4);
  }
  *(int *)(param_3 + 0x14) = iVar8;
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  uVar5 = *(uint *)(param_3 + 0x24) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300((int *)(param_3 + 0x1c),iVar6,4);
  }
  *(int *)(param_3 + 0x20) = iVar8;
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  piVar1 = (int *)(param_3 + 0x28);
  uVar5 = *(uint *)(param_3 + 0x30) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300(piVar1,iVar6,4);
  }
  *(int *)(param_3 + 0x2c) = iVar8;
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  uVar5 = *(uint *)(param_3 + 0x3c) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300((int *)(param_3 + 0x34),iVar6,4);
  }
  *(int *)(param_3 + 0x38) = iVar8;
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  uVar5 = *(uint *)(param_3 + 0x60) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300((int *)(param_3 + 0x58),iVar6,4);
  }
  *(int *)(param_3 + 0x5c) = iVar8;
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  uVar5 = *(uint *)(param_3 + 0x48) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300((int *)(param_3 + 0x40),iVar6,4);
  }
  *(int *)(param_3 + 0x44) = iVar8;
  cVar3 = FUN_004f5560();
  iVar8 = (int)cVar3;
  uVar5 = *(uint *)(param_3 + 0x54) & 0x7fffffff;
  if ((int)uVar5 < iVar8) {
    iVar6 = uVar5 * 2;
    if (iVar6 <= iVar8) {
      iVar6 = iVar8;
    }
    FUN_005b3300((int *)(param_3 + 0x4c),iVar6,4);
  }
  *(int *)(param_3 + 0x50) = iVar8;
  cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 0xac +
                                     *(int *)(param_1 + 600)) + 0x3c) + 0x4cc);
  cVar7 = '\0';
  local_1c = local_1c & 0xffffff00;
  cVar4 = FUN_004f5560();
  if ('\0' < cVar4) {
    do {
      iVar6 = (int)cVar7;
      iVar8 = iVar6 * 4;
      *(undefined4 *)(iVar8 + *(int *)(param_3 + 0x58)) = DAT_00aaa7a4;
      *(undefined4 *)(iVar8 + *(int *)(param_3 + 0x10)) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x600
            + iVar6 * 4);
      *(undefined4 *)(iVar8 + *(int *)(param_3 + 0x1c)) =
           *(undefined4 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x618
            + iVar6 * 4);
      iVar6 = *piVar1;
      bVar2 = cVar7 < cVar3;
      fVar9 = (float10)FUN_004f5550(local_1c);
      *(float *)(iVar6 + iVar8) = (float)fVar9;
      if (!bVar2) {
        *(float *)(iVar8 + *piVar1) =
             *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                                0x3c) + 0x740) * *(float *)(iVar8 + *piVar1);
      }
      *(float *)(iVar8 + *(int *)(param_3 + 0x40)) = *(float *)(iVar8 + *piVar1) * DAT_00aaa68c;
      *(undefined4 *)(iVar8 + *(int *)(param_3 + 0x4c)) = DAT_00a0f718;
      *(float *)(iVar8 + *(int *)(param_3 + 0x34)) = g_flMsToSeconds_Inferred;
      cVar7 = cVar7 + '\x01';
      local_1c = CONCAT31(local_1c._1_3_,cVar7);
      *(uint *)(iVar8 + *(int *)(param_3 + 4)) = (uint)bVar2;
      cVar4 = FUN_004f5560();
    } while (cVar7 < cVar4);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
