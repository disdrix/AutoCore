// =============================================================================
// FUN_0071cc40
// -----------------------------------------------------------------------------
// Stable ID: aa_0071cc40
// Address:   0x0071cc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071cc40 @ 0x0071cc40
// Stable ID: aa_0071cc40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0071cc40.
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

void FUN_0071cc40(void)



{

  uint uVar1;

  int in_EAX;

  uint uVar2;

  uint uVar3;

  uint *unaff_ESI;

  uint *unaff_EDI;

  

  uVar3 = *(uint *)(in_EAX + 0x1000) ^ *unaff_EDI;

  uVar2 = (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

           *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

          *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

          *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1004) ^ *unaff_ESI;

  uVar3 = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1008);

  uVar2 = uVar2 ^ (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x100c);

  uVar3 = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1010);

  uVar2 = uVar2 ^ (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1014);

  uVar3 = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1018);

  uVar2 = uVar2 ^ (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x101c);

  uVar3 = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1020);

  uVar2 = uVar2 ^ (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1024);

  uVar3 = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1028);

  uVar2 = uVar2 ^ (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x102c);

  uVar3 = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1030);

  uVar2 = uVar2 ^ (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1034);

  uVar3 = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1038);

  uVar2 = uVar2 ^ (*(int *)(in_EAX + 0x400 + (uVar3 >> 0x10 & 0xff) * 4) +

                   *(int *)(in_EAX + (uVar3 >> 0x18) * 4) ^

                  *(uint *)(in_EAX + 0x800 + (uVar3 >> 8 & 0xff) * 4)) +

                  *(int *)(in_EAX + 0xc00 + (uVar3 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x103c);

  uVar1 = *(uint *)(in_EAX + 0x1044);

  *unaff_ESI = uVar3 ^ (*(int *)(in_EAX + 0x400 + (uVar2 >> 0x10 & 0xff) * 4) +

                        *(int *)(in_EAX + (uVar2 >> 0x18) * 4) ^

                       *(uint *)(in_EAX + 0x800 + (uVar2 >> 8 & 0xff) * 4)) +

                       *(int *)(in_EAX + 0xc00 + (uVar2 & 0xff) * 4) ^ *(uint *)(in_EAX + 0x1040);

  *unaff_EDI = uVar2 ^ uVar1;

  return;

}
