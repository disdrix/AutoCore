# Raw capture: FUN_004f4ae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4ae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f4ae0` |
| **Canonical name** | `FUN_004f4ae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * __fastcall FUN_004f4ae0(int param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  
  iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c4 + param_1) + 0x3c) +
          0x10;
  if (iVar5 != 0) {
    if ((_DAT_00b040a0 & 1) == 0) {
      _DAT_00b040a0 = _DAT_00b040a0 | 1;
      _DAT_00b0409c = 4;
    }
    _snprintf(&DAT_00b03f98,0x104 - _DAT_00b0409c,"%S_key_i",iVar5);
    uVar1 = DAT_00a2c540;
    puVar2 = (undefined4 *)0xb03f97;
    do {
      puVar9 = puVar2;
      puVar2 = (undefined4 *)((int)puVar9 + 1);
    } while (*(char *)((int)puVar9 + 1) != '\0');
    *(undefined4 *)((int)puVar9 + 1) = DAT_00a2c53c;
    puVar10 = &DAT_00b03f98;
    *(undefined1 *)((int)puVar9 + 5) = uVar1;
    FUN_007b6a20(&DAT_00b03f98);
    cVar3 = FUN_007b6770(puVar10);
    if (cVar3 != '\0') {
      pcVar6 = &DAT_00b03f98;
      do {
        cVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
      pcVar6[-1 - _DAT_00b0409c] = '\0';
      return &DAT_00b03f98;
    }
  }
  iVar5 = (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c4 +
                                          param_1) + 0x3c) + 0x14))();
  if (iVar5 == 0) {
    DAT_00b03f98 = s_veh_p_h_default_key_i_009cd15c[0];
    DAT_00b03f99._0_1_ = s_veh_p_h_default_key_i_009cd15c[1];
    DAT_00b03f99._1_1_ = s_veh_p_h_default_key_i_009cd15c[2];
    DAT_00b03f99._2_1_ = s_veh_p_h_default_key_i_009cd15c[3];
    DAT_00b03f99._3_1_ = s_veh_p_h_default_key_i_009cd15c[4];
    DAT_00b03f9d = s_veh_p_h_default_key_i_009cd15c[5];
    DAT_00b03f99_4._1_1_ = s_veh_p_h_default_key_i_009cd15c[6];
    DAT_00b03f99_4._2_1_ = s_veh_p_h_default_key_i_009cd15c[7];
    DAT_00b03fa0 = s_veh_p_h_default_key_i_009cd15c[8];
    DAT_00b03fa0_1._0_1_ = s_veh_p_h_default_key_i_009cd15c[9];
    DAT_00b03fa0_1._1_1_ = s_veh_p_h_default_key_i_009cd15c[10];
    DAT_00b03fa0_1._2_1_ = s_veh_p_h_default_key_i_009cd15c[0xb];
    uVar7 = s_veh_p_h_default_key_i_009cd15c._12_4_;
    uVar8 = s_veh_p_h_default_key_i_009cd15c._16_4_;
    uVar4 = s_veh_p_h_default_key_i_009cd15c._20_2_;
  }
  else if (iVar5 == 1) {
    DAT_00b03f98 = s_veh_p_m_default_key_i_009cd174[0];
    DAT_00b03f99._0_1_ = s_veh_p_m_default_key_i_009cd174[1];
    DAT_00b03f99._1_1_ = s_veh_p_m_default_key_i_009cd174[2];
    DAT_00b03f99._2_1_ = s_veh_p_m_default_key_i_009cd174[3];
    DAT_00b03f99._3_1_ = s_veh_p_m_default_key_i_009cd174[4];
    DAT_00b03f9d = s_veh_p_m_default_key_i_009cd174[5];
    DAT_00b03f99_4._1_1_ = s_veh_p_m_default_key_i_009cd174[6];
    DAT_00b03f99_4._2_1_ = s_veh_p_m_default_key_i_009cd174[7];
    DAT_00b03fa0 = s_veh_p_m_default_key_i_009cd174[8];
    DAT_00b03fa0_1._0_1_ = s_veh_p_m_default_key_i_009cd174[9];
    DAT_00b03fa0_1._1_1_ = s_veh_p_m_default_key_i_009cd174[10];
    DAT_00b03fa0_1._2_1_ = s_veh_p_m_default_key_i_009cd174[0xb];
    uVar7 = s_veh_p_m_default_key_i_009cd174._12_4_;
    uVar8 = s_veh_p_m_default_key_i_009cd174._16_4_;
    uVar4 = s_veh_p_m_default_key_i_009cd174._20_2_;
  }
  else {
    if (iVar5 != 2) {
      DAT_00b03fa0 = s_i_g_2d_inv_default_00a657fc[8];
      DAT_00b03fa0_1._0_1_ = s_i_g_2d_inv_default_00a657fc[9];
      DAT_00b03fa0_1._1_1_ = s_i_g_2d_inv_default_00a657fc[10];
      DAT_00b03fa0_1._2_1_ = s_i_g_2d_inv_default_00a657fc[0xb];
      DAT_00b03f98 = s_i_g_2d_inv_default_00a657fc[0];
      DAT_00b03f99._0_1_ = s_i_g_2d_inv_default_00a657fc[1];
      DAT_00b03f99._1_1_ = s_i_g_2d_inv_default_00a657fc[2];
      DAT_00b03f99._2_1_ = s_i_g_2d_inv_default_00a657fc[3];
      DAT_00b03f99._3_1_ = s_i_g_2d_inv_default_00a657fc[4];
      DAT_00b03f9d = s_i_g_2d_inv_default_00a657fc[5];
      DAT_00b03f99_4._1_1_ = s_i_g_2d_inv_default_00a657fc[6];
      DAT_00b03f99_4._2_1_ = s_i_g_2d_inv_default_00a657fc[7];
      _DAT_00b03fa8 =
           CONCAT22(CONCAT11(DAT_00b03fa8_1._2_1_,s_i_g_2d_inv_default_00a657fc[0x12]),
                    s_i_g_2d_inv_default_00a657fc._16_2_);
      DAT_00b03fa4 = s_i_g_2d_inv_default_00a657fc[0xc];
      DAT_00b03fa4_1._0_1_ = s_i_g_2d_inv_default_00a657fc[0xd];
      DAT_00b03fa4_1._1_1_ = s_i_g_2d_inv_default_00a657fc[0xe];
      DAT_00b03fa4_1._2_1_ = s_i_g_2d_inv_default_00a657fc[0xf];
      return &DAT_00b03f98;
    }
    DAT_00b03f98 = s_veh_p_b_default_key_i_009cd18c[0];
    DAT_00b03f99._0_1_ = s_veh_p_b_default_key_i_009cd18c[1];
    DAT_00b03f99._1_1_ = s_veh_p_b_default_key_i_009cd18c[2];
    DAT_00b03f99._2_1_ = s_veh_p_b_default_key_i_009cd18c[3];
    DAT_00b03f99._3_1_ = s_veh_p_b_default_key_i_009cd18c[4];
    DAT_00b03f9d = s_veh_p_b_default_key_i_009cd18c[5];
    DAT_00b03f99_4._1_1_ = s_veh_p_b_default_key_i_009cd18c[6];
    DAT_00b03f99_4._2_1_ = s_veh_p_b_default_key_i_009cd18c[7];
    DAT_00b03fa0 = s_veh_p_b_default_key_i_009cd18c[8];
    DAT_00b03fa0_1._0_1_ = s_veh_p_b_default_key_i_009cd18c[9];
    DAT_00b03fa0_1._1_1_ = s_veh_p_b_default_key_i_009cd18c[10];
    DAT_00b03fa0_1._2_1_ = s_veh_p_b_default_key_i_009cd18c[0xb];
    uVar7 = s_veh_p_b_default_key_i_009cd18c._12_4_;
    uVar8 = s_veh_p_b_default_key_i_009cd18c._16_4_;
    uVar4 = s_veh_p_b_default_key_i_009cd18c._20_2_;
  }
  DAT_00b03fac = (char)uVar4;
  DAT_00b03fac_1 = SUB21(uVar4,1);
  DAT_00b03fa8 = (char)uVar8;
  DAT_00b03fa8_1._0_1_ = SUB41(uVar8,1);
  DAT_00b03faa = SUB41(uVar8,2);
  DAT_00b03fa8_1._2_1_ = SUB41(uVar8,3);
  DAT_00b03fa4 = (char)uVar7;
  DAT_00b03fa4_1._0_1_ = SUB41(uVar7,1);
  DAT_00b03fa4_1._1_1_ = SUB41(uVar7,2);
  DAT_00b03fa4_1._2_1_ = SUB41(uVar7,3);
  return &DAT_00b03f98;
}
```
