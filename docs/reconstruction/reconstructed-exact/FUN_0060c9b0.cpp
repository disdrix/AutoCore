// =============================================================================
// FUN_0060c9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0060c9b0
// Address:   0x0060c9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060c9b0 @ 0x0060c9b0
// Stable ID: aa_0060c9b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_004d0e90, FUN_0060c9b0, Object_ResolveFromTFID, __RTDynamicCast.
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

uint32_t /* width from decompiler */ FUN_0060c9b0(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  

  if (param_1[7] != 0xb) {

    return 0;

  }

  iVar1 = *param_2;

  iVar2 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,

                          &CVOGHBMissionEscort::RTTI_Type_Descriptor,0);

  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x28) == *(int *)(*(int *)(iVar1 + 4) + 0x10))) {

    if (((*(uint *)(iVar2 + 0x38) & *(uint *)(iVar2 + 0x3c)) != 0xffffffff) ||

       (*(char *)(iVar2 + 0x40) != '\0')) {

      pvVar3 = Object_ResolveFromTFID((TFID_16 *)(iVar2 + 0x38));

      if (pvVar3 != (void *)0x0) {

        (**(code **)(*param_1 + 0x18))(0,1);

        if ((char)param_2[2] != '\0') {

          *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xcc) = 1;

          FUN_004d0e90(pvVar3);

        }

      }

    }

    return 1;

  }

  return 0;

}
