# Raw capture: FUN_004bef20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bef20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bef20` |
| **Canonical name** | `FUN_004bef20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004bef20(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  do {
    *(int *)(param_1 + 0x18) = iVar3;
    if ((iVar3 != 0) &&
       (puVar1 = (undefined4 *)(*(int *)(iVar3 + 0xc) + 4), *(int *)(*(int *)(iVar3 + 0xc) + 4) != 0
       )) {
      iVar3 = *(int *)(param_2 + 4);
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(param_2 + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(param_2 + 8) - iVar3 >> 2)
         )) {
        FUN_004073a0(*(undefined4 *)(param_2 + 8),1,puVar1);
      }
      else {
        puVar2 = *(undefined4 **)(param_2 + 8);
        *puVar2 = *puVar1;
        *(undefined4 **)(param_2 + 8) = puVar2 + 1;
      }
    }
  } while ((*(int *)(param_1 + 0x18) != 0) &&
          (iVar3 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar3 != 0));
  return;
}
```
