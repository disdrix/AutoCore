// =============================================================================
// FUN_00749fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00749fd0
// Address:   0x00749fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00749fd0 @ 0x00749fd0
// Stable ID: aa_00749fd0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp"
//   - "Unimplemented code reached"
//   - "TransformInPlace() unable to lock source VB!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~149 non-empty decompiler lines.
//  - Control keywords: if×18, return×3, do×1, while×1.
//  - Notable callees: FUN_007468e0×5, FUN_00435d60×4, FUN_00414a50×2, vog_LogMessage×2, FUN_0044bc70, FUN_00749fd0, FUN_0076f6e0, TransformInPlace.
//  - Strings: ",0x2ea,3,

                   "; ",0x2fd,3,

                 ".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_00749fd0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *local_74;

  uint32_t /* width from decompiler */ *local_70;

  uint32_t /* width from decompiler */ *local_6c;

  int local_64;

  int local_60;

  int local_5c;

  int local_58;

  int local_54;

  int local_50;

  int local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30 [12];

  uint8_t local_24 [12];

  uint8_t local_18 [12];

  uint8_t local_c [12];

  

  local_4c = param_1;

  if (((*(uint *)(param_1 + 0xbc) >> 1 & 1) != 0) || ((*(uint *)(param_1 + 0xbc) >> 2 & 1) != 0)) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp",0x2ea,3,

                   "Unimplemented code reached");

    return;

  }

  iVar3 = FUN_007468e0(0,0);

  local_5c = FUN_007468e0(3,0);

  local_58 = FUN_007468e0(6,0);

  local_54 = FUN_007468e0(6,1);

  local_50 = FUN_007468e0(7,0);

  FUN_0044bc70(0);

  if (*(int *)(param_1 + 0x14) == 0) {

    local_64 = 0;

  }

  else {

    local_64 = *(int *)(*(int *)(param_1 + 0x14) + 0x18);

  }

  if ((*(int *)(param_1 + 0x14) == 0) ||

     (iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 0x10), iVar5 == 0)) {

    uVar4 = 0;

  }

  else {

    uVar4 = *(uint *)(iVar5 + 8);

  }

  uVar4 = uVar4 >> 2;

  iVar5 = *(int *)(param_1 + 0x14);

  piVar1 = *(int **)(iVar5 + 0x10);

  if (piVar1 != (int *)0x0) {

    piVar2 = (int *)*piVar1;

    if (piVar2 == (int *)0x0) {

      local_60 = 0;

    }

    else {

      iVar5 = (**(code **)(*piVar2 + 0x2c))

                        (piVar2,piVar1[2] * *(int *)(iVar5 + 0x14),

                         piVar1[2] * *(int *)(iVar5 + 0x18),&local_60,0x800);

      if (iVar5 < 0) {

        local_60 = 0;

      }

      else {

        piVar1[4] = piVar1[4] + 1;

      }

    }

    puVar7 = (uint32_t /* width from decompiler */ *)0x0;

    if (local_60 != 0) {

      local_6c = (uint32_t /* width from decompiler */ *)0x0;

      if (iVar3 != 0) {

        local_6c = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar3 + 2) + local_60);

      }

      local_74 = (uint32_t /* width from decompiler */ *)0x0;

      if (local_5c != 0) {

        local_74 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(local_5c + 2) + local_60);

      }

      local_70 = (uint32_t /* width from decompiler */ *)0x0;

      if (local_58 != 0) {

        local_70 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(local_58 + 2) + local_60);

      }

      if (local_54 != 0) {

        puVar7 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(local_54 + 2) + local_60);

      }

      puVar8 = (uint32_t /* width from decompiler */ *)0x0;

      if (local_50 != 0) {

        puVar8 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(local_50 + 2) + local_60);

      }

      if (0 < local_64) {

        do {

          if (local_6c != (uint32_t /* width from decompiler */ *)0x0) {

            FUN_0076f6e0();

            local_48 = local_3c;

            *local_6c = local_3c;

            local_44 = local_38;

            local_6c[1] = local_38;

            local_40 = local_34;

            local_6c[2] = local_34;

            local_6c = local_6c + uVar4;

          }

          if (local_74 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar6 = (uint32_t /* width from decompiler */ *)FUN_00435d60(local_30);

            *local_74 = *puVar6;

            local_74[1] = puVar6[1];

            local_74[2] = puVar6[2];

            local_74 = local_74 + uVar4;

          }

          if (local_70 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar6 = (uint32_t /* width from decompiler */ *)FUN_00435d60(local_24);

            *local_70 = *puVar6;

            local_70[1] = puVar6[1];

            local_70[2] = puVar6[2];

            local_70 = local_70 + uVar4;

          }

          if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar6 = (uint32_t /* width from decompiler */ *)FUN_00435d60(local_18);

            *puVar7 = *puVar6;

            puVar7[1] = puVar6[1];

            puVar7[2] = puVar6[2];

            puVar7 = puVar7 + uVar4;

          }

          if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar6 = (uint32_t /* width from decompiler */ *)FUN_00435d60(local_c);

            *puVar8 = *puVar6;

            puVar8[1] = puVar6[1];

            puVar8[2] = puVar6[2];

            puVar8 = puVar8 + uVar4;

          }

          local_64 = local_64 + -1;

        } while (local_64 != 0);

      }

      iVar3 = local_4c;

      FUN_00414a50();

      *(uint *)(iVar3 + 0xbc) = *(uint *)(iVar3 + 0xbc) | 1;

      return;

    }

  }

  FUN_00414a50();

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp",0x2fd,3,

                 "TransformInPlace() unable to lock source VB!");

  return;

}
