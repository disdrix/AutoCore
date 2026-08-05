# Annotated low-level: FUN_004d9ec0

| Field | Value |
|---|---|
| Stable ID | `aa_004d9ec0` |
| VA | `0x004d9ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d9ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004d9ec0(int param_1,int param_2,char param_3)

{
  int iVar1;
  
  if (param_3 != '\0') {
    iVar1 = *(int *)(param_1 + 0xe8bc);
    if (iVar1 != *(int *)(param_1 + 0xe8c0)) {
      do {
        if (*(int *)(param_2 + 0x1c) == *(int *)(iVar1 + 0x1c)) {
          return;
        }
        iVar1 = iVar1 + 0x138;
      } while (iVar1 != *(int *)(param_1 + 0xe8c0));
    }
  }
  Client_SendLogicUiPacket(param_2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
