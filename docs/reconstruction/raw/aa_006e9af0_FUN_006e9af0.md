# Raw capture: FUN_006e9af0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006e9af0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006e9af0` |
| **Canonical name** | `FUN_006e9af0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006e9af0(void)

{
  undefined1 *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = &LAB_006e9ab0;
  local_c = FUN_006e7a50;
  local_8 = FUN_006e7a90;
  local_4 = FUN_006e7ad0;
  FUN_006cb390(&local_10,0xffffffff,2);
  local_10 = &LAB_006e9940;
  local_c = FUN_006e9400;
  local_8 = FUN_006e9040;
  local_4 = FUN_006e9220;
  FUN_006cb390(&local_10,2,0xffffffff);
  return;
}
```
