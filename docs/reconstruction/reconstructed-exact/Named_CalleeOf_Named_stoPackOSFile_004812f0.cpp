// =============================================================================
// Named_CalleeOf_Named_stoPackOSFile_004812f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004812f0
// Callee of Named_stoPackOSFile
// Address:   0x004812f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_stoPackOSFile: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: while×1, for×1, return×1.
//  - Notable callees: FUN_004812f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_stoPackOSFile
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

void Named_CalleeOf_Named_stoPackOSFile_004812f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int in_EAX;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

  puVar2 = param_2;

  puVar3 = param_2;

  while (puVar3 = puVar3 + 7, puVar3 != puVar1) {

    puVar5 = puVar2 + 7;

    puVar6 = puVar3;

    puVar7 = puVar2;

    for (iVar4 = 7; puVar2 = puVar5, iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

  }

  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x1c;

  *param_1 = param_2;

  return;

}
