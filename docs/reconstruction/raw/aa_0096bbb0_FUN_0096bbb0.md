# Raw capture: FUN_0096bbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096bbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096bbb0` |
| **Canonical name** | `FUN_0096bbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0096bbb0(void)

{
  undefined4 *in_EAX;
  
  in_EAX[1] = &PTR_LAB_009d45f0;
  in_EAX[2] = 0;
  *in_EAX = &PTR_LAB_00aa0a20;
  in_EAX[1] = &PTR_LAB_00aa0a10;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = DAT_00d1f01c;
  in_EAX[8] = DAT_00d1f020;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0x101;
  in_EAX[0xc] = 1;
  in_EAX[0xd] = 1;
  in_EAX[0xe] = 0xffffffff;
  in_EAX[0xf] = 0xffffffff;
  in_EAX[0x10] = 0;
  in_EAX[0x11] = 0;
  in_EAX[0x12] = 1;
  in_EAX[0x13] = 0;
  in_EAX[0x14] = 0;
  return;
}
```
