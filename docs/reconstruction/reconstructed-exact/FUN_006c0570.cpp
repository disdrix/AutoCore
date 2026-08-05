// =============================================================================
// FUN_006c0570
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0570
// Address:   0x006c0570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c0570 @ 0x006c0570
// Stable ID: aa_006c0570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: FUN_006c0570.
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

void FUN_006c0570(uint8_t *param_1,int param_2,int param_3,char *param_4,char *param_5,

                 char *param_6)



{

  short sVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  bool bVar7;

  

  sVar1 = **(short **)(param_2 + 0x10);

  sVar2 = **(short **)(param_2 + 0x14);

  sVar3 = **(short **)(param_2 + 0x18);

  sVar4 = **(short **)(param_3 + 0x10);

  sVar5 = **(short **)(param_3 + 0x14);

  sVar6 = **(short **)(param_3 + 0x18);

  bVar7 = true;

  if (sVar1 == sVar4) {

    if ((sVar2 == sVar5) || (sVar2 == sVar6)) {

      bVar7 = *param_4 == '\0';

      *param_4 = '\x01';

    }

    if ((sVar3 == sVar5) || (sVar3 == sVar6)) {

      if (*param_5 != '\0') {

        bVar7 = false;

      }

      *param_5 = '\x01';

    }

  }

  if (sVar1 == sVar5) {

    if (sVar2 == sVar6) {

      if (*param_4 != '\0') {

        bVar7 = false;

      }

      *param_4 = '\x01';

    }

    if (sVar3 == sVar6) {

      if (*param_5 != '\0') {

        bVar7 = false;

      }

      *param_5 = '\x01';

    }

  }

  if (((sVar2 == sVar4) && ((sVar3 == sVar5 || (sVar3 == sVar6)))) ||

     ((sVar2 == sVar5 && (sVar3 == sVar6)))) {

    if (*param_6 != '\0') {

      bVar7 = false;

    }

    *param_6 = '\x01';

  }

  *param_1 = bVar7;

  return;

}
