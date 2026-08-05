# Raw capture: FUN_005acf10

| Field | Value |
|---|---|
| **Stable ID** | `aa_005acf10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005acf10` |
| **Canonical name** | `FUN_005acf10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005acf10(int param_1,FILE *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint local_24;
  int local_20;
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005ae180();
  *(int *)(*(int *)(param_1 + 0x8c) + 4) = *(int *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
  *(int *)(*(int *)(param_1 + 0x8c) + 8) = *(int *)(param_1 + 0x8c);
  FUN_005ae100();
  *(int *)(*(int *)(param_1 + 0x74) + 4) = *(int *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(int *)(*(int *)(param_1 + 0x74) + 8) = *(int *)(param_1 + 0x74);
  FUN_005ae100();
  *(int *)(*(int *)(param_1 + 0x80) + 4) = *(int *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(int *)(*(int *)(param_1 + 0x80) + 8) = *(int *)(param_1 + 0x80);
  local_20 = 0;
  for (local_24 = 0;
      (*(int *)(param_1 + 0x14) != 0 &&
      (local_24 < (uint)((*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) / 0xc)));
      local_24 = local_24 + 1) {
    local_10 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 8 + local_20);
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x14) + local_20);
    local_14 = *puVar4;
    local_8 = puVar4[1];
    local_4 = puVar4[2];
    local_c = local_14;
    FUN_005aec50(local_1c,&local_14);
    local_20 = local_20 + 0xc;
  }
  local_20 = 0;
  for (uVar6 = 0;
      (*(int *)(param_1 + 0x24) != 0 &&
      (uVar6 < (uint)((*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24)) / 0xc)));
      uVar6 = uVar6 + 1) {
    local_14 = *(undefined4 *)(local_20 + *(int *)(param_1 + 0x24));
    iVar5 = local_20 + *(int *)(param_1 + 0x24);
    local_10 = *(undefined4 *)(iVar5 + 8);
    local_8 = *(undefined4 *)(iVar5 + 4);
    local_4 = *(undefined4 *)(iVar5 + 8);
    local_c = local_14;
    FUN_005aec50(local_1c,&local_14);
    local_20 = local_20 + 0xc;
  }
  for (uVar6 = 0;
      (iVar5 = *(int *)(param_1 + 0x34), iVar5 != 0 &&
      (uVar6 < (uint)(*(int *)(param_1 + 0x38) - iVar5 >> 3))); uVar6 = uVar6 + 1) {
    local_14 = *(undefined4 *)(iVar5 + uVar6 * 8);
    local_c = *(undefined4 *)(iVar5 + uVar6 * 8 + 4);
    local_10 = local_14;
    FUN_005aed20(local_1c,&local_14);
  }
  fprintf(param_2,"\t\t<Requirement type=\"crazytaxi\" slot=\"%d\">\r\n");
  fprintf(param_2,"\t\t\t<ContinentCBID>%d</ContinentCBID>\r\n",*(undefined4 *)(param_1 + 0x44));
  fprintf(param_2,"\t\t\t<MissionStopLimit>%d</MissionStopLimit>\r\n",
          (uint)(*(char *)(param_1 + 100) != '\0'));
  if (*(char *)(param_1 + 100) != '\0') {
    fprintf(param_2,"\t\t\t<MissionStopCount>%d</MissionStopCount>\r\n");
  }
  fprintf(param_2,"\t\t\t<VehicleMaxVec>%f</VehicleMaxVec>\r\n",(double)*(float *)(param_1 + 0x5c));
  fprintf(param_2,"\t\t\t<RadiusOfStop>%f</RadiusOfStop>\r\n",(double)*(float *)(param_1 + 0x60));
  for (uVar6 = 0;
      (iVar5 = *(int *)(param_1 + 0x4c), iVar5 != 0 &&
      (uVar6 < (uint)(*(int *)(param_1 + 0x50) - iVar5 >> 3))); uVar6 = uVar6 + 1) {
    fprintf(param_2,"\t\t\t<GenericTargetCOID>%i</GenericTargetCOID>\r\n",
            *(undefined4 *)(iVar5 + uVar6 * 8));
  }
  fprintf(param_2,"\t\t\t<GiveMoney>%d</GiveMoney>\r\n");
  if ((*(char *)(param_1 + 0x6c) != '\0') &&
     (piVar7 = (int *)**(int **)(param_1 + 0x74), piVar7 != *(int **)(param_1 + 0x74))) {
    do {
      fprintf(param_2,
              "\t\t\t\t<MoneyReward><Level>%d</Level><Stops>%d</Stops><Amount>%d</Amount></MoneyReward>\r\n"
              ,piVar7[5],piVar7[7]);
      if (*(char *)((int)piVar7 + 0x21) == '\0') {
        piVar2 = (int *)piVar7[2];
        if (*(char *)((int)piVar2 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          piVar7 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x21);
            piVar7 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x21);
          piVar3 = (int *)piVar7[1];
          piVar2 = piVar7;
          while ((piVar7 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x21);
            piVar3 = (int *)piVar7[1];
            piVar2 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_1 + 0x74));
  }
  fprintf(param_2,"\t\t\t<GiveExp>%d</GiveExp>\r\n");
  if ((*(char *)(param_1 + 0x6d) != '\0') &&
     (piVar7 = (int *)**(int **)(param_1 + 0x80), piVar7 != *(int **)(param_1 + 0x80))) {
    do {
      fprintf(param_2,
              "\t\t\t\t<ExpReward> <Level>%d</Level> <Stops>%d</Stops> <Amount>%d</Amount> </ExpReward>\r\n"
              ,piVar7[5],piVar7[7]);
      if (*(char *)((int)piVar7 + 0x21) == '\0') {
        piVar2 = (int *)piVar7[2];
        if (*(char *)((int)piVar2 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          piVar7 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x21);
            piVar7 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x21);
          piVar3 = (int *)piVar7[1];
          piVar2 = piVar7;
          while ((piVar7 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x21);
            piVar3 = (int *)piVar7[1];
            piVar2 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_1 + 0x80));
  }
  piVar7 = (int *)**(int **)(param_1 + 0x8c);
  if (piVar7 != *(int **)(param_1 + 0x8c)) {
    do {
      fprintf(param_2,"\t\t\t<TimeLimit> <Stops>%d</Stops> <Percent>%f</Percent> </TimeLimit>\r\n",
              piVar7[4],(double)(float)piVar7[5]);
      if (*(char *)((int)piVar7 + 0x19) == '\0') {
        piVar2 = (int *)piVar7[2];
        if (*(char *)((int)piVar2 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar7 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x19);
            piVar7 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x19);
          piVar3 = (int *)piVar7[1];
          piVar2 = piVar7;
          while ((piVar7 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x19);
            piVar3 = (int *)piVar7[1];
            piVar2 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_1 + 0x8c));
  }
  fprintf(param_2,"\t\t</Requirement>\r\n");
  return;
}
```
