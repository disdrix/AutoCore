// =============================================================================
// FUN_00435380
// -----------------------------------------------------------------------------
// Stable ID: aa_00435380
// Address:   0x00435380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00435380 @ 0x00435380
// Stable ID: aa_00435380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00435380.
//  - Return sites: 1.

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

void FUN_00435380(int param_1)



{

  byte bVar1;

  byte bVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  int iVar5;

  byte *pbVar6;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = *(int *)(in_EAX + 0xc) + -1;

  if (-1 < iVar4) {

    local_4 = iVar4 * 2;

    iVar5 = iVar4 * 4;

    do {

      bVar1 = ('\x03' - ((byte)iVar4 & 3)) * '\x02';

      iVar3 = local_4 >> 3;

      pbVar6 = (byte *)((iVar5 >> 3) + param_1);

      local_4 = local_4 + -2;

      bVar2 = ('\x01' - ((byte)iVar4 & 1)) * '\x04';

      iVar4 = iVar4 + -1;

      iVar5 = iVar5 + -4;

      *pbVar6 = ~('\x0f' << (bVar2 & 0x1f)) & *pbVar6 |

                ((byte)((int)((uint)*(byte *)(iVar3 + param_1) & 3 << (bVar1 & 0x1f)) >>

                       (bVar1 & 0x1f)) & 0xf) << (bVar2 & 0x1f);

    } while (-1 < iVar4);

  }

  return;

}
