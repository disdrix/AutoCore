// =============================================================================
// FUN_004bfe10
// -----------------------------------------------------------------------------
// Stable ID: aa_004bfe10
// Address:   0x004bfe10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bfe10 @ 0x004bfe10
// Stable ID: aa_004bfe10
// Embedded strings (evidence for future rename):
//   - "CLoadQueue::update"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, goto×2, return×2, while×2.
//  - Notable callees: FUN_004bfe10, FUN_005c7df0, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CLoadQueue::update".
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

void __thiscall FUN_004bfe10(int param_1,float param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  uint uVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a192d;

  pvStack_c = ExceptionList;

  local_10 = DAT_00d1f040;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CLoadQueue::update");

  uVar3 = 0;

  local_4 = 0;

  local_14 = param_2;

  piVar6 = (int *)(param_1 + 8);

  do {

    if ((piVar6[1] != 0) && (piVar4 = *(int **)*piVar6, piVar4 != (int *)*piVar6)) {

      do {

        puVar1 = (uint32_t /* width from decompiler */ *)piVar4[2];

        cVar2 = FUN_005c7df0(&local_14,0);

        piVar5 = piVar4;

        if (cVar2 == '\0') {

LAB_004bfeb7:

          if (local_14 <= g_flZero) goto LAB_004bfed7;

          piVar5 = (int *)*piVar5;

        }

        else {

          if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)*puVar1)(1);

          }

          piVar5 = (int *)*piVar4;

          if (piVar4 != (int *)*piVar6) {

            *(int **)piVar4[1] = piVar5;

            *(int *)(*piVar4 + 4) = piVar4[1];

                    /* WARNING: Subroutine does not return */

            operator_delete(piVar4);

          }

          if (local_14 <= g_flZero) goto LAB_004bfeb7;

        }

        piVar4 = piVar5;

      } while (piVar5 != (int *)*piVar6);

    }

    uVar3 = uVar3 + 1;

    piVar6 = piVar6 + 3;

  } while (uVar3 < 9);

LAB_004bfed7:

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return;

}
