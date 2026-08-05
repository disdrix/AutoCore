// =============================================================================
// FUN_00835240
// -----------------------------------------------------------------------------
// Stable ID: aa_00835240
// Address:   0x00835240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00835240 @ 0x00835240
// Stable ID: aa_00835240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00835240.
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

void FUN_00835240(byte param_1)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  int *unaff_ESI;

  

  if (unaff_ESI != (int *)0x0) {

    iVar3 = (**(code **)(*unaff_ESI + 0x1d8))();

    if (iVar3 != 0) {

      iVar3 = (**(code **)(*unaff_ESI + 0x1d8))();

      if (*(char *)(iVar3 + 0x30c) != '\0') {

        iVar3 = (**(code **)(*unaff_ESI + 0x1d8))();

        if (*(int *)(iVar3 + 0x250) != 0) {

          iVar3 = (**(code **)(*unaff_ESI + 0x1d8))();

          iVar3 = *(int *)(iVar3 + 0x250);

          iVar2 = *(int *)(*(int *)(iVar3 + 4) + 4);

          puVar1 = (uint *)(iVar2 + iVar3 + 0x188);

          *puVar1 = *puVar1 ^ ((uint)param_1 * 2 ^ *(uint *)(iVar2 + 0x188 + iVar3)) & 2;

          return;

        }

      }

    }

    unaff_ESI[0x61] = unaff_ESI[0x61] ^ ((uint)param_1 * 2 ^ unaff_ESI[0x61]) & 2;

  }

  return;

}
