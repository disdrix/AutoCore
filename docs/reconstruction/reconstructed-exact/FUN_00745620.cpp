// =============================================================================
// FUN_00745620
// -----------------------------------------------------------------------------
// Stable ID: aa_00745620
// Address:   0x00745620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00745620 @ 0x00745620
// Stable ID: aa_00745620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, goto×2, return×2.
//  - Notable callees: FUN_0043b9e0×2, FUN_0075d530×2, FUN_00744170, FUN_007451b0, FUN_00745620.
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

uint32_t /* width from decompiler */ FUN_00745620(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  uint8_t local_1c [4];

  int *local_18;

  int *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1235;

  local_c = ExceptionList;

  piVar4 = *(int **)(param_1 + 0x54);

  piVar1 = *(int **)(param_1 + 0x50);

  if (piVar1 != piVar4) {

    do {

      if (*piVar1 == *param_2) break;

      piVar1 = piVar1 + 1;

    } while (piVar1 != piVar4);

    if (piVar1 != piVar4) {

      uVar3 = 1;

      ExceptionList = &local_c;

      goto LAB_00745738;

    }

  }

  local_18 = (int *)0x0;

  local_14 = (int *)0x0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_00744170(param_2,local_1c,0);

  piVar4 = local_18;

  if (local_18 != local_14) {

    do {

      piVar1 = *(int **)(param_1 + 0x54);

      piVar2 = *(int **)(param_1 + 0x50);

      if (piVar2 == piVar1) {

LAB_007456c4:

        FUN_0043b9e0();

        if (DAT_00d1f050 != 0) {

          FUN_0075d530();

        }

      }

      else {

        do {

          if (*piVar2 == *piVar4) break;

          piVar2 = piVar2 + 1;

        } while (piVar2 != piVar1);

        if (piVar2 == piVar1) goto LAB_007456c4;

      }

      piVar4 = piVar4 + 1;

    } while (piVar4 != local_14);

  }

  FUN_0043b9e0();

  if (DAT_00d1f050 != 0) {

    FUN_0075d530();

  }

  local_4 = 0xffffffff;

  if (local_18 != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  uVar3 = 0;

  local_18 = (int *)0x0;

  local_14 = (int *)0x0;

  local_10 = 0;

LAB_00745738:

  local_4 = 0xffffffff;

  FUN_007451b0(param_2,param_3);

  ExceptionList = local_c;

  return uVar3;

}
