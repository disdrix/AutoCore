// =============================================================================
// FUN_00611290
// -----------------------------------------------------------------------------
// Stable ID: aa_00611290
// Address:   0x00611290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00611290 @ 0x00611290
// Stable ID: aa_00611290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CVOGReaction_BuildTextParams, FUN_005711c0, FUN_00611290.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall

FUN_00611290(int param_1,int param_2,int *param_3,int param_4,float param_5,uint32_t /* width from decompiler */ param_6,

            uint32_t /* width from decompiler */ param_7,int param_8)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (param_4 == 4) {

    if (*(int *)(*(int *)(param_2 + 0x250) + 0x2b0) != 0) {

      iVar1 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0);

      if (((int)param_5 == *(int *)(param_1 + 0x18)) &&

         ((*(int *)(param_1 + 0x14) <= iVar1 || (*(char *)(param_1 + 0x23) == '\0')))) {

        param_3[*(byte *)(param_1 + 8) + 1] = (int)g_flOne;

        if (*(char *)(param_1 + 0x22) != '\0') {

          local_18 = *(uint32_t /* width from decompiler */ *)(*param_3 + 0x10);

          param_2 = *(int *)(*(int *)(param_2 + 4) + 4) + param_2;

          local_30 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x164);

          local_2c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x168);

          local_28 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

          local_24 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x170);

          local_10 = *(uint32_t /* width from decompiler */ *)(param_8 + 0x160);

          local_c = *(uint32_t /* width from decompiler */ *)(param_8 + 0x164);

          local_8 = *(uint32_t /* width from decompiler */ *)(param_8 + 0x168);

          local_4 = *(uint32_t /* width from decompiler */ *)(param_8 + 0x16c);

          local_20 = 0xffffffff;

          local_1c = 0xffffffff;

          CVOGReaction_BuildTextParams(&local_30);

        }

        return 1;

      }

    }

  }

  return 0;

}
