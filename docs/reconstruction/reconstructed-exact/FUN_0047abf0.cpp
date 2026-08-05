// =============================================================================
// FUN_0047abf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047abf0
// Address:   0x0047abf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047abf0 @ 0x0047abf0
// Stable ID: aa_0047abf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, do×1, while×1.
//  - Notable callees: FUN_00476d60×5, FUN_0047a480×4, FUN_00476cc0×3, FUN_004704a0, FUN_0047a420, FUN_0047abf0.
//  - Return sites: 7.

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

void __thiscall FUN_0047abf0(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  uint in_EAX;

  uint8_t *puVar3;

  ushort uVar4;

  uint8_t local_30c;

  uint8_t local_30b;

  uint8_t local_30a;

  int local_308;

  uint8_t local_300 [2];

  uint8_t local_2fe [766];

  

  uVar1 = *(uint *)(param_1 + 0x68);

  if ((uVar1 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((uVar1 & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((uVar1 & 2) != 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  *(uint *)(param_1 + 0x68) = uVar1 | 2;

  if ((*(byte *)(param_1 + 0x126) & 2) != 0) {

    if ((in_EAX < 0x301) && (in_EAX % 3 == 0)) {

      iVar2 = (int)in_EAX / 3;

      if (0 < iVar2) {

        puVar3 = local_2fe;

        local_308 = iVar2;

        do {

          FUN_0047a420();

          puVar3[-2] = local_30c;

          puVar3[-1] = local_30b;

          *puVar3 = local_30a;

          puVar3 = puVar3 + 3;

          local_308 = local_308 + -1;

        } while (local_308 != 0);

      }

      FUN_0047a480();

      FUN_004704a0(param_2,local_300,iVar2);

      if (((*(char *)(param_1 + 0x126) == '\x03') && (param_2 != 0)) &&

         ((*(byte *)(param_2 + 8) & 0x10) != 0)) {

        uVar4 = (ushort)iVar2;

        if (uVar4 < *(ushort *)(param_1 + 0x11a)) {

          FUN_00476d60();

          *(ushort *)(param_1 + 0x11a) = uVar4;

        }

        if (uVar4 < *(ushort *)(param_2 + 0x16)) {

          FUN_00476d60();

          *(ushort *)(param_2 + 0x16) = uVar4;

        }

      }

      return;

    }

    if (*(byte *)(param_1 + 0x126) == 3) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0(param_1);

    }

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_00476d60();

  FUN_0047a480();

  return;

}
