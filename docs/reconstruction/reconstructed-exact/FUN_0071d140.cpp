// =============================================================================
// FUN_0071d140
// -----------------------------------------------------------------------------
// Stable ID: aa_0071d140
// Address:   0x0071d140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071d140 @ 0x0071d140
// Stable ID: aa_0071d140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0071d140.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_0071d140(uint32_t /* width from decompiler */ param_1,uint *param_2)



{

  uint uVar1;

  uint uVar2;

  uint *unaff_ESI;

  uint uVar3;

  

  uVar2 = *unaff_ESI ^ _DAT_00afba4c;

  uVar1 = (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) + (&DAT_00afba50)[uVar2 >> 0x18] ^

          *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

          *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ *param_2 ^ _DAT_00afba48;

  uVar2 = uVar2 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba44;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar2 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ _DAT_00afba40;

  uVar2 = uVar2 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba3c;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar2 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ _DAT_00afba38;

  uVar2 = uVar2 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba34;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar2 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ _DAT_00afba30;

  uVar2 = uVar2 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba2c;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar2 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ _DAT_00afba28;

  uVar2 = uVar2 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba24;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar2 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ _DAT_00afba20;

  uVar2 = uVar2 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba1c;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar2 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ _DAT_00afba18;

  uVar2 = uVar2 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba14;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar2 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar2 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar2 & 0xff) * 4) ^ _DAT_00afba10;

  uVar3 = (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) + (&DAT_00afba50)[uVar1 >> 0x18] ^

          *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

          *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ DAT_00afba0c;

  *unaff_ESI = DAT_00afba08 ^ uVar1;

  *param_2 = uVar2 ^ uVar3;

  return;

}
