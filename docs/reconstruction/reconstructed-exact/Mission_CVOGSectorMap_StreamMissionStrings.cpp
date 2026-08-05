// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00498740×3, FUN_004d0530, FUN_004e2410, FUN_0079cd30, FUN_0079d1e0, FUN_0079d290.
//  - Strings: "CVOGSectorMap::StreamMissionStrings"; "lNumStrings"; "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Mission_CVOGSectorMap_StreamMissionStrings
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0530
// Address:   0x004d0530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "CVOGSectorMap::StreamMissionStrings"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_CVOGSectorMap_StreamMissionStrings(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe5c8) + 0xc);

  iVar1 = 0;

  FUN_0079d290(1,"CVOGSectorMap::StreamMissionStrings");

  FUN_00498740("lNumStrings",&local_4);

  iVar2 = *(int *)(param_1 + 0xe5c8);

  if (*(char *)(iVar2 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar2 + 0x1d) = 1;

  while( true ) {

    iVar2 = *(int *)(param_1 + 0xe5c8);

    if (*(char *)(iVar2 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar1 == 0) {

      iVar1 = *(int *)(iVar2 + 0x14);

    }

    else {

      iVar1 = *(int *)(iVar1 + 0x14);

    }

    if (iVar1 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(iVar1 + 8);

    }

    if (iVar2 == 0) break;

    FUN_00498740("lMissionStringID",iVar2 + 4);

    FUN_00498740("lOwnerID",iVar2 + 8);

    FUN_004e2410("cType",iVar2 + 0xc);

    FUN_0079cd30("strText",*(uint32_t /* width from decompiler */ *)(iVar2 + 0x10));

  }

  *(uint8_t *)(*(int *)(param_1 + 0xe5c8) + 0x1d) = 0;

  FUN_0079d1e0();

  return;

}
