# Annotated low-level: FUN_004fbef0

| Field | Value |
|---|---|
| Stable ID | `aa_004fbef0` |
| VA | `0x004fbef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fbef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004fbef0(int param_1,char param_2)

{
  if (param_2 != *(char *)(param_1 + 0x10a)) {
    *(char *)(param_1 + 0x10a) = param_2;
    *(char *)(param_1 + 0x109) = param_2;
    *(undefined4 *)(param_1 + 0x614) = 0;
    *(undefined4 *)(param_1 + 0x618) = 0;
    *(char *)(param_1 + 0x61c) = param_2;
    VehicleEntity_PushDriveAxesToController();
    *(undefined1 *)(param_1 + 0x101) = *(undefined1 *)(param_1 + 0x10a);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
