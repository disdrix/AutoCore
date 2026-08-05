# Raw capture: FUN_007fcc10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fcc10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fcc10` |
| **Canonical name** | `FUN_007fcc10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007fcc10(int *param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  float10 fVar3;
  
  if ((param_1 != (int *)0x0) && (unaff_ESI != (int *)0x0)) {
    fVar3 = (float10)(**(code **)(*param_1 + 0x458))();
    iVar1 = (**(code **)(*unaff_ESI + 0x494))();
    iVar2 = (**(code **)(*unaff_ESI + 0x490))();
    iVar1 = (int)ROUND((float)(iVar2 - iVar1) * (float)fVar3);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    (**(code **)(*unaff_ESI + 0x498))(iVar1);
  }
  return;
}
```
