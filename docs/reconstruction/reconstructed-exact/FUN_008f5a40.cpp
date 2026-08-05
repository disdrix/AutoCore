// =============================================================================
// FUN_008f5a40
// -----------------------------------------------------------------------------
// Stable ID: aa_008f5a40
// Address:   0x008f5a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f5a40 @ 0x008f5a40
// Stable ID: aa_008f5a40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×22, goto×7, do×1, return×1, while×1.
//  - Notable callees: FUN_008f5a40.
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

void FUN_008f5a40(void)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  if (*(int *)(in_EAX + 0x504) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x504) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x504) + 0xe8))();

      if (iVar2 != -1) goto LAB_008f5a87;

    }

    (**(code **)(**(int **)(in_EAX + 0x504) + 0xfc))(1,0x3e800000);

  }

LAB_008f5a87:

  if (*(int *)(in_EAX + 0x530) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x530) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x530) + 0xe8))();

      if (iVar2 != -1) goto LAB_008f5aca;

    }

    (**(code **)(**(int **)(in_EAX + 0x530) + 0xfc))(1,0x3e800000);

  }

LAB_008f5aca:

  if (*(int *)(in_EAX + 0x52c) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x52c) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x52c) + 0xe8))();

      if (iVar2 != -1) goto LAB_008f5b0d;

    }

    (**(code **)(**(int **)(in_EAX + 0x52c) + 0xfc))(1,0x3e800000);

  }

LAB_008f5b0d:

  if (*(int *)(in_EAX + 0x534) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x534) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x534) + 0xe8))();

      if (iVar2 != -1) goto LAB_008f5b50;

    }

    (**(code **)(**(int **)(in_EAX + 0x534) + 0xfc))(1,0x3e800000);

  }

LAB_008f5b50:

  if (*(int *)(in_EAX + 0x508) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x508) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x508) + 0xe8))();

      if (iVar2 != -1) goto LAB_008f5b93;

    }

    (**(code **)(**(int **)(in_EAX + 0x508) + 0xfc))(1,0x3e800000);

  }

LAB_008f5b93:

  if (*(int *)(in_EAX + 0x548) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x548) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x548) + 0xe8))();

      if (iVar2 != -1) goto LAB_008f5bd6;

    }

    (**(code **)(**(int **)(in_EAX + 0x548) + 0xfc))(1,0x3e800000);

  }

LAB_008f5bd6:

  piVar4 = (int *)(in_EAX + 0x540);

  iVar2 = 2;

  do {

    iVar3 = *piVar4;

    if ((iVar3 != 0) && (*(int *)(iVar3 + 0xe80) != 0)) {

      cVar1 = (**(code **)(**(int **)(iVar3 + 0xe80) + 0xd0))();

      if (cVar1 != '\0') {

        iVar3 = (**(code **)(**(int **)(*piVar4 + 0xe80) + 0xe8))();

        if (iVar3 != -1) goto LAB_008f5c2e;

      }

      (**(code **)(**(int **)(*piVar4 + 0xe80) + 0xfc))(1,0x3e800000);

    }

LAB_008f5c2e:

    piVar4 = piVar4 + 1;

    iVar2 = iVar2 + -1;

    if (iVar2 == 0) {

      return;

    }

  } while( true );

}
