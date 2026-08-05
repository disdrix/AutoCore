// =============================================================================
// FUN_00777770
// -----------------------------------------------------------------------------
// Stable ID: aa_00777770
// Address:   0x00777770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00777770 @ 0x00777770
// Stable ID: aa_00777770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×16, goto×7, return×4, do×2, while×2.
//  - Notable callees: FUN_007775d0×2, free×2, FUN_00770850, FUN_00771600, FUN_00771a00, FUN_00772190, FUN_00774cc0, FUN_00777770.
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

int FUN_00777770(int param_1,uint param_2,uint param_3,code *param_4,uint32_t /* width from decompiler */ param_5)



{

  byte *_Memory;

  size_t sVar1;

  int iVar2;

  size_t _Size;

  uint uVar3;

  byte local_b;

  byte local_a;

  byte local_9;

  int iStack_8;

  

  if (((int)param_2 < 2) || (param_1 < 1)) {

    return -3;

  }

  if ((param_3 & 2) != 0) {

    param_3 = param_3 | 1;

  }

  uVar3 = param_2 & 7;

  _Size = (uint)(uVar3 != 0) + ((int)param_2 >> 3);

  _Memory = malloc(_Size);

  if (_Memory == (byte *)0x0) {

    return -2;

  }

  if (uVar3 == 0) {

    local_b = 0xff;

  }

  else {

    local_b = (byte)(0xff >> (8U - (char)uVar3 & 0x1f));

  }

  local_a = 0;

  if ((param_3 & 8) != 0) {

    local_a = (byte)(0x80 >> (1U - (char)param_2 & 7));

  }

  local_9 = 1;

  if ((param_3 & 1) != 0) {

    local_9 = 3;

  }

  do {

    do {

      sVar1 = (*param_4)(_Memory,_Size,param_5);

      if (sVar1 != _Size) {

        free(_Memory);

        return -3;

      }

      *_Memory = '\x01' << ((char)param_2 - 1U & 7) | local_b & *_Memory;

      _Memory[uVar3 == 1] = _Memory[uVar3 == 1] | local_a;

      _Memory[_Size - 1] = _Memory[_Size - 1] | local_9;

      iVar2 = FUN_00774cc0();

      if (iVar2 != 0) goto LAB_0077791d;

      iVar2 = FUN_007775d0();

      if (iVar2 != 0) goto LAB_0077791d;

    } while (iStack_8 == 0);

    if ((param_3 & 2) != 0) {

      iVar2 = FUN_00771600();

      if (iVar2 != 0) goto LAB_0077791d;

      iVar2 = FUN_00772190();

      if (iVar2 != 0) goto LAB_0077791d;

      iVar2 = FUN_007775d0();

      if (iVar2 != 0) goto LAB_0077791d;

    }

  } while (iStack_8 == 0);

  if ((param_3 & 2) != 0) {

    iVar2 = FUN_00771a00();

    if (iVar2 != 0) goto LAB_0077791d;

    iVar2 = FUN_00770850(1);

    if (iVar2 != 0) goto LAB_0077791d;

  }

  iVar2 = 0;

LAB_0077791d:

  free(_Memory);

  return iVar2;

}
