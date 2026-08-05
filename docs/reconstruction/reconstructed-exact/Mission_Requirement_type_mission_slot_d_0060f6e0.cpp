// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: fprintf×7, FUN_0060f6e0.
//  - Strings: "\t\t<Requirement type=\"mission\" slot=\"%d\">\r\n"; "\t\t\t<IDs>"; "%d|"; "</IDs>\r\n".
//  - Return sites: 1.

// =============================================================================
// Mission_Requirement_type_mission_slot_d_0060f6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0060f6e0
// Address:   0x0060f6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "		<Requirement type="mission" slot="%d">

"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Mission_Requirement_type_mission_slot_d_0060f6e0(int param_1,FILE *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  fprintf(param_2,"\t\t<Requirement type=\"mission\" slot=\"%d\">\r\n",(uint)*(byte *)(param_1 + 8))

  ;

  fprintf(param_2,"\t\t\t<IDs>");

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

  if (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x18)) {

    do {

      fprintf(param_2,"%d|",*puVar1);

      puVar1 = puVar1 + 1;

    } while (puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x18));

  }

  fprintf(param_2,"</IDs>\r\n");

  fprintf(param_2,"\t\t\t<CountNeeded>%d</CountNeeded>\r\n",*(uint32_t /* width from decompiler */ *)(param_1 + 0x20));

  fprintf(param_2,"\t\t\t<IDsAreMedals>%d</IDsAreMedals>\r\n",(uint)*(byte *)(param_1 + 0x24));

  fprintf(param_2,"\t\t</Requirement>\r\n");

  return;

}
