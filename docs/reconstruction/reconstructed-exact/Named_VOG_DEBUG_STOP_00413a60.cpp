// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_00413a60, FUN_00419b80.
//  - Strings: "HashError:remove, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00413a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00413a60
// Address:   0x00413a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_00413a60(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)

{
  uint32_t /* width from decompiler */ *puVar1;
  int unaff_EDI;
  
  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {
    *param_3 = 0;
  }
  if (*(char *)(unaff_EDI + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:remove, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  puVar1 = (uint32_t /* width from decompiler */ *)FUN_00419b80(param_1,param_2);
  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {
    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {
      *param_3 = puVar1[3];
    }
    puVar1[3] = 0;
    if (puVar1 == *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x14)) {
      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14) = puVar1[8];
    }
    else {
      *(uint32_t /* width from decompiler */ *)(puVar1[9] + 0x20) = puVar1[8];
    }
    if (puVar1 == *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x18)) {
      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = puVar1[9];
    }
    else {
      *(uint32_t /* width from decompiler */ *)(puVar1[8] + 0x24) = puVar1[9];
    }
    *puVar1 = &PTR_FUN_00a64758;
    if ((uint32_t /* width from decompiler */ *)puVar1[3] != (uint32_t /* width from decompiler */ *)0x0) {
      (*(code *)**(uint32_t /* width from decompiler */ **)puVar1[3])(1);
    }
    puVar1[3] = 0;
    *puVar1 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20);
    *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x20) = puVar1;
    *(int *)(unaff_EDI + 0xc) = *(int *)(unaff_EDI + 0xc) + -1;
    return 0;
  }
  return 0x80004005;
}
