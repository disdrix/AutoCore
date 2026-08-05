# Raw capture: FUN_005cafb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cafb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cafb0` |
| **Canonical name** | `FUN_005cafb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005cafb0(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0x14 + param_1) + 0x3c);
  if ((iVar2 != 0) &&
     (((sVar1 = *(short *)(iVar2 + 0x3f4), sVar1 == 10 || (sVar1 == 0xb)) &&
      (iVar2 = FUN_004ce940(), iVar2 != 0)))) {
    iVar2 = FUN_005c9a00();
    if ((*(int *)(iVar2 + 4) != 0) && (*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 != 0)) {
      iVar2 = FUN_005c9a00();
      iVar2 = *(int *)(iVar2 + 8);
      iVar3 = FUN_005c9a00();
      if ((iVar2 != *(int *)(iVar3 + 4)) &&
         (iVar2 = FUN_005092b0(*(undefined2 *)(iVar2 + -4)), 0 < (short)iVar2)) {
        iVar3 = FUN_0040f540();
        FUN_00413f00(iVar3 - iVar2);
      }
    }
  }
  iVar2 = FUN_005c9a00();
  if ((*(int *)(iVar2 + 4) != 0) && (*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 != 0)) {
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -4;
  }
  return;
}
```
