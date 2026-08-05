# Raw capture: FUN_008baa20

| Field | Value |
|---|---|
| **Stable ID** | `aa_008baa20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008baa20` |
| **Canonical name** | `FUN_008baa20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_008baa20(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int *piVar9;
  float fVar10;
  int **ppiStack_144;
  int **ppiStack_140;
  char *pcStack_134;
  void *pvStack_114;
  int *piStack_110;
  char *pcStack_10c;
  void *pvStack_108;
  int *piStack_104;
  char *pcStack_100;
  undefined4 uStack_fc;
  int *piStack_f8;
  char *pcStack_f4;
  undefined4 uStack_f0;
  int *piStack_ec;
  char *pcStack_e8;
  undefined4 uStack_e4;
  int *piStack_e0;
  char *pcStack_dc;
  undefined4 uStack_d8;
  int *piStack_d4;
  char *pcStack_d0;
  void *pvStack_cc;
  int *piStack_c8;
  char *pcStack_c4;
  undefined4 uStack_c0;
  int *piStack_bc;
  char *pcStack_b8;
  undefined4 uStack_b4;
  int *piStack_b0;
  char *pcStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  char *pcStack_a0;
  undefined4 uStack_9c;
  int *piStack_98;
  char *pcStack_94;
  undefined4 uStack_90;
  int *piStack_8c;
  char *pcStack_88;
  undefined4 uStack_84;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009b66cc;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  param_1[0x16c] = -1;
  uStack_84 = 0x8baa52;
  FUN_00792600();
  uStack_84 = 0xffffffff;
  pcStack_88 = "i_d_macro_2d_wnd_bg_fill.xml";
  piStack_8c = param_1 + 0x144;
  uStack_90 = 0x8baa6a;
  (**(code **)(*param_1 + 0x404))();
  uStack_90 = 0xffffffff;
  pcStack_94 = "i_d_macro_2d_wnd_bg_texture.xml";
  piStack_98 = param_1 + 0x143;
  uStack_9c = 0x8baa82;
  (**(code **)(*param_1 + 0x404))();
  uStack_9c = 0xffffffff;
  pcStack_a0 = "i_d_macro_2d_wnd_inner_frame.xml";
  piStack_a4 = param_1 + 0x145;
  uStack_a8 = 0x8baa9a;
  (**(code **)(*param_1 + 0x404))();
  uStack_a8 = 0xffffffff;
  pcStack_ac = "i_d_macro_2d_wnd_title.xml";
  piStack_b0 = param_1 + 0x146;
  uStack_b4 = 0x8baab2;
  (**(code **)(*param_1 + 0x404))();
  uStack_b4 = 0xffffffff;
  pcStack_b8 = "i_d_macro_2d_wnd_title_cover.xml";
  piStack_bc = param_1 + 0x147;
  uStack_c0 = 0x8baaca;
  (**(code **)(*param_1 + 0x404))();
  uStack_c0 = 0xffffffff;
  pcStack_c4 = "i_d_macro_2d_wnd_icon.xml";
  piStack_c8 = param_1 + 0x148;
  pvStack_cc = (void *)0x8baae2;
  (**(code **)(*param_1 + 0x404))();
  pvStack_cc = (void *)0xffffffff;
  pcStack_d0 = "i_d_macro_2d_wnd_icon_cover.xml";
  piStack_d4 = param_1 + 0x149;
  uStack_d8 = 0x8baafa;
  (**(code **)(*param_1 + 0x404))();
  uStack_d8 = 0xffffffff;
  pcStack_dc = "i_d_macro_2d_wnd_label_name.xml";
  piStack_e0 = param_1 + 0x14a;
  uStack_e4 = 0x8bab12;
  (**(code **)(*param_1 + 0x404))();
  uStack_e4 = 0xffffffff;
  pcStack_e8 = "i_d_macro_2d_wnd_label_lines.xml";
  piStack_ec = param_1 + 0x14b;
  uStack_f0 = 0x8bab2a;
  (**(code **)(*param_1 + 0x404))();
  uStack_f0 = 0xffffffff;
  pcStack_f4 = "i_d_macro_2d_wnd_instructions.xml";
  piStack_f8 = param_1 + 0x14c;
  uStack_fc = 0x8bab42;
  (**(code **)(*param_1 + 0x404))();
  uStack_fc = 0xffffffff;
  pcStack_100 = "i_d_macro_2d_wnd_bg_buttons.xml";
  piStack_104 = param_1 + 0x14d;
  pvStack_108 = (void *)0x8bab5a;
  (**(code **)(*param_1 + 0x404))();
  pvStack_108 = (void *)0x9c40;
  pcStack_10c = "i_d_macro_2d_btn_close.xml";
  piStack_110 = param_1 + 0x141;
  pvStack_114 = (void *)0x8bab76;
  (**(code **)(*param_1 + 0x408))();
  pvStack_114 = (void *)0xffffffff;
  (**(code **)(*param_1 + 0x404))();
  piStack_f8 = operator_new(0x4a4);
  uStack_a8 = 0;
  iVar3 = 0;
  if (piStack_f8 != (int *)0x0) {
    iVar3 = FUN_00795f20();
  }
  uStack_a8 = 0xffffffff;
  param_1[0x159] = iVar3;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x159] + 0x28))();
  (**(code **)(*(int *)param_1[0x159] + 0x1d0))();
  (**(code **)(*(int *)param_1[0x159] + 0x98))();
  pvStack_114 = (void *)0x0;
  piVar9 = param_1 + 0x153;
  do {
    pcStack_134 = "i_d_macro_2d_wnd_bg_edit.xml";
    piVar5 = piVar9 + -5;
    (**(code **)(*param_1 + 0x404))();
    ppiStack_140 = (int **)0x8bac21;
    pvStack_114 = operator_new(0x4a4);
    pcStack_c4 = (char *)0x1;
    iVar3 = 0;
    if (pvStack_114 != (void *)0x0) {
      iVar3 = FUN_00795f20();
    }
    pcStack_c4 = (char *)0xffffffff;
    *piVar9 = iVar3;
    ppiStack_140 = (int **)0x8bac53;
    (**(code **)(*param_1 + 0xa8))();
    ppiStack_140 = (int **)0xa46f48;
    ppiStack_144 = (int **)0x8bac5f;
    (**(code **)(*(int *)*piVar9 + 0x28))();
    ppiStack_144 = (int **)0x6;
    (**(code **)(*(int *)*piVar9 + 0x98))();
    *(undefined1 *)(*piVar9 + 0x488) = 1;
    (**(code **)(*(int *)*piVar9 + 0x1d0))(0xff);
    piVar1 = (int *)*piVar5;
    pcStack_134 = (char *)0x40a00000;
    iVar3 = (**(code **)(*piVar1 + 0x134))(&piStack_110);
    pcStack_134 = (char *)(*(float *)(iVar3 + 4) * (float)piVar5 * _DAT_00aaabe0);
    iVar3 = (**(code **)(*piVar1 + 0x124))(&pcStack_10c);
    fVar10 = 0.0;
    pcStack_134 = (char *)((float)DAT_00d1e81c * ((float)piVar5 + *(float *)(iVar3 + 4)) *
                          DAT_00aaa678);
    puVar4 = (undefined4 *)(**(code **)(*(int *)*piVar5 + 0x120))(&pvStack_108,1,0);
    pcStack_134 = (char *)*puVar4;
    (**(code **)(*(int *)*piVar5 + 0x110))(&pcStack_134);
    piVar1 = (int *)*piVar9;
    (**(code **)(*(int *)*piVar5 + 0x134))(&piStack_110);
    (**(code **)(*piVar1 + 0x124))(&pcStack_10c);
    piVar5 = (int *)(**(code **)(*(int *)*piVar9 + 0x120))(&pvStack_108,1,0);
    ppiStack_144 = (int **)*piVar5;
    ppiStack_140 = (int **)(int)fVar10;
    (**(code **)(*(int *)*piVar9 + 0x110))(&ppiStack_144);
    pvStack_114 = pvStack_108;
    piVar9 = piVar9 + 1;
  } while ((int)pvStack_108 < 5);
  iVar3 = 0;
  piVar9 = param_1 + 0x15a;
  do {
    pvStack_108 = (void *)(iVar3 / param_1[0x16b]);
    pcStack_10c = (char *)(iVar3 % param_1[0x16b]);
    pcStack_134 = (char *)0x8badfd;
    pvStack_114 = operator_new(0x530);
    pcStack_b8 = (char *)0x2;
    if (pvStack_114 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      pcStack_134 = (char *)0x8bae16;
      iVar6 = FUN_0082b4c0();
    }
    pcStack_b8 = (char *)0xffffffff;
    *piVar9 = iVar6;
    pcStack_134 = (char *)0x8bae30;
    (**(code **)(*param_1 + 0xa8))();
    pcStack_134 = (char *)(iVar3 + 0x9c42);
    (**(code **)(*(int *)*piVar9 + 0x74))();
    piVar5 = (int *)*piVar9;
    if ((char)piVar5[0x13f] != '\0') {
      *(undefined1 *)(piVar5 + 0x13f) = 0;
      cVar2 = (**(code **)(*piVar5 + 0x3d8))();
      if (cVar2 != '\0') {
        (**(code **)(*piVar5 + 0x444))();
      }
    }
    (**(code **)(*(int *)*piVar9 + 0x43c))();
    *(int *)(*piVar9 + 0x520) = iVar3;
    (**(code **)(*(int *)*piVar9 + 0x444))();
    piVar5 = (int *)*piVar9;
    iVar6 = (**(code **)(*piVar5 + 0x134))();
    pvStack_114 = (void *)((float)(int)pvStack_114 * *(float *)(iVar6 + 4));
    ppiStack_140 = (int **)0x8baeb5;
    (**(code **)(*piVar5 + 0x124))();
    ppiStack_140 = &piStack_ec;
    ppiStack_144 = (int **)0x8baee9;
    pfVar7 = (float *)(**(code **)(*(int *)*piVar9 + 0x134))();
    ppiStack_144 = &piStack_f8;
    pfVar8 = (float *)(**(code **)(*(int *)*piVar9 + 0x124))();
    piStack_110 = (int *)0x0;
    pvStack_114 = (void *)(int)((float)DAT_00d1e818 * (*pfVar7 * 10776456.0 + *pfVar8) *
                               DAT_00aaa67c);
    (**(code **)(*(int *)*piVar9 + 0x118))(&pvStack_114);
    iVar3 = iVar3 + 1;
    piVar9 = piVar9 + 1;
  } while (iVar3 < 0xf);
  pcStack_134 = (char *)0x1;
  (**(code **)(*param_1 + 0xfc))();
  (**(code **)(*param_1 + 0x448))();
  (**(code **)(*param_1 + 0x34c))();
  (**(code **)(*param_1 + 0x450))();
  ExceptionList = pvStack_cc;
  return;
}
```
