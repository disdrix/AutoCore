// =============================================================================
// FUN_007943c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007943c0
// Address:   0x007943c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007943c0 @ 0x007943c0
// Stable ID: aa_007943c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, goto×2, return×1.
//  - Notable callees: FUN_00423f40×2, FUN_004294f0, FUN_007943c0, LeaveCriticalSection.
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

int FUN_007943c0(int param_1)



{

  char *pcVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  char *pcVar4;

  int iVar5;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar5 = param_1;

  param_1 = 0;

  local_4 = 0;

  local_8 = (int *)0x0;

  FUN_004294f0();

  iVar3 = FUN_00423f40(&local_8);

  do {

    if ((iVar3 != 0) || (iVar5 < 1)) goto LAB_00794477;

    if ((*local_8 == 1) &&

       ((pcVar4 = (char *)local_8[1], pcVar4 != (char *)0x0 && (*pcVar4 != '\0')))) {

      pcVar1 = pcVar4 + 1;

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      iVar3 = (int)pcVar4 - (int)pcVar1;

      if (iVar5 < iVar3) {

        param_1 = param_1 + iVar5;

LAB_00794477:

        if (*(char *)(in_EAX + 0x210) != '\0') {

          *(uint8_t *)(in_EAX + 0x210) = 0;

          LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x1ec));

        }

        return param_1;

      }

      iVar5 = iVar5 - iVar3;

LAB_0079445b:

      param_1 = param_1 + iVar3;

    }

    else if ((*local_8 == 0xc) && (local_8[1] != 0)) {

      pcVar4 = *(char **)(local_8[1] + 0x1c);

      iVar5 = iVar5 + -1;

      if (pcVar4 != (char *)0x0) {

        pcVar1 = pcVar4 + 1;

        do {

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        iVar3 = (int)pcVar4 - (int)pcVar1;

        goto LAB_0079445b;

      }

    }

    iVar3 = FUN_00423f40(&local_8);

  } while( true );

}
