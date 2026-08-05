// =============================================================================
// FUN_008f5c40
// -----------------------------------------------------------------------------
// Stable ID: aa_008f5c40
// Address:   0x008f5c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f5c40 @ 0x008f5c40
// Stable ID: aa_008f5c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×14, do×1, while×1, return×1.
//  - Notable callees: FUN_008f5c40.
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

void FUN_008f5c40(void)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  int *piVar3;

  int iVar4;

  

  if (*(int *)(in_EAX + 0x504) != 0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x504) + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x504) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(in_EAX + 0x530) != 0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x530) + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x530) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(in_EAX + 0x52c) != 0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x52c) + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x52c) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(in_EAX + 0x534) != 0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x534) + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x534) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(in_EAX + 0x508) != 0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x508) + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x508) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(in_EAX + 0x548) != 0) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x548) + 0xd0))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x548) + 0xfc))(0,0x3e800000);

    }

  }

  piVar3 = (int *)(in_EAX + 0x540);

  iVar4 = 2;

  do {

    iVar1 = *piVar3;

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0xe80) != 0)) {

      cVar2 = (**(code **)(**(int **)(iVar1 + 0xe80) + 0xd0))();

      if (cVar2 != '\0') {

        (**(code **)(**(int **)(*piVar3 + 0xe80) + 0xfc))(0,0x3e800000);

      }

    }

    piVar3 = piVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return;

}
