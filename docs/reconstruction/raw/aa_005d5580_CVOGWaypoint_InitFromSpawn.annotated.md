# Annotated low-level: CVOGWaypoint_InitFromSpawn

| Field | Value |
|---|---|
| Stable ID | `aa_005d5580` |
| VA | `0x005d5580` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d5580`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* AutoCore Phase D: Init waypoint from spawn MapPathCoid (+0xa0) and InitialPatrolDistance (+0x7c).
   Patrol float at waypoint+0x4c. */

void __thiscall
CVOGWaypoint_InitFromSpawn
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          char param_6,undefined1 param_7)

{
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
  if (param_6 == '\0') {
    *(undefined1 *)(param_1 + 0x50) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x50) = 2;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x40) = param_2;
  *(undefined4 *)(param_1 + 0x44) = param_3;
  *(undefined4 *)(param_1 + 0x48) = param_4;
  *(undefined1 *)(param_1 + 0x51) = param_7;
  *(undefined4 *)(param_1 + 0x4c) = param_5;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
