# Annotated low-level: FUN_0096bbb0

| Field | Value |
|---|---|
| Stable ID | `aa_0096bbb0` |
| VA | `0x0096bbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096bbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0096bbb0(void)

{
  undefined4 *in_EAX;
  
  in_EAX[1] = &PTR_LAB_009d45f0;
  in_EAX[2] = 0;
  *in_EAX = &PTR_LAB_00aa0a20;
  in_EAX[1] = &PTR_LAB_00aa0a10;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = DAT_00d1f01c;
  in_EAX[8] = DAT_00d1f020;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0x101;
  in_EAX[0xc] = 1;
  in_EAX[0xd] = 1;
  in_EAX[0xe] = 0xffffffff;
  in_EAX[0xf] = 0xffffffff;
  in_EAX[0x10] = 0;
  in_EAX[0x11] = 0;
  in_EAX[0x12] = 1;
  in_EAX[0x13] = 0;
  in_EAX[0x14] = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
