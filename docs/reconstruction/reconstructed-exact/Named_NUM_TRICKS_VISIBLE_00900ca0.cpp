// =============================================================================
// Named_NUM_TRICKS_VISIBLE_00900ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00900ca0
// Address:   0x00900ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_NUM_TRICKS_VISIBLE_00900ca0 @ 0x00900ca0
// Stable ID: aa_00900ca0
// Embedded strings (evidence for future rename):
//   - "TRICK_BUTTON"
//   - "TRICK_ICON"
//   - "TRIM_BUTTON"
//   - "TRIM_ICON"
//   - "NUM_TRICKS_VISIBLE"
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: block×45, _wcsicmp×6, FUN_0040d230×2, SysFreeString×2, swscanf×2, FUN_007933a0, FUN_00900ca0.
//  - Strings: "TRICK_BUTTON"; "TRICK_ICON"; "TRIM_BUTTON"; "TRIM_ICON".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "NUM_TRICKS_VISIBLE"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00900eba) */

/* WARNING: Removing unreachable block (ram,0x00900ed1) */

/* WARNING: Removing unreachable block (ram,0x00900f24) */

/* WARNING: Removing unreachable block (ram,0x00900f37) */

/* WARNING: Removing unreachable block (ram,0x00900f5e) */

/* WARNING: Removing unreachable block (ram,0x00900f71) */

/* WARNING: Removing unreachable block (ram,0x00900f16) */

/* WARNING: Removing unreachable block (ram,0x00900f7d) */

/* WARNING: Removing unreachable block (ram,0x00900f97) */

/* WARNING: Removing unreachable block (ram,0x00900fc9) */

/* WARNING: Removing unreachable block (ram,0x00900fe0) */

/* WARNING: Removing unreachable block (ram,0x0090102a) */

/* WARNING: Removing unreachable block (ram,0x00901041) */

/* WARNING: Removing unreachable block (ram,0x00901094) */

/* WARNING: Removing unreachable block (ram,0x009010a7) */

/* WARNING: Removing unreachable block (ram,0x009010ce) */

/* WARNING: Removing unreachable block (ram,0x009010e1) */

/* WARNING: Removing unreachable block (ram,0x00901086) */

/* WARNING: Removing unreachable block (ram,0x009010ed) */

/* WARNING: Removing unreachable block (ram,0x00901107) */

/* WARNING: Removing unreachable block (ram,0x00901139) */

/* WARNING: Removing unreachable block (ram,0x00901150) */

/* WARNING: Removing unreachable block (ram,0x00900d23) */

/* WARNING: Removing unreachable block (ram,0x00900d3a) */

/* WARNING: Removing unreachable block (ram,0x00900d40) */

/* WARNING: Removing unreachable block (ram,0x00900dac) */

/* WARNING: Removing unreachable block (ram,0x00900dbf) */

/* WARNING: Removing unreachable block (ram,0x00900dcd) */

/* WARNING: Removing unreachable block (ram,0x00900de0) */

/* WARNING: Removing unreachable block (ram,0x00900dec) */

/* WARNING: Removing unreachable block (ram,0x00900d85) */

/* WARNING: Removing unreachable block (ram,0x00900e06) */

/* WARNING: Removing unreachable block (ram,0x00900e38) */

/* WARNING: Removing unreachable block (ram,0x00900e4f) */

/* WARNING: Removing unreachable block (ram,0x0090119a) */

/* WARNING: Removing unreachable block (ram,0x009011b1) */

/* WARNING: Removing unreachable block (ram,0x00901204) */

/* WARNING: Removing unreachable block (ram,0x00901217) */

/* WARNING: Removing unreachable block (ram,0x0090123e) */

/* WARNING: Removing unreachable block (ram,0x00901251) */

/* WARNING: Removing unreachable block (ram,0x009011f6) */

/* WARNING: Removing unreachable block (ram,0x0090125d) */

/* WARNING: Removing unreachable block (ram,0x00901277) */

/* WARNING: Removing unreachable block (ram,0x009012a9) */

/* WARNING: Removing unreachable block (ram,0x009012c0) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_NUM_TRICKS_VISIBLE_00900ca0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  wchar_t *unaff_ESI;

  int iStack_18;

  void *pvStack_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ba9f0;

  local_c = ExceptionList;

  local_4 = 0;

  local_10 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))();

    iVar1 = _wcsicmp(L"TRICK_BUTTON",unaff_ESI);

    if (iVar1 == 0) {

      (**(code **)(*param_2 + 0x30))(param_2);

    }

    else {

      iVar1 = _wcsicmp(L"TRICK_ICON",unaff_ESI);

      if (iVar1 == 0) {

        (**(code **)(*param_2 + 0x30))(param_2);

      }

      else {

        iVar1 = _wcsicmp(L"TRIM_BUTTON",unaff_ESI);

        if (iVar1 == 0) {

          (**(code **)(*param_2 + 0x30))(param_2);

        }

        else {

          iVar1 = _wcsicmp(L"TRIM_ICON",unaff_ESI);

          if (iVar1 == 0) {

            (**(code **)(*param_2 + 0x30))(param_2);

          }

          else {

            iVar1 = _wcsicmp(L"NUM_TRICKS_VISIBLE",unaff_ESI);

            if (iVar1 == 0) {

              FUN_0040d230();

              (**(code **)(*param_2 + 0x68))(param_2);

              iVar1 = swscanf(unaff_ESI,L"%d;%d",&iStack_18);

              if (iVar1 == 2) {

                _DAT_00000000 = _DAT_00000000 - iStack_18;

              }

              *(int *)(param_1 + 0x518) = iStack_18;

            }

            else {

              iVar1 = _wcsicmp(L"NUM_TRIMS_VISIBLE",unaff_ESI);

              if (iVar1 == 0) {

                FUN_0040d230();

                (**(code **)(*param_2 + 0x68))(param_2);

                iVar1 = swscanf(unaff_ESI,L"%d;%d",&iStack_18);

                if (iVar1 == 2) {

                  _DAT_00000000 = _DAT_00000000 - iStack_18;

                }

                *(int *)(param_1 + 0x51c) = iStack_18;

              }

              else {

                FUN_007933a0(param_2);

              }

            }

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
