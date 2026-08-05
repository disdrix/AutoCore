// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostC_00513200
// -----------------------------------------------------------------------------
// Stable ID: aa_00513200
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostCreateFromPacket
// Address:   0x00513200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_00513200, FUN_00588450.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostCreateFromPacket
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostC_00513200(int *param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  

  iVar1 = (**(code **)(*param_1 + 0x25c))();

  if (iVar1 < 1) {

    (**(code **)(*param_1 + 0x260))(1);

  }

  if (*(byte *)(param_2 + 0xa7) != 0) {

    param_1[0x5f] = param_1[0x5f] ^ ((uint)*(byte *)(param_2 + 0xa7) * 4 ^ param_1[0x5f]) & 4;

    return;

  }

  if ((*(uint *)(param_2 + 8) & *(uint *)(param_2 + 0xc)) != 0xffffffff) {

    piVar3 = param_1;

    uVar2 = CVOGReaction_ResolveObjectTarget(0,*(uint *)(param_2 + 8),*(uint *)(param_2 + 0xc));

    FUN_00588450(uVar2,piVar3);

    (**(code **)(*param_1 + 0x260))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x84));

  }

  return;

}
