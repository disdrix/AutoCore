// =============================================================================
// FUN_00472120
// -----------------------------------------------------------------------------
// Stable ID: aa_00472120
// Address:   0x00472120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00472120 @ 0x00472120
// Stable ID: aa_00472120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, do×3, while×3, for×1.
//  - Notable callees: FUN_00472120.
//  - Return sites: 4.

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

void __fastcall FUN_00472120(int param_1)



{

  uint8_t *puVar1;

  int iVar2;

  int *in_EAX;

  char *pcVar3;

  uint8_t *puVar4;

  uint8_t *puVar5;

  int iVar6;

  

  iVar6 = *in_EAX;

  if ((char)in_EAX[2] == '\x06') {

    if (*(char *)((int)in_EAX + 9) == '\b') {

      param_1 = in_EAX[1] + param_1;

      if (iVar6 != 0) {

        do {

          pcVar3 = (char *)(param_1 + -1);

          param_1 = param_1 + -4;

          iVar6 = iVar6 + -1;

          *pcVar3 = -1 - *pcVar3;

        } while (iVar6 != 0);

        return;

      }

    }

    else {

      param_1 = in_EAX[1] + param_1;

      if (iVar6 != 0) {

        do {

          *(char *)(param_1 + -1) = -1 - *(char *)(param_1 + -1);

          iVar6 = iVar6 + -1;

          *(char *)(param_1 + -2) = -1 - *(char *)(param_1 + -2);

          param_1 = param_1 + -8;

        } while (iVar6 != 0);

        return;

      }

    }

  }

  else if ((char)in_EAX[2] == '\x04') {

    if (*(char *)((int)in_EAX + 9) == '\b') {

      puVar4 = (uint8_t *)(in_EAX[1] + param_1);

      puVar5 = puVar4;

      if (iVar6 != 0) {

        do {

          puVar5[-1] = -1 - puVar4[-1];

          puVar1 = puVar4 + -2;

          puVar4 = puVar4 + -2;

          iVar6 = iVar6 + -1;

          puVar5[-2] = *puVar1;

          puVar5 = puVar5 + -2;

        } while (iVar6 != 0);

        return;

      }

    }

    else {

      iVar2 = in_EAX[1] + param_1;

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        *(char *)(iVar2 + -1) = -1 - *(char *)(iVar2 + -1);

        *(char *)(iVar2 + -2) = -1 - *(char *)(iVar2 + -2);

        iVar2 = iVar2 + -4;

      }

    }

  }

  return;

}
