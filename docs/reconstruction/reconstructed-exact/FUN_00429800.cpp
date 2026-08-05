// =============================================================================
// FUN_00429800
// -----------------------------------------------------------------------------
// Stable ID: aa_00429800
// Address:   0x00429800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00429800 @ 0x00429800
// Stable ID: aa_00429800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00429800, FUN_004298d0.
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

void FUN_00429800(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  iVar1 = *(int *)(in_EAX + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(in_EAX + 8) - iVar1 >> 2) < (uint)(*(int *)(in_EAX + 0xc) - iVar1 >> 2))) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

    *puVar2 = *unaff_ESI;

    *(uint32_t /* width from decompiler */ **)(in_EAX + 8) = puVar2 + 1;

    return;

  }

  FUN_004298d0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),unaff_ESI);

  return;

}
