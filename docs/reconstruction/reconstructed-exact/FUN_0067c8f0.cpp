// =============================================================================
// FUN_0067c8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c8f0
// Address:   0x0067c8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067c8f0 @ 0x0067c8f0
// Stable ID: aa_0067c8f0
// Embedded strings (evidence for future rename):
//   - "Session %lu: Remote failed to acknowledge sequence %d (send count %d), session terminating"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
//   - "Session %lu: time since first resend %6.6lf seconds"
//   - "Session %lu: Remote failed to acknowledge ephemeral sequence, session terminating."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, while×3.
//  - Notable callees: FUN_0076cec0×3, vog_LogMessage×3, CONCAT31, FUN_0067c8f0, d.
//  - Strings: "Session %lu: time since first resend %6.6lf seconds".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __fastcall FUN_0067c8f0(int param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  int *piVar6;

  float fVar7;

  uint8_t local_4 [4];

  

  piVar6 = *(int **)(param_1 + 0x2958);

  if ((piVar6 != (int *)0x0) && (*(int *)(param_1 + 0x295c) - (int)piVar6 >> 2 != 0)) {

    piVar6 = (int *)*piVar6;

    fVar7 = *(float *)(param_1 + 0x29bc) - (float)piVar6[3];

    if ((*(char *)(piVar6 + 4) != '\0') && (_DAT_009e8fac < fVar7)) {

      uVar4 = FUN_0076cec0(local_4,

                           "Session %lu: Remote failed to acknowledge sequence %d (send count %d), session terminating."

                           ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),piVar6[1],*(char *)(piVar6 + 4));

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x593,3,uVar4);

      uVar4 = FUN_0076cec0(local_4,"Session %lu: time since first resend %6.6lf seconds",

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),(double)fVar7);

      uVar5 = vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                             ,0x594,3,uVar4);

      return uVar5 & 0xffffff00;

    }

  }

  piVar2 = (int *)**(int **)(param_1 + 0x10c);

  while( true ) {

    if (piVar2 == *(int **)(param_1 + 0x10c)) {

      return CONCAT31((int3)((uint)piVar6 >> 8),1);

    }

    if (_DAT_009e8fac <

        *(float *)(param_1 + 0x29bc) -

        (float)*(int *)(param_1 + 0x138 + (uint)*(byte *)(piVar2 + 3) * 0x28)) break;

    piVar6 = (int *)((uint)*(byte *)(piVar2 + 3) * 5);

    if (*(char *)((int)piVar2 + 0xe) == '\0') {

      piVar6 = (int *)piVar2[2];

      if (*(char *)((int)piVar6 + 0xe) == '\0') {

        cVar1 = *(char *)(*piVar6 + 0xe);

        piVar2 = piVar6;

        piVar6 = (int *)*piVar6;

        while (cVar1 == '\0') {

          cVar1 = *(char *)(*piVar6 + 0xe);

          piVar2 = piVar6;

          piVar6 = (int *)*piVar6;

        }

      }

      else {

        cVar1 = *(char *)(piVar2[1] + 0xe);

        piVar6 = (int *)piVar2[1];

        piVar3 = piVar2;

        while ((piVar2 = piVar6, piVar6 = piVar2, cVar1 == '\0' && (piVar3 == (int *)piVar2[2]))) {

          cVar1 = *(char *)(piVar2[1] + 0xe);

          piVar6 = (int *)piVar2[1];

          piVar3 = piVar2;

        }

      }

    }

  }

  uVar4 = FUN_0076cec0(local_4,

                       "Session %lu: Remote failed to acknowledge ephemeral sequence, session terminating."

                       ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20));

  uVar5 = vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                         ,0x5a3,3,uVar4);

  return uVar5 & 0xffffff00;

}
