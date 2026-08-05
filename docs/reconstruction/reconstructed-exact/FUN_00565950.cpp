// =============================================================================
// FUN_00565950  →  CVOGSpawnPoint_ActivateFromStream_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00565950
// Address:   0x00565950 – 0x00566485  (2870 B / 0xB36)  autoassault.exe @ 0x400000
// System:    client spawn-point stream unpack + activation
// Generated: 2026-07-23 scaffold; sealed W30-H 2026-07-29 (authoritative CF twin)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Named: CVOGSpawnPoint_ActivateFromStream_Inferred.cpp
// ABI: thiscall; ret 0x10; return 0 if stream null else 1; range default 75.0f
// =============================================================================

// PURPOSE: Versioned stream unpack into CVOGSpawnPoint MI subobject; add world
// offset; clamp bad activation range to 75.0f; optional linked spawn; InsertAlways maps.
// Embedded strings:
//   - "******BAD SPAWN POINT ACTIVATION RANGE: %d %f"
//   - "Spawn:%I64d"
// Entry: MI thunk 0x00567CBE. See W30-H dual A/B.

// READABILITY (auto CF):
//  - Body size: ~504 non-empty decompiler lines.
//  - Control keywords: if×43, do×10, while×10, goto×3, return×2.
//  - Notable callees: CONCAT44×6, FUN_00418e60×2, FUN_004bc180×2, FUN_00512160×2, FUN_00567860×2, sprintf×2, CONCAT12, FUN_0040b330.
//  - Strings: "******BAD SPAWN POINT ACTIVATION RANGE: %d %f"; "Spawn:%I64d".
//  - Return sites: 2.

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



uint32_t /* width from decompiler */ __thiscall FUN_00565950(int param_1,int *param_2,uint8_t *param_3,float *param_4)



{

  float *pfVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  char cVar4;

  int iVar5;

  uint uVar6;

  ulonglong uVar7;

  uint64_t uVar8;

  int iVar9;

  int *piVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ uVar12;

  char *pcVar13;

  void *pvVar14;

  RACE_ID_INFERRED RVar15;

  uint8_t *puVar16;

  uint32_t /* width from decompiler */ *puVar17;

  uint *puVar18;

  bool bVar19;

  int aiStack_5a8 [2];

  uint *puStack_5a0;

  void *pvStack_59c;

  int iStack_598;

  uint uStack_594;

  void *pvStack_590;

  uint32_t /* width from decompiler */ uStack_58c;

  uint uVar20;

  uint uVar21;

  int iStack_580;

  uint32_t /* width from decompiler */ uStack_57c;

  uint32_t /* width from decompiler */ uStack_578;

  uint32_t /* width from decompiler */ uStack_570;

  uint32_t /* width from decompiler */ uStack_56c;

  uint8_t *puStack_568;

  uint32_t /* width from decompiler */ uStack_564;

  int iStack_560;

  uint32_t /* width from decompiler */ uStack_55c;

  int iStack_558;

  uint32_t /* width from decompiler */ uStack_554;

  int iStack_550;

  uint uStack_54c;

  int *piStack_548;

  uint8_t *puStack_544;

  char acStack_530 [224];

  char acStack_450 [75];

  uint8_t auStack_405 [8];

  uint8_t auStack_3fd [869];

  uint32_t /* width from decompiler */ uStack_98;

  void *pvStack_94;

  uint32_t /* width from decompiler */ uStack_8c;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a4b5f;

  local_1c = ExceptionList;

  if (param_2 == (int *)0x0) {

    return 0;

  }

  puStack_544 = param_3;

  piStack_548 = param_2;

  uStack_54c = 0x5659b8;

  ExceptionList = &local_1c;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x1dc + param_1) + 0xb0))();

  iStack_550 = *(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x15c + param_1;

  uStack_54c = 0x10;

  uStack_554 = 0x5659d2;

  (**(code **)(*param_2 + 0x14))();

  pfVar1 = (float *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x15c + param_1);

  *pfVar1 = *param_4 + *pfVar1;

  pfVar1[1] = param_4[1] + pfVar1[1];

  pfVar1[2] = param_4[2] + pfVar1[2];

  pfVar1[3] = param_4[3] + pfVar1[3];

  iStack_558 = *(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x14c + param_1;

  uStack_554 = 0x10;

  uStack_55c = 0x565a38;

  (**(code **)(*param_2 + 0x14))();

  uStack_55c = 4;

  iStack_560 = param_1 + -0x144;

  uStack_564 = 0x565a48;

  (**(code **)(*param_2 + 0x14))();

  uStack_564 = 4;

  puStack_568 = (uint8_t *)(param_1 + -0x15c);

  uStack_56c = 0x565a58;

  (**(code **)(*param_2 + 0x14))();

  uStack_56c = 4;

  pfVar1 = (float *)(param_1 + -0x160);

  _uStack_578 = (double)CONCAT44(0x565a68,uStack_578);

  uStack_570 = pfVar1;

  (**(code **)(*param_2 + 0x14))();

  if (*pfVar1 <= 0.0) {

    uStack_57c = *(uint8_t **)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x78 + param_1);

    _uStack_578 = (double)*pfVar1;

    uStack_58c = 0x565a9e;

    sprintf(acStack_450,"******BAD SPAWN POINT ACTIVATION RANGE: %d %f");

    _uStack_578 = (double)CONCAT44(acStack_450,0x565aaf);

    OutputDebugStringA(acStack_450);

    *pfVar1 = _DAT_009d2eb8;

  }

  _uStack_578 = (double)CONCAT44(1,param_1 + -0x138);

  uStack_57c = (uint8_t *)0x565acb;

  (**(code **)(*param_2 + 0x14))();

  uStack_57c = (uint8_t *)0x1;

  (**(code **)(*param_2 + 0x14))();

  uStack_58c = 0x565aeb;

  (**(code **)(*param_2 + 0x14))();

  uStack_58c = 1;

  pvStack_590 = (void *)(param_1 + -0x12e);

  uStack_594 = 0x565afb;

  (**(code **)(*param_2 + 0x14))();

  uStack_594 = 1;

  iStack_598 = (int)&uStack_570 + 3;

  uStack_570 = (float *)((uint)uStack_570 & 0xffffff);

  pvStack_59c = (void *)0x565b0e;

  (**(code **)(*param_2 + 0x14))();

  iVar9 = *(int *)(*(int *)(param_1 + -0x1dc) + 4);

  puVar18 = (uint *)(iVar9 + -0x60 + param_1);

  *puVar18 = *puVar18 ^ ((uint)uStack_578._3_1_ << 9 ^ *(uint *)(iVar9 + -0x60 + param_1)) & 0x200;

  if (0x1e < (int)param_3) {

    pvStack_59c = (void *)0x1;

    puStack_5a0 = (uint *)(param_1 + -0x37);

    aiStack_5a8[1] = 0x565b44;

    (**(code **)(*param_2 + 0x14))();

  }

  if ((int)param_3 < 0x1d) {

    uStack_57c = auStack_405 + (4 - param_1);

    uStack_570 = (float *)(auStack_3fd + -param_1);

    puStack_568 = auStack_405 + (1 - param_1);

    puVar16 = (uint8_t *)(param_1 + -0xeb);

    _uStack_578 = (double)CONCAT44(10,uStack_578);

    do {

      puStack_5a0 = (uint *)(puVar16 + (int)(auStack_405 + -param_1));

      pvStack_59c = (void *)0xc;

      aiStack_5a8[1] = 0x565ba1;

      (**(code **)(*param_2 + 0x14))();

      if (*(int *)(puVar16 + (int)uStack_57c) < 0) {

        *(uint32_t /* width from decompiler */ *)(puVar16 + (int)uStack_57c) = 0xffffffff;

      }

      pvStack_59c = *(void **)(puVar16 + (int)uStack_57c);

      puStack_5a0 = (uint *)0x565bc1;

      iVar9 = FUN_005630f0();

      uVar8 = _uStack_578;

      if (iVar9 == -1) {

        *puVar16 = 0;

      }

      else {

        *(int *)(puVar16 + (int)uStack_57c) = iVar9;

        *puVar16 = 1;

      }

      uVar2 = puVar16[(int)uStack_570];

      *(uint32_t /* width from decompiler */ *)(puVar16 + -5) = *(uint32_t /* width from decompiler */ *)(puVar16 + (int)uStack_57c);

      uVar3 = puVar16[(int)(auStack_405 + -param_1)];

      puVar16[-1] = uVar2;

      uVar2 = puVar16[(int)puStack_568];

      puVar16[-9] = uVar3;

      puVar16[-8] = uVar2;

      puVar16 = puVar16 + 0xc;

      uVar7 = (ulonglong)_uStack_578 >> 0x20;

      iVar9 = (int)uVar7 + -1;

      uStack_578 = (uint32_t /* width from decompiler */)uVar8;

      _uStack_578 = (double)CONCAT44(iVar9,uStack_578);

    } while (iVar9 != 0);

  }

  else {

    piVar10 = (int *)(param_1 + -0xf0);

    iStack_580 = 0xc;

    do {

      pvStack_59c = (void *)0xc;

      puStack_5a0 = (uint *)(piVar10 + -1);

      aiStack_5a8[1] = 0x565c2d;

      (**(code **)(*param_2 + 0x14))();

      if (*piVar10 < 0) {

        *piVar10 = -1;

      }

      piVar10 = piVar10 + 3;

      iStack_580 = iStack_580 + -1;

    } while (iStack_580 != 0);

  }

  pvStack_59c = (void *)0x4;

  puStack_5a0 = (uint *)(param_1 + -0x40);

  aiStack_5a8[1] = 0x565c52;

  (**(code **)(*param_2 + 0x14))();

  aiStack_5a8[1] = 4;

  aiStack_5a8[0] = param_1 + -0x3c;

  (**(code **)(*param_2 + 0x14))();

  (**(code **)(*param_2 + 0x14))(param_1 + -0x140,8);

  (**(code **)(*param_2 + 0x14))(param_1 + -0x164,4);

  if (0xe < (int)param_3) {

    (**(code **)(*param_2 + 0x14))(param_1 + -0x38,1);

    (**(code **)(*param_2 + 0x14))(aiStack_5a8,4);

    FUN_00512460(puStack_5a0);

    *(uint **)(param_1 + -0x24) = puStack_5a0;

  }

  if (0x17 < (int)param_3) {

    (**(code **)(*param_2 + 0x14))(param_1 + -0x28,4);

  }

  if (0x19 < (int)param_3) {

    bVar19 = (int)(param_3 + -0x1d) < 0;

    if (0x1c < (int)param_3) goto LAB_00565d73;

    puVar17 = &uStack_578;

    puStack_5a0 = (uint *)0x2;

    do {

      (**(code **)(*param_2 + 0x14))(puVar17,0xc);

      puVar17 = puVar17 + 3;

      puStack_5a0 = (uint *)((int)puStack_5a0 + -1);

    } while (puStack_5a0 != (uint *)0x0);

    iVar9 = 0;

    puVar17 = &uStack_570;

    piVar10 = (int *)(param_1 + -0xf0);

    do {

      if (*piVar10 == -1) {

        *piVar10 = puVar17[-1];

        *(uint8_t *)(piVar10 + 1) = *(uint8_t *)puVar17;

        *(uint8_t *)(piVar10 + -1) = *(uint8_t *)(puVar17 + -2);

        uVar2 = *(uint8_t *)((int)puVar17 + -7);

        iVar9 = iVar9 + 1;

        *(uint8_t *)((int)piVar10 + 5) = 1;

        *(uint8_t *)((int)piVar10 + -3) = uVar2;

        puVar17 = puVar17 + 3;

      }

      piVar10 = piVar10 + 3;

      puStack_5a0 = (uint *)0x0;

    } while (iVar9 < 2);

  }

  bVar19 = (int)(param_3 + -0x1d) < 0;

  if ((int)param_3 < 0x1d) {

    piVar10 = (int *)(param_1 + -0xf0);

    iVar9 = 0xc;

    do {

      if ((*piVar10 != -1) && (*piVar10 < 4)) {

        *piVar10 = 0x25;

        *(uint8_t *)((int)piVar10 + 5) = 1;

      }

      piVar10 = piVar10 + 3;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

    bVar19 = (int)(param_3 + -0x1d) < 0;

  }

LAB_00565d73:

  if (param_3 == (uint8_t *)0x1d || SBORROW4((int)param_3,0x1d) != bVar19) {

    pcVar11 = (char *)(param_1 + -0xf3);

    iVar9 = 2;

    do {

      if ((pcVar11[-1] == '\0') && (*pcVar11 == '\0')) {

        pcVar11[3] = -1;

        pcVar11[4] = -1;

        pcVar11[5] = -1;

        pcVar11[6] = -1;

      }

      if ((pcVar11[0xb] == '\0') && (pcVar11[0xc] == '\0')) {

        pcVar11[0xf] = -1;

        pcVar11[0x10] = -1;

        pcVar11[0x11] = -1;

        pcVar11[0x12] = -1;

      }

      if ((pcVar11[0x17] == '\0') && (pcVar11[0x18] == '\0')) {

        pcVar11[0x1b] = -1;

        pcVar11[0x1c] = -1;

        pcVar11[0x1d] = -1;

        pcVar11[0x1e] = -1;

      }

      if ((pcVar11[0x23] == '\0') && (pcVar11[0x24] == '\0')) {

        pcVar11[0x27] = -1;

        pcVar11[0x28] = -1;

        pcVar11[0x29] = -1;

        pcVar11[0x2a] = -1;

      }

      if ((pcVar11[0x2f] == '\0') && (pcVar11[0x30] == '\0')) {

        pcVar11[0x33] = -1;

        pcVar11[0x34] = -1;

        pcVar11[0x35] = -1;

        pcVar11[0x36] = -1;

      }

      if ((pcVar11[0x3b] == '\0') && (pcVar11[0x3c] == '\0')) {

        pcVar11[0x3f] = -1;

        pcVar11[0x40] = -1;

        pcVar11[0x41] = -1;

        pcVar11[0x42] = -1;

      }

      pcVar11 = pcVar11 + 0x48;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  iVar9 = param_1 + *(int *)(*(int *)(param_1 + -0x1dc) + 4);

  iVar5 = *(int *)(iVar9 + -0x138);

  if ((((iVar5 != 0) && (*(char *)(iVar5 + 0x7e) != '\0')) && ((*(byte *)(iVar9 + -0x5f) & 2) != 0))

     && (*(char *)(iVar5 + 0x7d) == '\0')) {

    iVar9 = *(int *)(param_1 + -0x138 + *(int *)(*(int *)(param_1 + -0x1dc) + 4));

    uVar20 = *(uint *)(iVar9 + 0xe6d8);

    uVar6 = *(uint *)(iVar9 + 0xe6dc);

    *(uint *)(iVar9 + 0xe6d8) = uVar20 + 1;

    *(uint *)(iVar9 + 0xe6dc) = uVar6 + (0xfffffffe < uVar20);

    uVar21 = uVar6;

    pvStack_590 = operator_new(0x270);

    uStack_8c = 0;

    if (pvStack_590 == (void *)0x0) {

      uVar12 = 0;

    }

    else {

      uVar12 = FUN_0057b0e0();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + -0xfc) = uVar12;

    iVar9 = *(int *)(*(int *)(param_1 + -0x1dc) + 4);

    uStack_8c = 0xffffffff;

    sprintf(acStack_530,"Spawn:%I64d",*(uint32_t /* width from decompiler */ *)(iVar9 + -0x7c + param_1),

            *(uint32_t /* width from decompiler */ *)(iVar9 + -0x78 + param_1));

    iVar9 = (**(code **)(**(int **)(param_1 + -0xfc) + 8))

                      (DAT_00b04850,

                       *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x138 + param_1),

                       1);

    if (iVar9 == 0) {

      FUN_00512160(uStack_594,uVar6,0);

      (**(code **)(**(int **)(param_1 + -0xfc) + 0x218))

                (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x138 + param_1));

      pcVar11 = &stack0xfffffac4;

      pcVar13 = (char *)(*(int *)(param_1 + -0xfc) + 400);

      do {

        cVar4 = *pcVar11;

        *pcVar13 = cVar4;

        pcVar11 = pcVar11 + 1;

        pcVar13 = pcVar13 + 1;

      } while (cVar4 != '\0');

      *(uint8_t *)(*(int *)(param_1 + -0xfc) + 0x1d1) = 0x49;

      iVar9 = *(int *)(*(int *)(param_1 + -0x1dc) + 4);

      pvStack_59c = *(void **)(iVar9 + -0x7c + param_1);

      iStack_598 = *(int *)(iVar9 + -0x78 + param_1);

      iVar9 = *(int *)(param_1 + -0xfc);

      iVar5 = *(int *)(iVar9 + 0x1d8);

      if ((iVar5 == 0) ||

         ((uint)(*(int *)(iVar9 + 0x1e0) - iVar5 >> 3) <=

          (uint)(*(int *)(iVar9 + 0x1dc) - iVar5 >> 3))) {

        FUN_00418e60(*(uint32_t /* width from decompiler */ *)(iVar9 + 0x1dc),1,&pvStack_59c);

      }

      else {

        piVar10 = *(int **)(iVar9 + 0x1dc);

        *piVar10 = (int)pvStack_59c;

        piVar10[1] = iStack_598;

        *(int **)(iVar9 + 0x1dc) = piVar10 + 2;

      }

      FUN_004bc180(*(uint32_t /* width from decompiler */ *)(param_1 + -0xfc));

    }

    else {

      if (*(uint32_t /* width from decompiler */ **)(param_1 + -0xfc) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0xfc))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + -0xfc) = 0;

    }

    pvStack_59c = operator_new(0x350);

    uStack_98 = 1;

    if (pvStack_59c == (void *)0x0) {

      iVar9 = 0;

    }

    else {

      iVar9 = FUN_005dbfa0(1);

    }

    *(int *)(param_1 + -0x100) = iVar9;

    uStack_98 = 0xffffffff;

    iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 8))

                      (DAT_00bc5684,

                       *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x138 + param_1),

                       1);

    if (iVar9 == 0) {

      iVar9 = *(int *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x138 + param_1);

      uVar6 = *(uint *)(iVar9 + 0xe6d8);

      iVar5 = *(int *)(iVar9 + 0xe6dc);

      *(uint *)(iVar9 + 0xe6d8) = uVar6 + 1;

      *(uint *)(iVar9 + 0xe6dc) = iVar5 + (uint)(0xfffffffe < uVar6);

      FUN_00512160(uVar6,iVar5,0);

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x100) + 4) + 4) + 4 +

                           *(int *)(param_1 + -0x100)) + 0x218))

                (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x138 + param_1));

      iVar9 = *(int *)(*(int *)(param_1 + -0x1dc) + 4);

      uStack_57c = *(uint8_t **)(iVar9 + -0x15c + param_1);

      iVar9 = iVar9 + -0x15c + param_1;

      _uStack_578 = *(double *)(iVar9 + 4);

      uStack_570 = *(float **)(iVar9 + 0xc);

      FUN_005db4a0(&uStack_57c);

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x100) + 4) + 4) + 4 +

                           *(int *)(param_1 + -0x100)) + 0xb8))(*(uint32_t /* width from decompiler */ *)(param_1 + -0x160));

      *(uint8_t *)(*(int *)(param_1 + -0x100) + 0xde) = 1;

      *(uint8_t *)(*(int *)(param_1 + -0x100) + 0xdc) = 0;

      *(uint8_t *)(*(int *)(param_1 + -0x100) + 0xdd) = 0;

      pcVar11 = &stack0xfffffac8;

      pcVar13 = (char *)(*(int *)(param_1 + -0x100) + 0xe3);

      do {

        cVar4 = *pcVar11;

        *pcVar13 = cVar4;

        pcVar11 = pcVar11 + 1;

        pcVar13 = pcVar13 + 1;

      } while (cVar4 != '\0');

      *(uint8_t *)(*(int *)(param_1 + -0x100) + 0xdf) = 0;

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x100) + 0x15c) = 1;

      FUN_005dc5f0(1);

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x100) + 4) + 4) + 4 +

                           *(int *)(param_1 + -0x100)) + 0xb4))();

      iVar9 = *(int *)(param_1 + -0x100);

      iVar5 = *(int *)(iVar9 + 0x148);

      if ((iVar5 == 0) ||

         ((uint)(*(int *)(iVar9 + 0x150) - iVar5 >> 3) <=

          (uint)(*(int *)(iVar9 + 0x14c) - iVar5 >> 3))) {

        FUN_00418e60(*(uint32_t /* width from decompiler */ *)(iVar9 + 0x14c),1,&stack0xfffffa78);

      }

      else {

        puVar18 = *(uint **)(iVar9 + 0x14c);

        *puVar18 = uVar20;

        puVar18[1] = uVar21;

        *(uint **)(iVar9 + 0x14c) = puVar18 + 2;

      }

      iVar9 = *(int *)(param_1 + -0x100);

      if (iVar9 != 0) {

        iVar9 = *(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9;

      }

      FUN_004bc180(iVar9);

    }

    else {

      iVar9 = *(int *)(param_1 + -0x100);

      if (iVar9 != 0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x100) = 0;

    }

  }

  if (0x1f < (int)param_3) {

    pvStack_59c = (void *)0x0;

    (**(code **)(*param_2 + 0x14))(&pvStack_59c,4);

    if (0 < (int)pvStack_59c) {

      pvVar14 = operator_new__((int)pvStack_59c + 1);

      (**(code **)(*param_2 + 0x14))(pvVar14,pvStack_59c);

      operator_delete__(pvVar14);

    }

  }

  if (*(int *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x138 + param_1) != 0) {

    puVar18 = (uint *)(param_1 + -0xf0);

    pvStack_590 = (void *)0xc;

    do {

      puStack_5a0 = puVar18;

      if ((*(char *)((int)puVar18 + -3) != '\0') && (uVar20 = *puVar18, uVar20 != 0xffffffff)) {

        RVar15 = Object_GetRootRaceId

                           ((void *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x1dc + param_1));

        pvStack_59c = (void *)(int)(char)puVar18[1];

        if (*(char *)((int)puVar18 + 5) == '\0') {

          iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                   (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar20) * 4) + 4

                          );

          if (iVar9 == 0) {

LAB_00566386:

            uStack_594 = 0;

          }

          else {

            do {

              if (uVar20 == *(uint *)(iVar9 + 0x10)) {

                if (iVar9 == 0) goto LAB_00566386;

                uStack_594 = *(uint *)(iVar9 + 8);

                goto LAB_00566395;

              }

              iVar9 = *(int *)(iVar9 + 0xc);

            } while (iVar9 != 0);

            uStack_594 = 0;

          }

LAB_00566395:

          pvVar14 = pvStack_59c;

          if ((uStack_594 != 0) && (piVar10 = *(int **)(uStack_594 + 0x3c), piVar10 != (int *)0x0))

          {

            if (*(char *)(param_1 + -0x38) == '\0') {

              RVar15 = (**(code **)(*piVar10 + 0x14))();

            }

            pvVar14 = pvStack_59c;

            if (*(int *)(uStack_594 + 0x38) == 0x12) {

              pvVar14 = (void *)((int)pvStack_59c + (int)*(short *)((int)piVar10 + 0x4ee));

            }

          }

        }

        else {

          uStack_594 = uVar20;

          iVar9 = FUN_0040b330(&uStack_594);

          pvStack_59c = (void *)((int)pvStack_59c + (int)*(short *)(iVar9 + 0x28));

          pvVar14 = pvStack_59c;

        }

        puVar16 = uStack_57c;

        uStack_57c._0_2_ = SUB42(pvVar14,0);

        if ((int)pvVar14 < 2) {

          uStack_57c._0_2_ = 1;

        }

        uStack_57c._3_1_ = SUB41(puVar16,3);

        uStack_57c._0_3_ = CONCAT12(*(uint8_t *)((int)puStack_5a0 + 5),(uint16_t)uStack_57c);

        puVar16 = uStack_57c;

        puStack_544 = uStack_57c;

        uStack_54c = uVar20;

        piStack_548 = (int *)(param_1 + -0x1e0);

        FUN_00567860(&stack0xfffffac0,&uStack_54c);

        _uStack_578 = (double)CONCAT44((int *)(param_1 + -0x1e0),RVar15);

        uStack_570 = (float *)puVar16;

        FUN_00567860(&stack0xfffffac8,&uStack_578);

      }

      puVar18 = puStack_5a0 + 3;

      pvStack_590 = (void *)((int)pvStack_590 + -1);

    } while (pvStack_590 != (void *)0x0);

  }

  ExceptionList = pvStack_94;

  return 1;

}
