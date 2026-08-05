# Annotated low-level: FUN_0042adb0

| Field | Value |
|---|---|
| Stable ID | `aa_0042adb0` |
| VA | `0x0042adb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042adb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0042adb0(void)

{
  code *pcVar1;
  char *in_EAX;
  
  if (*in_EAX != '\0') {
    FUN_00780060();
    return;
  }
  if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
