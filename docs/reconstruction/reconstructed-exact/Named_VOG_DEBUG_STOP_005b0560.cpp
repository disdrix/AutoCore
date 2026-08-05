// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, return×2.
//  - Notable callees: FUN_007a4480×4, FUN_005b0560, FUN_005b0960, block.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_005b0560
// -----------------------------------------------------------------------------
// Stable ID: aa_005b0560
// Address:   0x005b0560  (autoassault.exe, image base 0x400000)
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

/* WARNING: Removing unreachable block (ram,0x005b05b5) */



void __fastcall Named_VOG_DEBUG_STOP_005b0560(int *param_1)



{

  void *pvVar1;

  

  if (*(char *)((int)param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)((int)param_1 + 0x1d) = 1;

  if (*(char *)((int)param_1 + 0x1d) == '\0') {

    FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (param_1[5] == 0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = *(void **)(param_1[5] + 8);

  }

  if (pvVar1 == (void *)0x0) {

    *(uint8_t *)((int)param_1 + 0x1d) = 0;

                    /* WARNING: Could not recover jumptable at 0x005b05e9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 4))();

    return;

  }

  FUN_005b0960();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
