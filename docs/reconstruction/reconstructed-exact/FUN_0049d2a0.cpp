// =============================================================================
// FUN_0049d2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049d2a0
// Address:   0x0049d2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049d2a0 @ 0x0049d2a0
// Stable ID: aa_0049d2a0
// Embedded strings (evidence for future rename):
//   - "direction"
//   - "useBodyH"
//   - "relativeCoords"
//   - "speed"
//   - "acceleration"
//   - "swirl"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005b8370×3, FUN_00799200×2, FUN_007995a0×2, FUN_007996d0×2, FUN_0049d2a0, FUN_00798f30, FUN_00799300, FUN_007994c0.
//  - Strings: "direction"; "useBodyH"; "relativeCoords"; "speed".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_0049d2a0(int param_1,int *param_2)



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

      *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | 0x40;

      param_2 = (int *)((uint)param_2 & 0xffffff00);

      cStack_9 = '\0';

      cStack_a = '\0';

      bStack_b = 0;

      uStack_4 = 0;

      FUN_007995a0(local_8,&uStack_4,L"direction",param_1 + 0xa4,param_1 + 0xb0,&param_2,&bStack_b);

      FUN_005b8370(uStack_4,0xc,param_1 + 0xa4,param_1);

      *(byte *)(param_1 + 0x1e6) =

           ((bStack_b & 1) * '\x04' | (byte)param_2 & 1) * '\x02' |

           *(byte *)(param_1 + 0x1e6) & 0xf5;

      cStack_a = '\0';

      FUN_007996d0(local_8,L"useBodyH",&cStack_a);

      *(byte *)(param_1 + 0x1e6) =

           *(byte *)(param_1 + 0x1e6) ^ (cStack_a << 5 ^ *(byte *)(param_1 + 0x1e6)) & 0x20;

      cStack_9 = '\0';

      FUN_007996d0(local_8,L"relativeCoords",&cStack_9);

      *(byte *)(param_1 + 0x1e6) =

           *(byte *)(param_1 + 0x1e6) ^ (cStack_9 << 6 ^ *(byte *)(param_1 + 0x1e6)) & 0x40;

      FUN_00798f30(local_8,&uStack_4,L"speed",param_1 + 0xdc,param_1 + 0xe0,&param_2);

      FUN_005b8370(uStack_4,4,param_1 + 0xdc,param_1);

      *(byte *)(param_1 + 0x1e6) =

           *(byte *)(param_1 + 0x1e6) ^ (*(byte *)(param_1 + 0x1e6) ^ (byte)param_2) & 1;

      FUN_007994c0(local_8,L"acceleration",param_1 + 0xbc,param_1 + 200,&param_2,&bStack_b);

      *(byte *)(param_1 + 0x1e6) =

           ((bStack_b & 1) * '\x04' | (byte)param_2 & 1) * '\x04' |

           *(byte *)(param_1 + 0x1e6) & 0xeb;

      FUN_00799200(local_8,L"swirl",param_1 + 0xd4,param_1 + 0xd8,&param_2);

      FUN_00799200(local_8,L"radius",param_1 + 0xe8,param_1 + 0xec,&param_2);

      FUN_00799300(local_8,L"detonationRadius",param_1 + 0xe4);

      FUN_007995a0(local_8,&uStack_4,L"pursueTarget",param_1 + 0xf0,0,0,0);

      FUN_005b8370(uStack_4,0xc,param_1 + 0xf0,param_1);

      (**(code **)(*local_8 + 8))(local_8);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
