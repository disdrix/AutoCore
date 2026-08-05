// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: block×52, _wcsicmp×8, FUN_007a8b00×2, SysFreeString×2, FUN_007fa8d0.
//  - Strings: "ACCURACY_ADJUST"; "COMBAT_ACCURACY_ADJUST"; "CURSOR"; "CURSOR_COMBAT".
//  - Return sites: 2.

// =============================================================================
// Named_COMBAT_ACCURACY_ADJUST_007fa8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fa8d0
// Address:   0x007fa8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "COMBAT_ACCURACY_ADJUST"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007faaf8) */

/* WARNING: Removing unreachable block (ram,0x007fab0f) */

/* WARNING: Removing unreachable block (ram,0x007fab15) */

/* WARNING: Removing unreachable block (ram,0x007fab60) */

/* WARNING: Removing unreachable block (ram,0x007fab73) */

/* WARNING: Removing unreachable block (ram,0x007fab7e) */

/* WARNING: Removing unreachable block (ram,0x007fab91) */

/* WARNING: Removing unreachable block (ram,0x007faba4) */

/* WARNING: Removing unreachable block (ram,0x007fabb7) */

/* WARNING: Removing unreachable block (ram,0x007fabca) */

/* WARNING: Removing unreachable block (ram,0x007fabdd) */

/* WARNING: Removing unreachable block (ram,0x007fabe5) */

/* WARNING: Removing unreachable block (ram,0x007fabf8) */

/* WARNING: Removing unreachable block (ram,0x007fac08) */

/* WARNING: Removing unreachable block (ram,0x007fac1b) */

/* WARNING: Removing unreachable block (ram,0x007fac2b) */

/* WARNING: Removing unreachable block (ram,0x007fac3e) */

/* WARNING: Removing unreachable block (ram,0x007fac44) */

/* WARNING: Removing unreachable block (ram,0x007fab50) */

/* WARNING: Removing unreachable block (ram,0x007fac4c) */

/* WARNING: Removing unreachable block (ram,0x007fac51) */

/* WARNING: Removing unreachable block (ram,0x007fac68) */

/* WARNING: Removing unreachable block (ram,0x007facc0) */

/* WARNING: Removing unreachable block (ram,0x007facdb) */

/* WARNING: Removing unreachable block (ram,0x007face5) */

/* WARNING: Removing unreachable block (ram,0x007fad37) */

/* WARNING: Removing unreachable block (ram,0x007fad4a) */

/* WARNING: Removing unreachable block (ram,0x007fad5a) */

/* WARNING: Removing unreachable block (ram,0x007fad71) */

/* WARNING: Removing unreachable block (ram,0x007fad88) */

/* WARNING: Removing unreachable block (ram,0x007fad9f) */

/* WARNING: Removing unreachable block (ram,0x007fadb6) */

/* WARNING: Removing unreachable block (ram,0x007fadcd) */

/* WARNING: Removing unreachable block (ram,0x007fade4) */

/* WARNING: Removing unreachable block (ram,0x007fadfb) */

/* WARNING: Removing unreachable block (ram,0x007fae12) */

/* WARNING: Removing unreachable block (ram,0x007fae35) */

/* WARNING: Removing unreachable block (ram,0x007fae58) */

/* WARNING: Removing unreachable block (ram,0x007fae72) */

/* WARNING: Removing unreachable block (ram,0x007fae92) */

/* WARNING: Removing unreachable block (ram,0x007faeb2) */

/* WARNING: Removing unreachable block (ram,0x007faec5) */

/* WARNING: Removing unreachable block (ram,0x007faea5) */

/* WARNING: Removing unreachable block (ram,0x007fae85) */

/* WARNING: Removing unreachable block (ram,0x007fae6b) */

/* WARNING: Removing unreachable block (ram,0x007faeca) */

/* WARNING: Removing unreachable block (ram,0x007fae48) */

/* WARNING: Removing unreachable block (ram,0x007fae25) */

/* WARNING: Removing unreachable block (ram,0x007fad2a) */

/* WARNING: Removing unreachable block (ram,0x007faed0) */

/* WARNING: Removing unreachable block (ram,0x007faed6) */

/* WARNING: Removing unreachable block (ram,0x007faef5) */



void __thiscall Named_COMBAT_ACCURACY_ADJUST_007fa8d0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  wchar_t *unaff_ESI;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b153a;

  local_c = ExceptionList;

  local_4 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))();

    iVar1 = _wcsicmp(L"ACCURACY_ADJUST",unaff_ESI);

    if (iVar1 == 0) {

      FUN_007a8b00(param_2,&uStack_1c,&uStack_18);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4a4) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4a8) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4ac) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b0) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c0) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c4) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c8) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4cc) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4d0) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4d4) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4d8) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4dc) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x4e0) = uStack_18;

    }

    else {

      iVar1 = _wcsicmp(L"COMBAT_ACCURACY_ADJUST",unaff_ESI);

      if (iVar1 == 0) {

        FUN_007a8b00(param_2,&uStack_1c,&uStack_18);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = uStack_18;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x54c) = uStack_18;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x550) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = uStack_18;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x558) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x55c) = uStack_18;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x560) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x564) = uStack_18;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = uStack_18;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x574) = uStack_18;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x578) = uStack_1c;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x57c) = uStack_18;

      }

      else {

        iVar1 = _wcsicmp(L"CURSOR",unaff_ESI);

        if ((iVar1 == 0) || (iVar1 = _wcsicmp(L"CURSOR_COMBAT",unaff_ESI), iVar1 == 0)) {

          _wcsicmp(L"CURSOR_COMBAT",unaff_ESI);

          (**(code **)(*param_2 + 0x30))(param_2);

        }

        else {

          iVar1 = _wcsicmp(L"CURSOR_ACCURACY",unaff_ESI);

          if ((iVar1 == 0) || (iVar1 = _wcsicmp(L"CURSOR_COMBAT_ACCURACY",unaff_ESI), iVar1 == 0)) {

            _wcsicmp(L"CURSOR_COMBAT_ACCURACY",unaff_ESI);

            (**(code **)(*param_2 + 0x30))(param_2);

          }

        }

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = pvStack_14;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
