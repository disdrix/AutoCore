// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00651b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00651b10
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x00651b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005071c0, FUN_005072d0, FUN_00651b10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00651b10(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (param_2 != 0) {

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

    FUN_005072d0(param_1);

  }

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_005071c0(param_1);

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

  }

  *(int *)(param_1 + 0xc) = param_2;

  return;

}
