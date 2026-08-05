// =============================================================================
// FUN_007fd850
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd850
// Address:   0x007fd850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd850 @ 0x007fd850
// Stable ID: aa_007fd850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: CNDHash_LookupByKey, FUN_007fb690, FUN_007fd850, __RTDynamicCast.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_007fd850(uint param_1,int param_2)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  int unaff_EDI;

  

  pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_EDI + 0xe98) + 0x548),param_1);

  if (pvVar2 != (void *)0x0) {

    if (*(int *)((int)pvVar2 + 0x158) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)((int)pvVar2 + 0x15c) - *(int *)((int)pvVar2 + 0x158) >> 2;

    }

    if (param_2 < iVar3) {

      piVar1 = *(int **)(*(int *)((int)pvVar2 + 0x158) + param_2 * 4);

      iVar3 = (**(code **)(*piVar1 + 0x50))();

      if (iVar3 == 0xc) {

        iVar3 = __RTDynamicCast(piVar1,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                &CVOGObjectiveRequirement_UseItem::RTTI_Type_Descriptor,0);

        if (iVar3 != 0) {

          *(uint *)(unaff_EDI + 0x3c20) = param_1;

          *(int *)(unaff_EDI + 0x3c24) = param_2;

          FUN_007fb690(0,(float)*(int *)(iVar3 + 0x34),0,*(uint32_t /* width from decompiler */ *)(iVar3 + 0x38),DAT_00afdef4,

                       DAT_00afdef0,0,0);

          return 1;

        }

      }

      return 0;

    }

  }

  return 0;

}
