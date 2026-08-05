// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069e730
// -----------------------------------------------------------------------------
// Stable ID: aa_0069e730
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069e730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×4, do×4, while×4, for×1, return×1.
//  - Notable callees: FUN_0056f570, FUN_0069e730, FUN_006a1be0, FUN_006a1cd0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069e730(int param_1,int param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float10 fVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aaed8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(int *)(param_1 + 0x34) = param_2;

  pvVar1 = operator_new__(*(int *)(param_1 + 0x2c) << 2);

  *(void **)(param_1 + 0x40) = pvVar1;

  FUN_006a1cd0();

  iVar5 = 0;

  local_4 = 0;

  if (0 < *(int *)(param_1 + 0x2c)) {

    do {

      fVar7 = (float10)FUN_006a1be0(0,0x461c4000);

      *(float *)(*(int *)(param_1 + 0x40) + iVar5 * 4) = (float)fVar7;

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0x2c));

  }

  puVar2 = operator_new__(param_2 << 6);

  iVar5 = param_2 * 2;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) = puVar2;

  if (0 < iVar5) {

    do {

      *puVar2 = 0;

      puVar2[1] = 0x3f800000;

      puVar2[2] = 0x3f800000;

      puVar2[3] = 0x3f800000;

      puVar2[4] = 0x3f800000;

      puVar2[5] = 0;

      puVar2[6] = 0;

      puVar2[7] = 0;

      puVar2 = puVar2 + 8;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  pvVar1 = operator_new__(*(int *)(param_1 + 0x30) << 2);

  iVar5 = *(int *)(param_1 + 0x2c) * param_2;

  *(void **)(param_1 + 0x38) = pvVar1;

  iVar4 = iVar5 * 0x20;

  param_2 = 0;

  if (0 < *(int *)(param_1 + 0x30)) {

    iVar6 = 0;

    do {

      pvVar1 = operator_new__(iVar5 * 0x80);

      *(void **)(iVar6 + *(int *)(param_1 + 0x38)) = pvVar1;

      iVar3 = 0;

      if (3 < iVar4) {

        do {

          *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + *(int *)(param_1 + 0x38)) + iVar3 * 4) = 0;

          *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + *(int *)(param_1 + 0x38)) + 4 + iVar3 * 4) = 0;

          *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + *(int *)(param_1 + 0x38)) + 8 + iVar3 * 4) = 0;

          *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + *(int *)(param_1 + 0x38)) + 0xc + iVar3 * 4) = 0;

          iVar3 = iVar3 + 4;

        } while (iVar3 < iVar4 + -3);

      }

      for (; iVar3 < iVar4; iVar3 = iVar3 + 1) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + *(int *)(param_1 + 0x38)) + iVar3 * 4) = 0;

      }

      param_2 = param_2 + 1;

      iVar6 = iVar6 + 4;

    } while (param_2 < *(int *)(param_1 + 0x30));

  }

  local_4 = 0xffffffff;

  FUN_0056f570();

  ExceptionList = local_c;

  return;

}
