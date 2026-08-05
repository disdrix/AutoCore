// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00423e00, FUN_0043c550, FUN_0043e5b0, FUN_0044d4e0, FUN_007b65d0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp"; "Removing resolver not found".
//  - Return sites: 1.

// =============================================================================
// Named_assManager_007b65d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b65d0
// Address:   0x007b65d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assManager"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_assManager_007b65d0(void)



{

  int iVar1;

  char cVar2;

  int unaff_EBX;

  int iVar3;

  int iVar4;

  int local_4;

  

  if (*(int *)(unaff_EBX + 8) != 0) {

    FUN_00423e00();

    if (*(uint32_t /* width from decompiler */ **)(unaff_EBX + 8) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_EBX + 8))(1);

    }

    iVar4 = DAT_00d1f1fc;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = 0;

    iVar3 = 0x14;

    do {

      iVar1 = *(int *)(iVar4 + 4);

      if ((iVar1 != 0) && (local_4 = (*(int *)(iVar4 + 8) - iVar1) / 0x1c, local_4 != 0)) {

        FUN_0044d4e0(iVar4,&local_4,iVar1);

        iVar4 = DAT_00d1f1fc;

      }

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  local_4 = *(int *)(unaff_EBX + 0xc);

  if (local_4 != 0) {

    cVar2 = FUN_0043e5b0(&local_4);

    if (cVar2 == '\0') {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",0x27b,3,

                     "Removing resolver not found");

    }

    else {

      FUN_0043c550(&local_4);

    }

    if (*(uint32_t /* width from decompiler */ **)(unaff_EBX + 0xc) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_EBX + 0xc))(1);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;

  }

  return;

}
