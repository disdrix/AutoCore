# Annotated low-level: AuthRequest_Serialize

| Field | Value |
|---|---|
| Stable ID | `aa_0071e460` |
| VA | `0x0071e460` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071e460`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall AuthRequest_Serialize(int param_1)

{
  FUN_0044cbd0();
  FUN_00480af0();
  FUN_00480af0();
  FUN_00439810();
  FUN_00480b50(param_1 + 0x34);
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
