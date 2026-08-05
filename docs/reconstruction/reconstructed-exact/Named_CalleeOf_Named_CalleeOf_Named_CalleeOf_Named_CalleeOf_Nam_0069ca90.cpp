// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069ca90
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ca90
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069ca90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: rand×5, FUN_0069c310, FUN_0069ca90.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069ca90(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int local_24;

  float local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  float local_c;

  uint32_t /* width from decompiler */ local_8;

  float local_4;

  

  fVar6 = DAT_00af55b4;

  if (*(int *)(param_1 + 0x28) != 0) {

    iVar7 = rand();

    fVar4 = (float)iVar7 * _DAT_009eb468;

    local_24 = 0;

    fVar5 = DAT_00af55b4 / (float)*(int *)(param_1 + 0x28);

    if (0 < *(int *)(param_1 + 0x28)) {

      do {

        fVar1 = fVar5 * *(float *)(param_1 + 0x2c);

        iVar7 = rand();

        local_18 = ((fVar5 - fVar1) * (float)iVar7 * _DAT_009eb468 + fVar1) * (float)local_24 +

                   fVar4 * fVar6;

        if (DAT_00af55b4 < local_18) {

          local_18 = local_18 - DAT_00af55b4;

        }

        fVar1 = *(float *)(param_1 + 0x30);

        local_10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

        fVar2 = *(float *)(param_1 + 0x34);

        local_8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

        fVar3 = *(float *)(param_1 + 0x30) - *(float *)(param_1 + 0x34);

        iVar7 = rand();

        local_14 = (((fVar1 + fVar2) - fVar3) * (float)iVar7 * _DAT_009eb468 + fVar3) * DAT_009d9908

        ;

        fVar1 = *(float *)(param_1 + 0x44);

        fVar2 = *(float *)(param_1 + 0x48);

        fVar3 = *(float *)(param_1 + 0x44) - *(float *)(param_1 + 0x48);

        iVar7 = rand();

        local_c = ((fVar1 + fVar2) - fVar3) * (float)iVar7 * _DAT_009eb468 + fVar3;

        fVar1 = *(float *)(param_1 + 0x3c);

        fVar2 = *(float *)(param_1 + 0x40);

        fVar3 = *(float *)(param_1 + 0x3c) - *(float *)(param_1 + 0x40);

        iVar7 = rand();

        local_4 = ((fVar1 + fVar2) - fVar3) * (float)iVar7 * _DAT_009eb468 + fVar3;

        FUN_0069c310(&local_18);

        local_24 = local_24 + 1;

      } while (local_24 < *(int *)(param_1 + 0x28));

    }

  }

  return;

}
