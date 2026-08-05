// =============================================================================
// FUN_0079d7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d7a0
// Address:   0x0079d7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079d7a0 @ 0x0079d7a0
// Stable ID: aa_0079d7a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, while×3, return×2, do×2.
//  - Notable callees: FUN_0079cec0×2, FUN_00782e60, FUN_0079d700, FUN_0079d7a0.
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

uint32_t /* width from decompiler */ FUN_0079d7a0(int param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *unaff_EBX;

  char local_100 [256];

  

  if (*(char *)(param_1 + 5) == '\0') {

    return 0;

  }

  iVar3 = FUN_0079cec0(local_100,0x100);

  do {

    if (iVar3 == 0) {

      iVar3 = *unaff_EBX;

      uVar6 = FUN_00782e60(*(uint32_t /* width from decompiler */ *)(iVar3 + 4));

      *(uint32_t /* width from decompiler */ *)(iVar3 + 4) = uVar6;

      return *(uint32_t /* width from decompiler */ *)*unaff_EBX;

    }

    pcVar4 = operator_new__(iVar3 + 1);

    pcVar5 = pcVar4;

    if (local_100[0] != '\0') {

      do {

        if (pcVar4 + iVar3 <= pcVar5) break;

        *pcVar5 = pcVar5[(int)(local_100 + -(int)pcVar4)];

        pcVar5 = pcVar5 + 1;

      } while (pcVar5[(int)(local_100 + -(int)pcVar4)] != '\0');

    }

    *pcVar5 = '\0';

    cVar2 = *pcVar4;

    pcVar5 = pcVar4;

    while (cVar2 != '\0') {

      if (('@' < cVar2) && (cVar2 < '[')) {

        *pcVar5 = cVar2 + ' ';

      }

      pcVar1 = pcVar5 + 1;

      pcVar5 = pcVar5 + 1;

      cVar2 = *pcVar1;

    }

    cVar2 = FUN_0079d700();

    if (cVar2 == '\0') {

      operator_delete__(pcVar4);

    }

    iVar3 = FUN_0079cec0(local_100,0x100);

  } while( true );

}
