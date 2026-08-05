# Raw capture: FUN_008a7cc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a7cc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008a7cc0` |
| **Canonical name** | `FUN_008a7cc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008a7cc0(int *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvStack_24;
  char *pcStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b39a5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  param_1[0x143] = -1;
  param_1[0x144] = 0;
  param_1[0x145] = 0;
  FUN_00792600();
  pcStack_20 = (char *)0x8a7d08;
  pcStack_20 = operator_new(0x488);
  local_4 = 0;
  if (pcStack_20 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    pvStack_24 = (void *)0x8a7d23;
    iVar1 = FUN_007b5dd0();
  }
  local_4 = 0xffffffff;
  param_1[0x14a] = iVar1;
  pcStack_20 = (char *)0x8a7d40;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_20 = "i_d_objstat_2d_wnd_status.xml";
  pvStack_24 = (void *)0x8a7d50;
  (**(code **)(*(int *)param_1[0x14a] + 0x28))();
  pvStack_24 = (void *)0x3f000000;
  (**(code **)(*(int *)param_1[0x14a] + 0xfc))(1);
  piVar2 = (int *)(**(code **)(*(int *)param_1[0x14a] + 0x140))(&pvStack_24,1);
  param_1[0x146] = *piVar2;
  param_1[0x147] = piVar2[1];
  (**(code **)(*param_1 + 0x34c))();
  ExceptionList = pvStack_24;
  return;
}
```
