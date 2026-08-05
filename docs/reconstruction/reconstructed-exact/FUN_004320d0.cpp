// =============================================================================
// FUN_004320d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004320d0
// Address:   0x004320d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004320d0 @ 0x004320d0
// Stable ID: aa_004320d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: ROUND×2, floor×2, FUN_004320d0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_004320d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar2;

  double dVar3;

  

  dVar3 = _DAT_00aaa650;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1b0) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1ac) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1b4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x2c) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30);

  for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = param_2;

  *(uint8_t *)(unaff_ESI + 0x154) = 0x5a;

  *(uint8_t *)(unaff_ESI + 0x17c) = 0xff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14c) = 0xffffffff;

  *(uint8_t *)(unaff_ESI + 0x17e) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x164) = 0x60;

  dVar3 = floor(dVar3);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x168) = 0x60;

  *(int *)(unaff_ESI + 0x20) = (int)ROUND(dVar3);

  dVar3 = floor(_DAT_00aaa650);

  *(int *)(unaff_ESI + 0x24) = (int)ROUND(dVar3);

  return;

}
