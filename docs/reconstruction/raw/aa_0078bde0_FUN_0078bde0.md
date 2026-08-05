# Raw capture: FUN_0078bde0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078bde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078bde0` |
| **Canonical name** | `FUN_0078bde0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0078bde0(int param_1)

{
  int iVar1;
  undefined4 *in_EAX;
  undefined4 uVar2;
  
  if (in_EAX != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x4a8) = *in_EAX;
    *(undefined4 *)(param_1 + 0x4ac) = in_EAX[1];
    *(undefined4 *)(param_1 + 0x4b0) = in_EAX[2];
    *(undefined4 *)(param_1 + 0x4b4) = in_EAX[3];
  }
  iVar1 = *(int *)(param_1 + 0x2ac);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(**(int **)(iVar1 + 0x8c) + 0x40))("Color");
    (**(code **)(**(int **)(iVar1 + 0x8c) + 0x4c))(uVar2,param_1 + 0x4a8);
  }
  return;
}
```
