# Raw capture: FUN_0078fdd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078fdd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0078fdd0` |
| **Canonical name** | `FUN_0078fdd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 __fastcall FUN_0078fdd0(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0078fdf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x388))();
    return uVar2;
  }
  return *(undefined1 *)((int)param_1 + 0x496);
}
```
