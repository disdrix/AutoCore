// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_005402a0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_005402a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005402a0
// Address:   0x005402a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_005402a0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = *(int *)(param_1 + 0xf10);

  iVar5 = 0;

  if (*(char *)(iVar4 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar4 + 0x1d) = 1;

  while( true ) {

    iVar4 = *(int *)(param_1 + 0xf10);

    if (*(char *)(iVar4 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    uVar3 = DAT_009d00b4;

    uVar2 = DAT_009d00b0;

    uVar1 = DAT_009d00ac;

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar4 + 0x14);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x14);

    }

    if (iVar5 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(iVar5 + 8);

    }

    if (iVar4 == 0) break;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x100) = DAT_009d00a8;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x104) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x108) = uVar2;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10c) = uVar3;

  }

  *(uint8_t *)(*(int *)(param_1 + 0xf10) + 0x1d) = 0;

  return;

}
