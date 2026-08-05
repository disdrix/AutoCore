// =============================================================================
// FUN_0047c6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047c6b0
// Address:   0x0047c6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047c6b0 @ 0x0047c6b0
// Stable ID: aa_0047c6b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: CONCAT11×3, FUN_0047a480×3, CONCAT22×2, FUN_00476d60×2, FUN_00476cc0, FUN_0047a420, FUN_0047c6b0.
//  - Return sites: 4.

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

void __thiscall FUN_0047c6b0(int param_1,int param_2)



{

  uint uVar1;

  int in_EAX;

  int iVar2;

  uint8_t local_10;

  uint8_t local_f;

  uint8_t local_e;

  uint8_t local_d;

  uint8_t local_c;

  uint8_t local_b;

  uint8_t local_a;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar1 = *(uint *)(param_1 + 0x68);

  if ((uVar1 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 2) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((uVar1 & 4) != 0) {

    *(uint *)(param_1 + 0x68) = uVar1 | 8;

  }

  if (in_EAX != 7) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_0047a420();

  iVar2 = FUN_0047a480();

  if (iVar2 == 0) {

    local_4 = CONCAT22(CONCAT11(local_4._3_1_,local_a),CONCAT11(local_b,local_c));

    local_8 = CONCAT22(CONCAT11(local_d,local_e),(ushort)local_10 * 0x100 + (ushort)local_f);

    if ((param_2 != 0) && ((*(uint *)(param_1 + 0x68) & 0x200) == 0)) {

      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x200;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = local_8;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x40) = local_4;

    }

  }

  return;

}
