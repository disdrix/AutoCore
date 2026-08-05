// =============================================================================
// Named_CalleeOf_Inv_Currently_Equipped_00845be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00845be0
// Callee of Inv_Currently_Equipped (+1 other named callers)
// Address:   0x00845be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Inv_Currently_Equipped: callee helper. Evidence string: "(Max. Enhancements: ". Supports parent flow (not a free-standing entry point). Inv_Currently_Equipped (+1 other named callers).
// Embedded strings (evidence):
//   - "(Max. Enhancements: "
//   - "(no enhancement)\n"
//   - "Will Be Permanently Removed"
//   - "(Power Cost per Shot: "
//   - "Gadget Slots: "
//   - " Locked)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~319 non-empty decompiler lines.
//  - Control keywords: if×23, goto×5, do×3, while×3, return×2.
//  - Notable callees: FUN_007a6de0×16, sprintf×7, FUN_00509410×3, FUN_00508ac0×2, CONCAT22, FUN_004ce940, FUN_004f1e20, FUN_005097b0.
//  - Strings: "(Max. Enhancements: "; "(no enhancement)\n"; "Will Be Permanently Removed"; "%s: %s\n".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Inv_Currently_Equipped (+1 other named callers)
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

int Named_CalleeOf_Inv_Currently_Equipped_00845be0(void)



{

  uint16_t uVar1;

  short sVar2;

  short sVar3;

  int *in_EAX;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  int iVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int iVar11;

  int unaff_EBX;

  code *pcVar12;

  int unaff_EBP;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ uVar13;

  int iStack_18c;

  int local_188;

  int iStack_184;

  uint32_t /* width from decompiler */ uStack_178;

  uint32_t /* width from decompiler */ uStack_174;

  uint32_t /* width from decompiler */ uStack_170;

  uint32_t /* width from decompiler */ uStack_16c;

  uint32_t /* width from decompiler */ uStack_168;

  uint32_t /* width from decompiler */ uStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  uint32_t /* width from decompiler */ uStack_150;

  uint32_t /* width from decompiler */ uStack_14c;

  uint32_t /* width from decompiler */ uStack_148;

  int iStack_144;

  uint32_t /* width from decompiler */ uStack_140;

  uint32_t /* width from decompiler */ uStack_13c;

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  uint32_t /* width from decompiler */ uStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  char acStack_108 [4];

  uint32_t /* width from decompiler */ uStack_104;

  uint8_t auStack_100 [108];

  char acStack_94 [12];

  char acStack_88 [136];

  

  local_188 = 0;

  FUN_007a69d0();

  iVar4 = FUN_004ce940();

  iVar5 = (**(code **)(*in_EAX + 0x60))();

  pcVar12 = sprintf_exref;

  if (((((uint)in_EAX[0x5f] >> 0x13 & 1) != 0) || (DAT_00d1791c != '\0')) &&

     (*(char *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x409) != '\0')) {

    iVar8 = *unaff_ESI;

    uVar13 = 0xffbbbbbb;

    uVar6 = FUN_007a6de0("(Max. Enhancements: ",0xffffffff);

    (**(code **)(iVar8 + 0x224))(uVar6,uVar13);

    pcVar12 = sprintf_exref;

    sprintf(acStack_88,"%i",(uint)*(byte *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x409));

    (**(code **)(*unaff_ESI + 0x250))(acStack_88);

    (**(code **)(*unaff_ESI + 0x224))(&DAT_00a393e0,0xffbbbbbb);

  }

  iStack_184 = 0;

  if (0 < iVar5) {

    do {

      if ((iVar4 == 0) || (iVar5 <= iStack_184)) {

        iVar8 = *unaff_ESI;

        uVar13 = 0xffbbbbbb;

        uVar6 = FUN_007a6de0("(no enhancement)\n",0xffffffff);

        (**(code **)(iVar8 + 0x224))(uVar6,uVar13);

        pcVar12 = sprintf_exref;

      }

      else {

        if (DAT_00d1791c != '\0') {

          uVar1 = (**(code **)(*in_EAX + 0x5c))(iStack_184);

          piVar7 = (int *)FUN_005097b0(uVar1);

          if ((piVar7 == (int *)0x0) || (*piVar7 == -1)) {

            iVar8 = iStack_184;

            uVar1 = (**(code **)(*in_EAX + 0x5c))(iStack_184,0xffffffff);

            uVar6 = FUN_00509410(uVar1);

            uVar6 = FUN_007a6de0(uVar6,iVar8);

            uVar13 = FUN_007a6de0("Will Be Permanently Removed",0xffffffff);

            (*pcVar12)(&uStack_104,"%s: %s\n",uVar13,uVar6);

            (**(code **)(*unaff_ESI + 0x224))(&uStack_104,0xffff2020);

            local_188 = local_188 + 1;

            goto LAB_00845e80;

          }

        }

        iVar8 = iStack_184;

        uVar1 = (**(code **)(*in_EAX + 0x5c))(iStack_184,0xffffffff);

        uVar6 = FUN_00509410(uVar1);

        uVar6 = FUN_007a6de0(uVar6,iVar8);

        (*pcVar12)(&uStack_104,&DAT_00a57d38,uVar6);

        (**(code **)(*unaff_ESI + 0x224))(&uStack_104,0xff20ff20);

        unaff_EBP = unaff_EBP + 1;

        uVar1 = (**(code **)(*in_EAX + 0x5c))(unaff_EBX);

        iVar8 = FUN_00508ac0(uVar1);

        if ((iVar8 != 0) && (*(short *)(iVar8 + 0xb6) != 0)) {

          iVar8 = *unaff_ESI;

          uVar13 = 0xffbbbbbb;

          uVar6 = FUN_007a6de0("(Power Cost per Shot: ",0xffffffff);

          (**(code **)(iVar8 + 0x224))(uVar6,uVar13);

          pcVar12 = sprintf_exref;

          sprintf(acStack_108,"%d",(int)*(short *)(iStack_184 + 0xb6));

          (**(code **)(*unaff_ESI + 0x224))(acStack_108,0xffffffff);

          (**(code **)(*unaff_ESI + 0x224))(&DAT_00a393e0,0xffbbbbbb);

          local_188 = local_188 + 1;

        }

      }

LAB_00845e80:

      iStack_184 = iStack_184 + 1;

    } while (iStack_184 < iVar5);

  }

  iVar5 = *(int *)(in_EAX[0x2a] + 0x3c);

  if (DAT_00d1791c == '\0') {

    if (0 < *(short *)(iVar5 + 0x4b4)) {

      if (*(char *)(iVar5 + 0x409) != '\0') {

        (**(code **)(*unaff_ESI + 0x250))(&DAT_00a15104);

      }

      iVar5 = *unaff_ESI;

      uVar13 = 0xffbbbbbb;

      uVar6 = FUN_007a6de0("Gadget Slots: ",0xffffffff);

      (**(code **)(iVar5 + 0x224))(uVar6,uVar13);

      pcVar12 = sprintf_exref;

      sprintf(acStack_88,"%i",(int)*(short *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b4));

      (**(code **)(*unaff_ESI + 0x250))(acStack_88);

      sVar3 = *(short *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b4);

      local_188 = CONCAT22(local_188._2_2_,sVar3);

      sVar2 = (**(code **)(*in_EAX + 0x8c))();

      if (sVar2 == sVar3) {

        (**(code **)(*unaff_ESI + 0x250))(&DAT_00a15104);

      }

      else {

        (**(code **)(*unaff_ESI + 0x224))(&DAT_00a69ae8,0xffbbbbbb);

        sVar3 = *(short *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b4);

        sVar2 = (**(code **)(*in_EAX + 0x8c))();

        sprintf(acStack_94,"%i",(int)sVar3 - (int)sVar2);

        (**(code **)(*unaff_ESI + 0x250))(acStack_94);

        iVar5 = *unaff_ESI;

        uVar13 = 0xffbbbbbb;

        uVar6 = FUN_007a6de0(" Locked)\n",0xffffffff);

        (**(code **)(iVar5 + 0x224))(uVar6,uVar13);

        pcVar12 = sprintf_exref;

      }

      local_188 = local_188 + 1;

    }

    iVar5 = (**(code **)(*in_EAX + 0x80))();

    iStack_184 = 0;

    if (0 < *(short *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b4)) {

      do {

        if ((iVar4 == 0) || (iVar5 <= iStack_184)) {

LAB_00846390:

          sVar3 = (**(code **)(*in_EAX + 0x8c))();

          iVar8 = local_188;

          if (iStack_184 < sVar3) {

            piVar7 = (int *)(**(code **)(*unaff_ESI + 0x1b8))();

            uVar6 = *(uint32_t /* width from decompiler */ *)(*piVar7 + 0x7c);

            piVar7 = (int *)(**(code **)(*unaff_ESI + 0x1b8))();

            uStack_160 = *(uint32_t /* width from decompiler */ *)(*piVar7 + 0x7c);

            uStack_170 = 1;

            uStack_150 = 1;

            uStack_16c = 0;

            uStack_14c = 0;

            uStack_120 = 0x15;

            uStack_11c = 10;

            uStack_118 = 0x29;

            uStack_114 = 0x20;

            uStack_15c = uVar6;

            (**(code **)(*unaff_ESI + 600))

                      (*(uint32_t /* width from decompiler */ *)(DAT_00d1ad30 + 0x18),&uStack_160,&uStack_120,&uStack_170,

                       &uStack_150);

            (**(code **)(*unaff_ESI + 0x250))(&DAT_00a2a000);

            iVar11 = *unaff_ESI;

            uVar13 = 0xffbbbbbb;

            uVar6 = FUN_007a6de0("(Open)\n",0xffffffff);

            (**(code **)(iVar11 + 0x224))(uVar6,uVar13);

            pcVar12 = sprintf_exref;

          }

          else {

            piVar7 = (int *)(**(code **)(*unaff_ESI + 0x1b8))();

            uVar6 = *(uint32_t /* width from decompiler */ *)(*piVar7 + 0x7c);

            piVar7 = (int *)(**(code **)(*unaff_ESI + 0x1b8))();

            uStack_140 = *(uint32_t /* width from decompiler */ *)(*piVar7 + 0x7c);

            uStack_178 = 1;

            uStack_158 = 1;

            puVar10 = &uStack_158;

            uStack_110 = 0;

            uStack_174 = 0;

            uStack_154 = 0;

            uStack_10c = 10;

            acStack_108[0] = '\x14';

            acStack_108[1] = '\0';

            acStack_108[2] = '\0';

            acStack_108[3] = '\0';

            uStack_104 = 0x20;

            uStack_13c = uVar6;

            (**(code **)(*unaff_ESI + 600))

                      (*(uint32_t /* width from decompiler */ *)(DAT_00d1ad30 + 0x18),&uStack_140,&uStack_110,&uStack_178,

                       puVar10);

            (**(code **)(*unaff_ESI + 0x250))(&DAT_00a2a000);

            iVar11 = (int)puVar10 + 1;

            uVar6 = FUN_007a6de0("(Requires Tinkering Kit %d+)\n",0xffffffff);

            (*pcVar12)(&uStack_118,uVar6,iVar11);

            (**(code **)(*unaff_ESI + 0x224))(&uStack_118,0xffbbbbbb);

          }

        }

        else {

          piVar7 = (int *)(**(code **)(*unaff_ESI + 0x1b8))();

          iVar8 = *(int *)(*piVar7 + 0x7c);

          piVar7 = (int *)(**(code **)(*unaff_ESI + 0x1b8))();

          uStack_148 = *(uint32_t /* width from decompiler */ *)(*piVar7 + 0x7c);

          uStack_164 = 0;

          uStack_134 = 0;

          puVar10 = &uStack_138;

          uStack_168 = 1;

          uStack_138 = 1;

          uStack_130 = 0x2a;

          uStack_12c = 10;

          uStack_128 = 0x3e;

          uStack_124 = 0x20;

          iStack_144 = iVar8;

          (**(code **)(*unaff_ESI + 600))

                    (*(uint32_t /* width from decompiler */ *)(DAT_00d1ad30 + 0x18),&uStack_148,&uStack_130,&uStack_168,

                     puVar10);

          (**(code **)(*unaff_ESI + 0x250))(&DAT_00a2a000);

          uVar9 = (**(code **)(*in_EAX + 0x7c))(puVar10);

          iVar8 = *(int *)(iVar8 + 0xf10);

          iVar8 = *(int *)(*(int *)(*(int *)(iVar8 + 0x10) +

                                   (*(uint *)(iVar8 + 8) & uVar9 & 0xffff) * 4) + 4);

          if (iVar8 == 0) {

LAB_0084624b:

            iStack_18c = 0;

          }

          else {

            do {

              if ((uVar9 & 0xffff) == *(uint *)(iVar8 + 0x10)) {

                if (iVar8 == 0) goto LAB_0084624b;

                iStack_18c = *(int *)(iVar8 + 8);

                goto LAB_0084625c;

              }

              iVar8 = *(int *)(iVar8 + 0xc);

            } while (iVar8 != 0);

            iStack_18c = 0;

          }

LAB_0084625c:

          if (iStack_18c == 0) {

            iVar8 = *unaff_ESI;

            uVar13 = 0xffffc529;

            uVar6 = FUN_007a6de0("*Unknown Gadget*\n",0xffffffff);

            (**(code **)(iVar8 + 0x224))(uVar6,uVar13);

            pcVar12 = sprintf_exref;

            goto LAB_00846390;

          }

          if (*(int *)(iStack_18c + 0x3c) == 0) {

            FUN_004f1e20(1,1);

          }

          puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iStack_18c + 0x3c) + 0x4c0);

          if (puVar10 == (uint32_t /* width from decompiler */ *)0x0) goto LAB_00846390;

          uVar13 = 0xffffffff;

          uVar6 = FUN_00509410(*puVar10);

          uVar6 = FUN_007a6de0(uVar6,uVar13);

          (*pcVar12)(auStack_100,&DAT_00a57d38,uVar6);

          (**(code **)(*unaff_ESI + 0x224))(auStack_100,0xffffc529);

          iVar11 = FUN_00508ac0(*puVar10);

          iVar8 = local_188 + 1;

          if ((iVar11 != 0) && (*(short *)(iVar11 + 0xb6) != 0)) {

            iVar8 = *unaff_ESI;

            uVar13 = 0xffbbbbbb;

            uVar6 = FUN_007a6de0("(Power Cost per Shot: ",0xffffffff);

            (**(code **)(iVar8 + 0x224))(uVar6,uVar13);

            pcVar12 = sprintf_exref;

            sprintf(acStack_108,"%d",(int)*(short *)(unaff_EBP + 0xb6));

            (**(code **)(*unaff_ESI + 0x224))(acStack_108,0xffffffff);

            (**(code **)(*unaff_ESI + 0x224))(&DAT_00a393e0,0xffbbbbbb);

            iVar8 = local_188 + 2;

          }

        }

        local_188 = iVar8;

        iStack_184 = iStack_184 + 1;

      } while (iStack_184 < *(short *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b4));

    }

  }

  else if (0 < *(short *)(iVar5 + 0x4b4)) {

    if (*(char *)(iVar5 + 0x409) != '\0') {

      (**(code **)(*unaff_ESI + 0x250))(&DAT_00a15104);

    }

    iVar4 = *unaff_ESI;

    uVar13 = 0xffbbbbbb;

    uVar6 = FUN_007a6de0("Gadget Slots: ",0xffffffff);

    (**(code **)(iVar4 + 0x224))(uVar6,uVar13);

    sprintf(acStack_88,"%i",(int)*(short *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b4));

    (**(code **)(*unaff_ESI + 0x250))(acStack_88);

    (**(code **)(*unaff_ESI + 0x224))(&DAT_00a69ae8,0xffbbbbbb);

    sprintf(acStack_94,"%i",(int)*(short *)(*(int *)(in_EAX[0x2a] + 0x3c) + 0x4b4));

    (**(code **)(*unaff_ESI + 0x250))(acStack_94);

    iVar4 = *unaff_ESI;

    uVar13 = 0xffbbbbbb;

    uVar6 = FUN_007a6de0(" Locked)\n",0xffffffff);

    (**(code **)(iVar4 + 0x224))(uVar6,uVar13);

    iVar4 = (**(code **)(*in_EAX + 0x80))();

    if (iVar4 != 0) {

      iVar4 = *unaff_ESI;

      uVar13 = 0xffffff33;

      uVar6 = FUN_007a6de0("(Current Gadgets Will Be Lost!)\n",0xffffffff);

      (**(code **)(iVar4 + 0x224))(uVar6,uVar13);

      return unaff_EBX;

    }

  }

  return local_188;

}
