# Raw capture: FUN_005dbc20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dbc20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dbc20` |
| **Canonical name** | `FUN_005dbc20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005dbc20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x168);
  if (puVar2 != *(undefined4 **)(param_1 + 0x16c)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
      FUN_005b04b0(*puVar2,*(undefined4 *)(iVar1 + param_1 + 0x164),
                   *(undefined4 *)(iVar1 + 0x168 + param_1));
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
      FUN_005b04b0(puVar2[1],*(undefined4 *)(iVar1 + param_1 + 0x164),
                   *(undefined4 *)(iVar1 + 0x168 + param_1));
      puVar2 = puVar2 + 3;
    } while (puVar2 != *(undefined4 **)(param_1 + 0x16c));
  }
  return;
}
```
