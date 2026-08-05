// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×15, return×9, goto×1.
//  - Notable callees: _CxxThrowException×7, FUN_004bc680×4, CVOGReaction_FailMissionNotify×2, FUN_007a4480×2, CNDHash_LookupByKey, FUN_004bc180, FUN_004bcb40, FUN_004bd1d0.
//  - Strings: "VOG_DEBUG_STOP"; "object %I64d (%d) is already listed".
//  - Return sites: 9.

// =============================================================================
// Mission_VOG_DEBUG_STOP
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "VOG_DEBUG_STOP"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004bc180 clean capture (not modernized).
//
// Address:  0x004bc180  (autoassault.exe, image base 0x400000)
// Stable:   aa_004bc180
// Stable ID: aa_004bc180
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004bc180_*.md
//           Original Ghidra symbol: FUN_004bc180
//
// Exactness: Body mirrors reconstructed-exact/FUN_004bc180*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_VOG_DEBUG_STOP
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc180
// Address:   0x004bc180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Type propagation algorithm not settling */



uint32_t /* width from decompiler */ __thiscall Mission_VOG_DEBUG_STOP(int param_1,int *param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint key;

  void *pvVar4;

  uint32_t /* width from decompiler */ local_34;

  int local_30;

  int local_2c;

  int local_28 [5];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  piVar1 = param_2;

  puStack_c = &LAB_009a174c;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffbc;

  iVar3 = param_2[0x59];

  local_8 = 0;

  if ((iVar3 < 1) && ((iVar3 < 0 || (param_2[0x58] == 0)))) {

    ExceptionList = &local_10;

    local_14 = &stack0xffffffbc;

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    local_28[3] = 0x80070057;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_28 + 3,(ThrowInfo *)&DAT_00acc430);

  }

  if ((char)param_2[0x5a] == '\0') {

    if (*(char *)(param_1 + 0xd) == '\0') {

      local_34 = 0x80070057;

      ExceptionList = &local_10;

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_34,(ThrowInfo *)&DAT_00acc430);

    }

  }

  else if (*(char *)(param_1 + 0xc) == '\0') {

    local_28[2] = 0x80070057;

    ExceptionList = &local_10;

    local_14 = &stack0xffffffbc;

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_28 + 2,(ThrowInfo *)&DAT_00acc430);

  }

  ExceptionList = &local_10;

  local_14 = &stack0xffffffbc;

  iVar3 = FUN_004e77d0(param_2[0x58],iVar3,param_2,0);

  if (iVar3 != 0) {

    FUN_007a4480(1,"object %I64d (%d) is already listed",piVar1[0x58],piVar1[0x59],

                 *(uint32_t /* width from decompiler */ *)(piVar1[0x2a] + 0x34));

    ExceptionList = local_10;

    return 0;

  }

  iVar3 = (**(code **)(*piVar1 + 0x208))();

  if (iVar3 == 0) {

    key = *(uint *)(piVar1[0x2a] + 0x38);

  }

  else {

    key = 0x30;

  }

  pvVar4 = CNDHash_LookupByKey(*(void **)(param_1 + 0x18),key);

  if (pvVar4 == (void *)0x0) {

    pvVar4 = operator_new(0x2c);

    if ((pvVar4 == (void *)0x0) || (iVar3 = FUN_004bcb40(), iVar3 == 0)) {

      local_28[1] = 0x8007000e;

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_28 + 1,(ThrowInfo *)&DAT_00acc430);

    }

    FUN_004bd1d0(*(uint32_t /* width from decompiler */ *)(piVar1[0x2a] + 0x38),iVar3,0);

  }

  FUN_004bc680(piVar1,local_28 + 4);

  piVar1[0x37] = local_28[4];

  if ((*(int *)(piVar1[0x2a] + 0x38) == 0x12) ||

     (((*(int *)(piVar1[0x2a] + 0x38) == 0xe &&

       (iVar3 = (**(code **)(*piVar1 + 0x1d4))(), iVar3 != 0)) &&

      (iVar3 = (**(code **)(*piVar1 + 0x1d4))(), *(char *)(iVar3 + 0x2ac) == '\0')))) {

    local_28[0] = FUN_004bc680(piVar1,local_28 + 4);

    if (local_28[0] < 0) {

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(local_28,(ThrowInfo *)&DAT_00acc430);

    }

    piVar1[0x34] = local_28[4];

  }

  else if (*(int *)(piVar1[0x2a] + 0x38) != 0x14) goto LAB_004bc376;

  CVOGReaction_FailMissionNotify(&param_2);

LAB_004bc376:

  cVar2 = FUN_005130e0(1);

  if (cVar2 != '\0') {

    local_2c = FUN_004bc680(piVar1,local_28 + 4);

    if (local_2c < 0) {

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_2c,(ThrowInfo *)&DAT_00acc430);

    }

    piVar1[0x35] = local_28[4];

  }

  if (((uint)piVar1[0x5f] >> 5 & 1) != 0) {

    local_30 = FUN_004bc680(piVar1,local_28 + 4);

    if (local_30 < 0) {

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_30,(ThrowInfo *)&DAT_00acc430);

    }

    piVar1[0x36] = local_28[4];

    CVOGReaction_FailMissionNotify(&param_2);

  }

  ExceptionList = local_10;

  return 0;

}
