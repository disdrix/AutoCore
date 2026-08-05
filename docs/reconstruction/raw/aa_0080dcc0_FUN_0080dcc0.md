# Raw capture: FUN_0080dcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080dcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0080dcc0` |
| **Canonical name** | `FUN_0080dcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0080dcc0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float local_104;
  char local_100 [256];
  
  FUN_007a69d0();
  if (*(char *)(unaff_EDI + 0x13) != '\0') {
    if (*(char *)(unaff_EDI + 0x12) != '\0') {
      iVar2 = CVOGReaction_ResolveObjectTarget
                        (1,*(undefined4 *)(unaff_EDI + 8),*(undefined4 *)(unaff_EDI + 0xc));
      if ((iVar2 == 0) || (DAT_00d1b6d8 == 0)) {
        local_104 = 0.0;
      }
      else {
        fVar4 = (float10)FUN_0052cec0(iVar2);
        local_104 = (float)fVar4;
      }
      uVar9 = 0xffffffff;
      if (*(char *)(unaff_EDI + 0x13) == '\0') {
        if (DAT_00aaa664 <= local_104) {
          pcVar7 = "Attempting... Failed!";
          FUN_007a69d0("Attempting... Failed!");
          uVar9 = FUN_007a6de0(pcVar7,uVar9);
          uVar5 = 0xffffffff;
          pcVar7 = "Percent Chance To Memorize:";
          FUN_007a69d0("Percent Chance To Memorize:",0xffffffff,(int)(local_104 * DAT_00aaa7ac),
                       uVar9);
          uVar9 = FUN_007a6de0(pcVar7,uVar5);
          sprintf(local_100,"%s %d%% - %s",uVar9);
        }
        else {
          pcVar7 = "You Had No Chance Of Memorizing The Item!";
          FUN_007a69d0("You Had No Chance Of Memorizing The Item!");
          pcVar3 = (char *)FUN_007a6de0(pcVar7,uVar9);
          pcVar7 = local_100;
          do {
            cVar1 = *pcVar3;
            *pcVar7 = cVar1;
            pcVar3 = pcVar3 + 1;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
        }
        if ((DAT_00d1b780 != 0) && (DAT_00d1b8dc != 0)) {
          FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_100,0);
        }
      }
      else {
        pcVar7 = "Attempting... Success!";
        FUN_007a69d0("Attempting... Success!",0xffffffff);
        uVar9 = FUN_007a6de0(pcVar7,uVar9);
        uVar5 = 0xffffffff;
        pcVar7 = "Percent Chance To Memorize:";
        FUN_007a69d0("Percent Chance To Memorize:",0xffffffff,(int)(local_104 * DAT_00aaa7ac),uVar9)
        ;
        uVar9 = FUN_007a6de0(pcVar7,uVar5);
        sprintf(local_100,"%s %d%% - %s",uVar9);
        if ((DAT_00d1b780 != 0) && (DAT_00d1b8dc != 0)) {
          FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_100,0);
        }
        FUN_007fef20(0,1,0);
        FUN_00888b00(DAT_00d1b870,1);
        *(undefined1 *)(unaff_ESI + 0x30d0) = 0;
        *(undefined4 *)(unaff_ESI + 0x30c8) = *(undefined4 *)(unaff_EDI + 8);
        *(undefined4 *)(unaff_ESI + 0x30cc) = *(undefined4 *)(unaff_EDI + 0xc);
        uVar9 = FUN_00524290();
        *(undefined4 *)(unaff_ESI + 0x30d4) = uVar9;
        iVar2 = FUN_00524290();
        uVar9 = 0;
        if (iVar2 == -1) {
          uVar8 = 0;
          uVar6 = 0x4e43;
          uVar5 = FUN_007a6de0("You have successfully memorized this item! All of your available slots are full, however, so you must overwrite an existing memory item. Select an item from Memory to replace, or hit cancel if you do not wish to memorize the new object."
                               ,0xffffffff);
        }
        else {
          uVar8 = 1;
          uVar6 = 0x4e41;
          uVar5 = FUN_007a6de0("You have successfully memorized this item! Do you wish to add it your Item Memory so that you can craft it in the future?"
                               ,0xffffffff);
        }
        FUN_007fdfb0(unaff_ESI,uVar5,uVar6,uVar8,uVar9);
      }
      if (*(char *)(unaff_EDI + 0x12) != '\0') {
        return;
      }
    }
    if ((*(char *)(unaff_EDI + 0x11) != '\0') &&
       (iVar2 = CVOGReaction_ResolveObjectTarget
                          (1,*(undefined4 *)(unaff_EDI + 8),*(undefined4 *)(unaff_EDI + 0xc)),
       iVar2 != 0)) {
      FUN_00524190(*(undefined1 *)(unaff_EDI + 0x10),iVar2);
      Client_RefreshOpenMissionUiWindows(unaff_ESI);
    }
  }
  return;
}
```
