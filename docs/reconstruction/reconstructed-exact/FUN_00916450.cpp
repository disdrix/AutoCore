// =============================================================================
// FUN_00916450
// -----------------------------------------------------------------------------
// Stable ID: aa_00916450
// Address:   0x00916450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00916450 @ 0x00916450
// Stable ID: aa_00916450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_0040c3d0, FUN_00490070, FUN_0090d400, FUN_00916450.
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

uint32_t /* width from decompiler */ FUN_00916450(void)



{

  int *piVar1;

  char cVar2;

  int *in_EAX;

  int *piVar3;

  int iVar4;

  int local_60;

  int local_5c;

  uint8_t local_58 [84];

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  uint8_t local_1;

  

  local_2 = 0xff;

  local_3 = 0xff;

  local_4 = 0xff;

  local_1 = 0xff;

  local_60 = DAT_00d1d86c;

  local_5c = DAT_00d1d870;

  piVar3 = (int *)FUN_00490070(&local_60,local_58,0);

  if (piVar3 != (int *)0x0) {

    iVar4 = (**(code **)(*piVar3 + 0x210))(0);

    if ((iVar4 != 0) && (DAT_00d1b6d8 != 0)) {

      iVar4 = (**(code **)(*piVar3 + 0x210))(0);

      if (iVar4 != DAT_00d1b6d8) {

        cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                            0x298))(piVar3);

        if ((cVar2 == '\0') && (DAT_00d09a48 != (int *)0x0)) {

          FUN_0090d400();

          if ((DAT_00d09a48[0x70] != DAT_00d1e818) || (DAT_00d09a48[0x71] != DAT_00d1e81c)) {

            (**(code **)(*DAT_00d09a48 + 0x28))(0);

          }

          DAT_00d09a48[0x140] = DAT_00d1d86c;

          DAT_00d09a48[0x141] = DAT_00d1d870;

          piVar1 = DAT_00d09a48;

          DAT_00d09a48[0x148] = DAT_00d09a48[0x140];

          iVar4 = DAT_00d17944;

          DAT_00d09a48[0x149] = piVar1[0x141];

          (**(code **)(*DAT_00d09a48 + 0x46c))

                    ((DAT_00d1d86c <= *(int *)(*(int *)(iVar4 + 0x2c) + 0x80) / 3) + '\x02');

          (**(code **)(*DAT_00d09a48 + 0x474))

                    (DAT_00d1d870 <= (*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * 2) / 3);

          FUN_0040c3d0(piVar3[0x58],piVar3[0x59],piVar3[0x5a],piVar3[0x5b]);

          piVar3 = DAT_00d09a48;

          if (DAT_00d09a48 != (int *)0x0) {

            (**(code **)(*DAT_00d09a48 + 0x3d8))();

            cVar2 = (**(code **)(*piVar3 + 0x3d8))();

            if (cVar2 == '\0') {

              (**(code **)(*in_EAX + 0x3ec))();

              (**(code **)(*in_EAX + 0x3f4))(1);

              (**(code **)(*in_EAX + 0xa8))(piVar3);

              (**(code **)(*piVar3 + 0xcc))(1);

              (**(code **)(*piVar3 + 0x43c))();

            }

          }

          return 1;

        }

      }

    }

  }

  return 0;

}
