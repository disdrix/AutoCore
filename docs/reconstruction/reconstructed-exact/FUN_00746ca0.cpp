// =============================================================================
// FUN_00746ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00746ca0
// Address:   0x00746ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746ca0 @ 0x00746ca0
// Stable ID: aa_00746ca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, do×1, while×1.
//  - Notable callees: FUN_00746ca0.
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

uint32_t /* width from decompiler */ FUN_00746ca0(void)



{

  char cVar1;

  int iVar2;

  int in_EAX;

  int iVar3;

  char *pcVar4;

  int iVar5;

  

  iVar2 = *(int *)(in_EAX + 4);

  if (iVar2 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(in_EAX + 8) - iVar2 >> 3;

  }

  iVar5 = 0;

  if (iVar3 + -1 < 1) {

    return 1;

  }

  pcVar4 = (char *)(iVar2 + 4);

  do {

    if (pcVar4[2] == '\x01') {

      cVar1 = *pcVar4;

      if (cVar1 == '\0') {

        return 2;

      }

      if (cVar1 == '\x01') {

        return 3;

      }

      if (cVar1 == '\x02') {

        return 4;

      }

    }

    iVar5 = iVar5 + 1;

    pcVar4 = pcVar4 + 8;

    if (iVar3 + -1 <= iVar5) {

      return 1;

    }

  } while( true );

}
