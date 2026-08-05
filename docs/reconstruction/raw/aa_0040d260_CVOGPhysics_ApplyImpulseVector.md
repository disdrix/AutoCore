# Raw capture: CVOGPhysics_ApplyImpulseVector

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d260` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040d260` |
| **Canonical name** | `CVOGPhysics_ApplyImpulseVector` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGPhysics_ApplyImpulseVector(int param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(param_2);
  return;
}
```
