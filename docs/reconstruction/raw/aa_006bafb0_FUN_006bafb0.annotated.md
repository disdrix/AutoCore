# Annotated low-level: FUN_006bafb0

| Field | Value |
|---|---|
| Stable ID | `aa_006bafb0` |
| VA | `0x006bafb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bafb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bafb0(int param_1,int param_2,int param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined1 local_26;
  undefined1 uStack_25;
  int iStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  do {
    iVar3 = param_2 + param_3 >> 1;
    local_20 = *(undefined4 *)(param_1 + iVar3 * 8);
    local_1c = *(undefined4 *)(param_1 + 4 + iVar3 * 8);
    iVar3 = param_2;
    iVar5 = param_3;
    do {
      pcVar4 = (char *)(*param_4)(&local_26,param_1 + iVar3 * 8,&local_20);
      if (*pcVar4 != '\0') {
        iStack_24 = param_1 + iVar3 * 8;
        do {
          iStack_24 = iStack_24 + 8;
          iVar3 = iVar3 + 1;
          pcVar4 = (char *)(*param_4)(&local_26,iStack_24,&local_20);
        } while (*pcVar4 != '\0');
      }
      pcVar4 = (char *)(*param_4)(&uStack_25,&local_20,param_1 + iVar5 * 8);
      if (*pcVar4 != '\0') {
        iStack_24 = param_1 + iVar5 * 8;
        do {
          iStack_24 = iStack_24 + -8;
          iVar5 = iVar5 + -1;
          pcVar4 = (char *)(*param_4)(&uStack_25,&local_20,iStack_24);
        } while (*pcVar4 != '\0');
      }
      if (iVar5 < iVar3) break;
      if (iVar5 != iVar3) {
        uVar1 = *(undefined4 *)(param_1 + iVar5 * 8);
        uVar2 = *(undefined4 *)(param_1 + 4 + iVar5 * 8);
        *(undefined4 *)(param_1 + iVar5 * 8) = *(undefined4 *)(param_1 + iVar3 * 8);
        *(undefined4 *)(param_1 + 4 + iVar5 * 8) = *(undefined4 *)(param_1 + 4 + iVar3 * 8);
        *(undefined4 *)(param_1 + iVar3 * 8) = uVar1;
        *(undefined4 *)(param_1 + 4 + iVar3 * 8) = uVar2;
      }
      iVar5 = iVar5 + -1;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar5);
    if (param_2 < iVar5) {
      FUN_006bafb0(param_1,param_2,iVar5,param_4);
    }
    param_2 = iVar3;
    if (param_3 <= iVar3) {
      return;
    }
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
