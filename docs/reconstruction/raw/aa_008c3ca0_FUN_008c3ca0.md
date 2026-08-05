# Raw capture: FUN_008c3ca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c3ca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008c3ca0` |
| **Canonical name** | `FUN_008c3ca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_008c3ca0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((0x9c46 < param_3) && (param_3 < 0x9c4f)) {
    if (param_2 == 5) {
      if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0)) {
        FUN_008c3140();
      }
      return 1;
    }
    if (param_2 == 8) {
      FUN_007fbbb0();
      FUN_008c3140();
      return 1;
    }
  }
  switch(param_3 + -40000) {
  case 0:
    if (param_2 == 8) {
      if (*(int *)(param_1 + 0x50c) == 1) {
        FUN_007fca10();
      }
      else if (*(int *)(param_1 + 0x50c) == 3) {
        FUN_007fca10();
        return 1;
      }
      return 1;
    }
    break;
  case 1:
    if (param_2 == 8) {
      return 1;
    }
    break;
  case 2:
    if (param_2 == 8) {
      *(undefined1 *)(param_1 + 0x521) = 0;
      *(bool *)(param_1 + 0x520) = *(char *)(param_1 + 0x520) == '\0';
      FUN_008c3080();
      return 1;
    }
    break;
  case 3:
    if (param_2 == 8) {
      *(undefined1 *)(param_1 + 0x520) = 0;
      *(bool *)(param_1 + 0x521) = *(char *)(param_1 + 0x521) == '\0';
      FUN_008c2fe0();
      return 1;
    }
    break;
  case 4:
    if (param_2 == 8) {
      FUN_008c2f50();
    }
    break;
  case 5:
    if (param_2 == 8) {
      FUN_0093bac0(&DAT_00d1a840,0);
      return 1;
    }
  }
  uVar1 = FUN_0087b500(param_2,param_3);
  return uVar1;
}
```
