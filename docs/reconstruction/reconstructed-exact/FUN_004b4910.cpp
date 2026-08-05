// =============================================================================
// FUN_004b4910
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4910
// Address:   0x004b4910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4910 @ 0x004b4910
// Stable ID: aa_004b4910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_004b1a60, FUN_004b4100, FUN_004b4910.
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

void __thiscall FUN_004b4910(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  

  if ((g_flOne <= DAT_00af06e0) || (cVar2 = FUN_004b4100(param_2,param_1), cVar2 == '\0')) {

    piVar3 = (int *)(param_2 + 0x10010);

    iVar5 = 0x4004;

    do {

      iVar4 = *piVar3;

      if (-1 < iVar4 + -1) {

        piVar6 = (int *)(param_2 + 4 + (iVar4 + -1 + iVar5) * 4);

        do {

          iVar1 = *piVar6;

          FUN_004b1a60();

          (**(code **)(iVar1 + 0xc))();

          piVar6 = piVar6 + -1;

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

      }

      piVar3 = piVar3 + -0x1001;

      iVar5 = iVar5 + -0x1001;

    } while (-1 < iVar5);

  }

  return;

}
