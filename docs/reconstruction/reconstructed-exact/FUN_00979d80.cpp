// =============================================================================
// FUN_00979d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00979d80
// Address:   0x00979d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00979d80 @ 0x00979d80
// Stable ID: aa_00979d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: return×5, if×2, switch×1.
//  - Notable callees: FUN_00979d80.
//  - Return sites: 5.

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

void FUN_00979d80(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int unaff_ESI;

  int iStack_70;

  int iStack_68;

  int iStack_64;

  int iStack_60;

  int iStack_5c;

  int iStack_50;

  int iStack_4c;

  uint8_t local_40 [8];

  uint8_t local_38 [8];

  uint8_t local_30 [16];

  uint8_t local_20 [16];

  uint8_t local_10 [8];

  uint8_t local_8 [8];

  

  if (*(int *)(unaff_ESI + 0x500) != 0) {

    switch(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x538)) {

    case 0:

      iStack_70 = 1;

      (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_40);

      iStack_70 = *(int *)(unaff_ESI + 0x51c) + *(int *)(unaff_ESI + 0x50c) +

                  *(int *)(unaff_ESI + 0x504);

      (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x110))(&iStack_70);

      return;

    case 1:

      iVar4 = *(int *)(unaff_ESI + 0x520);

      iVar1 = *(int *)(unaff_ESI + 0x510);

      iVar2 = *(int *)(unaff_ESI + 0x508);

      iStack_70 = 1;

      piVar5 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_38);

      iStack_68 = (*(int *)(unaff_ESI + 0x51c) - *piVar5 / 2) + *(int *)(unaff_ESI + 0x50c) +

                  *(int *)(unaff_ESI + 0x504);

      iStack_64 = iVar4 + iVar1 + iVar2;

      (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x110))(&iStack_68);

      return;

    case 2:

      iStack_70 = 1;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_30);

      iVar4 = *(int *)(iVar4 + 4);

      iVar1 = *(int *)(unaff_ESI + 0x520);

      iVar2 = *(int *)(unaff_ESI + 0x510);

      iVar3 = *(int *)(unaff_ESI + 0x508);

      piVar5 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_30,1);

      iStack_68 = (*(int *)(unaff_ESI + 0x51c) + *(int *)(unaff_ESI + 0x50c) +

                  *(int *)(unaff_ESI + 0x504)) - *piVar5;

      iStack_64 = (iVar1 + iVar2 + iVar3) - iVar4 / 2;

      (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x110))(&iStack_68);

      return;

    case 3:

      iStack_70 = 1;

      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_20);

      iVar4 = *(int *)(unaff_ESI + 0x520);

      iVar1 = *(int *)(unaff_ESI + 0x510);

      iVar2 = *(int *)(unaff_ESI + 0x508);

      iVar3 = *(int *)(iVar3 + 4);

      piVar5 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_20,1);

      iStack_60 = (*(int *)(unaff_ESI + 0x51c) - *piVar5 / 2) + *(int *)(unaff_ESI + 0x50c) +

                  *(int *)(unaff_ESI + 0x504);

      iStack_5c = (iVar4 + iVar1 + iVar2) - iVar3;

      (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x110))(&iStack_60);

      return;

    }

    if (*(int *)(unaff_ESI + 0x508) < 1) {

      iStack_70 = 1;

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_10);

      iVar4 = *(int *)(iVar4 + 4);

    }

    else {

      iVar4 = 0;

    }

    iVar1 = *(int *)(unaff_ESI + 0x520);

    iVar2 = *(int *)(unaff_ESI + 0x510);

    iVar3 = *(int *)(unaff_ESI + 0x508);

    iStack_70 = 1;

    piVar5 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(local_8);

    iStack_50 = (*(int *)(unaff_ESI + 0x51c) - *piVar5 / 2) + *(int *)(unaff_ESI + 0x50c) +

                *(int *)(unaff_ESI + 0x504);

    iStack_4c = ((iVar1 + iVar2) - iVar4) + iVar3;

    (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x110))(&iStack_50);

  }

  return;

}
