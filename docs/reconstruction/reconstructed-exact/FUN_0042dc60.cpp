// =============================================================================
// FUN_0042dc60
// -----------------------------------------------------------------------------
// Stable ID: aa_0042dc60
// Address:   0x0042dc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042dc60 @ 0x0042dc60
// Stable ID: aa_0042dc60
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Sending Connect Request"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×7, while×1, return×1.
//  - Notable callees: BitStream_writeBits×10, BitStream_writeFlag×2, FUN_0040b290, FUN_00424d10, FUN_0042bb40, FUN_0042bc80, FUN_0042dc60, FUN_007838a0.
//  - Strings: "LogNetInterface"; "Sending Connect Request".
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



void FUN_0042dc60(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int iVar3;

  int *unaff_ESI;

  uint uVar4;

  int unaff_retaddr;

  int local_98c;

  uint8_t local_985;

  uint local_984;

  undefined **local_980;

  uint32_t /* width from decompiler */ local_97c;

  uint32_t /* width from decompiler */ local_978;

  uint8_t *local_974;

  uint32_t /* width from decompiler */ local_970;

  uint local_96c;

  int local_968;

  uint8_t local_964;

  uint8_t local_963;

  uint32_t /* width from decompiler */ local_954;

  uint32_t /* width from decompiler */ local_950;

  uint32_t /* width from decompiler */ local_94c;

  uint8_t local_948;

  uint8_t auStack_84c [4];

  uint8_t local_848 [1488];

  uint8_t auStack_278 [4];

  uint32_t /* width from decompiler */ *puStack_274;

  

  if ((_DAT_00d20be0 & 1) == 0) {

    _DAT_00d20be0 = _DAT_00d20be0 | 1;

    DAT_00d20bdc = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d20bdc + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20bdc;

    FUN_00783aa0("Sending Connect Request");

    DAT_00d179a0 = 0;

  }

  local_974 = local_848;

  local_97c = 0;

  local_978 = 0;

  local_970 = 0x5d2;

  local_96c = local_96c & 0xffffff00;

  local_954 = 0x2e90;

  local_950 = 0x2e90;

  local_968 = 0;

  local_964 = 0;

  local_963 = 0;

  local_948 = 0;

  local_94c = 0;

  local_980 = &PTR_LAB_009d7ba4;

  local_985 = 2;

  BitStream_writeBits(8,&local_985);

  BitStream_writeBits(0x40,unaff_ESI + 0x4e);

  BitStream_writeBits(0x40,unaff_ESI + 0x50);

  local_98c = unaff_ESI[0x54];

  BitStream_writeBits(0x20,&local_98c);

  local_98c = unaff_ESI[0x52];

  BitStream_writeBits(0x20,&local_98c);

  local_98c = unaff_ESI[0x53];

  BitStream_writeBits(0x20,&local_98c);

  uVar4 = 0;

  cVar2 = BitStream_writeFlag(*(uint8_t *)((int)unaff_ESI + 0x135));

  if (cVar2 != '\0') {

    iVar3 = *(int *)(unaff_ESI[0x56] + 0x18);

    if (iVar3 != 0) {

      *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;

    }

    uVar4 = *(uint *)(iVar3 + 0x10);

    local_98c = iVar3;

    if (uVar4 < 0x400) {

      local_984 = uVar4;

      BitStream_writeBits(10,&local_984);

      BitStream_writeBits(uVar4 * 8,*(uint32_t /* width from decompiler */ *)(iVar3 + 0xc));

    }

    FUN_0040b290();

    uVar4 = local_968 + 7U >> 3;

    local_968 = uVar4 * 8;

    BitStream_writeBits(0x80,(int)unaff_ESI + 0x166);

  }

  BitStream_writeFlag((char)unaff_ESI[0x67]);

  local_984 = unaff_ESI[0x28];

  BitStream_writeBits(0x20,&local_984);

  iVar3 = (**(code **)*unaff_ESI)();

  FUN_0042bb40(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x20),0xff);

  (**(code **)(*unaff_ESI + 0x20))(&local_980);

  if (uVar4 != 0) {

    FUN_007838a0();

    FUN_0042bc80(5,auStack_278);

    while (puStack_274 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)puStack_274[2];

      *puStack_274 = 0;

      puStack_274[1] = 0;

      puStack_274[2] = 0;

      puStack_274 = puVar1;

    }

  }

  unaff_ESI[0x68] = unaff_ESI[0x68] + 1;

  iVar3 = unaff_ESI[0x43];

  unaff_ESI[0x69] = *(int *)(unaff_retaddr + 0x78);

  if (iVar3 == 0) {

    iVar3 = unaff_retaddr + 0x68;

  }

  FUN_00784d20(iVar3,auStack_84c,local_96c + 7 >> 3);

  FUN_00424d10();

  return;

}
