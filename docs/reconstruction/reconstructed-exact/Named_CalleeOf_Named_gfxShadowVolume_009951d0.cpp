// =============================================================================
// Named_CalleeOf_Named_gfxShadowVolume_009951d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009951d0
// Callee of Named_gfxShadowVolume
// Address:   0x009951d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00414b60, FUN_00414bc0, FUN_00414c20, FUN_00995050, FUN_00995150, FUN_009951d0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxShadowVolume
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

void __thiscall Named_CalleeOf_Named_gfxShadowVolume_009951d0(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b22ba;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(int *)(param_1 + 0xa8) = param_2 / 3;

  if (*(char *)(param_1 + 0xcc) == '\0') {

    FUN_00995050();

    ExceptionList = local_c;

    return;

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8);

  puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x60);

  if ((puVar2 != (uint32_t /* width from decompiler */ *)0x0) && (*(int *)(iVar1 + 100) - (int)puVar2 >> 2 != 0)) {

    FUN_00995150(*puVar2);

    ExceptionList = local_c;

    return;

  }

  uVar3 = FUN_00414bc0(0x1018);

  local_4 = 0;

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

  FUN_00414c20(unaff_EDI,uVar3,0x20,0);

  FUN_00414b60();

  ExceptionList = local_c;

  return;

}
