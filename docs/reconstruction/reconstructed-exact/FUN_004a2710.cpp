// =============================================================================
// FUN_004a2710
// -----------------------------------------------------------------------------
// Stable ID: aa_004a2710
// Address:   0x004a2710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a2710 @ 0x004a2710
// Stable ID: aa_004a2710
// Embedded strings (evidence for future rename):
//   - "duration"
//   - "VOG_DEBUG_STOP"
//   - "Pursue"
//   - "Environment"
//   - "Circle"
//   - "Orbit"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×14, return×6, goto×5, for×1, do×1, while×1.
//  - Notable callees: SysFreeString×7, _wcsicmp×5, FUN_007a4480×3, FUN_0049d070, FUN_0049d2a0, FUN_0049d510, FUN_0049d6f0, FUN_004a18b0.
//  - Strings: "duration"; "VOG_DEBUG_STOP"; "Ray"; "Pursue".
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ FUN_004a2710(char param_1,BSTR param_2)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  int iVar4;

  BSTR unaff_EBP;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char unaff_retaddr;

  BSTR *bstrString;

  void **ppvVar7;

  BSTR local_20;

  void *pvStack_1c;

  void *local_14 [2];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a10a1;

  local_c = ExceptionList;

  local_20 = (BSTR)0x0;

  local_4 = 0;

  if (param_2 == (BSTR)0x0) {

    ExceptionList = &local_c;

    FUN_007a4480();

    SysFreeString(local_20);

    ExceptionList = local_c;

    return 0;

  }

  ppvVar7 = local_14;

  ExceptionList = &local_c;

  iVar2 = (**(code **)(*(int *)param_2 + 0x44))();

  if ((iVar2 != 0) || (pvStack_1c == (void *)0x0)) {

    FUN_007a4480();

    SysFreeString(unaff_EBP);

    ExceptionList = local_14[0];

    return 0;

  }

  if (param_1 == '\0') {

    pvVar3 = operator_new(0x3e4);

    if (pvVar3 == (void *)0x0) {

      puVar5 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_004a6c80();

    }

  }

  else {

    puVar5 = (uint32_t /* width from decompiler */ *)(local_4 + 0x3f8);

  }

  puVar6 = puVar5;

  for (iVar2 = 0xf9; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  puVar6 = puVar5 + 2;

  puVar5[3] = puVar6;

  *puVar6 = puVar6;

  FUN_00799200(pvStack_1c,L"duration");

  *(byte *)(puVar5 + 0x79) =

       *(byte *)(puVar5 + 0x79) ^ (unaff_retaddr * '\x04' ^ *(byte *)(puVar5 + 0x79)) & 4;

  local_20 = (BSTR)0x0;

  (**(code **)(*(int *)param_2 + 0x30))();

  if (unaff_EBP == (BSTR)0x0) {

    SysFreeString(param_2);

    ExceptionList = pvStack_1c;

    return 0;

  }

  bstrString = &local_20;

  (**(code **)(*(int *)unaff_EBP + 0x20))(unaff_EBP);

  iVar2 = 0;

  if (0 < (int)unaff_EBP) {

    do {

      iVar4 = (**(code **)(*(int *)param_2 + 0x1c))(param_2,iVar2,&stack0xffffffcc);

      if ((iVar4 < 0) || (param_2 == (BSTR)0x0)) {

        FUN_007a4480(0,"VOG_DEBUG_STOP");

        goto LAB_004a28cf;

      }

      SysFreeString((BSTR)bstrString);

      bstrString = (BSTR *)0x0;

      (**(code **)(*(int *)param_2 + 0x1c))(param_2,&stack0xffffffbc);

      iVar4 = _wcsicmp(L"Ray",(wchar_t *)bstrString);

      if (iVar4 == 0) {

        cVar1 = FUN_0049d070(puVar5,param_2);

joined_r0x004a2954:

        if (cVar1 == '\0') {

LAB_004a28cf:

          SysFreeString((BSTR)bstrString);

          ExceptionList = param_2;

          return 0;

        }

      }

      else {

        iVar4 = _wcsicmp(L"Pursue",(wchar_t *)bstrString);

        if (iVar4 == 0) {

          cVar1 = FUN_0049d2a0(puVar5,param_2);

          goto joined_r0x004a2954;

        }

        iVar4 = _wcsicmp(L"Environment",(wchar_t *)bstrString);

        if (iVar4 == 0) {

          cVar1 = FUN_004a18b0(puVar5,param_2);

          goto joined_r0x004a2954;

        }

        iVar4 = _wcsicmp(L"Circle",(wchar_t *)bstrString);

        if (iVar4 == 0) {

          cVar1 = FUN_0049d510(puVar5,param_2);

          goto joined_r0x004a2954;

        }

        iVar4 = _wcsicmp(L"Orbit",(wchar_t *)bstrString);

        if (iVar4 == 0) {

          cVar1 = FUN_0049d6f0(puVar5,param_2);

          goto joined_r0x004a2954;

        }

      }

      (**(code **)(*(int *)param_2 + 8))(param_2);

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)unaff_EBP);

  }

  (**(code **)(*(int *)param_2 + 8))(param_2);

  (**(code **)(*(int *)param_2 + 8))(param_2);

  if ((char)local_14[0] != '\0') {

    puVar5[0xbd] = puVar5;

    puVar5[0xbc] = puVar5;

    SysFreeString(param_2);

    ExceptionList = ppvVar7;

    return 1;

  }

  puVar5[0xbd] = (int)pvStack_1c + 0x3f8;

  puVar5[0xbc] = *(uint32_t /* width from decompiler */ *)((int)pvStack_1c + 0x6e8);

  *(uint32_t /* width from decompiler */ **)(*(int *)((int)pvStack_1c + 0x6e8) + 0x2f4) = puVar5;

  *(uint32_t /* width from decompiler */ **)((int)pvStack_1c + 0x6e8) = puVar5;

  SysFreeString(param_2);

  ExceptionList = ppvVar7;

  return 1;

}
