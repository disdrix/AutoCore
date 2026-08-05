// =============================================================================
// FUN_007fce10
// -----------------------------------------------------------------------------
// Stable ID: aa_007fce10
// Address:   0x007fce10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fce10 @ 0x007fce10
// Stable ID: aa_007fce10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, goto×3, while×3, return×1.
//  - Notable callees: FUN_007fce10.
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

void FUN_007fce10(int param_1)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  char cVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int local_4;

  

  if (DAT_00d1b6d8 != 0) {

    iVar1 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x74 + DAT_00d1b6d8);

    cVar4 = '\0';

    local_4 = 0;

    piVar6 = (int *)(param_1 + 0x3220);

    do {

      iVar5 = 0;

      do {

        piVar6[5] = local_4 + iVar5;

        if (iVar1 == 0) {

LAB_007fcebe:

          iVar7 = *(int *)(DAT_00d1b6d8 + 0x930 + (uint)(byte)(cVar4 * '\n' + (char)iVar5) * 8);

          piVar6[2] = iVar7;

          piVar6[3] = iVar7 >> 0x1f;

          piVar6[4] = 0;

          if (iVar7 == -1) {

            *piVar6 = 0;

          }

          else if (iVar7 < -2000) {

            *piVar6 = 5;

          }

          else if (iVar7 < -1000) {

            *piVar6 = 4;

          }

          else {

            *piVar6 = (iVar7 < 0) + 2;

          }

        }

        else {

          uVar2 = *(uint *)(DAT_00d1b6d8 + 0x74c + (uint)(byte)(cVar4 * '\n' + (char)iVar5) * 4);

          iVar7 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) + (*(uint *)(iVar1 + 8) & uVar2) * 4) + 4

                          );

          if (iVar7 == 0) {

LAB_007fce9b:

            iVar7 = 0;

          }

          else {

            do {

              if (uVar2 == *(uint *)(iVar7 + 0x10)) {

                if (iVar7 == 0) goto LAB_007fce9b;

                iVar7 = *(int *)(iVar7 + 8);

                goto LAB_007fcea2;

              }

              iVar7 = *(int *)(iVar7 + 0xc);

            } while (iVar7 != 0);

            iVar7 = 0;

          }

LAB_007fcea2:

          if (iVar7 == 0) goto LAB_007fcebe;

          iVar3 = *(int *)(iVar7 + 0x5fc);

          piVar6[2] = iVar3;

          piVar6[3] = iVar3 >> 0x1f;

          piVar6[4] = iVar7;

          *piVar6 = 1;

        }

        iVar5 = iVar5 + 1;

        piVar6 = piVar6 + 6;

      } while (iVar5 < 10);

      cVar4 = cVar4 + '\x01';

      local_4 = local_4 + 10;

    } while (local_4 < 100);

  }

  return;

}
