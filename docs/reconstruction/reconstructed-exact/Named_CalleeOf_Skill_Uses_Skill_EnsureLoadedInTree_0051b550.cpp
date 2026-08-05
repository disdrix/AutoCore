// =============================================================================
// Named_CalleeOf_Skill_Uses_Skill_EnsureLoadedInTree_0051b550
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b550
// Callee of Skill_Uses_Skill_EnsureLoadedInTree
// Address:   0x0051b550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Uses_Skill_EnsureLoadedInTree: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: Skill_EnsureLoadedInTree×3, FUN_00518e30, FUN_0051b550.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Uses_Skill_EnsureLoadedInTree
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

void __fastcall Named_CalleeOf_Skill_Uses_Skill_EnsureLoadedInTree_0051b550(int *param_1)



{

  int iVar1;

  byte bVar2;

  

  FUN_00518e30(1);

  iVar1 = *(int *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3bc);

  bVar2 = (**(code **)(*param_1 + 0x264))();

  Skill_EnsureLoadedInTree(param_1,iVar1,(ushort)bVar2);

  iVar1 = *(int *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3c0);

  bVar2 = (**(code **)(*param_1 + 0x268))();

  Skill_EnsureLoadedInTree(param_1,iVar1,(ushort)bVar2);

  iVar1 = *(int *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3c4);

  bVar2 = (**(code **)(*param_1 + 0x26c))();

  Skill_EnsureLoadedInTree(param_1,iVar1,(ushort)bVar2);

  return;

}
