# Raw capture: FUN_005bbb90

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbb90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bbb90` |
| **Canonical name** | `FUN_005bbb90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005bbb90(int param_1,char param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  
  *(char *)(param_1 + 0x7f8) = param_2;
  if (param_2 == '\0') {
    if ((((DAT_00aaa66c < *(float *)(param_1 + 0x900) || DAT_00aaa66c == *(float *)(param_1 + 0x900)
          ) && (*(int *)(*(int *)(param_1 + 4) + 0x28) != 4)) && (param_3 == '\0')) &&
       (piVar2 = (int *)**(int **)(param_1 + 0xa24), piVar2 != *(int **)(param_1 + 0xa24))) {
      do {
        iVar1 = piVar2[2];
        *(undefined4 *)(iVar1 + 0x16c) = 0;
        *(undefined4 *)(iVar1 + 0x170) = 0;
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(param_1 + 0xa24));
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x804) = 0;
    *(undefined4 *)(param_1 + 0x810) = *(undefined4 *)(param_1 + 0x8fc);
    if ((*(byte *)(param_1 + 0x989) & 0x10) != 0) {
      *(undefined4 *)(param_1 + 0x808) = *(undefined4 *)(param_1 + 0x900);
      return;
    }
  }
  return;
}
```
