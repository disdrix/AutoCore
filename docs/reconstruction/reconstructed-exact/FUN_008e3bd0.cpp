// =============================================================================
// FUN_008e3bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e3bd0
// Address:   0x008e3bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e3bd0 @ 0x008e3bd0
// Stable ID: aa_008e3bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0040ee20, FUN_008e3bd0, Map_LowerBoundFindByIntKey.
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

void FUN_008e3bd0(void)



{

  int iVar1;

  int in_EAX;

  int *extraout_EAX;

  int unaff_ESI;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4 [4];

  

  if ((in_EAX != 0) && (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) == 0x1a)) {

    local_8 = *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0xa8) + 0x34);

    Map_LowerBoundFindByIntKey((void *)(unaff_ESI + 0x7f4),local_4,&local_8,unaff_EDI);

    iVar1 = *extraout_EAX;

    *(int *)(unaff_ESI + 0x800) = iVar1;

    if (iVar1 != *(int *)(unaff_ESI + 0x7f8)) {

      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;

      if (*(int *)(*(int *)(unaff_ESI + 0x800) + 0x10) < 1) {

        FUN_0040ee20(local_4,*(int *)(unaff_ESI + 0x800));

      }

    }

  }

  return;

}
