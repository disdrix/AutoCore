# Raw capture: CVOGReaction_BuildTextParams

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4870` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e4870` |
| **Canonical name** | `CVOGReaction_BuildTextParams` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGReaction_BuildTextParams(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = FUN_004e29c0(iVar1,*(undefined4 *)(iVar1 + 4),param_2);
  FUN_004e29f0(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}
```
