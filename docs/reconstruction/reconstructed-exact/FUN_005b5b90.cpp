// =============================================================================
// FUN_005b5b90
// -----------------------------------------------------------------------------
// Stable ID: aa_005b5b90
// Address:   0x005b5b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b5b90 @ 0x005b5b90
// Stable ID: aa_005b5b90
// Embedded strings (evidence for future rename):
//   - "SpeedTreeRT Error: %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: for×3, if×2, return×2.
//  - Notable callees: FUN_005b5590, FUN_005b56c0, FUN_005b5b90, FUN_005b7a40, FUN_00685ca0, FUN_0068ac80, fprintf.
//  - Strings: "SpeedTreeRT Error: %s\n".
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

uint32_t /* width from decompiler */ * __fastcall FUN_005b5b90(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6967;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x178);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_005b56c0();

  }

  *(uint8_t *)(puVar2 + 0xe) = 1;

  local_4 = 0xffffffff;

  iVar3 = FUN_0068ac80();

  puVar2[0xc] = iVar3;

  if (iVar3 != 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0xa4);

    puVar5 = puVar2 + 0x29;

    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0xe8);

    puVar5 = puVar2 + 0x3a;

    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 300);

    puVar5 = puVar2 + 0x4b;

    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    puVar2[0x5c] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x170);

    puVar2[0xd] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    puVar2[9] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    puVar2[0x14] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

    puVar2[0x17] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

    puVar2[0x18] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

    puVar2[0x15] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

    puVar2[0x16] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x58);

    puVar2[0x1b] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c);

    puVar2[0x1c] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

    puVar2[0x19] = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

    puVar2[0x1a] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

    puVar2[0x1e] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

    *(uint16_t *)(puVar2 + 0x1d) = *(uint16_t *)(param_1 + 0x74);

    puVar2[0x1f] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

    FUN_005b5590();

    puVar2[0x23] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c);

    puVar2[0x24] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x90);

    puVar2[0x25] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x94);

    puVar2[0x26] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x98);

    puVar2[0x27] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c);

    puVar2[0x28] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0);

    puVar2[0x13] = param_1;

    FUN_005b7a40();

    ExceptionList = local_c;

    return puVar2;

  }

  FUN_00685ca0();

  fprintf((FILE *)(_iob_exref + 0x40),"SpeedTreeRT Error: %s\n");

  (**(code **)*puVar2)();

  ExceptionList = local_10;

  return (uint32_t /* width from decompiler */ *)0x0;

}
