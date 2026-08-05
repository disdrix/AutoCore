// =============================================================================
// UI_QuickBarSlotButton_SetSelected
// -----------------------------------------------------------------------------
// Purpose:  Set or clear visual selected state on a QuickBar slot-button.
//           Select: gate on payload kind, exclusive-clear peers via CDlgQuickBar,
//           highlight child, stamp per-page global column, set fSelected.
//           Clear: unhighlight, force icon alpha 0xFF, clear global if match.
//
// Address:  0x00826780  (autoassault.exe, image base 0x400000)
// Body:     0x00826780–0x0082685e
// Stable:   aa_00826780
// System:   client UI / quickbar
//
// Does NOT: send QuickBarUpdate 0x2062, cast skills, mutate character QB binds.
// Sibling wire: Client_SendQuickBarUpdateFromUi (0x00826720).
// Ctor: UI_QuickBar_CreateSlotButton (0x00825bf0) seeds +0x4fc=0, +0x500=-1.
// Clear-others helper: FUN_0089fef0 (walks dlg+0x63c[10]).
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W17-N seal).
// =============================================================================

/* UI_QuickBarSlotButton_SetSelected

   Parameters:
     this (ECX): QuickBar slot-button widget*
     fSelected (stack): char — 0 clear, non-zero select

   Returns: void  (ret 4) */

void __thiscall
UI_QuickBarSlotButton_SetSelected(UI_QuickBarSlotButton *this, char fSelected)
{
  int kind;
  CDlgQuickBar *dlg;
  void *pColor;

  if (fSelected == '\0') {
    /* clear path */
    if ((this->fSelected != '\0') && (this->pHighlightChild != (int *)0x0)) {
      (**(code **)(*this->pHighlightChild + 4))(0);
    }
    if (this->pIconWidget != (int *)0x0) {
      pColor = (void *)(**(code **)(*this->pIconWidget + 0x164))(0);
      *(unsigned char *)((int)pColor + 3) = 0xff;
      (**(code **)(*this->pIconWidget + 0x34c))();
    }
    if (g_qbSelectedColumnByPage[this->pageIndex] == this->columnIndex) {
      g_qbSelectedColumnByPage[this->pageIndex] = -1;
    }
    this->fSelected = 0;
    return;
  }

  /* select path — require non-empty kind, not kind 6 */
  kind = this->payloadKind;
  if ((kind == 0) || (kind == 6)) {
    return;
  }

  /* parent at +0x88: gfxUIWindow → CDlgQuickBar; result in EAX for helper */
  dlg = (CDlgQuickBar *)
        __RTDynamicCast(this->pParentWindow, 0,
                        &gfxUIWindow_RTTI, &CDlgQuickBar_RTTI, 0);
  /* FUN_0089fef0 — clear other selected slots on dlg (in_EAX) */
  QuickBar_ClearOtherSelectedSlots_INFERRED(dlg);

  if (this->pHighlightChild != (int *)0x0) {
    (**(code **)(*this->pHighlightChild + 4))(1);
  }

  g_qbSelectedColumnByPage[this->pageIndex] = this->columnIndex;
  this->fSelected = fSelected;
  return;
}
