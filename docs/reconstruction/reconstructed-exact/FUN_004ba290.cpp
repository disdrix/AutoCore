// =============================================================================
// FUN_004ba290
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba290
// Address:   0x004ba290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ba290 @ 0x004ba290
// Stable ID: aa_004ba290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_004b8ed0, FUN_004b99c0, FUN_004ba290.
//  - Return sites: 3.

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

void FUN_004ba290(uint32_t /* width from decompiler */ param_1)



{

  uint *puVar1;

  char cVar2;

  int *piVar3;

  int *piVar4;

  

  piVar3 = (int *)*DAT_00b03714;

  if (piVar3 != DAT_00b03714) {

    do {

      puVar1 = (uint *)piVar3[2];

      cVar2 = FUN_004b8ed0(param_1);

      if (cVar2 == '\0') {

        piVar4 = (int *)*piVar3;

      }

      else {

        piVar4 = (int *)*piVar3;

        if (piVar3 != DAT_00b03714) {

          *(int **)piVar3[1] = piVar4;

          *(int *)(*piVar3 + 4) = piVar3[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar3);

        }

        *puVar1 = *puVar1 & 0xfffffffe;

        if (*(char *)((int)puVar1 + 9) == '\0') {

          FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar1);

        }

      }

      piVar3 = piVar4;

    } while (piVar4 != DAT_00b03714);

  }

  return;

}
