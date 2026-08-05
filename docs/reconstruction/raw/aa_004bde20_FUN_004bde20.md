# Raw capture: FUN_004bde20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bde20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bde20` |
| **Canonical name** | `FUN_004bde20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bde20(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 8);
  for (piVar3 = *(int **)(*(int *)(param_1 + 0xc) + 4); piVar3 != piVar1; piVar3 = piVar3 + 1) {
    iVar2 = *piVar3;
    if (((*(int *)(iVar2 + 8) == 0) && (*(char *)(iVar2 + 0xf) == '\0')) &&
       ((*(uint *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x180 + iVar2) >> 9 & 1) != 0)) {
      FUN_00496210(iVar2);
    }
  }
  return;
}
```
