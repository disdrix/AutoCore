// =============================================================================
// Named_CalleeOf_Client_QuickBar_ActivateSlot_008a0ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0ed0
// Callee of Client_QuickBar_ActivateSlot (+1 other named callers)
// Address:   0x008a0ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_QuickBar_ActivateSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_QuickBar_ActivateSlot (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_00826780×2, FUN_008a0210, FUN_008a0e10, FUN_008a0ed0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_QuickBar_ActivateSlot (+1 other named callers)
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

void __fastcall Named_CalleeOf_Client_QuickBar_ActivateSlot_008a0ed0(int *param_1)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  

  if ((-1 < in_EAX) && (in_EAX < 10)) {

    param_1[0x143] = in_EAX;

    iVar1 = *(int *)(&DAT_00d1da38 + in_EAX * 4);

    piVar2 = param_1 + 399;

    iVar3 = 10;

    do {

      if ((*piVar2 != 0) &&

         (*(int *)(*piVar2 + 0x504) = param_1[0x143], *(char *)(*piVar2 + 0x4fc) != '\0')) {

        FUN_00826780(0);

      }

      piVar2 = piVar2 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    FUN_008a0e10(param_1);

    (**(code **)(*param_1 + 0x448))();

    if ((((iVar1 < 0) || (9 < iVar1)) || (iVar1 = param_1[iVar1 + 399], iVar1 == 0)) ||

       ((*(uint *)(iVar1 + 0x550) & *(uint *)(iVar1 + 0x554)) == 0xffffffff)) {

      FUN_008a0210(1);

    }

    else {

      FUN_00826780(1);

    }

    if (-1 < DAT_00d1a9fc) {

      if (param_1[DAT_00d1a9fc + 399] != 0) {

        (**(code **)(*(int *)param_1[DAT_00d1a9fc + 399] + 0x44c))(0);

      }

      DAT_00d1a9fc = -1;

    }

                    /* WARNING: Could not recover jumptable at 0x008a0fa7. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x34c))();

    return;

  }

  return;

}
