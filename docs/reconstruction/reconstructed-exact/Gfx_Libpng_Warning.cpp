// =============================================================================
// Gfx_Libpng_Warning
// -----------------------------------------------------------------------------
// Stable ID: aa_00476fa0
// Address:   0x00476fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_Libpng_Warning for FUN_00476fa0 @ 0x00476fa0
// Stable ID: aa_00476fa0
// Embedded strings (evidence for future rename):
//   - "libpng warning: %s\n"
//   - "libpng warning no. %s: %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×1, while×1.
//  - Notable callees: fprintf×3, Gfx_Libpng_Warning.
//  - Strings: "libpng warning: %s\n"; "libpng warning no. %s: %s\n".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "libpng warning no. %s: %s
"
 * Domain alias of FUN_00476fa0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Gfx_Libpng_Warning(char *param_1)



{

  char cVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_14;

  char local_10 [16];

  

  if (*param_1 != '#') {

    fprintf((FILE *)(_iob_exref + 0x40),"libpng warning: %s\n",param_1);

    return;

  }

  iVar3 = 0;

  local_14 = local_10 + (4 - (int)param_1);

  do {

    cVar1 = param_1[iVar3];

    cVar2 = param_1[iVar3 + 1];

    param_1[(int)(local_10 + (iVar3 - (int)param_1))] = cVar2;

    if (cVar1 == ' ') break;

    cVar1 = param_1[iVar3 + 2];

    param_1[(int)(local_10 + iVar3 + (1 - (int)param_1))] = cVar1;

    if (cVar2 == ' ') {

      iVar3 = iVar3 + 1;

      break;

    }

    cVar2 = param_1[iVar3 + 3];

    param_1[(int)(local_10 + iVar3 + (2 - (int)param_1))] = cVar2;

    if (cVar1 == ' ') {

      iVar3 = iVar3 + 2;

      break;

    }

    cVar1 = param_1[iVar3 + 4];

    param_1[(int)(local_10 + iVar3 + (3 - (int)param_1))] = cVar1;

    if (cVar2 == ' ') {

      iVar3 = iVar3 + 3;

      break;

    }

    param_1[(int)(local_14 + iVar3)] = param_1[iVar3 + 5];

    if (cVar1 == ' ') {

      iVar3 = iVar3 + 4;

      break;

    }

    iVar3 = iVar3 + 5;

  } while (iVar3 < 0xf);

  if ((1 < iVar3) && (iVar3 < 0xf)) {

    local_10[iVar3 + -1] = '\0';

    fprintf((FILE *)(_iob_exref + 0x40),"libpng warning no. %s: %s\n",local_10,param_1 + iVar3);

    return;

  }

  fprintf((FILE *)(_iob_exref + 0x40),"libpng warning: %s\n",param_1);

  return;

}
