# Raw capture: FUN_005b0aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b0aa0` |
| **Canonical name** | `FUN_005b0aa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005b0aa0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    puVar3 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4);
    while (puVar3 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)puVar3[3];
      *puVar3 = &PTR_LAB_009d9330;
      *puVar3 = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 **)(param_1 + 0x20) = puVar3;
      puVar3 = puVar2;
    }
    iVar1 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;
  } while (uVar4 <= *(uint *)(param_1 + 8));
  return;
}
```
