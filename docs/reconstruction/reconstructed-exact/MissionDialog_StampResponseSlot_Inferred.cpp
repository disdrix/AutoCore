// =============================================================================
// MissionDialog_StampResponseSlot_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa510
// Address:   0x008aa510  (autoassault.exe, image base 0x400000)
// System:    missions-progression / mission dialog chrome
// Wave:      MEGA-046 (2026-08-05)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// =============================================================================
//
// PURPOSE:
//   Stamp one mission-dialog response-button slot:
//     - bounds: 0 <= slot < dialog+0x510
//     - if widget at dialog+0x708+slot*4 non-null:
//         vtbl+0x1d8(caption, 1, 1); vtbl+0x34c()
//     - TFID pair at dialog+0x518+slot*8 / +0x51c ← (tfidLo, tfidHi)
//
// ABI (sealed — custom register framing):
//   EDI = MissionDialogHost*
//   ESI = int slotIndex
//   EDX = const char* caption   (used before stack loads clobber EDX)
//   stack: int32 tfidLo, int32 tfidHi
//   RET 8
//
// Body: 0x008aa510–0x008aa55b exclusive (75 B / 0x4B)
// Full hex:
//   85f67c453bb7100500007d3d8b8cb70807000085c9741c8b016a016a0152
//   ff90d80100008b8cb7080700008b01ff904c0300008b4c24048b542408
//   898cf7180500008994f71c050000c20800
//
// Peer wipe: MissionDialog_ClearResponseButtonSlots_Inferred @ 0x008aa560
// Retired scaffold: Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa510
// =============================================================================

#include <cstdint>

struct MissionDialogHost {
  // layout (relevant only)
  // +0x510 int32  responseSlotCount
  // +0x518 int32  tfidPairs[][2]   // lo @ +0, hi @ +4, stride 8
  // +0x708 void*  responseWidgets[] // stride 4
  void **vtbl;
};

// Widget vtbl +0x1d8: set caption/text (product name open)
//   thiscall ECX=widget; stack: caption*, int, int  (image pushes 1,1 after caption)
// Widget vtbl +0x34c: refresh/invalidate (product name open)
//   thiscall ECX=widget; no stack args

// Image ABI uses EDI/ESI/EDX + stack. Modeled as explicit parameters for readability.
// Call order and stores match raw/live CF exactly.

void MissionDialog_StampResponseSlot_Inferred(
    MissionDialogHost *dialog, // EDI
    int slotIndex,             // ESI
    const char *caption,       // EDX at entry
    int32_t tfidLo,            // [ESP+4]
    int32_t tfidHi)            // [ESP+8]
{
  if (slotIndex < 0)
    return;
  if (slotIndex >= *(int32_t *)((uint8_t *)dialog + 0x510))
    return;

  void **widget = *(void ***)((uint8_t *)dialog + 0x708 + slotIndex * 4);
  if (widget != nullptr) {
    void **wvtbl = *(void ***)widget;
    // (**(code **)(*widget + 0x1d8))(caption, 1, 1);
    typedef void(__thiscall *SetCaptionFn)(void *, const char *, int, int);
    SetCaptionFn setCaption = *(SetCaptionFn *)((uint8_t *)wvtbl + 0x1d8);
    setCaption(widget, caption, 1, 1);

    // re-load widget ptr as image does
    widget = *(void ***)((uint8_t *)dialog + 0x708 + slotIndex * 4);
    wvtbl = *(void ***)widget;
    // (**(code **)(*widget + 0x34c))();
    typedef void(__thiscall *RefreshFn)(void *);
    RefreshFn refresh = *(RefreshFn *)((uint8_t *)wvtbl + 0x34c);
    refresh(widget);
  }

  *(int32_t *)((uint8_t *)dialog + 0x518 + slotIndex * 8) = tfidLo;
  *(int32_t *)((uint8_t *)dialog + 0x51c + slotIndex * 8) = tfidHi;
}
