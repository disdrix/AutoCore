// =============================================================================
// FUN_0044a730
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a730
// Address:   0x0044a730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044a730 @ 0x0044a730
// Stable ID: aa_0044a730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_0044a8c0×2, FUN_0044a730, FUN_0044aa90.
//  - Return sites: 3.

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

void FUN_0044a730(void)



{

  bool bVar1;

  uint *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

  bVar1 = true;

  local_8 = 1;

  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      puVar3 = puVar2;

      if ((*in_EAX < (uint)puVar3[3]) ||

         ((*in_EAX <= (uint)puVar3[3] && (in_EAX[1] < (uint)puVar3[4])))) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar3;

        bVar1 = true;

        local_8 = 1;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

        bVar1 = false;

        local_8 = 0;

      }

    } while (*(char *)((int)puVar2 + 0x19) == '\0');

  }

  local_4 = puVar3;

  if (bVar1) {

    if (puVar3 == (uint32_t /* width from decompiler */ *)**(int **)(unaff_EBX + 4)) {

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_0044a8c0(&local_4,1,puVar3,in_EAX);

      *unaff_ESI = *puVar3;

      *(uint8_t *)(unaff_ESI + 1) = 1;

      return;

    }

    FUN_0044aa90();

  }

  if ((*in_EAX <= (uint)local_4[3]) &&

     ((*in_EAX < (uint)local_4[3] || (in_EAX[1] <= (uint)local_4[4])))) {

    *unaff_ESI = local_4;

    *(uint8_t *)(unaff_ESI + 1) = 0;

    return;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0044a8c0(&local_4,local_8,puVar3,in_EAX);

  *unaff_ESI = *puVar3;

  *(uint8_t *)(unaff_ESI + 1) = 1;

  return;

}
