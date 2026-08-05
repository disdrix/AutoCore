// =============================================================================
// FUN_0047e240
// -----------------------------------------------------------------------------
// Stable ID: aa_0047e240
// Address:   0x0047e240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047e240 @ 0x0047e240
// Stable ID: aa_0047e240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, return×1.
//  - Notable callees: FUN_0047e240.
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

void __thiscall FUN_0047e240(int param_1,int param_2)



{

  short *psVar1;

  ushort uVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  ushort *local_c;

  uint local_8;

  int local_4;

  

  uVar2 = *(ushort *)(in_EAX + 2);

  iVar4 = 0;

  local_8 = 0xffffffff;

  iVar3 = 7;

  iVar5 = 4;

  if (uVar2 == 0) {

    iVar3 = 0x8a;

    iVar5 = 3;

  }

  *(uint16_t *)(in_EAX + 6 + param_1 * 4) = 0xffff;

  if (-1 < param_1) {

    local_c = (ushort *)(in_EAX + 6);

    local_4 = param_1 + 1;

    uVar6 = (uint)uVar2;

    do {

      uVar7 = (uint)*local_c;

      iVar4 = iVar4 + 1;

      if ((iVar3 <= iVar4) || (uVar6 != uVar7)) {

        if (iVar4 < iVar5) {

          psVar1 = (short *)(param_2 + 0xa74 + uVar6 * 4);

          *psVar1 = *psVar1 + (short)iVar4;

        }

        else if (uVar6 == 0) {

          if (iVar4 < 0xb) {

            *(short *)(param_2 + 0xab8) = *(short *)(param_2 + 0xab8) + 1;

          }

          else {

            *(short *)(param_2 + 0xabc) = *(short *)(param_2 + 0xabc) + 1;

          }

        }

        else {

          if (uVar6 != local_8) {

            psVar1 = (short *)(param_2 + 0xa74 + uVar6 * 4);

            *psVar1 = *psVar1 + 1;

          }

          *(short *)(param_2 + 0xab4) = *(short *)(param_2 + 0xab4) + 1;

        }

        iVar4 = 0;

        local_8 = uVar6;

        if (uVar7 == 0) {

          iVar3 = 0x8a;

          iVar5 = 3;

        }

        else if (uVar6 == uVar7) {

          iVar3 = 6;

          iVar5 = 3;

        }

        else {

          iVar3 = 7;

          iVar5 = 4;

        }

      }

      local_c = local_c + 2;

      local_4 = local_4 + -1;

      uVar6 = uVar7;

    } while (local_4 != 0);

  }

  return;

}
