# Raw capture: FUN_004e2ca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2ca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e2ca0` |
| **Canonical name** | `FUN_004e2ca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_004e2ca0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar2 = 0;
  if (iVar3 != 0) {
    while (param_2 != *(int *)(iVar3 + 0x10)) {
      piVar1 = (int *)(iVar3 + 0xc);
      iVar2 = iVar3;
      iVar3 = *piVar1;
      if (*piVar1 == 0) {
        FUN_00537d30();
        return 0;
      }
    }
    if (iVar3 != 0) {
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
        FUN_00537d30();
        return iVar3;
      }
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar3 + 0xc);
    }
  }
  FUN_00537d30();
  return iVar3;
}
```
