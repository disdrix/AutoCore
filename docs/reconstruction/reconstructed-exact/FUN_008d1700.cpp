// =============================================================================
// FUN_008d1700
// -----------------------------------------------------------------------------
// Stable ID: aa_008d1700
// Address:   0x008d1700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d1700 @ 0x008d1700
// Stable ID: aa_008d1700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_004faaf0, FUN_004fab40, FUN_004fcd80, FUN_00519a30, FUN_006a3db0, FUN_008d1700.
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

void FUN_008d1700(int param_1)



{

  int iVar1;

  int *in_EAX;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int unaff_EDI;

  uint8_t *puVar7;

  int iStack_14;

  uint8_t auStack_10 [16];

  

  if (((in_EAX != (int *)0x0) && (iVar2 = (**(code **)(*in_EAX + 700))(), iVar2 != 0)) &&

     (*(int *)(param_1 + 0x548) != 0)) {

    if ((DAT_00b042b8 == 0) && (FUN_00519a30(), DAT_00b042b8 == 0)) {

      return;

    }

    puVar7 = auStack_10;

    piVar3 = (int *)(**(code **)(*in_EAX + 0x120))(puVar7,1,1);

    iVar4 = DAT_00d1d86c - *piVar3;

    piVar3 = (int *)(**(code **)(*in_EAX + 700))();

    iVar2 = *(int *)(*piVar3 + 0x1c);

    piVar3 = (int *)(**(code **)(*in_EAX + 0x140))(&stack0xffffffdc,1);

    iVar1 = *piVar3;

    iVar5 = (**(code **)(*in_EAX + 0x140))(&stack0xffffffe4,1);

    iVar5 = *(int *)(iVar5 + 4);

    iVar6 = FUN_006a3db0();

    if (iVar6 < 2) {

      iVar6 = 1;

    }

    iVar2 = ((int)(((float)puVar7 / (float)iVar5) * (float)unaff_EDI) / iVar6) * (iVar2 / iVar6) +

            (int)((float)iVar4 * ((float)iVar2 / (float)iVar1)) / iVar6;

    if (0x3f < iVar2) {

      iVar2 = 0;

    }

    if (iStack_14 == 0) {

      FUN_004faaf0((&DAT_00a1e2e8)[iVar2]);

    }

    else if (iStack_14 == 1) {

      FUN_004fab40((&DAT_00a1e2e8)[iVar2]);

    }

    FUN_004fcd80(0);

  }

  return;

}
