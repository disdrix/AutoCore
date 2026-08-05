# Annotated low-level: FUN_006bc5b0

| Field | Value |
|---|---|
| Stable ID | `aa_006bc5b0` |
| VA | `0x006bc5b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bc5b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bc5b0(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  uVar4 = param_1[1];
  puVar6 = (undefined4 *)*param_1;
  iVar9 = uVar4 - 1;
  puVar8 = puVar6;
  if (3 < (int)uVar4) {
    uVar4 = uVar4 >> 2;
    iVar9 = iVar9 + uVar4 * -4;
    do {
      puVar7 = puVar8;
      if ((float)puVar6[3] == g_flZero) {
        uVar1 = puVar6[1];
        uVar2 = puVar6[2];
        uVar3 = puVar6[3];
        puVar7 = puVar8 + 4;
        *puVar8 = *puVar6;
        puVar8[1] = uVar1;
        puVar8[2] = uVar2;
        puVar8[3] = uVar3;
      }
      puVar8 = puVar7;
      if ((float)puVar6[7] == g_flZero) {
        uVar1 = puVar6[5];
        uVar2 = puVar6[6];
        uVar3 = puVar6[7];
        puVar8 = puVar7 + 4;
        *puVar7 = puVar6[4];
        puVar7[1] = uVar1;
        puVar7[2] = uVar2;
        puVar7[3] = uVar3;
      }
      puVar7 = puVar8;
      if ((float)puVar6[0xb] == g_flZero) {
        uVar1 = puVar6[9];
        uVar2 = puVar6[10];
        uVar3 = puVar6[0xb];
        puVar7 = puVar8 + 4;
        *puVar8 = puVar6[8];
        puVar8[1] = uVar1;
        puVar8[2] = uVar2;
        puVar8[3] = uVar3;
      }
      puVar8 = puVar7;
      if ((float)puVar6[0xf] == g_flZero) {
        uVar1 = puVar6[0xd];
        uVar2 = puVar6[0xe];
        uVar3 = puVar6[0xf];
        puVar8 = puVar7 + 4;
        *puVar7 = puVar6[0xc];
        puVar7[1] = uVar1;
        puVar7[2] = uVar2;
        puVar7[3] = uVar3;
      }
      puVar6 = puVar6 + 0x10;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (-1 < iVar9) {
    iVar9 = iVar9 + 1;
    puVar7 = puVar8;
    do {
      puVar8 = puVar7;
      if ((float)puVar6[3] == g_flZero) {
        uVar1 = puVar6[1];
        uVar2 = puVar6[2];
        uVar3 = puVar6[3];
        puVar8 = puVar7 + 4;
        *puVar7 = *puVar6;
        puVar7[1] = uVar1;
        puVar7[2] = uVar2;
        puVar7[3] = uVar3;
      }
      puVar6 = puVar6 + 4;
      iVar9 = iVar9 + -1;
      puVar7 = puVar8;
    } while (iVar9 != 0);
  }
  iVar9 = (int)puVar8 - *param_1 >> 4;
  if ((int)(param_1[2] & 0x7fffffffU) < iVar9) {
    iVar5 = (param_1[2] & 0x7fffffffU) * 2;
    if (iVar5 <= iVar9) {
      iVar5 = iVar9;
    }
    FUN_005b3300(param_1,iVar5,0x10);
  }
  param_1[1] = iVar9;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
