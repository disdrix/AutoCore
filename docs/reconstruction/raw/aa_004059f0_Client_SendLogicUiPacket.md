# Raw capture: Client_SendLogicUiPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004059f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004059f0` |
| **Canonical name** | `Client_SendLogicUiPacket` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall Client_SendLogicUiPacket(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x138) <
      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x138))) {
    iVar1 = *(int *)(param_1 + 8);
    FUN_00409cc0(iVar1,1,param_2,param_1,param_2);
    *(int *)(param_1 + 8) = iVar1 + 0x138;
    return;
  }
  FUN_004068f0(&param_2,*(undefined4 *)(param_1 + 8),param_2);
  return;
}
```
