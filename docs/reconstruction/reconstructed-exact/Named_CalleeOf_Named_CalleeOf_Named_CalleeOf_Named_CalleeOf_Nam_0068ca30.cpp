// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ca30
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ca30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068ca30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005971e0×2, FUN_004490a0, FUN_00685ec0, FUN_0068ca30.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ca30(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  

  puVar3 = param_2;

  iVar1 = *(int *)(param_1 + 0xe4);

  if ((iVar1 == 0) ||

     ((uint)(*(int *)(param_1 + 0xec) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0xe8) - iVar1 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe8),1,param_2);

  }

  else {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe8);

    *puVar2 = *param_2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xe8) = puVar2 + 1;

  }

  cVar4 = FUN_00685ec0();

  if (cVar4 != '\0') {

    param_2 = (uint32_t /* width from decompiler */ *)-(float)puVar3[1];

    FUN_005971e0(&param_2);

    return;

  }

  FUN_005971e0(puVar3 + 1);

  return;

}
