// =============================================================================
// FUN_007fcfc0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fcfc0
// Address:   0x007fcfc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fcfc0 @ 0x007fcfc0
// Stable ID: aa_007fcfc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: CNDHash_LookupByKey, FUN_007fb690, FUN_007fcfc0, __RTDynamicCast.
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

uint32_t /* width from decompiler */ __fastcall FUN_007fcfc0(int param_1)



{

  int *piVar1;

  uint in_EAX;

  void *pvVar2;

  int iVar3;

  int unaff_EDI;

  

  pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_EDI + 0xe98) + 0x548),in_EAX);

  if (pvVar2 != (void *)0x0) {

    if (*(int *)((int)pvVar2 + 0x158) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)((int)pvVar2 + 0x15c) - *(int *)((int)pvVar2 + 0x158) >> 2;

    }

    if (param_1 < iVar3) {

      piVar1 = *(int **)(*(int *)((int)pvVar2 + 0x158) + param_1 * 4);

      iVar3 = (**(code **)(*piVar1 + 0x50))();

      if (iVar3 == 0xc) {

        iVar3 = __RTDynamicCast(piVar1,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                &CVOGObjectiveRequirement_TimePlayed::RTTI_Type_Descriptor,0);

        if (iVar3 != 0) {

          FUN_007fb690(0,(float)*(int *)(iVar3 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x18),0,DAT_00afdf0c,

                       0,0,0);

          return 1;

        }

      }

    }

  }

  return 0;

}
