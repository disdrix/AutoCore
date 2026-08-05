// =============================================================================
// FUN_0047bb70
// -----------------------------------------------------------------------------
// Stable ID: aa_0047bb70
// Address:   0x0047bb70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047bb70 @ 0x0047bb70
// Stable ID: aa_0047bb70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×12, return×7, goto×2.
//  - Notable callees: FUN_00476d60×5, FUN_0047a480×5, FUN_0047a420×3, FUN_00470950, FUN_00476cc0, FUN_0047bb70.
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

void __thiscall FUN_0047bb70(int param_1,int param_2)



{

  char cVar1;

  uint uVar2;

  uint in_EAX;

  int iVar3;

  ushort local_10c;

  byte local_108;

  byte local_107;

  uint32_t /* width from decompiler */ local_106;

  ushort uStack_104;

  

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

  if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x10) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  cVar1 = *(char *)(param_1 + 0x126);

  if (cVar1 == '\0') {

    if (in_EAX == 2) {

      FUN_0047a420();

      *(uint16_t *)(param_1 + 0x11a) = 1;

      *(ushort *)(param_1 + 0x194) = local_10c * 0x100 + (local_10c >> 8);

LAB_0047bcea:

      iVar3 = FUN_0047a480();

      if (iVar3 != 0) {

        return;

      }

      FUN_00470950(*(uint16_t *)(param_1 + 0x11a),param_1 + 0x18c);

      return;

    }

  }

  else if (cVar1 == '\x02') {

    if (in_EAX == 6) {

      FUN_0047a420();

      *(uint16_t *)(param_1 + 0x11a) = 1;

      *(ushort *)(param_1 + 0x18e) = (ushort)local_108 * 0x100 + (ushort)local_107;

      *(ushort *)(param_1 + 400) =

           (ushort)(byte)local_106 * 0x100 + (ushort)(byte)((uint)local_106 >> 8);

      *(ushort *)(param_1 + 0x192) = uStack_104 * 0x100 + (uStack_104 >> 8);

      goto LAB_0047bcea;

    }

  }

  else if (cVar1 == '\x03') {

    if ((uVar2 & 2) == 0) {

      FUN_00476d60();

    }

    if ((in_EAX <= *(ushort *)(param_1 + 0x118)) && (in_EAX < 0x101)) {

      if (in_EAX == 0) {

        FUN_00476d60();

        FUN_0047a480();

        return;

      }

      FUN_0047a420();

      *(short *)(param_1 + 0x11a) = (short)in_EAX;

      goto LAB_0047bcea;

    }

  }

  FUN_00476d60();

  FUN_0047a480();

  return;

}
