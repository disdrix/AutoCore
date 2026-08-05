# Raw capture: CVOGReaction_ShowScreenText

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057c4a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0057c4a0` |
| **Canonical name** | `CVOGReaction_ShowScreenText` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGReaction_ShowScreenText(int param_1,int param_2)

{
  undefined4 local_138 [7];
  undefined4 local_11c;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  
  local_138[0] = *(undefined4 *)(param_1 + 0x160);
  local_110 = *(undefined4 *)(param_2 + 0x160);
  local_10c = *(undefined4 *)(param_2 + 0x164);
  local_108 = *(undefined4 *)(param_2 + 0x168);
  local_104 = *(undefined4 *)(param_2 + 0x16c);
  local_11c = 0x26;
  Client_SendLogicUiPacket(local_138);
  return;
}
```
