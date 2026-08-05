// =============================================================================
// FUN_00965750
// -----------------------------------------------------------------------------
// Stable ID: aa_00965750
// Address:   0x00965750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00965750 @ 0x00965750
// Stable ID: aa_00965750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, do×1, while×1.
//  - Notable callees: Beep×2, FUN_0044fd20, FUN_00965750.
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

uint32_t /* width from decompiler */ FUN_00965750(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int iVar2;

  int iVar3;

  int iVar4;

  int unaff_EDI;

  

  if (*(char *)(unaff_EDI + 0x40) != '\0') {

    if (param_1 == 0x201) {

      iVar4 = *(int *)(unaff_EDI + 0x34);

      iVar2 = (int)(short)in_EAX - *(int *)(iVar4 + 0x78);

      iVar3 = (int)(short)((uint)in_EAX >> 0x10) - *(int *)(iVar4 + 0x7c);

      if ((((0 < iVar2) && (0 < iVar3)) && (iVar2 < *(int *)(iVar4 + 0x80))) &&

         (iVar3 < *(int *)(iVar4 + 0x84))) {

        if ((*(int *)(unaff_EDI + 0x44) == 0) ||

           (0.0 < *(float *)(*(int *)(unaff_EDI + 0x44) + 0x104))) {

          Beep(0x1b8,100);

        }

        else {

          iVar4 = *(int *)(unaff_EDI + 0x6c);

          iVar2 = *(int *)(unaff_EDI + 0x70);

          if (iVar4 != iVar2) {

            do {

              cVar1 = FUN_0044fd20();

              if (cVar1 != '\0') {

                if (*(int *)(*(int *)(*(int *)(iVar4 + 0x10) + 0x14) + 0x1c) ==

                    *(int *)(*(int *)(iVar4 + 0x18) + 0x1c)) {

                  *(int *)(*(int *)(iVar4 + 0x10) + 0x14) = *(int *)(iVar4 + 0x18);

                  *(uint8_t *)(unaff_EDI + 0x41) = 1;

                }

                else {

                  Beep(0x1b8,100);

                }

              }

              iVar4 = iVar4 + 0x1c;

            } while (iVar4 != iVar2);

            *(uint8_t *)(unaff_EDI + 0x78) = 1;

            return 1;

          }

        }

        *(uint8_t *)(unaff_EDI + 0x78) = 1;

        return 1;

      }

    }

    if ((*(char *)(unaff_EDI + 0x78) != '\0') && (param_1 == 0x202)) {

      *(uint8_t *)(unaff_EDI + 0x78) = 0;

      return 1;

    }

  }

  return 0;

}
