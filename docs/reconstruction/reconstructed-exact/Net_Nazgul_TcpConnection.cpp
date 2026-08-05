// =============================================================================
// Net_Nazgul_TcpConnection
// -----------------------------------------------------------------------------
// Stable ID: aa_00682850
// Address:   0x00682850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Net_Nazgul_TcpConnection @ 0x00682850
// Stable ID: aa_00682850
// Embedded strings (evidence for future rename):
//   - "Error getting generator from key exchanger - prime and generator were likely not set."
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"
//   - "Error getting prime from key exchanger - prime and generator were likely not set."
//   - "Error getting public key from key exchanger - prime and generator probably weren\'t set."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, goto×1.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×2, FUN_00682070, Net_Nazgul_TcpConnection.
//  - Strings: "

                          );

      vog_LogMessage(".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "C:\vog\1_code\palantir\platform\library\src\nazgul\net\netTcpConnection.cpp"
 * Domain alias of FUN_00682850 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t __fastcall Net_Nazgul_TcpConnection(int param_1)



{

  uint8_t uVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ unaff_EBX;

  bool bVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iStack_81c;

  int *piStack_818;

  int iStack_814;

  int *piStack_810;

  int aiStack_80c [510];

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ *puStack_4;

  

  puStack_4 = (uint32_t /* width from decompiler */ *)0xffffffff;

  puStack_8 = &LAB_009a9a73;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar2 = (**(code **)(**(int **)(param_1 + 0x30) + 4))();

  iVar3 = (**(code **)(**(int **)(param_1 + 0x30) + 8))();

  iStack_814 = (**(code **)(**(int **)(param_1 + 0x30) + 0xc))();

  piStack_818 = (int *)(iStack_814 + iVar3 + 0xc + iVar2);

  if (piStack_818 < (int *)0x801) {

    piVar4 = aiStack_80c;

  }

  else {

    piVar4 = operator_new__((uint)piStack_818);

  }

  *piVar4 = iVar2;

  piVar4[1] = iVar3;

  piVar4[2] = iStack_814;

  puStack_4 = (uint32_t /* width from decompiler */ *)0x0;

  iStack_81c = iVar2;

  piStack_810 = piVar4;

  iVar5 = (**(code **)(**(int **)(param_1 + 0x30) + 0x10))(piVar4 + 3,&iStack_81c);

  if (iVar5 == 0) {

    iVar5 = (**(code **)(**(int **)(param_1 + 0x30) + 0x14))

                      ((int)piVar4 + iVar2 + 0xc,&stack0xfffff7dc);

    if (iVar5 == 0) {

      iVar2 = (**(code **)(**(int **)(param_1 + 0x30) + 0x18))

                        ((int)piVar4 + iVar2 + iVar3 + 0xc,&stack0xfffff7dc);

      if (iVar2 == 0) {

        uVar1 = FUN_00682070(piVar4,unaff_EBX,puStack_4);

        if (piStack_818 == &iStack_814) {

          ExceptionList = pvStack_14;

          return uVar1;

        }

        operator_delete__(piStack_818);

        ExceptionList = pvStack_14;

        return uVar1;

      }

      uVar6 = FUN_0076cec0(&stack0xfffff7e0,

                           "Error getting generator from key exchanger - prime and generator were likely not set."

                          );

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,0x561,3,uVar6);

      *puStack_4 = 0;

      bVar7 = piStack_818 == &iStack_814;

      goto LAB_006829b6;

    }

    uVar6 = FUN_0076cec0(&stack0xfffff7e0,

                         "Error getting prime from key exchanger - prime and generator were likely not set."

                        );

    uVar8 = 0x556;

  }

  else {

    uVar6 = FUN_0076cec0(&stack0xfffff7e0,

                         "Error getting public key from key exchanger - prime and generator probably weren\'t set."

                        );

    uVar8 = 0x54b;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                 ,uVar8,3,uVar6);

  *puStack_4 = 0;

  bVar7 = piStack_818 == &iStack_814;

LAB_006829b6:

  if (!bVar7) {

    operator_delete__(piStack_818);

  }

  ExceptionList = pvStack_14;

  return 0;

}
