// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: stoChunkWriter_EndChunk×2, FUN_00439810, FUN_0073f8a0, stoChunkWriter_BeginChunk, vog_LogMessage.
//  - Strings: "anmAnimEventsImpl: Error Writing Animation Events!"; "anmAnimEventsImpl: Error Writing track count!"; "anmAnimEventsImpl: Error Writing track events!".
//  - Return sites: 2.

// =============================================================================
// Named_anmAnimEventsImpl_0073f8a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f8a0
// Address:   0x0073f8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmAnimEventsImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Named_anmAnimEventsImpl_0073f8a0(void *param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad79e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  stoChunkWriter_BeginChunk(0x41455654,1);

  iVar4 = 0;

  local_4 = 0;

  uVar1 = (*(code *)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 8))(param_1);

  if ((int)uVar1 < 0) {

    pcVar6 = "anmAnimEventsImpl: Error Writing Animation Events!";

    uVar5 = 0xe9;

  }

  else {

    uVar2 = FUN_00439810();

    uVar1 = uVar1 | uVar2;

    if ((int)uVar1 < 0) {

      pcVar6 = "anmAnimEventsImpl: Error Writing track count!";

      uVar5 = 0xec;

    }

    else {

      uVar2 = 0;

      while( true ) {

        if ((*(int *)(unaff_EDI + 0x28) == 0) ||

           ((uint)((*(int *)(unaff_EDI + 0x2c) - *(int *)(unaff_EDI + 0x28)) / 0x1c) <= uVar2)) {

          puStack_8 = (uint8_t *)0xffffffff;

          stoChunkWriter_EndChunk();

          ExceptionList = param_1;

          return uVar1;

        }

        uVar3 = (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(unaff_EDI + 0x28) + iVar4))(param_1);

        uVar1 = uVar1 | uVar3;

        if ((int)uVar1 < 0) break;

        uVar2 = uVar2 + 1;

        iVar4 = iVar4 + 0x1c;

      }

      pcVar6 = "anmAnimEventsImpl: Error Writing track events!";

      uVar5 = 0xf1;

    }

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimEventsImpl.cpp",uVar5,3,

                 pcVar6);

  puStack_8 = (uint8_t *)0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = param_1;

  return 0xffffffff;

}
