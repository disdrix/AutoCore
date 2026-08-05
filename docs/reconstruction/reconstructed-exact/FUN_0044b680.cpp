// =============================================================================
// FUN_0044b680
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b680
// Address:   0x0044b680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044b680 @ 0x0044b680
// Stable ID: aa_0044b680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_0044b680.
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

uint __fastcall FUN_0044b680(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int in_EAX;

  uint uVar1;

  int iVar2;

  uint uVar3;

  char *pcVar4;

  char *pcVar5;

  bool bVar6;

  

  pcVar4 = *(char **)(param_2 + 4);

  if (pcVar4 == (char *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_2 + 8) - (int)pcVar4 >> 3;

  }

  pcVar5 = *(char **)(in_EAX + 4);

  if (pcVar5 == (char *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(in_EAX + 8) - (int)pcVar5 >> 3;

  }

  if (uVar3 == uVar1) {

    if (pcVar4 == (char *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_2 + 8) - (int)pcVar4 >> 3;

    }

    iVar2 = iVar2 * 8 + -8;

    uVar1 = 0;

    bVar6 = true;

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar6 = *pcVar4 == *pcVar5;

      pcVar4 = pcVar4 + 1;

      pcVar5 = pcVar5 + 1;

    } while (bVar6);

    if (bVar6) {

      return 1;

    }

  }

  return uVar1 & 0xffffff00;

}
