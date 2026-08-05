// =============================================================================
// QuickBar_RebindPageColumns_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0e10
// Address:   0x008a0e10  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W22-D dual A/B seal
// Exactness: Behavior-preserving CF from Ghidra decompile + callee ABI notes
//            from read_memory. Not modernization. Product name open (_Inferred).
// Bit-for-bit / runtime / diff: DEFERRED.
// Dual reviews:
//   reviews/A_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md
//   reviews/B_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Rebind the 10 QuickBar column slot widgets for the host's current page
//   from the global slot table DAT_00d1da60[page*10 + col] (stride 0x18).
//   Type 1 → skill bind, 2 → item bind, 5 → macro bind, else clear.
//   No-op when host vtbl+0x3d8 is false or DAT_00d1b6d8 == 0.
//   Client UI only — no sector packet.
//
// SIGNATURE:
//   void __stdcall QuickBar_RebindPageColumns_Inferred(int *host);
//   // RET 4; stack formal only (not ECX thiscall)
//
// KEY OFFSETS / GLOBALS:
//   host vtbl +0x3d8     visibility/ready gate
//   host +0x50c [0x143]  current page
//   host +0x63c [399]    10 column widget pointers
//   DAT_00d1b6d8         global enable gate
//   DAT_00d1a840         context object for FUN_007fce10
//   DAT_00d1da60 + n*0x18 type (i32)
//   DAT_00d1da68 + n*0x18 id for item/macro (+0x08 of row)
//   DAT_00d1da70 + n*0x18 id for skill     (+0x10 of row)
//
// CALLERS:
//   QuickBar_SelectPage_Inferred (0x008a0ed0)
//   CDlgQuickBar_CreateChildWidgets_Inferred (0x008a16b0)
//   FUN_008a1280, Client_RecvCreateCharacter
//
// CALLEES:
//   FUN_007fce10, FUN_00826860, FUN_008283a0, FUN_00827670,
//   QuickBar_ClearActiveSlot_INFERRED
// =============================================================================

// External callees (FUN_* pending owner duals)
void FUN_007fce10(void *ctx);
void FUN_00826860(/* widget + skill id — see plate */);
void FUN_008283a0(/* widget + item id — see plate */);
void FUN_00827670(unsigned id_or_ctx);
void QuickBar_ClearActiveSlot_INFERRED(/* widget */);

// Globals (image)
// extern int DAT_00d1b6d8;
// extern char DAT_00d1a840[];
// extern int DAT_00d1da60[]; // type table base; +8 da68; +0x10 da70

void QuickBar_RebindPageColumns_Inferred(int *host /* stack */)
{
  char visible;
  int col;
  int *widgetSlot;
  int key;
  int type;

  visible = (**(code **)(*host + 0x3d8))();
  if ((visible != '\0') && (DAT_00d1b6d8 != 0)) {
    FUN_007fce10(&DAT_00d1a840);
    col = 0;
    widgetSlot = host + 399; /* +0x63c */
    do {
      key = col + host[0x143] * 10; /* page*10 + col */
      type = *(int *)((char *)&DAT_00d1da60 + key * 0x18);
      if (type == 1) {
        /* Bytes: EAX=DAT_00d1da70[key], ECX=*widgetSlot, push *widgetSlot */
        FUN_00826860(*widgetSlot);
      } else if (type == 2) {
        /* Bytes: ECX=DAT_00d1da68[key], EAX=*widgetSlot */
        FUN_008283a0();
      } else if (type == 5) {
        FUN_00827670(*(unsigned *)((char *)&DAT_00d1da68 + key * 0x18));
      } else {
        /* Bytes: ESI=*widgetSlot */
        QuickBar_ClearActiveSlot_INFERRED();
      }
      col = col + 1;
      widgetSlot = widgetSlot + 1;
    } while (col < 10);
  }
  return;
}
