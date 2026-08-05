// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_007b80f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b80f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x007b80f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper. Evidence string: "CBR: Polling adapters\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CBR: Polling adapters\n"
//   - "CBR: Return Code %d\n"
//   - "None found."
//   - "CBR: Entering XML pathway\n"
//   - "file:///"
//   - "wad.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~275 non-empty decompiler lines.
//  - Control keywords: if×33, return×5, for×2, goto×2, do×1, while×1.
//  - Notable callees: _com_issue_error×12, OutputDebugStringA×8, FUN_0041a070×4, SysFreeString×4, FUN_007a4480×3, FUN_004048e0×2, FUN_004235b0×2, SysAllocString×2.
//  - Strings: "CBR: Polling adapters\n"; "CBR: Return Code %d\n"; "None found."; "CBR: Entering XML pathway\n".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_007b80f0(uint8_t *param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  BSTR pOVar1;

  IUnknown *pIVar2;

  char cVar3;

  short sVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  BSTR pOVar7;

  size_t sVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint8_t **ppuVar10;

  HRESULT HVar11;

  int *piVar12;

  int *piVar13;

  int *unaff_EBX;

  wchar_t *_Dest;

  uint32_t /* width from decompiler */ unaff_ESI;

  BSTR unaff_EDI;

  uint32_t /* width from decompiler */ *puVar14;

  bool bVar15;

  LPUNKNOWN *bstrString;

  void **ppvObject;

  int *piVar16;

  LPUNKNOWN pIStack_834;

  BSTR local_830;

  uint32_t /* width from decompiler */ *local_82c;

  uint32_t /* width from decompiler */ local_828;

  LPCRITICAL_SECTION local_824;

  int aiStack_820 [2];

  uint32_t /* width from decompiler */ local_818;

  wchar_t *local_814;

  _union_2683 _Stack_810;

  uint8_t **ppuStack_800;

  uint8_t *local_7fc;

  uint8_t local_7f8 [128];

  uint32_t /* width from decompiler */ local_778 [128];

  uint32_t /* width from decompiler */ local_578;

  int local_558;

  char local_418 [508];

  char acStack_21c [488];

  void *pvStack_34;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_1c;

  void *pvStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009acf1e;

  pvStack_14 = ExceptionList;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);

  local_828 = 0;

  ExceptionList = &pvStack_14;

  local_824 = lpCriticalSection;

  InitializeCriticalSection(lpCriticalSection);

  EnterCriticalSection(lpCriticalSection);

  bVar15 = DAT_00d1793c == '\0';

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *param_1 = 0;

  local_818 = 0xc80;

  if (bVar15) {

    puVar5 = operator_new__(0x1f4000);

    local_82c = puVar5;

    OutputDebugStringA("CBR: Polling adapters\n");

    iVar6 = GetAdaptersInfo(puVar5,&local_818);

    sprintf(local_418,"CBR: Return Code %d\n",iVar6);

    OutputDebugStringA(local_418);

    local_830 = SysAllocString(L"");

    if (local_830 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0(0x8007000e);

    }

    local_c = 0;

    puVar14 = puVar5;

    pOVar1 = local_830;

    if (iVar6 != 0) {

      FUN_004235b0(L"None found.");

      pOVar1 = local_830;

    }

    for (; pOVar7 = local_830, local_830 = pOVar1, puVar5 != (uint32_t /* width from decompiler */ *)0x0;

        puVar5 = (uint32_t /* width from decompiler */ *)*puVar5) {

      if (puVar5[0x68] == 6) {

        puVar14 = local_778;

        for (iVar6 = 0xd7; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar14 = 0;

          puVar14 = puVar14 + 1;

        }

        local_578 = puVar5[0x67];

        iVar6 = GetIfEntry(local_778);

        puVar14 = local_82c;

        if ((iVar6 == 0) && (local_558 == 5)) {

          SysFreeString(pOVar7);

          pOVar7 = (BSTR)FUN_004234e0(puVar5 + 0x6c,0xffffffff);

          puVar14 = local_82c;

          local_830 = pOVar7;

          if ((pOVar7 == (BSTR)0x0) && (puVar5 + 0x6c != (uint32_t /* width from decompiler */ *)0x0)) {

                    /* WARNING: Subroutine does not return */

            FUN_004048e0(0x8007000e);

          }

          break;

        }

      }

      pOVar1 = local_830;

      local_830 = pOVar7;

    }

    operator_delete__(puVar14);

    cVar3 = FUN_00423620(&local_830);

    if (cVar3 != '\0') {

      FUN_004235b0(L"None found.");

      pOVar7 = local_830;

    }

    sVar8 = wcslen((wchar_t *)&DAT_00d09e80);

    if (sVar8 == 0) {

      swprintf((wchar_t *)(param_1 + 0x2c),0xa95718,(wchar_t *)&DAT_00d0a088);

    }

    else {

      swprintf((wchar_t *)(param_1 + 0x2c),0xa958b8,(wchar_t *)&DAT_00d09e80,&DAT_00d09c78);

    }

    local_c = 0xffffffff;

    SysFreeString(pOVar7);

    if (DAT_00d1793c == '\0') goto LAB_007b8736;

  }

  OutputDebugStringA("CBR: Entering XML pathway\n");

  _Dest = (wchar_t *)(param_1 + 0x2c);

  local_814 = _Dest;

  wcscpy(_Dest,L"file:///");

  wcscat(_Dest,(wchar_t *)&DAT_00d09a70);

  wcscat(_Dest,L"wad.xml");

  local_7fc = local_7f8;

  ppvObject = (void **)0x7b8348;

  uVar9 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(_Dest,uVar9);

  ppuVar10 = ppuStack_800;

  do {

    cVar3 = *(char *)ppuVar10;

    *(char *)((int)ppuVar10 + ((int)(param_1 + 0x44c) - (int)ppuStack_800)) = cVar3;

    ppuVar10 = (uint8_t **)((int)ppuVar10 + 1);

  } while (cVar3 != '\0');

  if (ppuStack_800 != &local_7fc) {

    free(ppuStack_800);

  }

  sprintf(acStack_21c,"Loading XML String: %s\n",param_1 + 0x44c);

  OutputDebugStringA(acStack_21c);

  if (DAT_00d1e56c != (IUnknown *)0x0) {

    (*DAT_00d1e56c->lpVtbl->Release)(DAT_00d1e56c);

  }

  puVar5 = (uint32_t /* width from decompiler */ *)

           CoCreateInstance((IID *)&DAT_00a86108,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00a14100,

                            &pIStack_834);

  if ((int)puVar5 < 0) {

LAB_007b840d:

    DAT_00d1e56c = (IUnknown *)0x0;

  }

  else {

    puVar5 = (uint32_t /* width from decompiler */ *)OleRun(pIStack_834);

    if (-1 < (int)puVar5) {

      puVar5 = (uint32_t /* width from decompiler */ *)

               (*pIStack_834->lpVtbl->QueryInterface)

                         (pIStack_834,(IID *)&DAT_00a0f0f0,&DAT_00d1e56c);

    }

    (*pIStack_834->lpVtbl->Release)(pIStack_834);

    if ((int)puVar5 < 0) goto LAB_007b840d;

  }

  local_82c = puVar5;

  OutputDebugStringA("CreateInstance called\n");

  if ((int)puVar5 < 0) {

    FUN_007a4480(1,"DBReader: %u against %s",0x80040e03,

                 "ICloneBaseReader::FinalConstruct failed to create an instance of DOMDocument60.");

    ExceptionList = pvStack_18;

    return 0;

  }

  if (DAT_00d1e56c == (IUnknown *)0x0) {

    _com_issue_error(-0x7fffbffd);

  }

  pIVar2 = DAT_00d1e56c;

  HVar11 = (*DAT_00d1e56c->lpVtbl[0x15].QueryInterface)(DAT_00d1e56c,(IID *)0x0,ppvObject);

  if (HVar11 < 0) {

    _com_issue_errorex(HVar11,pIVar2,(_GUID *)&DAT_00a86138);

  }

  OutputDebugStringA("\n\n\tLoading wad.xml....\n\n");

  _Stack_810.n2.vt = 8;

  _Stack_810._8_4_ = SysAllocString(_Dest);

  if (((BSTR)_Stack_810._8_4_ == (BSTR)0x0) && (_Dest != (wchar_t *)0x0)) {

    _com_issue_error(-0x7ff8fff2);

  }

  local_c = 1;

  if (DAT_00d1e56c == (IUnknown *)0x0) {

    _com_issue_error(-0x7fffbffd);

  }

  sVar4 = FUN_0041a020();

  local_c = 0xffffffff;

  HVar11 = VariantClear((VARIANTARG *)&_Stack_810.n2);

  if (HVar11 < 0) {

    _com_issue_error(HVar11);

  }

  if (sVar4 != -1) {

    aiStack_820[0] = 0;

    if (DAT_00d1e56c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    piVar12 = (int *)FUN_0041a070();

    local_c = 2;

    if (*piVar12 == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    piVar12 = (int *)*piVar12;

    piVar16 = aiStack_820;

    (**(code **)(*piVar12 + 0x20))();

    pvStack_14 = (void *)0xffffffff;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))(unaff_EBX);

    }

    pIStack_834 = (LPUNKNOWN)0x0;

    if (DAT_00d1e56c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    piVar13 = (int *)FUN_0041a070();

    pvStack_14 = (void *)0x3;

    if (*piVar13 == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    bstrString = &pIStack_834;

    (**(code **)(*(int *)*piVar13 + 0x24))((int *)*piVar13);

    uStack_1c = 0xffffffff;

    if (unaff_EDI != (BSTR)0x0) {

      (**(code **)(*(int *)unaff_EDI + 8))(unaff_EDI);

    }

    if (DAT_00d1e56c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    piVar13 = (int *)FUN_0041a070();

    uStack_1c = 4;

    if (*piVar13 == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    (**(code **)(*(int *)*piVar13 + 0x2c))((int *)*piVar13,&stack0xfffff7c8);

    uStack_24 = 0xffffffff;

    if (piVar12 != (int *)0x0) {

      (**(code **)(*piVar12 + 8))(piVar12);

    }

    pIStack_834 = (LPUNKNOWN)0x0;

    if (DAT_00d1e56c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    piVar13 = (int *)FUN_0041a070();

    uStack_24 = 5;

    if (*piVar13 == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    (**(code **)(*(int *)*piVar13 + 0x30))((int *)*piVar13,&pIStack_834);

    uStack_2c = 0xffffffff;

    if (piVar16 != (int *)0x0) {

      (**(code **)(*piVar16 + 8))(piVar16);

    }

    FUN_007a4480(1,"%S(%i)(%S): pos %i, XML parse error: %S",unaff_EDI,piVar12,pIStack_834,unaff_ESI

                 ,bstrString);

    SysFreeString(unaff_EDI);

    SysFreeString((BSTR)bstrString);

    FUN_007a4480(1,"DBReader: %u against %s",0x80040e03,

                 "ICloneBaseReader::FinalConstruct failed to find wad.xml.");

    ExceptionList = pvStack_34;

    return 0;

  }

  OutputDebugStringA("g_pxmlDoc->load called\n");

  *param_1 = 1;

LAB_007b8736:

  param_1[1] = 0;

  LeaveCriticalSection(local_824);

  OutputDebugStringA("Left CriticalSection\n");

  ExceptionList = pvStack_14;

  return local_828;

}
