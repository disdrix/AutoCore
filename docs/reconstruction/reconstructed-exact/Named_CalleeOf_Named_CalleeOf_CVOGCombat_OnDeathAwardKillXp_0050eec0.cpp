// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_0050eec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0050eec0
// Callee of Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp
// Address:   0x0050eec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_0050e830, FUN_0050eec0, InitializeCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_0050eec0(int param_1,uint param_2)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  uVar1 = *(uint *)(param_1 + 8);

  puVar3 = operator_new(0x2c);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009cdb14;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(uint8_t *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

  }

  for (iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (uVar1 & param_2) * 4) + 4); iVar2 != 0;

      iVar2 = *(int *)(iVar2 + 0xc)) {

    if ((param_2 == *(uint *)(iVar2 + 0x10)) && (*(int *)(iVar2 + 8) != 0)) {

      FUN_0050e830(*(int *)(iVar2 + 8));

    }

  }

  return puVar3;

}
