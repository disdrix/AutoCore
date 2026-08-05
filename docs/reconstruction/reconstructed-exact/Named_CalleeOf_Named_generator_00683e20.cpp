// =============================================================================
// Named_CalleeOf_Named_generator_00683e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00683e20
// Callee of Named_generator
// Address:   0x00683e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00680c30, FUN_00680c50, FUN_00681020, FUN_00683e20, FUN_00685050, thunk_FUN_0076c4d0.
//  - Return sites: 1.

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

void __fastcall Named_CalleeOf_Named_generator_00683e20(int param_1)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *local_3c;

  int local_38;

  uint8_t auStack_34 [4];

  uint32_t /* width from decompiler */ local_30;

  uint8_t local_2c;

  uint8_t local_2b;

  uint16_t local_2a;

  uint8_t local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9bf2;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x10) != 0) {

    local_38 = DAT_009ea76c;

    local_3c = (int *)0x0;

    ExceptionList = &local_c;

    FUN_00680c30();

    local_4 = 0;

    local_2c = DAT_009ea59e;

    local_30 = 0;

    local_2b = 0;

    local_2a = 0;

    local_3c = operator_new__(DAT_009ea5a8);

    (**(code **)(**(int **)(param_1 + 0x10) + 0x10))(local_3c + 1,&local_38);

    *local_3c = local_38;

    uVar1 = (DAT_009ea5a8 - local_38) - 4;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)local_3c + local_38 + 4);

    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

      *(uint8_t *)puVar3 = 0;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

    FUN_00681020(&local_3c,DAT_009ea5a8,1);

    FUN_00685050(local_28,&local_30,auStack_34);

    thunk_FUN_0076c4d0();

    local_4 = 0xffffffff;

    FUN_00680c50();

  }

  ExceptionList = local_c;

  return;

}
