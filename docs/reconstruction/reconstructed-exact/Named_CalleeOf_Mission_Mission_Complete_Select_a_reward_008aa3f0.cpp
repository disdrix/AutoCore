// =============================================================================
// Named_CalleeOf_Mission_Mission_Complete_Select_a_reward_008aa3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa3f0
// Callee of Mission_Mission_Complete_Select_a_reward
// Address:   0x008aa3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Mission_Complete_Select_a_reward: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, if×1, return×1.
//  - Notable callees: FUN_008aa3f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Mission_Complete_Select_a_reward
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

void Named_CalleeOf_Mission_Mission_Complete_Select_a_reward_008aa3f0(int param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x578) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x558 + param_1 * 8);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x57c) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x55c + param_1 * 8);

  puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x698);

  iVar1 = 4;

  do {

    (**(code **)(*(int *)*puVar2 + 0x158))(0,in_EAX + 0x594);

    (**(code **)(*(int *)*puVar2 + 0x34c))();

    puVar2 = puVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  (**(code **)(**(int **)(in_EAX + 0x698 + param_1 * 4) + 0x158))(0,in_EAX + 0x5a4);

  (**(code **)(**(int **)(in_EAX + 0x698 + param_1 * 4) + 0x34c))();

  if (*(int **)(in_EAX + 0x708) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x708) + 0x308))(&DAT_00a1419b);

  }

  return;

}
