// =============================================================================
// Gfx_Libpng_Error
// -----------------------------------------------------------------------------
// Stable ID: aa_00476e70
// Address:   0x00476e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_Libpng_Error for FUN_00476e70 @ 0x00476e70
// Stable ID: aa_00476e70
// Embedded strings (evidence for future rename):
//   - "libpng error: %s, offset=%d\n"
//   - "libpng error no. %s: %s\n"
//   - "libpng error: %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: fprintf×3, Gfx_Libpng_Error, longjmp.
//  - Strings: "libpng error: %s, offset=%d\n"; "libpng error no. %s: %s\n"; "libpng error: %s\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "libpng error: %s, offset=%d
"
 * Domain alias of FUN_00476e70 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Gfx_Libpng_Error(int *param_1)



{

  char cVar1;

  char cVar2;

  char *in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ local_14;

  char local_10 [16];

  

  if (*in_EAX == '#') {

    iVar3 = 0;

    local_14 = local_10 + (4 - (int)in_EAX);

    do {

      cVar1 = in_EAX[iVar3];

      cVar2 = in_EAX[iVar3 + 1];

      in_EAX[(int)(local_10 + (iVar3 - (int)in_EAX))] = cVar2;

      if (cVar1 == ' ') break;

      cVar1 = in_EAX[iVar3 + 2];

      in_EAX[(int)(local_10 + iVar3 + (1 - (int)in_EAX))] = cVar1;

      if (cVar2 == ' ') {

        iVar3 = iVar3 + 1;

        break;

      }

      cVar2 = in_EAX[iVar3 + 3];

      in_EAX[(int)(local_10 + iVar3 + (2 - (int)in_EAX))] = cVar2;

      if (cVar1 == ' ') {

        iVar3 = iVar3 + 2;

        break;

      }

      cVar1 = in_EAX[iVar3 + 4];

      in_EAX[(int)(local_10 + iVar3 + (3 - (int)in_EAX))] = cVar1;

      if (cVar2 == ' ') {

        iVar3 = iVar3 + 3;

        break;

      }

      in_EAX[(int)(local_14 + iVar3)] = in_EAX[iVar3 + 5];

      if (cVar1 == ' ') {

        iVar3 = iVar3 + 4;

        break;

      }

      iVar3 = iVar3 + 5;

    } while (iVar3 < 0xf);

    if ((iVar3 < 2) || (0xe < iVar3)) {

      fprintf((FILE *)(_iob_exref + 0x40),"libpng error: %s, offset=%d\n");

    }

    else {

      local_10[iVar3 + -1] = '\0';

      fprintf((FILE *)(_iob_exref + 0x40),"libpng error no. %s: %s\n",local_10,in_EAX + iVar3);

    }

  }

  else {

    fprintf((FILE *)(_iob_exref + 0x40),"libpng error: %s\n");

  }

                    /* WARNING: Subroutine does not return */

  longjmp(param_1,1);

}
