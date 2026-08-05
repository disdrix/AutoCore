// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, for×1.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×3, LeaveCriticalSection×2, CONCAT31, CloseHandle, EnterCriticalSection, FUN_00469910, FUN_00719630.
//  - Strings: "Not replacing %s."; "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp"; "Error: Unable to open file <%s>"; "Added file %s".
//  - Return sites: 2.

// =============================================================================
// Named_assPackManager_00984910
// -----------------------------------------------------------------------------
// Stable ID: aa_00984910
// Address:   0x00984910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assPackManager"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

Named_assPackManager_00984910(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,char param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  DWORD DVar5;

  void *pvVar6;

  BOOL BVar7;

  DWORD *pDVar8;

  DWORD *pDVar9;

  void *local_178;

  int local_174 [2];

  LPCRITICAL_SECTION local_16c;

  int local_168;

  undefined **local_164;

  uint32_t /* width from decompiler */ local_160;

  HANDLE local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  DWORD local_150 [4];

  uint32_t /* width from decompiler */ local_140;

  uint16_t local_13c;

  int local_134;

  DWORD local_130 [6];

  uint local_118;

  uint8_t local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b07af;

  local_c = ExceptionList;

  local_16c = (LPCRITICAL_SECTION)(param_2 + 0x38);

  ExceptionList = &local_c;

  if (*(char *)(param_2 + 0x50) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection(local_16c);

  }

  local_4 = 0;

  FUN_00719630();

  iVar2 = FUN_009835f0();

  if (iVar2 != 0) {

    if ((((param_4 == '\0') &&

         (iVar3 = stat(param_1,&local_134),

         (~-(uint)(iVar3 != 0) & local_118) == *(uint *)(iVar2 + 0xc))) &&

        (iVar3 = FUN_0076ad40(param_1), iVar3 == *(int *)(iVar2 + 8))) &&

       (param_3 == *(short *)(iVar2 + 0x14))) {

      uVar4 = FUN_0076cec0(local_174,"Not replacing %s.",param_1);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0x128,1,uVar4

                    );

      if (*(char *)&local_16c[1].DebugInfo != '\0') {

        LeaveCriticalSection(local_16c);

      }

      ExceptionList = local_c;

      return 1;

    }

    FUN_009847c0(param_6);

  }

  local_164 = &PTR_FUN_00a9d84c;

  local_160 = 0;

  local_15c = (HANDLE)0xffffffff;

  local_158 = 0;

  local_154 = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  iVar2 = FUN_007669d0(param_1,1,0);

  if (iVar2 < 0) {

    uVar4 = FUN_0076cec0(local_174,"Error: Unable to open file <%s>",param_1);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0x163,3,uVar4);

    iVar2 = -1;

  }

  else {

    local_178 = (void *)0x0;

    DVar5 = GetFileSize(local_15c,(LPDWORD)&local_178);

    pvVar6 = operator_new__(DVar5);

    local_178 = pvVar6;

    if (((pvVar6 == (void *)0x0) || (iVar2 = FUN_00766840(pvVar6,DVar5), iVar2 < 0)) ||

       (local_174[0] = FUN_009834f0(), local_174[0] == 0)) {

      iVar2 = -1;

      operator_delete__(pvVar6);

    }

    else {

      local_168 = FUN_0071aaf0(DVar5);

      pvVar6 = operator_new__(local_168 + 1);

      iVar2 = FUN_0071ad70(param_3,&local_168);

      if (-1 < iVar2) {

        local_140 = 0;

        iVar2 = FUN_007199e0(local_110,pvVar6,local_168,local_150);

        local_13c = (uint16_t)param_3;

        local_150[2] = DVar5;

        local_150[3] = FUN_0076ad70();

        FUN_00989e00(local_174,local_110);

        local_134 = local_174[0];

        pDVar8 = local_150;

        pDVar9 = local_130;

        for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {

          *pDVar9 = *pDVar8;

          pDVar8 = pDVar8 + 1;

          pDVar9 = pDVar9 + 1;

        }

        FUN_00469910(local_174,&local_134);

      }

      operator_delete__(pvVar6);

      operator_delete__(local_178);

    }

  }

  uVar4 = FUN_0076cec0(local_174,"Added file %s",local_110);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assPackManager.cpp",0x166,1,uVar4);

  cVar1 = (*(code *)local_164[8])();

  if ((cVar1 == '\0') || (BVar7 = CloseHandle(local_15c), BVar7 != 0)) {

    local_15c = (HANDLE)0xffffffff;

  }

  local_4 = local_4 & 0xffffff00;

  FUN_00766750();

  if (*(char *)&local_16c[1].DebugInfo != '\0') {

    LeaveCriticalSection(local_16c);

  }

  ExceptionList = local_c;

  return iVar2;

}
