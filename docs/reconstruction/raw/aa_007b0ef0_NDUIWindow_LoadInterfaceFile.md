# Raw capture: NDUIWindow_LoadInterfaceFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b0ef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b0ef0` |
| **Canonical name** | `NDUIWindow_LoadInterfaceFile` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* NDUIWindow_LoadInterfaceFile
   
   Build path under ../interface/ (+ optional locale suffix) and load a window definition.
   Ends with vtable dispatch:
     if path ends in .xml → virtual +0x3a4 (InitFromInterfaceXml)
     else → virtual +0x3a0
   
   Entry for mission dialog widgets (i_d_npc_2d_wnd_*.xml) and many other HUD panels.
   Dump frame at 0x007B11F4 is mid-function near LAB path-resolve → load. */

void __thiscall NDUIWindow_LoadInterfaceFile(int *param_1,char *param_2)

{
  undefined1 *puVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  BOOL BVar5;
  undefined1 auVar6 [4];
  int iVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined4 local_210;
  undefined1 local_20c [4];
  char local_208 [2];
  undefined4 auStack_206 [64];
  char cStack_105;
  char local_104 [260];
  
  local_208[0] = '\0';
  local_208[1] = '\0';
  puVar11 = auStack_206;
  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  *(undefined2 *)puVar11 = 0;
  local_210 = param_1;
  if (param_2 == (char *)0x0) {
    pcVar3 = (char *)param_1[0xa1];
    if (pcVar3 == (char *)0x0) {
      return;
    }
    iVar7 = -2 - (int)pcVar3;
    do {
      cVar2 = *pcVar3;
      pcVar3[(int)auStack_206 + iVar7] = cVar2;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
  }
  else {
    iVar7 = FUN_007a69d0();
    if (*(int *)(iVar7 + 0x2c) == 0) {
      iVar7 = 0;
      do {
        cVar2 = s____interface__00afa148[iVar7];
        *(char *)((int)auStack_206 + iVar7 + -2) = cVar2;
        iVar7 = iVar7 + 1;
        pcVar3 = param_2;
      } while (cVar2 != '\0');
      do {
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      uVar4 = (int)pcVar3 - (int)param_2;
      pcVar3 = local_20c + 3;
      do {
        pcVar9 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar9 != '\0');
      for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)param_2;
        param_2 = param_2 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *param_2;
        param_2 = param_2 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
    else {
      iVar7 = 0;
      do {
        cVar2 = s____interface__00afa148[iVar7];
        *(char *)((int)auStack_206 + iVar7 + -2) = cVar2;
        iVar7 = iVar7 + 1;
      } while (cVar2 != '\0');
      pcVar3 = param_2;
      do {
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      strncat(local_208,param_2,(size_t)(pcVar3 + (-4 - (int)(param_2 + 1))));
      iVar7 = FUN_007a69d0();
      iVar7 = *(int *)(iVar7 + 0x2c);
      if (iVar7 == 1) {
        puVar11 = (undefined4 *)(local_20c + 3);
        do {
          pcVar3 = (char *)((int)puVar11 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        } while (*pcVar3 != '\0');
        *puVar11 = DAT_00a96c64;
        pcVar3 = param_2;
      }
      else if (iVar7 == 2) {
        puVar11 = (undefined4 *)(local_20c + 3);
        do {
          pcVar3 = (char *)((int)puVar11 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        } while (*pcVar3 != '\0');
        *puVar11 = DAT_00a96c60;
        pcVar3 = param_2;
      }
      else {
        pcVar3 = param_2;
        if (iVar7 == 3) {
          puVar11 = (undefined4 *)(local_20c + 3);
          do {
            pcVar3 = (char *)((int)puVar11 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          } while (*pcVar3 != '\0');
          *puVar11 = DAT_00a96c68;
          pcVar3 = param_2;
        }
      }
      do {
        pcVar9 = pcVar3;
        pcVar3 = pcVar9 + 1;
      } while (*pcVar9 != '\0');
      strncat(local_208,pcVar9 + -4,5);
      iVar7 = FUN_007b6a20();
      if ((*(byte *)(iVar7 + 4) & 1) != 0) {
        BVar5 = PathFileExistsA(local_208);
        param_1 = local_210;
        if (BVar5 != 0) goto LAB_007b1175;
        local_20c = (undefined1  [4])FUN_007b6420();
        pcVar3 = (char *)&DAT_00d1e574;
        do {
          pcVar9 = pcVar3;
          if (0xf < *(uint *)(pcVar3 + 0x14)) {
            pcVar9 = *(char **)pcVar3;
          }
          pcVar10 = local_104;
          do {
            cVar2 = *pcVar9;
            *pcVar10 = cVar2;
            pcVar9 = pcVar9 + 1;
            pcVar10 = pcVar10 + 1;
            auVar6 = local_20c;
          } while (cVar2 != '\0');
          do {
            cVar2 = *(char *)auVar6;
            auVar6 = (undefined1  [4])((int)auVar6 + 1);
          } while (cVar2 != '\0');
          uVar4 = (int)auVar6 - (int)local_20c;
          pcVar9 = &cStack_105;
          do {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
          } while (*pcVar10 != '\0');
          auVar6 = local_20c;
          for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar9 = *(undefined4 *)auVar6;
            auVar6 = (undefined1  [4])((int)auVar6 + 4);
            pcVar9 = pcVar9 + 4;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pcVar9 = *(char *)auVar6;
            auVar6 = (undefined1  [4])((int)auVar6 + 1);
            pcVar9 = pcVar9 + 1;
          }
          BVar5 = PathFileExistsA(local_104);
          param_1 = local_210;
          if (BVar5 != 0) goto LAB_007b1175;
          pcVar3 = pcVar3 + 0x1c;
        } while ((int)pcVar3 < 0xd1e7a4);
      }
      cVar2 = FUN_007b66c0(iVar7);
      param_1 = local_210;
      if (cVar2 == '\0') {
        iVar7 = 0;
        do {
          cVar2 = s____interface__00afa148[iVar7];
          *(char *)((int)auStack_206 + iVar7 + -2) = cVar2;
          iVar7 = iVar7 + 1;
          pcVar3 = param_2;
        } while (cVar2 != '\0');
        do {
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        uVar4 = (int)pcVar3 - (int)param_2;
        pcVar3 = local_20c + 3;
        do {
          pcVar9 = pcVar3 + 1;
          pcVar3 = pcVar3 + 1;
        } while (*pcVar9 != '\0');
        for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pcVar3 = *(undefined4 *)param_2;
          param_2 = param_2 + 4;
          pcVar3 = pcVar3 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar3 = *param_2;
          param_2 = param_2 + 1;
          pcVar3 = pcVar3 + 1;
        }
      }
    }
  }
LAB_007b1175:
  (**(code **)(*param_1 + 0x6c))(local_208);
  pcVar3 = local_20c;
  puVar1 = local_20c + 1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  iVar7 = tolower((int)pcVar3[(int)&local_210 - (int)puVar1]);
  if ((((iVar7 == 0x2e) &&
       (iVar7 = tolower((int)pcVar3[(int)&local_210 + (1 - (int)puVar1)]), iVar7 == 0x78)) &&
      (iVar7 = tolower((int)pcVar3[(int)&local_210 + (2 - (int)puVar1)]), iVar7 == 0x6d)) &&
     (iVar7 = tolower((int)pcVar3[(int)&local_210 + (3 - (int)puVar1)]), iVar7 == 0x6c)) {
    (**(code **)(*param_1 + 0x3a4))(local_20c,0);
    return;
  }
  (**(code **)(*param_1 + 0x3a0))(local_20c);
  return;
}
```
