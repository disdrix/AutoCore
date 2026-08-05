// =============================================================================
// MissionDialog_ClearResponseButtonSlots_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa560
// Address:   0x008aa560  (autoassault.exe, image base 0x400000)
// System:    missions-progression / mission dialog chrome
// Wave:      WQ7R-C (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// =============================================================================
//
// PURPOSE:
//   Pre-rebuild wipe of mission-dialog **response button** chrome:
//     - 8× TFID pairs at dialog+0x518 → (−1, −1)
//     - 8× widget pointers at dialog+0x708 → vtbl+0xBC destroy, then 0
//
// ABI (sealed):
//   EBX = mission dialog host*  (sole caller FUN_008ac110: MOV EBX,EDI)
//   no stack args; plain RET
//
// Body: 0x008aa560–0x008aa5a6 exclusive (70 B / 0x46)
// Full hex:
//   5556578db3080700008dbb18050000bd080000008b0685c0c707ffffffff
//   c74704ffffffff74118b13508bcbff92bc000000c7060000000083c708
//   83c60483ed0175d15f5e5dc3
// =============================================================================

#include <cstdint>

struct MissionDialogHost {
  // layout (relevant only)
  // +0x000 vtbl*
  // +0x518 int32 tfidPairs[8][2]
  // +0x708 void *responseWidgets[8]
  void **vtbl;
};

// Host vtbl +0xBC: destroy/release child widget (product name open)
// thiscall: ECX = dialog, stack = widget*

void MissionDialog_ClearResponseButtonSlots_Inferred(void)
{
  // Register this: EBX = dialog (image). Modeled as local for readability.
  MissionDialogHost *dialog; // = EBX at entry
  // The following matches image offsets relative to EBX:

  int *widgets = (int *)((uint8_t *)dialog + 0x708); // EBX+0x1c2 dwords
  int *tfids   = (int *)((uint8_t *)dialog + 0x518); // EBX+0x146 dwords
  int n = 8;
  do {
    int w = *widgets;
    tfids[0] = -1;
    tfids[1] = -1;
    if (w != 0) {
      // (**(code **)(*dialog + 0xbc))(w);
      typedef void (__thiscall *DestroyFn)(MissionDialogHost *, int);
      DestroyFn destroy = *(DestroyFn *)((uint8_t *)dialog->vtbl + 0xbc);
      destroy(dialog, w);
      *widgets = 0;
    }
    tfids += 2;    // +8 bytes
    widgets += 1;  // +4 bytes
    n -= 1;
  } while (n != 0);
}
