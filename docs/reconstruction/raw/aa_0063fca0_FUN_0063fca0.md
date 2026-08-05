# Raw capture: FUN_0063fca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063fca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0063fca0` |
| **Canonical name** | `FUN_0063fca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0063fca0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[2] == 2) {
      iVar1 = 0;
      if (0 < *(int *)(param_1 + 0x38)) {
        piVar2 = *(int **)(param_1 + 0x34);
        while ((undefined4 *)*piVar2 != param_2) {
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 1;
          if (*(int *)(param_1 + 0x38) <= iVar1) {
            (**(code **)*param_2)(1);
            return;
          }
        }
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + iVar1 * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x38) * 4);
      }
    }
    (**(code **)*param_2)(1);
  }
  return;
}
```
