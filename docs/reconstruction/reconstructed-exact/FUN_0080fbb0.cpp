// =============================================================================
// FUN_0080fbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080fbb0
// Address:   0x0080fbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080fbb0 @ 0x0080fbb0
// Stable ID: aa_0080fbb0
// Embedded strings (evidence for future rename):
//   - "How can I help you?"
//   - " says:\n"
//   - "%s%s%s%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_007a6de0×6, FUN_007a69d0, FUN_007fdfb0, FUN_0080fbb0, FUN_008f8200, __RTDynamicCast, sprintf, strncpy.
//  - Strings: "How can I help you?"; " says:\n"; "%s%s%s%s".
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

void FUN_0080fbb0(int param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  char local_818 [20];

  int local_804;

  char local_800 [1024];

  char local_400 [1024];

  

  if (*(int *)(param_1 + 0x109c) != 0) {

    FUN_007a69d0();

    local_818[0] = '\0';

    local_818[1] = '\0';

    local_818[2] = '\0';

    local_818[3] = '\0';

    local_818[4] = '\0';

    local_818[5] = '\0';

    local_818[6] = '\0';

    local_818[7] = '\0';

    local_818[8] = '\0';

    local_818[9] = '\0';

    local_818[10] = '\0';

    local_818[0xb] = '\0';

    pcVar6 = (char *)(param_2 + 0x1a);

    local_818[0xc] = '\0';

    local_818[0xd] = '\0';

    local_818[0xe] = '\0';

    local_818[0xf] = '\0';

    local_818[0x10] = 0;

    strncpy(local_818,pcVar6,0x10);

    pcVar5 = (char *)(param_2 + 0x2e);

    pcVar2 = pcVar5;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    local_804 = (int)pcVar2 - (param_2 + 0x2f);

    if (local_804 == 0) {

      pcVar2 = (char *)FUN_007a6de0("How can I help you?",0xffffffff);

      pcVar5 = local_800;

      do {

        cVar1 = *pcVar2;

        *pcVar5 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      pcVar5 = (char *)FUN_007a6de0("How can I help you?",0xffffffff);

      uVar3 = FUN_007a6de0(" says:\n",0xffffffff);

      uVar4 = FUN_007a6de0(&DAT_00a7ec08,0xffffffff);

    }

    else {

      pcVar2 = pcVar5;

      do {

        cVar1 = *pcVar2;

        pcVar2[(int)(local_800 + -(int)pcVar5)] = cVar1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      uVar3 = FUN_007a6de0(" says:\n",0xffffffff);

      uVar4 = FUN_007a6de0(&DAT_00a7ec08,0xffffffff);

    }

    sprintf(local_400,"%s%s%s%s",uVar4,pcVar6,uVar3,pcVar5);

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

    uVar7 = 0;

    pcVar6 = local_800;

    pcVar5 = local_818;

    uVar4 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                            &CDlgChatLog::RTTI_Type_Descriptor,0,uVar3,pcVar5,pcVar6,0);

    FUN_008f8200(uVar4,uVar3,pcVar5,pcVar6,uVar7);

    FUN_007fdfb0(param_1,local_400,0xffffffff,0,0);

  }

  return;

}
