// =============================================================================
// FUN_0042e5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042e5b0
// Address:   0x0042e5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042e5b0 @ 0x0042e5b0
// Stable ID: aa_0042e5b0
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Sending Connect Accept - connection established."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: BitStream_writeBits×5, FUN_00424d10, FUN_0042bc80, FUN_0042e5b0, FUN_007838a0, FUN_00783aa0, FUN_00783b60, FUN_00784d20.
//  - Strings: "LogNetInterface"; "Sending Connect Accept - connection established.".
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



void FUN_0042e5b0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *unaff_ESI;

  int unaff_retaddr;

  uint8_t local_985;

  int local_984;

  undefined **local_980;

  uint32_t /* width from decompiler */ local_97c;

  uint32_t /* width from decompiler */ local_978;

  uint8_t *local_974;

  uint32_t /* width from decompiler */ local_970;

  uint local_96c;

  uint local_968;

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

  

  if ((_DAT_00d20bd8 & 1) == 0) {

    _DAT_00d20bd8 = _DAT_00d20bd8 | 1;

    DAT_00d20bd4 = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d20bd4 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20bd4;

    FUN_00783aa0("Sending Connect Accept - connection established.");

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

  local_985 = 4;

  BitStream_writeBits(8,&local_985);

  BitStream_writeBits(0x40,unaff_ESI + 0x4e);

  BitStream_writeBits(0x40,unaff_ESI + 0x50);

  local_984 = unaff_ESI[0x28];

  local_968 = local_968 + 7 & 0xfffffff8;

  BitStream_writeBits(0x20,&local_984);

  (**(code **)(*unaff_ESI + 0x28))(&local_980);

  if (*(char *)((int)unaff_ESI + 0x135) != '\0') {

    BitStream_writeBits(0x80,(int)unaff_ESI + 0x176);

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

  if (param_2 == 0) {

    param_2 = unaff_retaddr + 0x68;

  }

  FUN_00784d20(param_2,auStack_84c,local_96c + 7 >> 3);

  FUN_00424d10();

  return;

}
