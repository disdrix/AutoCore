// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797530
// -----------------------------------------------------------------------------
// Stable ID: aa_00797530
// Callee of Named_CalleeOf_Client_RecvBroadcast (+1 other named callers)
// Address:   0x00797530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_RecvBroadcast (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×12, for×4, while×1, goto×1, return×1.
//  - Notable callees: end×2, FUN_00426ff0, FUN_00427050, FUN_00427210, FUN_004275b0, FUN_00427a40, FUN_00797530, push_back.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvBroadcast (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797530(char param_1)



{

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *this;

  short sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar7;

  int *piVar8;

  int local_9c;

  int local_98;

  uint local_94;

  int local_8c;

  int local_88;

  int local_84;

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_80 [28];

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_2c [8];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009add2c;

  local_c = ExceptionList;

  this = (basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *)

         (unaff_EBX + 3);

  ExceptionList = &local_c;

  puVar3 = (uint32_t /* width from decompiler */ *)

           std::

           basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

           end(this);

  sVar1 = *(short *)*puVar3;

  while (sVar1 == 0x20) {

    std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

    resize(this,unaff_EBX[8] - 1);

    unaff_EBX[0x2c] = unaff_EBX[0x2c] + -1;

    puVar3 = (uint32_t /* width from decompiler */ *)

             std::

             basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

             end(this);

    sVar1 = *(short *)*puVar3;

  }

  if ((unaff_EBX[8] == 0) &&

     ((unaff_EBX[0x25] == 0 || ((uint)((unaff_EBX[0x26] - unaff_EBX[0x25]) / 0x60) < 2)))) {

    if (unaff_EBX[0x33] == 1) {

      *unaff_EBX = (int)((float)unaff_EBX[0x28] * DAT_00a0f298);

    }

    else if (unaff_EBX[0x33] == 2) {

      *unaff_EBX = (int)(float)unaff_EBX[0x28];

    }

  }

  else {

    iVar6 = unaff_EBX[0x33];

    if (iVar6 == 1) {

      *unaff_EBX = *unaff_EBX +

                   (int)(((float)unaff_EBX[0x28] - (float)unaff_EBX[0x29]) * DAT_00a0f298);

    }

    else if (iVar6 == 2) {

      *unaff_EBX = *unaff_EBX + (int)((float)unaff_EBX[0x28] - (float)unaff_EBX[0x29]);

    }

    else if ((iVar6 == 3) && (param_1 == '\0')) {

      unaff_EBX[2] = (int)(((float)unaff_EBX[0x28] - (float)unaff_EBX[0x29]) /

                          (float)unaff_EBX[0x2c]);

    }

    if ((unaff_EBX[0x25] != 0) && (1 < (uint)((unaff_EBX[0x26] - unaff_EBX[0x25]) / 0x60))) {

      local_9c = 0;

      local_98 = 0;

      for (local_94 = 0;

          (unaff_EBX[0x25] != 0 && (local_94 < (uint)((unaff_EBX[0x26] - unaff_EBX[0x25]) / 0x60)));

          local_94 = local_94 + 1) {

        std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

        basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                  (local_80);

        local_4 = 0;

        iVar6 = unaff_EBX[0x25];

        local_88 = unaff_EBX[1];

        local_8c = (int)((float)*unaff_EBX + *(float *)(local_98 + iVar6));

        local_84 = unaff_EBX[2];

        local_60 = *(uint32_t /* width from decompiler */ *)(local_98 + 0xc + iVar6);

        local_64 = *(uint32_t /* width from decompiler */ *)(local_98 + 8 + iVar6);

        local_5c = *(uint32_t /* width from decompiler */ *)(local_98 + 0x10 + iVar6);

        local_58 = *(uint32_t /* width from decompiler */ *)(local_98 + 0x14 + iVar6);

        local_54 = *(uint32_t /* width from decompiler */ *)(local_98 + 0x18 + iVar6);

        local_50 = *(uint32_t /* width from decompiler */ *)(local_98 + 0x1c + iVar6);

        local_4c = *(uint32_t /* width from decompiler */ *)(local_98 + 0x20 + iVar6);

        puVar3 = (uint32_t /* width from decompiler */ *)(local_98 + 0x24 + iVar6);

        local_48 = *puVar3;

        local_44 = puVar3[1];

        local_40 = puVar3[2];

        local_3c = puVar3[3];

        local_38 = *(uint32_t /* width from decompiler */ *)(local_98 + 0x34 + iVar6);

        local_34 = *(uint32_t /* width from decompiler */ *)(local_98 + 0x38 + iVar6);

        puVar3 = (uint32_t /* width from decompiler */ *)(local_98 + 0x40 + iVar6);

        puVar7 = local_2c;

        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {

          *puVar7 = *puVar3;

          puVar3 = puVar3 + 1;

          puVar7 = puVar7 + 1;

        }

        iVar5 = 0;

        if (iVar6 != 0) {

          iVar5 = (unaff_EBX[0x26] - iVar6) / 0x60;

        }

        iVar2 = local_9c;

        if (local_94 < iVar5 - 1U) {

          local_9c = *(int *)(local_98 + 100 + iVar6);

        }

        else {

          local_9c = unaff_EBX[8];

        }

        for (; iVar2 < local_9c; iVar2 = iVar2 + 1) {

          if ((uint)unaff_EBX[9] < 8) {

            piVar4 = unaff_EBX + 4;

          }

          else {

            piVar4 = (int *)unaff_EBX[4];

          }

          std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

          ::push_back(local_80,*(wchar_t *)((int)piVar4 + iVar2 * 2));

        }

        iVar6 = unaff_EBX[0x21];

        if ((iVar6 == 0) ||

           ((uint)(unaff_EBX[0x23] - iVar6 >> 7) <= (uint)(unaff_EBX[0x22] - iVar6 >> 7))) {

          FUN_004275b0(unaff_EBX + 0x20,unaff_EBX[0x22],1,&local_8c);

        }

        else {

          iVar6 = unaff_EBX[0x22];

          FUN_00427a40(iVar6,local_9c);

          unaff_EBX[0x22] = iVar6 + 0x80;

        }

        local_4 = 0xffffffff;

        std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

        ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                  (local_80);

        local_98 = local_98 + 0x60;

      }

      goto LAB_00797934;

    }

    if ((unaff_EBX[0x25] != 0) && ((unaff_EBX[0x26] - unaff_EBX[0x25]) / 0x60 != 0)) {

      FUN_00426ff0();

      piVar4 = (int *)(unaff_EBX[0x25] + 0x40);

      piVar8 = unaff_EBX + 0x18;

      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {

        *piVar8 = *piVar4;

        piVar4 = piVar4 + 1;

        piVar8 = piVar8 + 1;

      }

    }

  }

  unaff_EBX[0xb] = unaff_EBX[0x31];

  unaff_EBX[10] = unaff_EBX[0x30];

  FUN_00427050();

LAB_00797934:

  unaff_EBX[1] = unaff_EBX[1] + (int)(float)unaff_EBX[0x2b];

  *(uint8_t *)(unaff_EBX + 0x2d) = 1;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::resize

            (this,0);

  FUN_00427210(0);

  ExceptionList = local_c;

  return;

}
