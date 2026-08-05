# Raw capture: FUN_007a6de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007a6de0` |
| **Canonical name** | `FUN_007a6de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
byte * __thiscall FUN_007a6de0(int param_1,byte *param_2,int param_3)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  undefined2 *puVar4;
  byte *pbVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  int iVar15;
  undefined2 *puVar16;
  undefined4 *puVar17;
  bool bVar18;
  int local_8 [2];
  
  if ((param_2 != (byte *)0x0) && (*param_2 != 0)) {
    pbVar13 = &DAT_00a32460;
    pbVar5 = param_2;
    do {
      bVar2 = *pbVar5;
      bVar18 = bVar2 < *pbVar13;
      if (bVar2 != *pbVar13) {
LAB_007a6e2c:
        iVar6 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_007a6e31;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar5[1];
      bVar18 = bVar2 < pbVar13[1];
      if (bVar2 != pbVar13[1]) goto LAB_007a6e2c;
      pbVar5 = pbVar5 + 2;
      pbVar13 = pbVar13 + 2;
    } while (bVar2 != 0);
    iVar6 = 0;
LAB_007a6e31:
    if (iVar6 != 0) {
      iVar6 = param_3;
      if (param_3 == -1) {
        iVar6 = *(int *)(param_1 + 0x2c);
      }
      local_8[0] = param_1;
      switch(iVar6) {
      case 0:
        FUN_007a62c0();
        pbVar5 = *(byte **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);
        do {
          bVar2 = *param_2;
          *pbVar5 = bVar2;
          param_2 = param_2 + 1;
          pbVar5 = pbVar5 + 1;
        } while (bVar2 != 0);
        break;
      case 1:
      case 2:
      case 3:
        puVar17 = &param_3;
        piVar10 = local_8;
        FUN_007a6490(piVar10,puVar17);
        FUN_007a6410(piVar10,puVar17);
        if (param_3 == -1) {
          FUN_007a62c0();
          pbVar5 = *(byte **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);
          do {
            bVar2 = *param_2;
            *pbVar5 = bVar2;
            param_2 = param_2 + 1;
            pbVar5 = pbVar5 + 1;
          } while (bVar2 != 0);
        }
        else {
          FUN_007a6310(iVar6,local_8[0]);
          FUN_007a6610();
        }
        break;
      case 4:
        iVar14 = 0;
        iVar6 = 0;
        pbVar5 = param_2;
        do {
          bVar2 = *pbVar5;
          pbVar5 = pbVar5 + 1;
        } while (bVar2 != 0);
        iVar3 = ((int)pbVar5 - (int)(param_2 + 1)) * 2;
        if (*(int *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4) < iVar3) {
          operator_delete__(*(void **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4));
          *(int *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4) = iVar3;
          pvVar7 = operator_new__(*(uint *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4));
          *(void **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4) = pvVar7;
        }
        uVar12 = *(uint *)(param_1 + 0x6c + *(int *)(param_1 + 0xc0) * 4);
        puVar17 = *(undefined4 **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);
        for (uVar11 = uVar12 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar17 = 0;
          puVar17 = puVar17 + 1;
        }
        for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
          *(undefined1 *)puVar17 = 0;
          puVar17 = (undefined4 *)((int)puVar17 + 1);
        }
        pbVar5 = param_2;
        do {
          bVar2 = *pbVar5;
          pbVar5 = pbVar5 + 1;
        } while (bVar2 != 0);
        iVar8 = (int)pbVar5 - (int)(param_2 + 1);
        iVar3 = *(int *)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);
        param_1 = local_8[0];
        if (0 < iVar8) {
          do {
            if (param_2[iVar14] == 0x20) {
              *(undefined1 *)(iVar6 + iVar3) = 0x20;
              iVar6 = iVar6 + 1;
              iVar15 = iVar14 + 1;
            }
            else {
              iVar9 = 0;
              do {
                if ((int)(char)param_2[iVar14] == (&DAT_00a96fa0)[iVar9]) break;
                iVar9 = iVar9 + 1;
              } while (iVar9 < 6);
              iVar15 = iVar14;
              if (iVar9 == 6) {
                iVar9 = 0;
                do {
                  piVar10 = &DAT_00a96fa0;
                  do {
                    if ((int)(char)param_2[iVar15] == *piVar10) goto joined_r0x007a7000;
                    piVar10 = piVar10 + 1;
                  } while ((int)piVar10 < 0xa96fb4);
                  iVar15 = iVar15 + 1;
                  iVar9 = iVar9 + 1;
                } while (iVar15 != iVar8);
joined_r0x007a7000:
                for (; (iVar15 < iVar8 && (param_2[iVar15] != 0x20)); iVar15 = iVar15 + 1) {
                  *(byte *)(iVar6 + iVar3) = param_2[iVar15];
                  iVar6 = iVar6 + 1;
                }
                if (0 < iVar9) {
                  pbVar5 = param_2 + iVar14;
                  do {
                    *(byte *)(iVar6 + iVar3) = *pbVar5;
                    iVar6 = iVar6 + 1;
                    pbVar5 = pbVar5 + 1;
                    iVar9 = iVar9 + -1;
                  } while (iVar9 != 0);
                }
                puVar4 = (undefined2 *)(iVar3 + -1);
                do {
                  puVar16 = puVar4;
                  puVar4 = (undefined2 *)((int)puVar16 + 1);
                } while (*(char *)((int)puVar16 + 1) != '\0');
                *(undefined2 *)((int)puVar16 + 1) = DAT_00a96f9c;
                *(undefined1 *)((int)puVar16 + 3) = DAT_00a96f9e;
                iVar6 = iVar6 + 2;
              }
              else {
                for (; (iVar15 < iVar8 && (param_2[iVar15] != 0x20)); iVar15 = iVar15 + 1) {
                  *(byte *)(iVar6 + iVar3) = param_2[iVar15];
                  iVar6 = iVar6 + 1;
                }
                puVar17 = (undefined4 *)(iVar3 + -1);
                do {
                  pcVar1 = (char *)((int)puVar17 + 1);
                  puVar17 = (undefined4 *)((int)puVar17 + 1);
                } while (*pcVar1 != '\0');
                *puVar17 = DAT_00a800e4;
                iVar6 = iVar6 + 3;
              }
            }
            iVar14 = iVar15;
          } while (iVar15 < iVar8);
        }
      }
      iVar14 = *(int *)(param_1 + 0xc0);
      iVar6 = iVar14 + 1;
      *(int *)(param_1 + 0xc0) = iVar6;
      if (iVar6 == 10) {
        *(undefined4 *)(param_1 + 0xc0) = 0;
      }
      return *(byte **)(param_1 + 4 + iVar14 * 4);
    }
  }
  return param_2;
}
```
