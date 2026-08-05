// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005b8500
// -----------------------------------------------------------------------------
// Stable ID: aa_005b8500
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x005b8500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper. Evidence string: "Failed to find parameter %d for event %d.". Supports parent flow (not a free-standing entry point). Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Embedded strings (evidence):
//   - "Failed to find parameter %d for event %d."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, for×1.
//  - Notable callees: FUN_005b8500, FUN_007a4480, Map_LowerBoundFindByIntKey.
//  - Strings: "Failed to find parameter %d for event %d.".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005b8500(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *pOutIt;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *unaff_EDI;

  

  iVar4 = param_2;

  pOutIt = (uint32_t /* width from decompiler */ *)(param_1 + 8);

  Map_LowerBoundFindByIntKey((void *)(param_2 + 0x224),&param_2,pOutIt,unaff_EDI);

  iVar5 = param_2;

  if (param_2 == *(int *)(iVar4 + 0x228)) {

    FUN_007a4480(0,"Failed to find parameter %d for event %d.",*pOutIt,*(uint32_t /* width from decompiler */ *)(iVar4 + 0x28)

                );

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  puVar6 = operator_new(0x1c);

  if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    uVar2 = *pOutIt;

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    *puVar6 = 0;

    puVar6[1] = 0;

    puVar6[2] = uVar2;

    puVar6[3] = 0;

    puVar6[5] = uVar3;

    puVar6[4] = param_3;

    puVar6[6] = uVar1;

    puVar6[3] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10);

    return puVar6;

  }

  uRam0000000c = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10);

  return (uint32_t /* width from decompiler */ *)0x0;

}
