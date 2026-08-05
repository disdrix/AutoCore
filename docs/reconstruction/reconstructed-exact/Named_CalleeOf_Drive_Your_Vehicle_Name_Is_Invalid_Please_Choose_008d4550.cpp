// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d4550
// -----------------------------------------------------------------------------
// Stable ID: aa_008d4550
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d4550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×4, block×2, FUN_004faaf0, FUN_004fab40, FUN_004fcb50, FUN_004fcd80, FUN_004fd970, FUN_008cfa00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
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

/* WARNING: Removing unreachable block (ram,0x008d4617) */

/* WARNING: Removing unreachable block (ram,0x008d4656) */



void Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d4550(void)



{

  ushort uVar1;

  int iVar2;

  uint uVar3;

  int unaff_ESI;

  

  if ((*(int *)(unaff_ESI + 0x548) != 0) && (*(int *)(*(int *)(unaff_ESI + 0x548) + 0x48) != 0)) {

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    uVar3 = FUN_004fcb50();

    FUN_004fd970((int)((ulonglong)uVar1 % (ulonglong)(longlong)(int)((uVar3 & 0xff) + 1)));

    if (*(int *)(unaff_ESI + 0x588) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      *(int *)(unaff_ESI + 0x590) =

           (int)((longlong)(ulonglong)uVar1 % (longlong)*(int *)(unaff_ESI + 0x588));

      FUN_008d37d0(unaff_ESI);

    }

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    FUN_004faaf0((&DAT_00a1e2e8)[uVar1 & 0x8000003f]);

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    FUN_004fab40((&DAT_00a1e2e8)[uVar1 & 0x8000003f]);

    FUN_004fcd80(0);

    FUN_008cfa00(unaff_ESI);

  }

  return;

}
