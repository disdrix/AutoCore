# Raw capture: FUN_008dbe10

| Field | Value |
|---|---|
| **Stable ID** | `aa_008dbe10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008dbe10` |
| **Canonical name** | `FUN_008dbe10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008dbe10(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x580) == 0) {
    return;
  }
  if (param_2 < 0) {
    return;
  }
  if (0x31 < param_2) {
    return;
  }
  FUN_007a69d0();
  if (param_2 == 0x30) {
    if (DAT_00d1b6d8 == 0) goto LAB_008dbf34;
    (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))(0,1,1);
    uVar3 = *(undefined4 *)(param_1 + 0x580);
    pcVar2 = "Shield generators are standard on all Human vehicles, providing a constantly regenerating damage buffer.  Keep an eye on the thin blue shield gauge next to your green HP gauge.  Later you will be able to upgrade your vehicle with Hazard Mode enabled shields, and launch devestating shield inversion attacks on your enemies."
             + (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +
                                                DAT_00d1b6d8) + 0x3c) + 0x532) * 0x200;
  }
  else if (param_2 == 0x31) {
    if (DAT_00d1b6d8 == 0) goto LAB_008dbf34;
    (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))(0,1,1);
    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) + 0x3c
                    );
    uVar3 = *(undefined4 *)(param_1 + 0x580);
    pcVar2 = "Commandos begin their career with 1 skill rank in Defense Grid.  This activates a short term shield grid boost around your vehicle that reduces damage from a variety of possible sources.  By default, this is mapped to the #1 slot in your QuickBar.  Left-Click that button or use the [$key]QuickBar 1[$/key] key to use the skill."
             + ((uint)*(byte *)(iVar1 + 0x531) + (uint)*(byte *)(iVar1 + 0x532) * 4) * 0x200;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))(0,1,1);
    uVar3 = *(undefined4 *)(param_1 + 0x580);
    pcVar2 = &DAT_00a15f10 + param_2 * 0x200;
  }
  FUN_007a6de0(pcVar2,0xffffffff);
  FUN_008aab00(uVar3);
LAB_008dbf34:
  (**(code **)(**(int **)(param_1 + 0x580) + 0x34c))();
  return;
}
```
