// =============================================================================
// FUN_00989350
// -----------------------------------------------------------------------------
// Stable ID: aa_00989350
// Address:   0x00989350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00989350 @ 0x00989350
// Stable ID: aa_00989350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0043b500×7, FUN_00439870×2, FUN_00439920×2, FUN_00439810, FUN_00989350, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall FUN_00989350(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  int iVar12;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad956;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x43504446,1);

  local_4 = 0;

  uVar2 = FUN_00439870();

  uVar3 = FUN_00439870();

  uVar4 = FUN_0043b500(param_2 + 0x10);

  uVar5 = FUN_0043b500(param_2 + 0x14);

  uVar6 = FUN_0043b500(param_2 + 0x18);

  uVar7 = FUN_0043b500(param_2 + 0x1c);

  uVar8 = FUN_0043b500(param_2 + 0x20);

  uVar9 = FUN_0043b500(param_2 + 0x24);

  uVar10 = FUN_0043b500(param_2 + 0x28);

  uVar11 = FUN_00439810();

  iVar1 = *(int *)(param_2 + 0x34);

  uVar11 = uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11;

  for (iVar12 = *(int *)(param_2 + 0x30); iVar12 != iVar1; iVar12 = iVar12 + 0x38) {

    uVar2 = FUN_00439920();

    uVar3 = FUN_00439920();

    uVar11 = uVar11 | uVar2 | uVar3;

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return uVar11;

}
