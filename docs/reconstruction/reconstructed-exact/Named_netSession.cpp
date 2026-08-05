// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×15, return×5, goto×1.
//  - Notable callees: FUN_00684b10×5, FUN_0076c3c0×4, FUN_0067f6c0×3, FUN_0076cec0×3, vog_LogMessage×3, FUN_0067c430×2, FUN_0076c330×2, FUN_0067c260.
//  - Strings: "Session %lu: acknowledgement timeout, terminating session."; "Outbound processing failed.".
//  - Return sites: 5.

// =============================================================================
// Named_netSession
// -----------------------------------------------------------------------------
// Stable ID: aa_0067f470
// Address:   0x0067f470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netSession"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_netSession(int param_1)



{

  int *piVar1;

  float fVar2;

  char cVar3;

  uint16_t uVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint uVar8;

  int iVar9;

  float10 fVar10;

  int local_34 [13];

  

  fVar10 = (float10)FUN_0076c330();

  *(float *)(param_1 + 0x2a40) = (float)fVar10;

  if (*(int *)(param_1 + 0x2a3c) != 0) {

    FUN_00684b00();

  }

  fVar10 = (float10)FUN_0076c330();

  fVar2 = *(float *)(param_1 + 0x29bc);

  *(float *)(param_1 + 0x29bc) = (float)fVar10;

  local_34[0] = (int)(0.0 - fVar2);

  FUN_0067c260(local_34);

  uVar4 = FUN_006a3db0();

  *(uint16_t *)(param_1 + 0x29c8) = uVar4;

  FUN_0076c500(1000);

  if (*(int **)(param_1 + 0x2984) == (int *)0x0) {

    if (*(int *)(param_1 + 0x2a3c) != 0) {

      FUN_00684b10();

    }

    return 0;

  }

  (**(code **)(**(int **)(param_1 + 0x2984) + 0xc))();

  iVar5 = FUN_0076c3c0();

  cVar3 = FUN_0067eed0();

  if (cVar3 == '\0') {

    if (*(int *)(param_1 + 0x2a3c) != 0) {

      FUN_00684b10();

    }

    return 0;

  }

  iVar6 = FUN_0076c3c0();

  cVar3 = FUN_0067c8f0();

  if (cVar3 == '\0') {

    uVar7 = FUN_0076cec0(local_34,"Session %lu: acknowledgement timeout, terminating session.",

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20));

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x1c9,1,uVar7);

  }

  else {

    uVar8 = FUN_0076c3c0();

    if (uVar8 / 100 < 0x3d) {

      thunk_FUN_0076c4d0();

      cVar3 = FUN_0067e790();

      if (cVar3 != '\0') {

        iVar9 = FUN_0076c3c0();

        if (*(char *)(param_1 + 5) != '\0') {

          cVar3 = FUN_0067f6c0();

          if (cVar3 != '\0') {

            cVar3 = FUN_0067f6c0();

            if (cVar3 != '\0') {

              cVar3 = FUN_0067f6c0();

              if (cVar3 != '\0') {

                FUN_0067c430();

                if (*(int *)(param_1 + 0x2a3c) != 0) {

                  FUN_00684b10();

                }

                return 0;

              }

            }

          }

        }

        if (*(int *)(param_1 + 0x2a3c) != 0) {

          piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x78);

          *piVar1 = *piVar1 + iVar6;

          piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x7c);

          *piVar1 = *piVar1 + iVar9;

          piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x80);

          *piVar1 = *piVar1 + iVar5;

          FUN_00684b10();

        }

        return 1;

      }

      uVar7 = FUN_0076cec0(local_34,"Outbound processing failed.");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x1e4,1,uVar7);

      goto LAB_0067f56a;

    }

    uVar7 = FUN_0076cec0(local_34,"Session %d: Receive timeout, no data received in %d seconds...",

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),0x3c);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x1d6,1,uVar7);

  }

  FUN_0067c430();

LAB_0067f56a:

  if (*(int *)(param_1 + 0x2a3c) != 0) {

    FUN_00684b10();

  }

  return 0;

}
