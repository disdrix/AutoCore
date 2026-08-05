// =============================================================================
// FUN_008c0b10
// -----------------------------------------------------------------------------
// Stable ID: aa_008c0b10
// Address:   0x008c0b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c0b10 @ 0x008c0b10
// Stable ID: aa_008c0b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×12, do×1, while×1, return×1.
//  - Notable callees: FUN_008c03c0, FUN_008c0b10.
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

void FUN_008c0b10(void)



{

  uint uVar1;

  uint uVar2;

  int unaff_ESI;

  int iVar3;

  

  iVar3 = 0;

  if (0 < *(int *)(unaff_ESI + 0x530)) {

    do {

      if (*(int *)(unaff_ESI + 0x568) == 0) {

        uVar1 = 0;

      }

      else {

        uVar1 = *(int *)(unaff_ESI + 0x56c) - *(int *)(unaff_ESI + 0x568) >> 2;

      }

      uVar2 = *(int *)(unaff_ESI + 0x560) + iVar3;

      if (uVar2 < uVar1) {

        FUN_008c03c0(unaff_ESI,*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x568) + uVar2 * 4));

      }

      else {

        if (*(int *)(*(int *)(unaff_ESI + 0x578) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x578) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x57c) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x57c) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x580) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x580) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x584) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x584) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x58c) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x58c) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x590) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x590) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x594) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x594) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x598) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x598) + iVar3 * 4) + 4))(0);

        }

        if (*(int *)(*(int *)(unaff_ESI + 0x588) + iVar3 * 4) != 0) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x588) + iVar3 * 4) + 4))(0);

        }

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(unaff_ESI + 0x530));

  }

  *(int *)(unaff_ESI + 0x574) =

       *(int *)(unaff_ESI + 0x574) +

       (uint)(*(char *)(unaff_ESI + 0x519) != '\0') + (uint)(*(char *)(unaff_ESI + 0x518) != '\0') +

       (uint)(*(char *)(unaff_ESI + 0x517) != '\0') + (uint)(*(char *)(unaff_ESI + 0x516) != '\0') +

       (uint)(*(char *)(unaff_ESI + 0x515) != '\0') + (uint)(*(char *)(unaff_ESI + 0x514) != '\0');

  (**(code **)(**(int **)(unaff_ESI + 0x5a0) + 0x34c))();

  (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0x34c))();

  (**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0x34c))();

  (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0x34c))();

  (**(code **)(**(int **)(unaff_ESI + 0x5b0) + 0x34c))();

  (**(code **)(**(int **)(unaff_ESI + 0x5b4) + 0x34c))();

                    /* WARNING: Could not recover jumptable at 0x008c0d06. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(**(int **)(unaff_ESI + 0x5b8) + 0x34c))();

  return;

}
