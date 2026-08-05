# Annotated low-level: Client_RecvLoginOk

| Field | Value |
|---|---|
| Stable ID | `aa_00821df0` |
| VA | `0x00821df0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00821df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall Client_RecvLoginOk(int param_1,undefined4 param_2,undefined4 param_3)

{
  OutputDebugStringA("RecvLoginOk\n");
  *(undefined1 *)(param_1 + 0x4a) = 2;
  *(undefined4 *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x54) = param_3;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00728840(*(int *)(param_1 + 4),param_2,param_3);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
