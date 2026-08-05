// READABILITY (auto CF):
//  - Body size: ~592 non-empty decompiler lines.
//  - Control keywords: if×52, while×15, for×14, do×10, return×6, goto×4.
//  - Notable callees: FUN_007a4480×16, FUN_004022a0×2, FUN_0053b4b0×2, CONCAT31, CreateSimpleObject_SerializeVariant2, FUN_00404840, FUN_0040fb90, FUN_00418700.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 6.

// =============================================================================
// CVOGCharacter_SerializeCreatePacket
// -----------------------------------------------------------------------------
// Stable ID: aa_0052f650
// Address:   0x0052f650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

int __thiscall

CVOGCharacter_SerializeCreatePacket

          (int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  char cVar1;

  uint *puVar2;

  int *piVar3;

  short sVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  void *pvVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int *piVar11;

  int *piVar12;

  uint uVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint32_t /* width from decompiler */ *puVar15;

  char *pcVar16;

  int iVar17;

  time_t tVar18;

  uint32_t /* width from decompiler */ auStack_74 [2];

  int *piStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ *puStack_60;

  int iStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint auStack_54 [2];

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  puVar15 = param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &DAT_009a3c51;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CreateSimpleObject_SerializeVariant2(param_2,param_3,param_4);

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = local_c;

    return 0;

  }

  *param_2 = 0x2015;

  iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c + param_1) + 0x160

                      ))();

  if (iVar5 != 0) {

    pcVar6 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c +

                                          param_1) + 0x160))();

    pcVar16 = (char *)(param_2 + 0x4e);

    do {

      cVar1 = *pcVar6;

      *pcVar16 = cVar1;

      pcVar6 = pcVar6 + 1;

      pcVar16 = pcVar16 + 1;

    } while (cVar1 != '\0');

  }

  *(byte *)((int)param_2 + 0x129) =

       *(byte *)((int)param_2 + 0x129) ^

       (*(byte *)(param_1 + -0xa94) ^ *(byte *)((int)param_2 + 0x129)) & 1;

  *(byte *)((int)param_2 + 0x129) =

       (*(char *)(param_1 + -0x6e7) * '\x04' ^ *(byte *)((int)param_2 + 0x129)) & 4 ^

       *(byte *)((int)param_2 + 0x129);

  param_2[0x36] = *(uint32_t /* width from decompiler */ *)(param_1 + -0xb90);

  param_2[0x37] = *(uint32_t /* width from decompiler */ *)(param_1 + -0xb8c);

  param_2[0x3a] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6a4);

  param_2[0x3b] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6a8);

  param_2[0x3c] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x698);

  param_2[0x3d] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x694);

  param_2[0x3f] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x68c);

  param_2[0x40] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x690);

  param_2[0x41] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x69c);

  param_2[0x3e] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6a0);

  *(uint8_t *)(param_2 + 0x4a) = *(uint8_t *)(param_1 + -0x6d8);

  param_2[0x48] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x664);

  param_2[0x49] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x660);

  *(uint8_t *)((int)param_2 + 0x12a) = *(uint8_t *)(param_1 + -0x6ec);

  tVar18 = time((time_t *)0x0);

  param_2[0x4c] = (int)tVar18;

  param_2[0x4d] = (int)tVar18 >> 0x1f;

  param_2[0x42] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x73c);

  param_2[0x43] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x738);

  param_2[0x44] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x730);

  param_2[0x45] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x72c);

  param_2[0x46] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x734);

  param_2[0x47] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x728);

  pcVar16 = (char *)(param_1 + -0xa4);

  iVar5 = 0x16b - (int)pcVar16;

  do {

    cVar1 = *pcVar16;

    pcVar16[(int)param_2 + iVar5] = cVar1;

    pcVar16 = pcVar16 + 1;

  } while (cVar1 != '\0');

  param_2[0x68] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x768);

  if ((char)param_4 == '\0') {

    ExceptionList = local_c;

    return 0x1a8;

  }

  param_2[0x230] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x680);

  param_2[0x231] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x67c);

  param_2[0x232] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x678);

  param_2[0x233] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x674);

  param_2[0x234] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x670);

  *(uint16_t *)(param_2 + 0x237) = *(uint16_t *)(param_1 + -0xc62);

  *(uint16_t *)(param_2 + 0x238) = *(uint16_t *)(param_1 + -0xc5e);

  *(uint16_t *)((int)param_2 + 0x8da) = *(uint16_t *)(param_1 + -0xc64);

  *(uint16_t *)((int)param_2 + 0x8de) = *(uint16_t *)(param_1 + -0xc60);

  *(uint16_t *)(param_2 + 0x235) = *(uint16_t *)(param_1 + -0xc74);

  *(uint16_t *)((int)param_2 + 0x8d6) = *(uint16_t *)(param_1 + -0xc72);

  *(uint16_t *)(param_2 + 0x236) = *(uint16_t *)(param_1 + -0x6d2);

  *(uint16_t *)(param_2 + 0x239) = *(uint16_t *)(param_1 + -0x6d4);

  param_2[0x4c8] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6e0);

  *(uint8_t *)((int)param_2 + 0x8e7) = *(uint8_t *)(param_1 + -0x807);

  *(uint8_t *)((int)param_2 + 0x8e6) = *(uint8_t *)(param_1 + -0x808);

  *(uint8_t *)(param_2 + 0x23a) = *(uint8_t *)(param_1 + -0x806);

  *(uint8_t *)((int)param_2 + 0x8e9) = *(uint8_t *)(param_1 + -0x805);

  param_2[0x4ca] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x74c);

  param_2[0x4cc] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x748);

  param_2[0x4cd] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x744);

  param_2[0x4ce] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x740);

  param_2[0x23b] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x70);

  param_2[0x23c] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c);

  param_2[0x23d] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x68);

  param_2[0x23e] = *(uint32_t /* width from decompiler */ *)(param_1 + -100);

  *(uint16_t *)((int)param_2 + 0x8e2) = *(uint16_t *)(param_1 + -0x820);

  param_2[0x4c9] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7a0);

  param_2[0x240] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x800);

  param_2[0x241] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7fc);

  param_2[0x242] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7f8);

  param_2[0x243] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7f4);

  param_2[0x244] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7f0);

  param_2[0x245] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7ec);

  param_2[0x246] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7e8);

  param_2[0x247] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7e4);

  param_2[0x248] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7e0);

  param_2[0x249] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7dc);

  param_2[0x24a] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7d8);

  param_2[0x24b] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7d4);

  param_2[0x24c] = *(uint32_t /* width from decompiler */ *)(param_1 + -2000);

  param_2[0x24d] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7cc);

  param_2[0x24e] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7c8);

  param_2[0x24f] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x7c4);

  param_2[0x250] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6d0);

  param_2[0x251] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6cc);

  param_2[0x252] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c8);

  param_2[0x253] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c4);

  param_2[0x254] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c0);

  param_2[0x255] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6bc);

  param_2[0x256] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x6b8);

  param_4 = operator_new__(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd2c +

                                            param_1) + 0xc) * 8);

  *(uint8_t *)(param_2 + 0x6d) = 0;

  iVar5 = *(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd2c + param_1);

  iVar17 = 0;

  if (*(char *)(iVar5 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar5 + 0x1d) = 1;

  puVar9 = param_4;

  while( true ) {

    iVar5 = *(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd2c + param_1);

    if (*(char *)(iVar5 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

      puVar9 = param_4;

    }

    if (iVar17 == 0) {

      iVar17 = *(int *)(iVar5 + 0x14);

    }

    else {

      iVar17 = *(int *)(iVar17 + 0x14);

    }

    if (iVar17 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar17 + 8);

    }

    if (iVar5 == 0) break;

    if (0 < *(short *)(iVar5 + 0x5f6)) {

      puVar9[(uint)*(byte *)(param_2 + 0x6d) * 2] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x5fc);

      *(uint16_t *)(puVar9 + (uint)*(byte *)(param_2 + 0x6d) * 2 + 1) =

           *(uint16_t *)(iVar5 + 0x5f6);

      *(char *)(param_2 + 0x6d) = *(char *)(param_2 + 0x6d) + '\x01';

    }

  }

  *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd2c + param_1) + 0x1d) = 0;

  puVar7 = operator_new__((uint)*(byte *)(param_2 + 0x6d) * 8);

  param_2[0x4cf] = puVar7;

  puVar9 = param_4;

  for (uVar13 = (uint)*(byte *)(param_2 + 0x6d) * 8 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {

    *puVar7 = *puVar9;

    puVar9 = puVar9 + 1;

    puVar7 = puVar7 + 1;

  }

  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

    *(uint8_t *)puVar7 = *(uint8_t *)puVar9;

    puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

  }

  operator_delete__(param_4);

  puVar9 = param_2 + 0x6e;

  for (iVar5 = 0x96; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  iVar5 = *(int *)(param_1 + -0x86c);

  param_3 = *(uint *)(iVar5 + 0xc);

  if (0x94 < param_3) {

    param_3 = 0x95;

  }

  param_4 = (uint32_t /* width from decompiler */ *)0x0;

  if (*(char *)(iVar5 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar5 + 0x1d) = 1;

  if (0 < (int)param_3) {

    puVar9 = param_2 + 0x6f;

    do {

      iVar5 = *(int *)(param_1 + -0x86c);

      if (*(char *)(iVar5 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (param_4 == (uint32_t /* width from decompiler */ *)0x0) {

        param_4 = *(uint32_t /* width from decompiler */ **)(iVar5 + 0x14);

      }

      else {

        param_4 = *(uint32_t /* width from decompiler */ **)((int)param_4 + 0x14);

      }

      if (param_4 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar7 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar7 = *(uint32_t /* width from decompiler */ **)((int)param_4 + 8);

      }

      puVar9[-1] = *puVar7;

      *(uint8_t *)puVar9 = *(uint8_t *)(puVar7 + 1);

      puVar9[1] = puVar7[2];

      puVar9 = puVar9 + 3;

      param_3 = param_3 - 1;

    } while (param_3 != 0);

  }

  *(uint8_t *)(*(int *)(param_1 + -0x86c) + 0x1d) = 0;

  iVar5 = *(int *)(*(int *)(param_1 + -0x868) + 0xc);

  param_2[0x6a] = iVar5;

  pvVar8 = operator_new__(iVar5 * 4);

  param_2[0x4d0] = pvVar8;

  iVar5 = *(int *)(param_1 + -0x868);

  iVar17 = 0;

  if (*(char *)(iVar5 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar5 + 0x1d) = 1;

  param_4 = (uint32_t /* width from decompiler */ *)0x0;

  while( true ) {

    iVar5 = *(int *)(param_1 + -0x868);

    if (*(char *)(iVar5 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar17 == 0) {

      iVar17 = *(int *)(iVar5 + 0x14);

    }

    else {

      iVar17 = *(int *)(iVar17 + 0x14);

    }

    if (iVar17 == 0) {

      puVar9 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar9 = *(uint32_t /* width from decompiler */ **)(iVar17 + 8);

    }

    if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) break;

    *(uint32_t /* width from decompiler */ *)((int)param_4 + param_2[0x4d0]) = *puVar9;

    param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + 4);

  }

  *(uint8_t *)(*(int *)(param_1 + -0x868) + 0x1d) = 0;

  if (*(int *)(param_1 + -0x82c) == 0) {

    sVar4 = 0;

  }

  else {

    sVar4 = (short)(*(int *)(param_1 + -0x828) - *(int *)(param_1 + -0x82c) >> 2);

  }

  *(short *)(param_2 + 0x6c) = sVar4;

  pvVar8 = operator_new__(sVar4 * 4);

  param_2[0x4d1] = pvVar8;

  iVar5 = 0;

  if (0 < *(short *)(param_2 + 0x6c)) {

    do {

      *(uint32_t /* width from decompiler */ *)(param_2[0x4d1] + iVar5 * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x82c) + iVar5 * 4);

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(short *)(param_2 + 0x6c));

  }

  sVar4 = (short)*(uint32_t /* width from decompiler */ *)(param_1 + -0x814);

  *(short *)((int)param_2 + 0x1b2) = sVar4;

  pvVar8 = operator_new__(sVar4 * 4);

  param_2[0x4d2] = pvVar8;

  pvVar8 = operator_new__(*(short *)((int)param_2 + 0x1b2) * 4);

  param_2[0x4d3] = pvVar8;

  pvVar8 = operator_new__(*(short *)((int)param_2 + 0x1b2) * 4);

  param_2[0x4d4] = pvVar8;

  piVar11 = (int *)**(int **)(param_1 + -0x818);

  if (piVar11 != *(int **)(param_1 + -0x818)) {

    iVar5 = 0;

    do {

      *(int *)(iVar5 + param_2[0x4d2]) = piVar11[3];

      iVar17 = piVar11[5];

      *(int *)(iVar5 + param_2[0x4d3]) = piVar11[4];

      *(int *)(iVar5 + param_2[0x4d4]) = iVar17;

      iVar5 = iVar5 + 4;

      if (*(char *)((int)piVar11 + 0x19) == '\0') {

        piVar12 = (int *)piVar11[2];

        if (*(char *)((int)piVar12 + 0x19) == '\0') {

          cVar1 = *(char *)(*piVar12 + 0x19);

          piVar11 = piVar12;

          piVar12 = (int *)*piVar12;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar12 + 0x19);

            piVar11 = piVar12;

            piVar12 = (int *)*piVar12;

          }

        }

        else {

          cVar1 = *(char *)(piVar11[1] + 0x19);

          piVar3 = (int *)piVar11[1];

          piVar12 = piVar11;

          while ((piVar11 = piVar3, cVar1 == '\0' && (piVar12 == (int *)piVar11[2]))) {

            cVar1 = *(char *)(piVar11[1] + 0x19);

            piVar3 = (int *)piVar11[1];

            piVar12 = piVar11;

          }

        }

      }

    } while (piVar11 != *(int **)(param_1 + -0x818));

  }

  puStack_60 = (uint32_t /* width from decompiler */ *)0x0;

  iStack_5c = 0;

  uStack_58 = 0;

  iVar5 = *(int *)(param_1 + -0x858);

  uStack_4 = 0;

  param_4 = (uint32_t /* width from decompiler */ *)0x0;

  if (*(char *)(iVar5 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar5 + 0x1d) = 1;

  while( true ) {

    iVar5 = *(int *)(param_1 + -0x858);

    if (*(char *)(iVar5 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (param_4 == (uint32_t /* width from decompiler */ *)0x0) {

      param_4 = *(uint32_t /* width from decompiler */ **)(iVar5 + 0x14);

    }

    else {

      param_4 = *(uint32_t /* width from decompiler */ **)((int)param_4 + 0x14);

    }

    if (param_4 == (uint32_t /* width from decompiler */ *)0x0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)((int)param_4 + 8);

    }

    if (iVar5 == 0) break;

    puVar2 = *(uint **)(iVar5 + 0x14c);

    if ((((short)puVar2[0x3e] == 0) || (*(char *)(iVar5 + 0x14) != '\0')) ||

       (-1 < (int)puVar2[0x40])) {

      uStack_24 = *(uint *)(iVar5 + 0x10);

      auStack_54[0] = *puVar2;

      iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x870) + 0x10) +

                               (*(uint *)(*(int *)(param_1 + -0x870) + 8) & auStack_54[0]) * 4) + 4)

      ;

      if (iVar5 == 0) {

LAB_00530018:

        puVar9 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        do {

          if (auStack_54[0] == *(uint *)(iVar5 + 0x10)) {

            if (iVar5 == 0) goto LAB_00530018;

            puVar9 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8);

            goto LAB_0053001f;

          }

          iVar5 = *(int *)(iVar5 + 0xc);

        } while (iVar5 != 0);

        puVar9 = (uint32_t /* width from decompiler */ *)0x0;

      }

LAB_0053001f:

      if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {

        uStack_4c = 0xffffffff;

        uStack_48 = 0xffffffff;

        uStack_44 = 0xffffffff;

        uStack_40 = 0xffffffff;

        uStack_3c = 0xffffffff;

        uStack_38 = 0xffffffff;

        uStack_34 = 0xffffffff;

        uStack_30 = 0xffffffff;

        uStack_2c = 0xffffffff;

        uStack_28 = 0xffffffff;

      }

      else {

        uStack_4c = *puVar9;

        uStack_48 = puVar9[1];

        uStack_44 = puVar9[2];

        uStack_40 = puVar9[3];

        uStack_3c = puVar9[4];

        uStack_38 = puVar9[5];

        uStack_34 = puVar9[6];

        uStack_30 = puVar9[7];

        uStack_2c = puVar9[8];

        uStack_28 = puVar9[9];

      }

      iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x844) + 0x10) +

                               (*(uint *)(*(int *)(param_1 + -0x844) + 8) & uStack_24) * 4) + 4);

      if (iVar5 == 0) {

LAB_005300c7:

        iVar5 = 0;

      }

      else {

        do {

          if (uStack_24 == *(uint *)(iVar5 + 0x10)) {

            if (iVar5 == 0) goto LAB_005300c7;

            iVar5 = *(int *)(iVar5 + 8);

            goto LAB_005300ce;

          }

          iVar5 = *(int *)(iVar5 + 0xc);

        } while (iVar5 != 0);

        iVar5 = 0;

      }

LAB_005300ce:

      if (iVar5 == 0) {

        uStack_20 = 0xffffffff;

        uStack_1c = 0xffffffff;

        uStack_18 = 0xffffffff;

        uStack_14 = 0xffffffff;

        FUN_0053b4b0(auStack_54);

      }

      else {

        uStack_20 = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

        uStack_1c = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

        uStack_18 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

        uStack_14 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10);

        FUN_0053b4b0(auStack_54);

      }

    }

  }

  *(uint8_t *)(*(int *)(param_1 + -0x858) + 0x1d) = 0;

  if (puStack_60 == (uint32_t /* width from decompiler */ *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = (iStack_5c - (int)puStack_60) / 0x48;

  }

  param_2[0x6b] = iVar5;

  if (iVar5 < 1) {

    param_2[0x4d5] = 0;

  }

  else {

    puVar9 = operator_new__(iVar5 * 0x48);

    param_2[0x4d5] = puVar9;

    if ((puStack_60 == (uint32_t /* width from decompiler */ *)0x0) ||

       (param_4 = (uint32_t /* width from decompiler */ *)((iStack_5c - (int)puStack_60) / 0x48), param_4 == (uint32_t /* width from decompiler */ *)0x0

       )) {

      FUN_00537430();

    }

    puVar7 = puStack_60;

    for (uVar13 = (uint)(param_2[0x6b] * 0x48) >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {

      *puVar9 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar9 = puVar9 + 1;

    }

    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

      *(uint8_t *)puVar9 = *(uint8_t *)puVar7;

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    }

  }

  puVar9 = param_2 + 0x1cc;

  puVar7 = (uint32_t /* width from decompiler */ *)(param_1 + -0x654);

  puVar14 = param_2 + 0x104;

  puVar10 = (uint32_t /* width from decompiler */ *)(param_1 + -0x470);

  param_4 = (uint32_t /* width from decompiler */ *)0x64;

  do {

    *puVar14 = *puVar10;

    puVar14[1] = puVar10[1];

    *puVar9 = *puVar7;

    puVar10 = puVar10 + 2;

    puVar14 = puVar14 + 2;

    puVar7 = puVar7 + 1;

    puVar9 = puVar9 + 1;

    param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + -1);

  } while (param_4 != (uint32_t /* width from decompiler */ *)0x0);

  puVar9 = param_2 + 600;

  for (iVar5 = 0x270; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar9 = 0xffffffff;

    puVar9 = puVar9 + 1;

  }

  if ((*(int *)(param_1 + -0xe4) == 0) ||

     ((iVar5 = *(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcf8 + param_1), iVar5 != 0 &&

      (*(char *)(iVar5 + 0xf5) == '\0')))) {

    if (puStack_60 == (uint32_t /* width from decompiler */ *)0x0) {

      ExceptionList = local_c;

      return (((int)*(short *)((int)param_2 + 0x1b2) + param_2[0x6b] * 6) * 3 + 0x4d6 +

              (uint)*(byte *)(param_2 + 0x6d) * 2 + (int)*(short *)(param_2 + 0x6c) + param_2[0x6a])

             * 4;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(puStack_60);

  }

  iVar5 = 0;

  auStack_74[0] = 0;

  param_4 = (uint32_t /* width from decompiler */ *)0x0;

  piVar11 = (int *)FUN_0040fb90();

  uStack_68 = 0;

  uStack_4 = CONCAT31(uStack_4._1_3_,1);

  param_3 = 0;

  piStack_6c = piVar11;

  FUN_004294f0();

  iVar17 = FUN_004022a0(auStack_74,&param_4);

  if (iVar17 == 0) {

    param_2 = param_2 + 600;

    do {

      if (0x137 < iVar5) break;

      if (*(int *)(*(int *)((int)param_4 + 0xa8) + 0x38) == 4) {

        iVar5 = FUN_00418700(piVar11,piVar11[1],&param_4);

        FUN_00404840(1);

        piVar11[1] = iVar5;

        **(int **)(iVar5 + 4) = iVar5;

        iVar5 = param_3;

        piVar11 = piStack_6c;

      }

      else {

        iVar17 = *(int *)(*(int *)((int)param_4 + 0xa8) + 0x3c);

        if ((*(char *)(iVar17 + 0x406) != '\0') && (*(char *)(iVar17 + 0x407) != '\0')) {

          *param_2 = *(uint32_t /* width from decompiler */ *)((int)param_4 + 0x160);

          iVar5 = iVar5 + 1;

          param_2[1] = *(uint32_t /* width from decompiler */ *)((int)param_4 + 0x164);

          param_2 = param_2 + 2;

          param_3 = iVar5;

        }

      }

      iVar17 = FUN_004022a0(auStack_74,&param_4);

    } while (iVar17 == 0);

  }

  iVar17 = *(int *)(param_1 + -0xe4);

  if (*(char *)(iVar17 + 0x54) != '\0') {

    *(uint8_t *)(iVar17 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar17 + 0x30));

  }

  piVar12 = (int *)*piVar11;

  if (piVar12 != piVar11) {

    puVar15 = puVar15 + iVar5 * 2 + 600;

    do {

      if (0x137 < iVar5) break;

      iVar17 = piVar12[2];

      *puVar15 = *(uint32_t /* width from decompiler */ *)(iVar17 + 0x160);

      puVar15[1] = *(uint32_t /* width from decompiler */ *)(iVar17 + 0x164);

      piVar12 = (int *)*piVar12;

      iVar5 = iVar5 + 1;

      puVar15 = puVar15 + 2;

    } while (piVar12 != piVar11);

  }

  piVar12 = (int *)*piVar11;

  *piVar11 = (int)piVar11;

  piVar11[1] = (int)piVar11;

  if (piVar12 == piVar11) {

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar11);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar12);

}
