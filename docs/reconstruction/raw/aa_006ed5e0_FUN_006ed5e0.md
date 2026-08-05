# Raw capture: FUN_006ed5e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ed5e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ed5e0` |
| **Canonical name** | `FUN_006ed5e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ed5e0(void)

{
  undefined1 *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = &LAB_006ed5a0;
  local_c = FUN_006ecf40;
  local_8 = FUN_006ecf80;
  local_4 = FUN_006ecfc0;
  FUN_006cb390(&local_10,0xffffffff,9);
  local_10 = &LAB_006ed410;
  local_c = FUN_006ecdb0;
  local_8 = FUN_006ec7f0;
  local_4 = FUN_006ecad0;
  FUN_006cb390(&local_10,9,0xffffffff);
  return;
}
```
