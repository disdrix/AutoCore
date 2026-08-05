// =============================================================================
// FUN_00477290
// -----------------------------------------------------------------------------
// Stable ID: aa_00477290
// Address:   0x00477290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477290 @ 0x00477290
// Stable ID: aa_00477290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00477290.
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

void __fastcall FUN_00477290(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  uint8_t uVar1;

  uint8_t *in_EAX;

  int iVar2;

  

  if (*(char *)((int)param_2 + 9) == '\x10') {

    for (iVar2 = (uint)*(byte *)((int)param_2 + 10) * *param_2; iVar2 != 0; iVar2 = iVar2 + -1) {

      uVar1 = *in_EAX;

      *in_EAX = in_EAX[1];

      in_EAX[1] = uVar1;

      in_EAX = in_EAX + 2;

    }

  }

  return;

}
