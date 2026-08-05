// READABILITY (auto CF):
//  - Body size: ~246 non-empty decompiler lines.
//  - Control keywords: if×29, for×5, do×4, while×4, return×4, goto×2.
//  - Notable callees: FUN_004c50c0×22, FUN_007a4480×4, free×2, FUN_00403450, FUN_004048c0, FUN_004048e0, FUN_0040d4f0, FUN_005320d0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal"; "b_1".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_005320d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005320d0
// Address:   0x005320d0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall Named_VOG_DEBUG_STOP_005320d0(int param_1)



{

  LPCWSTR lpString;

  int *piVar1;

  int iVar2;

  size_t _Size;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  UINT CodePage;

  LPSTR lpMultiByteStr;

  char *pcVar6;

  void *pvVar7;

  int iVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int local_444;

  CHAR local_438 [120];

  uint8_t auStack_3c0 [8];

  char local_3b8 [2];

  uint32_t /* width from decompiler */ local_3b6 [63];

  uint8_t auStack_2b8 [8];

  char local_2b0 [2];

  uint32_t /* width from decompiler */ local_2ae [66];

  char *local_1a4;

  char local_1a0 [128];

  char acStack_120 [268];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a3c8f;

  pvStack_14 = ExceptionList;

  iVar9 = 0;

  local_2b0[0] = '\0';

  local_2b0[1] = '\0';

  puVar10 = local_2ae;

  for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  *(uint16_t *)puVar10 = 0;

  local_3b8[0] = '\0';

  local_3b8[1] = '\0';

  puVar10 = local_3b6;

  for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  *(uint16_t *)puVar10 = 0;

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0x6c + param_1) +

                           0x3c) + 0x538);

  iVar8 = param_1 + -0x40;

  local_444 = 0;

  for (iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) +

                                (*(uint *)(iVar2 + 8) & *(uint *)(param_1 + 0x6b8)) * 4) + 4);

      iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {

    if (*(uint *)(param_1 + 0x6b8) == *(uint *)(iVar2 + 0x10)) {

      if (iVar2 != 0) {

        iVar9 = *(int *)(iVar2 + 8);

      }

      break;

    }

  }

  ExceptionList = &pvStack_14;

  if (iVar9 != 0) {

    local_1a4 = local_1a0;

    ExceptionList = &pvStack_14;

    uVar4 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar9 + 0x10,uVar4);

    pcVar6 = local_1a4;

    iVar9 = -2 - (int)local_1a4;

    pcVar5 = local_1a4;

    do {

      cVar3 = *pcVar5;

      pcVar5[(int)local_3b6 + iVar9] = cVar3;

      pcVar5 = pcVar5 + 1;

    } while (cVar3 != '\0');

    if (pcVar6 != local_1a0) {

      free(pcVar6);

    }

  }

  iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0xac + iVar8) + 0x3c)

                  + 0x538);

  if (*(char *)(iVar9 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar9 + 0x1d) = 1;

  do {

    iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0xac + iVar8) +

                             0x3c) + 0x538);

    if (*(char *)(iVar9 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (local_444 == 0) {

      local_444 = *(int *)(iVar9 + 0x14);

      if (local_444 == 0) goto LAB_0053226b;

      iVar9 = *(int *)(local_444 + 8);

    }

    else {

      local_444 = *(int *)(local_444 + 0x14);

      if (local_444 == 0) {

LAB_0053226b:

        iVar9 = 0;

      }

      else {

        iVar9 = *(int *)(local_444 + 8);

      }

    }

    if (iVar9 == 0) goto LAB_00532365;

    lpString = (LPCWSTR)(iVar9 + 0x10);

    lpMultiByteStr = local_438;

    CodePage = (*(code *)PTR_FUN_00af8c9c)();

    if (lpString == (LPCWSTR)0x0) {

      lpMultiByteStr = (char *)0x0;

    }

    else {

      iVar9 = lstrlenW(lpString);

      _Size = (iVar9 + 1) * 2;

      if ((0x80 < (int)_Size) && (lpMultiByteStr = malloc(_Size), lpMultiByteStr == (LPSTR)0x0)) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0(0x8007000e);

      }

      iVar9 = WideCharToMultiByte(CodePage,0,lpString,iVar9 + 1,lpMultiByteStr,_Size,(LPCSTR)0x0,

                                  (LPBOOL)0x0);

      if (iVar9 == 0) {

        uVar4 = FUN_004048c0();

        return uVar4;

      }

    }

    pcVar6 = lpMultiByteStr;

    do {

      cVar3 = *pcVar6;

      pcVar6[(int)(acStack_120 + -(int)lpMultiByteStr)] = cVar3;

      pcVar6 = pcVar6 + 1;

    } while (cVar3 != '\0');

    if (lpMultiByteStr != local_438) {

      free(lpMultiByteStr);

    }

    pcVar6 = strstr(acStack_120,"b_1");

  } while (pcVar6 == (char *)0x0);

  iVar9 = 0;

  do {

    cVar3 = acStack_120[iVar9];

    *(char *)((int)local_2ae + iVar9 + -2) = cVar3;

    iVar9 = iVar9 + 1;

  } while (cVar3 != '\0');

LAB_00532365:

  *(uint8_t *)

   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0xac + iVar8) + 0x3c) +

            0x538) + 0x1d) = 0;

  FUN_00581730(0);

  if (*(int *)(param_1 + 8) != 0) {

    pvVar7 = operator_new(0x5c);

    uStack_c = 0;

    if (pvVar7 == (void *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = FUN_0074d750();

    }

    uStack_c = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = uVar4;

    pvVar7 = operator_new(0x14);

    uStack_c = 1;

    if (pvVar7 == (void *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = FUN_0040d4f0();

    }

    uStack_c = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

    FUN_0074d420(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

    (**(code **)(**(int **)(param_1 + 0x24) + 4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),0);

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    piVar1 = (int *)(param_1 + 0x2c);

    FUN_004c50c0(0,1,auStack_3c0,uVar4,piVar1);

    if (*piVar1 == 0) {

      FUN_004c50c0(0,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(1,1,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x30) == 0) {

      FUN_004c50c0(1,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(2,1,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x34) == 0) {

      FUN_004c50c0(2,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(9,1,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x50) == 0) {

      FUN_004c50c0(9,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(10,1,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x54) == 0) {

      FUN_004c50c0(10,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(0xb,1,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x58) == 0) {

      FUN_004c50c0(0xb,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(0xc,1,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x5c) == 0) {

      FUN_004c50c0(0xc,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(0xd,0,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x60) == 0) {

      FUN_004c50c0(0xd,0,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(0xe,1,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 100) == 0) {

      FUN_004c50c0(0xe,1,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(0xf,0,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x68) == 0) {

      FUN_004c50c0(0xf,0,auStack_2b8,uVar4,piVar1);

    }

    uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    FUN_004c50c0(0x12,0,auStack_3c0,uVar4,piVar1);

    if (*(int *)(param_1 + 0x74) == 0) {

      FUN_004c50c0(0x12,0,auStack_2b8,uVar4,piVar1);

    }

    cVar3 = (**(code **)(**(int **)(param_1 + 0x24) + 0x18))(*piVar1,0,0x3f800000);

    if (cVar3 != '\0') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

      *(uint8_t *)(param_1 + 0xc) = 1;

      ExceptionList = pvStack_14;

      return 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0xffffffff;

    *(uint8_t *)(param_1 + 0xc) = 0;

  }

  ExceptionList = pvStack_14;

  return 0;

}
