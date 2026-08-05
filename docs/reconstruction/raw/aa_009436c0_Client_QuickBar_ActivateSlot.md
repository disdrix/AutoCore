# Raw capture: Client_QuickBar_ActivateSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_009436c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009436c0` |
| **Canonical name** | `Client_QuickBar_ActivateSlot` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* QuickBar activate: (slot, mode, page). page=-1 → UI+0x50c. index=slot+page*10.
   type@client+0x3220+idx*0x18: 1=cast skill (Client_CastSkillFromQuickBarSlot), 2=item use,
   5=power. On-foot (player+0x6b9): slot0/1 → QuickBarActivateSkillSlot or fire weapons. */

void Client_QuickBar_ActivateSlot(char param_1,char param_2,char param_3)

{
  uint uVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = *(int *)(in_EAX + 0xe98);
  if ((iVar3 == 0) ||
     ((((*(char *)(iVar3 + 0x6b9) == '\0' && (*(char *)(iVar3 + 0x6b8) == '\0')) ||
       (*(int *)(in_EAX + 0xf38) == 0)) ||
      (cVar2 = (**(code **)(**(int **)(in_EAX + 0xf38) + 0x3d8))(), cVar2 == '\0')))) {
    if (*(int *)(in_EAX + 0x10b0) != 0) {
      if (param_3 == -1) {
        iVar3 = *(int *)(*(int *)(in_EAX + 0x10b0) + 0x50c);
      }
      else {
        iVar3 = (int)param_3;
      }
      if (param_2 == '\x01') {
        FUN_008a0ed0();
        return;
      }
      iVar3 = (int)param_1 + iVar3 * 10;
      if (*(char *)(iVar3 + 0x3b80 + in_EAX) == '\0') {
        *(undefined1 *)(iVar3 + 0x3b80 + in_EAX) = 1;
        iVar5 = *(int *)(in_EAX + 0x3220 + iVar3 * 0x18);
        if (iVar5 == 1) {
          Client_CastSkillFromQuickBarSlot(*(undefined4 *)(in_EAX + (iVar3 * 3 + 0x645) * 8));
        }
        else if (iVar5 == 2) {
          if (((*(int *)(in_EAX + 0xe98) != 0) &&
              (iVar5 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x250), iVar5 != 0)) &&
             ((*(int *)(iVar5 + 0x2b0) != 0 &&
              (iVar5 = FUN_005710c0(*(undefined4 *)(in_EAX + (iVar3 * 3 + 0x645) * 8),0,0),
              iVar5 != 0)))) {
            iVar5 = *(int *)(*(int *)(iVar5 + 0xa8) + 0x3c);
            if ((iVar5 != 0) && (*(short *)(iVar5 + 0x3f4) == 8)) {
              return;
            }
            FUN_00941d50(1);
            *(undefined1 *)(iVar3 + 0x3b80 + in_EAX) = 0;
            return;
          }
        }
        else if (iVar5 == 5) {
          iVar5 = iVar3 * 3 + 0x645;
          uVar1 = *(uint *)(in_EAX + iVar5 * 8);
          uVar4 = uVar1 + 3000;
          iVar5 = *(int *)(in_EAX + 4 + iVar5 * 8) + (uint)(0xfffff447 < uVar1);
          if ((((*(int *)(in_EAX + 0x1138) != 0) && (iVar5 < 1)) && ((iVar5 < 0 || (uVar4 < 0xf))))
             && (-1 < iVar5)) {
            piVar6 = &DAT_00d177c8 + uVar4 * 5;
            iVar5 = 5;
            do {
              if (*piVar6 != 0) {
                FUN_00941fb0(in_EAX,*(undefined4 *)(*(int *)(in_EAX + 0x1138) + 0x510),1);
              }
              piVar6 = piVar6 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            *(undefined1 *)(iVar3 + 0x3b80 + in_EAX) = 0;
            return;
          }
        }
        *(undefined1 *)(iVar3 + 0x3b80 + in_EAX) = 0;
      }
    }
  }
  else {
    if (param_1 == '\0') {
      if (*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) != '\0') {
        Client_QuickBarActivateSkillSlot('\0');
        return;
      }
      FUN_00922270();
      return;
    }
    if (param_1 == '\x01') {
      if (*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) != '\0') {
        Client_QuickBarActivateSkillSlot('\x01');
        return;
      }
      Input_TryFireSecondaryWeapons();
      return;
    }
  }
  return;
}
```
