# Raw capture: FUN_006eed60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006eed60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006eed60` |
| **Canonical name** | `FUN_006eed60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006eed60(void)

{
  undefined1 *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = &LAB_006eeac0;
  local_c = (code *)&LAB_006ee880;
  local_8 = FUN_006ee8c0;
  local_4 = FUN_006eeb00;
  FUN_006cb390(&local_10,0xffffffff,0x14);
  local_10 = &LAB_006ee800;
  local_c = FUN_006ee5c0;
  local_8 = FUN_006ee680;
  local_4 = FUN_006ee740;
  FUN_006cb390(&local_10,0x14,0xffffffff);
  return;
}
```
