// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, for×2, while×1.
//  - Notable callees: FUN_007a4480×4, CreateSimpleObject_SerializeVariant2, FUN_004c59a0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_004c59a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c59a0
// Address:   0x004c59a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_VOG_DEBUG_STOP_004c59a0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  

  CreateSimpleObject_SerializeVariant2(param_2,param_3,param_4);

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  *param_2 = 0x2013;

  param_2[0x44] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x3a0);

  iVar6 = 0;

  param_2[0x36] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x3d8);

  if (*(int *)(param_1 + -0x2b0) == 0) {

    uVar4 = 0xffffffff;

    uVar3 = 0xffffffff;

  }

  else {

    iVar5 = *(int *)(param_1 + -0x2b0);

    iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);

    uVar4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar5);

    uVar3 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar5);

  }

  param_2[0x3e] = uVar4;

  param_2[0x3f] = uVar3;

  param_2[0x40] = 0xffffffff;

  param_2[0x41] = 0xffffffff;

  if (*(int *)(param_1 + -0x2a8) == 0) {

    uVar4 = 0xffffffff;

  }

  else {

    uVar4 = *(uint32_t /* width from decompiler */ *)

             (*(int *)(*(int *)(*(int *)(param_1 + -0x2a8) + 4) + 4) + 0x164 +

             *(int *)(param_1 + -0x2a8));

  }

  param_2[0x42] = uVar4;

  param_2[0x4a] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2e8);

  param_2[0x4b] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2e0);

  param_2[0x38] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d8);

  param_2[0x39] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d4);

  param_2[0x3a] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d0);

  param_2[0x3b] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2cc);

  *(uint8_t *)(param_2 + 0x43) = 0;

  uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0x27c

                      ))();

  param_2[0x45] = uVar4;

  *(uint8_t *)((int)param_2 + 0x126) = *(uint8_t *)(param_1 + -0x1f5);

  param_2[0x46] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x408) + 0x40);

  param_2[0x47] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x408) + 0x48);

  *(uint8_t *)(param_2 + 0x49) = *(uint8_t *)(*(int *)(param_1 + -0x408) + 0x51);

  param_2[0x48] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x408) + 0x4c);

  cVar1 = *(char *)(*(int *)(param_1 + -0x408) + 0x50);

  param_2[0x4c] = 0xffffffff;

  *(bool *)((int)param_2 + 0x125) = cVar1 != '\0';

  param_2[0x4d] = 0xffffffff;

  iVar5 = *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x48c + param_1);

  if (*(char *)(iVar5 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar5 + 0x1d) = 1;

  while( true ) {

    iVar5 = *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x48c + param_1);

    if (*(char *)(iVar5 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar6 == 0) {

      iVar6 = *(int *)(iVar5 + 0x14);

    }

    else {

      iVar6 = *(int *)(iVar6 + 0x14);

    }

    if (iVar6 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar6 + 8);

    }

    if (iVar5 == 0) break;

    if (0 < *(short *)(iVar5 + 0x5f6)) {

      param_2[(uint)*(byte *)(param_2 + 0x43) * 2 + 0x4e] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x5fc);

      *(uint16_t *)(param_2 + (uint)*(byte *)(param_2 + 0x43) * 2 + 0x4f) =

           *(uint16_t *)(iVar5 + 0x5f6);

      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';

    }

  }

  *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x48c + param_1) + 0x1d) = 0;

  return (uint)*(byte *)(param_2 + 0x43) * 8 + 0x138;

}
