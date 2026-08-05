// =============================================================================
// FUN_0088ca10
// -----------------------------------------------------------------------------
// Stable ID: aa_0088ca10
// Address:   0x0088ca10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088ca10 @ 0x0088ca10
// Stable ID: aa_0088ca10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×7, return×6, goto×2, switch×1.
//  - Notable callees: Client_SendSectorPacket, FUN_007fb990, FUN_0087b500, FUN_0088c340, FUN_0088ca10, FUN_0093e120.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __thiscall FUN_0088ca10(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ auStack_20 [2];

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t uStack_10;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if ((param_1[0x14e] == 0) || (iVar2 = (**(code **)(*param_1 + 0xe8))(), iVar2 == -1)) {

    return 0;

  }

  switch(param_3) {

  case 40000:

    if (param_2 == 8) {

      cVar1 = FUN_0088c340();

      if (cVar1 == '\0') {

        return 1;

      }

      FUN_007fb990();

      return 1;

    }

    break;

  case 0x9c41:

    if (param_2 == 8) {

      uStack_10 = 2;

      uStack_8 = 1;

      uStack_18 = *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x160);

      uStack_14 = *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x164);

LAB_0088cb62:

      uStack_4 = 0;

      auStack_20[0] = 0x20a4;

      Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

      return 1;

    }

    break;

  case 0x9c42:

    if (param_2 == 8) {

      uStack_10 = 2;

      uStack_8 = 3;

      uStack_18 = *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x160);

      uStack_14 = *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x164);

      goto LAB_0088cb62;

    }

    break;

  case 0x9c43:

    if (param_2 == 8) {

      uStack_10 = 0;

      uStack_8 = 0;

      uStack_18 = *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x160);

      uStack_14 = *(uint32_t /* width from decompiler */ *)(param_1[0x14e] + 0x164);

      goto LAB_0088cb62;

    }

    break;

  case 0x9c44:

    if (param_2 == 9) {

      FUN_0093e120(param_1[0x14e]);

      return 1;

    }

  }

  uVar3 = FUN_0087b500(param_2,param_3);

  return uVar3;

}
