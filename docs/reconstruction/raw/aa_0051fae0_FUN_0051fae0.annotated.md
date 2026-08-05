# Annotated low-level: FUN_0051fae0

| Field | Value |
|---|---|
| Stable ID | `aa_0051fae0` |
| VA | `0x0051fae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0051fae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0051fae0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *_Dest;
  
  if (*(void **)(param_1 + 0x64c) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x64c));
  }
  *(undefined4 *)(param_1 + 0x64c) = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + (1 - (int)(param_2 + 1));
  if (pcVar2 != (char *)0x0) {
    _Dest = operator_new__((uint)pcVar2);
    *(char **)(param_1 + 0x64c) = _Dest;
    strncpy(_Dest,param_2,(size_t)pcVar2);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
