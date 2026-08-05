# Annotated low-level: WeaponTrackAction_OnHeartBeat

| Field | Value |
|---|---|
| Stable ID | `aa_005a5020` |
| VA | `0x005a5020` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005a5020`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall WeaponTrackAction_OnHeartBeat(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_004f8430();
    *param_2 = DAT_00b05064;
    return;
  }
  *param_2 = DAT_00b05064;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
