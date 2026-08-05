// =============================================================================
// FUN_0096b060
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b060
// Address:   0x0096b060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096b060 @ 0x0096b060
// Stable ID: aa_0096b060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00439810, FUN_0096b060, stoChunkWriter_BeginChunk, stoChunkWriter_EndChunk.
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

uint __fastcall FUN_0096b060(uint32_t /* width from decompiler */ param_1)



{

  uint uVar1;

  uint uVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad931;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  stoChunkWriter_BeginChunk(0x50534b45,1);

  local_4 = 0;

  uVar1 = FUN_00439810();

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0xc);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x10)) {

    do {

      uVar2 = (**(code **)(*(int *)*puVar3 + 0x14))(param_1);

      puVar3 = puVar3 + 1;

      uVar1 = uVar1 | uVar2;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x10));

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = pvStack_c;

  return uVar1;

}
