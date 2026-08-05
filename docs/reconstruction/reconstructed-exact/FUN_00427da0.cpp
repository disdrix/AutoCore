// =============================================================================
// FUN_00427da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00427da0
// Address:   0x00427da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00427da0 @ 0x00427da0
// Stable ID: aa_00427da0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, do×1, goto×1, while×1.
//  - Notable callees: _CxxThrowException×3, EnterCriticalSection, FUN_00427da0, FUN_007a4480, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ __fastcall FUN_00427da0(uint32_t /* width from decompiler */ param_1,int param_2,int *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be230;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffd0;

  ExceptionList = &local_10;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_3 + 1));

  local_8 = 0;

  if ((char)param_3[10] != '\0') {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    local_18 = 0x80070005;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_18,(ThrowInfo *)&DAT_00acc430);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_3 + 4))(0);

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    local_1c = 0x8007000e;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_1c,(ThrowInfo *)&DAT_00acc430);

  }

  iVar1 = param_3[7];

  if (iVar1 == 0) {

LAB_00427e98:

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(1);

    }

    local_20 = 0x80070057;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_00acc430);

  }

  if (param_2 == *(int *)(iVar1 + 4)) {

    puVar2[2] = iVar1;

    if (param_3[7] != 0) {

      *(uint32_t /* width from decompiler */ **)(param_3[7] + 0xc) = puVar2;

    }

    puVar2[1] = param_1;

    param_3[7] = (int)puVar2;

  }

  else {

    do {

      iVar3 = iVar1;

      if (iVar3 == 0) goto LAB_00427e98;

      iVar1 = *(int *)(iVar3 + 8);

    } while ((iVar1 == 0) || (*(int *)(iVar1 + 4) != param_2));

    *(uint32_t /* width from decompiler */ **)(iVar3 + 8) = puVar2;

    puVar2[3] = iVar3;

    puVar2[2] = iVar1;

    *(uint32_t /* width from decompiler */ **)(iVar1 + 0xc) = puVar2;

    puVar2[1] = param_1;

  }

  if (param_3[8] == 0) {

    param_3[8] = param_3[7];

  }

  param_3[9] = param_3[9] + 1;

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_3 + 1));

  ExceptionList = local_10;

  return 0;

}
