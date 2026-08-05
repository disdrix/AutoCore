// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005b8370×2, FUN_007994c0×2, FUN_007996d0×2, FUN_0049d070, FUN_00798f30, FUN_007995a0, FUN_007a4480.
//  - Strings: "direction"; "useBodyH"; "relativeCoords"; "speed".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0049d070
// -----------------------------------------------------------------------------
// Stable ID: aa_0049d070
// Address:   0x0049d070  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_0049d070(int param_1,int *param_2)



{

  int iVar1;

  byte bStack_b;

  char cStack_a;

  char cStack_9;

  int *local_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (param_2 != (int *)0x0) {

    iVar1 = (**(code **)(*param_2 + 0x44))(param_2,&local_8);

    if ((iVar1 == 0) && (local_8 != (int *)0x0)) {

      *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | 0x10;

      param_2 = (int *)((uint)param_2 & 0xffffff00);

      cStack_9 = '\0';

      cStack_a = '\0';

      bStack_b = 0;

      uStack_4 = 0;

      FUN_007995a0(local_8,&uStack_4,L"direction",param_1 + 0x24,param_1 + 0x30,&param_2,&bStack_b);

      FUN_005b8370(uStack_4,0xc,param_1 + 0x24,param_1);

      *(byte *)(param_1 + 0x1e5) =

           (bStack_b & 1) * '\b' | *(byte *)(param_1 + 0x1e5) & 0xf6 | (byte)param_2 & 1;

      cStack_a = '\0';

      FUN_007996d0(local_8,L"useBodyH",&cStack_a);

      *(byte *)(param_1 + 0x1e5) =

           *(byte *)(param_1 + 0x1e5) ^ (cStack_a << 6 ^ *(byte *)(param_1 + 0x1e5)) & 0x40;

      cStack_9 = '\0';

      FUN_007996d0(local_8,L"relativeCoords",&cStack_9);

      *(byte *)(param_1 + 0x1e5) = *(byte *)(param_1 + 0x1e5) & 0x7f | cStack_9 << 7;

      FUN_00798f30(local_8,&uStack_4,L"speed",param_1 + 0x3c,param_1 + 0x40,&param_2);

      FUN_005b8370(uStack_4,4,param_1 + 0x3c,param_1);

      *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) & 0x7f | (byte)param_2 << 7;

      FUN_007994c0(local_8,L"acceleration",param_1 + 0x44,param_1 + 0x50,&param_2,&bStack_b);

      *(byte *)(param_1 + 0x1e5) =

           ((bStack_b & 1) * '\b' | (byte)param_2 & 1) * '\x02' | *(byte *)(param_1 + 0x1e5) & 0xed;

      FUN_007994c0(local_8,L"relativeAcceleration",param_1 + 0x5c,param_1 + 0x68,&param_2,&bStack_b)

      ;

      *(byte *)(param_1 + 0x1e5) =

           ((bStack_b & 1) * '\b' | (byte)param_2 & 1) * '\x04' | *(byte *)(param_1 + 0x1e5) & 0xdb;

      (**(code **)(*local_8 + 8))(local_8);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
