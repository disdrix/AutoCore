// =============================================================================
// Named_CalleeOf_Mission_No_Objective_0078be40
// -----------------------------------------------------------------------------
// Stable ID: aa_0078be40
// Callee of Mission_No_Objective
// Address:   0x0078be40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_No_Objective: mission/objective helper. Evidence string: "Direction". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Direction"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0078be40.
//  - Strings: "Direction".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_No_Objective
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

void __fastcall Named_CalleeOf_Mission_No_Objective_0078be40(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  

  if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x490) = *in_EAX;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x494) = in_EAX[1];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x498) = in_EAX[2];

  }

  iVar1 = *(int *)(param_1 + 0x2ac);

  if (iVar1 != 0) {

    uVar2 = (**(code **)(**(int **)(iVar1 + 0x8c) + 0x40))("Direction");

    (**(code **)(**(int **)(iVar1 + 0x8c) + 0x50))(uVar2,param_1 + 0x490);

  }

  return;

}
