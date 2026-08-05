// =============================================================================
// FUN_0059b370
// -----------------------------------------------------------------------------
// Stable ID: aa_0059b370
// Address:   0x0059b370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059b370 @ 0x0059b370
// Stable ID: aa_0059b370
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: return×12, if×11, switch×1.
//  - Notable callees: FUN_0059a1b0, FUN_0059b110, FUN_0059b190, FUN_0059b370, FUN_0059c620, FUN_0059c660, FUN_0059c680, FUN_0059c6a0.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 12.

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

uint32_t /* width from decompiler */ * FUN_0059b370(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5c36;

  local_c = ExceptionList;

  switch(param_1) {

  case 1:

  case 3:

  case 4:

  case 6:

  case 0x16:

  case 0x1e:

  case 0x20:

  case 0x22:

  case 0x30:

  case 0x36:

  case 0x38:

  case 0x3a:

  case 0x3c:

  case 0x3e:

  case 0x42:

  case 0x48:

    ExceptionList = &local_c;

    puVar1 = operator_new(0x4c0);

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      *puVar1 = &PTR_FUN_009d55fc;

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  default:

    ExceptionList = &local_c;

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    break;

  case 8:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x4c8);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059c680();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 10:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x4cc);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059c6c0();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0xc:

  case 0x18:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x544);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059c660();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0xe:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x744);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059a1b0();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0x10:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x5d4);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059c6e0();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0x12:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x528);

    local_4 = 1;

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059b110();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0x14:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x570);

    local_4 = 0;

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059b190();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0x1a:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x4e8);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059c620();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0x1c:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x4d4);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059c700();

      ExceptionList = local_c;

      return puVar1;

    }

    break;

  case 0x32:

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x4c8);

    if (pvVar2 != (void *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0059c6a0();

      ExceptionList = local_c;

      return puVar1;

    }

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
