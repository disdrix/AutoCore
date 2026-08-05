// =============================================================================
// FUN_0071c570
// -----------------------------------------------------------------------------
// Stable ID: aa_0071c570
// Address:   0x0071c570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071c570 @ 0x0071c570
// Stable ID: aa_0071c570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, while×2, goto×2, for×2, do×1.
//  - Notable callees: block×2, FUN_004810b0, FUN_00481130, FUN_0071c570, WSAGetLastError, memmove, recv.
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

/* WARNING: Removing unreachable block (ram,0x0071c5c8) */

/* WARNING: Removing unreachable block (ram,0x0071c5d0) */



char FUN_0071c570(SOCKET *param_1)



{

  SOCKET SVar1;

  void *_Dst;

  char cVar2;

  void *pvVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  SOCKET SVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint8_t local_4 [4];

  

  if ((*param_1 == 0xffffffff) || (cVar2 = FUN_00481130(), cVar2 != '\0')) {

    return '\0';

  }

  SVar9 = param_1[8];

  SVar1 = SVar9;

  while (SVar1 != 0) {

    cVar2 = FUN_004810b0(local_4);

    if (cVar2 == '\0') {

      return '\0';

    }

    if (SVar9 < 0x401) break;

    SVar9 = SVar9 - 0x400;

    SVar1 = param_1[8];

  }

  do {

    if (param_1[2] == 0) {

      pvVar3 = operator_new__(0x800);

      param_1[2] = (SOCKET)pvVar3;

      param_1[3] = 0x800;

      param_1[4] = (SOCKET)pvVar3;

      param_1[5] = 0;

    }

    pvVar3 = (void *)param_1[4];

    _Dst = (void *)param_1[2];

    uVar4 = param_1[3] - param_1[5];

    uVar7 = (uVar4 - (int)pvVar3) + (int)_Dst;

    if (uVar7 < 0x400) {

      if (_Dst == pvVar3) {

LAB_0071c65a:

        if (0x3ff < uVar7) goto LAB_0071c6ae;

      }

      else if (0x3ff < uVar4) {

        memmove(_Dst,pvVar3,param_1[5]);

        param_1[4] = param_1[2];

        uVar7 = uVar4;

        goto LAB_0071c65a;

      }

      puVar5 = operator_new__(param_1[3] + 0x400);

      uVar7 = param_1[5];

      if (uVar7 != 0) {

        puVar8 = (uint32_t /* width from decompiler */ *)param_1[4];

        puVar10 = puVar5;

        for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

          *puVar10 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar10 = puVar10 + 1;

        }

        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(uint8_t *)puVar10 = *(uint8_t *)puVar8;

          puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

          puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

        }

      }

      operator_delete__((void *)param_1[2]);

      param_1[3] = param_1[3] + 0x400;

      uVar7 = param_1[3] - param_1[5];

      param_1[2] = (SOCKET)puVar5;

      param_1[4] = (SOCKET)puVar5;

    }

LAB_0071c6ae:

    uVar7 = recv(*param_1,(char *)(param_1[4] + param_1[5]),uVar7 - 1,0);

    uVar4 = -(uint)(uVar7 != 0xffffffff) & uVar7;

    if ((uVar7 == 0xffffffff) && (iVar6 = WSAGetLastError(), iVar6 != 0x2733)) {

      cVar2 = '\0';

    }

    else {

      cVar2 = '\x01';

    }

    if (uVar4 != 0) {

      param_1[5] = param_1[5] + uVar4;

    }

    if ((cVar2 == '\0') || (uVar4 == 0)) {

      return cVar2;

    }

  } while( true );

}
