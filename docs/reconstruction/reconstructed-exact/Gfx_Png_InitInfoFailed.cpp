// =============================================================================
// Gfx_Png_InitInfoFailed
// -----------------------------------------------------------------------------
// Stable ID: aa_00435410
// Address:   0x00435410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_Png_InitInfoFailed for FUN_00435410 @ 0x00435410
// Stable ID: aa_00435410
// Embedded strings (evidence for future rename):
//   - "1.2.8"
//   - "Failed to create PNG structure"
//   - "Failed to initialize PNG info structure"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~268 non-empty decompiler lines.
//  - Control keywords: if×32, return×7, while×5, goto×2, do×2, for×1.
//  - Notable callees: FUN_00433440×4, _CxxThrowException×3, FUN_004330c0×2, FUN_00475780×2, FUN_00475ff0×2, FUN_004770d0×2, ROUND×2, floor×2.
//  - Strings: "1.2.8"; "Failed to create PNG structure"; "Failed to initialize PNG info structure".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Failed to initialize PNG info structure"
 * Domain alias of FUN_00435410 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Gfx_Png_InitInfoFailed(int param_1)



{

  uint8_t *puVar1;

  char cVar2;

  uint8_t uVar3;

  int *piVar4;

  int iVar5;

  void *pvVar6;

  uint uVar7;

  int extraout_EDX;

  int extraout_EDX_00;

  int *piVar8;

  bool bVar9;

  ushort in_FPUControlWord;

  double dVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint8_t *local_78;

  char *local_74;

  int local_70;

  uint local_6c;

  int local_68;

  char *local_64;

  uint local_60;

  int local_5c;

  int local_58;

  uint8_t local_54;

  uint16_t local_52;

  uint16_t local_50;

  uint16_t local_4e;

  uint16_t local_4c;

  int local_48;

  uint local_44;

  uint local_40;

  int local_3c;

  int local_38;

  void *local_34;

  int local_30;

  int local_2c;

  int local_28;

  int local_20;

  int *local_1c;

  int *local_18;

  uint8_t *local_14;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009be190;

  pvStack_10 = ExceptionList;

  local_14 = &stack0xffffff30;

  local_34 = (void *)0x0;

  local_8 = 0;

  ExceptionList = &pvStack_10;

  piVar4 = (int *)FUN_00475070("1.2.8",0,0,0,0,0);

  local_18 = piVar4;

  if (piVar4 == (int *)0x0) {

    local_74 = "Failed to create PNG structure";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_74,(ThrowInfo *)&DAT_00acc49c);

  }

  local_1c = (int *)FUN_00476670();

  if (local_1c == (int *)0x0) {

    FUN_00475ff0(&local_18,0);

    local_64 = "Failed to initialize PNG info structure";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_64,(ThrowInfo *)&DAT_00acc49c);

  }

  iVar5 = setjmp3(piVar4,3,&DAT_009a0456,local_8);

  piVar4 = local_18;

  if (iVar5 != 0) {

    if (local_34 == (void *)0x0) {

      FUN_00475ff0(&local_18,&local_1c);

      local_78 = &DAT_00a1419b;

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_78,(ThrowInfo *)&DAT_00acc49c);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(local_34);

  }

  FUN_00477140();

  piVar8 = local_1c;

  piVar4[0x12] = param_1 + 0x44;

  piVar4[0x10] = (int)&LAB_004352e0;

  piVar4[0x11] = 0;

  FUN_004752f0();

  local_54 = 0;

  local_52 = 0xc0;

  local_50 = 0xc0;

  local_4e = 0xc0;

  local_4c = 0;

  if (*(char *)((int)piVar8 + 0x1e) == ' ') {

LAB_004355cc:

    iVar5 = FUN_004770d0();

    if (iVar5 != 0) {

      *(uint8_t *)(param_1 + 0x152) = *(uint8_t *)(local_2c + 2);

      *(uint8_t *)(param_1 + 0x151) = *(uint8_t *)(local_2c + 4);

      *(uint8_t *)(param_1 + 0x150) = *(uint8_t *)(local_2c + 6);

      *(uint8_t *)(param_1 + 0x153) = 0;

    }

  }

  else {

    iVar5 = FUN_004770d0();

    if (iVar5 == 0) {

      uVar11 = 1;

    }

    else {

      uVar11 = 2;

    }

    FUN_00470d40(uVar11,_DAT_00aaa5f8);

    piVar4 = local_18;

    if (*(char *)((int)piVar8 + 0x1e) == ' ') goto LAB_004355cc;

  }

  if ((char)piVar8[6] == '\x10') {

    *(byte *)((int)piVar4 + 0x71) = *(byte *)((int)piVar4 + 0x71) | 4;

  }

  local_44 = (uint)*(byte *)((int)piVar8 + 0x1e);

  bVar9 = local_44 == 0x10;

  if (0x10 < local_44) {

    local_44 = 0x18;

  }

  if (bVar9) {

    local_44 = 8;

  }

  FUN_004323e0(*piVar8,local_44,2);

  if ((char)piVar8[0x1e] == '\0') {

    FUN_004330c0();

  }

  else {

    if ((char)piVar8[0x1e] != '\x01') goto LAB_00435709;

    dVar10 = (double)piVar8[0x1c];

    if (piVar8[0x1c] < 0) {

      dVar10 = dVar10 + _DAT_00aaa728;

    }

    dVar10 = floor(dVar10 * _DAT_00aaa970 + _DAT_00aaa5e0);

    local_60 = (uint)(in_FPUControlWord | 0xc00);

    local_58 = (int)ROUND(dVar10);

    FUN_004330c0();

    dVar10 = (double)local_1c[0x1d];

    if (local_1c[0x1d] < 0) {

      dVar10 = dVar10 + _DAT_00aaa728;

    }

    dVar10 = floor(dVar10 * _DAT_00aaa970 + _DAT_00aaa5e0);

    local_6c = (uint)(in_FPUControlWord | 0xc00);

    local_5c = (int)ROUND(dVar10);

  }

  FUN_00433120();

  piVar8 = local_1c;

LAB_00435709:

  if ((short)piVar8[5] == 0) {

    if ((char)piVar8[6] == '\x02') {

      FUN_00433440(0,0,0,0);

      FUN_00433440(0x55,0x55,0x55,0);

      FUN_00433440(0xaa,0xaa,0xaa,0);

      FUN_00433440(0xff,0xff,0xff,0);

      piVar8 = local_1c;

    }

    else {

      FUN_00433a00();

      piVar8 = local_1c;

    }

  }

  else {

    FUN_004339b0();

  }

  if ((*(short *)((int)piVar8 + 0x16) != 0) && (iVar5 = FUN_00433490(), iVar5 != 0)) {

    local_40 = 0;

    while( true ) {

      uVar7 = (uint)*(ushort *)((int)piVar8 + 0x16);

      if (*(uint *)(param_1 + 0x28) < (uint)*(ushort *)((int)piVar8 + 0x16)) {

        uVar7 = *(uint *)(param_1 + 0x28);

      }

      if (uVar7 <= local_40) break;

      *(uint8_t *)(iVar5 + 3 + local_40 * 4) = *(uint8_t *)(local_40 + piVar8[0x13]);

      local_40 = local_40 + 1;

    }

    if ((*(short *)((int)piVar8 + 0x16) == 1) && (*(char *)(iVar5 + 3) == '\0')) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c) = 0;

    }

    else {

      *(uint8_t *)(param_1 + 0x17d) = 1;

      for (; local_40 < *(uint *)(param_1 + 0x28); local_40 = local_40 + 1) {

        *(uint8_t *)(iVar5 + 3 + local_40 * 4) = 0xff;

      }

    }

  }

  cVar2 = *(char *)((int)piVar8 + 0x19);

  if ((cVar2 == '\x06') || ((cVar2 == '\x04' && (*(char *)((int)piVar8 + 0x1e) == ' ')))) {

    if (cVar2 == '\x04') {

      *(byte *)((int)local_18 + 0x71) = *(byte *)((int)local_18 + 0x71) | 0x40;

      *(byte *)((int)local_18 + 0x71) = *(byte *)((int)local_18 + 0x71) | 0x10;

    }

    FUN_004771b0(0xff);

    FUN_00433180();

    piVar8 = local_1c;

  }

  if ((*(byte *)((int)piVar8 + 0x19) & 2) != 0) {

    local_18[0x1c] = local_18[0x1c] | 1;

  }

  if (*(int *)(param_1 + 0x148) == 0) {

    pvVar6 = operator_new(((int)(*(byte *)((int)piVar8 + 0x1e) + 7) >> 3) * *piVar8 + 10);

    local_34 = pvVar6;

    local_48 = FUN_00477190();

    if (local_48 < 2) {

      local_70 = *(int *)(param_1 + 0x40);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x188 + local_70 * 4) = 0;

    }

    else {

      local_68 = *(int *)(param_1 + 0x40);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x188 + local_68 * 4) = 1;

    }

    local_20 = 0;

    do {

      if (local_48 <= local_20) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar6);

      }

      FUN_00435240();

      local_28 = 0;

      do {

        if (*(int *)(param_1 + 0x148) != 0) {

                    /* WARNING: Subroutine does not return */

          longjmp(local_18,1);

        }

        if (*(int *)(param_1 + 0x1b0) == 0) {

          if (((char)piVar8[7] != '\0') && (0 < local_20)) {

            FUN_00435350();

          }

          FUN_00475780(local_18,pvVar6);

          if (((char)piVar8[6] == '\x02') && (local_20 == local_48 + -1)) {

            FUN_00435380();

          }

          FUN_00435310();

          FUN_00435290();

        }

        else {

          local_3c = (*(int *)(param_1 + 0x10) - local_28) + -1;

          local_38 = FUN_00433d70();

          if ((((char)local_1c[7] != '\0') && (0 < local_20)) && (local_20 != 7)) {

            local_30 = *(int *)(param_1 + 0xc);

            while (-1 < local_30) {

              puVar1 = (uint8_t *)(local_38 + local_30 * 3);

              *(uint8_t *)((int)pvVar6 + local_30 * 4) = *puVar1;

              *(uint8_t *)((int)pvVar6 + local_30 * 4 + 1) = puVar1[1];

              *(uint8_t *)((int)pvVar6 + local_30 * 4 + 2) = puVar1[2];

              uVar3 = FUN_004332b0();

              *(uint8_t *)((int)pvVar6 + extraout_EDX * 4 + 3) = uVar3;

              local_30 = extraout_EDX + -1;

            }

          }

          FUN_00475780(local_18,pvVar6);

          local_30 = 0;

          while (piVar8 = local_1c, local_30 < *(int *)(param_1 + 0xc)) {

            puVar1 = (uint8_t *)(local_38 + local_30 * 3);

            *puVar1 = *(uint8_t *)((int)pvVar6 + local_30 * 4);

            puVar1[1] = *(uint8_t *)((int)pvVar6 + local_30 * 4 + 1);

            puVar1[2] = *(uint8_t *)((int)pvVar6 + local_30 * 4 + 2);

            FUN_00433280();

            local_30 = extraout_EDX_00 + 1;

          }

        }

        local_28 = local_28 + 1;

      } while (local_28 < *(int *)(param_1 + 0x10));

      local_20 = local_20 + 1;

    } while( true );

  }

                    /* WARNING: Subroutine does not return */

  longjmp(local_18,1);

}
