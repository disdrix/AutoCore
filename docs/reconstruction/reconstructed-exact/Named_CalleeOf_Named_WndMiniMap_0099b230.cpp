// =============================================================================
// Named_CalleeOf_Named_WndMiniMap_0099b230
// -----------------------------------------------------------------------------
// Stable ID: aa_0099b230
// Callee of Named_WndMiniMap (+2 other named callers)
// Address:   0x0099b230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_WndMiniMap: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_WndMiniMap (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~243 non-empty decompiler lines.
//  - Control keywords: if×8, switch×8, goto×6, return×1.
//  - Notable callees: CONCAT11×5, FUN_0099b010×4, CONCAT21×3, CONCAT12, CONCAT13, FUN_0099b230.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_WndMiniMap (+2 other named callers)
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

void Named_CalleeOf_Named_WndMiniMap_0099b230(uint32_t /* width from decompiler */ *param_1,int param_2,uint *param_3,int param_4,int param_5)



{

  ushort uVar1;

  ushort uVar2;

  uint16_t uVar3;

  uint uVar4;

  uint *puVar5;

  sbyte sVar6;

  byte bVar7;

  uint uVar8;

  uint uVar9;

  byte bVar10;

  int iVar11;

  byte *pbVar12;

  uint uVar13;

  ushort uVar14;

  ushort *puVar15;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_c;

  

  local_18 = DAT_00afdef0;

  uVar9 = param_3[1];

  param_4 = ((int)uVar9 >> 2) * param_5 + param_4;

  uVar8 = *param_3 & 3;

  uVar13 = uVar9 & 3;

  iVar11 = (int)*param_3 >> 2;

  if (param_2 == 0x31545844) {

    puVar15 = (ushort *)(param_4 + iVar11 * 8);

    param_3._0_1_ = 0xff;

  }

  else {

    pbVar12 = (byte *)(iVar11 * 0x10 + param_4);

    puVar15 = (ushort *)(pbVar12 + 8);

    if ((param_2 == 0x32545844) || (param_2 == 0x33545844)) {

      sVar6 = (char)uVar8 * '\x04';

      iVar11 = (int)((uint)*(ushort *)(pbVar12 + uVar13 * 2) & 0xf << sVar6) >> sVar6;

      param_3._0_1_ = (byte)iVar11 | (byte)(iVar11 << 4);

    }

    else if ((param_2 == 0x34545844) || (param_2 == 0x35545844)) {

      bVar7 = 0;

      switch(uVar13) {

      case 0:

        switch(uVar8) {

        case 0:

          bVar7 = pbVar12[2] & 7;

          break;

        case 1:

          bVar7 = pbVar12[2] >> 3 & 7;

          break;

        case 2:

          bVar7 = (pbVar12[3] & 1) * '\x04' | pbVar12[2] >> 6;

          break;

        case 3:

          bVar7 = pbVar12[3] >> 1 & 7;

        }

        break;

      case 1:

        switch(uVar8) {

        case 0:

          bVar7 = pbVar12[3] >> 4 & 7;

          break;

        case 1:

          bVar7 = (pbVar12[4] & 3) * '\x02' | pbVar12[3] >> 7;

          break;

        case 2:

          bVar7 = pbVar12[4] >> 2 & 7;

          break;

        case 3:

          bVar7 = pbVar12[4];

LAB_0099b3c4:

          bVar7 = bVar7 >> 5;

        }

        break;

      case 2:

        switch(uVar8) {

        case 0:

          bVar7 = pbVar12[5] & 7;

          break;

        case 1:

          bVar7 = pbVar12[5] >> 3 & 7;

          break;

        case 2:

          bVar7 = (pbVar12[6] & 1) * '\x04' | pbVar12[5] >> 6;

          break;

        case 3:

          bVar7 = pbVar12[6] >> 1 & 7;

        }

        break;

      case 3:

        switch(uVar8) {

        case 0:

          bVar7 = pbVar12[6] >> 4 & 7;

          break;

        case 1:

          bVar7 = (pbVar12[7] & 3) * '\x02' | pbVar12[6] >> 7;

          break;

        case 2:

          bVar7 = pbVar12[7] >> 2 & 7;

          break;

        case 3:

          bVar7 = pbVar12[7];

          goto LAB_0099b3c4;

        }

      }

      param_3._0_1_ = *pbVar12;

      bVar10 = pbVar12[1];

      uVar4 = (uint)bVar7;

      if (bVar10 < (byte)param_3) {

        if (uVar4 != 0) {

          if (uVar4 == 1) goto switchD_0099b41c_caseD_1;

          param_3._0_1_ =

               (byte)((int)((uVar4 - 1) * (uint)bVar10 + 3 + (8 - uVar4) * (uint)(byte)param_3) / 7)

          ;

        }

      }

      else {

        switch(uVar4) {

        case 0:

          break;

        case 1:

switchD_0099b41c_caseD_1:

          param_3._0_1_ = bVar10;

          break;

        default:

          param_3._0_1_ =

               (byte)((int)((uVar4 - 1) * (uint)bVar10 + 2 + (6 - uVar4) * (uint)(byte)param_3) / 5)

          ;

          break;

        case 6:

          param_3._0_1_ = 0;

          break;

        case 7:

          goto switchD_0099b41c_caseD_7;

        }

      }

    }

    else {

switchD_0099b41c_caseD_7:

      param_3._0_1_ = 0xff;

    }

  }

  uVar1 = *puVar15;

  uVar2 = puVar15[1];

  if (uVar13 < 2) {

    uVar14 = puVar15[2];

  }

  else {

    uVar14 = puVar15[3];

  }

  sVar6 = ((char)uVar8 + ((byte)uVar9 & 1) * '\x04') * '\x02';

  iVar11 = (int)(3 << sVar6 & (uint)uVar14) >> sVar6;

  if ((uVar1 <= uVar2) && (param_2 == 0x31545844)) {

    switch(iVar11) {

    case 0:

      puVar5 = (uint *)FUN_0099b010();

      local_18 = *puVar5;

      break;

    case 1:

      puVar5 = (uint *)FUN_0099b010();

      local_18 = *puVar5;

      break;

    case 2:

      FUN_0099b010();

      FUN_0099b010();

      local_18 = (uint)CONCAT21(CONCAT11((local_c._2_1_ >> 1) + 0x2a,

                                         ((byte)(local_c >> 8) >> 1) + 0x2c),

                                ((byte)(local_c >> 1) & 0x7f) + 0x22);

      break;

    case 3:

      local_18 = 0;

      param_3._0_1_ = 0;

    }

    goto switchD_0099b4dc_default;

  }

  switch(iVar11) {

  case 0:

    break;

  case 1:

    uVar1 = uVar2;

    break;

  case 2:

    uVar9 = uVar1 >> 8 & 0xf8;

    uVar8 = uVar1 >> 3 & 0xfc;

    iVar11 = (uVar1 & 0x1f) * 8;

    bVar7 = (byte)(iVar11 >> 5) | (byte)iVar11;

    uVar13 = uVar2 >> 8 & 0xf8;

    bVar10 = (byte)((int)uVar13 >> 5) | (byte)uVar13;

    iVar11 = (uVar2 & 0x1f) * 8;

    local_c._0_1_ = (byte)iVar11;

    uVar13 = uVar2 >> 3 & 0xfc;

    local_14 = (uint)CONCAT12(bVar10,(ushort)(byte)((byte)(iVar11 >> 5) | (byte)local_c));

    uVar3 = CONCAT11((char)((ulonglong)

                            ((longlong)

                             (int)((uint)(byte)((byte)((int)uVar9 >> 5) | (byte)uVar9) * 2) *

                            0x55555556) >> 0x20) +

                     (char)((ulonglong)((longlong)(int)(uint)bVar10 * 0x55555556) >> 0x20),

                     (char)((ulonglong)

                            ((longlong)

                             (int)((uint)(byte)((byte)((int)uVar8 >> 6) | (byte)uVar8) * 2) *

                            0x55555556) >> 0x20) +

                     (char)((ulonglong)

                            ((longlong)(int)(uint)(byte)((byte)((int)uVar13 >> 6) | (byte)uVar13) *

                            0x55555556) >> 0x20));

    goto LAB_0099b7c4;

  case 3:

    uVar9 = uVar1 >> 8 & 0xf8;

    iVar11 = (uVar1 & 0x1f) * 8;

    uVar8 = uVar1 >> 3 & 0xfc;

    bVar10 = (byte)((int)uVar8 >> 6) | (byte)uVar8;

    local_14 = (uint)CONCAT11(bVar10,(byte)(iVar11 >> 5) | (byte)iVar11);

    uVar8 = uVar2 >> 8 & 0xf8;

    iVar11 = (uVar2 & 0x1f) * 8;

    uVar13 = uVar2 >> 3 & 0xfc;

    bVar7 = (byte)(iVar11 >> 5) | (byte)iVar11;

    uVar3 = CONCAT11((char)(((uint)(byte)((byte)((int)uVar8 >> 5) | (byte)uVar8) * 2) / 3) +

                     (char)((ulonglong)

                            ((longlong)(int)(uint)(byte)((byte)((int)uVar9 >> 5) | (byte)uVar9) *

                            0x55555556) >> 0x20),

                     (char)((ulonglong)

                            ((longlong)

                             (int)((uint)(byte)((byte)((int)uVar13 >> 6) | (byte)uVar13) * 2) *

                            0x55555556) >> 0x20) +

                     (char)((ulonglong)((longlong)(int)(uint)bVar10 * 0x55555556) >> 0x20));

LAB_0099b7c4:

    local_18 = (uint)CONCAT21(uVar3,(char)((ulonglong)

                                           ((longlong)(int)((uint)bVar7 * 2) * 0x55555556) >> 0x20)

                                    + (char)((ulonglong)

                                             ((longlong)(int)(local_14 & 0xff) * 0x55555556) >> 0x20

                                            ));

  default:

    goto switchD_0099b4dc_default;

  }

  uVar9 = uVar1 >> 8 & 0xf8;

  uVar8 = uVar1 >> 3 & 0xfc;

  iVar11 = (uVar1 & 0x1f) * 8;

  local_18 = (uint)CONCAT21(CONCAT11((byte)((int)uVar9 >> 5) | (byte)uVar9,

                                     (byte)((int)uVar8 >> 6) | (byte)uVar8),

                            (byte)(iVar11 >> 5) | (byte)iVar11);

switchD_0099b4dc_default:

  local_18 = CONCAT13((byte)param_3,(undefined3)local_18);

  *param_1 = local_18;

  return;

}
