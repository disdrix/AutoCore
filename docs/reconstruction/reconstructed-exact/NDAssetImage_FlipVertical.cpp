// =============================================================================
// NDAssetImage_FlipVertical
// -----------------------------------------------------------------------------
// Stable ID: aa_004332e0
// Address:   0x004332e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Vertical flip of NDAssetImage pixel buffer (top-origin TGA normalize). After flip y=0 is bottom
   of image. */

uint32_t /* width from decompiler */ NDAssetImage_FlipVertical(void)

{
  uint32_t /* width from decompiler */ *puVar1;
  uint32_t /* width from decompiler */ *puVar2;
  uint uVar3;
  uint uVar4;
  uint32_t /* width from decompiler */ *puVar5;
  int unaff_EBX;
  uint32_t /* width from decompiler */ *puVar6;
  uint32_t /* width from decompiler */ *puVar7;
  int local_8;
  
  if (*(int *)(unaff_EBX + 0x1b0) == 0) {
    return 0;
  }
  puVar1 = malloc(*(int *)(unaff_EBX + 0xc) * *(int *)(unaff_EBX + 0x10));
  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {
    uVar4 = *(uint *)(unaff_EBX + 0xc);
    puVar2 = (uint32_t /* width from decompiler */ *)((*(int *)(unaff_EBX + 0x10) + -1) * uVar4 + *(int *)(unaff_EBX + 0x1b0))
    ;
    local_8 = 0;
    puVar5 = puVar1;
    if (0 < *(int *)(unaff_EBX + 0x10)) {
      do {
        puVar6 = puVar2;
        puVar7 = puVar5;
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(uint8_t *)puVar7 = *(uint8_t *)puVar6;
          puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);
          puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);
        }
        uVar4 = *(uint *)(unaff_EBX + 0xc);
        local_8 = local_8 + 1;
        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 - uVar4);
        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + uVar4);
      } while (local_8 < *(int *)(unaff_EBX + 0x10));
    }
    free(*(void **)(unaff_EBX + 0x1b0));
    *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x1b0) = puVar1;
    return 1;
  }
  return 0;
}
