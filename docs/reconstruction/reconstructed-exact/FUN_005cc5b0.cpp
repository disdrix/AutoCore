// =============================================================================
// FUN_005cc5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc5b0
// Address:   0x005cc5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cc5b0 @ 0x005cc5b0
// Stable ID: aa_005cc5b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_005083f0×2, FUN_005cc5b0.
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

void __fastcall FUN_005cc5b0(int param_1)



{

  int iVar1;

  int iVar2;

  

  if ((((*(int *)(param_1 + 0x18) != 0) &&

       (iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0xa4), iVar1 != 0)) &&

      (iVar2 = *(int *)(param_1 + 100), iVar2 != 0)) &&

     (*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x38) != 0x14)) {

    if ((*(uint *)(iVar2 + 0x210) & *(uint *)(iVar2 + 0x214)) == 0xffffffff) {

      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;

      if (*(char *)(param_1 + 0x21) == '\0') {

        *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;

      }

      if (*(char *)(param_1 + 0x6d) != '\0') {

        *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + -1;

      }

    }

    else {

      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + -1;

      if (*(char *)(param_1 + 0x21) == '\0') {

        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + -1;

      }

      if (*(char *)(param_1 + 0x6d) != '\0') {

        *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + -1;

        FUN_005083f0();

        return;

      }

    }

  }

  FUN_005083f0();

  return;

}
