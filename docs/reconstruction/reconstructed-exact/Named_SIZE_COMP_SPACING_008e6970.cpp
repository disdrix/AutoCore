// =============================================================================
// Named_SIZE_COMP_SPACING_008e6970
// -----------------------------------------------------------------------------
// Stable ID: aa_008e6970
// Address:   0x008e6970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_SIZE_COMP_SPACING_008e6970 @ 0x008e6970
// Stable ID: aa_008e6970
// Embedded strings (evidence for future rename):
//   - "START_COMP_BASE"
//   - "START_COMP_ENH1"
//   - "START_COMP_ENH2"
//   - "START_COMP_ENH3"
//   - "START_COMP_ENH4"
//   - "START_COMP_ENH5"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_007a8b00×7, _wcsicmp×7, SysFreeString×2, FUN_007933a0, FUN_008e6970.
//  - Strings: "START_COMP_BASE"; "START_COMP_ENH1"; "START_COMP_ENH2"; "START_COMP_ENH3".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "SIZE_COMP_SPACING"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_SIZE_COMP_SPACING_008e6970(int param_1,int *param_2,int param_3)



{

  int iVar1;

  void *unaff_EBP;

  BSTR unaff_ESI;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ba499;

  local_c = ExceptionList;

  local_10 = 0;

  local_4 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_10);

    iVar1 = _wcsicmp(L"START_COMP_BASE",unaff_ESI);

    if (iVar1 == 0) {

      FUN_007a8b00(param_2,param_1 + 0x78c,param_1 + 0x790,0);

    }

    else {

      iVar1 = _wcsicmp(L"START_COMP_ENH1",unaff_ESI);

      if (iVar1 == 0) {

        FUN_007a8b00(param_2,param_1 + 0x794,param_1 + 0x798,0);

      }

      else {

        iVar1 = _wcsicmp(L"START_COMP_ENH2",unaff_ESI);

        if (iVar1 == 0) {

          FUN_007a8b00(param_2,param_1 + 0x79c,param_1 + 0x7a0,0);

        }

        else {

          iVar1 = _wcsicmp(L"START_COMP_ENH3",unaff_ESI);

          if (iVar1 == 0) {

            FUN_007a8b00(param_2,param_1 + 0x7a4,param_1 + 0x7a8,0);

          }

          else {

            iVar1 = _wcsicmp(L"START_COMP_ENH4",unaff_ESI);

            if (iVar1 == 0) {

              FUN_007a8b00(param_2,param_1 + 0x7ac,param_1 + 0x7b0,0);

            }

            else {

              iVar1 = _wcsicmp(L"START_COMP_ENH5",unaff_ESI);

              if (iVar1 == 0) {

                FUN_007a8b00(param_2,param_1 + 0x7b4,param_1 + 0x7b8,0);

              }

              else {

                iVar1 = _wcsicmp(L"SIZE_COMP_SPACING",unaff_ESI);

                if (iVar1 == 0) {

                  FUN_007a8b00(param_2,param_1 + 0x7bc,param_1 + 0x7c0,0);

                }

                else {

                  FUN_007933a0(param_2,param_3);

                }

              }

            }

          }

        }

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = unaff_EBP;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
