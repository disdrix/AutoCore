// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_005f4380
// -----------------------------------------------------------------------------
// Stable ID: aa_005f4380
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x005f4380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005f3120, FUN_005f3160, FUN_005f4230, FUN_005f4380, FUN_00646d90, FUN_00646dd0.
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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_005f4380(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            )



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ local_20;

  uint8_t local_1c [16];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a79e0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_005f3120(param_1,param_2);

  local_4 = 0;

  FUN_00646d90(local_20,*(uint32_t /* width from decompiler */ *)(param_3 + 8));

  local_4._0_1_ = 1;

  uVar1 = FUN_005f4230(local_1c,param_4,param_5);

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_00646dd0();

  local_4 = 0xffffffff;

  FUN_005f3160();

  ExceptionList = pvStack_c;

  return uVar1;

}
