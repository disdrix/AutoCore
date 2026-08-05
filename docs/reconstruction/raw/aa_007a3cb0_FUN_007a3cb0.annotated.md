# Annotated low-level: FUN_007a3cb0

| Field | Value |
|---|---|
| Stable ID | `aa_007a3cb0` |
| VA | `0x007a3cb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007a3cb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007a3cb0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xd4) != 0) {
    FUN_00970a90();
    if (*(undefined4 **)(in_EAX + 0xd4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_EAX + 0xd4))(1);
    }
    *(undefined4 *)(in_EAX + 0xd4) = 0;
    *(undefined4 *)(in_EAX + 0xd4) = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x2b8));
  if (*(undefined4 **)(in_EAX + 0x128) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_EAX + 0x128))(1);
  }
  *(undefined4 *)(in_EAX + 0x128) = 0;
  FUN_0079e3e0();
  FUN_007544f0(in_EAX);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
