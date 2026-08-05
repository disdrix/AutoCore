// READABILITY (auto CF):
//  - Body size: ~192 non-empty decompiler lines.
//  - Control keywords: if×36, return×12, goto×7, do×4, while×4, for×1.
//  - Notable callees: GetAsyncKeyState×3, FUN_004040a0×2, FUN_007fca10×2, FUN_007fef20×2, FUN_008a70c0×2, FUN_0093a5c0×2, CONCAT31, Client_Input_OnKeyDown_MatchAction.
//  - Return sites: 12.

// =============================================================================
// Client_Input_OnKeyDown_MatchAction
// -----------------------------------------------------------------------------
// Stable ID: aa_00911030
// Address:   0x00911030  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (WM key-down → ActionMap held/edge)
// Generated: 2026-07-23 from raw capture
// Refined:   2026-07-23 human-refine — plate + section banners for ESC /
//            table scan / held+edge set. CF ≡ raw.
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  WM key-down path. Scans action-slot table (base ~DAT_00d1bc18 /
//           entry DAT_00d1bbee, stride 0x34 / short-step 0x1a) for DIK match
//           (+ optional LSHIFT 0x2A modifier from GetAsyncKeyState). On match
//           sets entry held (+4) and edge (+5), then FUN_0093a5c0(1).
//           ESC (0x1b) special-cases UI cancel when client vtbl+0x3d8 allows.
//
// Related:
//   Client_InitDefaultKeybinds     0x007f8720  (writes DIK defaults into slots)
//   Client_Input_PollBoundActions  0x00925d60  (edge consumers / QB)
//   Client_Input_DriveControlTick  0x009223b0  (held thr/steer/HB)
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 * - Section comments annotate ESC vs table-scan only; they do not invent branches.
 *
 * pClient  — this (int*); param_2 often VK/DIK-ish; param_3 lParam-ish pack.
 */

/* WI-INP-004: WM key-down path. Scans action-slot table (base ~DAT_00d1bc18 / entry DAT_00d1bbee,
   stride 0x34) for DIK match (+ LSHIFT 0x2A modifier). On match sets entry+4 held and +5 edge, then
   FUN_0093a5c0(1). ESC special-cases UI cancel. */

uint __thiscall Client_Input_OnKeyDown_MatchAction(int *pClient,uint param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  uint8_t uVar3;
  SHORT SVar4;
  SHORT SVar5;
  SHORT SVar6;
  int iVar7;
  uint32_t /* width from decompiler */ uVar8;
  uint uVar9;
  uint16_t *puVar10;
  short *psVar11;
  int iVar12;
  short sVar13;
  short sVar14;
  int *piVar15;
  
  // ---------------------------------------------------------------------------
  // SECTION 1: ESC gate — if vtbl+0x3d8 non-zero AND key==0x1b → UI cancel path
  // ---------------------------------------------------------------------------
  cVar2 = (**(code **)(*pClient + 0x3d8))();
  iVar12 = param_2;
  if ((cVar2 == '\0') || (param_2 != 0x1b)) {
LAB_009113c1:
    // -------------------------------------------------------------------------
    // SECTION 2: Normalize key + sample Shift → DIK_LSHIFT (0x2a) modifier
    // -------------------------------------------------------------------------
    iVar7 = param_3;
    uVar3 = FUN_00790020(iVar12,param_3);
    param_2 = CONCAT31(param_2._1_3_,uVar3);
    SVar4 = GetAsyncKeyState(0x10);
    SVar5 = GetAsyncKeyState(0xa0);
    SVar6 = GetAsyncKeyState(0xa1);
    if (((SVar4 == 0) && (SVar5 == 0)) && (SVar6 == 0)) {
      sVar13 = 0;
    }
    else {
      sVar13 = 0x2a;
    }
    sVar14 = (short)((iVar7 >> 0x18 & 1U) << 7) + (ushort)param_3._2_1_;
    // -------------------------------------------------------------------------
    // SECTION 3: Optional slot override via FUN_007f6db0; else scan DAT_00d1bc18
    // -------------------------------------------------------------------------
    puVar10 = (uint16_t *)FUN_007f6db0();
    if (puVar10 == (uint16_t *)0x0) {
      if ((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 == DAT_00d1b778)) {
        iVar12 = 0;
        psVar11 = &DAT_00d1bc18;
        do {
          if (psVar11[-0x15] == sVar14) {
            if (sVar13 == 0) {
              if (*psVar11 != 0) goto LAB_009114a8;
            }
            else if (*psVar11 == 0) {
LAB_009114a8:
              if ((char)psVar11[3] == '\0') goto LAB_009114ae;
            }
            goto LAB_00911462;
          }
LAB_009114ae:
          if (psVar11[-0x14] == sVar14) {
            if (sVar13 == 0) {
              if (psVar11[1] != 0) goto LAB_009114c9;
            }
            else if (psVar11[1] == 0) {
LAB_009114c9:
              if ((char)psVar11[3] == '\0') goto LAB_009114cf;
            }
LAB_00911462:
            puVar10 = &DAT_00d1bbee + iVar12 * 0x1a;
            if (puVar10 == (uint16_t *)0x0) break;
            goto LAB_0091147a;
          }
LAB_009114cf:
          psVar11 = psVar11 + 0x1a;
          iVar12 = iVar12 + 1;
          if (0xd1d477 < (int)psVar11) {
            return param_2 & 0xff;
          }
        } while( true );
      }
    }
    else {
LAB_0091147a:
      // -----------------------------------------------------------------------
      // SECTION 4: Match → set held (+4) and edge (+5), notify FUN_0093a5c0(1)
      // -----------------------------------------------------------------------
      if (*(char *)(puVar10 + 2) == '\0') {
        *(uint8_t *)(puVar10 + 2) = 1;
        *(uint8_t *)((int)puVar10 + 5) = 1;
        FUN_0093a5c0(1);
      }
    }
    return param_2 & 0xff;
  }

  if (*(char *)((int)pClient + 0x50d) == '\0') {
    *(uint8_t *)((int)pClient + 0x50d) = 1;
    iVar7 = FUN_0090d390();
    if (iVar7 != 0) {
      FUN_0090dab0();
      return 1;
    }
    if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0)) {
      FUN_008012f0();
      return 1;
    }
    if (((DAT_00d1b958 != (int *)0x0) &&
        (cVar2 = (**(code **)(*DAT_00d1b958 + 0x3d8))(), cVar2 != '\0')) &&
       (iVar7 = FUN_008a70c0(), iVar7 != -1)) {
      iVar12 = *DAT_00d1b958;
      uVar8 = FUN_008a70c0();
      (**(code **)(iVar12 + 0x338))(8,uVar8);
      FUN_007fc360();
      return 1;
    }
    if ((DAT_00d1b978 != (int *)0x0) &&
       (cVar2 = (**(code **)(*DAT_00d1b978 + 0x3d8))(), cVar2 != '\0')) {
      (**(code **)(*DAT_00d1b978 + 0x440))();
      (**(code **)(*pClient + 0x3c0))(0);
      (**(code **)(*pClient + 0x1c8))(0);
      return 1;
    }
    if ((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 == DAT_00d1b778)) {
      if (DAT_00d1d900 != -1) {
        FUN_0093bac0(&DAT_00d1a840,0);
        FUN_007fb990();
        return 1;
      }
      if (DAT_00d1d888 != 0) {
        FUN_0093e120(0);
        return 1;
      }
    }
    if ((DAT_00d1b95c == (int *)0x0) ||
       (cVar2 = (**(code **)(*DAT_00d1b95c + 0x3d8))(), cVar2 == '\0')) {
      if ((DAT_00d1b6d8 != 0) && (FUN_00402ae0(&param_2), param_2 != DAT_00d1b568)) {
        do {
          iVar12 = param_2;
          iVar7 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_2 + 0x20),0,
                                  &ClientSpecialEvent::RTTI_Type_Descriptor,
                                  &ClientSpecialEvent_Path::RTTI_Type_Descriptor,0);
          if (iVar7 == 0) {
            FUN_004040a0();
          }
          else {
            piVar15 = *(int **)(iVar12 + 0x20);
            if (piVar15 != (int *)0x0) {
              (**(code **)(*piVar15 + 4))(1);
            }
            FUN_004040a0();
            FUN_00402850(&DAT_00d1b564,&param_3,iVar12);
          }
        } while (param_2 != DAT_00d1b568);
        return 1;
      }
      piVar15 = DAT_00d1b90c;
      if (((DAT_00d1b90c == (int *)0x0) ||
          (cVar2 = (**(code **)(*DAT_00d1b90c + 0x3d8))(), cVar2 == '\0')) || (piVar15[0x143] == -1)
         ) {
        piVar15 = &DAT_00d1b870;
        do {
          if (((piVar15 != &DAT_00d1b8c8) && (piVar1 = (int *)*piVar15, piVar1 != (int *)0x0)) &&
             ((cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0' && (piVar1[0x140] == 1)))) {
            if ((DAT_00d1b8c4 != (int *)0x0) &&
               (cVar2 = (**(code **)(*DAT_00d1b8c4 + 0x3d8))(), cVar2 != '\0')) {
              FUN_007fca10();
              if (DAT_00d1a8e4 == '\0') {
                uVar8 = 0x1e;
              }
              else {
                uVar8 = 0x1d;
              }
              FUN_007fef20(uVar8,1,0);
            }
            piVar15 = &DAT_00d1b870;
            do {
              piVar1 = (int *)*piVar15;
              if (((piVar1 != (int *)0x0) &&
                  (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) && (piVar1[0x140] == 1)
                 ) {
                FUN_007fca10();
              }
              piVar15 = piVar15 + 1;
            } while ((int)piVar15 < 0xd1b958);
            return 1;
          }
          piVar15 = piVar15 + 1;
        } while ((int)piVar15 < 0xd1b958);
      }
      if ((DAT_00d1b780 == (int *)0x0) || (*DAT_00d1b780 != DAT_00d1b778)) {
        if (-1 < pClient[0x127]) {
          uVar9 = (**(code **)(*pClient + 0x338))(8,pClient[0x127]);
          return uVar9;
        }
        goto LAB_009113c1;
      }
      FUN_007fef20(0x29,0,0);
    }
  }
  return 1;
}
