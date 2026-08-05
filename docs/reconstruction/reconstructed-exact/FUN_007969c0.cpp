// =============================================================================
// FUN_007969c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007969c0
// Address:   0x007969c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007969c0 @ 0x007969c0
// Stable ID: aa_007969c0
// Embedded strings (evidence for future rename):
//   - "

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×2, do×1, while×1.
//  - Notable callees: FUN_00796810×2, MessageBoxA×2, sprintf×2, FUN_007965a0, FUN_007969c0, i.
//  - Strings: "Devices Are Taken"; "Too Many Users".
//  - Return sites: 4.

             );

      iVar2 = MessageBoxA(param_3,local_110,"
//   - "

              ,param_4);

      MessageBoxA(param_3,local_110,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

uint32_t /* width from decompiler */ __fastcall

FUN_007969c0(int param_1,int param_2,HWND param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ param_9)



{

  char cVar1;

  char *in_EAX;

  int iVar2;

  int *piVar3;

  int local_258 [4];

  uint32_t /* width from decompiler */ local_248;

  uint32_t /* width from decompiler */ local_244;

  uint32_t /* width from decompiler */ local_240;

  uint32_t /* width from decompiler */ local_23c;

  uint32_t /* width from decompiler */ local_238;

  uint32_t /* width from decompiler */ local_234;

  uint32_t /* width from decompiler */ local_230;

  uint32_t /* width from decompiler */ local_22c;

  uint32_t /* width from decompiler */ local_228;

  char local_214 [260];

  char local_110 [268];

  

  if (param_2 < 1) {

    return 0x80004005;

  }

  piVar3 = local_258;

  for (iVar2 = 0x52; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar3 = 0;

    piVar3 = piVar3 + 1;

  }

  local_258[2] = param_2 * 4;

  local_240 = param_6;

  local_248 = param_9;

  local_244 = param_5;

  local_23c = param_7;

  local_258[0] = 0x148;

  local_258[1] = 0x28;

  local_238 = param_8;

  local_234 = 0x2000000;

  local_230 = 0x100;

  local_22c = 0xffffff9c;

  local_228 = 100;

  iVar2 = -(int)in_EAX;

  do {

    cVar1 = *in_EAX;

    in_EAX[(int)(local_214 + iVar2)] = cVar1;

    in_EAX = in_EAX + 1;

  } while (cVar1 != '\0');

  local_258[3] = param_2;

  iVar2 = FUN_00796810(&param_4,1);

  if (iVar2 < 0) {

    if (iVar2 == -0x7ffbfc1a) {

      sprintf(local_110,

              "You have entered more users than there are suitable devices, or some users are claiming too many devices.\n\nClick Yes to give each user a default device, or click No to close the application"

             );

      iVar2 = MessageBoxA(param_3,local_110,"Devices Are Taken",0x34);

      if (iVar2 != 6) {

        return 0x80004005;

      }

    }

    else {

      if (iVar2 != -0x7ffbfc19) {

        return 0;

      }

      param_4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d0);

      sprintf(local_110,

              "There are not enough devices attached to the system for the number of users you entered.\n\nThe number of users has been automatically changed to %i (the number of devices available on the system)."

              ,param_4);

      MessageBoxA(param_3,local_110,"Too Many Users",0x30);

    }

    FUN_007965a0();

    FUN_00796810(&param_4,1);

  }

  return 0;

}
