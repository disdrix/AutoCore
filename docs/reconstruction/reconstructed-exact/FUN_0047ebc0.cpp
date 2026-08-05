// =============================================================================
// FUN_0047ebc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047ebc0
// Address:   0x0047ebc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047ebc0 @ 0x0047ebc0
// Stable ID: aa_0047ebc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0047f440×3, FUN_0047ebc0.
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

void FUN_0047ebc0(void)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(in_EAX + 0x16b4);

  *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | (ushort)(2 << ((byte)iVar2 & 0x1f));

  if (iVar2 < 0xe) {

    *(int *)(in_EAX + 0x16b4) = iVar2 + 3;

  }

  else {

    *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

         *(uint8_t *)(in_EAX + 0x16b0);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

         *(uint8_t *)(in_EAX + 0x16b1);

    iVar2 = *(int *)(in_EAX + 0x16b4);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(int *)(in_EAX + 0x16b4) = iVar2 + -0xd;

    *(ushort *)(in_EAX + 0x16b0) = 2 >> (0x10U - (char)iVar2 & 0x1f);

  }

  iVar2 = *(int *)(in_EAX + 0x16b4);

  *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | (ushort)(0 << ((byte)iVar2 & 0x1f));

  if (iVar2 < 10) {

    *(int *)(in_EAX + 0x16b4) = iVar2 + 7;

  }

  else {

    *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

         *(uint8_t *)(in_EAX + 0x16b0);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

         *(uint8_t *)(in_EAX + 0x16b1);

    iVar2 = *(int *)(in_EAX + 0x16b4);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(int *)(in_EAX + 0x16b4) = iVar2 + -9;

    *(ushort *)(in_EAX + 0x16b0) = 0 >> (0x10U - (char)iVar2 & 0x1f);

  }

  iVar1 = FUN_0047f440();

  iVar2 = *(int *)(iVar1 + 0x16b4);

  if ((*(int *)(iVar1 + 0x16ac) - iVar2) + 0xb < 9) {

    *(ushort *)(iVar1 + 0x16b0) = *(ushort *)(iVar1 + 0x16b0) | (ushort)(2 << ((byte)iVar2 & 0x1f));

    if (iVar2 < 0xe) {

      *(int *)(iVar1 + 0x16b4) = iVar2 + 3;

    }

    else {

      *(uint8_t *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 0x14)) =

           *(uint8_t *)(iVar1 + 0x16b0);

      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

      *(uint8_t *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) =

           *(uint8_t *)(iVar1 + 0x16b1);

      iVar2 = *(int *)(iVar1 + 0x16b4);

      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

      *(int *)(iVar1 + 0x16b4) = iVar2 + -0xd;

      *(ushort *)(iVar1 + 0x16b0) = 2 >> (0x10U - (char)iVar2 & 0x1f);

    }

    iVar2 = *(int *)(iVar1 + 0x16b4);

    *(ushort *)(iVar1 + 0x16b0) = *(ushort *)(iVar1 + 0x16b0) | (ushort)(0 << ((byte)iVar2 & 0x1f));

    if (9 < iVar2) {

      *(uint8_t *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 0x14)) =

           *(uint8_t *)(iVar1 + 0x16b0);

      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

      *(uint8_t *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) =

           *(uint8_t *)(iVar1 + 0x16b1);

      iVar2 = *(int *)(iVar1 + 0x16b4);

      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

      *(int *)(iVar1 + 0x16b4) = iVar2 + -9;

      *(ushort *)(iVar1 + 0x16b0) = 0 >> (0x10U - (char)iVar2 & 0x1f);

      iVar2 = FUN_0047f440();

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x16ac) = 7;

      return;

    }

    *(int *)(iVar1 + 0x16b4) = iVar2 + 7;

    iVar1 = FUN_0047f440();

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x16ac) = 7;

  return;

}
