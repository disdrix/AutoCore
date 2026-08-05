// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxView_00969d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00969d10
// Callee of Named_CalleeOf_Named_gfxView
// Address:   0x00969d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: for×3, if×2, return×1.
//  - Notable callees: FUN_00969d10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxView
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

void __fastcall

Named_CalleeOf_Named_CalleeOf_Named_gfxView_00969d10(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ *param_5)



{

  int *piVar1;

  int iVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (*(int *)(unaff_EBX + 4) != 0) {

    piVar1 = *(int **)(*(int *)(unaff_EBX + 4) + 0xc);

    (**(code **)(*piVar1 + 0x50))(piVar1,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),param_2,0xffffffff);

  }

  puVar3 = param_3;

  puVar4 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x30);

  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x70);

  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = *param_4;

    param_4 = param_4 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0xb0);

  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = *param_5;

    param_5 = param_5 + 1;

    puVar3 = puVar3 + 1;

  }

  iVar2 = *(int *)(unaff_EBX + 4);

  if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) {

    (**(code **)(**(int **)(iVar2 + 0xc) + 0x98))

              (*(int **)(iVar2 + 0xc),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18),

               (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x30));

    piVar1 = *(int **)(*(int *)(unaff_EBX + 4) + 0xc);

    (**(code **)(*piVar1 + 0x98))

              (piVar1,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1c),(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x70));

    piVar1 = *(int **)(*(int *)(unaff_EBX + 4) + 0xc);

    (**(code **)(*piVar1 + 0x98))(piVar1,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x20),unaff_EBX + 0xb0);

  }

  piVar1 = (int *)*DAT_00d1f044;

  (**(code **)(*piVar1 + 0xb0))(piVar1,2,param_3);

  (**(code **)(*piVar1 + 0xb0))(piVar1,3,unaff_EBP);

  *(uint8_t *)(unaff_EBX + 0xf0) = 1;

  *(uint8_t *)(unaff_EBX + 0x118) = 1;

  return;

}
