// =============================================================================
// Named_CalleeOf_CVOGSectorMap_AddCharacter_00521310
// -----------------------------------------------------------------------------
// Stable ID: aa_00521310
// Callee of CVOGSectorMap_AddCharacter (+1 other named callers)
// Address:   0x00521310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSectorMap_AddCharacter: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGSectorMap_AddCharacter (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: CVOGSectorMap_AddCharacter, FUN_004962b0, FUN_004bafe0, FUN_004c49d0, FUN_00521310, FUN_0053d970, FUN_005c93f0, FUN_00760fe0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGSectorMap_AddCharacter (+1 other named callers)
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

void __thiscall

Named_CalleeOf_CVOGSectorMap_AddCharacter_00521310(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  

  if ((char)param_7 != '\0') {

    FUN_005c93f0(param_2,param_3,param_4,param_5,param_6,param_7);

  }

  iVar1 = FUN_004bafe0(*(uint8_t *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xc34 + param_1),

                       *(uint32_t /* width from decompiler */ *)(param_1 + -0xb90),*(uint32_t /* width from decompiler */ *)(param_1 + -0xb8c));

  FUN_004c49d0(iVar1);

  if (iVar1 != 0) {

    FUN_0053d970(0);

    *(bool *)(iVar1 + 0x101) = *(char *)(param_1 + -0xa94) == '\0';

  }

  CVOGSectorMap_AddCharacter(param_1 + -0xda0);

  if (((*param_2 == 0x2016) && (*(int *)(param_1 + -0xd58) != 0)) &&

     (iVar1 = *(int *)(*(int *)(param_1 + -0xd58) + 0x94), iVar1 != 0)) {

    iVar1 = __RTDynamicCast(iVar1,0,&gfxLODHandler::RTTI_Type_Descriptor,

                            &gfxLODHandler_AutoAssault::RTTI_Type_Descriptor,0);

    if (iVar1 != 0) {

      FUN_00760fe0(0,0x4479c000);

    }

  }

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcf8 + param_1);

  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xe898) != 0)) {

    FUN_004962b0();

  }

  return;

}
