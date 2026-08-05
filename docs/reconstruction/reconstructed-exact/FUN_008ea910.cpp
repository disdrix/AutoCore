// =============================================================================
// FUN_008ea910
// -----------------------------------------------------------------------------
// Stable ID: aa_008ea910
// Address:   0x008ea910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ea910 @ 0x008ea910
// Stable ID: aa_008ea910
// Embedded strings (evidence for future rename):
//   - "MEMBER_WINDOW"
//   - "POWERS_WINDOW"
//   - "SHIELDS_WINDOW"
//   - "DETAILS_WINDOW"
//   - "HEALTHS_WINDOW"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: block×38, _wcsicmp×5, SysFreeString×2, FUN_007933a0, FUN_008ea910.
//  - Strings: "MEMBER_WINDOW"; "POWERS_WINDOW"; "SHIELDS_WINDOW"; "DETAILS_WINDOW".
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

/* WARNING: Removing unreachable block (ram,0x008eabaf) */

/* WARNING: Removing unreachable block (ram,0x008eabc2) */

/* WARNING: Removing unreachable block (ram,0x008eac03) */

/* WARNING: Removing unreachable block (ram,0x008eac1f) */

/* WARNING: Removing unreachable block (ram,0x008eac32) */

/* WARNING: Removing unreachable block (ram,0x008ead4a) */

/* WARNING: Removing unreachable block (ram,0x008ead5d) */

/* WARNING: Removing unreachable block (ram,0x008ead60) */

/* WARNING: Removing unreachable block (ram,0x008eada1) */

/* WARNING: Removing unreachable block (ram,0x008eadbd) */

/* WARNING: Removing unreachable block (ram,0x008eadd0) */

/* WARNING: Removing unreachable block (ram,0x008eac7c) */

/* WARNING: Removing unreachable block (ram,0x008eac90) */

/* WARNING: Removing unreachable block (ram,0x008eacd1) */

/* WARNING: Removing unreachable block (ram,0x008eaced) */

/* WARNING: Removing unreachable block (ram,0x008ead00) */

/* WARNING: Removing unreachable block (ram,0x008ea9c3) */

/* WARNING: Removing unreachable block (ram,0x008ea9da) */

/* WARNING: Removing unreachable block (ram,0x008ea9e0) */

/* WARNING: Removing unreachable block (ram,0x008eaa42) */

/* WARNING: Removing unreachable block (ram,0x008eaa76) */

/* WARNING: Removing unreachable block (ram,0x008eaaaa) */

/* WARNING: Removing unreachable block (ram,0x008eaae1) */

/* WARNING: Removing unreachable block (ram,0x008eaaf4) */

/* WARNING: Removing unreachable block (ram,0x008eab26) */

/* WARNING: Removing unreachable block (ram,0x008eab3c) */

/* WARNING: Removing unreachable block (ram,0x008eaabd) */

/* WARNING: Removing unreachable block (ram,0x008eaa89) */

/* WARNING: Removing unreachable block (ram,0x008eaa55) */

/* WARNING: Removing unreachable block (ram,0x008eaa21) */

/* WARNING: Removing unreachable block (ram,0x008eab4e) */

/* WARNING: Removing unreachable block (ram,0x008eab65) */

/* WARNING: Removing unreachable block (ram,0x008eae1a) */

/* WARNING: Removing unreachable block (ram,0x008eae2d) */

/* WARNING: Removing unreachable block (ram,0x008eae30) */

/* WARNING: Removing unreachable block (ram,0x008eae6b) */

/* WARNING: Removing unreachable block (ram,0x008eae87) */

/* WARNING: Removing unreachable block (ram,0x008eae9a) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_008ea910(void *param_1,int *param_2,int param_3)



{

  int iVar1;

  wchar_t *unaff_EBP;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ba683;

  local_c = ExceptionList;

  local_4 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))();

    iVar1 = _wcsicmp(L"MEMBER_WINDOW",unaff_EBP);

    if (iVar1 == 0) {

      (**(code **)(*param_2 + 0x30))();

    }

    else {

      iVar1 = _wcsicmp(L"POWERS_WINDOW",unaff_EBP);

      if (iVar1 == 0) {

        (**(code **)(*param_2 + 0x30))();

      }

      else {

        iVar1 = _wcsicmp(L"SHIELDS_WINDOW",unaff_EBP);

        if (iVar1 == 0) {

          (**(code **)(*param_2 + 0x30))();

        }

        else {

          iVar1 = _wcsicmp(L"DETAILS_WINDOW",unaff_EBP);

          if (iVar1 == 0) {

            (**(code **)(*param_2 + 0x30))();

          }

          else {

            iVar1 = _wcsicmp(L"HEALTHS_WINDOW",unaff_EBP);

            if (iVar1 == 0) {

              (**(code **)(*param_2 + 0x30))();

            }

            else {

              FUN_007933a0();

            }

          }

        }

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_EBP);

    ExceptionList = param_1;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
