// =============================================================================
// FUN_0048bb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0048bb20
// Address:   0x0048bb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048bb20 @ 0x0048bb20
// Stable ID: aa_0048bb20
// Embedded strings (evidence for future rename):
//   - "') {

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×1, goto×1.
//  - Notable callees: FUN_0048ad40×2, FUN_0048bb20, fprintf.
//  - Strings: "%s=\'%s\'"; "%s=\"%s\"".
//  - Return sites: 3.

        if ((int)piVar3 + (-8 - (int)piVar2) != DAT_009c6d7c) {

          pcVar4 = "
//   - "%s=\"%s\""
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void __thiscall FUN_0048bb20(int param_1,FILE *param_2)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a05c0;

  local_c = ExceptionList;

  local_10 = &DAT_00b03504;

  local_14 = &DAT_00b03504;

  local_4._0_1_ = 1;

  local_4._1_3_ = 0;

  ExceptionList = &local_c;

  FUN_0048ad40(param_1 + 0x14,&local_10);

  FUN_0048ad40((int *)(param_1 + 0x18),&local_14);

  piVar2 = *(int **)(param_1 + 0x18);

  if (*piVar2 != 0) {

    piVar3 = piVar2 + 2;

    cVar1 = (char)piVar2[2];

    while (cVar1 != '\0') {

      if (cVar1 == '\"') {

        if ((int)piVar3 + (-8 - (int)piVar2) != DAT_009c6d7c) {

          pcVar4 = "%s=\'%s\'";

          goto LAB_0048bbda;

        }

        break;

      }

      pcVar4 = (char *)((int)piVar3 + 1);

      piVar3 = (int *)((int)piVar3 + 1);

      cVar1 = *pcVar4;

    }

  }

  pcVar4 = "%s=\"%s\"";

LAB_0048bbda:

  fprintf(param_2,pcVar4,local_10 + 2,local_14 + 2);

  local_4 = (uint)local_4._1_3_ << 8;

  if (local_14 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_14);

  }

  local_4 = 0xffffffff;

  if (local_10 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_10);

  }

  ExceptionList = local_c;

  return;

}
