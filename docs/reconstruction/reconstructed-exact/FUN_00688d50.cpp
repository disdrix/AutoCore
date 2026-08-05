// =============================================================================
// FUN_00688d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00688d50
// Address:   0x00688d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00688d50 @ 0x00688d50
// Stable ID: aa_00688d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, while×2, do×1, return×1, goto×1.
//  - Notable callees: FUN_0068ed90×2, FUN_00688d50.
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

void FUN_00688d50(int param_1)



{

  int *piVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009aa072;

  local_10 = ExceptionList;

  local_8 = 0;

  piVar1 = DAT_00d08e98;

  ExceptionList = &local_10;

  do {

    while( true ) {

      if (piVar1 == DAT_00d08e9c) {

        ExceptionList = local_10;

        return;

      }

      if (param_1 != 0) break;

      if (*(int *)(*(int *)(*piVar1 + 0x10) + 8) == 1) {

        *(uint8_t *)(*(int *)(*piVar1 + 4) + 0x12) = 0;

      }

      if (*(int *)(*(int *)(*piVar1 + 0x10) + 0xc) == 1) {

        *(uint8_t *)(*(int *)(*piVar1 + 0x5c) + 0x12) = 0;

      }

      if ((*(int *)(*(int *)(*piVar1 + 0x10) + 0x10) == 1) ||

         (*(char *)(*(int *)(*piVar1 + 0x10) + 0x14) != '\0')) {

        FUN_0068ed90();

      }

LAB_00688dcc:

      piVar1 = piVar1 + 1;

    }

    if (param_1 != 1) goto LAB_00688dcc;

    FUN_0068ed90();

    *(uint8_t *)(*(int *)(*piVar1 + 0x14) + 0x30) = 0;

    piVar1 = piVar1 + 1;

  } while( true );

}
