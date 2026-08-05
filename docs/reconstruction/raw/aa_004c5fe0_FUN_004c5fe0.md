# Raw capture: FUN_004c5fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c5fe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c5fe0` |
| **Canonical name** | `FUN_004c5fe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004c5fe0(uint param_1)

{
  int iVar1;
  float10 fVar2;
  undefined4 uStack_4;
  
  uStack_4 = param_1 & 0xffffff;
  if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 - 0x4fc) + 4) + -0x458 + param_1) + 0x7e) == '\0'
     ) {
    fVar2 = (float10)FUN_004c55e0();
    if ((float10)g_flZero != fVar2) {
      iVar1 = 0;
      if (param_1 != 0x500) {
        iVar1 = *(int *)(*(int *)(param_1 - 0x4fc) + 4) + -0x4fc + param_1;
      }
      CVOGSpawnPoint_SetObjectActiveState(iVar1,(int)&uStack_4 + 3,0);
    }
  }
  if ((*(int *)(param_1 - 0x2a8) != 0) && (*(int *)(*(int *)(param_1 - 0x2a8) + 0xe0) != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 - 0x4fc) + 4);
    if (*(char *)(*(int *)(iVar1 + -0x458 + param_1) + 0x7e) != '\0') {
      if (param_1 == 0x500) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + param_1 + -0x4fc;
      }
      CVOGSpawnPoint_SetObjectActiveState(iVar1,(int)&uStack_4 + 3,0);
    }
    (**(code **)(**(int **)(param_1 - 0x2a8) + 0x44))();
  }
  return;
}
```
