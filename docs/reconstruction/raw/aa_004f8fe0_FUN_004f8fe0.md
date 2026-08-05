# Raw capture: FUN_004f8fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f8fe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f8fe0` |
| **Canonical name** | `FUN_004f8fe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004f8fe0(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x210))(0);
    if ((iVar3 == 0) || (*(char *)(param_1 + 0x103) != '\0')) {
      pbVar1 = (byte *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x17d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  FUN_004f7d60();
  return;
}
```
