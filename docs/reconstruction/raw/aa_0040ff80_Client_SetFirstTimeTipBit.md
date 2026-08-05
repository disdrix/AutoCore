# Raw capture: Client_SetFirstTimeTipBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ff80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040ff80` |
| **Canonical name** | `Client_SetFirstTimeTipBit` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* OR tip bit into FirstTimeFlags at character+0xD30.
   AL = tip id; EDX/param_2 = character object.
   Only for tip id < 0x80: flags[id>>5] |= 1<<(id&0x1f). */

void __fastcall Client_SetFirstTimeTipBit(undefined4 param_1,int param_2)

{
  uint *puVar1;
  byte in_AL;
  
  if (in_AL < 0x80) {
    puVar1 = (uint *)(param_2 + 0xd30 + (uint)(in_AL >> 5) * 4);
    *puVar1 = *puVar1 | 1 << (in_AL & 0x1f);
  }
  return;
}
```
