# Annotated low-level: FUN_0071ebc0

| Field | Value |
|---|---|
| Stable ID | `aa_0071ebc0` |
| VA | `0x0071ebc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071ebc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0071ebc0(uint param_1,uint *param_2)

{
  uint uVar1;
  undefined2 *in_EAX;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int unaff_EBX;
  uint uVar5;
  undefined4 local_4;
  
  uVar5 = 0;
  local_4 = 0;
  if (*(int *)(unaff_EBX + 0x40) == 0) {
    return 0x80004005;
  }
  if ((*(int *)(unaff_EBX + 4) == 0) ||
     (uVar1 = param_1, *(int *)(*(int *)(unaff_EBX + 4) + 4) != 6)) {
    do {
      if (param_1 <= uVar5) break;
      iVar2 = ov_read(*(undefined4 *)(unaff_EBX + 0x40),uVar5 + (int)in_EAX,param_1 - uVar5,0,2,1,
                      &local_4);
      uVar5 = uVar5 + iVar2;
    } while (iVar2 != 0);
    *param_2 = uVar5;
    return 0;
  }
  for (; 0xb < (int)uVar1; uVar1 = uVar1 - iVar2) {
    uVar5 = uVar1;
    if (0x2fff < uVar1) {
      uVar5 = 0x3000;
    }
    iVar2 = ov_read(*(undefined4 *)(unaff_EBX + 0x40),&DAT_00d0e658,uVar5,0,2,1,&local_4);
    if (iVar2 == 0) break;
    iVar4 = iVar2 / 0xc;
    if (0 < iVar4) {
      puVar3 = &DAT_00d0e65c;
      do {
        *in_EAX = puVar3[-2];
        in_EAX[1] = *puVar3;
        in_EAX[2] = puVar3[-1];
        in_EAX[3] = puVar3[3];
        in_EAX[4] = puVar3[1];
        in_EAX[5] = puVar3[2];
        in_EAX = in_EAX + 6;
        puVar3 = puVar3 + 6;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  *param_2 = param_1 - uVar1;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
