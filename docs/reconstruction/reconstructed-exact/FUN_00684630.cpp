// =============================================================================
// FUN_00684630
// -----------------------------------------------------------------------------
// Stable ID: aa_00684630
// Address:   0x00684630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00684630 @ 0x00684630
// Stable ID: aa_00684630
// Embedded strings (evidence for future rename):
//   - "Attempting to open a netUDPOutConnection that already has a socket associated with it"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"
//   - "unable to bind new UDP socket (out of file descriptors?)"
//   - "Bind failed"
//   - "Connect failed"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×2.
//  - Notable callees: FUN_0076cec0×4, vog_LogMessage×3, FUN_0067b3e0×2, socket×2, FUN_00683d50, FUN_00684630, bind, connect.
//  - Strings: "

                        );

    vog_LogMessage("; "unable to bind new UDP socket (out of file descriptors?)"; "Bind failed"; "Connect failed".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_00684630(int param_1,sockaddr *param_2,sockaddr *param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  SOCKET *pSVar3;

  SOCKET SVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  if (*(int *)(param_1 + 0xc0) != 0) {

    uVar2 = FUN_0076cec0(&param_3,

                         "Attempting to open a netUDPOutConnection that already has a socket associated with it"

                        );

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                   ,0x1a5,3,uVar2);

    return 0;

  }

  pSVar3 = operator_new(4);

  if (pSVar3 == (SOCKET *)0x0) {

    pSVar3 = (SOCKET *)0x0;

  }

  else {

    *pSVar3 = 0xffffffff;

  }

  *(SOCKET **)(param_1 + 0xc0) = pSVar3;

  if (*pSVar3 != 0xffffffff) {

LAB_006846a3:

    uVar2 = FUN_0076cec0(&param_3,"unable to bind new UDP socket (out of file descriptors?)");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                   ,0x1ae,3,uVar2);

    FUN_0067b3e0();

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xc0));

  }

  SVar4 = socket(2,2,0);

  *pSVar3 = SVar4;

  if (SVar4 == 0xffffffff) goto LAB_006846a3;

  iVar5 = bind(**(SOCKET **)(param_1 + 0xc0),param_3,0x10);

  if ((int)-(uint)(iVar5 != 0) < 0) {

    uVar2 = FUN_0076cec0(&param_3,"Bind failed");

    uVar6 = 0x1d7;

  }

  else {

    iVar5 = connect(**(SOCKET **)(param_1 + 0xc0),param_2,0x10);

    if (-1 < (int)-(uint)(iVar5 != 0)) {

      cVar1 = FUN_00683d50(&param_3);

      if ((cVar1 == '\x01') || ((param_3 != (sockaddr *)0x0 && (param_3 != (sockaddr *)0x1)))) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

        thunk_FUN_0076c4d0();

        return 1;

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 8;

      goto LAB_0068479b;

    }

    uVar2 = FUN_0076cec0(&param_3,"Connect failed");

    uVar6 = 0x1d0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netUdpOutConnection.cpp"

                 ,uVar6,2,uVar2);

LAB_0068479b:

  FUN_0067b3e0();

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0xc0));

}
