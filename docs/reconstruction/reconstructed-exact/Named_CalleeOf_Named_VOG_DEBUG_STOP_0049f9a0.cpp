// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0049f9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049f9a0
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0049f9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "Include". Supports parent flow (not a free-standing entry point). Named_VOG_DEBUG_STOP (+1 other named callers).
// Embedded strings (evidence):
//   - "fileName"
//   - "Include"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×14, return×5, goto×2, do×1, while×1.
//  - Notable callees: SysFreeString×3, VariantClear×2, _com_issue_error×2, CoCreateInstance, FUN_00403450, FUN_004048e0, FUN_0049f9a0, FUN_0075e2d0.
//  - Strings: "fileName"; "Include".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Named_CalleeOf_Named_VOG_DEBUG_STOP_0049f9a0(int *param_1)



{

  bool bVar1;

  HRESULT HVar2;

  void *this;

  BSTR bstrString;

  int iVar3;

  int iVar4;

  int *piVar5;

  int **ppiVar6;

  int *pXmlDom;

  char *pszPath;

  BSTR pOVar7;

  int *piVar8;

  int *piStack_3d8;

  int *piStack_3d4;

  uint32_t /* width from decompiler */ uStack_3c0;

  uint8_t auStack_3bc [28];

  uint32_t /* width from decompiler */ uStack_3a0;

  int *piStack_39c;

  int local_398 [28];

  char acStack_328 [16];

  char acStack_318 [260];

  uint8_t auStack_214 [496];

  uint8_t uStack_24;

  void *pvStack_1c;

  int *piStack_18;

  uint8_t uStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ *puStack_4;

  

  puStack_4 = (uint32_t /* width from decompiler */ *)0xffffffff;

  puStack_8 = &LAB_009a0fd1;

  pvStack_c = ExceptionList;

  piStack_3d4 = local_398;

  piStack_3d8 = param_1;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x44))();

  FUN_00798bb0(uStack_3a0,L"fileName");

  piStack_39c = local_398;

  (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(auStack_214);

  strncpy(acStack_318,(char *)piStack_39c,0x103);

  if (piStack_39c != local_398) {

    free(piStack_39c);

  }

  piVar5 = (int *)(auStack_3bc + 4);

  auStack_3bc._4_4_ = 0;

  (**(code **)(*param_1 + 0x2c))(param_1);

  HVar2 = CoCreateInstance((IID *)&DAT_00a0f0e0,(LPUNKNOWN)0x0,1,(IID *)&DAT_00a0f0f0,

                           (LPVOID *)&stack0xfffffc30);

  if (HVar2 < 0) {

    ExceptionList = pvStack_1c;

    return 1;

  }

  piVar8 = (int *)0x0;

  (**(code **)(_DAT_00000000 + 0xfc))(0);

  if (DAT_00b03604 != '\0') {

    FUN_00989e00(&stack0xfffffc3c,acStack_328);

    FUN_0075e2d0(&stack0xfffffc3c);

  }

  pszPath = acStack_328;

  pXmlDom = piStack_3d8;

  this = (void *)FUN_007b6a20();

  bVar1 = NDXml_LoadDocumentFromPath(this,pXmlDom,pszPath);

  if (!bVar1) {

LAB_0049fc8d:

    (**(code **)(*piStack_3d4 + 8))(piStack_3d4);

    ExceptionList = pvStack_1c;

    return 1;

  }

  bstrString = SysAllocString(L"Include");

  if (bstrString == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

    FUN_004048e0(0x8007000e);

  }

  piStack_18 = (int *)0x0;

  pOVar7 = bstrString;

  iVar3 = (**(code **)(*piStack_3d4 + 0xdc))(piStack_3d4,bstrString,&stack0xfffffc30);

  iVar4 = *piVar5;

  if (iVar3 == 0) {

    iVar4 = (**(code **)(iVar4 + 0x1c))(piVar5,0,&piStack_3d8);

    if (iVar4 == 0) {

      iVar3 = (**(code **)(*piStack_3d8 + 0x30))(piStack_3d8,&stack0xfffffc24);

      iVar4 = *piVar5;

      if (iVar3 != 0) goto LAB_0049fcb8;

      iVar4 = (**(code **)(iVar4 + 0x20))(piVar5,&piStack_3d4);

      if ((iVar4 == 0) && (0 < (int)piStack_3d4)) {

        VariantInit((VARIANTARG *)&stack0xfffffc38);

        iVar4 = 0;

        uStack_24 = 1;

        uStack_3c0 = (uint)bstrString & 0xffff0000;

        if (0 < (int)piStack_3d4) {

          do {

            iVar3 = (**(code **)(*piVar5 + 0x1c))(piVar5,0,&piStack_3d8);

            if (iVar3 == 0) {

              ppiVar6 = &piStack_3d8;

              (**(code **)(_DAT_00000000 + 0x48))(0,piStack_3d8,1,0,uStack_3c0,auStack_3bc._0_4_);

              (*(code *)(*ppiVar6)[2])(ppiVar6);

            }

            iVar4 = iVar4 + 1;

          } while (iVar4 < (int)piStack_3d4);

        }

        piVar5 = piStack_18;

        (**(code **)(_DAT_00000000 + 0x30))(0,piStack_18);

        piVar5 = (int *)*piVar5;

        if (piVar5 == (int *)0x0) {

          (**(code **)(*piVar8 + 8))(piVar8);

          (**(code **)(*(int *)pOVar7 + 8))(pOVar7);

          *puStack_4 = 0;

          uStack_14 = 0;

          HVar2 = VariantClear((VARIANTARG *)(auStack_3bc + 4));

          if (HVar2 < 0) {

            _com_issue_error(HVar2);

          }

          SysFreeString(bstrString);

          ExceptionList = pvStack_1c;

          return 0;

        }

        (**(code **)(*piVar5 + 0x20))(piVar5,pvStack_1c);

        (**(code **)(*(int *)pOVar7 + 8))(pOVar7);

        piStack_18 = (int *)((uint)piStack_18 & 0xffffff00);

        HVar2 = VariantClear((VARIANTARG *)auStack_3bc);

        if (HVar2 < 0) {

          _com_issue_error(HVar2);

        }

        piStack_18 = (int *)0xffffffff;

        SysFreeString(bstrString);

        goto LAB_0049fc8d;

      }

    }

    iVar4 = *piVar5;

  }

LAB_0049fcb8:

  (**(code **)(iVar4 + 8))(piVar5);

  (**(code **)(*piVar8 + 8))(piVar8);

  SysFreeString(bstrString);

  ExceptionList = pvStack_1c;

  return 1;

}
