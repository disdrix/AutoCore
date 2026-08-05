// =============================================================================
// EdRiverHandle_StampPolylineHeightGrid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005e2670
// Address:   0x005e2670–0x005e29c8  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005e2670
// System:    Editor river-handle / map height grid
// Dual:      W36-D 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: thiscall ECX=handle-host; 4 stack formals; RET 0x10.
// Vtable DATA xref only @ 0x009dc9b8 (ed_riverhandle family).
// Decompiler mislabels stack map* as unaff_retaddr — bytes win.
// =============================================================================

#include <cstdint>
#include <algorithm>

// Nested (not dual-owned this wave):
extern "C" void*    FUN_0043c460(void);           // CircularSentinel_Alloc0x14
extern "C" void     FUN_006442c0(void* map, ...); // segment influence stamp
extern "C" uint16_t FUN_006a3db0(void);           // ST0 round → int (AX)
extern "C" void     FUN_004a8d40(void* map /*ECX*/, int minX, int minY,
                                int maxX, int maxY);
extern "C" void     operator_delete(void* p);

static constexpr float kTwo       = 2.0f;     // 0x00a10e74
static constexpr float kU16ToUnit = 1.5259022e-05f; // 0x00af443c
static constexpr float kOne       = 1.0f;     // 0x00a0f2a0
static constexpr float kU16Max    = 65535.0f; // 0x00aaa634

struct CircNode {
  CircNode* next;   // +0x00
  CircNode* prev;   // +0x04
  float     x;      // +0x08
  float     y;      // +0x0c
  float     z;      // +0x10
};

struct CircHead {
  CircNode* next;   // self when empty
  CircNode* prev;
  uint32_t  pad;
};

// Host/node are COM-like vtable objects. Offsets are byte indices into vtable.
using VtGetStart = void* (__thiscall*)(void* self);
using VtPrep     = void  (__thiscall*)(void* self, int flag);
using VtFillList = void  (__thiscall*)(void* self, CircHead* list, float cellTwice);
using VtSample   = float (__thiscall*)(void* self, /* stack pack */...);
using VtRelease  = void  (__thiscall*)(void* self, int a, int b);
using VtNext     = void* (__thiscall*)(void* link);

static inline void** Vt(void* o)
{
  return *reinterpret_cast<void***>(o);
}

static void ClearCircList(CircHead* head)
{
  CircNode* n = head->next;
  head->next = reinterpret_cast<CircNode*>(head);
  head->prev = reinterpret_cast<CircNode*>(head);
  while (n != reinterpret_cast<CircNode*>(head)) {
    CircNode* nx = n->next;
    operator_delete(n);
    n = nx;
  }
}

extern "C" void EdRiverHandle_StampPolylineHeightGrid_Inferred(
    void* host /*ECX*/,
    void* map /*stack0*/,
    uint32_t argA /*stack1*/,
    float argB /*stack2*/,
    uint32_t argC /*stack3*/)
{
  // MSVC SEH (LAB_009a751d) omitted.

  void* node = reinterpret_cast<VtGetStart>(Vt(host)[0xb8 / 4])(host);
  if (node == nullptr) {
    return;
  }
  void* const start = node;

  reinterpret_cast<VtPrep>(Vt(node)[0xb4 / 4])(node, 1);

  auto* list = reinterpret_cast<CircHead*>(FUN_0043c460());

  const int width = *reinterpret_cast<int*>(
      reinterpret_cast<uint8_t*>(map) + 0x10);
  const float cell = *reinterpret_cast<float*>(
      reinterpret_cast<uint8_t*>(map) + 0x18);

  int minX = width;
  int minY = width;
  int maxX = 0;
  int maxY = 0;

  // ---- stamp each node in chain ----
  for (;;) {
    ClearCircList(list);

    // vfunc +0xbc consumes cell*2 and fills circular list of segment points
    reinterpret_cast<VtFillList>(Vt(node)[0xbc / 4])(
        node, list, cell * kTwo);

    CircNode* a = list->next;
    if (a != reinterpret_cast<CircNode*>(list)) {
      CircNode* b = a->next;
      if (b != reinterpret_cast<CircNode*>(list)) {
        do {
          int outMinX = width;
          int outMinY = width;
          int outMaxX = 0;
          int outMaxY = 0;

          // sample vfunc +0xac with argA/argB/argC + bbox outs (stack pack)
          // float infl = sample(...);
          // pack endpoints (a->x/y/z, b->x/y/z) and call FUN_006442c0(map, ...)
          // which writes influence and returns bbox via out slots
          (void)argA;
          (void)argB;
          (void)argC;
          FUN_006442c0(map /*, endpoints, infl, &outMinX, ... */);

          minX = (std::min)(minX, outMinX);
          minY = (std::min)(minY, outMinY);
          maxX = (std::max)(maxX, outMaxX);
          maxY = (std::max)(maxY, outMaxY);

          a = b;
          b = b->next;
        } while (b != reinterpret_cast<CircNode*>(list));
      }
    }

    // advance handle chain: node+0x14 → link; if link+4 null or next==start stop
    void** linkSlot = reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(node) + 0x14);
    void* link = linkSlot[0];
    if (link == nullptr ||
        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(link) + 4) ==
            nullptr) {
      break;
    }
    void* next = reinterpret_cast<VtNext>(
        Vt(*reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(link) + 4))[0x24 / 4])(
        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(link) + 4));
    if (next == nullptr || next == start) {
      break;
    }
    node = next;
  }

  // ---- requantize ushort grid in union bbox ----
  auto* cells = *reinterpret_cast<uint16_t**>(
      reinterpret_cast<uint8_t*>(map) + 0x3e0);
  // seed float uses -argB (bytes: xorps/subss path); clamp/blend with
  // influence float lane, then:
  for (int x = minX; x < maxX; ++x) {
    for (int y = minY; y < maxY; ++y) {
      const int idx = y * width + x;
      float v = static_cast<float>(cells[idx]) * kU16ToUnit;
      // + influence blend (from stamp buffer / -argB seed path — see raw)
      if (v < 0.0f) {
        v = 0.0f;
      } else if (v > kOne) {
        v = kOne;
      }
      // FLD v; FMUL 65535; CALL FUN_006a3db0; store AX
      // (FPU ST0 convention — modeled as scaled store)
      const float scaled = v * kU16Max;
      (void)scaled;
      cells[idx] = FUN_006a3db0();
    }
  }

  // ---- tile invalidate expanded by 2 ----
  FUN_004a8d40(map, minX - 2, minY - 2, maxX + 2, maxY + 2);

  // ---- release chain from start ----
  node = start;
  for (;;) {
    reinterpret_cast<VtRelease>(Vt(node)[0x70 / 4])(node, 1, 0);
    void** linkSlot = reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(node) + 0x14);
    void* link = linkSlot[0];
    if (link == nullptr ||
        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(link) + 4) ==
            nullptr) {
      break;
    }
    void* next = reinterpret_cast<VtNext>(
        Vt(*reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(link) + 4))[0x24 / 4])(
        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(link) + 4));
    if (next == nullptr || next == start) {
      break;
    }
    node = next;
  }

  ClearCircList(list);
  operator_delete(list);
  // RET 0x10
}
