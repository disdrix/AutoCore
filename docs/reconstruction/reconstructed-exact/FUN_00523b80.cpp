// =============================================================================
// FUN_00523b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00523b80
// Address:   0x00523b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00523b80 @ 0x00523b80
// Stable ID: aa_00523b80
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_00523b80.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

int __thiscall FUN_00523b80(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  *param_2 = 0x2017;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x164 + param_1);

  param_2[2] = *puVar1;

  param_2[3] = puVar1[1];

  param_2[4] = puVar1[2];

  param_2[5] = puVar1[3];

  *(uint8_t *)(param_2 + 6) = *(uint8_t *)(param_1 + 0x6c8);

  param_2[8] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x720);

  param_2[9] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x724);

  param_2[10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x730);

  *(uint16_t *)((int)param_2 + 0x46) = *(uint16_t *)(param_1 + 0x580);

  *(uint16_t *)((int)param_2 + 0x3a) = *(uint16_t *)(param_1 + 0x13e);

  *(uint16_t *)((int)param_2 + 0x3e) = *(uint16_t *)(param_1 + 0x142);

  *(uint16_t *)(param_2 + 0xe) = *(uint16_t *)(param_1 + 0x13c);

  *(uint16_t *)(param_2 + 0xf) = *(uint16_t *)(param_1 + 0x140);

  *(uint16_t *)(param_2 + 0xd) = *(uint16_t *)(param_1 + 300);

  *(uint16_t *)((int)param_2 + 0x36) = *(uint16_t *)(param_1 + 0x12e);

  *(uint16_t *)(param_2 + 0x10) = *(uint16_t *)(param_1 + 0x6ce);

  *(uint16_t *)((int)param_2 + 0x42) = *(uint16_t *)(param_1 + 0x6cc);

  iVar3 = *(int *)(param_1 + 0x250);

  if (iVar3 != 0) {

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x23c))();

    param_2[0xb] = uVar2;

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x250) + 4) + 4) + 4 +

                                 *(int *)(param_1 + 0x250)) + 0x244))();

    param_2[0xc] = uVar2;

  }

  *(uint8_t *)(param_2 + 0x11) = 0;

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1);

  iVar4 = 0;

  if (*(char *)(iVar3 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar3 + 0x1d) = 1;

  while( true ) {

    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1);

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar3 + 0x14);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

    }

    if (iVar4 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar4 + 8);

    }

    if (iVar3 == 0) break;

    if (0 < *(short *)(iVar3 + 0x5f6)) {

      param_2[(uint)*(byte *)(param_2 + 0x11) * 2 + 0x12] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x5fc);

      *(uint16_t *)(param_2 + (uint)*(byte *)(param_2 + 0x11) * 2 + 0x13) =

           *(uint16_t *)(iVar3 + 0x5f6);

      *(char *)(param_2 + 0x11) = *(char *)(param_2 + 0x11) + '\x01';

    }

  }

  *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1) + 0x1d) = 0;

  return (uint)*(byte *)(param_2 + 0x11) * 8 + 0x48;

}
