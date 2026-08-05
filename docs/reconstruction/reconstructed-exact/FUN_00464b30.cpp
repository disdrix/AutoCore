// =============================================================================
// FUN_00464b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00464b30
// Address:   0x00464b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00464b30 @ 0x00464b30
// Stable ID: aa_00464b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00746520×2, FUN_00464b30.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00464b30(void)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EDI;

  

  iVar1 = *(int *)(in_EAX + 4);

  if (*(int *)(iVar1 + 0x10) == 0) {

    return 0;

  }

  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 0x18);

  if (*(int *)(*(int *)(iVar1 + 0x10) + 0xc) - *(int *)(iVar1 + 0x14) < unaff_EDI) {

    uVar2 = FUN_00746520(0,unaff_EDI,1);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14) = 0;

    *(int *)(iVar1 + 0x18) = unaff_EDI;

    return uVar2;

  }

  uVar2 = FUN_00746520(*(int *)(iVar1 + 0x14),unaff_EDI,2);

  *(int *)(iVar1 + 0x18) = unaff_EDI;

  return uVar2;

}
