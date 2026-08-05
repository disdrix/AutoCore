# Raw capture: FUN_004c3fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c3fb0` |
| **Canonical name** | `FUN_004c3fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004c3fb0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + -0x2b0);
  if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x004c3fc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x2a0))();
    return;
  }
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + param_1 + -0x418);
  *piVar1 = *piVar1 + param_2;
  return;
}
```
