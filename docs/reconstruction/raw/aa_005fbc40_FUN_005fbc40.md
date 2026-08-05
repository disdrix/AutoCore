# Raw capture: FUN_005fbc40

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fbc40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fbc40` |
| **Canonical name** | `FUN_005fbc40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fbc40(undefined4 *param_1)

{
  if (-1 < (int)param_1[0x22]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x20],(param_1[0x22] & 0x7fffffff) * 0xc0,0x12);
  }
  if (-1 < (int)param_1[0x1c]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1a],param_1[0x1c] * 4,0x12);
  }
  if (-1 < (int)param_1[0x18]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x16],param_1[0x18] * 4,0x12);
  }
  if (-1 < (int)param_1[0x15]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x13],param_1[0x15] * 4,0x12);
  }
  if (-1 < (int)param_1[0x12]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x10],param_1[0x12] * 4,0x12);
  }
  if (-1 < (int)param_1[0xf]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0xd],param_1[0xf] * 4,0x12);
  }
  if (-1 < (int)param_1[0xc]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[10],param_1[0xc] * 4,0x12);
  }
  if (-1 < (int)param_1[9]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],param_1[9] * 4,0x12);
  }
  if (-1 < (int)param_1[6]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[4],param_1[6] * 4,0x12);
  }
  *param_1 = &PTR_FUN_009d81e8;
  if ((short)*(ushort *)(param_1 + 1) < 0) {
    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;
    FUN_005ffdb0(0);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```
