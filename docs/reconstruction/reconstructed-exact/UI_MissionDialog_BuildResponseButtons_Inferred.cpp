// =============================================================================
// UI_MissionDialog_BuildResponseButtons_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac110
// Address:   0x008ac110 – 0x008ac318 exclusive (520 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    client UI / mission dialog response strip
// Dual:      WQ7R-B 2026-08-04 accept-with-gaps
// Exactness: Behavior-preserving from decompile + read_memory corrections.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// ABI: EDI = MissionDialogUi* (caller-supplied this); bare RET; SEH present.
// Corrections vs raw Ghidra decompile:
//   - last-alone flag is stack byte, NOT (btn* >> 24)
//   - Y stride multiplies saved row ([esp+0x14]), NOT EBP (EBP = slot*)
//
// Design scale: DAT_00aaa67c = 1/1600, DAT_00aaa678 = 1/1200;
//               DAT_00d1e818/1c = runtime viewport W/H.

#include <cstdint>

struct UiVtable; // NDUI child / dialog

struct MissionDialogUi {
  UiVtable* vtbl;                 // +0x000
  // ...
  std::int32_t chrome_gate;       // +0x4C0   EDI[0x130]
  std::int32_t response_count;    // +0x510   EDI[0x144]
  std::int32_t origin_b_x;        // +0x5B4
  std::int32_t origin_b_y;        // +0x5B8
  std::int32_t extra_x;           // +0x5BC
  std::int32_t extra_y;           // +0x5C0
  std::int32_t origin_a_x;        // +0x5C4
  std::int32_t origin_a_y;        // +0x5C8
  std::int32_t btn_w;             // +0x5CC
  std::int32_t btn_h;             // +0x5D0
  std::int32_t stride_x;          // +0x5D4
  std::int32_t stride_y;          // +0x5D8
  std::int32_t columns;           // +0x640   EDI[400]
  std::int32_t layout_mode;       // +0x648   EDI[0x192]
  void*        response_slots[1]; // +0x708   EDI+0x1C2  (extent = response_count)
};

extern float DAT_00d1e818; // viewport width (runtime)
extern float DAT_00d1e81c; // viewport height (runtime)
extern float DAT_00aaa67c; // 0.000625f  = 1/1600
extern float DAT_00aaa678; // ~0.000833333f = 1/1200

extern void FUN_008aa560();           // pre-layout helper (EDI this)
extern void* operator_new(std::uint32_t);
extern int  FUN_0079c860();           // child ctor (ECX = raw 0x4CC)

// Ghidra: FUN_008ac110
void UI_MissionDialog_BuildResponseButtons_Inferred()
{
  // this in EDI (custom register this)
  MissionDialogUi* dialog = /* EDI */ nullptr;
  // body uses EDI directly; sketch uses dialog*

  if (dialog->chrome_gate == 0) {
    return;
  }

  FUN_008aa560();

  if (dialog->columns < 1) {
    dialog->columns = 1;
  }

  const int count = dialog->response_count;
  void** slot = &dialog->response_slots[0];

  for (int i = 0; i < count; ++i, ++slot) {
    const int row = i / dialog->columns;
    const int col = i - dialog->columns * row;
    const bool alone_last = (i == count - 1) && (col == 0);

    void* mem = operator_new(0x4CC);
    int btn = 0;
    if (mem != nullptr) {
      // ECX = mem; FUN_0079c860 constructs NDUI child
      btn = FUN_0079c860();
    }
    *slot = reinterpret_cast<void*>(btn);

    // dialog->vtbl[+0xA8] attach child
    // btn->vtbl[+0x28]("i_d_npc_2d_btn_response.xml")
    // btn->vtbl[+0x74](i + 0x9C46)

    const int size_x = static_cast<int>(
        static_cast<float>(dialog->btn_w) * DAT_00d1e818 * DAT_00aaa67c);
    const int size_y = static_cast<int>(
        static_cast<float>(dialog->btn_h) * DAT_00d1e81c * DAT_00aaa678);
    // btn->vtbl[+0x08](&size_x /* pair size_x,size_y */)

    int x = (alone_last ? dialog->origin_b_x : dialog->origin_a_x)
          + dialog->stride_x * col;
    int y = (alone_last ? dialog->origin_b_y : dialog->origin_a_y)
          + dialog->stride_y * row;

    if (dialog->layout_mode == 0 || dialog->layout_mode == 3) {
      x += dialog->extra_x;
      y += dialog->extra_y;
    }

    const int pos_x = static_cast<int>(
        DAT_00d1e818 * static_cast<float>(x) * DAT_00aaa67c);
    const int pos_y = static_cast<int>(
        DAT_00d1e81c * static_cast<float>(y) * DAT_00aaa678);
    // btn->vtbl[+0x118](&pos_x /* pair */)
  }
}
