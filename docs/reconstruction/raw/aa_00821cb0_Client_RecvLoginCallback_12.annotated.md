# Annotated low-level: Client_RecvLoginCallback_12

| Field | Value |
|---|---|
| Stable ID | `aa_00821cb0` |
| VA | `0x00821cb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00821cb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall Client_RecvLoginCallback_12(int param_1)

{
  OutputDebugStringA("RecvServerList\n");
  *(undefined1 *)(param_1 + 0x4a) = 3;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00728990(*(int *)(param_1 + 4),*(undefined4 *)(param_1 + 0x50),
                 *(undefined4 *)(param_1 + 0x54),*(undefined1 *)(param_1 + 0x74));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
