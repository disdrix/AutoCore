# Annotated low-level: FUN_005dc5f0

| Field | Value |
|---|---|
| Stable ID | `aa_005dc5f0` |
| VA | `0x005dc5f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dc5f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005dc5f0(int param_1,char param_2)

{
  CVOGHBBase *this;
  
  if (param_2 != *(char *)(param_1 + 0x160)) {
    this = *(CVOGHBBase **)(param_1 + 0xd8);
    *(char *)(param_1 + 0x160) = param_2;
    if (param_2 == '\0') {
      if (this != (CVOGHBBase *)0x0) {
        FUN_005081d0();
        return;
      }
    }
    else {
      if (this != (CVOGHBBase *)0x0) {
        CVOGHBBase_Start(this);
      }
      if (*(char *)(param_1 + 0x18b) != '\0') {
        FUN_005de1b0(0,0,0,0,0);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
