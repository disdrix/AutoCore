// =============================================================================
// FUN_00719630
// -----------------------------------------------------------------------------
// Stable ID: aa_00719630
// Address:   0x00719630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00719630 @ 0x00719630
// Stable ID: aa_00719630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: do×6, while×6, return×5, if×4, for×1.
//  - Notable callees: strrchr×2, FUN_00719630, _strnicmp.
//  - Return sites: 5.

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

void __fastcall FUN_00719630(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  int unaff_EBX;

  char *unaff_ESI;

  

  if (param_2 != (char *)0x0) {

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    iVar3 = _strnicmp(param_2,unaff_ESI,(int)pcVar2 - (int)(param_2 + 1));

    if (iVar3 == 0) {

      for (pcVar2 = unaff_ESI + ((int)pcVar2 - (int)(param_2 + 1));

          (*pcVar2 == '/' || (*pcVar2 == '\\')); pcVar2 = pcVar2 + 1) {

      }

      iVar3 = unaff_EBX - (int)pcVar2;

      do {

        cVar1 = *pcVar2;

        pcVar2[iVar3] = cVar1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      return;

    }

    iVar3 = unaff_EBX - (int)unaff_ESI;

    do {

      cVar1 = *unaff_ESI;

      unaff_ESI[iVar3] = cVar1;

      unaff_ESI = unaff_ESI + 1;

    } while (cVar1 != '\0');

    return;

  }

  pcVar2 = strrchr(unaff_ESI,0x2f);

  if (pcVar2 != (char *)0x0) {

    pcVar2 = pcVar2 + 1;

    iVar3 = unaff_EBX - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    return;

  }

  pcVar2 = strrchr(unaff_ESI,0x5c);

  if (pcVar2 != (char *)0x0) {

    pcVar2 = pcVar2 + 1;

    iVar3 = unaff_EBX - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[iVar3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    return;

  }

  iVar3 = unaff_EBX - (int)unaff_ESI;

  do {

    cVar1 = *unaff_ESI;

    unaff_ESI[iVar3] = cVar1;

    unaff_ESI = unaff_ESI + 1;

  } while (cVar1 != '\0');

  return;

}
