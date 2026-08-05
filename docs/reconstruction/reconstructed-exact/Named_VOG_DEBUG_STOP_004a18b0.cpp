// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, for×1.
//  - Notable callees: FUN_00799300×11, FUN_007994c0×10, FUN_00403450×3, FUN_00798bb0×3, free×3, FUN_004a1770×2, FUN_004a18b0, FUN_007a4480.
//  - Strings: "hemiTopColor"; "hemiBottomColor"; "directionalDifuse"; "directionalSpecular".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_004a18b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a18b0
// Address:   0x004a18b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_004a18b0(int param_1,int *param_2)



{

  char cVar1;

  char cVar2;

  char cVar3;

  char cVar4;

  char cVar5;

  char cVar6;

  char cVar7;

  char cVar8;

  char cVar9;

  char cVar10;

  char cVar11;

  char cVar12;

  char cVar13;

  char cVar14;

  char cVar15;

  char cVar16;

  char cVar17;

  char cVar18;

  char cVar19;

  char cVar20;

  char cVar21;

  char cVar22;

  char cVar23;

  uint16_t uVar24;

  uint32_t /* width from decompiler */ uVar25;

  int iVar26;

  uint32_t /* width from decompiler */ *puVar27;

  int *local_330;

  char cStack_329;

  char *pcStack_328;

  char acStack_324 [128];

  uint8_t *puStack_2a4;

  uint8_t auStack_2a0 [128];

  uint uStack_220;

  uint32_t /* width from decompiler */ auStack_21c [129];

  void *pvStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a1067;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  if (param_2 != (int *)0x0) {

    ExceptionList = &pvStack_14;

    uStack_220 = (**(code **)(*param_2 + 0x44))(param_2,&local_330);

    if ((uStack_220 == 0) && (local_330 != (int *)0x0)) {

      puVar27 = auStack_21c;

      for (iVar26 = 0x81; iVar26 != 0; iVar26 = iVar26 + -1) {

        *puVar27 = 0;

        puVar27 = puVar27 + 1;

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c8) = DAT_00aaa8a8;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1cc) = DAT_00a0f298;

      cVar1 = FUN_007994c0(local_330,L"hemiTopColor",param_1 + 0x13c,0,0,0);

      cVar2 = FUN_007994c0(local_330,L"hemiBottomColor",param_1 + 0x148,0,0,0);

      cVar3 = FUN_007994c0(local_330,L"directionalDifuse",param_1 + 0x154,0,0,0);

      cVar4 = FUN_007994c0(local_330,L"directionalSpecular",param_1 + 0x160,0,0,0);

      cVar5 = FUN_007994c0(local_330,L"directionalAmbient",param_1 + 0x16c,0,0,0);

      cVar6 = FUN_007994c0(local_330,L"directionalDirection",param_1 + 0x178,0,0,0);

      cVar7 = FUN_00799300(local_330,L"fogDensity",param_1 + 0x1bc);

      cVar8 = FUN_00799300(local_330,L"fogStart",param_1 + 0x1c0);

      cVar9 = FUN_00799300(local_330,L"fogEnd",param_1 + 0x1c4);

      cVar10 = FUN_007994c0(local_330,L"fogColor",param_1 + 0x184,0,0,0);

      cVar11 = FUN_00799300(local_330,L"farPlaneDistance",param_1 + 0x1c8);

      cVar12 = FUN_007994c0(local_330,L"shadowColor",param_1 + 400,0,0,0);

      cVar13 = FUN_00799300(local_330,L"shadowAlpha",param_1 + 0x1b4);

      cVar14 = FUN_00799300(local_330,L"windVariation",param_1 + 0x1b8);

      cVar15 = FUN_00799300(local_330,L"fadePercent",param_1 + 0x1cc);

      cVar16 = FUN_00799300(local_330,L"fadeDistance",param_1 + 0x1d0);

      cVar17 = FUN_00798bb0(local_330,L"bgMusic",&uStack_220);

      pcStack_328 = acStack_324;

      uVar25 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(&uStack_220,uVar25);

      strncpy((char *)(param_1 + 0x1ea),pcStack_328,0x103);

      if (pcStack_328 != acStack_324) {

        free(pcStack_328);

      }

      cVar18 = FUN_00798bb0(local_330,L"cloudName",&uStack_220);

      if ((short)uStack_220 != 0) {

        pcStack_328 = acStack_324;

        uVar25 = (*(code *)PTR_FUN_00af8c9c)();

        FUN_00403450(&uStack_220,uVar25);

        uStack_c = 0;

        uVar24 = FUN_004a1770(pcStack_328);

        *(uint16_t *)(param_1 + 0x1dc) = uVar24;

        uStack_c = 0xffffffff;

        if (pcStack_328 != acStack_324) {

          free(pcStack_328);

        }

      }

      uStack_220 = uStack_220 & 0xffff0000;

      cVar19 = FUN_00798bb0(local_330,L"skyName",&uStack_220);

      if ((short)uStack_220 != 0) {

        puStack_2a4 = auStack_2a0;

        uVar25 = (*(code *)PTR_FUN_00af8c9c)();

        FUN_00403450(&uStack_220,uVar25);

        uStack_c = 1;

        uVar24 = FUN_004a1770(puStack_2a4);

        *(uint16_t *)(param_1 + 0x1de) = uVar24;

        uStack_c = 0xffffffff;

        if (puStack_2a4 != auStack_2a0) {

          free(puStack_2a4);

        }

      }

      cVar20 = FUN_007994c0(local_330,L"skyTint1",param_1 + 0x19c,0,0,0);

      cVar21 = FUN_007994c0(local_330,L"skyTint2",param_1 + 0x1a8,0,0,0);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e0) = DAT_00aaa6f8;

      cVar22 = FUN_00799300(local_330,L"cloudAlpha",(uint32_t /* width from decompiler */ *)(param_1 + 0x1e0));

      cStack_329 = FUN_00799300(local_330,L"cameraShakeAmplitude",param_1 + 0x1d4);

      cVar23 = FUN_00799300(local_330,L"cameraShakeFrequency",param_1 + 0x1d8);

      if (((((((((((((((((((((cVar1 != '\0' || cVar2 != '\0') || cVar3 != '\0') || cVar4 != '\0') ||

                          cVar5 != '\0') || cVar6 != '\0') || cVar7 != '\0') || cVar8 != '\0') ||

                      cVar9 != '\0') || cVar10 != '\0') || cVar11 != '\0') || cVar12 != '\0') ||

                  cVar13 != '\0') || cVar14 != '\0') || cVar15 != '\0') || cVar16 != '\0') ||

              cVar17 != '\0') || cVar18 != '\0') || cVar19 != '\0') || cVar20 != '\0') ||

          cVar21 != '\0') || cVar22 != '\0') {

        *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | 1;

      }

      if (cStack_329 != '\0' || cVar23 != '\0') {

        *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | 2;

      }

      (**(code **)(*local_330 + 8))(local_330);

      ExceptionList = pvStack_18;

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  ExceptionList = pvStack_14;

  return 0;

}
