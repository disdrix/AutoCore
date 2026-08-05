// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×9, return×3.
//  - Notable callees: FUN_0067b110×2, FUN_00415e90, FUN_0046e280, FUN_0046e2a0, FUN_0067b120, FUN_0067ba30, FUN_00727c00, FUN_00729200.
//  - Strings: "[Opened TCP Connection]"; "AuthServer".
//  - Return sites: 3.

// =============================================================================
// Auth_AuthServer
// -----------------------------------------------------------------------------
// Stable ID: aa_00729200
// Address:   0x00729200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AuthServer"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Auth_AuthServer(uint32_t /* width from decompiler */ param_1)



{

  bool bVar1;

  bool bVar2;

  SOCKET *pSVar3;

  SOCKET SVar4;

  int iVar5;

  int unaff_EDI;

  int local_30;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af5e4;

  local_c = ExceptionList;

  if (*(int *)(unaff_EDI + 0x1c) != 0) {

    return 0xffffffff;

  }

  ExceptionList = &local_c;

  FUN_00415e90();

  FUN_0067b120(param_1);

  pSVar3 = operator_new(4);

  if (pSVar3 == (SOCKET *)0x0) {

    pSVar3 = (SOCKET *)0x0;

  }

  else {

    *pSVar3 = 0xffffffff;

  }

  *(SOCKET **)(unaff_EDI + 0x30) = pSVar3;

  if (*pSVar3 == 0xffffffff) {

    SVar4 = socket(2,1,0);

    *pSVar3 = SVar4;

    if (SVar4 != 0xffffffff) {

      iVar5 = FUN_0046e2a0(param_1,&local_30);

      if (-1 < iVar5) {

        if ((*(int **)(unaff_EDI + 0x30) == (int *)0x0) || (**(int **)(unaff_EDI + 0x30) == -1)) {

          FUN_0046e280(local_2c);

          local_4 = 1;

          bVar2 = false;

          bVar1 = true;

        }

        else {

          FUN_0067ba30(local_1c);

          local_4 = 0;

          bVar2 = true;

          bVar1 = false;

        }

        FUN_00727c00("[Opened TCP Connection]","AuthServer");

        local_4 = 0;

        if (bVar1) {

          FUN_0067b110();

        }

        local_4 = 0xffffffff;

        if (bVar2) {

          FUN_0067b110();

        }

        if (local_30 == 2) {

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 1;

          ExceptionList = local_c;

          return 0;

        }

      }

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_EDI + 0x30));

}
