# Raw capture: thunk_FUN_0096efd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004434c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004434c0` |
| **Canonical name** | `thunk_FUN_0096efd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall thunk_FUN_0096efd0(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &LAB_009ac21a;
  pvStack_c = ExceptionList;
  uStack_4 = 0;
  iVar2 = *param_1;
  ExceptionList = &pvStack_c;
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 8);
    ExceptionList = &pvStack_c;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
    *param_1 = 0;
  }
  uStack_4 = 0xffffffff;
  iVar2 = *param_1;
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}
```
