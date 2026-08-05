# Raw capture: DES_KeySchedule

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b740` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071b740` |
| **Canonical name** | `DES_KeySchedule` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall DES_KeySchedule(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int local_10;
  int local_c;
  int local_8;
  uint local_4;
  
  iVar1 = 0;
  do {
    (&DAT_00d176f0)[iVar1] =
         (*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcad0)[iVar1] - 1U & 7) * 4) &
         (int)*(char *)(((int)((int)(char)(&DAT_00afcad0)[iVar1] - 1U) >> 3) + param_2)) != 0;
    (&DAT_00d176f1)[iVar1] =
         (*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcad1)[iVar1] - 1U & 7) * 4) &
         (int)*(char *)(((int)((int)(char)(&DAT_00afcad1)[iVar1] - 1U) >> 3) + param_2)) != 0;
    (&DAT_00d176f2)[iVar1] =
         (*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcad2)[iVar1] - 1U & 7) * 4) &
         (int)*(char *)(((int)((int)(char)(&DAT_00afcad2)[iVar1] - 1U) >> 3) + param_2)) != 0;
    (&DAT_00d176f3)[iVar1] =
         (*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcad3)[iVar1] - 1U & 7) * 4) &
         (int)*(char *)(((int)((int)(char)(&DAT_00afcad3)[iVar1] - 1U) >> 3) + param_2)) != 0;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x38);
  puVar7 = (undefined4 *)&DAT_00d16e90;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_8 = 0;
  local_10 = 0;
  do {
    iVar1 = 0;
    iVar2 = (char)(&DAT_00afcb08)[local_8] + -0x1a;
    do {
      iVar5 = iVar2 + 0x1a;
      if ((int)(((0x1b < iVar1) - 1 & 0xffffffe4) + 0x38) <= iVar5) {
        iVar5 = iVar2 + -2;
      }
      (&DAT_00d12658)[iVar1] = (&DAT_00d176f0)[iVar5];
      iVar5 = iVar2 + 0x1b;
      if ((int)(((0x1a < iVar1) - 1 & 0xffffffe4) + 0x38) <= iVar5) {
        iVar5 = iVar2 + -1;
      }
      (&DAT_00d12659)[iVar1] = (&DAT_00d176f0)[iVar5];
      iVar5 = iVar2 + 0x1c;
      if ((int)(((0x1b < iVar1 + 2) - 1 & 0xffffffe4) + 0x38) <= iVar2 + 0x1c) {
        iVar5 = iVar2;
      }
      (&DAT_00d1265a)[iVar1] = (&DAT_00d176f0)[iVar5];
      iVar5 = iVar2 + 0x1d;
      if ((int)(((0x18 < iVar1) - 1 & 0xffffffe4) + 0x38) <= iVar5) {
        iVar5 = iVar2 + 1;
      }
      (&DAT_00d1265b)[iVar1] = (&DAT_00d176f0)[iVar5];
      iVar1 = iVar1 + 4;
      iVar2 = iVar2 + 4;
    } while (iVar1 < 0x38);
    uVar6 = 0;
    local_c = 4;
    local_4 = 0xfffffffc;
    uVar4 = 3;
    uVar8 = 2;
    uVar3 = 1;
    do {
      if (*(char *)(*(char *)(uVar3 + 0xafcb17) + 0xd12657) != '\0') {
        (&DAT_00d16e90)[local_10 + ((int)uVar6 >> 3)] =
             (&DAT_00d16e90)[local_10 + ((int)uVar6 >> 3)] | (&DAT_00afcd68)[(uVar6 & 7) * 4];
      }
      if (*(char *)((char)(&DAT_00afcb18)[uVar3] + 0xd12657) != '\0') {
        (&DAT_00d16e90)[local_10 + ((int)uVar3 >> 3)] =
             (&DAT_00d16e90)[local_10 + ((int)uVar3 >> 3)] | (&DAT_00afcd68)[(uVar3 & 7) * 4];
      }
      if (*(char *)((char)(&DAT_00afcb18)[uVar8] + 0xd12657) != '\0') {
        (&DAT_00d16e90)[local_10 + ((int)uVar8 >> 3)] =
             (&DAT_00d16e90)[local_10 + ((int)uVar8 >> 3)] | (&DAT_00afcd68)[(uVar8 & 7) * 4];
      }
      if (*(char *)((char)(&DAT_00afcb18)[uVar4] + 0xd12657) != '\0') {
        (&DAT_00d16e90)[local_10 + ((int)uVar4 >> 3)] =
             (&DAT_00d16e90)[local_10 + ((int)uVar4 >> 3)] | (&DAT_00afcd68)[(uVar4 & 7) * 4];
      }
      if (*(char *)((char)(&DAT_00afcb20)[local_4] + 0xd12657) != '\0') {
        (&DAT_00d16e90)[local_10 + (local_c >> 3)] =
             (&DAT_00d16e90)[local_10 + (local_c >> 3)] | (&DAT_00afcd68)[(local_4 & 7) * 4];
      }
      if (*(char *)((char)(&DAT_00afcb19)[local_c] + 0xd12657) != '\0') {
        (&DAT_00d16e90)[local_10 + ((int)(uVar6 + 5) >> 3)] =
             (&DAT_00d16e90)[local_10 + ((int)(uVar6 + 5) >> 3)] |
             (&DAT_00afcd68)[(uVar6 + 5 & 7) * 4];
      }
      local_c = local_c + 6;
      uVar3 = uVar3 + 6;
      local_4 = local_4 + 6;
      uVar6 = uVar6 + 6;
      uVar8 = uVar8 + 6;
      uVar4 = uVar4 + 6;
    } while ((int)uVar3 < 0x31);
    local_8 = local_8 + 1;
    local_10 = local_10 + 6;
  } while (local_10 < 0x60);
  return;
}
```
