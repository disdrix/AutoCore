// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: fprintf×9, CVOGObjectiveRequirement_Patrol_GetFlags.
//  - Strings: "\t\t<Requirement type=\"patrol\" slot=\"%d\">\r\n"; "\t\t\t<AutoComplete>%d</AutoComplete>\r\n"; "\t\t\t<AutoCompleteDistance>%f</AutoCompleteDistance>\r\n"; "\t\t\t<AutoFail>%d</AutoFail>\r\n".
//  - Return sites: 1.

// =============================================================================
// CVOGObjectiveRequirement_Patrol_GetFlags
// -----------------------------------------------------------------------------
// Stable ID: aa_0060e260
// Address:   0x0060e260  (autoassault.exe, image base 0x400000)
// System:    missions-progression
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

void __thiscall CVOGObjectiveRequirement_Patrol_GetFlags(int param_1,FILE *param_2)



{

  FILE *_File;

  uint32_t /* width from decompiler */ *puVar1;

  

  _File = param_2;

  fprintf(param_2,"\t\t<Requirement type=\"patrol\" slot=\"%d\">\r\n");

  fprintf(param_2,"\t\t\t<AutoComplete>%d</AutoComplete>\r\n",

          (uint)(*(char *)(param_1 + 0x10) != '\0'));

  fprintf(param_2,"\t\t\t<AutoCompleteDistance>%f</AutoCompleteDistance>\r\n",

          (double)*(float *)(param_1 + 0x14));

  fprintf(param_2,"\t\t\t<AutoFail>%d</AutoFail>\r\n",(uint)(*(char *)(param_1 + 0x18) != '\0'));

  fprintf(param_2,"\t\t\t<AutoFailDistance>%f</AutoFailDistance>\r\n",

          (double)*(float *)(param_1 + 0x1c));

  fprintf(param_2,"\t\t\t<ContinentCBID>%d</ContinentCBID>\r\n",*(uint32_t /* width from decompiler */ *)(param_1 + 0x28));

  param_2 = (FILE *)0x0;

  if (0 < *(int *)(param_1 + 0xd0)) {

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x30);

    do {

      fprintf(_File,"\t\t\t<GenericTargetCOID>%i</GenericTargetCOID>\r\n",*puVar1,puVar1[1]);

      param_2 = (FILE *)((int)param_2 + 1);

      puVar1 = puVar1 + 2;

    } while ((int)param_2 < *(int *)(param_1 + 0xd0));

  }

  fprintf(_File,"\t\t\t<Laps>%i</Laps>\r\n");

  fprintf(_File,"\t\t</Requirement>\r\n");

  return;

}
