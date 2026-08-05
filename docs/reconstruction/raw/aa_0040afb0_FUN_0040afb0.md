# Raw capture: FUN_0040afb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040afb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040afb0` |
| **Canonical name** | `FUN_0040afb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0040afb0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    piVar2 = *(int **)(param_1 + 0x30);
    do {
      if (*piVar2 == param_3) {
        *param_2 = (*(int **)(param_1 + 0x30))[iVar1 * 2 + 1];
        return;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar1 < *(int *)(param_1 + 0x34));
  }
  *param_2 = 0;
  return;
}
```
