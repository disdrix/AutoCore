// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00685db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00685db0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00685db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00685db0.
//  - Return sites: 1.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00685db0(int param_1)



{

  float fVar1;

  float fVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if ((*(int *)(param_1 + 0x4c) != 0) && (*(char *)(param_1 + 0x69) != '\0')) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x40);

    fVar1 = (float)puVar3[5];

    fVar2 = (float)puVar3[2];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = puVar3[3];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = puVar3[4];

    fVar1 = (fVar1 + fVar2) * DAT_00a0f298;

    *(float *)(param_1 + 0x74) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = *puVar3;

    uVar4 = puVar3[4];

    *(float *)(param_1 + 0x80) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = *puVar3;

    uVar4 = puVar3[1];

    *(float *)(param_1 + 0x8c) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = puVar3[3];

    uVar4 = puVar3[1];

    *(float *)(param_1 + 0x98) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = uVar4;

  }

  return;

}
