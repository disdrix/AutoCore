# Annotated low-level: Client_RecvLoginCallback_8

| Field | Value |
|---|---|
| Stable ID | `aa_00821c30` |
| VA | `0x00821c30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00821c30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall Client_RecvLoginCallback_8(int param_1,undefined4 param_2,undefined4 param_3)

{
  OutputDebugStringA("RecvPlayOk\n");
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  *(undefined1 *)(param_1 + 0x4b) = 1;
  *(undefined4 *)(param_1 + 0x70) = param_3;
  FUN_009332b0();
  if (DAT_00d1a90c != 0) {
    FUN_007290e0(DAT_00d1a90c);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
