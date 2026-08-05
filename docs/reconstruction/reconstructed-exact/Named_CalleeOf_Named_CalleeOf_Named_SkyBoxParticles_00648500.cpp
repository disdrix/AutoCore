// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_00648500
// -----------------------------------------------------------------------------
// Stable ID: aa_00648500
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x00648500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00648500.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_00648500(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  

  *param_1 = &PTR_FUN_009e4750;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0x80000000;

  uVar1 = param_1[4] & 0x7fffffff;

  if ((int)uVar1 < param_2[1]) {

    if (-1 < (int)param_1[4]) {

      (**(code **)(*DAT_00b05060 + 0x14))(param_1[2],uVar1 * 4,0x12);

    }

    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[1] * 4,0x12);

    param_1[2] = uVar2;

    param_1[4] = param_2[1];

  }

  puVar3 = (uint32_t /* width from decompiler */ *)param_1[2];

  param_1[3] = param_2[1];

  iVar5 = param_2[1];

  if (0 < iVar5) {

    iVar4 = *param_2 - (int)puVar3;

    do {

      *puVar3 = *(uint32_t /* width from decompiler */ *)(iVar4 + (int)puVar3);

      puVar3 = puVar3 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  return param_1;

}
