// =============================================================================
// FUN_006bae10
// -----------------------------------------------------------------------------
// Stable ID: aa_006bae10
// Address:   0x006bae10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bae10 @ 0x006bae10
// Stable ID: aa_006bae10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: while×4, if×4, do×2, return×1.
//  - Notable callees: FUN_006bae10×2.
//  - Return sites: 1.

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

void FUN_006bae10(int param_1,int param_2,int param_3,code *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  char *pcVar4;

  int iVar5;

  int iVar6;

  uint8_t local_56;

  uint8_t uStack_55;

  int local_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  

  do {

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + (param_2 + param_3 >> 1) * 0x14);

    local_30 = *puVar1;

    local_2c = puVar1[1];

    local_28 = puVar1[2];

    local_24 = puVar1[3];

    local_20 = puVar1[4];

    iVar5 = param_3;

    iVar6 = param_2;

    do {

      local_54 = param_1 + iVar6 * 0x14;

      pcVar4 = (char *)(*param_4)(&local_56,local_54,&local_30);

      cVar3 = *pcVar4;

      while (cVar3 != '\0') {

        local_54 = local_54 + 0x14;

        iVar6 = iVar6 + 1;

        pcVar4 = (char *)(*param_4)(&local_56,local_54,&local_30);

        cVar3 = *pcVar4;

      }

      local_54 = param_1 + iVar5 * 0x14;

      pcVar4 = (char *)(*param_4)(&uStack_55,&local_30,local_54);

      cVar3 = *pcVar4;

      while (cVar3 != '\0') {

        local_54 = local_54 + -0x14;

        iVar5 = iVar5 + -1;

        pcVar4 = (char *)(*param_4)(&uStack_55,&local_30,local_54);

        cVar3 = *pcVar4;

      }

      if (iVar5 < iVar6) break;

      if (iVar5 != iVar6) {

        puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 0x14);

        uStack_50 = *puVar1;

        uStack_4c = puVar1[1];

        uStack_48 = puVar1[2];

        uStack_44 = puVar1[3];

        uStack_40 = puVar1[4];

        puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + iVar6 * 0x14);

        *puVar1 = *puVar2;

        puVar1[1] = puVar2[1];

        puVar1[2] = puVar2[2];

        puVar1[3] = puVar2[3];

        puVar1[4] = puVar2[4];

        *puVar2 = uStack_50;

        puVar2[1] = uStack_4c;

        puVar2[2] = uStack_48;

        puVar2[3] = uStack_44;

        puVar2[4] = uStack_40;

      }

      iVar5 = iVar5 + -1;

      iVar6 = iVar6 + 1;

    } while (iVar6 <= iVar5);

    if (param_2 < iVar5) {

      FUN_006bae10(param_1,param_2,iVar5,param_4);

    }

    param_2 = iVar6;

    if (param_3 <= iVar6) {

      return;

    }

  } while( true );

}
