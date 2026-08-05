// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0049d990, FUN_00799200, FUN_007994c0, FUN_007996d0, FUN_007a4480.
//  - Strings: "axis"; "rotationSpeed"; "useBodyH"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0049d990
// -----------------------------------------------------------------------------
// Stable ID: aa_0049d990
// Address:   0x0049d990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_0049d990(int param_1,int *param_2)



{

  int iVar1;

  byte bStack_6;

  char cStack_5;

  int *local_4;

  

  if (param_2 != (int *)0x0) {

    iVar1 = (**(code **)(*param_2 + 0x44))(param_2,&local_4);

    if ((iVar1 == 0) && (local_4 != (int *)0x0)) {

      *(uint *)(param_1 + 0x3c8) = *(uint *)(param_1 + 0x3c8) | 1;

      FUN_007994c0(local_4,L"axis",param_1 + 0x2f8,param_1 + 0x304,&param_2,&bStack_6);

      *(uint *)(param_1 + 0x3c8) =

           ((bStack_6 & 1) * 4 | (uint)param_2 & 1) * 2 | *(uint *)(param_1 + 0x3c8) & 0xfffffff5;

      FUN_00799200(local_4,L"rotationSpeed",param_1 + 0x310,param_1 + 0x314,&param_2);

      *(uint *)(param_1 + 0x3c8) =

           *(uint *)(param_1 + 0x3c8) ^

           (((uint)param_2 & 0xff) * 4 ^ *(uint *)(param_1 + 0x3c8)) & 4;

      FUN_007996d0(local_4,L"useBodyH",&cStack_5);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ (cStack_5 << 5 ^ *(byte *)(param_1 + 0x1e8)) & 0x20;

      (**(code **)(*local_4 + 8))(local_4);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
