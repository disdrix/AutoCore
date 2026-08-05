// =============================================================================
// FUN_008b92f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b92f0
// Address:   0x008b92f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b92f0 @ 0x008b92f0
// Stable ID: aa_008b92f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0082ad00, FUN_008b92f0.
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

void __fastcall FUN_008b92f0(char *param_1)



{

  char cVar1;

  int in_EAX;

  char *pcVar2;

  int unaff_EBX;

  

  if ((-1 < unaff_EBX) && (unaff_EBX < 0xf)) {

    if (*(int *)(in_EAX + 0x568 + unaff_EBX * 4) != 0) {

      FUN_0082ad00();

    }

    if ((void *)(&DAT_00d17788)[unaff_EBX] != (void *)0x0) {

      operator_delete__((void *)(&DAT_00d17788)[unaff_EBX]);

    }

    (&DAT_00d17788)[unaff_EBX] = 0;

    if (param_1 != (char *)0x0) {

      pcVar2 = param_1;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(param_1 + 1))));

      (&DAT_00d17788)[unaff_EBX] = pcVar2;

      do {

        cVar1 = *param_1;

        *pcVar2 = cVar1;

        param_1 = param_1 + 1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

    }

  }

  return;

}
