// =============================================================================
// FUN_0079c860
// -----------------------------------------------------------------------------
// Stable ID: aa_0079c860
// Address:   0x0079c860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079c860 @ 0x0079c860
// Stable ID: aa_0079c860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0079c860, FUN_007b5dd0.
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

void FUN_0079c860(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ in_EAX;

  uint8_t *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  FUN_007b5dd0(unaff_ESI,in_EAX);

  *unaff_ESI = &PTR_FUN_00a97c34;

  *(uint8_t *)((int)unaff_ESI + 0x49e) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x49d) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x127) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x49f) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4a2) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4a1) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x128) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4a3) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4a6) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4a5) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x129) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4a7) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4aa) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4a9) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x12a) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4ab) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4ae) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4ad) = 0xff;

  *(uint8_t *)(unaff_ESI + 299) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4af) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4b2) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4b1) = 0xff;

  *(uint8_t *)(unaff_ESI + 300) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4b3) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4b6) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4b5) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x12d) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4b7) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4ba) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4b9) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x12e) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4bb) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4be) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4bd) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x12f) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4bf) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4c2) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4c1) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x130) = 0xff;

  *(uint8_t *)((int)unaff_ESI + 0x4c3) = 0xff;

  *(uint8_t *)(unaff_ESI + 0x122) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x48a) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x489) = 0;

  puVar2 = (uint8_t *)((int)unaff_ESI + 0x491);

  iVar3 = 6;

  do {

    puVar2[-6] = 0;

    *puVar2 = 0;

    uVar1 = DAT_00a0f734;

    puVar2 = puVar2 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  unaff_ESI[0x126] = 0xffffffff;

  unaff_ESI[0x131] = uVar1;

  unaff_ESI[0x132] = 0;

  unaff_ESI[0x8a] = DAT_00d1e7b0;

  unaff_ESI[0x8b] = DAT_00d1e7b4;

  return;

}
