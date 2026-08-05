// =============================================================================
// FUN_0099cdb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099cdb0
// Address:   0x0099cdb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099cdb0 @ 0x0099cdb0
// Stable ID: aa_0099cdb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, for×1, while×1, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable×3, CONCAT31, EnterCriticalSection, FUN_0071e820, FUN_00723290, FUN_0076c3c0, FUN_0076c4d0, FUN_0076c500.
//  - Return sites: 1.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall FUN_0099cdb0(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uStack_18;

  uint8_t *local_14;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009b06c7;

  pvStack_10 = ExceptionList;

  uStack_18 = 0x99cdd3;

  local_14 = &stack0xffffefa0;

  ExceptionList = &pvStack_10;

  FUN_0076c500(1000);

  *(uint8_t *)(param_1 + 0x1c) = 1;

  local_8 = 0;

  do {

    Sleep(0x1e);

    iVar1 = FUN_0076c3c0();

    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar1;

    if (199 < *(uint *)(param_1 + 0x20)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

      iVar1 = Client_GetMissionCompleteAudioTable();

      EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x3f8));

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = Client_GetMissionCompleteAudioTable();

      if (*(char *)(iVar2 + 0x410) != '\0') {

        uVar3 = Client_GetMissionCompleteAudioTable();

        FUN_00723290(uVar3);

      }

      for (piVar4 = *(int **)(param_1 + 0x10); piVar4 != *(int **)(param_1 + 0x14);

          piVar4 = piVar4 + 1) {

        iVar2 = *piVar4;

        FUN_0071e820((int)&uStack_18 + 3);

        *(uint8_t *)(iVar2 + 0x1c4) = 0;

      }

      local_8 = local_8 & 0xffffff00;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x3f8));

    }

    FUN_0076c4d0();

  } while (*(char *)(param_1 + 0x1c) != '\0');

  FUN_0099cf08();

  return;

}
