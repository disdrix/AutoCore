// =============================================================================
// FUN_004772c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004772c0
// Address:   0x004772c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004772c0 @ 0x004772c0
// Stable ID: aa_004772c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1.
//  - Notable callees: FUN_004772c0.
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

void __fastcall FUN_004772c0(int param_1)



{

  byte bVar1;

  byte *in_EAX;

  byte *pbVar2;

  undefined *puVar3;

  

  bVar1 = *(byte *)(param_1 + 9);

  if (bVar1 < 8) {

    pbVar2 = in_EAX + *(int *)(param_1 + 4);

    if (bVar1 == 1) {

      puVar3 = &DAT_00afa648;

    }

    else if (bVar1 == 2) {

      puVar3 = &DAT_00afa748;

    }

    else {

      if (bVar1 != 4) {

        return;

      }

      puVar3 = &DAT_00afa848;

    }

    for (; in_EAX < pbVar2; in_EAX = in_EAX + 1) {

      *in_EAX = puVar3[*in_EAX];

    }

  }

  return;

}
