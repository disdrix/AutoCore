// =============================================================================
// FUN_00672440
// -----------------------------------------------------------------------------
// Stable ID: aa_00672440
// Address:   0x00672440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00672440 @ 0x00672440
// Stable ID: aa_00672440
// Embedded strings (evidence for future rename):
//   - "Audio Capture chunk is too large! (%d bytes)"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"
//   - "Couldnt lock capture device\n"
//   - "Couldnt get capture position\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_00672220×2, FUN_0076c130×2, FUN_00672440, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Audio Capture chunk is too large! (%d bytes)"; "Couldnt lock capture device\n"; "Couldnt get capture position\n".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_00672440(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t *puVar7;

  uint8_t **ppuVar8;

  uint8_t *puStack_28;

  uint8_t *puStack_24;

  uint32_t /* width from decompiler */ local_1c;

  int iStack_18;

  uint32_t /* width from decompiler */ local_10;

  uint8_t local_c [4];

  uint8_t local_8 [8];

  

  piVar1 = *(int **)(param_1 + 0x98);

  local_10 = 0;

  local_1c = 0;

  if (piVar1 != (int *)0x0) {

    puStack_24 = local_c;

    puStack_28 = local_8;

    iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1);

    if (-1 < iVar2) {

      uVar5 = iStack_18 - *(int *)(param_1 + 200);

      if ((int)uVar5 < 0) {

        uVar5 = (*(int *)(param_1 + 0xc4) - *(int *)(param_1 + 200)) + iStack_18;

      }

      if (8000 < (int)uVar5) {

        uVar3 = FUN_0076cec0(&local_10,"Audio Capture chunk is too large! (%d bytes)",uVar5);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                       ,0x1f0,2,uVar3);

      }

      iVar2 = uVar5 - uVar5 % *(uint *)(param_1 + 0xcc);

      if (iVar2 != 0) {

        ppuVar8 = &puStack_28;

        puVar7 = &stack0xffffffe0;

        puVar6 = &local_1c;

        iVar4 = (**(code **)(**(int **)(param_1 + 0x98) + 0x20))

                          (*(int **)(param_1 + 0x98),*(uint32_t /* width from decompiler */ *)(param_1 + 200));

        if (-1 < iVar4) {

          FUN_00672220(ppuVar8,puVar7);

          *(uint *)(param_1 + 200) =

               (uint)(puVar7 + *(int *)(param_1 + 200)) % *(uint *)(param_1 + 0xc4);

          if (iVar2 != 0) {

            FUN_00672220(iVar2,puVar6);

            *(uint *)(param_1 + 200) =

                 (uint)(*(int *)(param_1 + 200) + (int)puVar6) % *(uint *)(param_1 + 0xc4);

          }

          (**(code **)(**(int **)(param_1 + 0x98) + 0x2c))

                    (*(int **)(param_1 + 0x98),ppuVar8,puVar7,iVar2,puVar6);

          return 0;

        }

        FUN_0076c130("Couldnt lock capture device\n");

      }

      return 0xffffffff;

    }

    FUN_0076c130("Couldnt get capture position\n");

  }

  return 0xffffffff;

}
