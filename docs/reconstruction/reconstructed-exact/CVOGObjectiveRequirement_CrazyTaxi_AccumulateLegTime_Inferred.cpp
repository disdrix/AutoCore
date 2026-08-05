// =============================================================================
// CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred  (FUN_005accf0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005accf0
// Address:   0x005accf0  (autoassault.exe, image base 0x400000)
// Body:      0x005accf0 – 0x005acee7 exclusive (503 B / 0x1F7); plate max 005acee6
// System:    CVOGObjectiveRequirement_CrazyTaxi time-budget leg accumulation
// Generated: 2026-07-29 W30-M dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of live decompile CF + byte-sealed RET 0x14.
// ABI:       __thiscall; ECX=CrazyTaxi*; 5 stack args; RET 0x14; x87 float return
// Authority: raw decompile remains authoritative for dual-reg lower-bound walk.
// =============================================================================

#include <cmath>
#include <cstdint>

// Layout (ctor FUN_005adb20 + XML dump FUN_005acf10):
//   this+0x4c : TFID array base (8 B/elem) — GenericTarget taxi stops
//   this+0x8c : TimeLimit map head* ; +0x90 size
//   TimeLimit node: key Stops @ +0x0C, Percent float @ +0x14, isnil @ +0x19
// Actor:
//   +0x250 chain → continent scale float @ +0x634
//   dual-base vtbl +0x1a0 → float3* world position (when fromIndex < 0)

struct MapNode_Val12 {
  MapNode_Val12* left;     // +0x00
  MapNode_Val12* parent;    // +0x04
  MapNode_Val12* right;     // +0x08
  std::int32_t key;        // +0x0C  Stops
  std::uint32_t val1;      // +0x10
  float percent;           // +0x14  TimeLimit Percent
  std::uint8_t color;      // +0x18
  std::uint8_t isnil;      // +0x19
};

struct TfidPair {
  std::uint32_t a;
  std::uint32_t b;
};

// DAT_00aaa688 @ 0x00aaa688 = 5.0f (read_memory: 00 00 a0 40)
extern float DAT_00aaa688; // 5.0f

extern "C" void* __cdecl FUN_004bb1c0(int zero, std::uint32_t a, std::uint32_t b);
extern "C" void __fastcall StdTree_Dec_Val12(MapNode_Val12** it);

static float* ObjectWorldPos(void* obj)
{
  auto* o = reinterpret_cast<std::uint8_t*>(obj);
  auto* b1 = *reinterpret_cast<std::uint8_t**>(o + 4);
  auto* b2 = *reinterpret_cast<std::uint8_t**>(b1 + 4);
  return reinterpret_cast<float*>(b2 + 0x84 + reinterpret_cast<std::uintptr_t>(o));
}

// Retail: FUN_005accf0
float __thiscall CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred(
    void* self,
    void* actor,
    int stopsKey,
    float acc,
    int fromIndex,
    int toIndex)
{
  auto* req = reinterpret_cast<std::uint8_t*>(self);
  auto* act = reinterpret_cast<std::uint8_t*>(actor);

  // scale = *(*(*(*(*(actor+0x250)+4)+4) + 0xAC + *(actor+0x250)) + 0x3C) + 0x634
  auto* p250 = *reinterpret_cast<std::uint8_t**>(act + 0x250);
  auto* a = *reinterpret_cast<std::uint8_t**>(p250 + 4);
  auto* b = *reinterpret_cast<std::uint8_t**>(a + 4);
  auto* blk = *reinterpret_cast<std::uint8_t**>(
      b + 0xac + reinterpret_cast<std::uintptr_t>(p250));
  auto* c = *reinterpret_cast<std::uint8_t**>(blk + 0x3c);
  float scale = *reinterpret_cast<float*>(c + 0x634);

  float srcx = 0.f, srcy = 0.f, srcz = 0.f;
  if (fromIndex < 0) {
    // (**(code**)( *( *(actor+4)+4 ) + 4 + actor + 0x1a0 ))()
    auto mid = *reinterpret_cast<std::uintptr_t*>(act + 4);
    mid = *reinterpret_cast<std::uintptr_t*>(mid + 4);
    auto* adj = reinterpret_cast<std::uint8_t*>(mid + 4 + reinterpret_cast<std::uintptr_t>(act));
    using Fn = float* (__thiscall*)(void*);
    auto fn = *reinterpret_cast<Fn*>(*reinterpret_cast<std::uint8_t**>(adj) + 0x1a0);
    float* p = fn(adj);
    srcx = p[0];
    srcy = p[1];
    srcz = p[2];
  } else {
    auto* vec = *reinterpret_cast<TfidPair**>(req + 0x4c);
    TfidPair* e = vec + fromIndex;
    void* obj = FUN_004bb1c0(0, e->a, e->b);
    if (obj) {
      float* p = ObjectWorldPos(obj);
      srcx = p[0];
      srcy = p[1];
      srcz = p[2];
    }
    // if resolve fails, decomp leaves src uninitialized (residual)
  }

  auto* vec = *reinterpret_cast<TfidPair**>(req + 0x4c);
  TfidPair* de = vec + toIndex;
  void* dest = FUN_004bb1c0(0, de->a, de->b);
  if (dest) {
    float* dp = ObjectWorldPos(dest);
    float dx = srcx - dp[0];
    float dy = srcy - dp[1];
    float dz = srcz - dp[2];

    // TimeLimit Val12 map: head* at this+0x8c
    MapNode_Val12* head = *reinterpret_cast<MapNode_Val12**>(req + 0x8c);
    MapNode_Val12* node = head->parent; // root
    MapNode_Val12* best = head;
    // MSVC lower_bound dual-reg form (raw authority):
    while (node->isnil == 0) {
      if (node->key < stopsKey) {
        MapNode_Val12* r = node->right;
        // decomp keeps prior best when branching right
        node = r;
      } else {
        best = node;
        node = node->left;
      }
    }
    // raw: if best != begin (head->left), Dec
    if (best != head->left) {
      StdTree_Dec_Val12(&best);
    }

    float dist = std::sqrt(dx * dx + dy * dy + dz * dz);
    if (best == head) {
      dist = dist / scale;
    } else {
      dist = (dist / scale) * best->percent;
    }
    acc = dist + acc;
  }

  if (stopsKey < 1) {
    acc = acc + DAT_00aaa688; // +5.0f
  }
  return acc; // ret 0x14
}
