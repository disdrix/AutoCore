// =============================================================================
// FUN_00943db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00943db0
// Address:   0x00943db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00943db0 @ 0x00943db0
// Stable ID: aa_00943db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, while×3, do×2.
//  - Notable callees: FUN_008d80c0×2, Client_RefreshLocalCharacterLevelUi, FUN_004040a0, FUN_00406b80, FUN_0040fb90, FUN_004cd310, FUN_004d9b50, FUN_00943db0.
//  - Return sites: 4.

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

void FUN_00943db0(void)



{

  void *pvVar1;

  int unaff_EBX;

  int *piVar2;

  int *piVar3;

  int *local_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bb997;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (DAT_00d1b77c != 0) {

    ExceptionList = &pvStack_c;

    if (*(int *)(DAT_00d1b77c + 0xa7c) != 0) {

      ExceptionList = &pvStack_c;

      FUN_008d80c0(*(int *)(DAT_00d1b77c + 0xa7c));

    }

    if (*(int *)(DAT_00d1b77c + 0xa80) != 0) {

      FUN_008d80c0(*(int *)(DAT_00d1b77c + 0xa80));

    }

  }

  local_1c = (int *)**(int **)(unaff_EBX + 0xd28);

  if (local_1c != *(int **)(unaff_EBX + 0xd28)) {

    do {

      if ((int *)local_1c[8] != (int *)0x0) {

        (**(code **)(*(int *)local_1c[8] + 4))(1);

      }

      FUN_004040a0();

    } while (local_1c != *(int **)(unaff_EBX + 0xd28));

  }

  pvVar1 = *(void **)(*(int *)(unaff_EBX + 0xd28) + 4);

  if (*(char *)((int)pvVar1 + 0x29) == '\0') {

    FUN_00406b80(*(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8));

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(int *)(*(int *)(unaff_EBX + 0xd28) + 4) = *(int *)(unaff_EBX + 0xd28);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xd2c) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xd28) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xd28);

  *(int *)(*(int *)(unaff_EBX + 0xd28) + 8) = *(int *)(unaff_EBX + 0xd28);

  FUN_0094dab0();

  piVar2 = (int *)(unaff_EBX + 0xe9c);

  local_1c = (int *)0xc;

  while (*piVar2 == 0) {

    piVar2 = piVar2 + 1;

    local_1c = (int *)((int)local_1c + -1);

    if (local_1c == (int *)0x0) {

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x140) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x144) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xe98) = 0;

      FUN_004cd310(0);

      Client_RefreshLocalCharacterLevelUi();

      ExceptionList = pvStack_c;

      return;

    }

  }

  if (*(int *)(unaff_EBX + 0xe04) != 0) {

    FUN_004d9b50(*piVar2);

  }

  (**(code **)(*(int *)(*(int *)(*(int *)(*piVar2 + 4) + 4) + 4 + *piVar2) + 0x2a8))

            (*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xd34));

  uStack_18 = FUN_0040fb90();

  uStack_14 = 0;

  puStack_8 = (uint8_t *)0x0;

  (**(code **)(*(int *)(*(int *)(*(int *)(*piVar2 + 4) + 4) + 4 + *piVar2) + 0x2b0))(&local_1c);

  piVar3 = (int *)*local_1c;

  if (piVar3 != local_1c) {

    do {

      if ((uint32_t /* width from decompiler */ *)piVar3[2] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)piVar3[2])(1);

      }

      piVar3[2] = 0;

      piVar3 = (int *)*piVar3;

    } while (piVar3 != local_1c);

  }

  *piVar2 = 0;

  pvStack_c = (void *)0xffffffff;

  piVar2 = (int *)*local_1c;

  *local_1c = (int)local_1c;

  local_1c[1] = (int)local_1c;

  uStack_18 = 0;

  if (piVar2 != local_1c) {

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar2);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_1c);

}
