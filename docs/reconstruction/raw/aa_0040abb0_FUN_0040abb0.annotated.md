# Annotated low-level: FUN_0040abb0

| Field | Value |
|---|---|
| Stable ID | `aa_0040abb0` |
| VA | `0x0040abb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040abb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0040abb0(undefined4 param_1,int param_2)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  
  if (in_EAX != (char *)0x0) {
    iVar2 = (param_2 + 0x1b0) - (int)in_EAX;
    do {
      cVar1 = *in_EAX;
      in_EAX[iVar2] = cVar1;
      in_EAX = in_EAX + 1;
    } while (cVar1 != '\0');
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
