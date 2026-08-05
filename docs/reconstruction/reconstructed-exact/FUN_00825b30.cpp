// =============================================================================
// FUN_00825b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00825b30
// Address:   0x00825b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00825b30 @ 0x00825b30
// Stable ID: aa_00825b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007916e0, FUN_00825b30.
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

void __thiscall FUN_00825b30(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  

  cVar1 = (**(code **)(*param_1 + 0xd0))();

  if (cVar1 != (char)param_2) {

    FUN_007916e0(param_2);

    if ((char)param_2 == '\x01') {

      if ((param_1[0x153] != 0) && (*(char *)((int)param_1 + 0x4fe) == '\x01')) {

        (**(code **)(*(int *)param_1[0x153] + 0xcc))(0);

      }

      (**(code **)(*param_1 + 0x444))();

      (**(code **)(*param_1 + 0x448))();

    }

  }

  return;

}
