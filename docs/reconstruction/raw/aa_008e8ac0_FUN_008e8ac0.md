# Raw capture: FUN_008e8ac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e8ac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008e8ac0` |
| **Canonical name** | `FUN_008e8ac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_008e8ac0(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  
  if ((param_1 & param_2) == 0xffffffff) {
    return 0;
  }
  iVar2 = 0;
  piVar3 = (int *)(unaff_EBX + 0x52c);
  while (((iVar1 = *piVar3, iVar1 == 0 || (*(uint *)(iVar1 + 8) != param_1)) ||
         (*(uint *)(iVar1 + 0xc) != param_2))) {
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
    if (3 < iVar2) {
      return 0;
    }
  }
  return *(undefined4 *)(unaff_EBX + 0x52c + iVar2 * 4);
}
```
