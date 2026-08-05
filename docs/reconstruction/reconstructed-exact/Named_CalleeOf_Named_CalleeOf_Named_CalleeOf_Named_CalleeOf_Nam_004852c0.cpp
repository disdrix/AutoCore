// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004852c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004852c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x004852c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper. Evidence string: "    block %d: crc = 0x%8x, combined CRC = 0x%8x, size = %d\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "    block %d: crc = 0x%8x, combined CRC = 0x%8x, size = %d\n"
//   - "    final combined CRC = 0x%x\n   "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_004834c0×18, FUN_00483540×2, fprintf×2, FUN_00483480, FUN_004835f0, FUN_004837a0, FUN_004852c0, FUN_00489190.
//  - Strings: "    block %d: crc = 0x%8x, combined CRC = 0x%8x, size = %d\n"; "    final combined CRC = 0x%x\n   ".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004852c0(char param_1)



{

  int in_EAX;

  uint uVar1;

  uint uVar2;

  

  if (0 < *(int *)(in_EAX + 0x44)) {

    uVar2 = ~*(uint *)(in_EAX + 0x260);

    uVar1 = (*(uint *)(in_EAX + 0x264) >> 0x1f | *(uint *)(in_EAX + 0x264) * 2) ^ uVar2;

    *(uint *)(in_EAX + 0x260) = uVar2;

    *(uint *)(in_EAX + 0x264) = uVar1;

    if (1 < *(int *)(in_EAX + 0x26c)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4c) = 0;

    }

    if (1 < *(int *)(in_EAX + 0x268)) {

      fprintf((FILE *)(_iob_exref + 0x40),

              "    block %d: crc = 0x%8x, combined CRC = 0x%8x, size = %d\n",

              *(int *)(in_EAX + 0x26c),uVar2,uVar1,*(int *)(in_EAX + 0x44));

    }

    FUN_00489190();

  }

  *(int *)(in_EAX + 0x2c) = *(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 0x44);

  if (*(int *)(in_EAX + 0x26c) == 1) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x25c) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 600) = 0;

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

  }

  if (0 < *(int *)(in_EAX + 0x44)) {

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_00483540(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x260));

    FUN_004834c0(1);

    FUN_004834c0(0x18);

    FUN_004835f0();

    FUN_004837a0();

  }

  if (param_1 != '\0') {

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_004834c0(8);

    FUN_00483540(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x264));

    if (1 < *(int *)(in_EAX + 0x268)) {

      fprintf((FILE *)(_iob_exref + 0x40),"    final combined CRC = 0x%x\n   ",

              *(uint32_t /* width from decompiler */ *)(in_EAX + 0x264));

    }

    FUN_00483480();

    return;

  }

  return;

}
