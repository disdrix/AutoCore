// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_00921890
// -----------------------------------------------------------------------------
// Stable ID: aa_00921890
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x00921890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, while×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_00411900×2, Client_SendSectorPacket, FUN_00402c40, FUN_0040cf90, FUN_005469a0, FUN_00921890.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
 * Xref/callee-driven rename (parent seed scan)
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



uint32_t /* width from decompiler */ Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_00921890(void)



{

  ushort uVar1;

  char cVar2;

  float *pfVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  uint32_t /* width from decompiler */ auStack_40 [2];

  int iStack_38;

  int iStack_34;

  int iStack_30;

  float fStack_2c;

  int iStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  float fStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  if ((DAT_00d1b6d8 != 0) && (DAT_00d1b1f8 != (int *)0x0)) {

    pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a0))();

    fStack_50 = *pfVar3;

    fStack_4c = pfVar3[1];

    fStack_48 = pfVar3[2];

    fStack_44 = pfVar3[3];

    piVar4 = (int *)(**(code **)(*DAT_00d1b1f8 + 0x3ac))();

    if (piVar4 != (int *)0x0) {

      if ((*(int *)(DAT_00d1b6d8 + 0x6b4) < 1) && (*(int *)(piVar4[0x2a] + 0x38) == 4)) {

        uStack_60 = 0;

        FUN_00402c40();

        iVar5 = FUN_00411900(&uStack_60);

        while (iVar5 != 0) {

          cVar2 = FUN_005469a0(*(uint32_t /* width from decompiler */ *)(piVar4[0x2a] + 0x34));

          if (cVar2 != '\0') {

            *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;

            return 0;

          }

          iVar5 = FUN_00411900(&uStack_60);

        }

        *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;

      }

      iVar5 = (**(code **)(*piVar4 + 0x1cc))();

      iVar6 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar6 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

      fStack_50 = ((float)uVar1 * _DAT_00aaacac - DAT_00aaa688) + fStack_50;

      iVar6 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar6 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

      fStack_48 = ((float)uVar1 * _DAT_00aaacac - DAT_00aaa688) + fStack_48;

      if (*(int **)(iVar5 + 8) != (int *)0x0) {

        pfVar3 = &fStack_5c;

        fStack_5c = fStack_50;

        fStack_58 = fStack_4c;

        fStack_54 = fStack_48;

        (**(code **)(**(int **)(iVar5 + 8) + 0x10))(3,pfVar3);

        FUN_0040cf90(pfVar3);

      }

      piVar4[0x22] = (int)fStack_48;

      piVar4[0x23] = (int)fStack_44;

      piVar4[0x20] = (int)fStack_50;

      fStack_18 = g_flMsToSeconds_Inferred;

      uStack_1c = 0;

      uStack_20 = 0;

      uStack_24 = 0;

      piVar4[0x21] = (int)fStack_4c;

      iStack_38 = piVar4[0x58];

      iStack_34 = piVar4[0x59];

      iStack_30 = piVar4[0x20];

      fStack_2c = fStack_4c;

      iStack_28 = piVar4[0x22];

      auStack_40[0] = 0x2057;

      uStack_14 = (**(code **)(*piVar4 + 0x25c))();

      Client_SendSectorPacket(&DAT_00d1a840,0x30,auStack_40);

      return 1;

    }

  }

  return 0;

}
