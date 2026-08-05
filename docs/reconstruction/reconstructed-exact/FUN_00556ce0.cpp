// =============================================================================
// FUN_00556ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00556ce0
// Address:   0x00556ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00556ce0 @ 0x00556ce0
// Stable ID: aa_00556ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_00556ce0, FUN_005590d0.
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

void __thiscall FUN_00556ce0(uint8_t *param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  int iVar4;

  

  FUN_005590d0(param_2 + 0x430);

  pcVar2 = (char *)(param_2 + 0x440);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x544);

  if (*pcVar2 == '\0') {

    param_1[0x440] = 0;

  }

  else {

    iVar3 = (int)(param_1 + 0x440) - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  param_1[0x54c] = *(uint8_t *)(param_2 + 0x54c);

  param_2 = param_2 - (int)param_1;

  iVar3 = 4;

  do {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = *(uint32_t /* width from decompiler */ *)(param_1 + param_2 + 0x104);

    pcVar2 = param_1 + param_2;

    if (param_1[param_2] == '\0') {

      *param_1 = 0;

    }

    else {

      iVar4 = (int)param_1 - (int)pcVar2;

      do {

        cVar1 = *pcVar2;

        pcVar2[iVar4] = cVar1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

    }

    param_1 = param_1 + 0x10c;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
