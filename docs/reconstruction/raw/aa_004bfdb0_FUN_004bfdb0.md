# Raw capture: FUN_004bfdb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfdb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bfdb0` |
| **Canonical name** | `FUN_004bfdb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004bfdb0(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  
  uVar4 = 0;
  piVar3 = (int *)(param_1 + 8);
  do {
    if ((piVar3[1] != 0) && (piVar5 = *(int **)*piVar3, piVar5 != (int *)*piVar3)) {
      do {
        iVar1 = piVar5[2];
        cVar2 = FUN_005c6720(param_2);
        if (cVar2 != '\0') {
          *(undefined1 *)(iVar1 + 0x51) = param_3;
          return;
        }
        piVar5 = (int *)*piVar5;
      } while (piVar5 != (int *)*piVar3);
    }
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 3;
  } while (uVar4 < 9);
  return;
}
```
