# Raw capture: FUN_008db3f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008db3f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008db3f0` |
| **Canonical name** | `FUN_008db3f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008db3f0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x584) != 0) {
    if (param_2 != 6) {
      (**(code **)(**(int **)(param_1 + 0x584) + 0x58))();
      return;
    }
    piVar1 = *(int **)(param_1 + 0x584);
    iVar2 = *piVar1;
    uVar3 = (**(code **)(**(int **)(param_1 + 0x584) + 0x2d8))();
    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);
    (**(code **)(iVar2 + 0x50))("i_d_first_2d_btn_minimize_off.dds",uVar3);
  }
  return;
}
```
