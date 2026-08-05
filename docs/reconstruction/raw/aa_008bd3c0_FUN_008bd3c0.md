# Raw capture: FUN_008bd3c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bd3c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bd3c0` |
| **Canonical name** | `FUN_008bd3c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008bd3c0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  FUN_007916e0(param_2);
  if (((char)param_2 != '\0') &&
     ((*(int *)(param_1 + 0x550) == 0 ||
      ((uint)(*(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2) < 4)))) {
    if (*(int *)(param_1 + 0x550) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2;
      if (3 < iVar1) {
        return;
      }
    }
    piVar2 = (int *)(param_1 + 0x56c + iVar1 * 4);
    iVar1 = 4 - iVar1;
    do {
      if (piVar2[-4] != 0) {
        (**(code **)(*(int *)piVar2[-4] + 0xcc))(0);
      }
      if (*piVar2 != 0) {
        (**(code **)(*(int *)*piVar2 + 0xcc))(0);
      }
      if (piVar2[4] != 0) {
        (**(code **)(*(int *)piVar2[4] + 0xcc))(0);
      }
      if (piVar2[8] != 0) {
        (**(code **)(*(int *)piVar2[8] + 0xcc))(0);
      }
      if (piVar2[0xc] != 0) {
        (**(code **)(*(int *)piVar2[0xc] + 0xcc))(0);
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}
```
