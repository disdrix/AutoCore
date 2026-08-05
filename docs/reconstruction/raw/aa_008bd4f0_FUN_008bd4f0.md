# Raw capture: FUN_008bd4f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bd4f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bd4f0` |
| **Canonical name** | `FUN_008bd4f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008bd4f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = DAT_00d1d8dc;
  for (uVar3 = 0;
      (iVar1 = param_1[0x154], iVar1 != 0 && (uVar3 < (uint)(param_1[0x155] - iVar1 >> 2)));
      uVar3 = uVar3 + 1) {
    iVar1 = *(int *)(iVar1 + uVar3 * 4);
    if (((iVar1 == 0) || (piVar2 == (int *)0x0)) || (iVar1 == piVar2[0x146])) {
      DAT_00d1d8f4 = 1;
      DAT_00d1d8f5 = 0;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(0);
        piVar2 = DAT_00d1d8dc;
      }
    }
  }
  param_1[0x144] = -1;
  param_1[0x145] = -1;
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```
