// =============================================================================
// FUN_00476cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00476cc0
// Address:   0x00476cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476cc0 @ 0x00476cc0
// Stable ID: aa_00476cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×8, goto×2, for×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00476cc0, FUN_00476e70, swi.
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

void FUN_00476cc0(int param_1)



{

  code *pcVar1;

  char *in_EAX;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  char local_10 [16];

  

  uVar4 = *(uint *)(param_1 + 0x6c);

  if ((uVar4 & 0xc0000) != 0) {

    if (*in_EAX == '#') {

      iVar2 = 1;

      do {

        if (in_EAX[iVar2] == ' ') break;

        if (in_EAX[iVar2 + 1] == ' ') {

          iVar2 = iVar2 + 1;

          break;

        }

        iVar2 = iVar2 + 2;

      } while (iVar2 < 0xf);

      if ((uVar4 & 0x80000) == 0) {

        in_EAX = in_EAX + iVar2;

        goto LAB_00476d47;

      }

      uVar3 = iVar2 - 1;

      uVar4 = 0;

      if (0 < (int)uVar3) {

        pcVar6 = in_EAX + 1;

        pcVar7 = local_10;

        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar6;

          pcVar6 = pcVar6 + 4;

          pcVar7 = pcVar7 + 4;

        }

        for (uVar5 = uVar3 & 3; uVar4 = uVar3, uVar5 != 0; uVar5 = uVar5 - 1) {

          *pcVar7 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          pcVar7 = pcVar7 + 1;

        }

      }

      local_10[uVar4] = '\0';

    }

    else {

      if ((uVar4 & 0x80000) == 0) goto LAB_00476d47;

      local_10[0] = '0';

      local_10[1] = 0;

    }

    in_EAX = local_10;

  }

LAB_00476d47:

  if (*(code **)(param_1 + 0x40) != (code *)0x0) {

    (**(code **)(param_1 + 0x40))(param_1,in_EAX);

  }

  FUN_00476e70(param_1);

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}
