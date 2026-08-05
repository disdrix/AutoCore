# Raw capture: FUN_006fabe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006fabe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006fabe0` |
| **Canonical name** | `FUN_006fabe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_006fabe0(int param_1,int param_2,short *param_3,int param_4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  short sVar4;
  char *pcVar5;
  float *pfVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  int iVar10;
  bool bVar11;
  undefined1 local_d;
  int local_c;
  int local_8;
  char local_4 [4];
  
  iVar3 = param_4;
  local_8 = 8;
  local_c = param_1;
  do {
    fVar2 = *(float *)(local_c + 0xd0);
    iVar10 = 0;
    pfVar6 = (float *)(local_c + 0xd8);
    iVar7 = 3;
    do {
      if (fVar2 < pfVar6[-1]) {
        iVar10 = iVar7 + -2;
        fVar2 = pfVar6[-1];
      }
      if (fVar2 < *pfVar6) {
        iVar10 = iVar7 + -1;
        fVar2 = *pfVar6;
      }
      if (fVar2 < pfVar6[1]) {
        fVar2 = pfVar6[1];
        iVar10 = iVar7;
      }
      if (fVar2 < pfVar6[2]) {
        iVar10 = iVar7 + 1;
        fVar2 = pfVar6[2];
      }
      if (fVar2 < pfVar6[3]) {
        iVar10 = iVar7 + 2;
        fVar2 = pfVar6[3];
      }
      if (fVar2 < pfVar6[4]) {
        iVar10 = iVar7 + 3;
        fVar2 = pfVar6[4];
      }
      if (fVar2 < pfVar6[5]) {
        iVar10 = iVar7 + 4;
        fVar2 = pfVar6[5];
      }
      iVar1 = iVar7 + 5;
      pfVar6 = pfVar6 + 7;
      iVar7 = iVar7 + 7;
    } while (iVar1 < 0xf);
    if (iVar10 < 3) {
      *param_3 = (short)iVar10;
      FUN_006f9a10(iVar3,iVar10);
      sVar4 = FUN_006f80d0(*(undefined4 *)(iVar3 + 0x30));
      param_3[1] = sVar4;
      iVar7 = *(int *)(param_2 + 0x54) + -1;
      if (-1 < iVar7) {
        psVar9 = (short *)(param_2 + 0x22 + iVar7 * 6);
        do {
          if ((psVar9[-1] == *param_3) && (*psVar9 == sVar4)) {
            return 1;
          }
          iVar7 = iVar7 + -1;
          psVar9 = psVar9 + -3;
        } while (-1 < iVar7);
      }
      pcVar5 = (char *)FUN_006f8b10(&param_4,iVar3);
      bVar11 = *pcVar5 == '\0';
    }
    else if (iVar10 < 6) {
      *param_3 = (short)iVar10;
      FUN_006f9c20(iVar3,iVar10 + -3);
      sVar4 = FUN_006f80d0(*(undefined4 *)(iVar3 + 0x30));
      param_3[1] = sVar4;
      iVar7 = *(int *)(param_2 + 0x54) + -1;
      if (-1 < iVar7) {
        psVar9 = (short *)(param_2 + 0x22 + iVar7 * 6);
        do {
          if ((psVar9[-1] == *param_3) && (*psVar9 == sVar4)) {
            return 1;
          }
          iVar7 = iVar7 + -1;
          psVar9 = psVar9 + -3;
        } while (-1 < iVar7);
      }
      pcVar5 = (char *)FUN_006f8c00(&local_d,iVar3);
      bVar11 = *pcVar5 == '\0';
    }
    else {
      *(undefined2 *)(iVar3 + 0x38) = *(undefined2 *)(&DAT_00a0ef08 + iVar10 * 4);
      *(undefined2 *)(iVar3 + 0x3a) = *(undefined2 *)(&DAT_00a0ef2c + iVar10);
      FUN_006f9e30(iVar3);
      psVar9 = param_3 + 1;
      FUN_006f8340(param_3,psVar9);
      *(short *)(iVar3 + 0x38) = *param_3;
      *(short *)(iVar3 + 0x3a) = *psVar9;
      iVar7 = *(int *)(param_2 + 0x54) + -1;
      if (-1 < iVar7) {
        psVar8 = (short *)(param_2 + 0x22 + iVar7 * 6);
        do {
          if ((psVar8[-1] == *param_3) && (*psVar8 == *psVar9)) {
            return 1;
          }
          iVar7 = iVar7 + -1;
          psVar8 = psVar8 + -3;
        } while (-1 < iVar7);
      }
      FUN_006f9f90(local_4,iVar3);
      bVar11 = local_4[0] == '\0';
    }
    if (!bVar11) {
      return 2;
    }
    *(undefined4 *)(local_c + 0xd0 + iVar10 * 4) = 0xff7fffff;
    local_8 = local_8 + -1;
  } while (0 < local_8);
  return 0;
}
```
