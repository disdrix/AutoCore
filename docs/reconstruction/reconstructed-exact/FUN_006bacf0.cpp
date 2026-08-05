// =============================================================================
// FUN_006bacf0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bacf0
// Address:   0x006bacf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bacf0 @ 0x006bacf0
// Stable ID: aa_006bacf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: while×4, if×4, do×2, return×1.
//  - Notable callees: FUN_006bacf0×2.
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

void FUN_006bacf0(int param_1,int param_2,int param_3,code *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puVar12;

  int iVar13;

  int iVar14;

  uint8_t local_2a;

  uint8_t uStack_29;

  int local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  do {

    local_28 = param_2;

    puVar1 = (uint32_t /* width from decompiler */ *)((param_2 + param_3 >> 1) * 0x10 + param_1);

    local_20 = *puVar1;

    uStack_1c = puVar1[1];

    uStack_18 = puVar1[2];

    uStack_14 = puVar1[3];

    iVar13 = param_3;

    do {

      local_24 = local_28 * 0x10 + param_1;

      pcVar11 = (char *)(*param_4)(&local_2a,local_24,&local_20);

      cVar3 = *pcVar11;

      iVar14 = local_24;

      while (cVar3 != '\0') {

        local_28 = local_28 + 1;

        iVar14 = iVar14 + 0x10;

        pcVar11 = (char *)(*param_4)(&local_2a,iVar14,&local_20);

        cVar3 = *pcVar11;

      }

      local_24 = iVar13 * 0x10 + param_1;

      pcVar11 = (char *)(*param_4)(&uStack_29,&local_20,local_24);

      cVar3 = *pcVar11;

      iVar14 = local_24;

      while (cVar3 != '\0') {

        iVar14 = iVar14 + -0x10;

        iVar13 = iVar13 + -1;

        pcVar11 = (char *)(*param_4)(&uStack_29,&local_20,iVar14);

        cVar3 = *pcVar11;

      }

      if (iVar13 < local_28) break;

      if (iVar13 != local_28) {

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar13 * 0x10 + param_1);

        uVar4 = *puVar1;

        uVar5 = puVar1[1];

        uVar6 = puVar1[2];

        uVar7 = puVar1[3];

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar13 * 0x10 + param_1);

        puVar2 = (uint32_t /* width from decompiler */ *)(local_28 * 0x10 + param_1);

        uVar8 = puVar2[1];

        uVar9 = puVar2[2];

        uVar10 = puVar2[3];

        puVar12 = (uint32_t /* width from decompiler */ *)(local_28 * 0x10 + param_1);

        *puVar1 = *puVar2;

        puVar1[1] = uVar8;

        puVar1[2] = uVar9;

        puVar1[3] = uVar10;

        *puVar12 = uVar4;

        puVar12[1] = uVar5;

        puVar12[2] = uVar6;

        puVar12[3] = uVar7;

      }

      iVar13 = iVar13 + -1;

      local_28 = local_28 + 1;

    } while (local_28 <= iVar13);

    if (param_2 < iVar13) {

      FUN_006bacf0(param_1,param_2,iVar13,param_4);

    }

    param_2 = local_28;

    if (param_3 <= local_28) {

      return;

    }

  } while( true );

}
