// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00799200×5, FUN_007996d0×2, FUN_0049d6f0, FUN_007994c0, FUN_007a4480.
//  - Strings: "axis"; "useBodyH"; "relativeCoords"; "planetRadiusChange".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0049d6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049d6f0
// Address:   0x0049d6f0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_0049d6f0(int param_1,int *param_2)



{

  int iVar1;

  char cStack_7;

  char cStack_6;

  char cStack_5;

  int *local_4;

  

  if (param_2 != (int *)0x0) {

    iVar1 = (**(code **)(*param_2 + 0x44))(param_2,&local_4);

    if ((iVar1 == 0) && (local_4 != (int *)0x0)) {

      *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | 0x20;

      param_2 = (int *)((uint)param_2 & 0xffffff00);

      cStack_5 = '\0';

      cStack_6 = '\0';

      cStack_7 = '\0';

      FUN_007994c0(local_4,L"axis",param_1 + 0xfc,param_1 + 0x108,&param_2,&cStack_6);

      *(byte *)(param_1 + 0x1e7) =

           (*(byte *)(param_1 + 0x1e7) & 0x3f | cStack_6 << 7) ^ ((byte)param_2 & 1) << 6;

      FUN_007996d0(local_4,L"useBodyH",&cStack_5);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ (cStack_5 << 5 ^ *(byte *)(param_1 + 0x1e8)) & 0x20;

      cStack_7 = '\0';

      FUN_007996d0(local_4,L"relativeCoords",&cStack_7);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ (cStack_7 << 6 ^ *(byte *)(param_1 + 0x1e8)) & 0x40;

      FUN_00799200(local_4,L"planetRadiusChange",param_1 + 0x114,param_1 + 0x118,&param_2);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ (*(byte *)(param_1 + 0x1e8) ^ (byte)param_2) & 1;

      FUN_00799200(local_4,L"planetRotationSpeed",param_1 + 0x11c,param_1 + 0x120,&param_2);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ ((byte)param_2 * '\x02' ^ *(byte *)(param_1 + 0x1e8)) & 2;

      FUN_00799200(local_4,L"moonRotationSpeed",param_1 + 0x124,param_1 + 0x128,&param_2);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ ((byte)param_2 * '\x04' ^ *(byte *)(param_1 + 0x1e8)) & 4;

      FUN_00799200(local_4,L"moonRadius",param_1 + 300,param_1 + 0x130,&param_2);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ ((byte)param_2 * '\b' ^ *(byte *)(param_1 + 0x1e8)) & 8;

      FUN_00799200(local_4,L"moonRadiusChange",param_1 + 0x134,param_1 + 0x138,&param_2);

      *(byte *)(param_1 + 0x1e8) =

           *(byte *)(param_1 + 0x1e8) ^ ((byte)param_2 << 4 ^ *(byte *)(param_1 + 0x1e8)) & 0x10;

      (**(code **)(*local_4 + 8))(local_4);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
