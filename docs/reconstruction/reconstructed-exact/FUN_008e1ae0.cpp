// =============================================================================
// FUN_008e1ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1ae0
// Address:   0x008e1ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e1ae0 @ 0x008e1ae0
// Stable ID: aa_008e1ae0
// Embedded strings (evidence for future rename):
//   - "%i/%i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_0052ad60, FUN_0052ada0, FUN_008e1ae0, sprintf.
//  - Strings: "%i/%i".
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

void FUN_008e1ae0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_108 [2];

  uint32_t /* width from decompiler */ uStack_106;

  char cStack_102;

  char cStack_101;

  char local_100 [252];

  

  if ((*(int *)(unaff_EBX + 0x564 + unaff_ESI * 4) != 0) && (DAT_00d1b6d8 != 0)) {

    _local_108 = _local_108 & 0xffff0000;

    puVar3 = (uint32_t /* width from decompiler */ *)(local_108 + 2);

    for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    *(uint16_t *)puVar3 = 0;

    iVar2 = FUN_0052ad60(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x5e4 + unaff_ESI * 4));

    uVar1 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x5e4 + unaff_ESI * 4));

    if (0 < iVar2) {

      sprintf(local_108,"%i/%i",uVar1,iVar2);

      (**(code **)(**(int **)(unaff_EBX + 0x564 + unaff_ESI * 4) + 0x34c))();

      return;

    }

    uStack_106._2_1_ = s_UNLEARNED_00a3be84[4];

    uStack_106._3_1_ = s_UNLEARNED_00a3be84[5];

    cStack_102 = s_UNLEARNED_00a3be84[6];

    cStack_101 = s_UNLEARNED_00a3be84[7];

    local_108[0] = s_UNLEARNED_00a3be84[0];

    local_108[1] = s_UNLEARNED_00a3be84[1];

    uStack_106._0_1_ = s_UNLEARNED_00a3be84[2];

    uStack_106._1_1_ = s_UNLEARNED_00a3be84[3];

    local_100[0] = s_UNLEARNED_00a3be84[8];

    local_100[1] = s_UNLEARNED_00a3be84[9];

    (**(code **)(**(int **)(unaff_EBX + 0x564 + unaff_ESI * 4) + 0x34c))();

  }

  return;

}
