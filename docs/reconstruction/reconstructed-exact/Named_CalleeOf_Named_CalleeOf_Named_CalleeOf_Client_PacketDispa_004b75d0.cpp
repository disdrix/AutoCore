// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004b75d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b75d0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x004b75d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~261 non-empty decompiler lines.
//  - Control keywords: if×19, goto×8, while×3, do×1, switch×1, return×1.
//  - Notable callees: FUN_004e8bf0×4, FUN_004e96e0×3, SQRT×2, FUN_004b75d0, FUN_004e88e0, FUN_004e9530, FUN_0096d460, Object_ResolveFromTFID.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004b75d0(int param_1)



{

  char cVar1;

  int iVar2;

  float fVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  uint8_t *puVar8;

  float *pfVar9;

  uint32_t /* width from decompiler */ *puVar10;

  float *pfVar11;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  int *local_c0;

  int iStack_bc;

  float fStack_b8;

  int *local_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

  uint32_t /* width from decompiler */ uStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint8_t auStack_6c [12];

  uint8_t auStack_60 [16];

  uint8_t auStack_50 [16];

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [28];

  

  local_b4 = *(int **)(param_1 + 0x228);

  piVar6 = (int *)*local_b4;

  local_c0 = piVar6;

  if (piVar6 != local_b4) {

    do {

      iVar2 = piVar6[4];

      if (((((*(char *)(iVar2 + 0x20) == '\0') || (*(int *)(param_1 + 0x2c) == 0)) ||

           (*(int *)(param_1 + 0x10) == 0)) ||

          ((((piVar5 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x68)), piVar5 == (int *)0x0 &&

             (iVar7 = *(int *)(iVar2 + 4), iVar7 != 5)) &&

            ((iVar7 != 6 && ((iVar7 != 4 && (iVar7 != 1)))))) && (piVar6 = local_c0, iVar7 != 0))))

         || ((iStack_bc = (**(code **)(**(int **)(param_1 + 0x10) + 0x1cc))(), piVar6 = local_c0,

             iStack_bc == 0 || (*(int **)(iStack_bc + 8) == (int *)0x0)))) goto LAB_004b7dcc;

      if (*(int *)(iVar2 + 0x24) == -1) {

        iVar7 = (**(code **)(**(int **)(iStack_bc + 8) + 0xc))();

        puVar8 = auStack_30;

LAB_004b76b2:

        pfVar9 = (float *)FUN_004e9530(puVar8,iVar7 + 0x90);

        fStack_d0 = *pfVar9;

        fStack_cc = pfVar9[1];

        fStack_c8 = pfVar9[2];

        fStack_c4 = pfVar9[3];

      }

      else {

        piVar6 = (int *)FUN_0096d460(*(int *)(iVar2 + 0x24));

        if (piVar6 != (int *)0x0) {

          iVar7 = (**(code **)(*piVar6 + 0xc))();

          puVar8 = auStack_60;

          goto LAB_004b76b2;

        }

      }

      if (piVar5 == (int *)0x0) {

        fStack_d4 = 0.0;

        fStack_d8 = 0.0;

        fStack_dc = 0.0;

        fStack_e0 = 0.0;

      }

      else {

        (**(code **)(*piVar5 + 0x144))();

        fStack_e0 = (float)piVar5[0x20];

        fStack_dc = (float)piVar5[0x21];

        fStack_d8 = (float)piVar5[0x22];

        fStack_d4 = (float)piVar5[0x23];

        iVar7 = (**(code **)(*piVar5 + 0x1cc))();

        if ((iVar7 != 0) && (*(int **)(iVar7 + 8) != (int *)0x0)) {

          iVar7 = (**(code **)(**(int **)(iVar7 + 8) + 0x48))();

          fStack_dc = *(float *)(iVar7 + 4) + fStack_dc;

        }

        fStack_d4 = fStack_d4 - fStack_c4;

        fStack_e0 = fStack_e0 - fStack_d0;

        fStack_dc = fStack_dc - fStack_cc;

        fStack_d8 = fStack_d8 - fStack_c8;

      }

      switch(*(uint32_t /* width from decompiler */ *)(iVar2 + 4)) {

      case 0:

        if (fStack_d8 * fStack_d8 + fStack_dc * fStack_dc + fStack_e0 * fStack_e0 == 0.0) {

          if (*(char *)(iVar2 + 0x20) == '\x02') {

LAB_004b77fd:

            fStack_e0 = *(float *)(param_1 + 0x80);

            fStack_dc = *(float *)(param_1 + 0x84);

            fStack_d8 = *(float *)(param_1 + 0x88);

            fStack_d4 = *(float *)(param_1 + 0x8c);

            goto LAB_004b781d;

          }

        }

        else {

LAB_004b79c4:

          *(uint8_t *)(iVar2 + 0x20) = 2;

          *(float *)(param_1 + 0x80) = fStack_e0 + fStack_d0;

          *(float *)(param_1 + 0x84) = fStack_dc + fStack_cc;

          *(float *)(param_1 + 0x88) = fStack_d8 + fStack_c8;

          *(float *)(param_1 + 0x8c) = fStack_d4 + fStack_c4;

        }

        break;

      case 1:

        if (fStack_d8 * fStack_d8 + fStack_dc * fStack_dc + fStack_e0 * fStack_e0 == 0.0) {

          if (*(char *)(iVar2 + 0x20) == '\x01') {

            iVar7 = (**(code **)(**(int **)(iStack_bc + 8) + 0xc))();

            puVar10 = (uint32_t /* width from decompiler */ *)FUN_004e96e0(auStack_40,iVar7 + 0x80);

            uStack_90 = *puVar10;

            uStack_8c = puVar10[1];

            uStack_88 = puVar10[2];

            uStack_84 = puVar10[3];

            FUN_004e8bf0(&fStack_d0,&uStack_90,param_1 + 0x80,&fStack_e0);

          }

          else {

            fStack_e0 = *(float *)(param_1 + 0x80);

            fStack_dc = *(float *)(param_1 + 0x84);

            fStack_d8 = *(float *)(param_1 + 0x88);

            fStack_d4 = *(float *)(param_1 + 0x8c);

          }

          fStack_e0 = fStack_e0 - fStack_d0;

          fStack_dc = fStack_dc - fStack_cc;

          fStack_d8 = fStack_d8 - fStack_c8;

          fStack_d4 = fStack_d4 - fStack_c4;

        }

        else {

          *(uint8_t *)(iVar2 + 0x20) = 2;

          *(float *)(param_1 + 0x80) = fStack_e0 + fStack_d0;

          *(float *)(param_1 + 0x84) = fStack_dc + fStack_cc;

          *(float *)(param_1 + 0x88) = fStack_d8 + fStack_c8;

          *(float *)(param_1 + 0x8c) = fStack_d4 + fStack_c4;

        }

        fStack_b8 = fStack_d8 * fStack_d8 + fStack_dc * fStack_dc + fStack_e0 * fStack_e0;

        if (fStack_b8 != 0.0) {

          fVar3 = g_flOne / SQRT(fStack_b8);

          fStack_e0 = fStack_e0 * fVar3;

          fStack_dc = fStack_dc * fVar3;

          fStack_d8 = fStack_d8 * fVar3;

          fStack_d4 = fVar3 * fStack_d4;

        }

        break;

      case 4:

        if (fStack_d8 * fStack_d8 + fStack_dc * fStack_dc + fStack_e0 * fStack_e0 == 0.0) {

          if (*(char *)(iVar2 + 0x20) == '\x01') {

            iVar7 = (**(code **)(**(int **)(iStack_bc + 8) + 0xc))();

            puVar10 = (uint32_t /* width from decompiler */ *)FUN_004e96e0(auStack_20,iVar7 + 0x80);

            uStack_80 = *puVar10;

            uStack_7c = puVar10[1];

            uStack_78 = puVar10[2];

            uStack_74 = puVar10[3];

            FUN_004e8bf0(&fStack_d0,&uStack_80,param_1 + 0x80,&fStack_e0);

          }

          else {

            fStack_e0 = *(float *)(param_1 + 0x80);

            fStack_dc = *(float *)(param_1 + 0x84);

            fStack_d8 = *(float *)(param_1 + 0x88);

            fStack_d4 = *(float *)(param_1 + 0x8c);

          }

          fStack_e0 = fStack_e0 - fStack_d0;

          fStack_dc = fStack_dc - fStack_cc;

          fStack_d8 = fStack_d8 - fStack_c8;

          fStack_d4 = fStack_d4 - fStack_c4;

        }

        else {

          *(uint8_t *)(iVar2 + 0x20) = 2;

          *(float *)(param_1 + 0x80) = fStack_e0 + fStack_d0;

          *(float *)(param_1 + 0x84) = fStack_dc + fStack_cc;

          *(float *)(param_1 + 0x88) = fStack_d8 + fStack_c8;

          *(float *)(param_1 + 0x8c) = fStack_d4 + fStack_c4;

        }

        fStack_e0 = SQRT(fStack_e0 * fStack_e0 + fStack_dc * fStack_dc + fStack_d8 * fStack_d8);

        break;

      case 5:

        if (fStack_d8 * fStack_d8 + fStack_dc * fStack_dc + fStack_e0 * fStack_e0 != 0.0)

        goto LAB_004b79c4;

        if (*(char *)(iVar2 + 0x20) != '\x01') goto LAB_004b77fd;

        iVar7 = *(int *)(param_1 + 0x10);

        uStack_b0 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x90);

        uStack_ac = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x94);

        uStack_a8 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x98);

        uStack_a4 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x9c);

        FUN_004e8bf0(&fStack_d0,&uStack_b0,(float *)(param_1 + 0x80),&fStack_e0);

        *(float *)(param_1 + 0x80) = fStack_e0;

        *(float *)(param_1 + 0x84) = fStack_dc;

        *(float *)(param_1 + 0x88) = fStack_d8;

        *(float *)(param_1 + 0x8c) = fStack_d4;

        *(uint8_t *)(iVar2 + 0x20) = 2;

        goto LAB_004b781d;

      case 6:

        if (fStack_d8 * fStack_d8 + fStack_dc * fStack_dc + fStack_e0 * fStack_e0 != 0.0)

        goto LAB_004b79c4;

        if (*(char *)(iVar2 + 0x20) != '\x01') goto LAB_004b77fd;

        iVar7 = (**(code **)(**(int **)(iStack_bc + 8) + 0xc))();

        puVar10 = (uint32_t /* width from decompiler */ *)FUN_004e96e0(auStack_50,iVar7 + 0x80);

        uStack_a0 = *puVar10;

        uStack_9c = puVar10[1];

        uStack_98 = puVar10[2];

        uStack_94 = puVar10[3];

        FUN_004e8bf0(&fStack_d0,&uStack_a0,param_1 + 0x80,&fStack_e0);

LAB_004b781d:

        fStack_e0 = fStack_e0 - fStack_d0;

        fStack_dc = fStack_dc - fStack_cc;

        fStack_d8 = fStack_d8 - fStack_c8;

        fStack_d4 = fStack_d4 - fStack_c4;

      }

      pfVar11 = (float *)FUN_004e88e0(auStack_6c,&fStack_e0);

      pfVar9 = (float *)(iVar2 + 0x14);

      *pfVar9 = *pfVar11;

      *(float *)(iVar2 + 0x18) = pfVar11[1];

      *(float *)(iVar2 + 0x1c) = pfVar11[2];

      *pfVar9 = *(float *)(iVar2 + 8) * *pfVar9;

      *(float *)(iVar2 + 0x18) = *(float *)(iVar2 + 0xc) * *(float *)(iVar2 + 0x18);

      *(float *)(iVar2 + 0x1c) = *(float *)(iVar2 + 0x10) * *(float *)(iVar2 + 0x1c);

      piVar6 = local_c0;

LAB_004b7dcc:

      if (*(char *)((int)piVar6 + 0x15) == '\0') {

        piVar5 = (int *)piVar6[2];

        if (*(char *)((int)piVar5 + 0x15) == '\0') {

          cVar1 = *(char *)(*piVar5 + 0x15);

          piVar6 = piVar5;

          piVar5 = (int *)*piVar5;

          while (local_c0 = piVar6, cVar1 == '\0') {

            cVar1 = *(char *)(*piVar5 + 0x15);

            piVar6 = piVar5;

            piVar5 = (int *)*piVar5;

          }

        }

        else {

          cVar1 = *(char *)(piVar6[1] + 0x15);

          piVar4 = (int *)piVar6[1];

          piVar5 = piVar6;

          while ((piVar6 = piVar4, local_c0 = piVar6, cVar1 == '\0' && (piVar5 == (int *)piVar6[2]))

                ) {

            cVar1 = *(char *)(piVar6[1] + 0x15);

            piVar4 = (int *)piVar6[1];

            piVar5 = piVar6;

          }

        }

      }

    } while (piVar6 != local_b4);

  }

  return;

}
