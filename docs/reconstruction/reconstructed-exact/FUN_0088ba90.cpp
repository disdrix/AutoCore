// =============================================================================
// FUN_0088ba90
// -----------------------------------------------------------------------------
// Stable ID: aa_0088ba90
// Address:   0x0088ba90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088ba90 @ 0x0088ba90
// Stable ID: aa_0088ba90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×12, return×8, switch×2, do×2, while×2, goto×1.
//  - Notable callees: Client_SendSectorPacket×3, FUN_00404ad0×2, FUN_004c3f10×2, FUN_0088a7a0×2, FUN_0095c5a0×2, TFID_EqualsObjectId×2, FUN_007fbcf0, FUN_007fbd10.
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ __thiscall FUN_0088ba90(int param_1,int param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint uVar6;

  int local_30 [4];

  uint32_t /* width from decompiler */ auStack_20 [2];

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t uStack_10;

  uint uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  local_30[0] = param_1;

  if ((0x9c47 < param_3) && (param_3 < 0xa030)) {

    if ((*(int *)(param_1 + 0x530) != 0) &&

       (param_3 - 0x9c48U < (uint)((*(int *)(param_1 + 0x534) - *(int *)(param_1 + 0x530)) / 0x18)))

    {

      iVar4 = (param_3 - 0x9c48U) * 0x18;

      iVar1 = *(int *)(param_1 + 0x530) + iVar4;

      if (*(int *)(iVar1 + 0x14) != 0) {

        switch(param_2) {

        case 5:

          if (*(int *)(iVar1 + 0xc) != 0) {

            uVar5 = 1;

            (**(code **)(**(int **)(iVar1 + 0xc) + 0x120))(local_30,1,1);

            puVar2 = (uint32_t /* width from decompiler */ *)

                     (**(code **)(**(int **)(iVar4 + *(int *)(param_1 + 0x530) + 0xc) + 0x140))

                               (&stack0xffffffcc,1);

            FUN_007fd3d0(uVar5,unaff_EDI,*puVar2,puVar2[1]);

          }

          return 1;

        case 6:

          FUN_007fc970();

          return 1;

        case 8:

          FUN_0093e120(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x14));

          return 1;

        case 0xe:

          auStack_20[0] = 0x20a4;

          uStack_10 = 0;

          uStack_8 = 0;

          uStack_4 = 0;

          uStack_18 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x14) + 0x160);

          uStack_14 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x14) + 0x164);

          Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

          return 1;

        }

        goto LAB_0088bc0f;

      }

    }

    return 0;

  }

LAB_0088bc0f:

  uVar3 = param_3 - 0x9c42;

  switch(uVar3) {

  case 0:

  case 1:

  case 2:

    if (param_2 == 8) {

      if (((DAT_00d1b6d8 != 0) && (uVar3 != DAT_00d1b251)) &&

         (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) {

        DAT_00d1b251 = (byte)uVar3;

        FUN_0095c5a0();

        uVar3 = FUN_004c3f10(1);

        uVar6 = 0;

        if (uVar3 != 0) {

          do {

            puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404ad0(uVar6);

            iVar4 = TFID_EqualsObjectId(puVar2,&DAT_00a1e3d8);

            if ((char)iVar4 == '\0') {

              auStack_20[0] = 0x20a4;

              uStack_10 = 2;

              uStack_8 = FUN_007fbd10();

              uStack_8 = uStack_8 & 0xff;

              uStack_14 = puVar2[1];

              uStack_4 = 0;

              uStack_18 = *puVar2;

              Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

            }

            uVar6 = uVar6 + 1;

          } while (uVar6 < uVar3);

        }

      }

      FUN_0088a7a0();

      return 1;

    }

    break;

  case 3:

  case 4:

  case 5:

    if (param_2 == 8) {

      if (((DAT_00d1b6d8 != 0) && (param_3 - 0x9c45U != (uint)DAT_00d1b252)) &&

         (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) {

        DAT_00d1b252 = (byte)(param_3 - 0x9c45U);

        FUN_0095c5a0();

        uVar3 = FUN_004c3f10(1);

        uVar6 = 0;

        if (uVar3 != 0) {

          do {

            puVar2 = (uint32_t /* width from decompiler */ *)FUN_00404ad0(uVar6);

            iVar4 = TFID_EqualsObjectId(puVar2,&DAT_00a1e3d8);

            if ((char)iVar4 == '\0') {

              auStack_20[0] = 0x20a4;

              uStack_10 = 1;

              uStack_8 = FUN_007fbcf0();

              uStack_8 = uStack_8 & 0xffff;

              uStack_14 = puVar2[1];

              uStack_4 = 0;

              uStack_18 = *puVar2;

              Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

            }

            uVar6 = uVar6 + 1;

          } while (uVar6 < uVar3);

        }

      }

      FUN_0088a7a0();

      return 1;

    }

  }

  uVar5 = FUN_0087b500(param_2,param_3);

  return uVar5;

}
