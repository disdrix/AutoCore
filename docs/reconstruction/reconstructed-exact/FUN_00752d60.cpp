// =============================================================================
// FUN_00752d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00752d60
// Address:   0x00752d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752d60 @ 0x00752d60
// Stable ID: aa_00752d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00437d60, FUN_00439a70, FUN_00458510, FUN_00752d60.
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

void FUN_00752d60(void)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_24 [2];

  uint local_1c;

  

  uVar2 = *(uint *)(*(int *)(unaff_EDI + 8) + 0x18);

  uVar3 = *(uint *)(*(int *)(unaff_EDI + 8) + 0x14);

  local_1c = uVar2;

  if (uVar3 < uVar2) {

    do {

      iVar1 = (uint)*(ushort *)(*(int *)(*(int *)(unaff_EDI + 8) + 0x10) + 4 + uVar3 * 8) +

              *(int *)(unaff_EDI + 0xc);

      if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {

        local_24[0] = 2;

        FUN_00437d60(local_24);

        FUN_00439a70();

        FUN_00458510(local_24);

        uVar2 = local_1c;

      }

      uVar3 = uVar3 + 1;

    } while (uVar3 < uVar2);

  }

  return;

}
