// READABILITY (auto CF):
//  - Body size: ~256 non-empty decompiler lines.
//  - Control keywords: if×26, return×7, do×3, while×3, for×1.
//  - Notable callees: FUN_004073a0×2, CONCAT31, ExitProcess, FUN_0044b610, FUN_0044b9c0, FUN_00457ac0, FUN_0046bf90, FUN_0046c1b0.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp"; ");

          if (iVar9 == 3) {

            _File = fopen("; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n".
//  - Return sites: 7.

// =============================================================================
// Named_gfxDeviceIB_0098fef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098fef0
// Address:   0x0098fef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceIB"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxDeviceIB_0098fef0(int param_1,int *param_2)



{

  int *piVar1;

  ushort *puVar2;

  uint uVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  FILE *_File;

  uint uVar7;

  uint *puVar8;

  int iVar9;

  void *pvVar10;

  uint unaff_ESI;

  int *piVar11;

  ushort *local_8c;

  ushort *local_88;

  ushort *local_84;

  int *local_80;

  int *local_7c;

  uint local_78;

  int local_74;

  uint local_70;

  uint local_6c;

  uint local_68 [2];

  uint8_t local_60 [4];

  void *local_5c;

  uint *local_58;

  int local_54;

  uint local_50 [4];

  uint8_t local_40 [8];

  int *local_38;

  uint32_t /* width from decompiler */ local_34;

  void *local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b1f0e;

  local_14 = ExceptionList;

  if ((param_2 == (int *)0x0) ||

     (((iVar9 = param_2[0x2b], iVar9 != 4 && (iVar9 != 5)) && (iVar9 != 6)))) {

    return 0;

  }

  ExceptionList = &local_14;

  FUN_00457ac0(local_40);

  local_c = 0;

  FUN_0044b610();

  iVar9 = param_2[3];

  if (*(int *)(iVar9 + 0x10) == 0) {

    local_8c = (ushort *)0x0;

  }

  else {

    local_8c = (ushort *)

               FUN_00743be0(*(uint32_t /* width from decompiler */ *)(iVar9 + 0x18),*(uint32_t /* width from decompiler */ *)(iVar9 + 0x1c),0x810);

  }

  local_78 = 0;

  if (0 < param_2[0x2a]) {

    local_74 = (int)local_7c * 2;

    local_6c = (int)local_80 * 2;

    local_70 = (int)local_84 * 2;

    local_84 = local_8c + 2;

    local_88 = local_8c + 1;

    do {

      local_50[1] = (uint)*local_88;

      local_50[0] = (uint)*local_8c;

      local_50[2] = (uint)*local_84;

      local_50[3] = (uint)*local_8c;

      iVar9 = 0;

      do {

        uVar7 = local_50[iVar9 + 1];

        uVar3 = local_50[iVar9];

        if ((int)uVar3 < (int)uVar7) {

          uVar7 = uVar3 << 0x10 | uVar7;

        }

        else {

          uVar7 = uVar7 << 0x10 | uVar3;

        }

        local_80 = (int *)uVar7;

        FUN_0046c1b0();

        if (local_7c == local_38) {

          local_68[1] = 0;

          local_68[0] = uVar7;

          puVar5 = (uint32_t /* width from decompiler */ *)FUN_0046bf90(local_60,local_68);

          local_7c = (int *)*puVar5;

        }

        local_7c[3] = local_7c[3] + 1;

        iVar9 = iVar9 + 1;

      } while (iVar9 < 3);

      local_88 = (ushort *)((int)local_88 + local_70);

      local_8c = (ushort *)((int)local_8c + local_74);

      local_84 = (ushort *)((int)local_84 + local_6c);

      local_78 = local_78 + 1;

    } while ((int)local_78 < param_2[0x2a]);

  }

  piVar11 = *(int **)(param_2[3] + 0x10);

  pvVar10 = (void *)0x0;

  if ((piVar11 != (int *)0x0) && (piVar4 = (int *)*piVar11, piVar4 != (int *)0x0)) {

    piVar1 = piVar11 + 3;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,

                     "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

      piVar11[3] = 0;

    }

    else {

      (**(code **)(*piVar4 + 0x30))(piVar4);

    }

  }

  puVar8 = (uint *)0x0;

  local_5c = (void *)0x0;

  local_58 = (uint *)0x0;

  local_54 = 0;

  local_c = CONCAT31(local_c._1_3_,1);

  piVar11 = (int *)*local_38;

  if (piVar11 != local_38) {

    do {

      if (piVar11[3] != 2) {

        local_6c = (uint)piVar11[2] >> 0x10;

        local_78 = piVar11[2] & 0xffff;

        if ((pvVar10 == (void *)0x0) ||

           ((uint)(local_54 - (int)pvVar10 >> 2) <= (uint)((int)puVar8 - (int)pvVar10 >> 2))) {

          FUN_004073a0(puVar8,1,&local_6c);

          pvVar10 = local_5c;

        }

        else {

          *puVar8 = local_6c;

          local_58 = puVar8 + 1;

        }

        if ((pvVar10 == (void *)0x0) ||

           ((uint)(local_54 - (int)pvVar10 >> 2) <= (uint)((int)local_58 - (int)pvVar10 >> 2))) {

          FUN_004073a0(local_58,1,&local_78);

          puVar8 = local_58;

          pvVar10 = local_5c;

        }

        else {

          *local_58 = local_78;

          local_58 = local_58 + 1;

          puVar8 = local_58;

        }

      }

      piVar11 = (int *)*piVar11;

    } while (piVar11 != local_38);

    if (pvVar10 != (void *)0x0) {

      local_7c = (int *)((int)puVar8 - (int)pvVar10 >> 2);

      if (local_7c == (int *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar10);

      }

      puVar8 = (uint *)(**(code **)(*param_2 + 0x7c))();

      local_6c = *puVar8;

      uVar6 = (**(code **)(*param_2 + 0x28))();

      (**(code **)(local_6c + 0x24))(uVar6);

      if (((param_2[0x16] != 0) && (param_2[0x17] != 0)) &&

         (*(int *)(param_2[0x17] + 0x1c) != param_2[0x18])) {

        (**(code **)(*param_2 + 0x80))();

      }

      puVar8[0x19] = param_2[0x19];

      local_70 = *puVar8;

      uVar6 = (**(code **)(*param_2 + 0x2c))();

      (**(code **)(local_70 + 0x34))(uVar6);

      local_80 = *(int **)(param_1 + 0x28);

      if ((local_80 != (int *)0x0) && (local_80[1] = local_80[1] + 1, local_80[1] == 1)) {

        (**(code **)(*local_80 + 4))();

      }

      piVar11 = (int *)puVar8[8];

      if (piVar11 != (int *)0x0) {

        piVar4 = piVar11 + 1;

        *piVar4 = *piVar4 + -1;

        if (*piVar4 == 0) {

          (**(code **)(*piVar11 + 8))();

        }

      }

      puVar8[8] = (uint)local_80;

      *(uint8_t *)(puVar8 + 9) = *(uint8_t *)(param_1 + 0x2c);

      *(uint8_t *)((int)puVar8 + 0x25) = *(uint8_t *)(param_1 + 0x2d);

      *(uint8_t *)((int)puVar8 + 0x26) = *(uint8_t *)(param_1 + 0x2e);

      (**(code **)(*puVar8 + 0x74))();

      puVar8[0x2b] = 2;

      puVar8[0x2f] = puVar8[0x2f] | 0x20;

      puVar8[0x2a] = (int)local_84 / 2;

      FUN_0044b9c0(local_84,0x20,0,0);

      uVar7 = puVar8[3];

      piVar11 = *(int **)(uVar7 + 0x10);

      if (piVar11 == (int *)0x0) {

        local_84 = (ushort *)0x0;

      }

      else {

        local_84 = (ushort *)0x0;

        if ((int *)*piVar11 != (int *)0x0) {

          local_84 = *(ushort **)(uVar7 + 0x18);

          iVar9 = (**(code **)(*(int *)*piVar11 + 0x2c))

                            (*piVar11,(int)*(ushort **)(uVar7 + 0x18) * piVar11[4],

                             *(int *)(uVar7 + 0x1c) * piVar11[4],&local_84,0x800);

          if (iVar9 < 0) {

            local_84 = (ushort *)0x0;

          }

          else {

            piVar11[3] = piVar11[3] + 1;

          }

        }

      }

      for (uVar7 = 0; uVar7 < unaff_ESI; uVar7 = uVar7 + 1) {

        *local_84 = *(ushort *)((int)pvVar10 + uVar7 * 4);

        local_84 = local_84 + 1;

      }

      local_84 = *(ushort **)(puVar8[3] + 0x10);

      if ((local_84 != (ushort *)0x0) && (piVar11 = *(int **)local_84, piVar11 != (int *)0x0)) {

        puVar2 = local_84 + 6;

        *(int *)puVar2 = *(int *)puVar2 + -1;

        if (*(int *)puVar2 < 0) {

          iVar9 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca

                               ,"Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

          if (iVar9 == 3) {

            _File = fopen("c:\\VOGCRASH.txt","w");

            if (_File != (FILE *)0x0) {

              fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                      "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,

                      "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

              fclose(_File);

            }

            raise(0x16);

                    /* WARNING: Subroutine does not return */

            ExitProcess(3);

          }

          local_84[6] = 0;

          local_84[7] = 0;

        }

        else {

          (**(code **)(*piVar11 + 0x30))(piVar11);

        }

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar10);

    }

  }

  if (local_2c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_2c);

  }

  local_2c = (void *)0x0;

  local_28 = 0;

  local_24 = 0;

  piVar11 = (int *)*local_38;

  *local_38 = (int)local_38;

  local_38[1] = (int)local_38;

  local_34 = 0;

  if (piVar11 == local_38) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_38);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar11);

}
