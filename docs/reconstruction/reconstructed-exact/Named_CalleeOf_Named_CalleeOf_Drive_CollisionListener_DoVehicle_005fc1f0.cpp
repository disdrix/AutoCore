// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_CollisionListener_DoVehicle_005fc1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc1f0
// Callee of Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision
// Address:   0x005fc1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision: vehicle collision helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject×2, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, FUN_005fc1f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Drive_CollisionListener_DoVehicle_005fc1f0(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009dd2f0;

  CVOGHBBase_SetPeriodAndCounter(param_1,1,true);

  param_1[2] = param_3;

  if (param_2 == 0) {

    CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);

    return param_1;

  }

  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));

  return param_1;

}
