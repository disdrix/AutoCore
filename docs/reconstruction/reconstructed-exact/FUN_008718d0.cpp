// =============================================================================
// FUN_008718d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008718d0
// Address:   0x008718d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008718d0 @ 0x008718d0
// Stable ID: aa_008718d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, while×1, goto×1, return×1.
//  - Notable callees: FUN_00411500, FUN_007fbd30, FUN_00870e80, FUN_00871150, FUN_00871690, FUN_008718d0.
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

void FUN_008718d0(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int *unaff_EBX;

  int *piVar5;

  int *piVar6;

  

  if (unaff_EBX != (int *)0x0) {

    piVar2 = (int *)FUN_00871690(*unaff_EBX,unaff_EBX[1]);

    if (piVar2 == (int *)0x0) {

      piVar2 = operator_new(0x40);

      piVar2[0xe] = -1;

      FUN_00411500(param_1 + 0x628,piVar2);

    }

    piVar5 = unaff_EBX;

    piVar6 = piVar2 + 2;

    for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {

      *piVar6 = *piVar5;

      piVar5 = piVar5 + 1;

      piVar6 = piVar6 + 1;

    }

    *piVar2 = 0;

    uVar4 = 0;

    while( true ) {

      iVar3 = *(int *)(DAT_00d1b644 + 0xe75c);

      if ((iVar3 == 0) || ((uint)(*(int *)(DAT_00d1b644 + 0xe760) - iVar3 >> 2) <= uVar4))

      goto LAB_0087199e;

      iVar3 = *(int *)(iVar3 + uVar4 * 4);

      iVar1 = *(int *)(*(int *)(iVar3 + 4) + 4);

      if ((*(int *)(iVar1 + 0x164 + iVar3) == *unaff_EBX) &&

         (*(int *)(iVar1 + 0x168 + iVar3) == unaff_EBX[1])) break;

      uVar4 = uVar4 + 1;

    }

    *piVar2 = iVar3;

    *(uint16_t *)(iVar3 + 0x60c) = *(uint16_t *)((int)unaff_EBX + 0xe);

    *(uint *)(iVar3 + 0x610) = (uint)*(ushort *)(unaff_EBX + 2);

    *(uint *)(iVar3 + 0x614) = (uint)*(ushort *)((int)unaff_EBX + 10);

    *(uint *)(iVar3 + 0x618) = (uint)*(ushort *)(unaff_EBX + 3);

LAB_0087199e:

    FUN_00871150(piVar2);

    FUN_00870e80();

    FUN_007fbd30();

    *(uint8_t *)(param_1 + 0x548) = 1;

  }

  return;

}
