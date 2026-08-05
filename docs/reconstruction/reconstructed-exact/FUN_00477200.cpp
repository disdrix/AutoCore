// =============================================================================
// FUN_00477200
// -----------------------------------------------------------------------------
// Stable ID: aa_00477200
// Address:   0x00477200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477200 @ 0x00477200
// Stable ID: aa_00477200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×3.
//  - Notable callees: FUN_00477200.
//  - Return sites: 3.

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

void __fastcall FUN_00477200(int param_1)



{

  byte *in_EAX;

  byte *pbVar1;

  int iVar2;

  

  if (*(char *)(param_1 + 8) == '\0') {

    iVar2 = *(int *)(param_1 + 4);

    if (iVar2 != 0) {

      do {

        *in_EAX = ~*in_EAX;

        in_EAX = in_EAX + 1;

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

      return;

    }

  }

  else if (*(char *)(param_1 + 8) == '\x04') {

    if (*(char *)(param_1 + 9) == '\b') {

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 4) - 1U >> 1) + 1;

        do {

          *in_EAX = ~*in_EAX;

          in_EAX = in_EAX + 2;

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

        return;

      }

    }

    else if ((*(char *)(param_1 + 9) == '\x10') && (*(int *)(param_1 + 4) != 0)) {

      pbVar1 = in_EAX + 1;

      iVar2 = (*(int *)(param_1 + 4) - 1U >> 2) + 1;

      do {

        pbVar1[-1] = ~pbVar1[-1];

        *pbVar1 = ~*pbVar1;

        pbVar1 = pbVar1 + 4;

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

    }

  }

  return;

}
