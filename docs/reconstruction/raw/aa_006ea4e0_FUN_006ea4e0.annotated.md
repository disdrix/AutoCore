# Annotated low-level: FUN_006ea4e0

| Field | Value |
|---|---|
| Stable ID | `aa_006ea4e0` |
| VA | `0x006ea4e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ea4e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ea4e0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  do {
    uVar1 = *(uint *)(param_1 + (param_2 + param_3 >> 1) * 4);
    iVar4 = param_3;
    iVar5 = param_2;
    do {
      uVar2 = *(uint *)(param_1 + iVar5 * 4);
      while (uVar2 < uVar1) {
        iVar5 = iVar5 + 1;
        uVar2 = *(uint *)(param_1 + iVar5 * 4);
      }
      uVar2 = *(uint *)(param_1 + iVar4 * 4);
      while (uVar1 < uVar2) {
        iVar4 = iVar4 + -1;
        uVar2 = *(uint *)(param_1 + iVar4 * 4);
      }
      if (iVar4 < iVar5) break;
      if (iVar4 != iVar5) {
        uVar3 = *(undefined4 *)(param_1 + iVar4 * 4);
        *(undefined4 *)(param_1 + iVar4 * 4) = *(undefined4 *)(param_1 + iVar5 * 4);
        *(undefined4 *)(param_1 + iVar5 * 4) = uVar3;
      }
      iVar4 = iVar4 + -1;
      iVar5 = iVar5 + 1;
    } while (iVar5 <= iVar4);
    if (param_2 < iVar4) {
      FUN_006ea4e0(param_1,param_2,iVar4,param_4);
    }
    param_2 = iVar5;
    if (param_3 <= iVar5) {
      return;
    }
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
