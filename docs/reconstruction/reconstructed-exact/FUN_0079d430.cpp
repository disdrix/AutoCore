// =============================================================================
// FUN_0079d430
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d430
// Address:   0x0079d430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079d430 @ 0x0079d430
// Stable ID: aa_0079d430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, while×4, do×3, goto×1.
//  - Notable callees: FUN_00793930, FUN_00793aa0, FUN_00793b80, FUN_0079d430.
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

uint32_t /* width from decompiler */ FUN_0079d430(int *param_1,int param_2)



{

  char cVar1;

  byte bVar2;

  char *pcVar3;

  int iVar4;

  byte *pbVar5;

  byte *pbVar6;

  byte *pbVar7;

  char *unaff_EBX;

  int *piVar8;

  uint64_t uVar9;

  

  piVar8 = *(int **)(*param_1 + 4);

  if (piVar8 == (int *)0x0) {

    return 0;

  }

  cVar1 = *unaff_EBX;

  pcVar3 = unaff_EBX;

  while (cVar1 != '\0') {

    pcVar3 = pcVar3 + 1;

    cVar1 = *pcVar3;

  }

  iVar4 = (int)pcVar3 - (int)unaff_EBX;

  if (iVar4 == 0) {

    return 0;

  }

  pbVar5 = operator_new__(iVar4 + 1);

  FUN_00793aa0(pbVar5);

  FUN_00793930();

  if ((*(char *)((int)param_1 + 5) != '\0') && (pbVar6 = pbVar5, 0 < iVar4)) {

    do {

      *pbVar6 = *pbVar6 ^ 0xaa;

      pbVar6 = pbVar6 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  do {

    pbVar6 = (byte *)piVar8[5];

    bVar2 = *pbVar6;

    pbVar7 = pbVar5;

    if (*pbVar5 == bVar2) {

      do {

        if (bVar2 == 0) break;

        bVar2 = pbVar6[1];

        pbVar6 = pbVar6 + 1;

        pbVar7 = pbVar7 + 1;

      } while (*pbVar7 == bVar2);

    }

    bVar2 = *pbVar7;

    if ((*pbVar6 == 0) && ((((bVar2 == 0 || (bVar2 == 0x20)) || (bVar2 == 10)) || (bVar2 == 0xd))))

    {

LAB_0079d50b:

      if (param_2 != 0) {

        uVar9 = FUN_00793b80();

        *(uint32_t /* width from decompiler */ *)((ulonglong)uVar9 >> 0x20) = (int)uVar9;

      }

      operator_delete__(pbVar5);

      return 1;

    }

    iVar4 = (**(code **)(*piVar8 + 4))(pbVar5);

    if (iVar4 < 1) {

      if (-1 < iVar4) goto LAB_0079d50b;

      piVar8 = (int *)piVar8[2];

    }

    else {

      piVar8 = (int *)piVar8[3];

    }

    if ((piVar8 == (int *)0x0) || (iVar4 == 0)) {

      operator_delete__(pbVar5);

      return 0;

    }

  } while( true );

}
