// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00680220×2, FUN_0076cec0×2, vog_LogMessage×2, FUN_0066f1b0, FUN_00674140, FUN_00674170.
//  - Strings: "Allocating audio frame buffer: %d"; "Uknown result code: %d".
//  - Return sites: 1.

// =============================================================================
// Named_ChatClientImpl_0066f1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066f1b0
// Address:   0x0066f1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_ChatClientImpl_0066f1b0(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int local_10;

  uint8_t local_c [4];

  uint8_t local_8 [4];

  uint8_t local_4 [4];

  

  if (*(int *)(param_1 + 0x30) != 0) {

    cVar1 = FUN_00680220(&local_10,local_c);

    while (cVar1 != '\0') {

      if (local_10 == 0) {

        if (*(void **)(param_1 + 0x178) != (void *)0x0) {

          operator_delete__(*(void **)(param_1 + 0x178));

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

        }

        iVar2 = FUN_00674140();

        iVar3 = FUN_00674170();

        pvVar4 = operator_new__(iVar2 * iVar3 + 1);

        *(void **)(param_1 + 0x178) = pvVar4;

        uVar5 = FUN_0076cec0(local_8,"Allocating audio frame buffer: %d",iVar2 * iVar3);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                       ,0x2b2,1,uVar5);

      }

      else {

        uVar5 = FUN_0076cec0(local_4,"Uknown result code: %d",local_10);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                       ,0x2b6,3,uVar5);

      }

      cVar1 = FUN_00680220(&local_10,local_c);

    }

  }

  return 1;

}
