# Annotated low-level: FUN_004abc80

| Field | Value |
|---|---|
| Stable ID | `aa_004abc80` |
| VA | `0x004abc80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004abc80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004abc80(int param_1,int param_2)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint local_8;
  int local_4;
  
  iVar4 = 0;
  local_4 = 4;
  do {
    cVar2 = '\0';
    local_8 = local_8 & 0xffffff00;
    iVar3 = param_2;
    do {
      puVar1 = (undefined1 *)(*(int *)(param_1 + 4) + iVar4);
      FUN_004a8ec0(CONCAT31((int3)((uint)puVar1 >> 8),*puVar1),
                   CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),puVar1[1]),iVar3,local_8);
      cVar2 = cVar2 + '\x01';
      iVar3 = iVar3 + 0x20;
      local_8 = CONCAT31(local_8._1_3_,cVar2);
    } while (cVar2 < '\x04');
    param_2 = param_2 + 8;
    iVar4 = iVar4 + 2;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
