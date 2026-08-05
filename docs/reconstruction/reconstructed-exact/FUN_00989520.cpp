// =============================================================================
// FUN_00989520
// -----------------------------------------------------------------------------
// Stable ID: aa_00989520
// Address:   0x00989520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00989520 @ 0x00989520
// Stable ID: aa_00989520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00439810, FUN_00989350, FUN_00989520, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint __fastcall FUN_00989520(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afc1f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x43504447,1);

  local_4 = 0;

  uVar3 = FUN_00439810();

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xc);

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    if (puVar2[2] == 0) {

      uVar4 = 0xffffffff;

    }

    else {

      uVar4 = FUN_00989350();

    }

    uVar3 = uVar3 | uVar4;

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return uVar3;

}
