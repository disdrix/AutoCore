// =============================================================================
// FUN_00447dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00447dd0
// Address:   0x00447dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00447dd0 @ 0x00447dd0
// Stable ID: aa_00447dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00447dd0, FUN_00447ea0, FUN_00447fd0.
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

void FUN_00447dd0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  *unaff_EDI = *in_EAX;

  unaff_EDI[1] = in_EAX[1];

  unaff_EDI[2] = in_EAX[2];

  unaff_EDI[3] = in_EAX[3];

  *(uint8_t *)(unaff_EDI + 4) = *(uint8_t *)(in_EAX + 4);

  *(uint8_t *)((int)unaff_EDI + 0x11) = *(uint8_t *)((int)in_EAX + 0x11);

  unaff_EDI[5] = in_EAX[5];

  unaff_EDI[6] = in_EAX[6];

  unaff_EDI[7] = in_EAX[7];

  unaff_EDI[8] = in_EAX[8];

  unaff_EDI[9] = in_EAX[9];

  unaff_EDI[10] = in_EAX[10];

  unaff_EDI[0xb] = in_EAX[0xb];

  unaff_EDI[0xc] = in_EAX[0xc];

  unaff_EDI[0xd] = in_EAX[0xd];

  unaff_EDI[0xe] = in_EAX[0xe];

  unaff_EDI[0xf] = in_EAX[0xf];

  unaff_EDI[0x10] = in_EAX[0x10];

  puVar1 = unaff_EDI + 0x11;

  iVar2 = 0xd;

  do {

    *puVar1 = *(uint32_t /* width from decompiler */ *)(((int)in_EAX - (int)unaff_EDI) + (int)puVar1);

    puVar1[1] = *(uint32_t /* width from decompiler */ *)(((int)in_EAX - (int)unaff_EDI) + 4 + (int)puVar1);

    puVar1 = puVar1 + 2;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  FUN_00447ea0();

  unaff_EDI[0x2f] = in_EAX[0x2f];

  unaff_EDI[0x30] = in_EAX[0x30];

  FUN_00447fd0(in_EAX + 0x31);

  return;

}
