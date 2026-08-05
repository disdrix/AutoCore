# Raw capture: FUN_0073fad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073fad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0073fad0` |
| **Canonical name** | `FUN_0073fad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint FUN_0073fad0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int unaff_EBX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  int unaff_retaddr;
  undefined4 uVar5;
  char cStack_1c;
  char local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b1950;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkReader_EnterChunkScope();
  local_4 = 0;
  if (local_14 == 0x41455654) {
    if (local_10 == (void *)0x1) {
      uVar1 = (**(code **)(*(int *)(param_1 + 8) + 4))();
      if ((int)uVar1 < 0) {
        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",0x111
                       ,3,"anmAnimEventsImpl: Error Reading Anim Events!");
        puStack_8 = (undefined1 *)0xffffffff;
        if (cStack_1c != '\0') {
          FUN_00769e40();
        }
        ExceptionList = local_10;
        return 0xffffffff;
      }
      if (*(int *)(unaff_EBX + 0x4044) == 0) {
        uVar2 = FUN_00437050(&stack0xffffffd8);
      }
      else {
        uVar2 = FUN_00768760(&stack0xffffffd8);
      }
      uVar1 = uVar1 | uVar2;
      if ((int)uVar1 < 0) {
        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",0x115
                       ,3,"anmAnimEventsImpl: Error Reading track count!");
        puStack_8 = (undefined1 *)0xffffffff;
        if (cStack_1c != '\0') {
          FUN_00769e40();
        }
        ExceptionList = local_10;
        return 0xffffffff;
      }
      FUN_00450020(unaff_EBP);
      iVar4 = 0;
      if (0 < unaff_EBP) {
        iVar3 = 0;
        do {
          uVar2 = (**(code **)(*(int *)(iVar3 + *(int *)(unaff_retaddr + 0x28)) + 4))();
          uVar1 = uVar1 | uVar2;
          if ((int)uVar1 < 0) {
            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",
                           0x11b,3,"anmTrackEvents: Error Reading track events!");
            puStack_8 = (undefined1 *)0xffffffff;
            if (cStack_1c != '\0') {
              FUN_00769e40();
            }
            ExceptionList = local_10;
            return 0xffffffff;
          }
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x1c;
        } while (iVar4 < unaff_EBP);
      }
      puStack_8 = (undefined1 *)0xffffffff;
      if (cStack_1c != '\0') {
        FUN_00769e40();
      }
      ExceptionList = local_10;
      return uVar1;
    }
    uVar5 = 0x123;
  }
  else {
    uVar5 = 0x106;
  }
  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",uVar5,3);
  local_4 = 0xffffffff;
  if (local_18 != '\0') {
    FUN_00769e40();
  }
  ExceptionList = local_c;
  return 0xffffffff;
}
```
