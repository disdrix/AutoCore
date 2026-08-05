// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×2, do×1, while×1.
//  - Notable callees: FUN_007a4480×3, GetLastError×3, CryptCreateHash, CryptDeriveKey, CryptDestroyHash, CryptHashData, EnterCriticalSection, FUN_0076cec0.
//  - Strings: "funfunfun with the crypto-fun"; "Microsoft Base Cryptographic Provider v1.0"; "VOG_DEBUG_STOP"; "CryptDeriveKey - %s".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_00799db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00799db0
// Address:   0x00799db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
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



uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_00799db0(void)



{

  BYTE BVar1;

  BOOL BVar2;

  BYTE *pBVar3;

  DWORD DVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  HCRYPTHASH local_22c;

  BYTE local_228 [32];

  CHAR local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  pcVar7 = "funfunfun with the crypto-fun";

  pBVar3 = local_228;

  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {

    *(uint32_t /* width from decompiler */ *)pBVar3 = *(uint32_t /* width from decompiler */ *)pcVar7;

    pcVar7 = pcVar7 + 4;

    pBVar3 = pBVar3 + 4;

  }

  *(uint16_t *)pBVar3 = *(uint16_t *)pcVar7;

  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00d0a394);

  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00d0a394);

  BVar2 = CryptAcquireContextA

                    (&DAT_00d0a3b0,(LPCSTR)0x0,"Microsoft Base Cryptographic Provider v1.0",1,

                     0xf0000000);

  if (BVar2 == 0) {

    GetLastError();

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    return 0x80004001;

  }

  BVar2 = CryptCreateHash(DAT_00d0a3b0,0x8003,0,0,&local_22c);

  if (BVar2 != 0) {

    pBVar3 = local_228;

    do {

      BVar1 = *pBVar3;

      pBVar3 = pBVar3 + 1;

    } while (BVar1 != '\0');

    BVar2 = CryptHashData(local_22c,local_228,(int)pBVar3 - (int)(local_228 + 1),0);

    if (BVar2 != 0) {

      BVar2 = CryptDeriveKey(DAT_00d0a3b0,0x6801,local_22c,0x280000,&DAT_00d0a3b4);

      if (BVar2 == 0) {

        DVar4 = GetLastError();

        local_208[0] = '\0';

        local_208[1] = '\0';

        puVar8 = local_206;

        for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {

          *puVar8 = 0;

          puVar8 = puVar8 + 1;

        }

        *(uint16_t *)puVar8 = 0;

        DVar4 = FormatMessageA(0x1000,(LPCVOID)0x0,DVar4,0,local_208,0x200,(va_list *)0x0);

        if (DVar4 != 0) {

          uVar5 = FUN_0076cec0(&local_22c,"CryptDeriveKey - %s",local_208);

          vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDCrypto.cpp",0x47,2,uVar5);

        }

        FUN_007a4480(0,"VOG_DEBUG_STOP");

        return 0x80004005;

      }

      CryptDestroyHash(local_22c);

      _DAT_00d0a3ac = DAT_00d0a3b0;

      _DAT_00d0a390 = DAT_00d0a3b4;

      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00d0a394);

      return 0;

    }

  }

  GetLastError();

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0x80004005;

}
