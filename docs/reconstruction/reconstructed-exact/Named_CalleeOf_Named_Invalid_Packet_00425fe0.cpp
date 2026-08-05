// =============================================================================
// Named_CalleeOf_Named_Invalid_Packet_00425fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00425fe0
// Callee of Named_Invalid_Packet
// Address:   0x00425fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Invalid_Packet: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00424ee0×4, FUN_00425fe0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_Invalid_Packet
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

void Named_CalleeOf_Named_Invalid_Packet_00425fe0(int *param_1)



{

  byte bVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int unaff_ESI;

  

  uVar2 = *(uint *)(unaff_ESI + 0x18);

  if (*(uint *)(unaff_ESI + 0x2c) < uVar2) {

    *(uint8_t *)(unaff_ESI + 0x1c) = 1;

    return;

  }

  bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(unaff_ESI + 0xc));

  uVar3 = uVar2 + 1;

  *(uint *)(unaff_ESI + 0x18) = uVar3;

  if ((bVar1 & (byte)(1 << ((byte)uVar2 & 7))) != 0) {

    if (*(uint *)(unaff_ESI + 0x2c) < uVar3) {

      *(uint8_t *)(unaff_ESI + 0x1c) = 1;

    }

    else {

      bVar1 = *(byte *)((uVar3 >> 3) + *(int *)(unaff_ESI + 0xc));

      *(uint *)(unaff_ESI + 0x18) = uVar2 + 2;

      if ((bVar1 & (byte)(1 << ((byte)uVar3 & 7))) != 0) {

        param_1[0x2d] = param_1[0x2d] | 8;

        return;

      }

    }

    iVar4 = FUN_00424ee0(unaff_ESI,0xffff);

    param_1[0x3a] = iVar4;

    iVar4 = FUN_00424ee0(unaff_ESI,0xffff);

    param_1[0x39] = iVar4;

    iVar4 = FUN_00424ee0(unaff_ESI,0x7ff);

    param_1[0x38] = iVar4;

    iVar4 = FUN_00424ee0(unaff_ESI,0x7ff);

    param_1[0x37] = iVar4;

    (**(code **)(*param_1 + 0x4c))();

  }

  return;

}
