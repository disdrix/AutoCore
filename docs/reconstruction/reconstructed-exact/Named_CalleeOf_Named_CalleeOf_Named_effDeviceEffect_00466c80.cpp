// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00466c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00466c80
// Callee of Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00466c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00446f30, FUN_00456960, FUN_0045f220, FUN_00466c80, _ltoa, _strdup.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_effDeviceEffect
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

void Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00466c80(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_50;

  char *local_4c;

  char local_48 [68];

  

  iVar3 = 0;

  do {

    local_50 = *(uint32_t /* width from decompiler */ *)(param_2 + 4 + iVar3 * 8);

    _ltoa(*(long *)(param_2 + iVar3 * 8),local_48,10);

    local_4c = _strdup(local_48);

    iVar1 = *(int *)(unaff_EDI + 4);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(unaff_EDI + 0xc) - iVar1 >> 2) <=

        (uint)(*(int *)(unaff_EDI + 8) - iVar1 >> 2))) {

      FUN_00456960(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8));

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 8);

      *puVar2 = local_4c;

      *(uint32_t /* width from decompiler */ **)(unaff_EDI + 8) = puVar2 + 1;

    }

    iVar1 = *(int *)(param_1 + 4);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(param_1 + 0xc) - iVar1 >> 3) <= (uint)(*(int *)(param_1 + 8) - iVar1 >> 3)))

    {

      FUN_00446f30(*(uint32_t /* width from decompiler */ *)(param_1 + 8),&local_50);

    }

    else {

      iVar1 = *(int *)(param_1 + 8);

      FUN_0045f220(local_50);

      *(int *)(param_1 + 8) = iVar1 + 8;

    }

    iVar3 = iVar3 + 1;

  } while (iVar3 < 10);

  return;

}
