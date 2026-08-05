// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00680c50, FUN_006812b0, FUN_00682070, FUN_00682a40, FUN_0076cec0, vog_LogMessage.
//  - Strings: "

                        );

    vog_LogMessage(".
//  - Return sites: 2.

// =============================================================================
// Named_netTcpConnection_00682a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00682a40
// Address:   0x00682a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netTcpConnection"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t __fastcall Named_netTcpConnection_00682a40(int param_1)



{

  uint uVar1;

  uint8_t uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iStack_34;

  int *piStack_30;

  int iStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  int iStack_20;

  void *pvStack_14;

  void *pvStack_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ *puStack_4;

  

  puStack_4 = (uint32_t /* width from decompiler */ *)0xffffffff;

  puStack_8 = &DAT_009a9a85;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iStack_34 = (**(code **)(**(int **)(param_1 + 0x30) + 4))();

  uVar1 = iStack_34 + 4;

  piStack_30 = operator_new__(uVar1);

  *piStack_30 = iStack_34;

  iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 0x10))(piStack_30 + 1,&iStack_34);

  if (iVar3 != 0) {

    uVar4 = FUN_0076cec0(&iStack_34,

                         "Unable to retrieve public key, prime and generator not set in key exchanger?"

                        );

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                   ,0x587,2,uVar4);

    *puStack_4 = 0;

    ExceptionList = pvStack_14;

    return 0;

  }

  FUN_006812b0(&stack0xffffffc8,uVar1,1);

  pvStack_c = (void *)0x0;

  uVar2 = FUN_00682070(iStack_20 + iStack_2c,uStack_24,puStack_4);

  pvStack_c = (void *)0xffffffff;

  FUN_00680c50();

  ExceptionList = pvStack_14;

  return uVar2;

}
