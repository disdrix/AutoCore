// =============================================================================
// FUN_00975870
// -----------------------------------------------------------------------------
// Stable ID: aa_00975870
// Address:   0x00975870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00975870 @ 0x00975870
// Stable ID: aa_00975870
// Embedded strings (evidence for future rename):
//   - "LogEventConnection"
//   - "EventConnection %s: WroteEvent %s - %d bits"
//   - "EventConnection %s: Full %d %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~291 non-empty decompiler lines.
//  - Control keywords: if×38, goto×5, while×2, return×2, for×1.
//  - Notable callees: BitStream_writeBits×6, realloc×4, FUN_00783aa0×3, FUN_00783b60×3, FUN_007845c0×3, CONCAT31, FUN_0042b450, FUN_00975870.
//  - Strings: "LogEventConnection"; "EventConnection %s: WroteEvent %s - %d bits"; "EventConnection %s: Full %d %d".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00975870(int *param_1,uint param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  char cVar6;

  byte bVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  byte *pbVar10;

  int iVar11;

  void *pvVar12;

  uint uVar13;

  int *piVar14;

  int *local_18;

  int *local_14;

  int local_10;

  int iStack_c;

  int *local_8;

  uint uStack_4;

  

  uVar5 = param_2;

  if ((char)param_1[0x67] != '\0') {

    param_2 = 0xf00dbaad;

    BitStream_writeBits(0x20,&param_2);

  }

  fVar3 = (float)*(int *)(uVar5 + 0x30);

  local_18 = (int *)0x0;

  local_14 = (int *)0x0;

  if (*(int *)(uVar5 + 0x30) < 0) {

    fVar3 = fVar3 + _DAT_00aaa5dc;

  }

  fVar3 = g_flOne / fVar3;

  iVar8 = param_1[0x76];

  uVar13 = param_2;

  while (iVar8 != 0) {

    param_2 = *(uint *)(uVar5 + 0x18);

    if (*(uint *)(uVar5 + 0x10) * 8 < param_2) break;

    fVar4 = (float)(int)param_2;

    if ((int)param_2 < 0) {

      fVar4 = fVar4 + _DAT_00aaa5dc;

    }

    uVar13 = param_2;

    if ((float)param_1[0x7d] < fVar4 * fVar3) break;

    piVar14 = (int *)param_1[0x76];

    local_8 = piVar14;

    if (*(uint *)(uVar5 + 0x30) < param_2 + 1) {

      uVar13 = (*(uint *)(uVar5 + 0x30) + 8 >> 3) + 0x5dc;

      if (*(uint *)(uVar5 + 0x10) < uVar13) {

        if (*(char *)(uVar5 + 0x14) != '\0') {

          *(uint *)(uVar5 + 0x10) = uVar13;

          pvVar12 = realloc(*(void **)(uVar5 + 0xc),uVar13);

          *(void **)(uVar5 + 0xc) = pvVar12;

          *(uint *)(uVar5 + 0x2c) = uVar13 * 8;

          *(uint *)(uVar5 + 0x30) = uVar13 * 8;

          goto LAB_00975960;

        }

      }

      else {

        *(uint *)(uVar5 + 0x10) = uVar13;

      }

      *(uint8_t *)(uVar5 + 0x1c) = 1;

    }

    else {

LAB_00975960:

      pbVar10 = (byte *)(*(int *)(uVar5 + 0xc) + (*(uint *)(uVar5 + 0x18) >> 3));

      *pbVar10 = *pbVar10 | '\x01' << ((byte)*(uint *)(uVar5 + 0x18) & 7);

      *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + 1;

    }

    param_2 = *(uint *)(uVar5 + 0x18);

    if ((char)param_1[0x67] != '\0') {

      *(uint *)(uVar5 + 0x18) = param_2 + 0x10;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)*piVar14;

    iStack_c = (**(code **)(*param_1 + 0x50))();

    iVar8 = (**(code **)*puVar1)();

    iStack_c = *(int *)(iVar8 + 0x10 + iStack_c * 4);

    BitStream_writeBits((char)param_1[0x7f],&iStack_c);

    (**(code **)(*(int *)*piVar14 + 0xc))(param_1,uVar5);

    if ((_DAT_00d20bb8 & 1) == 0) {

      _DAT_00d20bb8 = _DAT_00d20bb8 | 1;

      DAT_00d20bb4 = FUN_00783b60("LogEventConnection");

    }

    if (*(char *)(DAT_00d20bb4 + 4) != '\0') {

      piVar14 = (int *)*piVar14;

      iVar8 = *(int *)(uVar5 + 0x18);

      DAT_00d179a0 = DAT_00d20bb4;

      iStack_c = FUN_007845c0();

      uVar9 = (**(code **)(*piVar14 + 0x24))(iVar8 - param_2);

      FUN_00783aa0("EventConnection %s: WroteEvent %s - %d bits",iStack_c,uVar9);

      DAT_00d179a0 = 0;

      piVar14 = local_8;

    }

    if ((char)param_1[0x67] != '\0') {

      piVar2 = *(int **)(uVar5 + 0x18);

      *(uint *)(uVar5 + 0x18) = param_2;

      local_8 = piVar2;

      BitStream_writeBits(0x10,&local_8);

      *(int **)(uVar5 + 0x18) = piVar2;

    }

    uVar13 = param_2;

    if ((uint)(*(int *)(uVar5 + 0x30) - *(int *)(uVar5 + 0x18)) < 0x80) {

      *(uint *)(uVar5 + 0x18) = param_2 - 1;

      *(uint8_t *)(uVar5 + 0x1c) = 0;

      break;

    }

    param_1[0x81] = param_1[0x81] + -1;

    param_1[0x76] = piVar14[2];

    piVar14[2] = 0;

    piVar2 = piVar14;

    if (local_18 != (int *)0x0) {

      local_14[2] = (int)piVar14;

      piVar2 = local_18;

    }

    local_18 = piVar2;

    local_14 = piVar14;

    iVar8 = param_1[0x76];

  }

  param_2 = uVar13;

  if ((*(int *)(uVar5 + 0x18) + 1U <= *(uint *)(uVar5 + 0x30)) ||

     (cVar6 = FUN_0042b450(), cVar6 != '\0')) {

    pbVar10 = (byte *)((*(uint *)(uVar5 + 0x18) >> 3) + *(int *)(uVar5 + 0xc));

    *pbVar10 = *pbVar10 & ~('\x01' << ((byte)*(uint *)(uVar5 + 0x18) & 7));

    *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + 1;

  }

  local_10 = -2;

  piVar14 = local_18;

  if (param_1[0x74] != 0) {

    while( true ) {

      uVar13 = *(uint *)(uVar5 + 0x18);

      piVar14 = local_18;

      if (*(uint *)(uVar5 + 0x10) * 8 < uVar13) break;

      piVar2 = (int *)param_1[0x74];

      if (param_1[0x7c] + 0x7e < piVar2[1]) {

        if ((_DAT_00d20bb8 & 2) == 0) {

          _DAT_00d20bb8 = _DAT_00d20bb8 | 2;

          DAT_00d20bac = FUN_00783b60("LogEventConnection");

        }

        if (*(char *)(DAT_00d20bac + 4) != '\0') {

          DAT_00d179a0 = DAT_00d20bac;

          uVar9 = FUN_007845c0();

          FUN_00783aa0("EventConnection %s: Full %d %d",uVar9,*(uint32_t /* width from decompiler */ *)(param_1[0x74] + 4),

                       param_1[0x7c]);

          DAT_00d179a0 = 0;

        }

        break;

      }

      uStack_4 = uVar13;

      if (*(uint *)(uVar5 + 0x30) < uVar13 + 1) {

        uVar13 = (*(uint *)(uVar5 + 0x30) + 8 >> 3) + 0x5dc;

        if (*(uint *)(uVar5 + 0x10) < uVar13) {

          if (*(char *)(uVar5 + 0x14) != '\0') {

            *(uint *)(uVar5 + 0x10) = uVar13;

            pvVar12 = realloc(*(void **)(uVar5 + 0xc),uVar13);

            *(void **)(uVar5 + 0xc) = pvVar12;

            *(uint *)(uVar5 + 0x2c) = uVar13 * 8;

            *(uint *)(uVar5 + 0x30) = uVar13 * 8;

            goto LAB_00975b8b;

          }

        }

        else {

          *(uint *)(uVar5 + 0x10) = uVar13;

        }

        *(uint8_t *)(uVar5 + 0x1c) = 1;

      }

      else {

LAB_00975b8b:

        pbVar10 = (byte *)((*(uint *)(uVar5 + 0x18) >> 3) + *(int *)(uVar5 + 0xc));

        *pbVar10 = *pbVar10 | '\x01' << ((byte)*(uint *)(uVar5 + 0x18) & 7);

        *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + 1;

      }

      cVar6 = piVar2[1] == local_10 + 1;

      param_2 = CONCAT31(param_2._1_3_,cVar6);

      if (*(uint *)(uVar5 + 0x30) < *(int *)(uVar5 + 0x18) + 1U) {

        uVar13 = (*(uint *)(uVar5 + 0x30) + 8 >> 3) + 0x5dc;

        if (*(uint *)(uVar5 + 0x10) < uVar13) {

          if (*(char *)(uVar5 + 0x14) != '\0') {

            *(uint *)(uVar5 + 0x10) = uVar13;

            pvVar12 = realloc(*(void **)(uVar5 + 0xc),uVar13);

            *(void **)(uVar5 + 0xc) = pvVar12;

            *(uint *)(uVar5 + 0x2c) = uVar13 * 8;

            *(uint *)(uVar5 + 0x30) = uVar13 * 8;

            cVar6 = (char)param_2;

            goto LAB_00975c09;

          }

        }

        else {

          *(uint *)(uVar5 + 0x10) = uVar13;

        }

        *(uint8_t *)(uVar5 + 0x1c) = 1;

LAB_00975c33:

        param_2 = piVar2[1];

        BitStream_writeBits(7,&param_2);

      }

      else {

LAB_00975c09:

        pbVar10 = (byte *)(*(int *)(uVar5 + 0xc) + (*(uint *)(uVar5 + 0x18) >> 3));

        bVar7 = '\x01' << ((byte)*(uint *)(uVar5 + 0x18) & 7);

        if (cVar6 == '\0') {

          *pbVar10 = *pbVar10 & ~bVar7;

        }

        else {

          *pbVar10 = *pbVar10 | bVar7;

        }

        *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + 1;

        if (cVar6 == '\0') goto LAB_00975c33;

      }

      local_10 = piVar2[1];

      if ((char)param_1[0x67] != '\0') {

        *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + 0x10;

      }

      param_2 = *(uint *)(uVar5 + 0x18);

      puVar1 = (uint32_t /* width from decompiler */ *)*piVar2;

      local_8 = (int *)(**(code **)(*param_1 + 0x50))();

      iVar8 = (**(code **)*puVar1)();

      local_8 = *(int **)(iVar8 + 0x10 + (int)local_8 * 4);

      BitStream_writeBits((char)param_1[0x7f],&local_8);

      (**(code **)(*(int *)*piVar2 + 0xc))(param_1,uVar5);

      iVar8 = *(int *)(uVar5 + 0x18);

      iVar11 = (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)();

      *(int *)(iVar11 + 0x2c) = *(int *)(iVar11 + 0x2c) + 1;

      *(int *)(iVar11 + 0x24) = *(int *)(iVar11 + 0x24) + (iVar8 - param_2);

      if ((_DAT_00d20bb8 & 4) == 0) {

        _DAT_00d20bb8 = _DAT_00d20bb8 | 4;

        DAT_00d20bb0 = FUN_00783b60("LogEventConnection");

      }

      if (*(char *)(DAT_00d20bb0 + 4) != '\0') {

        local_8 = (int *)*piVar2;

        iVar8 = *(int *)(uVar5 + 0x18);

        DAT_00d179a0 = DAT_00d20bb0;

        iStack_c = FUN_007845c0();

        uVar9 = (**(code **)(*local_8 + 0x24))(iVar8 - param_2);

        FUN_00783aa0("EventConnection %s: WroteEvent %s - %d bits",iStack_c,uVar9);

        DAT_00d179a0 = 0;

      }

      if ((char)param_1[0x67] != '\0') {

        uVar13 = *(uint *)(uVar5 + 0x18);

        *(uint *)(uVar5 + 0x18) = param_2 - 0x10;

        param_2 = uVar13;

        BitStream_writeBits(0x10,&param_2);

        *(uint *)(uVar5 + 0x18) = uVar13;

      }

      if ((uint)(*(int *)(uVar5 + 0x30) - *(int *)(uVar5 + 0x18)) < 0x80) {

        *(uint *)(uVar5 + 0x18) = uStack_4;

        *(uint8_t *)(uVar5 + 0x1c) = 0;

        break;

      }

      param_1[0x81] = param_1[0x81] + -1;

      param_1[0x74] = piVar2[2];

      piVar2[2] = 0;

      piVar14 = piVar2;

      if (local_18 != (int *)0x0) {

        local_14[2] = (int)piVar2;

        piVar14 = local_18;

      }

      local_18 = piVar14;

      local_14 = piVar2;

      piVar14 = local_18;

      if (param_1[0x74] == 0) break;

    }

  }

  for (; piVar14 != (int *)0x0; piVar14 = (int *)piVar14[2]) {

    (**(code **)(*(int *)*piVar14 + 0x1c))(param_1);

  }

  *(int **)(param_3 + 0x14) = local_18;

  if (*(int *)(uVar5 + 0x18) + 1U <= *(uint *)(uVar5 + 0x30)) {

LAB_00975e93:

    pbVar10 = (byte *)(*(int *)(uVar5 + 0xc) + (*(uint *)(uVar5 + 0x18) >> 3));

    *pbVar10 = *pbVar10 & ~('\x01' << ((byte)*(uint *)(uVar5 + 0x18) & 7));

    *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + 1;

    return;

  }

  uVar13 = (*(uint *)(uVar5 + 0x30) + 8 >> 3) + 0x5dc;

  if (*(uint *)(uVar5 + 0x10) < uVar13) {

    if (*(char *)(uVar5 + 0x14) != '\0') {

      *(uint *)(uVar5 + 0x10) = uVar13;

      pvVar12 = realloc(*(void **)(uVar5 + 0xc),uVar13);

      *(void **)(uVar5 + 0xc) = pvVar12;

      *(uint *)(uVar5 + 0x2c) = uVar13 * 8;

      *(uint *)(uVar5 + 0x30) = uVar13 * 8;

      goto LAB_00975e93;

    }

  }

  else {

    *(uint *)(uVar5 + 0x10) = uVar13;

  }

  *(uint8_t *)(uVar5 + 0x1c) = 1;

  return;

}
