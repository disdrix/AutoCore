// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00799200×3, FUN_007996d0×2, FUN_0049d510, FUN_005b8370, FUN_007995a0, FUN_007a4480.
//  - Strings: "rotationSpeed"; "radius"; "radiusAcceleration"; "axis".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0049d510
// -----------------------------------------------------------------------------
// Stable ID: aa_0049d510
// Address:   0x0049d510  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_0049d510(int param_1,int *param_2)



{

  int iVar1;

  char cStack_b;

  byte bStack_a;

  char cStack_9;

  int *local_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (param_2 != (int *)0x0) {

    iVar1 = (**(code **)(*param_2 + 0x44))(param_2,&local_8);

    if ((iVar1 == 0) && (local_8 != (int *)0x0)) {

      *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | 8;

      param_2 = (int *)((uint)param_2 & 0xffffff00);

      cStack_9 = '\0';

      bStack_a = 0;

      cStack_b = '\0';

      uStack_4 = 0;

      FUN_00799200(local_8,L"rotationSpeed",param_1 + 0x9c,param_1 + 0xa0,&param_2);

      *(byte *)(param_1 + 0x1e7) =

           *(byte *)(param_1 + 0x1e7) ^ ((byte)param_2 << 5 ^ *(byte *)(param_1 + 0x1e7)) & 0x20;

      FUN_00799200(local_8,L"radius",param_1 + 0x74,param_1 + 0x78,&param_2);

      *(byte *)(param_1 + 0x1e6) = *(byte *)(param_1 + 0x1e6) & 0x7f | (byte)param_2 << 7;

      FUN_00799200(local_8,L"radiusAcceleration",param_1 + 0x7c,param_1 + 0x80,&param_2);

      *(byte *)(param_1 + 0x1e7) =

           *(byte *)(param_1 + 0x1e7) ^ (*(byte *)(param_1 + 0x1e7) ^ (byte)param_2) & 1;

      FUN_007995a0(local_8,&uStack_4,L"axis",param_1 + 0x84,param_1 + 0x90,&param_2,&bStack_a);

      FUN_005b8370(uStack_4,0xc,param_1 + 0x84,param_1);

      *(byte *)(param_1 + 0x1e7) =

           ((bStack_a & 1) * '\x02' | (byte)param_2 & 1) * '\x02' |

           *(byte *)(param_1 + 0x1e7) & 0xf9;

      FUN_007996d0(local_8,L"useBodyH",&cStack_9);

      *(byte *)(param_1 + 0x1e7) =

           *(byte *)(param_1 + 0x1e7) ^ (cStack_9 * '\b' ^ *(byte *)(param_1 + 0x1e7)) & 8;

      cStack_b = '\0';

      FUN_007996d0(local_8,L"relativeCoords",&cStack_b);

      *(byte *)(param_1 + 0x1e7) =

           *(byte *)(param_1 + 0x1e7) ^ (cStack_b << 4 ^ *(byte *)(param_1 + 0x1e7)) & 0x10;

      (**(code **)(*local_8 + 8))(local_8);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
