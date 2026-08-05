// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0048b890
// -----------------------------------------------------------------------------
// Stable ID: aa_0048b890
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0048b890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, while×2, do×1, goto×1.
//  - Notable callees: FUN_0048aa20×4, FUN_0048d0a0×3, fseek×2, CONCAT31, FUN_0048a890, FUN_0048b890, block, fread.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

/* WARNING: Removing unreachable block (ram,0x0048b9a3) */



uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0048b890(int param_1,FILE *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  FILE *_File;

  char *pcVar4;

  uint uVar5;

  size_t _ElementSize;

  char *_DstBuf;

  size_t sVar6;

  char *pcVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  _File = param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a0578;

  local_c = ExceptionList;

  if (param_2 == (FILE *)0x0) {

    ExceptionList = &local_c;

    uVar5 = FUN_0048d0a0(2,0,0,0);

    ExceptionList = local_c;

    return (uint32_t /* width from decompiler */ *)(uVar5 & 0xffffff00);

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

  ExceptionList = &local_c;

  while (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

    puVar2 = (uint32_t /* width from decompiler */ *)puVar2[10];

    (*(code *)*puVar3)(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0xffffffff;

  fseek(_File,0,2);

  _ElementSize = ftell(_File);

  fseek(_File,0,0);

  if (_ElementSize == 0) {

    uVar5 = FUN_0048d0a0(0xd,0,0,0);

    ExceptionList = local_c;

    return (uint32_t /* width from decompiler */ *)(uVar5 & 0xffffff00);

  }

  uStack_4 = 0;

  FUN_0048a890(_ElementSize);

  _DstBuf = operator_new(_ElementSize + 1);

  *_DstBuf = '\0';

  param_2 = (FILE *)_DstBuf;

  sVar6 = fread(_DstBuf,_ElementSize,1,_File);

  pcVar4 = (char *)param_2;

  if (sVar6 != 1) {

    FUN_0048d0a0(2,0,0,0);

    ExceptionList = local_c;

    return &DAT_00b03500;

  }

  *(char *)((int)param_2 + _ElementSize) = '\0';

  cVar1 = *(char *)param_2;

  pcVar7 = _DstBuf;

  do {

    if (cVar1 == '\0') {

      if ((int)pcVar7 - (int)_DstBuf != 0) {

        FUN_0048aa20(_DstBuf,(int)pcVar7 - (int)_DstBuf);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pcVar4);

    }

    if (*pcVar7 == '\n') {

      FUN_0048aa20(_DstBuf,pcVar7 + (1 - (int)_DstBuf));

LAB_0048b9ea:

      _DstBuf = pcVar7 + 1;

      pcVar7 = _DstBuf;

    }

    else if (*pcVar7 == '\r') {

      if (0 < (int)pcVar7 - (int)_DstBuf) {

        FUN_0048aa20(_DstBuf,(int)pcVar7 - (int)_DstBuf);

      }

      param_2 = (FILE *)CONCAT31(param_2._1_3_,10);

      FUN_0048aa20(&param_2,1);

      if (pcVar7[1] != '\n') goto LAB_0048b9ea;

      _DstBuf = pcVar7 + 2;

      pcVar7 = _DstBuf;

    }

    else {

      pcVar7 = pcVar7 + 1;

    }

    cVar1 = *pcVar7;

  } while( true );

}
