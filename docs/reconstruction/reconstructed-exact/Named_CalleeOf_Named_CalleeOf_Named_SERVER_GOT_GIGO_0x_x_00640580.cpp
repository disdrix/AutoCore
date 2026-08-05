// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00640580
// -----------------------------------------------------------------------------
// Stable ID: aa_00640580
// Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x00640580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~286 non-empty decompiler lines.
//  - Control keywords: if×25, goto×4, do×3, while×3, for×1, return×1.
//  - Notable callees: FUN_00652910×12, FUN_00641860×6, FUN_00638180×3, FUN_005b3300×2, FUN_00638060×2, FUN_006380a0×2, FUN_006381a0×2, FUN_006326b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

/* WARNING: Removing unreachable block (ram,0x00640983) */



uint8_t * Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00640580(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,ushort param_3)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  uint8_t *puVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ *puVar10;

  ushort *puVar11;

  uint uVar12;

  uint uVar13;

  undefined *puVar14;

  uint uVar15;

  int *piVar16;

  uint uStack_80;

  ushort *puStack_7c;

  uint uStack_78;

  uint32_t /* width from decompiler */ *puStack_74;

  int iStack_70;

  uint32_t /* width from decompiler */ *puStack_6c;

  int iStack_68;

  int iStack_64;

  uint32_t /* width from decompiler */ uStack_4c;

  int iStack_48;

  uint uStack_44;

  int iStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  int *piStack_38;

  undefined *local_34;

  uint8_t *puStack_30;

  int iStack_2c;

  uint32_t /* width from decompiler */ local_28;

  ushort auStack_24 [8];

  ushort auStack_14 [8];

  ushort auStack_4 [2];

  

  iStack_64 = 1;

  local_28 = 0;

  iStack_68 = 2;

  puStack_6c = (uint32_t /* width from decompiler */ *)&param_3;

  *param_2 = 0;

  iStack_70 = 0x6405b1;

  FUN_00652910();

  puVar10 = (uint32_t /* width from decompiler */ *)(uint)param_3;

  iStack_64 = 5;

  iStack_68 = (int)puVar10 + 1;

  puStack_6c = (uint32_t /* width from decompiler */ *)0x6405c6;

  iVar2 = (**(code **)*DAT_00b05060)();

  puStack_74 = (uint32_t /* width from decompiler */ *)0x6405d5;

  iStack_70 = iVar2;

  puStack_6c = puVar10;

  iStack_40 = iVar2;

  FUN_00641860();

  puStack_74 = (uint32_t /* width from decompiler */ *)0x1;

  uStack_78 = 2;

  puStack_7c = auStack_4;

  *(uint8_t *)((int)puVar10 + iVar2) = 0;

  uStack_80 = 0x6405e9;

  FUN_00652910();

  puVar11 = (ushort *)(uint)auStack_4[0];

  puStack_74 = (uint32_t /* width from decompiler */ *)0x5;

  uStack_78 = (int)puVar11 + 1;

  puStack_7c = (ushort *)0x6405fe;

  uVar3 = (**(code **)*DAT_00b05060)();

  uStack_80 = uVar3;

  puStack_7c = puVar11;

  uStack_44 = uVar3;

  FUN_00641860();

  *(uint8_t *)((int)puVar11 + uVar3) = 0;

  FUN_00652910(auStack_14,2,1);

  uVar12 = (uint)auStack_14[0];

  piVar16 = (int *)0x5;

  uVar3 = uVar12 + 1;

  uVar4 = (**(code **)*DAT_00b05060)(uVar3);

  uVar15 = uVar12;

  FUN_00641860(uVar4,uVar12);

  *(uint8_t *)(uVar12 + uVar4) = 0;

  FUN_00652910(auStack_24,2,1);

  uVar12 = (uint)auStack_24[0];

  puStack_74 = (uint32_t /* width from decompiler */ *)0x0;

  iStack_48 = 0;

  uStack_44 = 0;

  iStack_40 = -0x80000000;

  uVar13 = uVar12;

  if (uVar12 != 0) {

    FUN_005b3300(&iStack_48,uVar12,1);

    uStack_44 = uVar12;

    puStack_74 = (uint32_t /* width from decompiler */ *)(**(code **)*DAT_00b05060)(uVar12 << 4,5);

    iStack_70 = 0;

    puVar10 = puStack_74;

    uVar13 = uStack_44;

    if (uVar12 != 0) {

      do {

        puStack_6c = puVar10;

        FUN_00652910(auStack_24,2,1);

        uVar13 = (uint)auStack_24[0];

        iVar2 = (**(code **)*DAT_00b05060)(uVar13 + 1,5);

        FUN_00641860(iVar2,uVar13);

        *(uint8_t *)(uVar13 + iVar2) = 0;

        FUN_00652910(&stack0xffffffa8,2,1);

        if ((ushort)uVar4 < 0x100) {

          *(uint8_t *)(iStack_70 + iStack_48) = 0;

          uVar13 = uVar4;

        }

        else {

          *(char *)(iStack_70 + iStack_48) = (char)(uVar4 >> 8);

          uVar13 = uVar4 & 0xff;

        }

        FUN_00652910(&uStack_78,2,1);

        FUN_00652910(&puStack_7c,2,1);

        FUN_00652910(&uStack_80,2,1);

        if (puStack_6c != (uint32_t /* width from decompiler */ *)0x0) {

          FUN_00651cf0(iVar2,0,uVar13 & 0xffff,uStack_78 & 0xffff,(uint)puStack_7c & 0xffff,

                       uStack_80 & 0xffff);

        }

        puStack_6c = puStack_6c + 4;

        iStack_70 = iStack_70 + 1;

        iVar2 = iStack_68;

        puVar10 = puStack_6c;

        uVar13 = uStack_44;

      } while (iStack_70 < (int)uVar12);

    }

  }

  uStack_44 = uVar13;

  FUN_00652910(&uStack_78,2,1);

  FUN_00652910(&uStack_80,2,1);

  if ((*(int *)(iStack_64 + 0x18) == 0) ||

     (puStack_7c = (ushort *)(**(code **)(**(int **)(iStack_64 + 0x18) + 8))(iVar2),

     puStack_7c == (ushort *)0x0)) {

    if (puStack_74 != (uint32_t /* width from decompiler */ *)0x0) {

      piVar9 = (int *)(iStack_64 + 0x1c);

      puStack_7c = (ushort *)(**(code **)(*(int *)(iStack_64 + 0x1c) + 8))(iVar2);

      if (puStack_7c != (ushort *)0x0) goto LAB_00640846;

      iVar5 = (**(code **)(*DAT_00b05060 + 0x10))(0x28,0x19);

      *(uint16_t *)(iVar5 + 4) = 0x28;

      piVar16 = (int *)FUN_006326b0(iVar2,0,0,uVar3 & 0xffff,0,0,puStack_7c,uVar12);

      (**(code **)(*piVar9 + 4))(piVar16,iVar2);

      goto LAB_0064087c;

    }

  }

  else {

LAB_00640846:

    puVar10 = puStack_74;

    if (puStack_74 != (uint32_t /* width from decompiler */ *)0x0) {

      for (; uVar12 != 0; uVar12 = uVar12 - 1) {

        (**(code **)(*DAT_00b05060 + 4))(*puVar10);

        puVar10 = puVar10 + 4;

      }

      (**(code **)(*DAT_00b05060 + 4))(puStack_74);

    }

LAB_0064087c:

    if (puStack_7c != (ushort *)0x0) {

      uStack_4c = 0x80000000;

      local_34 = (undefined *)0x80000000;

      uStack_3c = 0;

      piStack_38 = (int *)0x0;

      FUN_006327e0(auStack_24,&uStack_3c);

      uVar3 = (int)piStack_38 * 0x10 + (uStack_78 & 0xffff);

      puVar6 = (uint8_t *)0x0;

      if (0 < (int)uVar3) {

        if (0 < (int)uVar3) {

          uVar12 = 0;

          if (-1 < (int)uVar3) {

            uVar12 = uVar3;

          }

          FUN_005b3300(&stack0xffffffac,uVar12,1);

        }

        if (0 < (int)uVar3) {

          do {

            *puVar6 = 0;

            puVar6 = puVar6 + 1;

          } while ((int)puVar6 < (int)uVar3);

        }

      }

      uVar12 = uStack_80 & 0xffff;

      FUN_00641860(0,uVar12);

      FUN_00652910(&iStack_2c,2,1);

      uVar12 = uVar12 + 0xf & 0xfffffff0;

      iStack_2c = 0;

      if (0 < iStack_40) {

        do {

          iVar2 = *(int *)(uStack_44 + iStack_2c * 4);

          iVar5 = (**(code **)(*piVar16 + 0x20))(iVar2);

          bVar1 = *(byte *)(iVar2 + uVar3);

          iVar2 = *(int *)(*(ushort *)(iVar5 + 0xe) + 4 + unaff_ESI);

          piVar9 = (int *)((uint)*(ushort *)(iVar5 + 0xe) + unaff_ESI);

          if (iVar2 == 0) {

            *piVar9 = 0;

            piVar9[2] = 0;

          }

          else {

            piVar9[2] = iVar2;

            iVar2 = iVar2 * (uint)bVar1;

            *piVar9 = unaff_ESI + uVar12;

            iVar5 = FUN_00641860(*piVar9,iVar2);

            if (iVar5 != iVar2) {

              (**(code **)(*DAT_00b05060 + 4))(iStack_70);

              *puStack_30 = 0;

              puVar6 = puStack_30;

              goto LAB_00640b4d;

            }

            uVar12 = uVar12 + (iVar2 + 0xfU & 0xfffffff0);

          }

          iStack_2c = iStack_2c + 1;

          iVar2 = iStack_70;

        } while (iStack_2c < iStack_40);

      }

      iVar5 = (**(code **)(*DAT_00b05060 + 0x10))(0x24,6);

      puVar10 = puStack_6c;

      *(uint16_t *)(iVar5 + 4) = 0x24;

      if (puStack_6c == (uint32_t /* width from decompiler */ *)0x0) {

        DAT_00d02c6c = DAT_00d02c6c + 1;

        local_34 = &DAT_00d02c70;

      }

      else {

        iVar5 = FUN_00638060(puStack_6c);

        iVar7 = FUN_006381a0(iVar5);

        local_34 = (undefined *)(iVar7 + 0xc);

        FUN_006380a0(local_34,puVar10,iVar5 + 1);

      }

      iVar5 = FUN_00652bc0(&local_34,uVar15);

      piVar16 = (int *)(local_34 + -4);

      *piVar16 = *piVar16 + -1;

      if (*piVar16 < 0) {

        FUN_00638180();

      }

      *piStack_38 = iVar5;

      if (iStack_70 == 0) {

        DAT_00d02c6c = DAT_00d02c6c + 1;

        puVar14 = &DAT_00d02c70;

      }

      else {

        iVar7 = FUN_00638060(iStack_70);

        iVar8 = FUN_006381a0(iVar7);

        puVar14 = (undefined *)(iVar8 + 0xc);

        FUN_006380a0(puVar14,iStack_70,iVar7 + 1);

      }

      *(int *)(puVar14 + -4) = *(int *)(puVar14 + -4) + 1;

      piVar16 = (int *)(*(int *)(iVar5 + 0x10) + -4);

      *piVar16 = *piVar16 + -1;

      if (*piVar16 < 0) {

        FUN_00638180();

      }

      *(undefined **)(iVar5 + 0x10) = puVar14;

      piVar16 = (int *)(puVar14 + -4);

      *piVar16 = *piVar16 + -1;

      if (*piVar16 < 0) {

        FUN_00638180();

      }

      iVar7 = *(int *)(iVar5 + 0x18);

      *(int *)(iVar5 + 0x18) = iStack_64;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x1c) = unaff_EDI;

      *(int *)(iVar5 + 0x20) = unaff_ESI;

      iStack_64 = iVar7;

      if (puStack_74[6] != 0) {

        (**(code **)(*DAT_00b05060 + 4))(iVar2);

      }

      (**(code **)(*DAT_00b05060 + 4))(puStack_6c);

      (**(code **)(*DAT_00b05060 + 4))(puStack_74);

      *puStack_30 = 1;

      puVar6 = puStack_30;

LAB_00640b4d:

      if (-1 < (int)piStack_38) {

        (**(code **)(*DAT_00b05060 + 0x14))(iStack_40,(int)piStack_38 * 4,0x12);

      }

      if (-1 < (int)uVar3) {

        (**(code **)(*DAT_00b05060 + 0x14))(uVar4,uVar3 & 0x7fffffff,0x12);

      }

      goto LAB_00640b91;

    }

  }

  (**(code **)(*DAT_00b05060 + 4))(iVar2);

  *puStack_30 = 0;

  puVar6 = puStack_30;

LAB_00640b91:

  if (-1 < (int)uStack_44) {

    (**(code **)(*DAT_00b05060 + 0x14))(uStack_4c,uStack_44 & 0x7fffffff,0x12);

  }

  return puVar6;

}
