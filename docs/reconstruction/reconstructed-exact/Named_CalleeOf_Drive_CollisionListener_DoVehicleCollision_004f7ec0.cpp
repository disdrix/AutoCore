// =============================================================================
// Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision_004f7ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7ec0
// Callee of Drive_CollisionListener_DoVehicleCollision
// Address:   0x004f7ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_CollisionListener_DoVehicleCollision: vehicle collision helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_004f7ec0, FUN_005fc1f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_CollisionListener_DoVehicleCollision
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

void __thiscall Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision_004f7ec0(int param_1,char param_2)



{

  void *pvVar1;

  CVOGHBBase *pAction;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2ccf;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0x100) != '\0') {

    if (param_2 == '\0') {

      ExceptionList = &local_c;

      pvVar1 = operator_new(0x24);

      pAction = (CVOGHBBase *)0x0;

      local_4 = 0;

      if (pvVar1 != (void *)0x0) {

        pAction = (CVOGHBBase *)FUN_005fc1f0(param_1,DAT_00af0c70);

      }

      local_4 = 0xffffffff;

      CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +

                                   0xe4ec),pAction);

      CVOGHBBase_Start(pAction);

    }

    *(char *)(param_1 + 0x100) = param_2;

    ExceptionList = local_c;

    return;

  }

  *(char *)(param_1 + 0x100) = param_2;

  return;

}
