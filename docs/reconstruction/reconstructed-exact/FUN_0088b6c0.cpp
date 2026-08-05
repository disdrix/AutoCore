// =============================================================================
// FUN_0088b6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088b6c0
// Address:   0x0088b6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088b6c0 @ 0x0088b6c0
// Stable ID: aa_0088b6c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×2.
//  - Notable callees: FUN_0088a7a0, FUN_0088ad60, FUN_0088b6c0.
//  - Return sites: 2.

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

void __fastcall FUN_0088b6c0(int *param_1)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (DAT_00d1b6d8 != 0)) {

    if (*(char *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) + 0xf5)

        != '\0') {

      piVar2 = param_1 + 0x150;

      iVar3 = 3;

      do {

        if (*piVar2 != 0) {

          cVar1 = (**(code **)(*(int *)*piVar2 + 0xd8))();

          if (cVar1 != '\0') {

            (**(code **)(*(int *)*piVar2 + 0xd4))(0);

            (**(code **)(*(int *)*piVar2 + 0x34c))();

          }

        }

        piVar2 = piVar2 + 1;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

      param_1 = param_1 + 0x153;

      iVar3 = 3;

      do {

        if (*param_1 != 0) {

          cVar1 = (**(code **)(*(int *)*param_1 + 0xd8))();

          if (cVar1 != '\0') {

            (**(code **)(*(int *)*param_1 + 0xd4))(0);

            (**(code **)(*(int *)*param_1 + 0x34c))();

          }

        }

        param_1 = param_1 + 1;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

      return;

    }

    FUN_0088ad60(param_1,1,1);

    FUN_0088a7a0();

  }

  return;

}
