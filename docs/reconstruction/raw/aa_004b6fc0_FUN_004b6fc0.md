# Raw capture: FUN_004b6fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6fc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b6fc0` |
| **Canonical name** | `FUN_004b6fc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004b6fc0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_dc [46];
  undefined4 uStack_24;
  undefined4 uStack_20;
  char *pcStack_1c;
  undefined4 *puStack_18;
  
  if ((*(int *)(param_1 + 0x1fc) != 0) &&
     (piVar3 = (int *)**(int **)(param_1 + 0x1f8), piVar3 != *(int **)(param_1 + 0x1f8))) {
    do {
      puVar1 = (undefined4 *)piVar3[2];
      puVar4 = puVar1;
      puVar5 = auStack_dc;
      for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_00720d40();
      FUN_00720670();
      pcStack_1c = "Requesting play %s\n";
      uStack_20 = 0xffffffff;
      uStack_24 = 0x4b700d;
      puStack_18 = puVar1;
      FUN_007a4480();
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 0x1f8));
  }
  return;
}
```
