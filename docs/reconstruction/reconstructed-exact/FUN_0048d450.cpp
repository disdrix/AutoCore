// =============================================================================
// FUN_0048d450
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d450
// Address:   0x0048d450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d450 @ 0x0048d450
// Stable ID: aa_0048d450
// Embedded strings (evidence for future rename):
//   - "<?xml"
//   - "<!--"
//   - "<![CDATA["
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×21, goto×11, return×3, do×3, while×3.
//  - Notable callees: FUN_0048c2d0×2, FUN_0048cea0×2, FUN_0048af60, FUN_0048c0b0, FUN_0048c120, FUN_0048c1e0, FUN_0048c360, FUN_0048cc80.
//  - Strings: "<?xml"; "<!--"; "<![CDATA[".
//  - Return sites: 3.

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

int __thiscall FUN_0048d450(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  char *pcVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0732;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pcVar3 = (char *)FUN_0048cea0(param_2,param_3);

  if (((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) || (*pcVar3 != '<')) {

    ExceptionList = local_c;

    return 0;

  }

  iVar4 = FUN_0048af60();

  pcVar3 = (char *)FUN_0048cea0(pcVar3,param_3);

  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {

    ExceptionList = local_c;

    return 0;

  }

  cVar2 = FUN_0048cff0(pcVar3,"<?xml",1,param_3);

  if (cVar2 == '\0') {

    cVar2 = *pcVar3;

    pcVar7 = "<!--";

    if (cVar2 != '\0') {

      do {

        if (*pcVar7 == '\0') goto LAB_0048d52b;

      } while (((pcVar3 + -0x9c6ec8)[(int)pcVar7] == *pcVar7) &&

              (pcVar1 = pcVar3 + -0x9c6ec7 + (int)pcVar7, pcVar7 = pcVar7 + 1, *pcVar1 != '\0'));

      if (*pcVar7 == '\0') {

LAB_0048d52b:

        pvVar5 = operator_new(0x2c);

        local_4 = 1;

        if (pvVar5 != (void *)0x0) {

          iVar6 = FUN_0048c0b0();

          goto LAB_0048d664;

        }

        goto LAB_0048d662;

      }

    }

    pcVar7 = "<![CDATA[";

    if (cVar2 != '\0') {

      do {

        if (*pcVar7 == '\0') goto LAB_0048d57b;

      } while (((pcVar3 + -0x9c6ed8)[(int)pcVar7] == *pcVar7) &&

              (pcVar1 = pcVar3 + -0x9c6ed7 + (int)pcVar7, pcVar7 = pcVar7 + 1, *pcVar1 != '\0'));

      if (*pcVar7 == '\0') {

LAB_0048d57b:

        pvVar5 = operator_new(0x30);

        local_4 = 2;

        if (pvVar5 == (void *)0x0) {

          iVar6 = 0;

          uRam0000002c = 1;

        }

        else {

          iVar6 = FUN_0048c120(&DAT_00a1419b);

          *(uint8_t *)(iVar6 + 0x2c) = 1;

        }

        goto LAB_0048d664;

      }

    }

    pcVar7 = "<!";

    if (cVar2 != '\0') {

      do {

        if (*pcVar7 == '\0') goto LAB_0048d5db;

      } while (((pcVar3 + -0x9c7458)[(int)pcVar7] == *pcVar7) &&

              (pcVar1 = pcVar3 + -0x9c7457 + (int)pcVar7, pcVar7 = pcVar7 + 1, *pcVar1 != '\0'));

      if (*pcVar7 == '\0') {

LAB_0048d5db:

        pvVar5 = operator_new(0x2c);

        local_4 = 3;

        if (pvVar5 != (void *)0x0) {

          iVar6 = FUN_0048c2d0();

          goto LAB_0048d664;

        }

        goto LAB_0048d662;

      }

    }

    iVar6 = FUN_0048cc80(pcVar3[1],param_3);

    if ((iVar6 == 0) && (pcVar3[1] != '_')) {

      pvVar5 = operator_new(0x2c);

      local_4 = 5;

      if (pvVar5 != (void *)0x0) {

        iVar6 = FUN_0048c2d0();

        goto LAB_0048d664;

      }

    }

    else {

      pvVar5 = operator_new(0x50);

      local_4 = 4;

      if (pvVar5 != (void *)0x0) {

        iVar6 = FUN_0048c360(&DAT_00a1419b);

        goto LAB_0048d664;

      }

    }

  }

  else {

    pvVar5 = operator_new(0x38);

    local_4 = 0;

    if (pvVar5 != (void *)0x0) {

      iVar6 = FUN_0048c1e0();

      goto LAB_0048d664;

    }

  }

LAB_0048d662:

  iVar6 = 0;

LAB_0048d664:

  local_4 = 0xffffffff;

  if (iVar6 == 0) {

    if (iVar4 != 0) {

      FUN_0048d0a0(3,0,0,0);

    }

  }

  else {

    *(uint32_t /* width from decompiler */ *)(iVar6 + 0x10) = param_1;

  }

  ExceptionList = local_c;

  return iVar6;

}
