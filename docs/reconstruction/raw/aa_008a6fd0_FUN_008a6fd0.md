# Raw capture: FUN_008a6fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a6fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008a6fd0` |
| **Canonical name** | `FUN_008a6fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008a6fd0(char param_1)

{
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  
  if (param_1 != '\0') {
    if (unaff_ESI[0x153] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x153] + 0xcc))(1);
    }
    if (unaff_ESI[0x152] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x152] + 0xcc))(1);
    }
    if (unaff_ESI[0xac] != 0) {
      iVar1 = (**(code **)(*(int *)unaff_ESI[0xac] + 0x34))();
      if (iVar1 != 0) {
        piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0xac] + 0x34))();
        (**(code **)(*piVar2 + 0x3bc))();
      }
    }
                    /* WARNING: Could not recover jumptable at 0x008a7045. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*unaff_ESI + 0x3bc))();
    return;
  }
  if (unaff_ESI[0x153] != 0) {
    (**(code **)(*(int *)unaff_ESI[0x153] + 0xcc))(0);
  }
  if (unaff_ESI[0x152] != 0) {
                    /* WARNING: Could not recover jumptable at 0x008a707d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)unaff_ESI[0x152] + 0xcc))();
    return;
  }
  return;
}
```
