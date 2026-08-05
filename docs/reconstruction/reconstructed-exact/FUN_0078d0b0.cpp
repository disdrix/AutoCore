// =============================================================================
// FUN_0078d0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078d0b0
// Address:   0x0078d0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078d0b0 @ 0x0078d0b0
// Stable ID: aa_0078d0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, goto×1.
//  - Notable callees: FUN_0078d0b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0078d0b0(int *param_1,int param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_3 < 0x68) {

    cVar1 = (**(code **)(*param_1 + 0x490))();

    if ((cVar1 == '\0') || (param_2 != 7)) {

      if ((100 < param_3) && ((param_3 < 0x68 && (param_2 == 7)))) {

        if ((param_3 != 0x66) ||

           ((param_1[0x24c] == 0 || (*(char *)(param_1[0x24c] + 0x489) != '\0')))) {

          (**(code **)(*param_1 + 0x488))();

        }

        return 1;

      }

      goto LAB_0078d132;

    }

  }

  else {

    if (param_2 != 8) {

LAB_0078d132:

      cVar1 = (**(code **)(*param_1 + 0xd8))();

      if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

        uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

        return uVar2;

      }

      return 0;

    }

    (**(code **)(*param_1 + 0x45c))(param_3);

  }

  (**(code **)(*param_1 + 0x48c))();

  return 1;

}
