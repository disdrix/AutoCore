// =============================================================================
// FUN_0088f500
// -----------------------------------------------------------------------------
// Stable ID: aa_0088f500
// Address:   0x0088f500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088f500 @ 0x0088f500
// Stable ID: aa_0088f500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, return×1.
//  - Notable callees: FUN_00513e70, FUN_00514050, FUN_005142a0, FUN_005706d0, FUN_0085d970, FUN_0088f500, FUN_00977a30, sprintf.
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

void FUN_0088f500(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  char acStack_28c [96];

  uint8_t auStack_22c [244];

  char acStack_138 [312];

  

  if (DAT_00d1b6d8 != 0) {

    piVar1 = *(int **)(DAT_00d1b6d8 + 0x650);

    if (piVar1 == (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x5bc) + 4))(0);

      (**(code **)(**(int **)(in_EAX + 0x5c0) + 4))(0);

      (**(code **)(**(int **)(in_EAX + 0x5c4) + 4))(0);

      (**(code **)(**(int **)(in_EAX + 0x5c8) + 4))(0);

      (**(code **)(**(int **)(in_EAX + 0x5cc) + 4))(0);

      if (*(int *)(in_EAX + 0x5b8) != 0) {

        (**(code **)(**(int **)(in_EAX + 0x5b8) + 4))(1);

      }

      if (*(int *)(in_EAX + 0x5b4) != 0) {

        (**(code **)(**(int **)(in_EAX + 0x5b4) + 4))(0);

      }

    }

    else {

      if (*(int *)(in_EAX + 0x5b8) != 0) {

        (**(code **)(**(int **)(in_EAX + 0x5b8) + 4))(0);

      }

      if (*(int *)(in_EAX + 0x5b4) != 0) {

        (**(code **)(**(int **)(in_EAX + 0x5b4) + 4))(1);

      }

      (**(code **)(**(int **)(in_EAX + 0x5bc) + 4))(1);

      (**(code **)(**(int **)(in_EAX + 0x5c0) + 0x268))();

      iVar3 = FUN_005142a0();

      if ((-1 < iVar3 >> 0x1f) && ((iVar3 < 0 || (iVar3 != 0)))) {

        FUN_00977a30(DAT_00d1ad30,iVar3,iVar3 >> 0x1f);

        (**(code **)(**(int **)(in_EAX + 0x5c0) + 4))(1);

        (**(code **)(**(int **)(in_EAX + 0x5c0) + 0x34c))();

      }

      pcVar4 = (char *)(**(code **)(*piVar1 + 0x15c))();

      pcVar6 = acStack_28c;

      do {

        cVar2 = *pcVar4;

        *pcVar6 = cVar2;

        pcVar4 = pcVar4 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar2 != '\0');

      iVar3 = **(int **)(in_EAX + 0x5c4);

      uVar5 = FUN_00514050(&stack0xfffffd70);

      (**(code **)(iVar3 + 0x15c))(1,uVar5);

      (**(code **)(**(int **)(in_EAX + 0x5c4) + 0x1d8))(&stack0xfffffd6c,1,1);

      (**(code **)(**(int **)(in_EAX + 0x5c4) + 4))(1);

      (**(code **)(**(int **)(in_EAX + 0x5c4) + 0x34c))();

      (**(code **)(**(int **)(in_EAX + 0x5c8) + 4))(1);

      (**(code **)(**(int **)(in_EAX + 0x5cc) + 4))(1);

      (**(code **)(**(int **)(in_EAX + 0x5cc) + 0x58))();

      FUN_0085d970(piVar1,auStack_22c);

      iVar3 = **(int **)(in_EAX + 0x5cc);

      uVar5 = (**(code **)(**(int **)(in_EAX + 0x5cc) + 0x2c8))(0);

      (**(code **)(iVar3 + 0x50))(auStack_22c,uVar5);

      (**(code **)(**(int **)(in_EAX + 0x5cc) + 0xcc))(1);

      (**(code **)(**(int **)(in_EAX + 0x5cc) + 0x34c))();

      cVar2 = FUN_00513e70();

      if (cVar2 == '\0') {

        pcVar6 = (char *)0x0;

      }

      else {

        uVar5 = (**(code **)(*piVar1 + 0x25c))();

        sprintf(acStack_138,"%d",uVar5);

        pcVar6 = acStack_138;

      }

      (**(code **)(**(int **)(in_EAX + 0x5cc) + 0x1d8))(pcVar6,1,1);

      (**(code **)(**(int **)(in_EAX + 0x5cc) + 0x34c))();

    }

    if ((*(int *)(in_EAX + 0x588) != 0) && (*(int *)(*(int *)(in_EAX + 0x588) + 0x35c) != 0)) {

      FUN_005706d0();

    }

  }

  return;

}
