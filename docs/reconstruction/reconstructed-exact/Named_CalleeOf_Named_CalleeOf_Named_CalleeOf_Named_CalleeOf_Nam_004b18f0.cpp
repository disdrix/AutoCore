// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b18f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b18f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004b18f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004b18f0, FUN_004cd220, FUN_006a3db0, FUN_00973690, FUN_00973820.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b18f0(int param_1,int param_2)



{

  int iVar1;

  uint8_t uVar2;

  float10 fVar3;

  float fVar4;

  

  if (param_2 != 0) {

    FUN_00973820(&DAT_00aef980);

    FUN_00973690(0x3f400000,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x34),DAT_00afdef0);

    uVar2 = FUN_006a3db0();

    *(uint8_t *)(*(int *)(param_1 + 8) + 0x37) = uVar2;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

    fVar3 = (float10)FUN_004cd220(*(uint32_t /* width from decompiler */ *)(param_1 + 0x178),*(uint32_t /* width from decompiler */ *)(param_1 + 0x180))

    ;

    fVar4 = *(float *)(param_1 + 0x17c);

    iVar1 = *(int *)(param_1 + 8);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x178) = DAT_00b03530;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x17c) = DAT_00b03534;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x180) = DAT_00b03538;

    iVar1 = *(int *)(param_1 + 8);

    fVar4 = 0.0 - (float)((float10)fVar4 - fVar3) / *(float *)(iVar1 + 0x17c);

    *(float *)(iVar1 + 0x178) = *(float *)(iVar1 + 0x178) * fVar4;

    *(float *)(iVar1 + 0x17c) = *(float *)(iVar1 + 0x17c) * fVar4;

    *(float *)(iVar1 + 0x180) = *(float *)(iVar1 + 0x180) * fVar4;

    iVar1 = *(int *)(param_1 + 8);

    *(float *)(iVar1 + 0x178) = *(float *)(param_1 + 0x178) + *(float *)(iVar1 + 0x178);

    *(float *)(iVar1 + 0x17c) = *(float *)(param_1 + 0x17c) + *(float *)(iVar1 + 0x17c);

    *(float *)(iVar1 + 0x180) = *(float *)(param_1 + 0x180) + *(float *)(iVar1 + 0x180);

    *(float *)(*(int *)(param_1 + 8) + 0x17c) =

         *(float *)(*(int *)(param_1 + 8) + 0x17c) + DAT_00aaa8f4;

  }

  return;

}
