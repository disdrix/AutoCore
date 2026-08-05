// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co_0077d520
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d520
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Sending_Connect_Request (+1 other named callers)
// Address:   0x0077d520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Sending_Connect_Request: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Mission_Sending_Connect_Request (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~246 non-empty decompiler lines.
//  - Control keywords: if×21, while×7, do×6, return×1.
//  - Notable callees: free×4, FUN_00433ba0×2, FUN_00433c00, FUN_0077d440, FUN_0077d520, malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Sending_Connect_Request (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co_0077d520(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  short sVar3;

  int *piVar4;

  uint *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  int *piVar8;

  int iVar9;

  int *piVar10;

  int iVar11;

  int *piVar12;

  int iVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  int local_154;

  int local_150;

  int *local_14c;

  int local_148;

  uint32_t /* width from decompiler */ local_13c;

  undefined **local_138;

  uint32_t /* width from decompiler */ *local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ *local_12c;

  uint32_t /* width from decompiler */ local_128;

  char local_124;

  uint32_t /* width from decompiler */ local_120;

  uint8_t local_11c;

  uint8_t local_11b;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  uint8_t local_100;

  

  DAT_00d17a28 = 1;

  FUN_00433c00();

  if ((DAT_00d1eab4 < 0x100) || (0x100 < DAT_00d1eab4)) {

    DAT_00d1eab4 = 0x100;

  }

  FUN_00433ba0(0x100);

  uVar15 = DAT_00d1eaa8 + 1;

  FUN_00433ba0(uVar15);

  uVar16 = uVar15;

  if (((uVar15 <= DAT_00d1eaa8) && (uVar16 = DAT_00d1eaa8, uVar15 < DAT_00d1eaa8)) &&

     (uVar16 = uVar15, uVar15 == 0)) {

    DAT_00d1eaa8 = uVar15;

    free(DAT_00d1eab0);

    DAT_00d1eab0 = (uint32_t /* width from decompiler */ *)0x0;

    DAT_00d1eaac = 0;

    uVar16 = DAT_00d1eaa8;

  }

  DAT_00d1eaa8 = uVar16;

  iVar9 = 0;

  iVar13 = 0;

  do {

    iVar11 = (&DAT_00a1ea68)[iVar9];

    piVar4 = (int *)(DAT_00d1eabc + iVar13);

    *(char *)((int)piVar4 + 5) = (char)iVar9;

    iVar9 = iVar9 + 1;

    *piVar4 = iVar11 + 1;

    iVar13 = iVar13 + 0xc;

    piVar4[2] = 0;

    *(uint8_t *)(piVar4 + 1) = 0;

  } while (iVar9 < 0x100);

  local_150 = 0x100;

  piVar4 = operator_new__(0x800);

  if (piVar4 == (int *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    iVar9 = 0x100;

    piVar10 = piVar4;

    do {

      *piVar10 = 0;

      piVar10[1] = 0;

      piVar10 = piVar10 + 2;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  iVar9 = 0;

  piVar10 = piVar4;

  do {

    iVar13 = DAT_00d1eabc + iVar9;

    *piVar10 = 0;

    piVar10[1] = iVar13;

    iVar9 = iVar9 + 0xc;

    piVar10 = piVar10 + 2;

  } while (iVar9 < 0xc00);

  local_14c = piVar4 + 0x1fe;

  do {

    iVar9 = -1;

    iVar11 = 0;

    uVar16 = 0xffffffff;

    local_148 = -1;

    local_154 = -1;

    uVar15 = 0xfffffffe;

    iVar13 = iVar9;

    if (0 < local_150) {

      do {

        puVar5 = (uint *)piVar4[iVar11 * 2];

        if (puVar5 == (uint *)0x0) {

          uVar7 = *(uint *)piVar4[iVar11 * 2 + 1];

        }

        else {

          uVar7 = *puVar5;

        }

        if (uVar7 < uVar15) {

          if (puVar5 == (uint *)0x0) {

            puVar5 = (uint *)piVar4[iVar11 * 2 + 1];

          }

          uVar14 = *puVar5;

          iVar9 = iVar11;

          uVar16 = uVar15;

          local_154 = iVar13;

          local_148 = iVar11;

        }

        else {

          if (puVar5 == (uint *)0x0) {

            uVar7 = *(uint *)piVar4[iVar11 * 2 + 1];

          }

          else {

            uVar7 = *puVar5;

          }

          uVar14 = uVar15;

          iVar9 = iVar13;

          if (uVar7 < uVar16) {

            if (puVar5 == (uint *)0x0) {

              puVar5 = (uint *)piVar4[iVar11 * 2 + 1];

            }

            uVar16 = *puVar5;

            local_154 = iVar11;

          }

        }

        iVar11 = iVar11 + 1;

        uVar15 = uVar14;

        iVar13 = iVar9;

      } while (iVar11 < local_150);

    }

    uVar16 = DAT_00d1eaa8 + 1;

    if (DAT_00d1eaac < uVar16) {

      uVar14 = (uVar16 - (uVar16 & 0xf)) + 0x10;

      puVar6 = malloc(uVar14 * 8);

      puVar2 = DAT_00d1eab0;

      uVar15 = DAT_00d1eaa8;

      uVar7 = 0;

      DAT_00d1eab0 = puVar6;

      if (DAT_00d1eaa8 != 0) {

        do {

          puVar1 = DAT_00d1eab0 + uVar7 * 2;

          if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

            *puVar1 = puVar2[uVar7 * 2];

            puVar1[1] = puVar2[uVar7 * 2 + 1];

          }

          uVar7 = uVar7 + 1;

        } while (uVar7 < uVar15);

      }

      DAT_00d1eab0 = puVar2;

      free(puVar2);

      iVar9 = local_148;

      DAT_00d1eaac = uVar14;

      DAT_00d1eab0 = puVar6;

    }

    uVar15 = uVar16;

    if (((uVar16 <= DAT_00d1eaa8) && (uVar15 = DAT_00d1eaa8, uVar16 < DAT_00d1eaa8)) &&

       (uVar15 = uVar16, uVar16 == 0)) {

      DAT_00d1eaa8 = uVar16;

      free(DAT_00d1eab0);

      DAT_00d1eab0 = (uint32_t /* width from decompiler */ *)0x0;

      DAT_00d1eaac = 0;

      uVar15 = DAT_00d1eaa8;

    }

    DAT_00d1eaa8 = uVar15;

    piVar10 = DAT_00d1eab0 + DAT_00d1eaa8 * 2 + -2;

    piVar8 = (int *)piVar4[iVar9 * 2];

    if (piVar8 == (int *)0x0) {

      piVar8 = (int *)piVar4[iVar9 * 2 + 1];

    }

    piVar12 = (int *)piVar4[local_154 * 2];

    if (piVar12 == (int *)0x0) {

      piVar12 = (int *)piVar4[local_154 * 2 + 1];

    }

    *piVar10 = *piVar12 + *piVar8;

    if (piVar4[iVar9 * 2 + 1] == 0) {

      sVar3 = (short)(piVar4[iVar9 * 2] - (int)DAT_00d1eab0 >> 3);

    }

    else {

      iVar13 = piVar4[iVar9 * 2 + 1] - DAT_00d1eabc;

      sVar3 = -1 - (((short)(iVar13 / 0xc) + (short)(iVar13 >> 0x1f)) -

                   (short)((longlong)iVar13 * 0x2aaaaaab >> 0x3f));

    }

    *(short *)(piVar10 + 1) = sVar3;

    if (piVar4[local_154 * 2 + 1] == 0) {

      sVar3 = (short)(piVar4[local_154 * 2] - (int)DAT_00d1eab0 >> 3);

    }

    else {

      sVar3 = -1 - (short)((piVar4[local_154 * 2 + 1] - DAT_00d1eabc) / 0xc);

    }

    *(short *)((int)piVar10 + 6) = sVar3;

    iVar13 = local_154;

    if (iVar9 <= local_154) {

      iVar13 = iVar9;

      iVar9 = local_154;

    }

    piVar4[iVar13 * 2 + 1] = 0;

    piVar4[iVar13 * 2] = (int)piVar10;

    local_150 = local_150 + -1;

    if (local_154 != local_150) {

      piVar4[iVar9 * 2] = *local_14c;

      piVar4[iVar9 * 2 + 1] = local_14c[1];

    }

    local_14c = local_14c + -2;

  } while (local_150 != 1);

  puVar2 = (uint32_t /* width from decompiler */ *)*piVar4;

  *DAT_00d1eab0 = *puVar2;

  DAT_00d1eab0[1] = puVar2[1];

  operator_delete__(piVar4);

  local_10c = 0x20;

  local_108 = 0x20;

  local_12c = &local_13c;

  local_13c = 0;

  local_134 = (uint32_t /* width from decompiler */ *)0x0;

  local_130 = 0;

  local_128 = 4;

  local_124 = '\0';

  local_138 = &PTR_LAB_009d7b94;

  local_120 = 0;

  local_11c = 0;

  local_11b = 0;

  local_100 = 0;

  local_104 = 0;

  FUN_0077d440(&local_138,0,0);

  local_138 = &PTR_LAB_009d7b00;

  if (local_124 != '\0') {

    free(local_12c);

  }

  while (local_134 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)local_134[2];

    *local_134 = 0;

    local_134[1] = 0;

    local_134[2] = 0;

    local_134 = puVar2;

  }

  return;

}
