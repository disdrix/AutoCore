# Raw capture: FUN_006e8de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006e8de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006e8de0` |
| **Canonical name** | `FUN_006e8de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006e8de0(void)

{
  code *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = FUN_006e8d10;
  local_c = FUN_006e8800;
  local_8 = FUN_006e8840;
  local_4 = FUN_006e89f0;
  FUN_006cb390(&local_10,0xffffffff,0x15);
  local_10 = FUN_006e8920;
  local_c = FUN_006e86b0;
  local_8 = FUN_006e8560;
  local_4 = FUN_006e8400;
  FUN_006cb390(&local_10,0x15,0xffffffff);
  return;
}
```
