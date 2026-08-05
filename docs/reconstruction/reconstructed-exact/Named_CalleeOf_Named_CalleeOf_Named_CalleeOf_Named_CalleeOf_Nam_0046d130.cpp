// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0046d130
// -----------------------------------------------------------------------------
// Stable ID: aa_0046d130
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x0046d130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: for×2, if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0046d130.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
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

uint __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0046d130(uint *param_1,uint param_2)



{

  uint in_EAX;

  uint uVar1;

  uint *puVar2;

  uint uVar3;

  

  uVar1 = ~in_EAX;

  for (; (param_2 != 0 && (((uint)param_1 & 3) != 0)); param_1 = (uint *)((int)param_1 + 1)) {

    uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a24568 + (((byte)*param_1 ^ uVar1) & 0xff) * 4);

    param_2 = param_2 - 1;

  }

  if (0x1f < param_2) {

    uVar3 = param_2 >> 5;

    puVar2 = param_1;

    do {

      uVar1 = uVar1 ^ *puVar2;

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4) ^ puVar2[1];

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4) ^ puVar2[2];

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4) ^ puVar2[3];

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4) ^ puVar2[4];

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4) ^ puVar2[5];

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4) ^ puVar2[6];

      param_1 = puVar2 + 8;

      param_2 = param_2 - 0x20;

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4) ^ puVar2[7];

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4);

      uVar3 = uVar3 - 1;

      puVar2 = param_1;

    } while (uVar3 != 0);

  }

  if (3 < param_2) {

    uVar3 = param_2 >> 2;

    do {

      uVar1 = uVar1 ^ *param_1;

      param_1 = param_1 + 1;

      uVar1 = *(uint *)(&DAT_00a24968 + (uVar1 >> 0x10 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24d68 + (uVar1 >> 8 & 0xff) * 4) ^

              *(uint *)(&DAT_00a24568 + (uVar1 >> 0x18) * 4) ^

              *(uint *)(&DAT_00a25168 + (uVar1 & 0xff) * 4);

      param_2 = param_2 - 4;

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

  }

  for (; param_2 != 0; param_2 = param_2 - 1) {

    uVar3 = *param_1;

    param_1 = (uint *)((int)param_1 + 1);

    uVar1 = uVar1 >> 8 ^ *(uint *)(&DAT_00a24568 + (((byte)uVar3 ^ uVar1) & 0xff) * 4);

  }

  return ~uVar1;

}
