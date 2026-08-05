// =============================================================================
// QuickBar_SelectPage_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0ed0
// Address:   0x008a0ed0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 dual A/B (base scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra name remains FUN_008a0ed0 until NAMING_REGISTRY rename.
// =============================================================================
//
// PURPOSE:
//   Select QuickBar page index 0..9 on the QB dialog host.
//   - Page in EAX; host (CDlgQuickBar* Probable) in ECX.
//   - Stores page at host+0x50c; rebinds 10 column widgets; restores or
//     auto-picks remembered column (DAT_00d1da38[page]); clears hover residual.
//   - Client UI only — no sector packet.
//
// CALLERS (role):
//   Client_QuickBar_ActivateSlot mode==1 (shift-QB; slot formal = page)
//   FUN_008a0fb0 page±delta; FUN_008a0fe0 show/refresh; FUN_009114f0 bind next
//   Client_SkillTrainUiRequest_INFERRED post auto-map refresh
//
// CALLEES:
//   FUN_008a0e10          rebind columns from DAT_00d1da60[page*10+i]
//   FUN_00826780(this,0/1) deactivate / activate column widget
//   FUN_008a0210(1)       auto-select next valid column
//   host vtbl +0x448 / +0x34c   chrome refresh / layout
//
// READABILITY:
//   Control flow preserved from Ghidra decompile. Types tentative.
//   Dual name is _Inferred (no product string in unit).
// =============================================================================

// External (still FUN_* / DAT_* pending owner duals)
void FUN_008a0e10(int *host);
void __thiscall FUN_00826780(int widget, char activate);
unsigned FUN_008a0210(char direction_forward);
// DAT_00d1da38 : i32[10] last column per page
// DAT_00d1a9fc : i32 hover column residual

void __fastcall QuickBar_SelectPage_Inferred(int *host)
{
  int prevCol;
  int page; /* in_EAX */
  int *colSlot;
  int remaining;
  int widget;

  /* page register is EAX at entry (decompiler: in_EAX) */
  page = /* in_EAX */;

  if (!((-1 < page) && (page < 10))) {
    return;
  }

  host[0x143] = page;                         /* +0x50c current page */
  prevCol = *(int *)((char *)&DAT_00d1da38 + page * 4);

  colSlot = host + 399;                       /* +0x63c column widget ptrs */
  remaining = 10;
  do {
    if ((*colSlot != 0) &&
        (*(int *)(*colSlot + 0x504) = host[0x143],
         *(char *)(*colSlot + 0x4fc) != '\0')) {
      FUN_00826780(/* this = *colSlot */ 0);
    }
    colSlot = colSlot + 1;
    remaining = remaining + -1;
  } while (remaining != 0);

  FUN_008a0e10(host);
  (**(code **)(*host + 0x448))();             /* host refresh */

  if ((((prevCol < 0) || (9 < prevCol)) ||
       (widget = host[prevCol + 399], widget == 0)) ||
      ((*(unsigned *)(widget + 0x550) & *(unsigned *)(widget + 0x554)) == 0xffffffff)) {
    FUN_008a0210(1);                          /* auto-pick next valid column */
  }
  else {
    FUN_00826780(/* this = widget */ 1);      /* restore selection */
  }

  if (-1 < DAT_00d1a9fc) {
    if (host[DAT_00d1a9fc + 399] != 0) {
      (**(code **)(*(int *)host[DAT_00d1a9fc + 399] + 0x44c))(0);
    }
    DAT_00d1a9fc = -1;
  }

  /* WARNING (decomp): indirect vtbl call at 0x008a0fa7 */
  (**(code **)(*host + 0x34c))();
  return;
}
