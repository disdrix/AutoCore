// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt_005531d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005531d0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect
// Address:   0x005531d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004c4140, FUN_004ceba0, FUN_005531d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt_005531d0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  short sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0.0;

  if (param_2 != (int *)0x0) {

    iVar2 = (**(code **)(*param_2 + 0x214))();

    if (iVar2 != 0) {

      (**(code **)(*param_2 + 0x214))();

      sVar1 = FUN_004c4140();

      local_4 = (float)(int)sVar1;

    }

  }

  FUN_004ceba0(local_4,0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),param_2,param_3,param_4);

  return;

}
