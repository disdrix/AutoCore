# Raw capture: UI_UpdateOverheatTip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921580` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00921580` |
| **Canonical name** | `UI_UpdateOverheatTip` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void UI_UpdateOverheatTip(float param_1)

{
  int *piVar1;
  char cVar2;
  float10 fVar3;
  undefined4 extraout_var;
  float fVar4;
  
  if ((((DAT_00d1b968 != (int *)0x0) && (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) &&
      (DAT_00d1b6d8 != 0)) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {
    if (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x150) <
        *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x244)) {
      if (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x244) / 2 <=
          *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x150)) {
        Client_MaybeShowFirstTimeTip();
        return;
      }
    }
    else {
      Client_MaybeShowFirstTimeTip(0x1d);
      cVar2 = (**(code **)(*DAT_00d1b968 + 0x3d8))(extraout_var);
      if ((cVar2 != '\0') && (cVar2 = FUN_00861c10(), cVar2 != '\0')) {
        if (DAT_00d1b968[0x146] != -2) {
          return;
        }
        if (DAT_00d1b968[0x147] != -1) {
          return;
        }
        fVar4 = (float)DAT_00d1b968[0x148];
        fVar3 = (float10)(**(code **)(*DAT_00d1b968 + 0xf4))();
        piVar1 = DAT_00d1b968;
        DAT_00d1b968[0x149] = (int)(float)fVar3;
        piVar1[0x148] = (int)(fVar4 + param_1);
        return;
      }
      FUN_007fde80("Weapons Overheated!",0,0x3e4ccccd,0x3f000000,2);
      DAT_00d1b968[0x146] = -2;
      DAT_00d1b968[0x147] = -1;
      if (DAT_00d1e450 != 0) {
        FUN_0048a780(PTR_s_LED_FX_LED_FX_overheat_xml_00b00250,DAT_00d1e450);
        return;
      }
    }
  }
  return;
}
```
