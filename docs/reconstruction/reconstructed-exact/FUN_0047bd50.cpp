// =============================================================================
// FUN_0047bd50
// -----------------------------------------------------------------------------
// Stable ID: aa_0047bd50
// Address:   0x0047bd50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047bd50 @ 0x0047bd50
// Stable ID: aa_0047bd50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×11, return×7.
//  - Notable callees: FUN_00476d60×5, FUN_0047a480×5, FUN_0046f8d0, FUN_00476cc0, FUN_0047a420, FUN_0047bd50.
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

void __thiscall FUN_0047bd50(int param_1,int param_2)



{

  byte bVar1;

  uint uVar2;

  short sVar3;

  int in_EAX;

  int iVar4;

  uint8_t local_8;

  uint8_t local_7;

  uint32_t /* width from decompiler */ local_6;

  

  uVar2 = *(uint *)(param_1 + 0x68);

  if ((uVar2 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((uVar2 & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  bVar1 = *(byte *)(param_1 + 0x126);

  if ((bVar1 == 3) && ((uVar2 & 2) == 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x20) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if (bVar1 == 3) {

    iVar4 = 1;

  }

  else {

    iVar4 = (bVar1 & 2 | 1) * 2;

  }

  if (in_EAX != iVar4) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_0047a420();

  iVar4 = FUN_0047a480();

  if (iVar4 == 0) {

    if (*(byte *)(param_1 + 0x126) == 3) {

      *(byte *)(param_1 + 0x138) = local_8;

      if (*(ushort *)(param_2 + 0x14) != 0) {

        if (*(ushort *)(param_2 + 0x14) < (ushort)local_8) {

          FUN_00476d60();

          return;

        }

        iVar4 = (uint)local_8 * 3 + *(int *)(param_1 + 0x114);

        *(ushort *)(param_1 + 0x13a) =

             (ushort)*(byte *)((uint)local_8 * 3 + *(int *)(param_1 + 0x114));

        *(ushort *)(param_1 + 0x13c) = (ushort)*(byte *)(iVar4 + 1);

        *(ushort *)(param_1 + 0x13e) = (ushort)*(byte *)(iVar4 + 2);

      }

    }

    else if ((*(byte *)(param_1 + 0x126) & 2) == 0) {

      sVar3 = (ushort)local_8 * 0x100 + (ushort)local_7;

      *(short *)(param_1 + 0x140) = sVar3;

      *(short *)(param_1 + 0x13e) = sVar3;

      *(short *)(param_1 + 0x13c) = sVar3;

      *(short *)(param_1 + 0x13a) = sVar3;

    }

    else {

      *(ushort *)(param_1 + 0x13a) = (ushort)local_8 * 0x100 + (ushort)local_7;

      *(short *)(param_1 + 0x13c) = (short)((local_6 & 0xff) * 0x100 + (local_6 >> 8 & 0xff));

      *(ushort *)(param_1 + 0x13e) = local_6._2_2_ * 0x100 + (local_6._2_2_ >> 8);

    }

    FUN_0046f8d0(param_1);

  }

  return;

}
