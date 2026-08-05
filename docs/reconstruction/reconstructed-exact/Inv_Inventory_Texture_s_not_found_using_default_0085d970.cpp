// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: do×7, while×7, if×6, return×3, for×2.
//  - Notable callees: PathFileExistsA×2, FUN_007a4480, FUN_007b6420, FUN_007b66c0, FUN_007b6a20, FUN_0085d970.
//  - Strings: "Inventory Texture <%s> not found, using default...\n".
//  - Return sites: 3.

// =============================================================================
// Inv_Inventory_Texture_s_not_found_using_default_0085d970
// -----------------------------------------------------------------------------
// Stable ID: aa_0085d970
// Address:   0x0085d970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Inventory Texture <%s> not found, using default...
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_Inventory_Texture_s_not_found_using_default_0085d970(int *param_1,LPCSTR param_2)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  BOOL BVar4;

  char *pcVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  uint uVar9;

  LPCSTR pCVar10;

  char *pcVar11;

  LPCSTR pCVar12;

  uint32_t /* width from decompiler */ uStack_108;

  char acStack_104 [260];

  

  if ((param_2 != (LPCSTR)0x0) && (*param_2 = '\0', param_1 != (int *)0x0)) {

    pcVar2 = (char *)(**(code **)(*param_1 + 0x1c4))();

    pCVar10 = param_2;

    do {

      cVar1 = *pcVar2;

      *pCVar10 = cVar1;

      pcVar2 = pcVar2 + 1;

      pCVar10 = pCVar10 + 1;

    } while (cVar1 != '\0');

    pCVar10 = param_2 + -1;

    do {

      pCVar12 = pCVar10;

      pCVar10 = pCVar12 + 1;

    } while (pCVar12[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pCVar12 + 1) = DAT_00a2c53c;

    pCVar12[5] = DAT_00a2c540;

    iVar3 = FUN_007b6a20();

    if ((*(byte *)(iVar3 + 4) & 1) != 0) {

      BVar4 = PathFileExistsA(param_2);

      if (BVar4 != 0) {

        return;

      }

      uStack_108 = (char *)FUN_007b6420();

      pcVar2 = (char *)&DAT_00d1e574;

      do {

        pcVar8 = pcVar2;

        if (0xf < *(uint *)(pcVar2 + 0x14)) {

          pcVar8 = *(char **)pcVar2;

        }

        pcVar11 = acStack_104;

        do {

          cVar1 = *pcVar8;

          *pcVar11 = cVar1;

          pcVar8 = pcVar8 + 1;

          pcVar11 = pcVar11 + 1;

          pcVar5 = uStack_108;

        } while (cVar1 != '\0');

        do {

          cVar1 = *pcVar5;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        uVar6 = (int)pcVar5 - (int)uStack_108;

        pcVar8 = (char *)((int)&uStack_108 + 3);

        do {

          pcVar11 = pcVar8 + 1;

          pcVar8 = pcVar8 + 1;

        } while (*pcVar11 != '\0');

        pcVar11 = uStack_108;

        for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar11;

          pcVar11 = pcVar11 + 4;

          pcVar8 = pcVar8 + 4;

        }

        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *pcVar8 = *pcVar11;

          pcVar11 = pcVar11 + 1;

          pcVar8 = pcVar8 + 1;

        }

        BVar4 = PathFileExistsA(acStack_104);

        if (BVar4 != 0) {

          return;

        }

        pcVar2 = pcVar2 + 0x1c;

      } while ((int)pcVar2 < 0xd1e7a4);

    }

    cVar1 = FUN_007b66c0(iVar3);

    if (cVar1 == '\0') {

      uVar7 = (**(code **)(*param_1 + 0x1c4))();

      FUN_007a4480(0,"Inventory Texture <%s> not found, using default...\n",uVar7);

      *(uint32_t /* width from decompiler */ *)param_2 = s_i_g_2d_inv_default_00a657fc._0_4_;

      *(uint32_t /* width from decompiler */ *)(param_2 + 4) = s_i_g_2d_inv_default_00a657fc._4_4_;

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = s_i_g_2d_inv_default_00a657fc._8_4_;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = s_i_g_2d_inv_default_00a657fc._12_4_;

      *(uint16_t *)(param_2 + 0x10) = s_i_g_2d_inv_default_00a657fc._16_2_;

      param_2[0x12] = s_i_g_2d_inv_default_00a657fc[0x12];

      pCVar10 = param_2 + -1;

      do {

        pCVar12 = pCVar10;

        pCVar10 = pCVar12 + 1;

      } while (pCVar12[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pCVar12 + 1) = DAT_00a2c53c;

      pCVar12[5] = DAT_00a2c540;

    }

  }

  return;

}
