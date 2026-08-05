// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_00649a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00649a50
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x00649a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper. Evidence string: "hkFakeRigidBodyDeactivator_SINGLETON". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "hkFakeRigidBodyDeactivator_SINGLETON"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006463a0, FUN_00646d10, FUN_006499c0, FUN_00649a50.
//  - Strings: "hkFakeRigidBodyDeactivator_SINGLETON"; "hkVector4Zero_SINGLETON".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_00649a50(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  FUN_00646d10(param_2,param_3,param_4);

  *param_1 = &PTR_FUN_009e47a0;

  *(uint8_t *)(param_1 + 5) = 0;

  FUN_006499c0(&PTR_PTR_00af4f88,"hkFakeRigidBodyDeactivator_SINGLETON");

  FUN_006463a0(&DAT_00bc5630,"hkVector4Zero_SINGLETON");

  return param_1;

}
