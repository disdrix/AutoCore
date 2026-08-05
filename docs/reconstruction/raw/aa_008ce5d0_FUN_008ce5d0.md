# Raw capture: FUN_008ce5d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ce5d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ce5d0` |
| **Canonical name** | `FUN_008ce5d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008ce5d0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int *piVar2;
  
  if ((char)param_2 == '\0') {
    FUN_008d80c0(param_1);
  }
  FUN_00792250(param_2,param_3);
  DAT_00d1a8f7 = 1;
  if ((char)param_2 != '\0') {
    FUN_008cc5a0();
    if (DAT_00d1b77c != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b77c + 0xaf0) + 4) + 4) + 4 +
                           *(int *)(DAT_00d1b77c + 0xaf0)) + 0x1cc))();
      FUN_009100f0();
    }
    FUN_008cd200(param_1);
    FUN_008cd070();
    (**(code **)(*param_1 + 0x444))();
    piVar2 = &DAT_00d1b6dc;
    do {
      if (*piVar2 != 0) {
        bVar1 = 1;
        goto LAB_008ce663;
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0xd1b70c);
    bVar1 = 0;
LAB_008ce663:
    param_1[0x126] = (-(uint)bVar1 & 5) + 40000;
  }
  return;
}
```
