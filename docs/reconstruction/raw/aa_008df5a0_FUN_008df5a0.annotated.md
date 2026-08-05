# Annotated low-level: FUN_008df5a0

| Field | Value |
|---|---|
| Stable ID | `aa_008df5a0` |
| VA | `0x008df5a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008df5a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008df5a0(undefined4 param_1,char param_2)

{
  char cVar1;
  undefined4 *in_EAX;
  
  if (DAT_00d1b6d8 != 0) {
    cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +
                                       DAT_00d1b6d8) + 0x3c) + 0x532);
    if (cVar1 == '\0') {
      if (param_2 != '\0') {
        *(undefined1 *)((int)in_EAX + 2) = 0x1d;
        *(undefined1 *)((int)in_EAX + 1) = 0x50;
        *(undefined1 *)in_EAX = 0xff;
        *(undefined1 *)((int)in_EAX + 3) = 0xff;
        return;
      }
      *(undefined1 *)((int)in_EAX + 2) = 10;
      *(undefined1 *)((int)in_EAX + 1) = 0x1e;
      *(undefined1 *)in_EAX = 0x62;
      *(undefined1 *)((int)in_EAX + 3) = 0xff;
      return;
    }
    if (cVar1 == '\x01') {
      if (param_2 != '\0') {
        *(undefined1 *)((int)in_EAX + 2) = 0x6b;
        *(undefined1 *)((int)in_EAX + 1) = 0xff;
        *(undefined1 *)in_EAX = 0x40;
        *(undefined1 *)((int)in_EAX + 3) = 0xff;
        return;
      }
      *(undefined1 *)((int)in_EAX + 2) = 0x2b;
      *(undefined1 *)((int)in_EAX + 1) = 100;
      *(undefined1 *)in_EAX = 0x1a;
      *(undefined1 *)((int)in_EAX + 3) = 0xff;
      return;
    }
    if (cVar1 == '\x02') {
      *(undefined1 *)((int)in_EAX + 3) = 0xff;
      if (param_2 != '\0') {
        *(undefined1 *)((int)in_EAX + 2) = 0xfb;
        *(undefined1 *)((int)in_EAX + 1) = 0x7d;
        *(undefined1 *)in_EAX = 10;
        return;
      }
      *(undefined1 *)((int)in_EAX + 2) = 100;
      *(undefined1 *)((int)in_EAX + 1) = 0x2a;
      *(undefined1 *)in_EAX = 5;
      return;
    }
  }
  if (param_2 != '\0') {
    *in_EAX = DAT_00afdf0c;
    return;
  }
  *in_EAX = DAT_00afdf00;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
