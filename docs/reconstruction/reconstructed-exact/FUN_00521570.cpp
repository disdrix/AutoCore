// =============================================================================
// FUN_00521570
// -----------------------------------------------------------------------------
// Stable ID: aa_00521570
// Address:   0x00521570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521570 @ 0x00521570
// Stable ID: aa_00521570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004c3320, FUN_00521570.
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

void __thiscall FUN_00521570(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,char *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_2 == 0) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    iVar2 = *(int *)(iVar1 + 0xa8 + param_1);

    if ((iVar2 != 0) && (*(int *)(iVar2 + 0xe8a0) != 0)) {

      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

      iVar2 = *(int *)(*(int *)(iVar3 + 0xa8) + 0xe8a0);

      if ((*(int *)(iVar2 + 0x160) != *(int *)(iVar3 + 0x164)) ||

         (*(int *)(iVar2 + 0x164) != *(int *)(iVar3 + 0x168))) {

        if (*(int *)(*(int *)(*(int *)(iVar1 + param_1 + 0xac) + 0x3c) + 0x528) != 0) {

          *(uint32_t /* width from decompiler */ *)param_4 = s_char_g_m_ai_anm_009cf0e8._0_4_;

          *(uint32_t /* width from decompiler */ *)(param_4 + 4) = s_char_g_m_ai_anm_009cf0e8._4_4_;

          *(uint32_t /* width from decompiler */ *)(param_4 + 8) = s_char_g_m_ai_anm_009cf0e8._8_4_;

          *(uint32_t /* width from decompiler */ *)(param_4 + 0xc) = s_char_g_m_ai_anm_009cf0e8._12_4_;

          return;

        }

        *(uint32_t /* width from decompiler */ *)param_4 = s_char_g_f_ai_anm_009cf0d8._0_4_;

        *(uint32_t /* width from decompiler */ *)(param_4 + 4) = s_char_g_f_ai_anm_009cf0d8._4_4_;

        *(uint32_t /* width from decompiler */ *)(param_4 + 8) = s_char_g_f_ai_anm_009cf0d8._8_4_;

        *(uint32_t /* width from decompiler */ *)(param_4 + 0xc) = s_char_g_f_ai_anm_009cf0d8._12_4_;

        return;

      }

    }

  }

  FUN_004c3320(param_2,param_3,param_4);

  return;

}
