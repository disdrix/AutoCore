// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007e26e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007e26e0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007e26e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "DBReader: %u against %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DBReader: %u against %s"
//   - "dcFetch2::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~270 non-empty decompiler lines.
//  - Control keywords: if×14, return×2, do×1, while×1.
//  - Notable callees: FUN_004231d0×56, FUN_0041a3e0×3, FUN_00423170×3, wcscpy×3, FUN_0041a810×2, FUN_0041a9b0×2, FUN_0041bf70×2, FUN_00422de0×2.
//  - Strings: "DBReader: %u against %s"; "dcFetch2::Open".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

int __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007e26e0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint8_t uStack_9a8;

  uint8_t uStack_9a7;

  uint8_t uStack_9a6;

  uint8_t uStack_9a5;

  short sStack_9a4;

  uint8_t uStack_99d;

  uint8_t uStack_995;

  uint32_t /* width from decompiler */ uStack_994;

  uint32_t /* width from decompiler */ uStack_990;

  wchar_t *pwStack_98c;

  uint32_t /* width from decompiler */ uStack_988;

  int iStack_984;

  uint32_t /* width from decompiler */ uStack_980;

  uint32_t /* width from decompiler */ *puStack_97c;

  uint32_t /* width from decompiler */ uStack_978;

  uint32_t /* width from decompiler */ uStack_974;

  uint32_t /* width from decompiler */ uStack_970;

  uint32_t /* width from decompiler */ uStack_96c;

  uint32_t /* width from decompiler */ local_968;

  uint32_t /* width from decompiler */ local_964;

  wchar_t *local_960;

  uint32_t /* width from decompiler */ local_95c;

  int local_958;

  uint32_t /* width from decompiler */ local_954;

  uint32_t /* width from decompiler */ *local_950;

  uint32_t /* width from decompiler */ local_94c;

  uint32_t /* width from decompiler */ local_948;

  uint32_t /* width from decompiler */ local_944;

  uint32_t /* width from decompiler */ local_940;

  short sStack_93c;

  short sStack_938;

  short sStack_934;

  uint32_t /* width from decompiler */ uStack_930;

  uint32_t /* width from decompiler */ uStack_92c;

  uint32_t /* width from decompiler */ uStack_928;

  uint32_t /* width from decompiler */ uStack_924;

  uint32_t /* width from decompiler */ uStack_920;

  uint32_t /* width from decompiler */ uStack_91c;

  uint32_t /* width from decompiler */ uStack_918;

  uint32_t /* width from decompiler */ uStack_914;

  uint32_t /* width from decompiler */ uStack_910;

  uint32_t /* width from decompiler */ *puStack_90c;

  uint32_t /* width from decompiler */ uStack_908;

  uint32_t /* width from decompiler */ uStack_904;

  uint32_t /* width from decompiler */ uStack_900;

  uint32_t /* width from decompiler */ uStack_8fc;

  uint32_t /* width from decompiler */ uStack_8f8;

  uint32_t /* width from decompiler */ uStack_8f4;

  uint32_t /* width from decompiler */ uStack_8f0;

  uint32_t /* width from decompiler */ uStack_8ec;

  uint32_t /* width from decompiler */ uStack_8e8;

  uint32_t /* width from decompiler */ uStack_8e4;

  uint32_t /* width from decompiler */ uStack_8e0;

  int iStack_8dc;

  wchar_t awStack_8d8 [34];

  wchar_t awStack_894 [66];

  wchar_t awStack_810 [1026];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009b0106;

  local_c = ExceptionList;

  if (DAT_00d1793c == '\0') {

    local_950 = &local_968;

    local_968 = 0;

    local_964 = 0;

    local_960 = (wchar_t *)0x0;

    local_95c = 0;

    local_958 = 0;

    local_954 = 0;

    local_948 = 0;

    local_94c = 0;

    local_944 = 0;

    local_940 = 0;

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_004230d0(local_950,&param_2);

    iVar2 = FUN_00422fb0(1,1,4);

    if (-1 < iVar2) {

      iVar2 = FUN_0041a810(&local_968,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);

    }

    local_960 = awStack_8d8;

    if ((((((((-1 < iVar2) && (iVar2 = FUN_004231d0(&local_968,1,0x42), -1 < iVar2)) &&

            (iVar2 = FUN_004231d0(&local_968,2,0x802), -1 < iVar2)) &&

           ((iVar2 = FUN_004231d0(&local_968,3,1), -1 < iVar2 &&

            (iVar2 = FUN_004231d0(&local_968,4,4), -1 < iVar2)))) &&

          (iVar2 = FUN_004231d0(&local_968,5,4), -1 < iVar2)) &&

         (((iVar2 = FUN_004231d0(&local_968,6,4), -1 < iVar2 &&

           (iVar2 = FUN_004231d0(&local_968,7,4), -1 < iVar2)) &&

          ((iVar2 = FUN_004231d0(&local_968,8,4), -1 < iVar2 &&

           (((iVar2 = FUN_004231d0(&local_968,9,4), -1 < iVar2 &&

             (iVar2 = FUN_004231d0(&local_968,10,4), -1 < iVar2)) &&

            (iVar2 = FUN_004231d0(&local_968,0xb,2), -1 < iVar2)))))))) &&

        (((iVar2 = FUN_004231d0(&local_968,0xc,2), -1 < iVar2 &&

          (iVar2 = FUN_004231d0(&local_968,0xd,1), -1 < iVar2)) &&

         ((iVar2 = FUN_004231d0(&local_968,0xe,4), -1 < iVar2 &&

          (((iVar2 = FUN_004231d0(&local_968,0xf,4), -1 < iVar2 &&

            (iVar2 = FUN_004231d0(&local_968,0x10,4), -1 < iVar2)) &&

           ((iVar2 = FUN_004231d0(&local_968,0x11,2), -1 < iVar2 &&

            (((iVar2 = FUN_004231d0(&local_968,0x12,0x82), -1 < iVar2 &&

              (iVar2 = FUN_004231d0(&local_968,0x13,4), -1 < iVar2)) &&

             (iVar2 = FUN_004231d0(&local_968,0x14,4), -1 < iVar2)))))))))))) &&

       (((iVar2 = FUN_004231d0(&local_968,0x15,1), -1 < iVar2 &&

         (iVar2 = FUN_004231d0(&local_968,0x16,2), -1 < iVar2)) &&

        ((iVar2 = FUN_004231d0(&local_968,0x17,4), -1 < iVar2 &&

         (iVar2 = FUN_004231d0(&local_968,0x18,4), -1 < iVar2)))))) {

      if (local_958 != 0) {

        puStack_97c = &uStack_994;

        uStack_994 = 0;

        uStack_990 = 0;

        pwStack_98c = (wchar_t *)0x0;

        uStack_988 = 0;

        iStack_984 = 0;

        uStack_980 = 0;

        uStack_974 = 0;

        uStack_978 = 0;

        uStack_970 = 0;

        uStack_96c = 0;

        local_4 = CONCAT31(local_4._1_3_,1);

        FUN_004230d0(puStack_97c,&param_2);

        iVar2 = FUN_00422fb0(1,1,4);

        if (-1 < iVar2) {

          iVar2 = FUN_0041a810(&uStack_994,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);

        }

        pwStack_98c = awStack_8d8;

        if (((((-1 < iVar2) && (iVar2 = FUN_004231d0(&uStack_994,1,0x42), -1 < iVar2)) &&

             ((iVar2 = FUN_004231d0(&uStack_994,2,0x802), -1 < iVar2 &&

              ((((iVar2 = FUN_004231d0(&uStack_994,3,4), -1 < iVar2 &&

                 (iVar2 = FUN_004231d0(&uStack_994,4,4), -1 < iVar2)) &&

                (iVar2 = FUN_004231d0(&uStack_994,5,1), -1 < iVar2)) &&

               ((iVar2 = FUN_004231d0(&uStack_994,6,1), -1 < iVar2 &&

                (iVar2 = FUN_004231d0(&uStack_994,7,1), -1 < iVar2)))))))) &&

            ((((iVar2 = FUN_004231d0(&uStack_994,8,1), -1 < iVar2 &&

               ((iVar2 = FUN_004231d0(&uStack_994,9,4), -1 < iVar2 &&

                (iVar2 = FUN_004231d0(&uStack_994,10,4), -1 < iVar2)))) &&

              (((iVar2 = FUN_004231d0(&uStack_994,0xb,4), -1 < iVar2 &&

                (((iVar2 = FUN_004231d0(&uStack_994,0xc,4), -1 < iVar2 &&

                  (iVar2 = FUN_004231d0(&uStack_994,0xd,4), -1 < iVar2)) &&

                 (iVar2 = FUN_004231d0(&uStack_994,0xe,4), -1 < iVar2)))) &&

               ((((iVar2 = FUN_004231d0(&uStack_994,0xf,4), -1 < iVar2 &&

                  (iVar2 = FUN_004231d0(&uStack_994,0x10,4), -1 < iVar2)) &&

                 (iVar2 = FUN_004231d0(&uStack_994,0x11,4), -1 < iVar2)) &&

                ((iVar2 = FUN_004231d0(&uStack_994,0x12,4), -1 < iVar2 &&

                 (iVar2 = FUN_004231d0(&uStack_994,0x13,2), -1 < iVar2)))))))) &&

             ((((iVar2 = FUN_004231d0(&uStack_994,0x14,2), -1 < iVar2 &&

                (((iVar2 = FUN_004231d0(&uStack_994,0x15,1), -1 < iVar2 &&

                  (iVar2 = FUN_004231d0(&uStack_994,0x16,4), -1 < iVar2)) &&

                 (iVar2 = FUN_004231d0(&uStack_994,0x17,4), -1 < iVar2)))) &&

               ((iVar2 = FUN_004231d0(&uStack_994,0x18,4), -1 < iVar2 &&

                (iVar2 = FUN_004231d0(&uStack_994,0x19,2), -1 < iVar2)))) &&

              (iVar2 = FUN_004231d0(&uStack_994,0x1a,0x82), -1 < iVar2)))))) &&

           (((iVar2 = FUN_004231d0(&uStack_994,0x1b,1), -1 < iVar2 &&

             (iVar2 = FUN_004231d0(&uStack_994,0x1c,4), -1 < iVar2)) &&

            ((iVar2 = FUN_004231d0(&uStack_994,0x1d,4), -1 < iVar2 &&

             (((iVar2 = FUN_004231d0(&uStack_994,0x1e,2), -1 < iVar2 &&

               (iVar2 = FUN_004231d0(&uStack_994,0x1f,4), -1 < iVar2)) &&

              (iVar2 = FUN_004231d0(&uStack_994,0x20,4), -1 < iVar2)))))))) {

          iVar2 = (-(uint)(iStack_984 != 0) & 0x7fffbffb) + 0x80004005;

        }

        iVar3 = FUN_0041a9b0();

        if ((iVar3 == 0) || (iVar3 = FUN_0041a9b0(), iVar3 == 0)) {

          if (*(int *)(param_1 + 0x558) == 0) {

            FUN_007d9440(0);

          }

          puVar1 = param_3;

          param_3[1] = uStack_8f0;

          param_3[3] = uStack_918;

          param_3[6] = uStack_904;

          param_3[2] = uStack_8ec;

          param_3[9] = uStack_8f8;

          param_3[4] = uStack_8f4;

          *param_3 = param_2;

          param_3[0xc] = uStack_8e4;

          param_3[7] = uStack_8fc;

          param_3[5] = uStack_908;

          *(uint8_t *)((int)param_3 + 0x36) = uStack_995;

          param_3[10] = uStack_8e8;

          param_3[8] = uStack_928;

          param_3[0xb] = uStack_8e0;

          *(uint8_t *)(param_3 + 0xd) = uStack_99d;

          *(uint8_t *)((int)param_3 + 0x35) = uStack_9a5;

          *(uint8_t *)((int)param_3 + 0x37) = uStack_9a7;

          param_3[0x243] = (uint)(sStack_9a4 == -1);

          param_3[0x244] = uStack_92c;

          *(uint8_t *)((int)param_3 + 0x909) = uStack_9a8;

          param_3[0x245] = uStack_930;

          wcscpy((wchar_t *)(param_3 + 0xe),awStack_8d8);

          wcscpy((wchar_t *)((int)puVar1 + 0x7a),awStack_810);

          wcscpy((wchar_t *)(puVar1 + 0x21f),awStack_894);

          *(uint8_t *)(puVar1 + 0x242) = uStack_9a6;

          puVar1[0x249] = uStack_920;

          puVar1[0x240] = (uint)(sStack_93c == -1);

          puVar1[0x247] = uStack_910;

          puVar1[0x241] = (uint)(sStack_938 == -1);

          puVar1[0x248] = uStack_900;

          puVar1[0x24a] = uStack_91c;

          puVar1[0x246] = uStack_914;

          *(uint8_t *)((int)puVar1 + 0x909) = uStack_9a8;

          *(short *)(puVar1 + 0x24b) = sStack_934;

          puVar1[0x244] = uStack_92c;

          puVar1[0x243] = (uint)(sStack_9a4 == -1);

          puVar1[0x245] = uStack_930;

          if (sStack_934 < 1) {

            puVar1[0x24c] = 0;

          }

          else {

            pvVar4 = operator_new__(sStack_934 * 0x14);

            puVar1[0x24c] = pvVar4;

          }

          if ((puVar1[0x24c] != 0) &&

             (puVar5 = (uint32_t /* width from decompiler */ *)FUN_0041ac60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x558),param_2),

             puVar5 != (uint32_t /* width from decompiler */ *)0x0)) {

            uStack_924 = 0;

            FUN_004294f0();

            iVar3 = FUN_00423f40(&puStack_90c);

            if (iVar3 == 0) {

              iVar3 = 0;

              do {

                if (puStack_90c == (uint32_t /* width from decompiler */ *)0x0) break;

                puVar7 = (uint32_t /* width from decompiler */ *)(puVar1[0x24c] + iVar3);

                *puVar7 = *puStack_90c;

                puVar7[1] = puStack_90c[1];

                puVar7[2] = puStack_90c[2];

                iStack_8dc = iVar3 + 0x14;

                puVar7[3] = puStack_90c[3];

                puVar7[4] = puStack_90c[4];

                iVar6 = FUN_00423f40(&puStack_90c);

                iVar3 = iStack_8dc;

              } while (iVar6 == 0);

            }

            FUN_0041aed0();

            (**(code **)*puVar5)(1);

          }

        }

        if (local_958 != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        if (iStack_984 != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        local_4 = local_4 & 0xffffff00;

        FUN_0041a3e0(&uStack_994);

        local_4 = 0xffffffff;

        FUN_0041a3e0(&local_968);

        ExceptionList = local_c;

        return iVar2;

      }

      iVar2 = -0x7fffbffb;

    }

    FUN_00423170();

    FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcFetch2::Open");

    local_4 = 0xffffffff;

    FUN_0041a3e0(&local_968);

  }

  ExceptionList = local_c;

  return 0;

}
