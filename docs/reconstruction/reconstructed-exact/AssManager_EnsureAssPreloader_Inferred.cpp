// =============================================================================
// AssManager_EnsureAssPreloader_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d3c0
// Address:   0x0075d3c0–0x0075d466  (166 B / 0xA6)
// Ghidra:    FUN_0075d3c0
// System:    assets / assManager + assPreloader
// Dual:      W33-O 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   stack = AssManager* / NDResourceCache* host; RET 4; void.
//   Idempotent: if host+0x6c already non-null → return.
//   Else: operator_new(0x114) + FUN_00970cf0 (AssPreloader ctor) → host+0x6c.
//   Then walk circular list sentinel at host+8; for each node push PodU32U8
//   { *(node+8), 1 } into preloader+0xAC via locked GuardedVector_PushBack
//   Stride2 U32U8 (FUN_0043e8f0 pack + FUN_0043e7f0).
//
// Callers:
//   FUN_0075d470 (host ctor: zeros +0x6c then ensure)
//   FUN_00934420 ("Preloading enabled" → DAT_00d1f050)
//
// Name is structural (_Inferred). Reject scaffold Client_InitInstance chain name.
// Nested AssPreloader ctor body not dual-owned here.
// =============================================================================

#include <cstdint>

struct AssManagerHost {
  // +0x08: circular list sentinel (AssManager tracked-asset list)
  // +0x6c: AssPreloader*
};

struct ListNode {
  ListNode* next;   // +0x00
  // ...
  uint32_t key;     // +0x08 (sealed by bytes / SweepTrackedAssets dual)
};

struct PodU32U8 {
  uint32_t a;
  uint8_t  b;
  // 3 B pad
};

extern "C" void* operator_new(uint32_t size);
extern "C" void* FUN_00970cf0(void* mem /*, host ctx */); // AssPreloader ctor
extern "C" void FUN_0043e8f0(void); // PodU32U8 pack helper (site-specific regs)
extern "C" void FUN_0043e7f0(const PodU32U8* value /*stack*/,
                             void* container /*EDI*/); // PushBackLocked Stride2 U32U8

// Clean surface: stack host explicit; SEH frame omitted.
void AssManager_EnsureAssPreloader_Inferred(void* host /*stack; retail*/)
{
  auto* h = reinterpret_cast<uint8_t*>(host);
  if (*reinterpret_cast<void**>(h + 0x6c) != nullptr) {
    return;
  }

  void* mem = operator_new(0x114);
  void* pre = (mem != nullptr) ? FUN_00970cf0(mem) : nullptr;
  *reinterpret_cast<void**>(h + 0x6c) = pre;

  auto* head = *reinterpret_cast<ListNode**>(h + 0x08);
  for (ListNode* node = head->next; node != head; node = node->next) {
    PodU32U8 val{};
    val.a = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(node) + 0x08);
    val.b = 1;
    // Retail: FUN_0043e8f0 pack; EDI = pre + 0xAC; FUN_0043e7f0(&val)
    if (pre != nullptr) {
      void* ring = reinterpret_cast<uint8_t*>(pre) + 0xAC;
      FUN_0043e8f0();
      FUN_0043e7f0(&val, ring);
    }
  }
}
