// =============================================================================
// FUN_00755c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00755c30
// Address:   0x00755c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755c30 @ 0x00755c30
// Stable ID: aa_00755c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, goto×2, do×1, while×1.
//  - Notable callees: FUN_00442ed0, FUN_00755c30.
//  - Return sites: 4.

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

int __fastcall FUN_00755c30(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  int unaff_EBX;

  undefined **ppuStack_24;

  int **ppiStack_20;

  int *piStack_1c;

  int *local_18;

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac208;

  pvStack_c = ExceptionList;

  local_18 = (int *)0x0;

  local_14 = 0;

  local_10 = (void *)0x0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))();

  FUN_00442ed0(uVar1);

  ppiStack_20 = &piStack_1c;

  ppuStack_24 = &PTR_LAB_00a9f52c;

  (**(code **)(**(int **)(param_1 + 8) + 0x20))(&ppuStack_24);

  piVar2 = piStack_1c;

  do {

    if (piVar2 == local_18) {

LAB_00755cb8:

      piVar2 = piStack_1c;

      if (piStack_1c == local_18) {

        if (piStack_1c != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(piStack_1c);

        }

        ExceptionList = local_10;

        return 0;

      }

LAB_00755cbe:

      if (piStack_1c != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(piStack_1c);

      }

      ExceptionList = local_10;

      return *piVar2;

    }

    if (*piVar2 == unaff_EBX) {

      if ((piVar2 != local_18) && (piVar2 = piVar2 + 1, piVar2 != local_18)) goto LAB_00755cbe;

      goto LAB_00755cb8;

    }

    piVar2 = piVar2 + 1;

  } while( true );

}
