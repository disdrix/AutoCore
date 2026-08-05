# Raw capture: Client_InteractClickPickTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_009247b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009247b0` |
| **Canonical name** | `Client_InteractClickPickTarget` |
| **System** | `interaction-activation` |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |
| **Live re-check** | `2026-07-29` `batch_decompile` `0x009247b0` ≡ body below (no delta) |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Click/interact target pick. When selected object has flag at +0x11c and distance <= DAT_00aaa6fc
   (~25f), calls Client_SendUseObject (C2S 0x2072). Server should range-gate UseObject (~25-30f). */

undefined4
Client_InteractClickPickTarget
          (undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  char *pcVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  float *pfVar8;
  int *unaff_EBX;
  float10 fVar9;
  float fStack_10c;
  int iStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  int iStack_e4;
  float fStack_d8;
  int iStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  undefined4 uStack_a4;
  TFID_16 aTStack_98 [3];
  undefined1 auStack_68 [84];
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  unaff_EBX[0x349] = 0;
  if ((*(char *)(DAT_00d1b6d8 + 0x4f1) != '\0') ||
     (cVar3 = (**(code **)(*unaff_EBX + 0x3d8))(), cVar3 == '\0')) {
    return 0;
  }
  iStack_d4 = (int)(short)((uint)param_2 >> 0x10);
  unaff_EBX[0x156] = 0;
  uStack_12 = 0xff;
  uStack_13 = 0xff;
  uStack_14 = 0xff;
  uStack_11 = 0xff;
  if (DAT_00d1a8da != '\0') {
    iStack_d4 = DAT_00d1d870;
    fStack_d8 = DAT_00d1d86c;
    iVar6 = (**(code **)(**(int **)(*(int *)(DAT_00d1b644 + 0xe894) + 0xc0) + 0x10))
                      (&fStack_d8,5,auStack_68,0);
    if (iVar6 == 0) {
      return 0;
    }
    pcVar1 = *(char **)(iVar6 + 0x78);
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
    if (*pcVar1 != '\x01') {
      return 0;
    }
    if (*(int *)(pcVar1 + 4) == 0) {
      return 0;
    }
    FUN_0093e120(*(int *)(pcVar1 + 4));
    return 1;
  }
  iStack_108 = DAT_00d1d870;
  fStack_10c = DAT_00d1d86c;
  piVar4 = (int *)FUN_00490070(&fStack_10c,auStack_68,param_4);
  aTStack_98[0].dwCoidLo = DAT_00a158b8;
  aTStack_98[0].dwCoidHi = DAT_00a158bc;
  aTStack_98[0].bGlobal = (byte)DAT_00a158c0;
  aTStack_98[0].bPad0 = DAT_00a158c0._1_1_;
  aTStack_98[0].bPad1 = DAT_00a158c0._2_1_;
  aTStack_98[0].bPad2 = DAT_00a158c0._3_1_;
  aTStack_98[0].bPad3 = (byte)DAT_00a158c4;
  aTStack_98[0].bPad4 = DAT_00a158c4._1_1_;
  aTStack_98[0].bPad5 = DAT_00a158c4._2_1_;
  aTStack_98[0].bPad6 = DAT_00a158c4._3_1_;
  if ((piVar4 == (int *)0x0) && (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) {
    bVar2 = false;
    fStack_104 = 0.0;
    if (param_3 == '\0') {
      iStack_108 = iStack_d4;
      fStack_10c = (float)(int)(short)param_2;
      FUN_0075c340(&fStack_10c,&fStack_100,&fStack_bc);
      fStack_b0 = fStack_bc;
      fStack_ac = fStack_b8;
      fStack_f0 = fStack_100;
      fStack_a8 = fStack_b4;
      fStack_ec = fStack_fc;
      uStack_a4 = 0;
      fStack_e8 = fStack_f8;
      iStack_e4 = 0;
      cVar3 = FUN_004cff70(&fStack_f0,&fStack_b0,&fStack_d0,400);
      if (cVar3 == '\0') {
        return 1;
      }
      bVar2 = true;
      fVar9 = (float10)FUN_0040d020(fStack_d0 - *(float *)(DAT_00d17944 + 0x228),
                                    fStack_cc - *(float *)(DAT_00d17944 + 0x22c),
                                    fStack_c8 - *(float *)(DAT_00d17944 + 0x230));
      fStack_104 = (float)(fVar9 * (float10)_DAT_00aaacbc);
      fStack_10c = fStack_104 * DAT_00a110d8;
      if (DAT_00aaa6fc <= fStack_10c) {
        fStack_10c = DAT_00aaa6fc;
      }
      iVar6 = DAT_00d1b6d8;
      if (DAT_00d1b6d8 != 0) {
        iVar6 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
      }
      Skill_GatherTargetsInArea
                (aTStack_98,0,DAT_00d1b644,iVar6,&fStack_d0,fStack_10c,1,3,0,0,1,1,0,0,0xbf800000);
      if ((aTStack_98[0].dwCoidLo & aTStack_98[0].dwCoidHi) == 0xffffffff) {
        fStack_10c = fStack_104 * DAT_00aaa688;
        if (DAT_00aaa6fc <= fStack_10c) {
          fStack_10c = DAT_00aaa6fc;
        }
        iVar6 = DAT_00d1b6d8;
        if (DAT_00d1b6d8 != 0) {
          iVar6 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
        }
        FUN_0058cd60(aTStack_98,0,DAT_00d1b644,iVar6,&fStack_d0,fStack_10c,1,5,0,0,1);
        if ((aTStack_98[0].dwCoidLo & aTStack_98[0].dwCoidHi) != 0xffffffff) {
          piVar4 = Object_ResolveFromTFID(aTStack_98);
        }
      }
      else {
        piVar5 = Object_ResolveFromTFID(aTStack_98);
        if ((piVar5 != (int *)0x0) && (*(int *)(piVar5[0x2a] + 0x38) == 0x12)) {
          (**(code **)(*piVar5 + 0x1d8))();
          cVar3 = FUN_0040b1b0();
          if (cVar3 != '\0') {
            piVar4 = piVar5;
          }
        }
      }
    }
    if (piVar4 == (int *)0x0) {
      aTStack_98[0].dwCoidLo = DAT_00a158b8;
      aTStack_98[0].dwCoidHi = DAT_00a158bc;
      aTStack_98[0].bGlobal = (byte)DAT_00a158c0;
      aTStack_98[0].bPad0 = DAT_00a158c0._1_1_;
      aTStack_98[0].bPad1 = DAT_00a158c0._2_1_;
      aTStack_98[0].bPad2 = DAT_00a158c0._3_1_;
      aTStack_98[0].bPad3 = (byte)DAT_00a158c4;
      aTStack_98[0].bPad4 = DAT_00a158c4._1_1_;
      aTStack_98[0].bPad5 = DAT_00a158c4._2_1_;
      aTStack_98[0].bPad6 = DAT_00a158c4._3_1_;
      if (!bVar2) {
        fStack_10c = (float)(int)(short)param_2;
        iStack_108 = iStack_d4;
        FUN_0075c340(&fStack_10c,&fStack_100,&fStack_bc);
        fStack_f0 = fStack_bc;
        fStack_ec = fStack_b8;
        fStack_b0 = fStack_100;
        fStack_e8 = fStack_b4;
        fStack_ac = fStack_fc;
        iStack_e4 = 0;
        fStack_a8 = fStack_f8;
        uStack_a4 = 0;
        cVar3 = FUN_004cff70(&fStack_b0,&fStack_f0,&fStack_d0,400);
        if (cVar3 == '\0') goto LAB_00924d29;
        fVar9 = (float10)FUN_0040d020(fStack_d0 - *(float *)(DAT_00d17944 + 0x228),
                                      fStack_cc - *(float *)(DAT_00d17944 + 0x22c),
                                      fStack_c8 - *(float *)(DAT_00d17944 + 0x230));
        fStack_104 = (float)(fVar9 * (float10)_DAT_00aaacbc);
      }
      fStack_10c = fStack_104 * DAT_00aaa6fc;
      if (DAT_00a1109c <= fStack_10c) {
        fStack_10c = DAT_00a1109c;
      }
      iVar6 = DAT_00d1b6d8;
      if (DAT_00d1b6d8 != 0) {
        iVar6 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
      }
      Skill_GatherTargetsInArea
                (aTStack_98,0,DAT_00d1b644,iVar6,&fStack_d0,fStack_10c,1,2,0,0,1,0,1,0,0xbf800000);
      if ((aTStack_98[0].dwCoidLo & aTStack_98[0].dwCoidHi) != 0xffffffff) {
        piVar4 = Object_ResolveFromTFID(aTStack_98);
      }
    }
  }
LAB_00924d29:
  if ((char)param_4 == '\0') {
    if (DAT_00d1b6d8 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8);
    }
    if (piVar4 == piVar5) {
      return 1;
    }
    piVar5 = *(int **)(DAT_00d1b6d8 + 0x250);
    if (piVar5 != (int *)0x0) {
      piVar5 = (int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5);
    }
    if (piVar4 == piVar5) {
      return 1;
    }
  }
  unaff_EBX[0x349] = (int)piVar4;
  unaff_EBX[0x1d6] = (int)piVar4;
  unaff_EBX[0x15a] = 0;
  if (piVar4 != (int *)0x0) {
    iVar6 = FUN_005245d0(piVar4);
    if ((iVar6 != 0) || (iVar6 = FUN_00524520(unaff_EBX[0x1d6]), iVar6 != 0)) {
      Client_SendUseObject_IfInteractable();
    }
    FUN_0093e120(unaff_EBX[0x1d6]);
  }
  if (DAT_00d1bdfa != '\0') {
    DAT_00d1d867 = 1;
    uVar7 = (**(code **)(*unaff_EBX + 0x380))(param_1,param_2);
    return uVar7;
  }
  iVar6 = unaff_EBX[0x1d6];
  if (iVar6 == 0) goto switchD_00924f0c_caseD_5;
  iStack_d4 = DAT_00d1d904;
  if (DAT_00d1d900 != -1) {
    FUN_00941ac0(&DAT_00d1a640);
    goto switchD_00924f0c_caseD_3;
  }
  if (*(int *)(iVar6 + 0x11c) != 0) {
    fStack_100 = *(float *)(iVar6 + 0x80);
    fStack_fc = *(float *)(iVar6 + 0x84);
    fStack_f8 = *(float *)(iVar6 + 0x88);
    pfVar8 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                           DAT_00d1b6d8) + 0x1a0))();
    fStack_100 = fStack_100 - *pfVar8;
    fStack_fc = fStack_fc - pfVar8[1];
    fStack_f8 = fStack_f8 - pfVar8[2];
    if (SQRT(fStack_100 * fStack_100 + fStack_fc * fStack_fc + fStack_f8 * fStack_f8) <=
        DAT_00aaa6fc) {
      Client_SendUseObject();
    }
  }
  piVar4 = (int *)unaff_EBX[0x1d6];
  switch(*(undefined4 *)(piVar4[0x2a] + 0x38)) {
  case 3:
    break;
  case 4:
    fStack_f0 = 1.16098e-41;
    fStack_e8 = (float)piVar4[0x58];
    iStack_e4 = piVar4[0x59];
    Client_SendSectorPacket(&DAT_00d1a840,0x10,&fStack_f0);
    break;
  case 0xe:
  case 0x12:
  case 0x14:
    if (((piVar4 != (int *)0x0) && (iVar6 = (**(code **)(*piVar4 + 0x1d8))(), iVar6 != 0)) &&
       (cVar3 = FUN_0040b1b0(), cVar3 != '\0')) {
      FUN_0093e120(0);
      if (param_3 != '\0') {
        *(undefined1 *)((int)unaff_EBX + 0xa32) = 0;
      }
      break;
    }
  default:
switchD_00924f0c_caseD_5:
    if (param_3 != '\0') {
      *(undefined1 *)((int)unaff_EBX + 0xa32) = 1;
    }
    break;
  case 0x16:
    fStack_e8 = (float)CONCAT31(fStack_e8._1_3_,(char)piVar4[0x5a]);
    FUN_00938670(piVar4[0x58],piVar4[0x59],fStack_e8,iStack_e4);
  }
switchD_00924f0c_caseD_3:
  if (((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&
     (*(undefined1 *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x107) = 1,
     *(char *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x108) == '\0')) {
    FUN_004f3640(0,1);
  }
  if (param_3 != '\0') {
    *(undefined1 *)((int)unaff_EBX + 0xa32) = 1;
  }
  return 1;
}
```

---

## Version note `2026-07-29` (append-only)

| Check | Result |
|---|---|
| Live `batch_decompile` `0x009247b0` | **Identical** to raw body above |
| Callers | Sole: `FUN_009251d0` @ `0x009251d0` (two call sites) |
| Callees (UseObject) | `Client_SendUseObject` `0x00916740`; `Client_SendUseObject_IfInteractable` `0x00930d70` |
| `DAT_00aaa6fc` | `read_memory` → `00 00 c8 41` = **25.0f** |
| `DAT_00a110d8` | `00 00 20 41` = **10.0f** |
| `DAT_00aaa688` | `00 00 a0 40` = **5.0f** |
| `DAT_00a1109c` | `00 00 20 42` = **40.0f** |
| `_DAT_00aaacbc` | `8f c2 75 3c` ≈ **0.015f** |
| Case 4 imm float | bits `0x0000205d` = QuestItemPickup opcode |
| Three-rep + dual | Human-refined clean/annotated; A/B refresh this date |
| Chain link | `reviews/CHAIN_2026-07-29_interaction_useobject.md` |
