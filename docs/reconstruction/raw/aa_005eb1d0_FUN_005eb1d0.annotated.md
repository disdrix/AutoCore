# Annotated low-level: FUN_005eb1d0

| Field | Value |
|---|---|
| Stable ID | `aa_005eb1d0` |
| VA | `0x005eb1d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eb1d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005eb1d0(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = param_2;
  FUN_005f5690(param_2);
  pcVar2 = (char *)FUN_005eaf50(&param_2,param_1 + 0x80,0x38d1b717);
  if (*pcVar2 == '\0') {
    FUN_005eb0e0(iVar1 + 0x20);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
