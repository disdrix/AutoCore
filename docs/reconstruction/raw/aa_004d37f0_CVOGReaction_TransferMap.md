# Raw capture: CVOGReaction_TransferMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d37f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d37f0` |
| **Canonical name** | `CVOGReaction_TransferMap` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGReaction_TransferMap(int param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  if ((((*(char *)(param_1 + 0x7e) != '\0') && (param_2 != (int *)0x0)) &&
      (iVar2 = (**(code **)(*param_2 + 0x210))(0), iVar2 != 0)) &&
     ((*(char *)(iVar2 + 0x4f4) == '\0' &&
      (cVar1 = FUN_004d2ac0(iVar2,param_2,param_3), cVar1 != '\0')))) {
    *(undefined1 *)(iVar2 + 0x4f4) = 1;
    FUN_004025e0(&stack0xffffffd4);
  }
  return;
}
```
