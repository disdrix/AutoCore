// =============================================================================
// FUN_004cfd50
// -----------------------------------------------------------------------------
// Stable ID: aa_004cfd50
// Address:   0x004cfd50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cfd50 @ 0x004cfd50
// Stable ID: aa_004cfd50
// Embedded strings (evidence for future rename):
//   - "UpdatePhysXPositions"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, do×3, while×3, return×1.
//  - Notable callees: FUN_004cfd50, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "UpdatePhysXPositions".
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

void __fastcall FUN_004cfd50(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1f5d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("UpdatePhysXPositions");

  piVar5 = *(int **)(*(int *)(param_1 + 0xe4a4) + 8);

  local_4 = 0;

  if (piVar5 != piVar5 + *(int *)(*(int *)(param_1 + 0xe4a4) + 0xc)) {

    do {

      piVar6 = *(int **)(*piVar5 + 0x3c);

      if (piVar6 != piVar6 + *(int *)(*piVar5 + 0x40)) {

        do {

          iVar1 = *(int *)(*piVar6 + 0x34);

          iVar2 = 0;

          if (0 < iVar1) {

            piVar3 = *(int **)(*piVar6 + 0x30);

            piVar4 = piVar3;

            do {

              if (*piVar4 == 1) {

                piVar3 = (int *)piVar3[iVar2 * 2 + 1];

                if (((piVar3 != (int *)0x0) && (((uint)piVar3[0x5f] >> 6 & 1) != 0)) &&

                   (((uint)piVar3[0x5f] >> 5 & 1) != 0)) {

                  piVar3 = (int *)(**(code **)(*piVar3 + 0x1c8))();

                  (**(code **)(*piVar3 + 0x30))();

                }

                break;

              }

              iVar2 = iVar2 + 1;

              piVar4 = piVar4 + 2;

            } while (iVar2 < iVar1);

          }

          piVar6 = piVar6 + 1;

        } while (piVar6 != (int *)(*(int *)(*piVar5 + 0x3c) + *(int *)(*piVar5 + 0x40) * 4));

      }

      piVar5 = piVar5 + 1;

    } while (piVar5 != (int *)(*(int *)(*(int *)(param_1 + 0xe4a4) + 8) +

                              *(int *)(*(int *)(param_1 + 0xe4a4) + 0xc) * 4));

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
