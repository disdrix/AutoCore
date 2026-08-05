# Raw capture: FUN_0058abc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058abc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0058abc0` |
| **Canonical name** | `FUN_0058abc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
char FUN_0058abc0(int param_1,undefined4 param_2,int param_3,float param_4)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  char *pcVar8;
  char local_400 [1024];
  
  FUN_007a69d0();
  cVar7 = '\0';
  if ((*(byte *)(param_3 + 0x624) & 0x40) != 0) {
    if (*(short *)(param_3 + 0xd0) != 0) {
      iVar6 = (int)((float)(int)*(short *)(param_3 + 0xd0) * param_4);
      uVar2 = FUN_007a6de0("Combat",0xffffffff);
      sprintf(local_400,"%s: %+d\n",uVar2,iVar6);
      pcVar3 = local_400;
      do {
        cVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar7 != '\0');
      uVar4 = (int)pcVar3 - (int)local_400;
      pcVar3 = (char *)(param_1 + -1);
      do {
        pcVar8 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar8 != '\0');
      pcVar8 = local_400;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar3 = pcVar3 + 1;
      }
      cVar7 = '\x01';
    }
    if (*(short *)(param_3 + 0xd4) != 0) {
      iVar6 = (int)((float)(int)*(short *)(param_3 + 0xd4) * param_4);
      uVar2 = FUN_007a6de0("Perception",0xffffffff);
      sprintf(local_400,"%s: %+d\n",uVar2,iVar6);
      pcVar3 = local_400;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar3 - (int)local_400;
      pcVar3 = (char *)(param_1 + -1);
      do {
        pcVar8 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar8 != '\0');
      pcVar8 = local_400;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar3 = pcVar3 + 1;
      }
      cVar7 = cVar7 + '\x01';
    }
    if (*(short *)(param_3 + 0xd6) != 0) {
      iVar6 = (int)((float)(int)*(short *)(param_3 + 0xd6) * param_4);
      uVar2 = FUN_007a6de0(&DAT_00a2e4fc,0xffffffff);
      sprintf(local_400,"%s: %+d\n",uVar2,iVar6);
      pcVar3 = local_400;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar3 - (int)local_400;
      pcVar3 = (char *)(param_1 + -1);
      do {
        pcVar8 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar8 != '\0');
      pcVar8 = local_400;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar3 = pcVar3 + 1;
      }
      cVar7 = cVar7 + '\x01';
    }
    if (*(short *)(param_3 + 0xd2) != 0) {
      iVar6 = (int)((float)(int)*(short *)(param_3 + 0xd2) * param_4);
      uVar2 = FUN_007a6de0("Theory",0xffffffff);
      sprintf(local_400,"%s: %+d\n",uVar2,iVar6);
      pcVar3 = local_400;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar3 - (int)local_400;
      pcVar3 = (char *)(param_1 + -1);
      do {
        pcVar8 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar8 != '\0');
      pcVar8 = local_400;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar3 = pcVar3 + 1;
      }
      cVar7 = cVar7 + '\x01';
    }
    return cVar7;
  }
  return '\0';
}
```
