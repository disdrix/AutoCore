// =============================================================================
// FUN_0042d510
// -----------------------------------------------------------------------------
// Stable ID: aa_0042d510
// Address:   0x0042d510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042d510 @ 0x0042d510
// Stable ID: aa_0042d510
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Sending Connect Challenge Request to %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: BitStream_writeBits×2, BitStream_writeFlag×2, FUN_00424d10, FUN_0042d510, FUN_00783aa0, FUN_00783b60, FUN_007845c0, FUN_00784d20.
//  - Strings: "LogNetInterface"; "Sending Connect Challenge Request to %s".
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



void FUN_0042d510(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_ESI;

  int unaff_EDI;

  uint8_t local_70d;

  undefined **local_70c;

  uint32_t /* width from decompiler */ local_708;

  uint32_t /* width from decompiler */ local_704;

  uint8_t *local_700;

  uint32_t /* width from decompiler */ local_6fc;

  uint8_t local_6f8;

  int local_6f4;

  uint8_t local_6f0;

  uint8_t local_6ef;

  uint32_t /* width from decompiler */ local_6e0;

  uint32_t /* width from decompiler */ local_6dc;

  uint32_t /* width from decompiler */ local_6d8;

  uint8_t local_6d4;

  uint8_t local_5d4 [1492];

  

  if ((_DAT_00d20bf8 & 1) == 0) {

    _DAT_00d20bf8 = _DAT_00d20bf8 | 1;

    DAT_00d20bf4 = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d20bf4 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20bf4;

    uVar1 = FUN_007845c0();

    FUN_00783aa0("Sending Connect Challenge Request to %s",uVar1);

    DAT_00d179a0 = 0;

  }

  local_700 = local_5d4;

  local_708 = 0;

  local_704 = 0;

  local_6fc = 0x5d2;

  local_6f8 = 0;

  local_6e0 = 0x2e90;

  local_6dc = 0x2e90;

  local_6f4 = 0;

  local_6f0 = 0;

  local_6ef = 0;

  local_6d4 = 0;

  local_6d8 = 0;

  local_70c = &PTR_LAB_009d7ba4;

  local_70d = 0;

  BitStream_writeBits(8,&local_70d);

  BitStream_writeBits(0x40,unaff_ESI + 0x138);

  BitStream_writeFlag(*(uint8_t *)(unaff_ESI + 0x164));

  BitStream_writeFlag(*(uint8_t *)(unaff_ESI + 0x165));

  *(int *)(unaff_ESI + 0x1a0) = *(int *)(unaff_ESI + 0x1a0) + 1;

  iVar2 = *(int *)(unaff_ESI + 0x10c);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1a4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x78);

  if (iVar2 == 0) {

    iVar2 = unaff_EDI + 0x68;

  }

  FUN_00784d20(iVar2,local_5d4,local_6f4 + 7U >> 3);

  FUN_00424d10();

  return;

}
