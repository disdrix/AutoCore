// =============================================================================
// FUN_004823b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004823b0
// Address:   0x004823b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004823b0 @ 0x004823b0
// Stable ID: aa_004823b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×9, goto×3, return×2, while×1, for×1.
//  - Notable callees: FUN_004852c0×2, CONCAT11, CONCAT13, FUN_004820a0, FUN_00482180, FUN_00482350, FUN_004823b0.
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

uint32_t /* width from decompiler */ FUN_004823b0(void)



{

  int *piVar1;

  ushort uVar2;

  byte bVar3;

  int in_EAX;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar1 = *(int **)(in_EAX + 0x20);

  uStack_4 = 0;

  while( true ) {

    if (piVar1[2] == 1) break;

    if (piVar1[2] == 2) {

LAB_00482456:

      bVar3 = FUN_00482180();

      uVar2 = CONCAT11(uStack_4._3_1_,uStack_4._2_1_ | bVar3);

      uStack_4 = (uint)uVar2 << 0x10;

      if ((piVar1[1] == 2) || (piVar1[3] != 0)) {

        if (piVar1[0x11] < piVar1[0x12]) {

          if (*(int *)(*piVar1 + 4) == 0) {

LAB_004824c3:

            uStack_4._2_2_ = uVar2;

            if ((uStack_4._2_1_ == '\0') && (uStack_4._3_1_ == '\0')) {

              return 0;

            }

            return 1;

          }

        }

        else {

          FUN_004852c0(0);

          piVar1[2] = 1;

        }

      }

      else {

        if ((uint)piVar1[0xd] < 0x100) {

          FUN_004820a0();

        }

        piVar1[0xd] = 0x100;

        piVar1[0xe] = 0;

        FUN_004852c0(piVar1[1] == 4);

        piVar1[2] = 1;

      }

    }

  }

  bVar3 = FUN_00482350();

  uStack_4 = CONCAT13(uStack_4._3_1_ | bVar3,(undefined3)uStack_4);

  uVar2 = uStack_4._2_2_;

  if ((piVar1[0x14] < piVar1[0x13]) ||

     (((piVar1[1] == 4 && (piVar1[3] == 0)) && ((0xff < (uint)piVar1[0xd] || (piVar1[0xe] < 1))))))

  goto LAB_004824c3;

  piVar1[0x11] = 0;

  piVar1[0x13] = 0;

  piVar1[0x14] = 0;

  piVar1[0x98] = -1;

  piVar5 = piVar1 + 0x16;

  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

    *piVar5 = 0;

    piVar5 = piVar5 + 1;

  }

  piVar1[0x9b] = piVar1[0x9b] + 1;

  piVar1[2] = 2;

  if (((piVar1[1] == 3) && (piVar1[3] == 0)) && ((0xff < (uint)piVar1[0xd] || (piVar1[0xe] < 1))))

  goto LAB_004824c3;

  goto LAB_00482456;

}
