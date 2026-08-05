// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00651bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00651bb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x00651bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_005071c0×2, FUN_005072d0×2, FUN_00651bb0.
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00651bb0(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009e3a68;

  *param_1 = &PTR_FUN_009e3a90;

  param_1[2] = &PTR_LAB_009e3a7c;

  param_1[5] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  iVar1 = *param_2;

  if (iVar1 != 0) {

    *(short *)(iVar1 + 6) = *(short *)(iVar1 + 6) + 1;

    FUN_005072d0(param_1);

  }

  if (param_1[3] != 0) {

    FUN_005071c0(param_1);

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[3];

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

  }

  param_1[3] = iVar1;

  iVar1 = param_2[1];

  if (iVar1 != 0) {

    *(short *)(iVar1 + 6) = *(short *)(iVar1 + 6) + 1;

    FUN_005072d0(param_1);

  }

  if (param_1[4] != 0) {

    FUN_005071c0(param_1);

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[4];

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

  }

  param_1[4] = iVar1;

  param_1[6] = param_2[2];

  return param_1;

}
