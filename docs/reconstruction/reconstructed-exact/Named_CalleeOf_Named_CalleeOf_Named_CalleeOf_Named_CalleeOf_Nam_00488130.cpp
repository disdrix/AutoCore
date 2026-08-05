// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00488130
// -----------------------------------------------------------------------------
// Stable ID: aa_00488130
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00488130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, while×1.
//  - Notable callees: FUN_00488130.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00488130(int param_1,int param_2,uint param_3,int *param_4)



{

  byte bVar1;

  byte bVar2;

  ushort uVar3;

  ushort uVar4;

  int in_EAX;

  uint uVar5;

  int iVar6;

  uint uVar7;

  int unaff_EDI;

  bool bVar8;

  

  bVar8 = *(byte *)(param_1 + unaff_EDI) < *(byte *)(in_EAX + unaff_EDI);

  if (((((((*(byte *)(param_1 + unaff_EDI) != *(byte *)(in_EAX + unaff_EDI)) ||

          (bVar1 = *(byte *)(in_EAX + 1 + unaff_EDI), bVar2 = *(byte *)(param_1 + 1 + unaff_EDI),

          bVar8 = bVar2 < bVar1, bVar2 != bVar1)) ||

         (bVar1 = *(byte *)(in_EAX + 2 + unaff_EDI), bVar2 = *(byte *)(param_1 + 2 + unaff_EDI),

         bVar8 = bVar2 < bVar1, bVar2 != bVar1)) ||

        ((bVar1 = *(byte *)(in_EAX + 3 + unaff_EDI), bVar2 = *(byte *)(param_1 + 3 + unaff_EDI),

         bVar8 = bVar2 < bVar1, bVar2 != bVar1 ||

         (bVar1 = *(byte *)(in_EAX + 4 + unaff_EDI), bVar2 = *(byte *)(param_1 + 4 + unaff_EDI),

         bVar8 = bVar2 < bVar1, bVar2 != bVar1)))) ||

       ((bVar1 = *(byte *)(in_EAX + 5 + unaff_EDI), bVar2 = *(byte *)(param_1 + 5 + unaff_EDI),

        bVar8 = bVar2 < bVar1, bVar2 != bVar1 ||

        ((bVar1 = *(byte *)(in_EAX + 6 + unaff_EDI), bVar2 = *(byte *)(param_1 + 6 + unaff_EDI),

         bVar8 = bVar2 < bVar1, bVar2 != bVar1 ||

         (bVar1 = *(byte *)(in_EAX + 7 + unaff_EDI), bVar2 = *(byte *)(param_1 + 7 + unaff_EDI),

         bVar8 = bVar2 < bVar1, bVar2 != bVar1)))))) ||

      (bVar1 = *(byte *)(in_EAX + 8 + unaff_EDI), bVar2 = *(byte *)(param_1 + 8 + unaff_EDI),

      bVar8 = bVar2 < bVar1, bVar2 != bVar1)) ||

     (((bVar1 = *(byte *)(in_EAX + 9 + unaff_EDI), bVar2 = *(byte *)(param_1 + 9 + unaff_EDI),

       bVar8 = bVar2 < bVar1, bVar2 != bVar1 ||

       (bVar1 = *(byte *)(in_EAX + 10 + unaff_EDI), bVar2 = *(byte *)(param_1 + 10 + unaff_EDI),

       bVar8 = bVar2 < bVar1, bVar2 != bVar1)) ||

      (bVar1 = *(byte *)(in_EAX + 0xb + unaff_EDI), bVar2 = *(byte *)(param_1 + 0xb + unaff_EDI),

      bVar8 = bVar2 < bVar1, bVar2 != bVar1)))) {

    return (uint)bVar8;

  }

  uVar5 = in_EAX + 0xc;

  uVar7 = param_1 + 0xc;

  iVar6 = param_3 + 8;

  while ((bVar8 = *(byte *)(uVar7 + unaff_EDI) < *(byte *)(uVar5 + unaff_EDI),

         *(byte *)(uVar7 + unaff_EDI) == *(byte *)(uVar5 + unaff_EDI) &&

         (uVar3 = *(ushort *)(param_2 + uVar5 * 2), uVar4 = *(ushort *)(param_2 + uVar7 * 2),

         bVar8 = uVar4 < uVar3, uVar4 == uVar3))) {

    bVar1 = *(byte *)(uVar5 + 1 + unaff_EDI);

    bVar2 = *(byte *)(uVar7 + 1 + unaff_EDI);

    bVar8 = bVar2 < bVar1;

    if ((bVar2 != bVar1) ||

       (uVar3 = *(ushort *)(param_2 + (uVar5 + 1) * 2),

       uVar4 = *(ushort *)(param_2 + (uVar7 + 1) * 2), bVar8 = uVar4 < uVar3, uVar4 != uVar3))

    break;

    bVar1 = *(byte *)(uVar5 + 2 + unaff_EDI);

    bVar2 = *(byte *)(uVar7 + 2 + unaff_EDI);

    bVar8 = bVar2 < bVar1;

    if ((bVar2 != bVar1) ||

       (uVar3 = *(ushort *)(param_2 + (uVar5 + 2) * 2),

       uVar4 = *(ushort *)(param_2 + (uVar7 + 2) * 2), bVar8 = uVar4 < uVar3, uVar4 != uVar3))

    break;

    bVar1 = *(byte *)(uVar5 + 3 + unaff_EDI);

    bVar2 = *(byte *)(uVar7 + 3 + unaff_EDI);

    bVar8 = bVar2 < bVar1;

    if ((bVar2 != bVar1) ||

       (uVar3 = *(ushort *)(param_2 + (uVar5 + 3) * 2),

       uVar4 = *(ushort *)(param_2 + (uVar7 + 3) * 2), bVar8 = uVar4 < uVar3, uVar4 != uVar3))

    break;

    bVar1 = *(byte *)(uVar5 + 4 + unaff_EDI);

    bVar2 = *(byte *)(uVar7 + 4 + unaff_EDI);

    bVar8 = bVar2 < bVar1;

    if ((bVar2 != bVar1) ||

       (uVar3 = *(ushort *)(param_2 + (uVar5 + 4) * 2),

       uVar4 = *(ushort *)(param_2 + (uVar7 + 4) * 2), bVar8 = uVar4 < uVar3, uVar4 != uVar3))

    break;

    bVar1 = *(byte *)(uVar5 + 5 + unaff_EDI);

    bVar2 = *(byte *)(uVar7 + 5 + unaff_EDI);

    bVar8 = bVar2 < bVar1;

    if ((bVar2 != bVar1) ||

       (uVar3 = *(ushort *)(param_2 + (uVar5 + 5) * 2),

       uVar4 = *(ushort *)(param_2 + (uVar7 + 5) * 2), bVar8 = uVar4 < uVar3, uVar4 != uVar3))

    break;

    bVar1 = *(byte *)(uVar5 + 6 + unaff_EDI);

    bVar2 = *(byte *)(uVar7 + 6 + unaff_EDI);

    bVar8 = bVar2 < bVar1;

    if ((bVar2 != bVar1) ||

       (uVar3 = *(ushort *)(param_2 + (uVar5 + 6) * 2),

       uVar4 = *(ushort *)(param_2 + (uVar7 + 6) * 2), bVar8 = uVar4 < uVar3, uVar4 != uVar3))

    break;

    bVar1 = *(byte *)(uVar5 + 7 + unaff_EDI);

    bVar2 = *(byte *)(uVar7 + 7 + unaff_EDI);

    bVar8 = bVar2 < bVar1;

    if ((bVar2 != bVar1) ||

       (uVar3 = *(ushort *)(param_2 + (uVar5 + 7) * 2),

       uVar4 = *(ushort *)(param_2 + (uVar7 + 7) * 2), bVar8 = uVar4 < uVar3, uVar4 != uVar3))

    break;

    uVar5 = uVar5 + 8;

    uVar7 = uVar7 + 8;

    if (param_3 <= uVar5) {

      uVar5 = uVar5 - param_3;

    }

    if (param_3 <= uVar7) {

      uVar7 = uVar7 - param_3;

    }

    *param_4 = *param_4 + -1;

    iVar6 = iVar6 + -8;

    if (iVar6 < 0) {

      return uVar5 & 0xffffff00;

    }

  }

  return (uint)bVar8;

}
