// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_0071d530
// -----------------------------------------------------------------------------
// Stable ID: aa_0071d530
// Callee of Named_CalleeOf_Auth_AuthServer
// Address:   0x0071d530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Auth_AuthServer: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0071d530.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Auth_AuthServer
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_0071d530(uint32_t /* width from decompiler */ param_1,uint *param_2)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint *unaff_ESI;

  

  uVar3 = *unaff_ESI ^ DAT_00afba08;

  uVar1 = (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) + (&DAT_00afba50)[uVar3 >> 0x18] ^

          *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

          *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ *param_2 ^ DAT_00afba0c;

  uVar3 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba10;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar3 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ _DAT_00afba14;

  uVar3 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba18;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar3 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ _DAT_00afba1c;

  uVar3 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba20;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar3 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ _DAT_00afba24;

  uVar3 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba28;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar3 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ _DAT_00afba2c;

  uVar3 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba30;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar3 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ _DAT_00afba34;

  uVar3 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba38;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar3 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ _DAT_00afba3c;

  uVar3 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar1 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba40;

  uVar1 = uVar1 ^ (*(int *)(&DAT_00afbe50 + (uVar3 >> 0x10 & 0xff) * 4) +

                   (&DAT_00afba50)[uVar3 >> 0x18] ^

                  *(uint *)(&DAT_00afc250 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(&DAT_00afc650 + (uVar3 & 0xff) * 4) ^ _DAT_00afba44;

  uVar2 = uVar1 ^ _DAT_00afba4c;

  *param_2 = uVar3 ^ (*(int *)(&DAT_00afbe50 + (uVar1 >> 0x10 & 0xff) * 4) +

                      (&DAT_00afba50)[uVar1 >> 0x18] ^

                     *(uint *)(&DAT_00afc250 + (uVar1 >> 8 & 0xff) * 4)) +

                     *(int *)(&DAT_00afc650 + (uVar1 & 0xff) * 4) ^ _DAT_00afba48;

  *unaff_ESI = uVar2;

  return;

}
