// =============================================================================
// FUN_007b0770
// -----------------------------------------------------------------------------
// Stable ID: aa_007b0770
// Address:   0x007b0770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b0770 @ 0x007b0770
// Stable ID: aa_007b0770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×2.
//  - Notable callees: FUN_00797d70, FUN_007a69d0, FUN_007a6de0, FUN_007b0770.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_007b0770(int *param_1,char *param_2,char param_3,char param_4)



{

  char *pcVar1;

  char *pcVar2;

  char cVar3;

  float fVar4;

  int iVar5;

  char *pcVar6;

  void *pvVar7;

  char *pcVar8;

  

  if (param_2 == (char *)0x0) {

    if ((void *)param_1[0x9d] != (void *)0x0) {

      operator_delete__((void *)param_1[0x9d]);

    }

    iVar5 = DAT_00aaa8dc;

    param_1[0x9d] = 0;

    param_1[0x49] = 0;

    param_1[0xb1] = iVar5;

  }

  else {

    if (param_4 != '\0') {

      FUN_007a69d0();

      param_2 = (char *)FUN_007a6de0(param_2,0xffffffff);

    }

    pcVar1 = param_2 + 1;

    pcVar6 = param_2;

    do {

      cVar3 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar3 != '\0');

    pcVar2 = pcVar6 + (1 - (int)pcVar1);

    if (((char *)param_1[0x49] != pcVar2) || (param_1[0x9d] == 0)) {

      if ((void *)param_1[0x9d] != (void *)0x0) {

        operator_delete__((void *)param_1[0x9d]);

      }

      param_1[0x9d] = 0;

      pvVar7 = operator_new__((uint)pcVar2);

      param_1[0x9d] = (int)pvVar7;

    }

    pcVar8 = (char *)param_1[0x9d];

    do {

      cVar3 = *param_2;

      *pcVar8 = cVar3;

      param_2 = param_2 + 1;

      pcVar8 = pcVar8 + 1;

    } while (cVar3 != '\0');

    param_1[0x49] = (int)pcVar2;

    fVar4 = (float)(int)(pcVar6 + (7 - (int)pcVar1));

    if ((int)(pcVar6 + (7 - (int)pcVar1)) < 0) {

      fVar4 = fVar4 + _DAT_00aaa5dc;

    }

    param_1[0xb1] = (int)fVar4;

  }

  pvVar7 = (void *)param_1[0xa3];

  if (pvVar7 != (void *)0x0) {

    FUN_00797d70(pvVar7);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar7);

  }

  param_1[0xa3] = 0;

  if (param_3 != '\0') {

    (**(code **)(*param_1 + 0x268))();

  }

  return;

}
