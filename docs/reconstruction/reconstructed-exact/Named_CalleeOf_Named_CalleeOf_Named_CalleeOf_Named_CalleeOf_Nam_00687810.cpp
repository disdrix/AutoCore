// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687810
// -----------------------------------------------------------------------------
// Stable ID: aa_00687810
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00687810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_00687810.
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00687810(int *param_1)



{

  float fVar1;

  void *pvVar2;

  int iVar3;

  uint uVar4;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a9f62;

  local_10 = ExceptionList;

  local_8 = 0;

  if (param_1[0xb] == 0) {

    uVar4 = (uint)*(ushort *)(*param_1 + 0xb4);

    ExceptionList = &local_10;

    pvVar2 = operator_new__(uVar4 * 4);

    param_1[0xb] = (int)pvVar2;

    iVar3 = 0;

    while (iVar3 < (int)uVar4) {

      if (uVar4 == 0) {

        *(float *)(param_1[0xb] + iVar3 * 4) = g_flOne;

        iVar3 = iVar3 + 1;

      }

      else {

        fVar1 = (float)iVar3;

        iVar3 = iVar3 + 1;

        *(float *)(param_1[0xb] + -4 + iVar3 * 4) = fVar1 * (float)param_1[9] + g_flOne;

      }

    }

  }

  ExceptionList = local_10;

  return param_1[0xb];

}
