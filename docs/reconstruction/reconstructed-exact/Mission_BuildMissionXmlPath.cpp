// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00546460, _snprintf, _unlink.
//  - Strings: "%s%S.xml"; "..\\missions\\".
//  - Return sites: 1.

// =============================================================================
// Mission_BuildMissionXmlPath
// -----------------------------------------------------------------------------
// Purpose:  Build filesystem path `..\missions\%s%S.xml` for a mission asset and optionally unlink/replace the prior file. Small path helper used by mission streaming/export tools.
//
// Address:  0x00546460  (autoassault.exe, image base 0x400000)
// Stable:   aa_00546460
// System:   missions-progression
//
// Evidence strings (from raw decompile):
//   - "%s%S.xml"
//   - "..\missions\"
//
// Notable callees:
//   - _snprintf
//   - _unlink
//
// Notes:    Thin FS helper; mission content pipeline.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

void __fastcall Mission_BuildMissionXmlPath(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char local_110 [2];

  uint32_t /* width from decompiler */ local_10e [66];

  

  local_110[0] = '\0';

  local_110[1] = '\0';

  puVar2 = local_10e;

  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint16_t *)puVar2 = 0;

  _snprintf(local_110,0x104,"%s%S.xml","..\\missions\\",param_1 + 4);

  _unlink(local_110);

  return;

}
