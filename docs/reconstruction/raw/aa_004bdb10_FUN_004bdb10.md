# Raw capture: FUN_004bdb10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bdb10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bdb10` |
| **Canonical name** | `FUN_004bdb10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bdb10(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  while( true ) {
    if ((*(int *)(param_1 + 0x18) != 0) &&
       (piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 0xc), *piVar1 != 0)) {
      piVar1 = (int *)*piVar1;
      uVar3 = (**(code **)(*piVar1 + 0xc))();
      uVar4 = (**(code **)(*piVar1 + 0x48))(uVar3);
      FUN_0074c9c0(&DAT_00d1eb60,uVar4,uVar3);
    }
    if ((*(int *)(param_1 + 0x18) == 0) ||
       (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar2 == 0)) break;
    *(int *)(param_1 + 0x18) = iVar2;
  }
  *(undefined1 *)(param_1 + 0x5c4) = 1;
  return;
}
```
