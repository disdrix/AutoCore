// =============================================================================
// FUN_004d2700
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2700
// Address:   0x004d2700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2700 @ 0x004d2700
// Stable ID: aa_004d2700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_004d0250, FUN_004d2700, __RTDynamicCast.
//  - Return sites: 1.

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

void FUN_004d2700(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  TypeDescriptor *pTVar4;

  TypeDescriptor *pTVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  uVar6 = 0;

  pTVar5 = &CVOGTrigger::RTTI_Type_Descriptor;

  pTVar4 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

  uVar3 = 0;

  uVar1 = CVOGReaction_ResolveObjectTarget(0,param_3,param_4);

  iVar2 = __RTDynamicCast(uVar1,uVar3,pTVar4,pTVar5,uVar6);

  if (iVar2 != 0) {

    FUN_004d0250(iVar2,param_1);

  }

  return;

}
