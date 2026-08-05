// =============================================================================
// FUN_005ea300
// -----------------------------------------------------------------------------
// Stable ID: aa_005ea300
// Address:   0x005ea300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ea300 @ 0x005ea300
// Stable ID: aa_005ea300
// Embedded strings (evidence for future rename):
//   - "Could not locate the following map module: %s"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapModule.cpp"
//   - "VOG_DEBUG_STOP"
//   - "In Module(%xh) Dropped map object of COID:%xh CBID:%xh bytes:%xh pObj:%xh hr:%xh\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×10, do×4, while×4, for×3, goto×1, return×1.
//  - Notable callees: FUN_007a4480×3, CARRY4×2, FUN_00513880×2, FUN_005e9ef0×2, FUN_00766750×2, CVOGReaction_GiveItemByCbid, CVOGReaction_RemoveObject, FUN_00418d70.
//  - Strings: "Could not locate the following map module: %s"; "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapModule.cpp"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __fastcall FUN_005ea300(int param_1)



{

  char *pcVar1;

  uint *puVar2;

  uint uVar3;

  void *this;

  char cVar4;

  char *pcVar5;

  uint uVar6;

  int *piVar7;

  int iVar8;

  uint uVar9;

  int unaff_EBP;

  int *piVar10;

  uint unaff_ESI;

  char *pcVar11;

  int unaff_EDI;

  uint32_t /* width from decompiler */ *puVar12;

  char *pcVar13;

  uint32_t /* width from decompiler */ uVar14;

  uint8_t *puVar15;

  int iParam;

  uint *puVar16;

  uint32_t /* width from decompiler */ uVar17;

  int local_28c;

  int iStack_288;

  int iStack_284;

  void *local_280;

  int iStack_278;

  uint uStack_26c;

  int iStack_268;

  uint8_t auStack_25c [31];

  char cStack_23d;

  char local_23c [2];

  uint32_t /* width from decompiler */ uStack_23a;

  char local_138 [280];

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint8_t uStack_14;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a77e3;

  local_c = ExceptionList;

  piVar10 = (int *)0x0;

  local_23c[0] = '\0';

  local_23c[1] = '\0';

  puVar12 = &uStack_23a;

  for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar12 = 0;

    puVar12 = puVar12 + 1;

  }

  *(uint16_t *)puVar12 = 0;

  pcVar1 = (char *)(param_1 + 0x20);

  pcVar5 = pcVar1;

  do {

    cVar4 = *pcVar5;

    pcVar5 = pcVar5 + 1;

  } while (cVar4 != '\0');

  pcVar13 = &cStack_23d;

  do {

    pcVar11 = pcVar13 + 1;

    pcVar13 = pcVar13 + 1;

  } while (*pcVar11 != '\0');

  pcVar11 = pcVar1;

  for (uVar9 = (uint)((int)pcVar5 - (int)pcVar1) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar13 = *(uint32_t /* width from decompiler */ *)pcVar11;

    pcVar11 = pcVar11 + 4;

    pcVar13 = pcVar13 + 4;

  }

  for (uVar9 = (int)pcVar5 - (int)pcVar1 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

    *pcVar13 = *pcVar11;

    pcVar11 = pcVar11 + 1;

    pcVar13 = pcVar13 + 1;

  }

  pcVar1 = &cStack_23d;

  do {

    pcVar5 = pcVar1;

    pcVar1 = pcVar5 + 1;

  } while (pcVar5[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = DAT_009dcdcc;

  pcVar5[5] = DAT_009dcdd0;

  ExceptionList = &local_c;

  local_28c = param_1;

  FUN_007667d0();

  local_4 = 0;

  iVar8 = FUN_007669d0(local_23c,1,0x8000000);

  if (iVar8 < 0) {

    sprintf(local_138,"Could not locate the following map module: %s",local_23c);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapModule.cpp",0x8a,3,local_138);

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    local_4 = 0xffffffff;

    FUN_00766750();

    uVar17 = 0;

  }

  else {

    iVar8 = FUN_0076ad40();

    local_280 = operator_new(0x18);

    local_4._0_1_ = 1;

    if (local_280 != (void *)0x0) {

      piVar10 = (int *)FUN_0076c0b0(iVar8);

    }

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_00766840(piVar10[1],iVar8);

    piVar10[3] = iVar8;

    (**(code **)(*piVar10 + 8))();

    iStack_278 = FUN_005e9e40(piVar10);

    uVar17 = 4;

    puVar2 = (uint *)(param_1 + 0x10);

    puVar16 = puVar2;

    (**(code **)(*piVar10 + 0x14))(puVar2,4);

    iParam = 4;

    puVar15 = auStack_25c;

    (**(code **)(*piVar10 + 0x14))();

    FUN_00513880(piVar10,&uStack_26c);

    iVar8 = (int)*puVar2 >> 0x1f;

    if ((iVar8 <= iStack_268) && ((iVar8 < iStack_268 || (*puVar2 < uStack_26c)))) {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    this = local_c;

    uVar9 = *(uint *)((int)local_c + 0xe6d8);

    uVar6 = uVar9 - 1;

    iStack_278 = *(int *)((int)local_c + 0xe6dc) - (uint)(uVar9 == 0);

    uVar3 = *(uint *)(unaff_EDI + 0x10);

    *(uint *)((int)local_c + 0xe6d8) = uVar3 + uVar9;

    *(uint *)((int)local_c + 0xe6dc) =

         ((int)uVar3 >> 0x1f) + *(int *)((int)local_c + 0xe6dc) + (uint)CARRY4(uVar3,uVar9);

    local_28c = 0;

    FUN_005743e0(0,0,0);

    iVar8 = 0;

    if (0 < *(int *)(unaff_EDI + 0x10)) {

      do {

        uVar14 = 4;

        (**(code **)(*piVar10 + 0x14))(&stack0xfffffd68,4);

        FUN_00513880(piVar10,&local_28c);

        (**(code **)(*piVar10 + 0x14))(&stack0xfffffd64,4);

        piVar7 = (int *)CVOGReaction_GiveItemByCbid(iParam);

        if ((piVar7 == (int *)0x0) ||

           (unaff_EDI = (**(code **)(*piVar7 + 8))(iParam,this,1), unaff_EDI < 0)) {

          *(uint8_t *)((int)this + 0x7f) = 1;

          FUN_007a4480(1,

                       "In Module(%xh) Dropped map object of COID:%xh CBID:%xh bytes:%xh pObj:%xh hr:%xh\n"

                       ,*(uint32_t /* width from decompiler */ *)(puVar15 + 0x1c),unaff_EBP,iVar8,iParam,puVar16,piVar7,

                       unaff_EDI);

          (**(code **)(*piVar10 + 4))(puVar16,1);

          if (piVar7 != (int *)0x0) {

            (**(code **)*piVar7)(1);

          }

        }

        else {

          *(uint8_t *)(piVar7 + 0x5e) = uStack_14;

          (**(code **)(*piVar7 + 0x218))(this);

          FUN_00512160(unaff_ESI + uVar6,unaff_EBP + local_28c + (uint)CARRY4(unaff_ESI,uVar6),0);

          iStack_284 = piVar7[0x59];

          iStack_288 = piVar7[0x58];

          FUN_00418d70(&iStack_288);

          if ((*(int *)(piVar7[0x2a] + 0x38) == 3) && (*(char *)((int)this + 0x100) != '\0')) {

            *(byte *)((int)piVar7 + 0x17d) = *(byte *)((int)piVar7 + 0x17d) | 0x10;

          }

          if (*(uint32_t /* width from decompiler */ **)((int)this + 0xe504) == (uint32_t /* width from decompiler */ *)0x0) {

            (**(code **)(*piVar7 + 0xa4))(piVar10,unaff_EDI,uStack_1c,1);

            (**(code **)(*piVar7 + 0x34))(uVar6,unaff_EDI);

            (**(code **)(*piVar7 + 0x2a4))(*(uint32_t /* width from decompiler */ *)((int)this + 0xe4e8));

            (**(code **)(*piVar7 + 0xb4))();

          }

          else {

            cVar4 = (**(code **)**(uint32_t /* width from decompiler */ **)((int)this + 0xe504))(piVar7);

            if (cVar4 == '\0') {

              (**(code **)*piVar7)(1);

              (**(code **)(*piVar10 + 4))(uVar14,1);

              FUN_005e9ef0(0,this,puStack_8);

              goto LAB_005ea749;

            }

            (**(code **)(*piVar7 + 0xa4))(piVar10,uVar17,uStack_20);

            (**(code **)(*piVar7 + 0xb4))();

            (**(code **)(*piVar7 + 0x34))(uVar6,uVar17);

          }

          if (((uint)piVar7[0x5f] >> 9 & 1) == 0) {

            CVOGReaction_RemoveObject(this,piVar7[0x58],piVar7[0x59],'\0');

          }

          FUN_005e9ef0(piVar7,this,puStack_8);

        }

LAB_005ea749:

        iVar8 = iVar8 + 1;

      } while (iVar8 < *(int *)(unaff_EDI + 0x10));

    }

    (**(code **)*piVar10)(1);

    local_4 = 0xffffffff;

    FUN_00766750();

    uVar17 = 1;

  }

  ExceptionList = local_c;

  return uVar17;

}
