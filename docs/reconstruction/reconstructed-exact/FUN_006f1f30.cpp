// =============================================================================
// FUN_006f1f30
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1f30
// Address:   0x006f1f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1f30 @ 0x006f1f30
// Stable ID: aa_006f1f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006f39a0×4, FUN_006f3bb0×2, FUN_006f1f30.
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

void FUN_006f1f30(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  byte bVar4;

  int *piVar5;

  char *pcVar6;

  int local_10;

  

  iVar3 = (int)param_1 + 0x38;

  pcVar6 = (char *)((int)param_1 + 0x40);

  piVar5 = (int *)(param_2 + 0x10);

  local_10 = 3;

  param_1 = (int *)(param_2 + 0x28);

  do {

    if (*pcVar6 == '\x01') {

      iVar1 = *param_1;

      iVar2 = piVar5[-1];

      bVar4 = (byte)*(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

      FUN_006f39a0((*piVar5 - iVar1 >> (bVar4 & 0x1f)) + 1);

      FUN_006f39a0(iVar2 - iVar1 >> (bVar4 & 0x1f));

      FUN_006f39a0(pcVar6 + (0x1e - iVar3));

    }

    if (*pcVar6 == '\x02') {

      iVar1 = piVar5[-1];

      FUN_006f3bb0(*piVar5 + 1);

      FUN_006f3bb0(iVar1);

      FUN_006f39a0(pcVar6 + (0x21 - iVar3));

    }

    param_1 = param_1 + 1;

    pcVar6 = pcVar6 + 1;

    piVar5 = piVar5 + 2;

    local_10 = local_10 + -1;

  } while (local_10 != 0);

  return;

}
