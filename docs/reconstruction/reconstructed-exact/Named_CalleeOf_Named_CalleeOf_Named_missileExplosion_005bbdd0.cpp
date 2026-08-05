// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_missileExplosion_005bbdd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005bbdd0
// Callee of Named_CalleeOf_Named_missileExplosion
// Address:   0x005bbdd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_missileExplosion: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~154 non-empty decompiler lines.
//  - Control keywords: for×4, return×1.
//  - Notable callees: FUN_004a6c80×2, FUN_004933f0, FUN_005b8210, FUN_005bbdd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_missileExplosion
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_missileExplosion_005bbdd0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6bbf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005b8210();

  local_4 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  FUN_004a6c80();

  FUN_004a6c80();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7dc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7ec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7f0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7f4) = 0;

  *(uint8_t *)(param_1 + 0x7f8) = 0;

  *(uint8_t *)(param_1 + 0x7f9) = 0;

  *(uint8_t *)(param_1 + 0x7fa) = 0;

  *(uint8_t *)(param_1 + 0x7fb) = 0;

  *(uint8_t *)(param_1 + 0x7fc) = 0;

  *(uint8_t *)(param_1 + 0x7ff) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x800) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x804) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x808) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x810) = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x7dc);

  *(uint8_t *)(param_1 + 0x7fd) = 1;

  *(uint8_t *)(param_1 + 0x7fe) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x814) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x818) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x81c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x820) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x824) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x828) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x82c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x830) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x834) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x838) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x83c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x840) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x844) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x848) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x850) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x854) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x858) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x85c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x860) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x864) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x868) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x86c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x870) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x874) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x878) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x87c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x880) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x884) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x888) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x890) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x894) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x898) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x89c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b8) = 0;

  *(float *)(param_1 + 0x8bc) = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8cc) = 0;

  uVar3 = FUN_004933f0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa24) = uVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa28) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x3f8);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  for (iVar4 = 0xf9; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  puVar5 = puVar2;

  for (iVar4 = 0xf9; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *puVar1 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7ec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7f0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7f4) = 0;

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x8d0);

  for (iVar4 = 0x30; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x990) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x994) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x998) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x99c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9d0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9d4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9d8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9dc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9e0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9e4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9ec) = 0;

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x9f0);

  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(int *)(param_1 + 0x308) = param_1 + 0x14;

  *(int *)(param_1 + 0x304) = param_1 + 0x14;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x7e0) = puVar1;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x6ec) = puVar2;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x6e8) = puVar2;

  *puVar1 = puVar1;

  ExceptionList = local_c;

  return param_1;

}
