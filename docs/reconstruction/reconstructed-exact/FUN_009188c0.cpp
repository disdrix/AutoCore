// =============================================================================
// FUN_009188c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009188c0
// Address:   0x009188c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009188c0 @ 0x009188c0
// Stable ID: aa_009188c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0040cf50, FUN_009188c0, FUN_00930fc0.
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

void __fastcall FUN_009188c0(int param_1)



{

  char cVar1;

  uint8_t local_3c [4];

  int local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint8_t local_16;

  uint8_t local_15;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009ad333;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffb8;

  local_8 = 0;

  local_20 = DAT_00d1f040;

  local_16 = 0;

  local_15 = 0;

  local_24 = 0;

  local_28 = 0xff;

  local_2c = 0xff;

  local_30 = 0xff;

  local_34 = 0xff;

  local_1c = 0xffffffff;

  ExceptionList = &local_10;

  cVar1 = FUN_0040cf50();

  if (cVar1 == '\0') {

    *(uint8_t *)(param_1 + 0xb94) = 0;

    *(uint8_t *)(param_1 + 0xbb4) = 0;

    *(uint8_t *)(param_1 + 0xbd4) = 0;

    if (DAT_00d1b644 != 0) {

      local_15 = *(uint8_t *)(DAT_00d1b644 + 0xf5);

    }

    if (*(int *)(param_1 + 0x758) != 0) {

      local_38 = *(int *)(*(int *)(*(int *)(param_1 + 0x758) + 0xa8) + 0x38);

      if (((local_38 == 0xe) || (local_38 == 0x12)) || (local_38 == 0x14)) {

        local_16 = 1;

        FUN_00930fc0(&DAT_00d1a840,local_3c,0,0);

      }

    }

  }

  ExceptionList = local_10;

  return;

}
