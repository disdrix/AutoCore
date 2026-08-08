// =============================================================================
// FUN_005197b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005197b0
// Address:   0x005197b0  (autoassault.exe, image base 0x400000)
// System:    factions (see EnsureFactionsLookupLoaded.cpp)
// Generated: 2026-07-23 scaffold; refined 2026-08-04 WQ9R-F → EnsureFactionsLookupLoaded
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005197b0 @ 0x005197b0
// Stable ID: aa_005197b0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: ifÃ—11, returnÃ—4, doÃ—3, whileÃ—3, gotoÃ—2.
//  - Notable callees: WideCharToMultiByteÃ—2, freeÃ—2, lstrlenWÃ—2, mallocÃ—2, FUN_004048c0, FUN_004048e0, FUN_005197b0, FUN_0051d290.
//  - Strings: "VOG_DEBUG_STOP".
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

void FUN_005197b0(void)



{

  char cVar1;

  size_t sVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  UINT UVar6;

  char *pcVar7;

  LPCWSTR lpString;

  uint local_134;

  uint8_t local_128 [4];

  void *local_124;

  int local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  char *local_114;

  CHAR local_110 [128];

  char *pcStack_90;

  CHAR aCStack_8c [128];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3683;

  pvStack_c = ExceptionList;

  local_118 = 0;

  ExceptionList = &pvStack_c;

  FUN_0051d290(4);

  local_124 = (void *)0x0;

  local_120 = 0;

  local_11c = 0;

  local_4 = 0;

  FUN_007e1d80();

  iVar4 = FUN_007ce550(&local_118,local_128);

  FUN_007b7df0();

  pvVar3 = local_124;

  if (iVar4 < 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  local_134 = 0;

  lpString = (LPCWSTR)((int)pvVar3 + 0x44);

  do {

    if (local_124 == (void *)0x0) {

      ExceptionList = pvStack_c;

      return;

    }

    if ((uint)((local_120 - (int)local_124) / 0xc4) <= local_134) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_124);

    }

    puVar5 = operator_new(100);

    local_114 = local_110;

    *puVar5 = *(uint32_t /* width from decompiler */ *)(lpString + -0x22);

    UVar6 = (*(code *)PTR_FUN_00af8c9c)();

    if (lpString == (LPCWSTR)0x40) {

      local_114 = (char *)0x0;

    }

    else {

      iVar4 = lstrlenW(lpString + -0x20);

      sVar2 = (iVar4 + 1) * 2;

      if ((0x80 < (int)sVar2) && (local_114 = malloc(sVar2), local_114 == (char *)0x0))

      goto LAB_005198cf;

      iVar4 = WideCharToMultiByte(UVar6,0,lpString + -0x20,iVar4 + 1,local_114,sVar2,(LPCSTR)0x0,

                                  (LPBOOL)0x0);

      if (iVar4 == 0) goto LAB_005199fc;

    }

    pcVar7 = local_114;

    do {

      cVar1 = *pcVar7;

      pcVar7[(int)puVar5 + (4 - (int)local_114)] = cVar1;

      pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    if (local_114 != local_110) {

      free(local_114);

    }

    pcStack_90 = aCStack_8c;

    UVar6 = (*(code *)PTR_FUN_00af8c9c)();

    if (lpString == (LPCWSTR)0x0) {

      pcStack_90 = (char *)0x0;

    }

    else {

      iVar4 = lstrlenW(lpString);

      sVar2 = (iVar4 + 1) * 2;

      if ((0x80 < (int)sVar2) && (pcStack_90 = malloc(sVar2), pcStack_90 == (char *)0x0)) {

LAB_005198cf:

                    /* WARNING: Subroutine does not return */

        FUN_004048e0(0x8007000e);

      }

      iVar4 = WideCharToMultiByte(UVar6,0,lpString,iVar4 + 1,pcStack_90,sVar2,(LPCSTR)0x0,

                                  (LPBOOL)0x0);

      if (iVar4 == 0) {

LAB_005199fc:

        FUN_004048c0();

        return;

      }

    }

    pcVar7 = pcStack_90;

    do {

      cVar1 = *pcVar7;

      pcVar7[(int)puVar5 + (0x24 - (int)pcStack_90)] = cVar1;

      pcVar7 = pcVar7 + 1;

    } while (cVar1 != '\0');

    if (pcStack_90 != aCStack_8c) {

      free(pcStack_90);

    }

    FUN_0051e5d0(*puVar5,puVar5,0);

    local_134 = local_134 + 1;

    lpString = lpString + 0x62;

  } while( true );

}

