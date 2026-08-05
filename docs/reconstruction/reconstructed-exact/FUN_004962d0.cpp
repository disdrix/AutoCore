// =============================================================================
// FUN_004962d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004962d0
// Address:   0x004962d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004962d0 @ 0x004962d0
// Stable ID: aa_004962d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_00402090, FUN_004073a0, FUN_004962d0, FUN_004bf450, FUN_005815a0, FUN_005b7df0.
//  - Return sites: 4.

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

void __thiscall FUN_004962d0(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3,char param_4,char param_5)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  char cVar5;

  int iVar6;

  

  iVar4 = param_2;

  if (param_4 != '\0') {

    iVar6 = *(int *)(*(int *)(param_2 + 4) + 4) + param_2;

    iVar1 = *(int *)(iVar6 + 0xac);

    iVar2 = *(int *)(iVar1 + 0x38);

    if ((((iVar2 == 1) || (iVar2 == 3)) && (*(char *)(*(int *)(iVar1 + 0x3c) + 0x408) != '\x03')) &&

       ((*(uint *)(iVar6 + 0x180) >> 0x12 & 1) == 0)) {

      FUN_005815a0(1);

    }

  }

  if (((*(char *)(iVar4 + 0xd) != '\0') && (*(int *)(param_1 + 0x28) != 0)) &&

     ((*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) + 0x3f2

                ) & 0x20) == 0)) {

    iVar6 = FUN_00402090(*param_3,param_3[2]);

    cVar5 = param_5;

    if ((*(int *)(iVar6 + 0x24) != 0) && (param_5 == '\0')) {

      FUN_004bf450(iVar4,1);

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = 0;

      return;

    }

    FUN_005b7df0(iVar4);

    if ((*(int *)(iVar6 + 0x24) != 0) && (cVar5 != '\0')) {

      *(uint8_t *)(*(int *)(iVar6 + 0x24) + 0x570) = 1;

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = 0;

    return;

  }

  iVar6 = *(int *)(param_1 + 0x1c);

  if ((iVar6 != 0) &&

     ((uint)(*(int *)(param_1 + 0x20) - iVar6 >> 2) < (uint)(*(int *)(param_1 + 0x24) - iVar6 >> 2))

     ) {

    piVar3 = *(int **)(param_1 + 0x20);

    *piVar3 = iVar4;

    *(int **)(param_1 + 0x20) = piVar3 + 1;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = 2;

    return;

  }

  FUN_004073a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),1,&param_2);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = 2;

  return;

}
