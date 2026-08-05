// =============================================================================
// FUN_008f0c80
// -----------------------------------------------------------------------------
// Stable ID: aa_008f0c80
// Address:   0x008f0c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f0c80 @ 0x008f0c80
// Stable ID: aa_008f0c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, do×1, return×1.
//  - Notable callees: FUN_0040dfb0, FUN_0040e1e0, FUN_00792c20, FUN_008f0c80.
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

void __fastcall FUN_008f0c80(uint32_t /* width from decompiler */ *param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b76ef;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a38aac;

  local_4 = 2;

  piVar4 = *(int **)param_1[0x158];

  if (piVar4 != (int *)param_1[0x158]) {

    do {

      operator_delete__((void *)piVar4[7]);

      if (*(char *)((int)piVar4 + 0x21) == '\0') {

        piVar2 = (int *)piVar4[2];

        if (*(char *)((int)piVar2 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x21);

          piVar4 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x21);

            piVar4 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar4[1] + 0x21);

          piVar3 = (int *)piVar4[1];

          piVar2 = piVar4;

          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {

            cVar1 = *(char *)(piVar4[1] + 0x21);

            piVar3 = (int *)piVar4[1];

            piVar2 = piVar4;

          }

        }

      }

    } while (piVar4 != (int *)param_1[0x158]);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0x19f] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x19f])(1);

  }

  param_1[0x19f] = 0;

  local_4._0_1_ = 1;

  FUN_0040e1e0();

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0040dfb0(param_1 + 0x157);

  *param_1 = &PTR_FUN_00a58c6c;

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_00792c20();

  ExceptionList = param_1;

  return;

}
