# Raw capture: FUN_006ec4c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ec4c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ec4c0` |
| **Canonical name** | `FUN_006ec4c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ec4c0(void)

{
  undefined1 *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  local_10 = &LAB_006ec470;
  local_c = FUN_006ec270;
  local_8 = FUN_006e9b60;
  local_4 = FUN_006ec2f0;
  FUN_006cb390(&local_10,3,0xffffffff);
  local_10 = &LAB_006ea680;
  local_c = FUN_006ebed0;
  local_8 = FUN_006ebad0;
  local_4 = FUN_006eb810;
  FUN_006cb390(&local_10,0xffffffff,3);
  return;
}
```
