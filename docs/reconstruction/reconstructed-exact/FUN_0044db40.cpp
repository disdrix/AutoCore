// =============================================================================
// FUN_0044db40
// -----------------------------------------------------------------------------
// Stable ID: aa_0044db40
// Address:   0x0044db40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044db40 @ 0x0044db40
// Stable ID: aa_0044db40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT31×2, FUN_0044db40, FUN_0044dd10.
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

uint32_t /* width from decompiler */ * FUN_0044db40(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint *unaff_EBX;

  

  puVar1 = param_1;

  puVar3 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  param_1 = (uint32_t /* width from decompiler */ *)CONCAT31(param_1._1_3_,1);

  if (*(char *)((int)puVar3[1] + 0x25) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      puVar3 = puVar2;

      param_1 = (uint32_t /* width from decompiler */ *)CONCAT31(param_1._1_3_,*unaff_EBX < (uint)puVar3[3]);

      if (*unaff_EBX < (uint)puVar3[3]) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

      }

    } while (*(char *)((int)puVar2 + 0x25) == '\0');

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0044dd10(&param_1,param_1,puVar3,unaff_EBX);

  *puVar1 = *puVar3;

  *(uint8_t *)(puVar1 + 1) = 1;

  return puVar1;

}
