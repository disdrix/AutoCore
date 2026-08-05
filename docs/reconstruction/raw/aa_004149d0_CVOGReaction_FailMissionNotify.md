# Raw capture: CVOGReaction_FailMissionNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_004149d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004149d0` |
| **Canonical name** | `CVOGReaction_FailMissionNotify` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGReaction_FailMissionNotify(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 2))) {
    puVar2 = *(undefined4 **)(param_1 + 8);
    *puVar2 = *param_2;
    *(undefined4 **)(param_1 + 8) = puVar2 + 1;
    return;
  }
  FUN_0040dbf0(&param_2,*(undefined4 *)(param_1 + 8),param_2);
  return;
}
```
