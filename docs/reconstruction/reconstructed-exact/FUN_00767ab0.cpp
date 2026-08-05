// =============================================================================
// FUN_00767ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00767ab0
// Address:   0x00767ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00767ab0 @ 0x00767ab0
// Stable ID: aa_00767ab0
// Embedded strings (evidence for future rename):
//   - "%I64u"
//   - "%#.16g"
//   - "%+#.8g"
//   - "%I64i"
//   - "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"
//   - "Unhandled block data type"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×16, goto×6, return×4, while×3, do×1.
//  - Notable callees: FUN_00767160×5, CONCAT44×3, CONCAT14, FUN_00767ab0, vog_LogMessage.
//  - Strings: "%I64u"; "%#.16g"; "%+#.8g"; "%I64i".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00767ab0(int *param_1,int param_2)



{

  int iVar1;

  float *in_EAX;

  uint uVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  char *pcVar4;

  ulonglong uVar5;

  uint64_t uVar6;

  

  if (unaff_ESI[7] == 0) {

    iVar1 = *param_1;

    while (iVar1 != 0) {

      param_1 = param_1 + 1;

      iVar1 = *param_1;

    }

    uVar2 = (**(code **)(*(int *)*unaff_ESI + 0x18))();

    unaff_ESI[1] = unaff_ESI[1] | uVar2;

    return unaff_ESI[1];

  }

  if (unaff_ESI[7] != 1) {

    return 0xffffffff;

  }

  do {

    if (param_2 == 0) {

      return unaff_ESI[1];

    }

    param_2 = param_2 + -1;

    iVar1 = *param_1;

    piVar3 = param_1;

    while (iVar1 != 0) {

      iVar1 = *piVar3;

      if (iVar1 < 0x609) {

        if (iVar1 == 0x608) {

          uVar6 = *(uint64_t *)in_EAX;

          pcVar4 = "%I64u";

          goto LAB_00767b9c;

        }

        if (iVar1 < 0x303) {

          if (iVar1 != 0x302) {

            if (iVar1 == 0x101) {

              uVar5 = (ulonglong)CONCAT14(*(uint8_t *)in_EAX,&DAT_00a9d718);

              goto LAB_00767c15;

            }

            if (iVar1 != 0x202) goto LAB_00767c5c;

          }

          uVar2 = FUN_00767160();

          unaff_ESI[1] = unaff_ESI[1] | uVar2;

          in_EAX = (float *)((int)in_EAX + 2);

        }

        else {

          if (iVar1 == 0x404) {

            uVar6 = CONCAT44(*in_EAX,&DAT_00a9d718);

          }

          else {

            if (iVar1 != 0x504) goto LAB_00767c5c;

            uVar6 = CONCAT44(*in_EAX,&DAT_00a37c64);

          }

          uVar2 = FUN_00767160(uVar6);

          unaff_ESI[1] = unaff_ESI[1] | uVar2;

          in_EAX = in_EAX + 1;

        }

      }

      else if (iVar1 < 0x909) {

        if (iVar1 == 0x908) {

          uVar6 = *(uint64_t *)in_EAX;

          pcVar4 = "%#.16g";

        }

        else {

          if (iVar1 != 0x708) {

            if (iVar1 != 0x804) goto LAB_00767c5c;

            uVar2 = FUN_00767160("%+#.8g",(double)*in_EAX);

            unaff_ESI[1] = unaff_ESI[1] | uVar2;

            in_EAX = in_EAX + 1;

            goto LAB_00767c25;

          }

          uVar6 = *(uint64_t *)in_EAX;

          pcVar4 = "%I64i";

        }

LAB_00767b9c:

        uVar2 = FUN_00767160(pcVar4,uVar6);

        unaff_ESI[1] = unaff_ESI[1] | uVar2;

        in_EAX = in_EAX + 2;

      }

      else {

        if (iVar1 != 0xa01) {

LAB_00767c5c:

          vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x114,3,

                         "Unhandled block data type");

          return 0xffffffff;

        }

        uVar5 = CONCAT44((int)*(char *)in_EAX,&DAT_00a37c64);

LAB_00767c15:

        uVar2 = FUN_00767160(uVar5);

        unaff_ESI[1] = unaff_ESI[1] | uVar2;

        in_EAX = (float *)((int)in_EAX + 1);

      }

LAB_00767c25:

      piVar3 = piVar3 + 1;

      iVar1 = *piVar3;

    }

    unaff_ESI[8] = 0;

    uVar2 = (**(code **)(*(int *)*unaff_ESI + 0x18))();

    unaff_ESI[1] = unaff_ESI[1] | uVar2;

  } while( true );

}
