// =============================================================================
// FUN_0042d2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042d2c0
// Address:   0x0042d2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042d2c0 @ 0x0042d2c0
// Stable ID: aa_0042d2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: return×10, if×6, goto×2, switch×1.
//  - Notable callees: FUN_0042c6c0×2, BitStream_readBits, FUN_004256f0, FUN_0042d2c0, FUN_0042d650, FUN_0042d960, FUN_0042df20, FUN_0042e780.
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ __thiscall FUN_0042d2c0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *local_c [2];

  

  param_1[0x26] = param_1[0x26] + (*(uint *)(param_3 + 0x2c) >> 3);

  local_c[0] = param_1;

  if ((**(byte **)(param_3 + 0xc) & 0x80) == 0) {

    BitStream_readBits(8,local_c);

    if (7 < (byte)local_c[0]) {

      (**(code **)(*param_1 + 0x18))(param_2,local_c[0],param_3);

      return 0;

    }

    switch((uint)local_c[0] & 0xff) {

    case 0:

      FUN_0042d650(param_1,param_2,param_4);

      return 0;

    case 1:

      FUN_0042d960(param_1);

      return 0;

    case 2:

      FUN_0042df20(param_1,param_2,param_3,param_4);

      if (param_4 == 0) {

        return 0;

      }

      goto LAB_0042d3a6;

    case 3:

      FUN_0042ea90(param_1,param_2);

      return 0;

    case 4:

      FUN_0042e780(param_1,param_2,param_3);

      break;

    case 5:

      FUN_0042ffc0(param_1,param_3);

      return 0;

    case 6:

      FUN_0042ef30(param_1,param_2,param_3);

      return 0;

    case 7:

      FUN_0042f950(param_1,param_2,param_3);

      break;

    default:

      goto LAB_0042d414;

    }

    if (param_4 != 0) {

LAB_0042d3a6:

      uVar3 = FUN_0042c6c0();

      return uVar3;

    }

  }

  else {

    piVar2 = (int *)FUN_0042c6c0();

    if (piVar2 != (int *)0x0) {

      piVar2[2] = piVar2[2] + 1;

      FUN_004256f0(param_3);

      piVar1 = piVar2 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

        return 0;

      }

    }

  }

LAB_0042d414:

  return 0;

}
