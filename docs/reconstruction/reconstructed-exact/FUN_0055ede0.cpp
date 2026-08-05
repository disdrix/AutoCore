// =============================================================================
// FUN_0055ede0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ede0
// Address:   0x0055ede0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055ede0 @ 0x0055ede0
// Stable ID: aa_0055ede0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×8, do×4, while×4, return×1.
//  - Notable callees: FUN_005b3370×2, FUN_0055ede0.
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

void FUN_0055ede0(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *unaff_ESI;

  int *piVar4;

  int local_c;

  int local_8;

  

  piVar3 = *(int **)(param_1 + 8);

  if (piVar3 != piVar3 + *(int *)(param_1 + 0xc)) {

    do {

      iVar1 = *(int *)(*piVar3 + 0x5c);

      piVar4 = (int *)(*piVar3 + 0x58);

      local_c = 0;

      if (0 < iVar1) {

        do {

          iVar2 = (**(code **)(**(int **)(*piVar4 + local_c * 4) + 0x20))();

          if (iVar2 != 0xb) {

            iVar2 = *piVar4;

            if (unaff_ESI[1] == (unaff_ESI[2] & 0x7fffffffU)) {

              FUN_005b3370();

            }

            *(uint32_t /* width from decompiler */ *)(*unaff_ESI + unaff_ESI[1] * 4) = *(uint32_t /* width from decompiler */ *)(iVar2 + local_c * 4);

            unaff_ESI[1] = unaff_ESI[1] + 1;

          }

          local_c = local_c + 1;

        } while (local_c < iVar1);

      }

      piVar3 = piVar3 + 1;

    } while (piVar3 != (int *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 4));

  }

  piVar3 = *(int **)(param_1 + 0x14);

  if (piVar3 != piVar3 + *(int *)(param_1 + 0x18)) {

    do {

      iVar1 = *(int *)(*piVar3 + 0x5c);

      piVar4 = (int *)(*piVar3 + 0x58);

      local_8 = 0;

      if (0 < iVar1) {

        do {

          iVar2 = (**(code **)(**(int **)(*piVar4 + local_8 * 4) + 0x20))();

          if (iVar2 != 0xb) {

            iVar2 = *piVar4;

            if (unaff_ESI[1] == (unaff_ESI[2] & 0x7fffffffU)) {

              FUN_005b3370();

            }

            *(uint32_t /* width from decompiler */ *)(*unaff_ESI + unaff_ESI[1] * 4) = *(uint32_t /* width from decompiler */ *)(iVar2 + local_8 * 4);

            unaff_ESI[1] = unaff_ESI[1] + 1;

          }

          local_8 = local_8 + 1;

        } while (local_8 < iVar1);

      }

      piVar3 = piVar3 + 1;

    } while (piVar3 != (int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18) * 4));

  }

  return;

}
