// =============================================================================
// FUN_00722300
// -----------------------------------------------------------------------------
// Stable ID: aa_00722300
// Address:   0x00722300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00722300 @ 0x00722300
// Stable ID: aa_00722300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_00720180×2, Client_GetMissionCompleteAudioTable, FUN_0071fe70, FUN_00720290, FUN_007208d0, FUN_00721a80, FUN_00721d30, FUN_00721f30.
//  - Return sites: 2.

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

void FUN_00722300(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  if (*(char *)(in_EAX + 0x11) == '\0') {

    if (*(char *)(in_EAX + 0x10) != '\0') {

      FUN_007208d0();

      FUN_00721f30(in_EAX,param_1);

      FUN_00721d30(param_1);

      if (*(char *)(in_EAX + 0x16) != '\0') {

        iVar1 = Client_GetMissionCompleteAudioTable();

        FUN_00721a80(in_EAX + 0x90,*(uint8_t *)(iVar1 + 0x25a),0);

        *(uint8_t *)(in_EAX + 0x16) = 0;

      }

      if (*(char *)(in_EAX + 0x17) != '\0') {

        iVar1 = -1;

        iVar4 = 0;

        piVar3 = (int *)(in_EAX + 0x80);

        do {

          if ((*piVar3 != 0) &&

             (iVar2 = _stricmp((char *)(in_EAX + 0x90),(char *)(*piVar3 + 0x48)), iVar2 == 0)) {

            iVar1 = iVar4;

          }

          iVar4 = iVar4 + 1;

          piVar3 = piVar3 + 1;

        } while (iVar4 < 2);

        FUN_00720180(iVar1,0);

        *(uint8_t *)(in_EAX + 0x17) = 0;

      }

    }

    return;

  }

  FUN_00720180(0xffffffff,1);

  FUN_00720290(0xffffffff,1);

  FUN_0071fe70();

  *(uint8_t *)(in_EAX + 0x11) = 0;

  return;

}
