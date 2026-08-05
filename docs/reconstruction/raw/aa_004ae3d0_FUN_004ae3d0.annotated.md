# Annotated low-level: FUN_004ae3d0

| Field | Value |
|---|---|
| Stable ID | `aa_004ae3d0` |
| VA | `0x004ae3d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ae3d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004ae3d0(int param_1,int param_2,int param_3)

{
  float *pfVar1;
  int iVar2;
  undefined1 **ppuVar3;
  float *pfVar4;
  int iVar5;
  void *pvVar6;
  undefined1 **ppuVar7;
  undefined4 *puVar8;
  undefined1 **ppuVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined1 **ppuStack_f4;
  undefined4 uStack_f0;
  undefined1 **ppuStack_ec;
  undefined1 *puStack_e8;
  undefined1 local_d4 [4];
  undefined1 **local_d0;
  undefined1 **local_cc;
  int local_c8;
  undefined1 *local_c4;
  undefined4 local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined1 local_b0 [4];
  void *local_ac;
  undefined1 **local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  undefined1 local_94 [4];
  void *local_90;
  void *local_8c;
  undefined4 local_88;
  float local_84;
  float local_80;
  undefined4 *local_78;
  undefined4 *local_74;
  undefined4 local_70;
  float local_6c;
  int local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  fVar12 = DAT_00a0f718;
  puStack_10 = &LAB_009a137f;
  local_14 = ExceptionList;
  ppuVar9 = (undefined1 **)0x0;
  if ((*(int *)(param_2 + 4) != 0) &&
     (fVar10 = (float)((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x14), 2 < (int)fVar10)) {
    local_bc = *(float *)(param_1 + 0x10);
    local_98 = *(float *)(param_1 + 0x14);
    local_9c = 0.0;
    local_a0 = 0.0;
    ExceptionList = &local_14;
    if (0 < (int)fVar10) {
      iVar5 = 0;
      ExceptionList = &local_14;
      local_b8 = fVar10;
      do {
        iVar2 = *(int *)(param_2 + 4);
        if (*(float *)(iVar5 + iVar2) <= 0.0 && *(float *)(iVar5 + iVar2) != 0.0) {
          *(undefined4 *)(iVar5 + iVar2) = 0;
        }
        fVar10 = (float)*(int *)(param_1 + 0x10) * *(float *)(param_1 + 0x18);
        if (fVar10 <= *(float *)(iVar5 + iVar2)) {
          *(float *)(iVar5 + iVar2) = fVar10 - fVar12;
        }
        pfVar4 = (float *)(iVar5 + 8 + iVar2);
        pfVar1 = (float *)(iVar5 + 8 + iVar2);
        if (*pfVar4 <= 0.0 && *pfVar4 != 0.0) {
          *pfVar1 = 0.0;
        }
        fVar10 = (float)*(int *)(param_1 + 0x14) * *(float *)(param_1 + 0x18);
        if (fVar10 <= *pfVar1) {
          *pfVar1 = fVar10 - fVar12;
        }
        fVar11 = g_flOne / *(float *)(param_1 + 0x18);
        fVar10 = (float)(int)(*(float *)(iVar5 + iVar2) * fVar11);
        fVar11 = (float)(int)(fVar11 * *pfVar1);
        if ((int)fVar10 < (int)local_bc) {
          local_bc = fVar10;
        }
        if ((int)local_9c < (int)fVar10) {
          local_9c = fVar10;
        }
        if ((int)fVar11 < (int)local_98) {
          local_98 = fVar11;
        }
        if ((int)local_a0 < (int)fVar11) {
          local_a0 = fVar11;
        }
        iVar5 = iVar5 + 0x14;
        local_b8 = (float)((int)local_b8 + -1);
      } while (local_b8 != 0.0);
    }
    local_ac = (void *)0x0;
    local_a8 = (undefined1 **)0x0;
    local_a4 = 0;
    local_90 = (void *)0x0;
    local_8c = (void *)0x0;
    local_88 = 0;
    local_78 = (undefined4 *)0x0;
    local_74 = (undefined4 *)0x0;
    local_70 = 0;
    ppuVar7 = (undefined1 **)0x0;
    local_d0 = (undefined1 **)0x0;
    local_cc = (undefined1 **)0x0;
    local_c8 = 0;
    local_84 = **(float **)(param_2 + 4);
    local_80 = (*(float **)(param_2 + 4))[2];
    puStack_e8 = (undefined1 *)0x1;
    ppuStack_ec = (undefined1 **)0x0;
    local_c = 3;
    uStack_f0 = 0x4ae57f;
    local_68 = param_1;
    FUN_004afd00();
    pvVar6 = local_ac;
    local_c4 = *(undefined1 **)(*(int *)(param_2 + 4) + 0x14);
    local_c0 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x1c);
    if ((local_ac == (void *)0x0) ||
       ((uint)(local_a4 - (int)local_ac >> 3) <= (uint)((int)local_a8 - (int)local_ac >> 3))) {
      puStack_e8 = (undefined1 *)0x1;
      ppuStack_ec = local_a8;
      uStack_f0 = 0x4ae5f0;
      FUN_004afd00();
      pvVar6 = local_ac;
    }
    else {
      puStack_e8 = local_b0;
      ppuStack_ec = &local_c4;
      uStack_f0 = 1;
      ppuStack_f4 = local_a8;
      FUN_00567420();
      local_a8 = local_a8 + 2;
    }
    ppuVar3 = local_a8;
    local_c4 = *(undefined1 **)(*(int *)(param_2 + 4) + 0x28);
    local_c0 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x30);
    if ((pvVar6 == (void *)0x0) ||
       ((uint)(local_a4 - (int)pvVar6 >> 3) <= (uint)((int)local_a8 - (int)pvVar6 >> 3))) {
      puStack_e8 = (undefined1 *)0x1;
      ppuStack_ec = local_a8;
      uStack_f0 = 0x4ae666;
      FUN_004afd00();
    }
    else {
      puStack_e8 = local_b0;
      ppuStack_ec = &local_c4;
      uStack_f0 = 1;
      ppuStack_f4 = local_a8;
      FUN_00567420();
      local_a8 = ppuVar3 + 2;
    }
    local_6c = local_bc;
    if ((int)local_bc <= (int)local_9c) {
      do {
        iVar5 = local_68;
        if ((int)local_98 <= (int)local_a0) {
          local_54 = (float)(int)local_6c;
          local_30 = (float)((int)local_6c + 1);
          local_b4 = local_98;
          do {
            local_b8 = *(float *)(iVar5 + 0x18) * local_30;
            local_64 = *(float *)(iVar5 + 0x18) * local_54;
            local_60 = (float)(int)local_b4 * *(float *)(iVar5 + 0x18);
            local_b4 = (float)((int)local_b4 + 1);
            local_bc = (float)(int)local_b4 * *(float *)(iVar5 + 0x18);
            if (((ppuVar9 != (undefined1 **)0x0) &&
                (local_c4 = (undefined1 *)((int)ppuVar7 - (int)ppuVar9 >> 3),
                local_c4 != (undefined1 *)0x0)) && (ppuVar9 != ppuVar7)) {
              ppuVar7 = ppuVar9;
              local_cc = ppuVar9;
            }
            if (((local_90 != (void *)0x0) &&
                (local_c4 = (undefined1 *)((int)local_8c - (int)local_90 >> 3),
                local_c4 != (undefined1 *)0x0)) && (local_90 != local_8c)) {
              local_8c = local_90;
            }
            local_40 = local_64;
            local_3c = local_60;
            if ((ppuVar9 == (undefined1 **)0x0) ||
               ((uint)(local_c8 - (int)ppuVar9 >> 3) <= (uint)((int)ppuVar7 - (int)ppuVar9 >> 3))) {
              puStack_e8 = (undefined1 *)0x1;
              uStack_f0 = 0x4ae79f;
              ppuStack_ec = ppuVar7;
              FUN_004afd00();
              ppuVar9 = local_d0;
            }
            else {
              puStack_e8 = local_d4;
              ppuStack_ec = (undefined1 **)&local_40;
              uStack_f0 = 1;
              ppuStack_f4 = ppuVar7;
              FUN_00567420();
              local_cc = ppuVar7 + 2;
            }
            ppuVar7 = local_cc;
            local_5c = local_64;
            local_58 = local_bc;
            if ((ppuVar9 == (undefined1 **)0x0) ||
               ((uint)(local_c8 - (int)ppuVar9 >> 3) <= (uint)((int)local_cc - (int)ppuVar9 >> 3)))
            {
              puStack_e8 = (undefined1 *)0x1;
              uStack_f0 = 0x4ae817;
              ppuStack_ec = local_cc;
              FUN_004afd00();
              ppuVar9 = local_d0;
            }
            else {
              puStack_e8 = local_d4;
              ppuStack_ec = (undefined1 **)&local_5c;
              uStack_f0 = 1;
              ppuStack_f4 = local_cc;
              FUN_00567420();
              local_cc = ppuVar7 + 2;
            }
            ppuVar7 = local_cc;
            local_48 = local_b8;
            local_44 = local_60;
            if ((ppuVar9 == (undefined1 **)0x0) ||
               ((uint)(local_c8 - (int)ppuVar9 >> 3) <= (uint)((int)local_cc - (int)ppuVar9 >> 3)))
            {
              puStack_e8 = (undefined1 *)0x1;
              uStack_f0 = 0x4ae892;
              ppuStack_ec = local_cc;
              FUN_004afd00();
              ppuVar9 = local_d0;
            }
            else {
              puStack_e8 = local_d4;
              ppuStack_ec = (undefined1 **)&local_48;
              uStack_f0 = 1;
              ppuStack_f4 = local_cc;
              FUN_00567420();
              local_cc = ppuVar7 + 2;
            }
            ppuVar7 = local_cc;
            puStack_e8 = local_d4;
            ppuStack_ec = (undefined1 **)local_b0;
            uStack_f0 = 0x4ae8b0;
            FUN_004adc60();
            puStack_e8 = local_94;
            ppuStack_ec = (undefined1 **)0x4ae8c1;
            FUN_004ae050();
            if (((ppuVar9 != (undefined1 **)0x0) &&
                (local_c4 = (undefined1 *)((int)ppuVar7 - (int)ppuVar9 >> 3),
                local_c4 != (undefined1 *)0x0)) && (ppuVar9 != ppuVar7)) {
              ppuVar7 = ppuVar9;
              local_cc = ppuVar9;
            }
            if (((local_90 != (void *)0x0) &&
                (local_c4 = (undefined1 *)((int)local_8c - (int)local_90 >> 3),
                local_c4 != (undefined1 *)0x0)) && (local_90 != local_8c)) {
              local_8c = local_90;
            }
            local_38 = local_b8;
            local_34 = local_bc;
            if ((ppuVar9 == (undefined1 **)0x0) ||
               ((uint)(local_c8 - (int)ppuVar9 >> 3) <= (uint)((int)ppuVar7 - (int)ppuVar9 >> 3))) {
              puStack_e8 = (undefined1 *)0x1;
              uStack_f0 = 0x4ae96d;
              ppuStack_ec = ppuVar7;
              FUN_004afd00();
              ppuVar9 = local_d0;
            }
            else {
              puStack_e8 = local_d4;
              ppuStack_ec = (undefined1 **)&local_38;
              uStack_f0 = 1;
              ppuStack_f4 = ppuVar7;
              FUN_00567420();
              local_cc = ppuVar7 + 2;
            }
            ppuVar7 = local_cc;
            local_50 = local_64;
            local_4c = local_bc;
            if ((ppuVar9 == (undefined1 **)0x0) ||
               ((uint)(local_c8 - (int)ppuVar9 >> 3) <= (uint)((int)local_cc - (int)ppuVar9 >> 3)))
            {
              puStack_e8 = (undefined1 *)0x1;
              uStack_f0 = 0x4ae9e5;
              ppuStack_ec = local_cc;
              FUN_004afd00();
              ppuVar9 = local_d0;
            }
            else {
              puStack_e8 = local_d4;
              ppuStack_ec = (undefined1 **)&local_50;
              uStack_f0 = 1;
              ppuStack_f4 = local_cc;
              FUN_00567420();
              local_cc = ppuVar7 + 2;
            }
            ppuVar7 = local_cc;
            local_84 = local_b8;
            local_80 = local_60;
            if ((ppuVar9 == (undefined1 **)0x0) ||
               ((uint)(local_c8 - (int)ppuVar9 >> 3) <= (uint)((int)local_cc - (int)ppuVar9 >> 3)))
            {
              puStack_e8 = (undefined1 *)0x1;
              uStack_f0 = 0x4aea54;
              ppuStack_ec = local_cc;
              FUN_004afd00();
              ppuVar9 = local_d0;
            }
            else {
              puStack_e8 = local_d4;
              ppuStack_ec = (undefined1 **)&local_84;
              uStack_f0 = 1;
              ppuStack_f4 = local_cc;
              FUN_00567420();
              local_cc = ppuVar7 + 2;
            }
            ppuVar7 = local_cc;
            puStack_e8 = local_d4;
            ppuStack_ec = (undefined1 **)local_b0;
            uStack_f0 = 0x4aea72;
            FUN_004adc60();
            puStack_e8 = local_94;
            ppuStack_ec = (undefined1 **)0x4aea83;
            FUN_004ae050();
          } while ((int)local_b4 <= (int)local_a0);
        }
        local_6c = (float)((int)local_6c + 1);
      } while ((int)local_6c <= (int)local_9c);
    }
    puStack_e8 = (undefined1 *)0x4aeab4;
    FUN_004ab3d0();
    local_c4 = (undefined1 *)&ppuStack_f4;
    FUN_004b08b0(0);
    puStack_e8 = (undefined1 *)0x4aeae4;
    FUN_004b0330();
    puVar8 = local_78;
    if (local_78 != local_74) {
      do {
        local_2c = *puVar8;
        local_24 = puVar8[1];
        local_28 = 0;
        puStack_e8 = (undefined1 *)0x4aeb26;
        FUN_004b0b40();
        puVar8 = puVar8 + 2;
      } while (puVar8 != local_74);
    }
    pfVar4 = *(float **)(param_3 + 4);
    if (pfVar4 != *(float **)(param_3 + 8)) {
      do {
        pfVar1 = *(float **)(param_2 + 4);
        local_b4 = pfVar1[2] - pfVar4[2];
        fVar12 = g_flOne / ((pfVar1[0xc] - pfVar1[2]) * (pfVar1[5] - *pfVar1) -
                           (pfVar1[7] - pfVar1[2]) * (pfVar1[10] - *pfVar1));
        fVar10 = ((*pfVar1 - *pfVar4) * (pfVar1[7] - pfVar4[2]) - (pfVar1[5] - *pfVar4) * local_b4)
                 * fVar12;
        fVar11 = ((pfVar1[5] - *pfVar4) * (pfVar1[0xc] - pfVar4[2]) -
                 (pfVar1[10] - *pfVar4) * (pfVar1[7] - pfVar4[2])) * fVar12;
        fVar12 = ((pfVar1[10] - *pfVar4) * local_b4 -
                 (*pfVar1 - *pfVar4) * (pfVar1[0xc] - pfVar4[2])) * fVar12;
        pfVar4[3] = pfVar1[0xd] * fVar10 + pfVar1[8] * fVar12 + pfVar1[3] * fVar11;
        iVar5 = *(int *)(param_2 + 4);
        pfVar4[4] = *(float *)(iVar5 + 0x38) * fVar10 + *(float *)(iVar5 + 0x24) * fVar12 +
                    *(float *)(iVar5 + 0x10) * fVar11;
        pfVar4 = pfVar4 + 5;
      } while (pfVar4 != *(float **)(param_3 + 8));
    }
    if (ppuVar9 != (undefined1 **)0x0) {
                    /* WARNING: Subroutine does not return */
      puStack_e8 = &UNK_004aec63;
      operator_delete(ppuVar9);
    }
    if (local_78 != (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      puStack_e8 = &UNK_004aec74;
      operator_delete(local_78);
    }
    if (local_90 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      puStack_e8 = &UNK_004aec85;
      operator_delete(local_90);
    }
    if (local_ac != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      puStack_e8 = &UNK_004aec96;
      operator_delete(local_ac);
    }
  }
  ExceptionList = local_14;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
