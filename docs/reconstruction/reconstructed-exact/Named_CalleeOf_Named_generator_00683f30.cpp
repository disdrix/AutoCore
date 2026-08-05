// =============================================================================
// Named_CalleeOf_Named_generator_00683f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00683f30
// Callee of Named_generator
// Address:   0x00683f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00681020×2, FUN_00683f30.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_generator
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_generator_00683f30(int *param_1)



{

  char cVar1;

  uint uVar2;

  void *pvVar3;

  int unaff_EDI;

  uint auStack_8 [2];

  

  uVar2 = (**(code **)(*param_1 + 0x4c))();

  auStack_8[0] = uVar2;

  if ((uint)param_1[0x32] < uVar2) {

    param_1[0x32] = uVar2;

    operator_delete__((void *)param_1[0x31]);

    pvVar3 = operator_new__(uVar2);

    param_1[0x31] = (int)pvVar3;

  }

  if (auStack_8[0] != 0) {

    cVar1 = (**(code **)(*param_1 + 0x40))(param_1[0x31],auStack_8,0);

    if (cVar1 == '\x01') {

      if (unaff_EDI != 0) {

        FUN_00681020(param_1 + 0x31,unaff_EDI,1);

        param_1[0x31] = 0;

        param_1[0x32] = 0;

        return 1;

      }

      FUN_00681020(&stack0xfffffff0,0,1);

      return 1;

    }

  }

  return 0;

}
