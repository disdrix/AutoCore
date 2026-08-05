// =============================================================================
// Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision_00415cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00415cb0
// Callee of Drive_CollisionListener_DoVehicleCollision
// Address:   0x00415cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_CollisionListener_DoVehicleCollision: vehicle collision helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00415cb0.
//  - Return sites: 1.

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

void __thiscall Named_CalleeOf_Drive_CollisionListener_DoVehicleCollision_00415cb0(int param_1,uint32_t /* width from decompiler */ *param_2)

{
  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);
  param_2[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);
  param_2[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);
  param_2[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);
  return;
}
