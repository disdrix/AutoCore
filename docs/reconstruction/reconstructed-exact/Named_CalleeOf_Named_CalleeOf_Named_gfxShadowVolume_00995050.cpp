// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00995050
// -----------------------------------------------------------------------------
// Stable ID: aa_00995050
// Callee of Named_CalleeOf_Named_gfxShadowVolume
// Address:   0x00995050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×2, for×1, if×1.
//  - Notable callees: FUN_00414c20×2, FUN_0044c3c0, FUN_00746d00, FUN_00995050.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxShadowVolume
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_00995050(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint uVar1;

  uint uVar2;

  uint8_t local_24 [4];

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b2296;

  local_c = ExceptionList;

  local_20 = (uint32_t /* width from decompiler */ *)0x0;

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0044c3c0(0,0);

  *local_20 = DAT_00a242d0;

  local_20[1] = DAT_00a242d4;

  local_20[2] = DAT_00a242d8;

  local_20[3] = DAT_00a242dc;

  local_20[4] = DAT_00a242e0;

  local_20[5] = DAT_00a242e4;

  FUN_00746d00();

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

  FUN_00414c20(param_2,local_24,0x20,0);

  uVar1 = *(uint *)(param_1 + 0xd8);

  for (uVar2 = *(uint *)(param_1 + 0xd4); uVar2 < uVar1; uVar2 = uVar2 + 8) {

    FUN_00414c20(param_2,local_24,0x20,0);

  }

  if (local_20 == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_20);

}
