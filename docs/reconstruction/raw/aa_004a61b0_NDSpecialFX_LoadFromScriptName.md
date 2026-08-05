# Raw capture: NDSpecialFX_LoadFromScriptName

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a61b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004a61b0` |
| **Canonical name** | `NDSpecialFX_LoadFromScriptName` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* NDSpecialFX_LoadFromScriptName
   
   Build path: ../scripts/ + name + ".xml" (or keep _nfx.xml suffix).
   Open with tag "NDSpecialFX" via NDXml_OpenTaggedDocument.
   Parses first node into a special-FX object and attaches.
   
   Interact-icon crash path uses names like:
     interact_npc_available_new_mission_core
     interact_npc_available_new_mission
     interact_npc_active_mission_target_complete
     generic_interact / generic_interact_npc */

void * __cdecl NDSpecialFX_LoadFromScriptName(char *pszName,int flags,int unused)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 local_139 [13];
  int local_12c;
  undefined1 local_124 [3];
  char cStack_121;
  char local_120 [2];
  undefined4 uStack_11e;
  char cStack_11a;
  char cStack_119;
  char local_118 [260];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009a1144;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00799940();
  pcVar2 = local_120 + 2;
  for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  pcVar2[0] = '\0';
  pcVar2[1] = '\0';
  local_120[0] = s____scripts__00a96040[0];
  local_120[1] = s____scripts__00a96040[1];
  uStack_11e._0_1_ = s____scripts__00a96040[2];
  uStack_11e._1_1_ = s____scripts__00a96040[3];
  uStack_11e._2_1_ = s____scripts__00a96040[4];
  uStack_11e._3_1_ = s____scripts__00a96040[5];
  cStack_11a = s____scripts__00a96040[6];
  cStack_119 = s____scripts__00a96040[7];
  local_c = 0;
  local_118[0] = s____scripts__00a96040[8];
  local_118[1] = s____scripts__00a96040[9];
  local_118[2] = s____scripts__00a96040[10];
  local_118[3] = s____scripts__00a96040[0xb];
  pcVar2 = pszName;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar8 = &cStack_121;
  do {
    pcVar7 = pcVar8 + 1;
    pcVar8 = pcVar8 + 1;
  } while (*pcVar7 != '\0');
  pcVar7 = pszName;
  for (uVar6 = (uint)((int)pcVar2 - (int)pszName) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar6 = (int)pcVar2 - (int)pszName & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  pcVar2 = strstr(pszName,"_nfx.xml");
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &cStack_121;
    do {
      pcVar8 = pcVar2;
      pcVar2 = pcVar8 + 1;
    } while (pcVar8[1] != '\0');
    *(undefined4 *)(pcVar8 + 1) = DAT_009ca184;
    *(undefined4 *)(pcVar8 + 5) = DAT_009ca188;
    pcVar8[9] = DAT_009ca18c;
  }
  iVar5 = NDXml_OpenTaggedDocument(local_120,"NDSpecialFX");
  if ((iVar5 == 0) && (0 < local_12c)) {
    piVar3 = (int *)FUN_00799900(0);
    if (piVar3 == (int *)0x0) {
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    else {
      local_139[0] = 0;
      pvVar4 = (void *)FUN_004a4fa0(piVar3,local_124,local_139,pszName);
      (**(code **)(*piVar3 + 8))(piVar3);
      if (pvVar4 != (void *)0x0) {
        FUN_004a0b90(pvVar4,(int)pvVar4 + 0xd5,1,0xffffffff,unused);
        FUN_004b85d0();
        FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar4);
      }
    }
  }
  local_c = 0xffffffff;
  FUN_007989b0();
  ExceptionList = local_14;
  return (void *)0x0;
}
```
