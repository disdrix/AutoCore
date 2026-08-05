// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068e950
// -----------------------------------------------------------------------------
// Stable ID: aa_0068e950
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068e950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00685ec0, FUN_0068e950.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068e950(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  float fVar2;

  char cVar3;

  int iVar4;

  

  if ((*(int *)(param_1 + 0x14) != 0) && (param_3 != (uint32_t /* width from decompiler */ *)0x0)) {

    cVar3 = FUN_00685ec0();

    fVar2 = g_flOne;

    if (cVar3 != '\0') {

      fVar2 = DAT_00aaa668;

    }

    iVar4 = *(int *)(param_1 + 0x14);

    param_2 = param_2 * 0x40;

    *(uint32_t /* width from decompiler */ *)(iVar4 + param_2) = *param_3;

    iVar4 = iVar4 + param_2;

    *(float *)(iVar4 + 4) = fVar2 * (float)param_3[1];

    *(uint32_t /* width from decompiler */ *)(iVar4 + 8) = param_3[2];

    *(float *)(iVar4 + 0xc) = fVar2 * (float)param_3[3];

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = param_3[4];

    *(float *)(iVar4 + 0x14) = fVar2 * (float)param_3[5];

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x18) = param_3[6];

    *(float *)(iVar4 + 0x1c) = fVar2 * (float)param_3[7];

    puVar1 = (uint32_t /* width from decompiler */ *)(param_2 + 0x20 + *(int *)(param_1 + 0x14));

    *puVar1 = param_3[2];

    puVar1[1] = fVar2 * (float)param_3[1];

    puVar1[2] = *param_3;

    puVar1[3] = fVar2 * (float)param_3[3];

    puVar1[4] = param_3[6];

    puVar1[5] = fVar2 * (float)param_3[5];

    puVar1[6] = param_3[4];

    puVar1[7] = fVar2 * (float)param_3[7];

  }

  return;

}
