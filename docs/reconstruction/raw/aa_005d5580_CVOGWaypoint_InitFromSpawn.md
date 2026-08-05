# Raw capture: CVOGWaypoint_InitFromSpawn

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5580` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d5580` |
| **Canonical name** | `CVOGWaypoint_InitFromSpawn` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
