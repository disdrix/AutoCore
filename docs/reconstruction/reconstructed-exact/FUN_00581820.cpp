// =============================================================================
// FUN_00581820
// -----------------------------------------------------------------------------
// Stable ID: aa_00581820
// Address:   0x00581820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581820 @ 0x00581820
// Stable ID: aa_00581820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×13, do×3, while×3, goto×3, return×3.
//  - Notable callees: FUN_00785ca0×7, CONCAT31, FUN_00517680, FUN_00581820.
//  - Return sites: 3.

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

uint __fastcall FUN_00581820(int param_1)



{

  char *pcVar1;

  char cVar2;

  uint uVar3;

  char *pcVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x88));

  if ((char)uVar3 == '\0') {

    cVar2 = *(char *)(param_1 + -0x82);

    uVar3 = CONCAT31((int3)(uVar3 >> 8),cVar2);

    if (((cVar2 == '\0') || (cVar2 == '\x01')) || (cVar2 == '\x03')) {

      uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x7c));

      if ((char)uVar3 == '\0') {

        uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x78));

        if ((char)uVar3 == '\0') {

          pcVar4 = *(char **)(param_1 + -0x78);

          if (pcVar4 != (char *)0x0) {

            pcVar1 = pcVar4 + 1;

            do {

              cVar2 = *pcVar4;

              pcVar4 = pcVar4 + 1;

            } while (cVar2 != '\0');

            uVar3 = (int)pcVar4 - (int)pcVar1;

            if (0x104 < uVar3) goto LAB_00581935;

          }

          uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x74));

          if ((char)uVar3 == '\0') {

            pcVar4 = *(char **)(param_1 + -0x74);

            if (pcVar4 != (char *)0x0) {

              pcVar1 = pcVar4 + 1;

              do {

                cVar2 = *pcVar4;

                pcVar4 = pcVar4 + 1;

              } while (cVar2 != '\0');

              uVar3 = (int)pcVar4 - (int)pcVar1;

              if (0x104 < uVar3) goto LAB_00581935;

            }

            uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x6c));

            if ((char)uVar3 == '\0') {

              uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x68));

              if ((char)uVar3 == '\0') {

                uVar3 = 0;

                puVar6 = (uint32_t /* width from decompiler */ *)(param_1 + -100);

                do {

                  uVar5 = FUN_00785ca0(*puVar6);

                  if ((char)uVar5 != '\0') goto LAB_0058192f;

                  uVar3 = uVar3 + 1;

                  puVar6 = puVar6 + 1;

                } while (uVar3 < 0x13);

                uVar5 = *(uint *)(param_1 + -0x18);

                if ((-2 < (int)uVar5) && ((int)uVar5 < 0x13)) {

                  uVar3 = FUN_00517680();

                  return uVar3;

                }

LAB_0058192f:

                return uVar5 & 0xffffff00;

              }

            }

          }

        }

      }

    }

  }

LAB_00581935:

  return uVar3 & 0xffffff00;

}
