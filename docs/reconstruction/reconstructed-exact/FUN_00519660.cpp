// =============================================================================
// FUN_00519660
// -----------------------------------------------------------------------------
// Stable ID: aa_00519660
// Address:   0x00519660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00519660 @ 0x00519660
// Stable ID: aa_00519660
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_00519660, FUN_0051d230, FUN_0051e4d0, FUN_00604e10, FUN_00605090, FUN_007a4480, FUN_007b7df0, FUN_007cea40.
//  - Strings: "VOG_DEBUG_STOP".
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

void FUN_00519660(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ local_24;

  void *local_20;

  uint8_t local_1c [4];

  void *local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a366e;

  local_c = ExceptionList;

  local_24 = 0;

  ExceptionList = &local_c;

  FUN_0051d230(4);

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  FUN_007e1d80();

  iVar1 = FUN_007cea40(&local_24,local_1c);

  FUN_007b7df0();

  if (iVar1 < 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  uVar3 = 0;

  iVar1 = 0;

  while( true ) {

    if (local_18 == (void *)0x0) {

      ExceptionList = local_c;

      return;

    }

    if ((uint)((local_14 - (int)local_18) / 0x3d4) <= uVar3) break;

    local_20 = operator_new(0x1c);

    local_4._0_1_ = 1;

    if (local_20 == (void *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00604e10();

    }

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_00605090(*(uint32_t /* width from decompiler */ *)(iVar1 + (int)local_18),iVar1 + 4 + (int)local_18,

                 iVar1 + 0x46 + (int)local_18,0,iVar1 + 0x34a + (int)local_18,

                 iVar1 + 0x248 + (int)local_18,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x3cc + (int)local_18),

                 *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3d0 + (int)local_18));

    FUN_0051e4d0(*puVar2,puVar2,0);

    uVar3 = uVar3 + 1;

    iVar1 = iVar1 + 0x3d4;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_18);

}
