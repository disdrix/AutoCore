// =============================================================================
// FUN_004b7470
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7470
// Address:   0x004b7470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b7470 @ 0x004b7470
// Stable ID: aa_004b7470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×1.
//  - Notable callees: FUN_004b7470, FUN_0058e980.
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

void FUN_004b7470(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  int *piVar7;

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  piVar4 = DAT_00b03714;

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(param_1 + 8)) {

    do {

      piVar6 = (int *)*piVar4;

      uVar1 = *puVar5;

      if (piVar6 != piVar4) {

        do {

          iVar2 = piVar6[2];

          piVar3 = *(int **)(iVar2 + 0x204);

          piVar7 = (int *)*piVar3;

          if (piVar7 != piVar3) {

            do {

              FUN_0058e980(uVar1);

              piVar7 = (int *)*piVar7;

              piVar4 = DAT_00b03714;

            } while (piVar7 != (int *)*(int *)(iVar2 + 0x204));

          }

          piVar6 = (int *)*piVar6;

        } while (piVar6 != piVar4);

      }

      puVar5 = puVar5 + 1;

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(param_1 + 8));

  }

  return;

}
