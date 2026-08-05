// =============================================================================
// FUN_006725b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006725b0
// Address:   0x006725b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006725b0 @ 0x006725b0
// Stable ID: aa_006725b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1, for×1.
//  - Notable callees: FUN_00680220×2, FUN_00567420, FUN_006725b0, FUN_00673730, FUN_006802d0.
//  - Return sites: 3.

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

void FUN_006725b0(void)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  int *piVar4;

  void *local_38;

  int local_34;

  uint8_t local_30 [8];

  uint8_t local_28 [4];

  int *local_24;

  int *local_20;

  int local_1c;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009a9218;

  local_14 = ExceptionList;

  piVar4 = (int *)0x0;

  piVar3 = (int *)0x0;

  local_24 = (int *)0x0;

  local_20 = (int *)0x0;

  local_1c = 0;

  local_c = 0;

  ExceptionList = &local_14;

  cVar2 = FUN_00680220(&local_34,&local_38);

  while (piVar1 = piVar3, cVar2 == '\x01') {

    if (local_34 == 4) {

      operator_delete__(*(void **)((int)local_38 + 4));

                    /* WARNING: Subroutine does not return */

      operator_delete(local_38);

    }

    if ((piVar3 == (int *)0x0) ||

       ((uint)(local_1c - (int)piVar3 >> 3) <= (uint)((int)piVar4 - (int)piVar3 >> 3))) {

      FUN_00673730(piVar4,1,local_30);

      piVar3 = local_24;

    }

    else {

      FUN_00567420(piVar4,1,local_30,local_28,local_34);

      local_20 = piVar4 + 2;

    }

    piVar4 = local_20;

    cVar2 = FUN_00680220(&local_34,&local_38);

  }

  for (; piVar1 != piVar4; piVar1 = piVar1 + 2) {

    local_38 = (void *)piVar1[1];

    local_34 = *piVar1;

    FUN_006802d0(local_34,local_38);

  }

  if (piVar3 != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar3);

  }

  ExceptionList = local_14;

  return;

}
