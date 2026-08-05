// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_00538000, FUN_00538e50.
//  - Strings: "HashError:Destroy, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00538e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00538e50
// Address:   0x00538e50  (autoassault.exe, image base 0x400000)
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

void __thiscall Named_VOG_DEBUG_STOP_00538e50(int param_1,void *param_2)



{

  int iVar1;

  

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:Destroy, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar1 = FUN_00538000(param_2,&param_2);

  if (-1 < iVar1) {

                    /* WARNING: Subroutine does not return */

    operator_delete(param_2);

  }

  return;

}
