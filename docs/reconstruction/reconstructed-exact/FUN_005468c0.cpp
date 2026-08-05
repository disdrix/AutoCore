// =============================================================================
// FUN_005468c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005468c0
// Address:   0x005468c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005468c0 @ 0x005468c0
// Stable ID: aa_005468c0
// Embedded strings (evidence for future rename):
//   - "\t<Objective name=\"%S\" map=\"%S\" ID=\"%d\" sequence=\"%d\"> <!-- don\'t ever edit this "
//   - "\t\t<ExternalText></ExternalText>\r\n"
//   - "\t\t<ExternalText>%s</ExternalText>\r\n"
//   - "\t\t<Title></Title>\r\n"
//   - "\t\t<Title>%s</Title>\r\n"
//   - "\t\t<DefaultText></DefaultText>\r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: fprintf×9, FUN_005468c0, FUN_0059d880.
//  - Strings: "%S\" ID=\"%d\" sequence=\"%d\"> <!-- don\'t ever edit this -->\r\n"; "\t\t<ExternalText></ExternalText>\r\n"; "\t\t<ExternalText>%s</ExternalText>\r\n"; "\t\t<Title></Title>\r\n".
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

void FUN_005468c0(int *param_1,FILE *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  

  fprintf(param_2,

          "\t<Objective name=\"%S\" map=\"%S\" ID=\"%d\" sequence=\"%d\"> <!-- don\'t ever edit this -->\r\n"

          ,(int)param_1 + 0x16,param_1 + 0x26,param_1[4],(uint)*(byte *)(param_1 + 5));

  if (*param_1 == 0) {

    fprintf(param_2,"\t\t<ExternalText></ExternalText>\r\n");

  }

  else {

    fprintf(param_2,"\t\t<ExternalText>%s</ExternalText>\r\n",*param_1);

  }

  if (param_1[1] == 0) {

    fprintf(param_2,"\t\t<Title></Title>\r\n");

  }

  else {

    fprintf(param_2,"\t\t<Title>%s</Title>\r\n",param_1[1]);

  }

  if (param_1[2] == 0) {

    fprintf(param_2,"\t\t<DefaultText></DefaultText>\r\n");

  }

  else {

    fprintf(param_2,"\t\t<DefaultText>%s</DefaultText>\r\n",param_1[2]);

  }

  uVar2 = FUN_0059d880();

  fprintf(param_2,"\t\t<CompleteCount>%i</CompleteCount>\r\n",uVar2);

  for (uVar3 = 0;

      (iVar1 = param_1[0x56], iVar1 != 0 && (uVar3 < (uint)(param_1[0x57] - iVar1 >> 2)));

      uVar3 = uVar3 + 1) {

    (**(code **)(**(int **)(iVar1 + uVar3 * 4) + 0x54))(param_2);

  }

  fprintf(param_2,"\t</Objective>\r\n");

  return;

}
