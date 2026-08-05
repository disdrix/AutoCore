// =============================================================================
// Named_COMMANDO_DESCRIPTIONS_008d5870
// -----------------------------------------------------------------------------
// Stable ID: aa_008d5870
// Address:   0x008d5870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_COMMANDO_DESCRIPTIONS_008d5870 @ 0x008d5870
// Stable ID: aa_008d5870
// Embedded strings (evidence for future rename):
//   - "咋ဤⶋ斀\x9c桒ﶨ£헿쒃蔈痀윊⑄Д"
//   - "쒃蔈痀윊⑄Д"
//   - "RACE_DESCRIPTIONS"
//   - "쒃蔈痀褆⑜\xeb14譙⑌儐偨ꏽ＀菕ࣄ삅ੵ䓇ᐤ\x01"
//   - "COMMANDO_DESCRIPTIONS"
//   - "쒃蔈痀윊⑄Ĕ"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×14, goto×3, return×2, do×2, while×2.
//  - Notable callees: _wcsicmp×8, SysFreeString×4, FUN_00402d50, FUN_007933a0, FUN_008d5870, SysStringLen, free.
//  - Strings: "咋ဤⶋ斀\x9c桒ﶨ£헿쒃蔈痀윊⑄Д"; "쒃蔈痀윊⑄Д"; "RACE_DESCRIPTIONS"; "쒃蔈痀褆⑜\xeb14譙⑌儐偨ꏽ＀菕ࣄ삅ੵ䓇ᐤ\x01".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "COMMANDO_DESCRIPTIONS"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_COMMANDO_DESCRIPTIONS_008d5870(int *param_1,int param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  UINT UVar5;

  void *pvVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char *pcVar8;

  wchar_t **unaff_EBX;

  int *unaff_EBP;

  int *unaff_ESI;

  char *pcVar9;

  wchar_t *pwStack_c4;

  int *piVar10;

  OLECHAR *bstrString;

  wchar_t *local_a8;

  wchar_t awStack_a4 [2];

  int *piStack_a0;

  OLECHAR aOStack_98 [60];

  uint8_t uStack_20;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ba006;

  local_c = ExceptionList;

  local_a8 = (wchar_t *)0x0;

  local_4 = 0;

  if ((param_1 == (int *)0x0) || (param_2 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  pwStack_c4 = L"咋ဤⶋ斀\x9c桒ﶨ£헿쒃蔈痀윊⑄Д";

  ExceptionList = &local_c;

  (**(code **)(*param_1 + 0x1c))();

  pwStack_c4 = L"쒃蔈痀윊⑄Д";

  iVar3 = _wcsicmp(L"RACE_DESCRIPTIONS",local_a8);

  if (iVar3 == 0) {

    awStack_a4[0] = L'\x04';

    awStack_a4[1] = L'\0';

  }

  else {

    pwStack_c4 = L"쒃蔈痀褆⑜\xeb14譙⑌儐偨ꏽ＀菕ࣄ삅ੵ䓇ᐤ\x01";

    iVar3 = _wcsicmp(L"COMMANDO_DESCRIPTIONS",local_a8);

    if (iVar3 == 0) {

      awStack_a4[0] = L'\0';

      awStack_a4[1] = L'\0';

    }

    else {

      pwStack_c4 = L"쒃蔈痀윊⑄Ĕ";

      iVar3 = _wcsicmp(L"ENGINEER_DESCRIPTIONS",local_a8);

      if (iVar3 == 0) {

        awStack_a4[0] = L'\x01';

        awStack_a4[1] = L'\0';

      }

      else {

        pwStack_c4 = L"쒃蔈痀윊⑄Ȕ";

        iVar3 = _wcsicmp(L"OFFICER_DESCRIPTIONS",local_a8);

        if (iVar3 == 0) {

          awStack_a4[0] = L'\x02';

          awStack_a4[1] = L'\0';

        }

        else {

          pwStack_c4 = L"쒃蔈࿀쮅\x01윀⑄̔";

          iVar3 = _wcsicmp(L"RANGER_DESCRIPTIONS",local_a8);

          if (iVar3 != 0) {

            pwStack_c4 = L"蓇됤";

            FUN_007933a0();

            goto LAB_008d5981;

          }

          awStack_a4[0] = L'\x03';

          awStack_a4[1] = L'\0';

        }

      }

    }

  }

  pwStack_c4 = L"䒋ᠤ쌻ㅵ蓇됤";

  (**(code **)(*param_1 + 0x30))();

  if (piStack_a0 != (int *)0x0) {

    bstrString = aOStack_98;

    pwStack_c4 = L"Ｓ尹․踏ŉ";

    piVar10 = piStack_a0;

    (**(code **)(*piStack_a0 + 0x20))();

    iVar3 = 0;

    if (0 < (int)piStack_a0) {

      do {

        pwStack_c4 = awStack_a4;

        (**(code **)(*(int *)local_a8 + 0x1c))(local_a8,iVar3);

        SysFreeString(bstrString);

        bstrString = (OLECHAR *)0x0;

        (**(code **)(*unaff_ESI + 0x1c))(unaff_ESI,&stack0xffffff44);

        iVar4 = _wcsicmp(L"HUMAN",pwStack_c4);

        if (iVar4 == 0) {

          iVar4 = 0;

LAB_008d5a3b:

          SysFreeString(pwStack_c4);

          pwStack_c4 = (BSTR)0x0;

          (**(code **)(*unaff_EBP + 0x68))(unaff_EBP,&pwStack_c4);

          piVar1 = unaff_ESI + (int)piVar10 + iVar4 * 5 + 0x17a;

          if ((void *)unaff_ESI[(int)piVar10 + iVar4 * 5 + 0x17a] != (void *)0x0) {

            operator_delete__((void *)unaff_ESI[(int)piVar10 + iVar4 * 5 + 0x17a]);

          }

          *piVar1 = 0;

          if (pwStack_c4 != (BSTR)0x0) {

            UVar5 = SysStringLen(pwStack_c4);

            pvVar6 = operator_new__(UVar5 + 1);

            *piVar1 = (int)pvVar6;

            puVar7 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_c4);

            pcVar8 = (char *)*puVar7;

            pcVar9 = (char *)*piVar1;

            do {

              cVar2 = *pcVar8;

              *pcVar9 = cVar2;

              pcVar8 = pcVar8 + 1;

              pcVar9 = pcVar9 + 1;

            } while (cVar2 != '\0');

            uStack_20 = 0;

            if (unaff_EBX != &local_a8) {

              free(unaff_EBX);

            }

          }

        }

        else {

          iVar4 = _wcsicmp(L"MUTANT",pwStack_c4);

          if (iVar4 == 0) {

            iVar4 = 1;

            goto LAB_008d5a3b;

          }

          iVar4 = _wcsicmp(L"BIOMEK",pwStack_c4);

          if (iVar4 == 0) {

            iVar4 = 2;

            goto LAB_008d5a3b;

          }

        }

        (**(code **)(*unaff_EBP + 8))(unaff_EBP);

        iVar3 = iVar3 + 1;

      } while (iVar3 < (int)piStack_a0);

    }

    pwStack_c4 = local_a8;

    (**(code **)(*(int *)local_a8 + 8))();

  }

LAB_008d5981:

  local_4 = 0xffffffff;

  SysFreeString(local_a8);

  ExceptionList = local_c;

  return;

}
