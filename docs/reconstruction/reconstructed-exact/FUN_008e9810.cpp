// =============================================================================
// FUN_008e9810
// -----------------------------------------------------------------------------
// Stable ID: aa_008e9810
// Address:   0x008e9810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e9810 @ 0x008e9810
// Stable ID: aa_008e9810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_007916e0, FUN_008e88f0, FUN_008e9810.
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

void __thiscall FUN_008e9810(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  

  cVar1 = (**(code **)(*param_1 + 0xd0))();

  if (((char)param_2 != cVar1) && (FUN_007916e0(param_2), (char)param_2 != '\0')) {

    (**(code **)(*param_1 + 0x448))();

    FUN_008e88f0();

    param_1 = param_1 + 0x16e;

    iVar2 = 4;

    do {

      if (*param_1 != 0) {

        (**(code **)(*(int *)*param_1 + 4))(0);

      }

      param_1 = param_1 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}
