# Raw capture: WeaponTrackAction_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a5020` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a5020` |
| **Canonical name** | `WeaponTrackAction_OnHeartBeat` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
