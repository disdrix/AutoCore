// =============================================================================
// FUN_0042e9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042e9a0
// Address:   0x0042e9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042e9a0 @ 0x0042e9a0
// Stable ID: aa_0042e9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: BitStream_writeBits×3, FUN_00424d10, FUN_0042bb40, FUN_0042e9a0, FUN_00784d20.
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

void FUN_0042e9a0(int param_1,int param_2)



{

  int in_EAX;

  int unaff_ESI;

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

  

  if (unaff_ESI != 0) {

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

    local_70d = 3;

    BitStream_writeBits(8,&local_70d);

    BitStream_writeBits(0x40,in_EAX + 4);

    BitStream_writeBits(0x40,in_EAX + 0xc);

    FUN_0042bb40(unaff_ESI,0xff);

    if (param_2 == 0) {

      param_2 = param_1 + 0x68;

    }

    FUN_00784d20(param_2,local_5d4,local_6f4 + 7U >> 3);

    FUN_00424d10();

  }

  return;

}
