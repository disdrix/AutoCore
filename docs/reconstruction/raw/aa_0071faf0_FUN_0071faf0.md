# Raw capture: FUN_0071faf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071faf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071faf0` |
| **Canonical name** | `FUN_0071faf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0071faf0(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int unaff_EDI;
  uint local_4;
  
  if (*(int *)(unaff_EDI + 0x10) == 0) {
    return 0;
  }
  uVar2 = 0;
  local_4 = param_1;
  if (*(int *)(unaff_EDI + 0x1c) != 0) {
    do {
      if (*(int *)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4) != 0) {
        local_4 = 0;
        piVar1 = *(int **)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4);
        (**(code **)(*piVar1 + 0x24))(piVar1,&local_4);
        if ((local_4 & 1) == 0) break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(unaff_EDI + 0x1c));
  }
  if (uVar2 != *(uint *)(unaff_EDI + 0x1c)) {
    return *(undefined4 *)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4);
  }
  CVOGReaction_RandomUnitScalar();
  uVar2 = FUN_00424830();
  return *(undefined4 *)(*(int *)(unaff_EDI + 0x10) + (uVar2 % *(uint *)(unaff_EDI + 0x1c)) * 4);
}
```
