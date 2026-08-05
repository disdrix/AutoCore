// =============================================================================
// FUN_004f1e20
// -----------------------------------------------------------------------------
// Stable ID: aa_004f1e20
// Address:   0x004f1e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f1e20 @ 0x004f1e20
// Stable ID: aa_004f1e20
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
//   - "%S%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_00402d50, FUN_00404ba0, FUN_0043d650, FUN_0043d670, FUN_004a1620, FUN_004a6390.
//  - Strings: "VOG_DEBUG_STOP"; "%S%s".
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

int __thiscall FUN_004f1e20(int param_1,char param_2,char param_3)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  size_t sVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t *puStack_194;

  uint8_t auStack_190 [128];

  char acStack_110 [260];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2b94;

  pvStack_c = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x10);

  ExceptionList = &pvStack_c;

  EnterCriticalSection(lpCriticalSection);

  local_4 = 0;

  if (*(char *)(param_1 + 0x29) == '\0') {

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x3c))(1);

    }

    iVar1 = FUN_0059c000(param_1);

    if (iVar1 != 0) {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

      LeaveCriticalSection(lpCriticalSection);

      ExceptionList = pvStack_c;

      return iVar1;

    }

    if (((param_3 != '\0') && (*(int *)(param_1 + 0x3c) != -0x316)) &&

       (sVar2 = wcslen((wchar_t *)(*(int *)(param_1 + 0x3c) + 0x316)), 1 < sVar2)) {

      if (param_2 != '\0') {

        pvVar3 = operator_new(8);

        local_4._0_1_ = 1;

        if (pvVar3 == (void *)0x0) {

          uVar4 = 0;

        }

        else {

          uVar4 = FUN_004a1620();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = uVar4;

        local_4._0_1_ = 0;

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(param_1 + 0x3c) + 0x316);

        local_4._0_1_ = 2;

        FUN_004a6390(*puVar5);

        local_4 = (uint)local_4._1_3_ << 8;

        if (puStack_194 != auStack_190) {

          free(puStack_194);

        }

      }

      _snprintf(acStack_110,0x104,"%S%s",*(int *)(param_1 + 0x3c) + 0x316,&DAT_009ca184);

      FUN_0043d650(0);

      uVar4 = FUN_00404ba0(acStack_110);

      FUN_0043d670(uVar4);

    }

    *(uint8_t *)(param_1 + 0x29) = 1;

  }

  if (param_2 != '\0') {

    FUN_004f1c70();

  }

  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;

  LeaveCriticalSection(lpCriticalSection);

  ExceptionList = pvStack_c;

  return 0;

}
