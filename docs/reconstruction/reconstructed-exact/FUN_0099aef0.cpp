// =============================================================================
// FUN_0099aef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099aef0
// Address:   0x0099aef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099aef0 @ 0x0099aef0
// Stable ID: aa_0099aef0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effSurfaceFormat.cpp"
//   - "Unimplemented code reached"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×7, switch×1, if×1.
//  - Notable callees: FUN_0099aef0, vog_LogMessage.
//  - Strings: ",

                   0x26d,3,".
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

void __thiscall FUN_0099aef0(uint *param_1,uint param_2)



{

  ushort uVar1;

  byte bVar2;

  uint32_t /* width from decompiler */ in_EAX;

  

  bVar2 = (byte)(param_2 >> 8);

  switch(in_EAX) {

  case 0x15:

    *param_1 = param_2;

    return;

  case 0x16:

    *param_1 = param_2 | 0xff000000;

    return;

  case 0x17:

    *(ushort *)param_1 =

         ((param_2._2_1_ & 0xfff8) << 5 | (ushort)(bVar2 & 0xfc)) * 8 |

         (ushort)((byte)(param_2 >> 3) & 0x1f);

    return;

  default:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effSurfaceFormat.cpp",

                   0x26d,3,"Unimplemented code reached");

    return;

  case 0x19:

    break;

  case 0x1a:

    *(ushort *)param_1 =

         (ushort)(((param_2 >> 0x18 & 0xf0) << 4 | (uint)(param_2._2_1_ & 0xf0)) << 4) |

         (ushort)(bVar2 & 0xf0 | (byte)(param_2 >> 4) & 0xf);

    return;

  }

  uVar1 = (ushort)((param_2 >> 0x10 & 0xf8) << 5);

  if ((char)(param_2 >> 0x18) == '\0') {

    *(ushort *)param_1 = (uVar1 | bVar2 & 0xf8) * 4 | (ushort)(byte)((byte)param_2 >> 3);

    return;

  }

  *(ushort *)param_1 = (uVar1 | bVar2 & 0xd8) * 4 | (ushort)(byte)((byte)param_2 >> 3 | 0x80);

  return;

}
