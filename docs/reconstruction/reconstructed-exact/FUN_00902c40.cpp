// =============================================================================
// FUN_00902c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00902c40
// Address:   0x00902c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00902c40 @ 0x00902c40
// Stable ID: aa_00902c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~1126 non-empty decompiler lines.
//  - Control keywords: if×138, goto×69, while×11, return×8, do×6, switch×6, for×6.
//  - Notable callees: FUN_005a6f20×24, FUN_0040da70×20, SBORROW2×9, strncpy×6, FUN_00906dd0×5, FUN_00902560×4, FUN_004049e0×2, FUN_00569dc0×2.
//  - Return sites: 8.

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



void __fastcall FUN_00902c40(int param_1)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  short sVar5;

  short sVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  uint uVar11;

  char *pcVar12;

  char *_Str2;

  int iVar13;

  short *psVar14;

  short *psVar15;

  int *piVar16;

  uint uVar17;

  int extraout_ECX;

  int *piVar18;

  uint32_t /* width from decompiler */ *puVar19;

  bool bVar20;

  bool bVar21;

  float10 fVar22;

  float10 fVar23;

  float fVar24;

  float fVar25;

  uint64_t uVar26;

  size_t sVar27;

  uint32_t /* width from decompiler */ uVar28;

  float fStack_644;

  float fStack_638;

  float fStack_634;

  float fStack_628;

  int iStack_624;

  int iStack_61c;

  int iStack_618;

  char acStack_608 [2];

  uint32_t /* width from decompiler */ auStack_606 [63];

  char acStack_508 [2];

  uint32_t /* width from decompiler */ auStack_506 [63];

  char acStack_408 [2];

  uint32_t /* width from decompiler */ auStack_406 [63];

  char acStack_308 [2];

  uint32_t /* width from decompiler */ auStack_306 [63];

  char acStack_208 [2];

  uint32_t /* width from decompiler */ auStack_206 [63];

  char acStack_108 [2];

  uint32_t /* width from decompiler */ auStack_106 [64];

  

  iVar3 = DAT_00d1ad2c;

  iVar7 = *(int *)(param_1 + 0x50c);

  piVar18 = (int *)(param_1 + 0x50c);

  if ((iVar7 == 0) || (*(int *)(iVar7 + 0x7fc) == 0)) {

    return;

  }

  iVar7 = (**(code **)(**(int **)(iVar7 + 0x7fc) + 0x464))();

  iStack_618 = 0;

  piVar16 = (int *)(*piVar18 + 0x798);

  do {

    if (iVar7 == *piVar16) {

      if (iStack_618 < 9) goto LAB_00902cc7;

      goto LAB_0090337b;

    }

    iStack_618 = iStack_618 + 1;

    piVar16 = piVar16 + 1;

  } while (iStack_618 < 0x11);

  iStack_618 = -1;

LAB_00902cc7:

  iVar7 = 0;

LAB_00902cc9:

  if (*(int *)(iVar3 + 0x18) == 0) {

    iVar8 = 0;

  }

  else {

    iVar8 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2;

  }

  fStack_638 = (float)iVar7;

  if (iVar7 < iVar8) {

LAB_00902cf0:

    iVar8 = *(int *)(iVar3 + 0x18);

    if (iVar8 == 0) {

      iVar9 = 0;

    }

    else {

      iVar9 = *(int *)(iVar3 + 0x1c) - iVar8 >> 2;

    }

    if (iVar9 <= (int)fStack_638) goto LAB_0090336f;

    iVar9 = iVar7 * 4;

    if ((((*(uint *)(*(int *)(iVar9 + iVar8) + 0x1f0) & *(uint *)(*(int *)(iVar9 + iVar8) + 500)) ==

          0xffffffff) ||

        (iVar2 = (int)fStack_638 * 4, iVar8 = *(int *)(iVar2 + *(int *)(iVar3 + 0x18)),

        (*(uint *)(iVar8 + 0x1f0) & *(uint *)(iVar8 + 500)) == 0xffffffff)) || (DAT_00d1b644 == 0))

    goto switchD_00902dd4_default;

    iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

    piVar16 = (int *)CVOGReaction_ResolveObjectTarget

                               (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),*(uint32_t /* width from decompiler */ *)(iVar8 + 500));

    iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

    piVar10 = (int *)CVOGReaction_ResolveObjectTarget

                               (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),*(uint32_t /* width from decompiler */ *)(iVar8 + 500));

    if ((piVar16 == (int *)0x0) || (piVar10 == (int *)0x0)) goto switchD_00902dd4_default;

    switch(iStack_618) {

    case 1:

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      if (cVar4 != '\x01') {

        sVar5 = *(short *)(*(int *)(piVar16[0x2a] + 0x3c) + 0x4b8);

        sVar6 = *(short *)(*(int *)(piVar10[0x2a] + 0x3c) + 0x4b8);

        bVar21 = SBORROW2(sVar5,sVar6);

        bVar20 = (short)(sVar5 - sVar6) < 0;

        goto LAB_0090333f;

      }

      if (*(short *)(*(int *)(piVar10[0x2a] + 0x3c) + 0x4b8) <

          *(short *)(*(int *)(piVar16[0x2a] + 0x3c) + 0x4b8)) goto LAB_00903345;

      break;

    case 2:

      acStack_608[0] = '\0';

      acStack_608[1] = '\0';

      puVar19 = auStack_606;

      for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar19 = 0;

        puVar19 = puVar19 + 1;

      }

      *(uint16_t *)puVar19 = 0;

      acStack_408[0] = '\0';

      acStack_408[1] = '\0';

      puVar19 = auStack_406;

      for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar19 = 0;

        puVar19 = puVar19 + 1;

      }

      *(uint16_t *)puVar19 = 0;

      sVar27 = 0xff;

      pcVar12 = (char *)(**(code **)(*piVar16 + 0x15c))();

      strncpy(acStack_608,pcVar12,sVar27);

      sVar27 = 0xff;

      pcVar12 = (char *)(**(code **)(*piVar10 + 0x15c))();

      strncpy(acStack_408,pcVar12,sVar27);

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      if (cVar4 != '\x01') {

        _Str2 = acStack_408;

        pcVar12 = acStack_608;

        goto LAB_00903117;

      }

      _Str2 = acStack_408;

      pcVar12 = acStack_608;

      goto LAB_0090328c;

    case 3:

      iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

      if (*(int *)(iVar8 + 0x1e8) == 0 && *(int *)(iVar8 + 0x1ec) == 0) {

        iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

        uVar17 = *(uint *)(iVar8 + 0x230);

        iVar8 = *(int *)(iVar8 + 0x234);

      }

      else {

        iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

        uVar17 = *(uint *)(iVar8 + 0x1e8);

        iVar8 = *(int *)(iVar8 + 0x1ec);

      }

      iVar13 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

      if (*(int *)(iVar13 + 0x1e8) == 0 && *(int *)(iVar13 + 0x1ec) == 0) {

        iVar13 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

        uVar11 = *(uint *)(iVar13 + 0x230);

        iVar13 = *(int *)(iVar13 + 0x234);

      }

      else {

        iVar13 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

        uVar11 = *(uint *)(iVar13 + 0x1e8);

        iVar13 = *(int *)(iVar13 + 0x1ec);

      }

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      if (cVar4 != '\x01') {

        if ((iVar13 < iVar8) || ((iVar13 <= iVar8 && (uVar11 <= uVar17)))) break;

        goto LAB_00903345;

      }

      if ((iVar13 <= iVar8) && ((iVar13 < iVar8 || (uVar11 < uVar17)))) goto LAB_00903345;

      break;

    case 4:

      iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

      if (*(int *)(iVar8 + 0x238) == 0 && *(int *)(iVar8 + 0x23c) == 0) {

        fStack_628 = 0.0;

        iStack_624 = 0;

      }

      else {

        iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

        fStack_628 = *(float *)(iVar8 + 0x238);

        iStack_624 = *(int *)(iVar8 + 0x23c);

      }

      uVar17 = 0;

      iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

      if (*(int *)(iVar8 + 0x238) == 0 && *(int *)(iVar8 + 0x23c) == 0) {

        iStack_61c = 0;

      }

      else {

        iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

        uVar17 = *(uint *)(iVar8 + 0x238);

        iStack_61c = *(int *)(iVar8 + 0x23c);

      }

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      if (cVar4 == '\x01') {

        if ((iStack_61c <= iStack_624) && ((iStack_61c < iStack_624 || (uVar17 < (uint)fStack_628)))

           ) goto LAB_00903345;

      }

      else if ((iStack_624 <= iStack_61c) &&

              ((iStack_624 < iStack_61c || ((uint)fStack_628 < uVar17)))) goto LAB_00903345;

      break;

    case 5:

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      if (cVar4 == '\x01') {

        iVar13 = *(int *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar9) + 0x21c);

        iVar8 = *(int *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar2) + 0x21c);

        bVar21 = SBORROW4(iVar13,iVar8);

        bVar20 = iVar13 - iVar8 < 0;

      }

      else {

        iVar13 = *(int *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar9) + 0x21c);

        iVar8 = *(int *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar2) + 0x21c);

        bVar21 = SBORROW4(iVar13,iVar8);

        bVar20 = iVar13 - iVar8 < 0;

      }

LAB_0090333f:

      if (bVar21 != bVar20) {

LAB_00903345:

        uVar28 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar9);

        *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar9) =

             *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2);

        *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2) = uVar28;

        fStack_638 = (float)((int)fStack_638 + 1);

        goto LAB_00902cf0;

      }

      break;

    case 6:

      acStack_108[0] = '\0';

      acStack_108[1] = '\0';

      puVar19 = auStack_106;

      for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar19 = 0;

        puVar19 = puVar19 + 1;

      }

      *(uint16_t *)puVar19 = 0;

      acStack_308[0] = '\0';

      acStack_308[1] = '\0';

      puVar19 = auStack_306;

      for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar19 = 0;

        puVar19 = puVar19 + 1;

      }

      *(uint16_t *)puVar19 = 0;

      strncpy(acStack_108,(char *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar9) + 0x1c2),0xff);

      strncpy(acStack_308,(char *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar2) + 0x1c2),0xff);

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      pcVar12 = acStack_108;

      _Str2 = acStack_308;

      goto LAB_00903284;

    case 7:

      acStack_508[0] = '\0';

      acStack_508[1] = '\0';

      puVar19 = auStack_506;

      for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar19 = 0;

        puVar19 = puVar19 + 1;

      }

      *(uint16_t *)puVar19 = 0;

      acStack_208[0] = '\0';

      acStack_208[1] = '\0';

      puVar19 = auStack_206;

      for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar19 = 0;

        puVar19 = puVar19 + 1;

      }

      *(uint16_t *)puVar19 = 0;

      strncpy(acStack_508,(char *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar9) + 0x1d3),0xff);

      strncpy(acStack_208,(char *)(*(int *)(*(int *)(iVar3 + 0x18) + iVar2) + 0x1d3),0xff);

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      pcVar12 = acStack_508;

      _Str2 = acStack_208;

LAB_00903284:

      if (cVar4 != '\x01') {

LAB_00903117:

        iVar8 = _stricmp(pcVar12,_Str2);

        if (0 < iVar8) goto LAB_0090329d;

        break;

      }

LAB_0090328c:

      iVar8 = _stricmp(pcVar12,_Str2);

      if (-1 < iVar8) break;

LAB_0090329d:

      uVar28 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar9);

      *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar9) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2);

      *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2) = uVar28;

      fStack_638 = (float)((int)fStack_638 + 1);

      goto LAB_00902cf0;

    case 8:

      cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

      if (cVar4 != '\x01') {

        sVar5 = *(short *)(*(int *)(piVar16[0x2a] + 0x3c) + 0x4b4);

        sVar6 = *(short *)(*(int *)(piVar10[0x2a] + 0x3c) + 0x4b4);

        bVar21 = SBORROW2(sVar5,sVar6);

        bVar20 = (short)(sVar5 - sVar6) < 0;

        goto LAB_0090333f;

      }

      if (*(short *)(*(int *)(piVar10[0x2a] + 0x3c) + 0x4b4) <

          *(short *)(*(int *)(piVar16[0x2a] + 0x3c) + 0x4b4)) goto LAB_00903345;

    }

switchD_00902dd4_default:

    fStack_638 = (float)((int)fStack_638 + 1);

    goto LAB_00902cf0;

  }

LAB_0090337b:

  if (((((iStack_618 != 9) && (iStack_618 != 10)) && (iStack_618 != 0xb)) && (iStack_618 != 0xc)) ||

     (cVar4 = FUN_00906dd0(), cVar4 != '\f')) {

    if ((((iStack_618 != 9) && (iStack_618 != 10)) &&

        ((iStack_618 != 0xb && ((iStack_618 != 0xc && (iStack_618 != 0xd)))))) ||

       (cVar4 = FUN_00906dd0(), cVar4 != '\x0e')) {

      if ((((((iStack_618 != 9) && (iStack_618 != 10)) && (iStack_618 != 0xb)) &&

           ((iStack_618 != 0xc && (iStack_618 != 0xd)))) &&

          ((iStack_618 != 0xe && ((iStack_618 != 0xf && (iStack_618 != 0x10)))))) ||

         (cVar4 = FUN_00906dd0(), cVar4 != '\x1c')) {

        if (((((iStack_618 != 10) && (iStack_618 != 0xb)) && (iStack_618 != 0xc)) &&

            (((iStack_618 != 9 && (iStack_618 != 0xe)) && (iStack_618 != 0xd)))) ||

           (cVar4 = FUN_00906dd0(), cVar4 != '\x10')) {

          if (((iStack_618 != 9) && (iStack_618 != 10)) &&

             ((iStack_618 != 0xb && (iStack_618 != 0xc)))) {

            return;

          }

          cVar4 = FUN_00906dd0();

          if (cVar4 != '\n') {

            return;

          }

          iVar7 = 0;

          do {

            if (*(int *)(iVar3 + 0x18) == 0) {

              iVar8 = 0;

            }

            else {

              iVar8 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2;

            }

            fStack_638 = (float)iVar7;

            if (iVar8 <= iVar7) {

              return;

            }

            while( true ) {

              iVar8 = *(int *)(iVar3 + 0x18);

              if (iVar8 == 0) {

                iVar9 = 0;

              }

              else {

                iVar9 = *(int *)(iVar3 + 0x1c) - iVar8 >> 2;

              }

              if (iVar9 <= (int)fStack_638) break;

              iVar9 = iVar7 * 4;

              if (((*(uint *)(*(int *)(iVar9 + iVar8) + 0x1f0) &

                   *(uint *)(*(int *)(iVar9 + iVar8) + 500)) != 0xffffffff) && (DAT_00d1b644 != 0))

              {

                iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

                piVar16 = (int *)CVOGReaction_ResolveObjectTarget

                                           (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),

                                            *(uint32_t /* width from decompiler */ *)(iVar8 + 500));

                iVar2 = (int)fStack_638 * 4;

                iVar8 = *(int *)(iVar2 + *(int *)(iVar3 + 0x18));

                piVar10 = (int *)CVOGReaction_ResolveObjectTarget

                                           (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),

                                            *(uint32_t /* width from decompiler */ *)(iVar8 + 500));

                if ((piVar16 != (int *)0x0) &&

                   (((iVar8 = (**(code **)(*piVar16 + 500))(), iVar8 != 0 && (piVar10 != (int *)0x0)

                     ) && (iVar8 = (**(code **)(*piVar10 + 500))(), iVar8 != 0)))) {

                  switch(iStack_618) {

                  case 9:

                    cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                    if (cVar4 == '\x01') {

                      iVar8 = (**(code **)(*piVar16 + 500))();

                      iVar8 = *(int *)(iVar8 + 0xb4);

                      iVar13 = (**(code **)(*piVar10 + 500))();

                      if (iVar8 <= *(int *)(iVar13 + 0xb4)) break;

LAB_00904a92:

                      iVar8 = *(int *)(iVar3 + 0x18);

                      uVar28 = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9);

                      *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9) = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar2);

                      *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2) = uVar28;

                    }

                    else {

                      iVar8 = (**(code **)(*piVar16 + 500))();

                      iVar8 = *(int *)(iVar8 + 0xb4);

                      iVar13 = (**(code **)(*piVar10 + 500))();

                      if (iVar8 < *(int *)(iVar13 + 0xb4)) goto LAB_00904a92;

                    }

                    break;

                  case 10:

                    iVar8 = (**(code **)(*piVar16 + 500))();

                    fVar24 = (float)(int)*(short *)(iVar8 + 0xb8) * _DAT_00aaa958;

                    iVar8 = (**(code **)(*piVar10 + 500))();

                    fVar25 = (float)(int)*(short *)(iVar8 + 0xb8) * _DAT_00aaa958;

                    cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                    if (cVar4 == '\x01') {

                      bVar20 = fVar24 == fVar25;

                      bVar21 = fVar24 < fVar25;

                      goto LAB_00904a90;

                    }

                    iVar8 = (**(code **)(*piVar16 + 500))();

                    sVar5 = *(short *)(iVar8 + 0xb8);

                    iVar8 = (**(code **)(*piVar10 + 500))();

                    if (sVar5 < *(short *)(iVar8 + 0xb8)) goto LAB_00904a92;

                    break;

                  case 0xb:

                    cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                    if (cVar4 == '\x01') {

                      iVar8 = (**(code **)(*piVar16 + 500))();

                      iVar8 = *(int *)(iVar8 + 0xb0);

                      iVar13 = (**(code **)(*piVar10 + 500))();

                      if (*(int *)(iVar13 + 0xb0) < iVar8) goto LAB_00904a92;

                    }

                    else {

                      iVar8 = (**(code **)(*piVar16 + 500))();

                      iVar8 = *(int *)(iVar8 + 0xb0);

                      iVar13 = (**(code **)(*piVar10 + 500))();

                      if (iVar8 < *(int *)(iVar13 + 0xb0)) goto LAB_00904a92;

                    }

                    break;

                  case 0xc:

                    iVar8 = (**(code **)(*piVar16 + 500))();

                    fVar24 = (float)(int)*(short *)(iVar8 + 0xba) * _DAT_00aaa958;

                    iVar8 = (**(code **)(*piVar10 + 500))();

                    fVar25 = (float)(int)*(short *)(iVar8 + 0xba) * _DAT_00aaa958;

                    cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                    if (cVar4 == '\x01') {

                      bVar20 = fVar24 == fVar25;

                      bVar21 = fVar24 < fVar25;

                    }

                    else {

                      bVar20 = fVar25 == fVar24;

                      bVar21 = fVar25 < fVar24;

                    }

LAB_00904a90:

                    if (!bVar21 && !bVar20) goto LAB_00904a92;

                  }

                }

              }

              fStack_638 = (float)((int)fStack_638 + 1);

            }

            iVar7 = iVar7 + 1;

          } while( true );

        }

        iVar7 = 0;

        do {

          if (*(int *)(iVar3 + 0x18) == 0) {

            iVar8 = 0;

          }

          else {

            iVar8 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2;

          }

          fStack_638 = (float)iVar7;

          if (iVar8 <= iVar7) {

            return;

          }

          while( true ) {

            iVar8 = *(int *)(iVar3 + 0x18);

            if (iVar8 == 0) {

              iVar9 = 0;

            }

            else {

              iVar9 = *(int *)(iVar3 + 0x1c) - iVar8 >> 2;

            }

            if (iVar9 <= (int)fStack_638) break;

            iVar9 = iVar7 * 4;

            if (((*(uint *)(*(int *)(iVar9 + iVar8) + 0x1f0) &

                 *(uint *)(*(int *)(iVar9 + iVar8) + 500)) != 0xffffffff) && (DAT_00d1b644 != 0)) {

              iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

              piVar16 = (int *)CVOGReaction_ResolveObjectTarget

                                         (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),

                                          *(uint32_t /* width from decompiler */ *)(iVar8 + 500));

              iVar2 = (int)fStack_638 * 4;

              iVar8 = *(int *)(iVar2 + *(int *)(iVar3 + 0x18));

              piVar10 = (int *)CVOGReaction_ResolveObjectTarget

                                         (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),

                                          *(uint32_t /* width from decompiler */ *)(iVar8 + 500));

              if (((piVar16 != (int *)0x0) &&

                  ((iVar8 = (**(code **)(*piVar16 + 0x1f0))(), iVar8 != 0 && (piVar10 != (int *)0x0)

                   ))) && (iVar8 = (**(code **)(*piVar10 + 0x1f0))(), iVar8 != 0)) {

                switch(iStack_618) {

                case 9:

                  cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                  uVar28 = 3;

                  if (cVar4 == '\x01') {

                    (**(code **)(*piVar16 + 0x1f0))();

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 3;

                    (**(code **)(*piVar10 + 0x1f0))(3);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    fVar23 = (float10)(float)fVar23;

                  }

                  else {

                    (**(code **)(*piVar16 + 0x1f0))(3);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 3;

                    (**(code **)(*piVar10 + 0x1f0))(3);

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    fVar22 = (float10)(float)fVar22;

                  }

                  break;

                case 10:

                  cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                  uVar28 = 4;

                  if (cVar4 == '\x01') {

                    (**(code **)(*piVar16 + 0x1f0))();

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 4;

                    (**(code **)(*piVar10 + 0x1f0))(4);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    fVar23 = (float10)(float)fVar23;

                  }

                  else {

                    (**(code **)(*piVar16 + 0x1f0))(4);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 4;

                    (**(code **)(*piVar10 + 0x1f0))(4);

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    fVar22 = (float10)(float)fVar22;

                  }

                  break;

                case 0xb:

                  cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                  uVar28 = 0;

                  if (cVar4 == '\x01') {

                    (**(code **)(*piVar16 + 0x1f0))();

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 0;

                    (**(code **)(*piVar10 + 0x1f0))(0);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    fVar23 = (float10)(float)fVar23;

                  }

                  else {

                    (**(code **)(*piVar16 + 0x1f0))(0);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 0;

                    (**(code **)(*piVar10 + 0x1f0))(0);

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    fVar22 = (float10)(float)fVar22;

                  }

                  break;

                case 0xc:

                  cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                  uVar28 = 2;

                  if (cVar4 == '\x01') {

                    (**(code **)(*piVar16 + 0x1f0))();

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 2;

                    (**(code **)(*piVar10 + 0x1f0))(2);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    fVar23 = (float10)(float)fVar23;

                  }

                  else {

                    (**(code **)(*piVar16 + 0x1f0))(2);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 2;

                    (**(code **)(*piVar10 + 0x1f0))(2);

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    fVar22 = (float10)(float)fVar22;

                  }

                  break;

                case 0xd:

                  cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                  uVar28 = 1;

                  if (cVar4 == '\x01') {

                    (**(code **)(*piVar16 + 0x1f0))();

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 1;

                    (**(code **)(*piVar10 + 0x1f0))(1);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    fVar23 = (float10)(float)fVar23;

                  }

                  else {

                    (**(code **)(*piVar16 + 0x1f0))(1);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 1;

                    (**(code **)(*piVar10 + 0x1f0))(1);

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    fVar22 = (float10)(float)fVar22;

                  }

                  break;

                case 0xe:

                  cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                  uVar28 = 5;

                  if (cVar4 == '\x01') {

                    (**(code **)(*piVar16 + 0x1f0))();

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 5;

                    (**(code **)(*piVar10 + 0x1f0))(5);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    fVar23 = (float10)(float)fVar23;

                  }

                  else {

                    (**(code **)(*piVar16 + 0x1f0))(5);

                    fVar22 = (float10)FUN_005a6f20(uVar28);

                    uVar28 = 5;

                    (**(code **)(*piVar10 + 0x1f0))(5);

                    fVar23 = (float10)FUN_005a6f20(uVar28);

                    fVar22 = (float10)(float)fVar22;

                  }

                  break;

                default:

                  goto switchD_009043e5_default;

                }

                if (fVar22 < fVar23) {

                  iVar8 = *(int *)(iVar3 + 0x18);

                  uVar28 = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9);

                  *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9) = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar2);

                  *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2) = uVar28;

                }

              }

            }

switchD_009043e5_default:

            fStack_638 = (float)((int)fStack_638 + 1);

          }

          iVar7 = iVar7 + 1;

        } while( true );

      }

      iVar7 = 0;

      do {

        if (*(int *)(iVar3 + 0x18) == 0) {

          iVar8 = 0;

        }

        else {

          iVar8 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2;

        }

        fStack_644 = (float)iVar7;

        if (iVar8 <= iVar7) {

          return;

        }

        while( true ) {

          iVar8 = *(int *)(iVar3 + 0x18);

          if (iVar8 == 0) {

            iVar9 = 0;

          }

          else {

            iVar9 = *(int *)(iVar3 + 0x1c) - iVar8 >> 2;

          }

          if (iVar9 <= (int)fStack_644) break;

          iVar9 = *(int *)(iVar8 + iVar7 * 4);

          iVar8 = iVar7 * 4;

          if (((*(uint *)(iVar9 + 0x1f0) & *(uint *)(iVar9 + 500)) != 0xffffffff) &&

             (DAT_00d1b644 != 0)) {

            iVar9 = *(int *)(*(int *)(iVar3 + 0x18) + iVar8);

            piVar16 = (int *)CVOGReaction_ResolveObjectTarget

                                       (1,*(uint32_t /* width from decompiler */ *)(iVar9 + 0x1f0),

                                        *(uint32_t /* width from decompiler */ *)(iVar9 + 500));

            iVar2 = (int)fStack_644 * 4;

            iVar9 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

            piVar10 = (int *)CVOGReaction_ResolveObjectTarget

                                       (1,*(uint32_t /* width from decompiler */ *)(iVar9 + 0x1f0),

                                        *(uint32_t /* width from decompiler */ *)(iVar9 + 500));

            if ((piVar16 != (int *)0x0) &&

               (((iVar9 = (**(code **)(*piVar16 + 0x1f8))(), iVar9 != 0 && (piVar10 != (int *)0x0))

                && (iVar9 = (**(code **)(*piVar10 + 0x1f8))(), iVar9 != 0)))) {

              switch(iStack_618) {

              case 9:

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 == '\x01') {

                  iVar9 = (**(code **)(*piVar16 + 0x1f8))();

                  sVar5 = *(short *)(iVar9 + 0xcc);

                  iVar9 = (**(code **)(*piVar10 + 0x1f8))();

                  if (*(short *)(iVar9 + 0xcc) < sVar5) goto LAB_0090425c;

                }

                else {

                  iVar9 = (**(code **)(*piVar16 + 0x1f8))();

                  sVar5 = *(short *)(iVar9 + 0xcc);

                  iVar9 = (**(code **)(*piVar10 + 0x1f8))();

                  bVar21 = SBORROW2(sVar5,*(short *)(iVar9 + 0xcc));

                  bVar20 = (short)(sVar5 - *(short *)(iVar9 + 0xcc)) < 0;

LAB_0090425a:

                  if (bVar21 != bVar20) {

LAB_0090425c:

                    iVar9 = *(int *)(iVar3 + 0x18);

                    uVar28 = *(uint32_t /* width from decompiler */ *)(iVar9 + iVar8);

                    *(uint32_t /* width from decompiler */ *)(iVar9 + iVar8) = *(uint32_t /* width from decompiler */ *)(iVar9 + iVar2);

                    *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2) = uVar28;

                  }

                }

                break;

              case 10:

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 != '\x01') {

                  iVar9 = (**(code **)(*piVar16 + 0x1f8))();

                  sVar5 = *(short *)(iVar9 + 0xb4);

                  iVar9 = (**(code **)(*piVar10 + 0x1f8))();

                  bVar21 = SBORROW2(sVar5,*(short *)(iVar9 + 0xb4));

                  bVar20 = (short)(sVar5 - *(short *)(iVar9 + 0xb4)) < 0;

                  goto LAB_0090425a;

                }

                iVar9 = (**(code **)(*piVar16 + 0x1f8))();

                sVar5 = *(short *)(iVar9 + 0xb4);

                iVar9 = (**(code **)(*piVar10 + 0x1f8))();

                if (*(short *)(iVar9 + 0xb4) < sVar5) goto LAB_0090425c;

                break;

              case 0xb:

                (**(code **)(*piVar16 + 0x1f8))();

                iVar9 = FUN_004049e0();

                fStack_638 = (float)*(int *)(iVar9 + 0x4c0);

                (**(code **)(*piVar10 + 0x1f8))();

                iVar9 = FUN_004049e0();

                fStack_634 = (float)*(int *)(iVar9 + 0x4c0);

                if (fStack_638 == 0.0) {

                  fStack_638 = 0.0;

                }

                if (fStack_634 == 0.0) {

                  fStack_634 = 0.0;

                }

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 == '\x01') {

                  if (fStack_634 < fStack_638) goto LAB_0090425c;

                }

                else if (fStack_638 < fStack_634) goto LAB_0090425c;

                break;

              case 0xc:

                piVar16 = (int *)(**(code **)(*piVar16 + 0x1f8))();

                psVar14 = (short *)(**(code **)(*piVar16 + 0x38))();

                piVar16 = (int *)(**(code **)(*piVar10 + 0x1f8))();

                psVar15 = (short *)(**(code **)(*piVar16 + 0x38))();

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 != '\x01') {

                  bVar21 = SBORROW2(*psVar14,*psVar15);

                  bVar20 = (short)(*psVar14 - *psVar15) < 0;

                  goto LAB_0090425a;

                }

                if (*psVar15 < *psVar14) goto LAB_0090425c;

                break;

              case 0xd:

                piVar16 = (int *)(**(code **)(*piVar16 + 0x1f8))();

                iVar9 = (**(code **)(*piVar16 + 0x38))();

                piVar16 = (int *)(**(code **)(*piVar10 + 0x1f8))();

                iVar13 = (**(code **)(*piVar16 + 0x38))();

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 != '\x01') {

                  bVar21 = SBORROW2(*(short *)(iVar9 + 2),*(short *)(iVar13 + 2));

                  bVar20 = (short)(*(short *)(iVar9 + 2) - *(short *)(iVar13 + 2)) < 0;

                  goto LAB_0090425a;

                }

                if (*(short *)(iVar13 + 2) < *(short *)(iVar9 + 2)) goto LAB_0090425c;

                break;

              case 0xe:

                piVar16 = (int *)(**(code **)(*piVar16 + 0x1f8))();

                iVar9 = (**(code **)(*piVar16 + 0x38))();

                piVar16 = (int *)(**(code **)(*piVar10 + 0x1f8))();

                iVar13 = (**(code **)(*piVar16 + 0x38))();

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 != '\x01') {

                  bVar21 = SBORROW2(*(short *)(iVar9 + 6),*(short *)(iVar13 + 6));

                  bVar20 = (short)(*(short *)(iVar9 + 6) - *(short *)(iVar13 + 6)) < 0;

                  goto LAB_0090425a;

                }

                if (*(short *)(iVar13 + 6) < *(short *)(iVar9 + 6)) goto LAB_0090425c;

                break;

              case 0xf:

                piVar16 = (int *)(**(code **)(*piVar16 + 0x1f8))();

                iVar9 = (**(code **)(*piVar16 + 0x38))();

                piVar16 = (int *)(**(code **)(*piVar10 + 0x1f8))();

                iVar13 = (**(code **)(*piVar16 + 0x38))();

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 != '\x01') {

                  bVar21 = SBORROW2(*(short *)(iVar9 + 8),*(short *)(iVar13 + 8));

                  bVar20 = (short)(*(short *)(iVar9 + 8) - *(short *)(iVar13 + 8)) < 0;

                  goto LAB_0090425a;

                }

                if (*(short *)(iVar13 + 8) < *(short *)(iVar9 + 8)) goto LAB_0090425c;

                break;

              case 0x10:

                piVar16 = (int *)(**(code **)(*piVar16 + 0x1f8))();

                iVar9 = (**(code **)(*piVar16 + 0x38))();

                piVar16 = (int *)(**(code **)(*piVar10 + 0x1f8))();

                iVar13 = (**(code **)(*piVar16 + 0x38))();

                cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

                if (cVar4 != '\x01') {

                  bVar21 = SBORROW2(*(short *)(iVar9 + 10),*(short *)(iVar13 + 10));

                  bVar20 = (short)(*(short *)(iVar9 + 10) - *(short *)(iVar13 + 10)) < 0;

                  goto LAB_0090425a;

                }

                if (*(short *)(iVar13 + 10) < *(short *)(iVar9 + 10)) goto LAB_0090425c;

              }

            }

          }

          fStack_644 = (float)((int)fStack_644 + 1);

        }

        iVar7 = iVar7 + 1;

      } while( true );

    }

    iVar7 = 0;

    do {

      if (*(int *)(iVar3 + 0x18) == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2;

      }

      fStack_638 = (float)iVar7;

      if (iVar8 <= iVar7) {

        return;

      }

      while( true ) {

        iVar8 = *(int *)(iVar3 + 0x18);

        if (iVar8 == 0) {

          iVar9 = 0;

        }

        else {

          iVar9 = *(int *)(iVar3 + 0x1c) - iVar8 >> 2;

        }

        if (iVar9 <= (int)fStack_638) break;

        iVar9 = iVar7 * 4;

        if ((((*(uint *)(*(int *)(iVar9 + iVar8) + 0x1f0) & *(uint *)(*(int *)(iVar9 + iVar8) + 500)

              ) == 0xffffffff) || (DAT_00d1b644 == 0)) ||

           (iVar2 = (int)fStack_638 * 4, iVar8 = *(int *)(iVar2 + *(int *)(iVar3 + 0x18)),

           (*(uint *)(iVar8 + 0x1f0) & *(uint *)(iVar8 + 500)) == 0xffffffff))

        goto switchD_00903a96_default;

        iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

        piVar16 = (int *)CVOGReaction_ResolveObjectTarget

                                   (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),*(uint32_t /* width from decompiler */ *)(iVar8 + 500));

        iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

        piVar10 = (int *)CVOGReaction_ResolveObjectTarget

                                   (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),*(uint32_t /* width from decompiler */ *)(iVar8 + 500));

        if (((piVar16 == (int *)0x0) || (iVar8 = (**(code **)(*piVar16 + 0x1d4))(), iVar8 == 0)) ||

           ((piVar10 == (int *)0x0 || (iVar8 = (**(code **)(*piVar10 + 0x1d4))(), iVar8 == 0))))

        goto switchD_00903a96_default;

        switch(iStack_618) {

        case 9:

          (**(code **)(*piVar16 + 0x1d4))();

          (**(code **)(*piVar10 + 0x1d4))();

          cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

          if (cVar4 != '\x01') {

            FUN_00902560();

            uVar26 = FUN_00902560();

            if ((int)uVar26 < (int)((ulonglong)uVar26 >> 0x20)) goto LAB_00903d4b;

            goto switchD_00903a96_default;

          }

          FUN_00902560();

          iVar8 = FUN_00902560();

          if (iVar8 <= extraout_ECX) goto switchD_00903a96_default;

          goto LAB_00903d4b;

        case 10:

          cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

          if (cVar4 == '\x01') {

            iVar8 = (**(code **)(*piVar16 + 0x1d4))();

            fVar24 = *(float *)(iVar8 + 0x10c);

            iVar8 = (**(code **)(*piVar10 + 0x1d4))();

            bVar20 = fVar24 == *(float *)(iVar8 + 0x10c);

            bVar21 = fVar24 < *(float *)(iVar8 + 0x10c);

          }

          else {

            iVar8 = (**(code **)(*piVar16 + 0x1d4))();

            fVar24 = *(float *)(iVar8 + 0x10c);

            iVar8 = (**(code **)(*piVar10 + 0x1d4))();

            bVar20 = *(float *)(iVar8 + 0x10c) == fVar24;

            bVar21 = *(float *)(iVar8 + 0x10c) < fVar24;

          }

          break;

        case 0xb:

          cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

          if (cVar4 == '\x01') {

            iVar8 = (**(code **)(*piVar16 + 0x1d4))();

            fVar24 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8)

                                        + 0x3c) + 0x634);

            iVar8 = (**(code **)(*piVar10 + 0x1d4))();

            pfVar1 = (float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8) +

                                       0x3c) + 0x634);

            bVar20 = fVar24 == *pfVar1;

            bVar21 = fVar24 < *pfVar1;

          }

          else {

            iVar8 = (**(code **)(*piVar16 + 0x1d4))();

            fVar24 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8)

                                        + 0x3c) + 0x634);

            iVar8 = (**(code **)(*piVar10 + 0x1d4))();

            fVar25 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xac + iVar8)

                                        + 0x3c) + 0x634);

            bVar20 = fVar25 == fVar24;

            bVar21 = fVar25 < fVar24;

          }

          break;

        case 0xc:

          cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

          if (cVar4 == '\x01') {

            bVar20 = (float)piVar16[0x30] == (float)piVar10[0x30];

            bVar21 = (float)piVar16[0x30] < (float)piVar10[0x30];

          }

          else {

            bVar20 = (float)piVar10[0x30] == (float)piVar16[0x30];

            bVar21 = (float)piVar10[0x30] < (float)piVar16[0x30];

          }

          break;

        case 0xd:

          iVar8 = (**(code **)(*piVar16 + 0x1d4))();

          if ((iVar8 != 0) && (iVar8 = (**(code **)(*piVar10 + 0x1d4))(), iVar8 != 0)) {

            (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

            iVar8 = (**(code **)(*piVar16 + 0x1d4))();

            sVar5 = *(short *)(iVar8 + 0x1e6);

            iVar8 = (**(code **)(*piVar10 + 0x1d4))();

            if (sVar5 < *(short *)(iVar8 + 0x1e6)) goto LAB_00903d4b;

          }

        default:

          goto switchD_00903a96_default;

        }

        if (!bVar21 && !bVar20) {

LAB_00903d4b:

          iVar8 = *(int *)(iVar3 + 0x18);

          uVar28 = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9);

          *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9) = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar2);

          *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2) = uVar28;

        }

switchD_00903a96_default:

        fStack_638 = (float)((int)fStack_638 + 1);

      }

      iVar7 = iVar7 + 1;

    } while( true );

  }

  iVar7 = 0;

  do {

    if (*(int *)(iVar3 + 0x18) == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2;

    }

    fStack_638 = (float)iVar7;

    if (iVar8 <= iVar7) {

      return;

    }

    while( true ) {

      iVar8 = *(int *)(iVar3 + 0x18);

      if (iVar8 == 0) {

        iVar9 = 0;

      }

      else {

        iVar9 = *(int *)(iVar3 + 0x1c) - iVar8 >> 2;

      }

      if (iVar9 <= (int)fStack_638) break;

      iVar9 = iVar7 * 4;

      if ((((*(uint *)(*(int *)(iVar9 + iVar8) + 0x1f0) & *(uint *)(*(int *)(iVar9 + iVar8) + 500))

            == 0xffffffff) ||

          (iVar2 = (int)fStack_638 * 4, iVar8 = *(int *)(iVar2 + *(int *)(iVar3 + 0x18)),

          (*(uint *)(iVar8 + 0x1f0) & *(uint *)(iVar8 + 500)) == 0xffffffff)) || (DAT_00d1b644 == 0)

         ) goto switchD_009034e1_default;

      iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar9);

      piVar16 = (int *)CVOGReaction_ResolveObjectTarget

                                 (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),*(uint32_t /* width from decompiler */ *)(iVar8 + 500));

      iVar8 = *(int *)(*(int *)(iVar3 + 0x18) + iVar2);

      piVar10 = (int *)CVOGReaction_ResolveObjectTarget

                                 (1,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1f0),*(uint32_t /* width from decompiler */ *)(iVar8 + 500));

      if (((piVar16 == (int *)0x0) || (iVar8 = (**(code **)(*piVar16 + 0x1e0))(), iVar8 == 0)) ||

         ((piVar10 == (int *)0x0 || (iVar8 = (**(code **)(*piVar10 + 0x1e0))(), iVar8 == 0))))

      goto switchD_009034e1_default;

      switch(iStack_618) {

      case 9:

        (**(code **)(*piVar16 + 0x1e0))();

        fVar22 = (float10)FUN_0056b560();

        fStack_628 = (float)fVar22;

        (**(code **)(*piVar10 + 0x1e0))();

        fVar22 = (float10)FUN_0056b560();

        fStack_644 = (float)fVar22;

        (**(code **)(*piVar16 + 0x1e0))();

        iVar8 = FUN_0040da70();

        if (iVar8 == 0) {

LAB_0090355d:

          fStack_628 = 0.0;

        }

        else {

          (**(code **)(*piVar16 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if (*(char *)(iVar8 + 0x3f4) == '\t') goto LAB_0090355d;

          (**(code **)(*piVar16 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if ((*(byte *)(iVar8 + 0x536) & 4) != 0) goto LAB_0090355d;

        }

        (**(code **)(*piVar10 + 0x1e0))();

        iVar8 = FUN_0040da70();

        if (iVar8 == 0) {

LAB_009035b3:

          fStack_644 = 0.0;

        }

        else {

          (**(code **)(*piVar10 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if (*(char *)(iVar8 + 0x3f4) == '\t') goto LAB_009035b3;

          (**(code **)(*piVar10 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if ((*(byte *)(iVar8 + 0x536) & 4) != 0) goto LAB_009035b3;

        }

        cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

        if (cVar4 == '\x01') {

LAB_009038e8:

          bVar20 = fStack_628 == fStack_644;

          bVar21 = fStack_628 < fStack_644;

        }

        else {

          bVar20 = fStack_644 == fStack_628;

          bVar21 = fStack_644 < fStack_628;

        }

        goto LAB_009038f3;

      case 10:

        iVar8 = (**(code **)(*piVar16 + 0x1e0))();

        sVar5 = *(short *)(iVar8 + 0x118);

        (**(code **)(*piVar16 + 0x1e0))();

        iVar8 = FUN_0040da70();

        sVar5 = *(short *)(iVar8 + 0x530) + sVar5;

        iVar8 = (**(code **)(*piVar10 + 0x1e0))();

        sVar6 = *(short *)(iVar8 + 0x118);

        (**(code **)(*piVar10 + 0x1e0))();

        iVar8 = FUN_0040da70();

        sVar6 = *(short *)(iVar8 + 0x530) + sVar6;

        (**(code **)(*piVar16 + 0x1e0))();

        iVar8 = FUN_0040da70();

        if (iVar8 == 0) {

LAB_00903689:

          sVar5 = 0;

        }

        else {

          (**(code **)(*piVar16 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if ((*(byte *)(iVar8 + 0x536) & 4) != 0) goto LAB_00903689;

        }

        (**(code **)(*piVar10 + 0x1e0))();

        iVar8 = FUN_0040da70();

        if (iVar8 == 0) {

LAB_009036c4:

          sVar6 = 0;

        }

        else {

          (**(code **)(*piVar10 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if ((*(byte *)(iVar8 + 0x536) & 4) != 0) goto LAB_009036c4;

        }

        cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

        if (cVar4 != '\x01') {

          if (sVar5 < sVar6) goto LAB_009038f5;

          break;

        }

        if (sVar5 <= sVar6) break;

        goto LAB_009038f5;

      case 0xb:

        uVar28 = 0;

        (**(code **)(*piVar16 + 0x1e0))(0);

        fStack_628 = (float)FUN_0056a680(uVar28);

        uVar28 = 0;

        (**(code **)(*piVar10 + 0x1e0))(0);

        iVar8 = FUN_0056a680(uVar28);

        (**(code **)(*piVar16 + 0x1e0))();

        iVar13 = FUN_0040da70();

        if (iVar13 == 0) {

LAB_00903763:

          fStack_628 = 1.4012985e-38;

        }

        else {

          (**(code **)(*piVar16 + 0x1e0))();

          iVar13 = FUN_0040da70();

          if (*(char *)(iVar13 + 0x3f4) == '\t') goto LAB_00903763;

        }

        (**(code **)(*piVar10 + 0x1e0))();

        iVar13 = FUN_0040da70();

        if (iVar13 == 0) {

LAB_0090379e:

          iVar8 = 10000000;

        }

        else {

          (**(code **)(*piVar10 + 0x1e0))();

          iVar13 = FUN_0040da70();

          if (*(char *)(iVar13 + 0x3f4) == '\t') goto LAB_0090379e;

        }

        cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

        if (cVar4 == '\x01') {

          if ((int)fStack_628 < iVar8) goto LAB_009038f5;

        }

        else if (iVar8 < (int)fStack_628) goto LAB_009038f5;

        break;

      case 0xc:

        (**(code **)(*piVar16 + 0x1e0))();

        iVar8 = FUN_0056b280();

        (**(code **)(*piVar16 + 0x1e0))();

        fVar22 = (float10)FUN_00569dc0();

        fStack_644 = (float)(fVar22 + (float10)iVar8);

        (**(code **)(*piVar10 + 0x1e0))();

        iVar8 = FUN_0056b280();

        (**(code **)(*piVar10 + 0x1e0))();

        fVar22 = (float10)FUN_00569dc0();

        fStack_628 = (float)(fVar22 + (float10)iVar8);

        (**(code **)(*piVar16 + 0x1e0))();

        iVar8 = FUN_0040da70();

        if (iVar8 == 0) {

LAB_0090387e:

          fStack_644 = 0.0;

        }

        else {

          (**(code **)(*piVar16 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if ((*(byte *)(iVar8 + 0x536) & 4) != 0) goto LAB_0090387e;

        }

        (**(code **)(*piVar10 + 0x1e0))();

        iVar8 = FUN_0040da70();

        if (iVar8 == 0) {

LAB_009038ba:

          fStack_628 = 0.0;

        }

        else {

          (**(code **)(*piVar10 + 0x1e0))();

          iVar8 = FUN_0040da70();

          if ((*(byte *)(iVar8 + 0x536) & 4) != 0) goto LAB_009038ba;

        }

        cVar4 = (**(code **)(**(int **)(*piVar18 + 0x800) + 0x3bc))();

        if (cVar4 != '\x01') goto LAB_009038e8;

        bVar20 = fStack_644 == fStack_628;

        bVar21 = fStack_644 < fStack_628;

LAB_009038f3:

        if (!bVar21 && !bVar20) {

LAB_009038f5:

          iVar8 = *(int *)(iVar3 + 0x18);

          uVar28 = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9);

          *(uint32_t /* width from decompiler */ *)(iVar8 + iVar9) = *(uint32_t /* width from decompiler */ *)(iVar8 + iVar2);

          *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x18) + iVar2) = uVar28;

        }

      }

switchD_009034e1_default:

      fStack_638 = (float)((int)fStack_638 + 1);

    }

    iVar7 = iVar7 + 1;

  } while( true );

LAB_0090336f:

  iVar7 = iVar7 + 1;

  goto LAB_00902cc9;

}
