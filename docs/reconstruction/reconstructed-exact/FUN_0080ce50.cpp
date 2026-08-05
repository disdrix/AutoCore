// =============================================================================
// FUN_0080ce50
// -----------------------------------------------------------------------------
// Stable ID: aa_0080ce50
// Address:   0x0080ce50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080ce50 @ 0x0080ce50
// Stable ID: aa_0080ce50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00530550, FUN_0080ce50, FUN_0090cbc0.
//  - Return sites: 2.

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

void __fastcall FUN_0080ce50(int param_1)



{

  char cVar1;

  int in_EAX;

  

  if (*(int *)(param_1 + 0xe98) != 0) {

    cVar1 = FUN_00530550(*(uint32_t /* width from decompiler */ *)(in_EAX + 4));

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x1034) + 0x514) + 0x3d8))();

      if (cVar1 != '\0') {

        FUN_0090cbc0();

        return;

      }

    }

  }

  return;

}
