// =============================================================================
// CVOGSectorMap_Destructor
// -----------------------------------------------------------------------------
// Stable ID: aa_004d64d0
// Address:   0x004d64d0–0x004d6c77  (1960 B, autoassault.exe base 0x400000)
// System:    client / CVOGSectorMap
// Generated: 2026-07-29 W26-J dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving sequential model of dtor CF. Not modernization.
//            Decompiler nests many frees under false operator_delete-noreturn;
//            machine code is free → zero → continue (see epilogue bytes).
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004d64d0
// =============================================================================
//
// PURPOSE:
//   CVOGSectorMap C++ destructor body. Reinstalls vtbl PTR_FUN_009cc770,
//   decrements construction counter _DAT_00b037e4, destroys the CNDHash at
//   dword index 0x3971 under traversal lock, virtual-deletes owned members,
//   drains embedded thread-safe lists via PopFront, tears down subsystem
//   helpers, and frees buffer triples across the 0xE920 object.
//
// ABI:
//   __thiscall; ECX=this; frame sub/add esp,8; bare ret; void.
//   Entry: 83 EC 08 53 56 8B F1 33 DB C7 06 70 C7 9C 00
//   Exit:  5E 5B 83 C4 08 C3
//
// TWIN: aa_004d8a10 CVOGSectorMap_Constructor (same vtbl; counter ++)
// CALLER: Catch@0094b325 (Client_InitInstance failure: dtor + operator_delete)
// =============================================================================

#include <cstdint>
#include <windows.h>

// Callees (Ghidra names until product duals exist).
extern "C" void* __fastcall FUN_0040b020(void* list); // ThreadSafeObjectList_PopFront
extern "C" void FUN_00497360(void);
extern "C" void __fastcall FUN_004bcbf0(void* list);  // ThreadSafeObjectList_Dtor
extern "C" void FUN_004d2970(void);
extern "C" int __fastcall FUN_004e3610(uint32_t key, void** out);
extern "C" void FUN_004e4410(void);
extern "C" void FUN_004e4460(void);
extern "C" void FUN_004e7200(void);
extern "C" void FUN_004e7290(void);
extern "C" void FUN_004e72c0(void);
extern "C" void FUN_004e72f0(void);
extern "C" void FUN_004e7320(void);
extern "C" void FUN_004e7350(void);
extern "C" void FUN_004e7380(void);
extern "C" void FUN_005b0680(void);
extern "C" void FUN_005bf720(void);
extern "C" void FUN_007a4480(int level, const char* msg);
extern "C" void operator_delete(void* p);

extern void* PTR_FUN_009cc770;
extern uint32_t _DAT_00b037e4;
extern void** DAT_00b05060;

// Opaque 0xE920 host; dword-index addressing matches decompiler.
struct CVOGSectorMap {
  void* vtbl;            // +0x00 → PTR_FUN_009cc770
  uint32_t raw[0x3A48];  // remainder
};

static void virtual_delete_if(uint32_t*& slot) {
  if (slot != nullptr) {
    void** obj = reinterpret_cast<void**>(slot);
    auto fn = *reinterpret_cast<void(__thiscall**)(void*, int)>(*obj);
    fn(obj, 1);
    slot = nullptr;
  }
}

static void free_buffer_triple(uint32_t* base_slot) {
  // base_slot[0]=begin, [1]=end, [2]=cap  (dword indices relative)
  void* p = reinterpret_cast<void*>(base_slot[0]);
  if (p != nullptr) {
    operator_delete(p);
  }
  base_slot[0] = 0;
  base_slot[1] = 0;
  base_slot[2] = 0;
}

void __fastcall CVOGSectorMap_Destructor(CVOGSectorMap* self)
{
  uint32_t* w = reinterpret_cast<uint32_t*>(self);

  self->vtbl = PTR_FUN_009cc770;
  w[0x3a04] = 0;
  _DAT_00b037e4 = _DAT_00b037e4 - 1;

  // Early buffer at [0x3a1d]
  free_buffer_triple(&w[0x3a1d]);

  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3a45]));

  // --- CNDHash at [0x3971]: lock, traverse, destroy entries, unlock, delete hash ---
  {
    uint8_t* hash = reinterpret_cast<uint8_t*>(w[0x3971]);
    if (hash[0x1d] != 0) {
      FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    hash[0x1d] = 1;

    int node = 0;
    for (;;) {
      hash = reinterpret_cast<uint8_t*>(w[0x3971]);
      if (hash[0x1d] == 0) {
        FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      if (node == 0) {
        node = *reinterpret_cast<int*>(hash + 0x14);
      } else {
        node = *reinterpret_cast<int*>(node + 0x14);
      }
      uint32_t* payload = (node == 0) ? nullptr
                                      : *reinterpret_cast<uint32_t**>(node + 8);
      if (payload == nullptr) break;

      uint32_t key = payload[0];
      if (reinterpret_cast<uint8_t*>(w[0x3971])[0x1d] != 0) {
        FUN_007a4480(0, "HashError:Destroy, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      void* tmp = nullptr;
      int rc = FUN_004e3610(key, &tmp);
      if (rc >= 0) {
        operator_delete(tmp);
      }
    }
    reinterpret_cast<uint8_t*>(w[0x3971])[0x1d] = 0;
    virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3971]));
  }

  // Cascade of owned pointer virtual-deletes (order matches raw/live).
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3973]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3974]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3975]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3976]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3972]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3947]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3949]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3970]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3948]));

  void* p3942 = reinterpret_cast<void*>(w[0x3942]);
  if (p3942 != nullptr) {
    FUN_005b0680();
    operator_delete(p3942);
  }
  w[0x3942] = 0;

  // List [0x397f]: drain PopFront (payload discarded), clear +0xC, virtual-delete
  if (w[0x397f] != 0) {
    void* list = reinterpret_cast<void*>(w[0x397f]);
    void* item = FUN_0040b020(list);
    while (item != nullptr) {
      item = FUN_0040b020(list);
    }
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(list) + 0xC) = 0;
    virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x397f]));
  }

  // List [0x3991]: drain PopFront + payload (*vtbl)(1)
  if (w[0x3991] != 0) {
    void* list = reinterpret_cast<void*>(w[0x3991]);
    void** item = reinterpret_cast<void**>(FUN_0040b020(list));
    while (item != nullptr) {
      auto fn = *reinterpret_cast<void(__thiscall**)(void*, int)>(*item);
      fn(item, 1);
      item = reinterpret_cast<void**>(FUN_0040b020(list));
    }
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(list) + 0xC) = 0;
    virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3991]));
  }

  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3992]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3993]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x397e]));

  FUN_004d2970();
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3943]));
  FUN_005bf720();
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3a3d]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3a26]));

  if (w[0x3a27] != 0) {
    *reinterpret_cast<uint32_t*>(w[0x3a27] + 0x2e4) = 0;
    // (*( *(obj+0x2c) )->vtbl + 0x10)()
    void** inner = *reinterpret_cast<void***>(w[0x3a27] + 0x2c);
    auto vfn = *reinterpret_cast<void(__thiscall**)(void*)>(
        reinterpret_cast<uint8_t*>(*inner) + 0x10);
    vfn(inner);
  }

  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3a25]));
  virtual_delete_if(reinterpret_cast<uint32_t*&>(w[0x3a24]));
  free_buffer_triple(&w[0x3a42]);

  FUN_004e7380();
  FUN_00497360();
  FUN_00497360();

  free_buffer_triple(&w[0x3a33]);
  free_buffer_triple(&w[0x3a2f]);
  free_buffer_triple(&w[0x3a2a]);
  free_buffer_triple(&w[0x3a21]);
  free_buffer_triple(&w[0x3a1d]); // second free path (idempotent zeros)
  free_buffer_triple(&w[0x3a19]);

  FUN_004e7350();
  FUN_004e7350();

  if (static_cast<int>(w[0x3a05]) >= 0) {
    auto vfn = *reinterpret_cast<void(__thiscall**)(void*, uint32_t, uint32_t, uint32_t)>(
        reinterpret_cast<uint8_t*>(*DAT_00b05060) + 0x14);
    vfn(DAT_00b05060, w[0x3a03], w[0x3a05] * 4, 0x12);
  }

  free_buffer_triple(&w[0x39ff]);
  free_buffer_triple(&w[0x39ea]);
  free_buffer_triple(&w[0x39e6]);
  free_buffer_triple(&w[0x39e2]);
  FUN_00497360();
  free_buffer_triple(&w[0x39db]);
  free_buffer_triple(&w[0x39d7]);
  free_buffer_triple(&w[0x39d3]);

  FUN_004e7320();
  free_buffer_triple(&w[0x39cc]);
  free_buffer_triple(&w[0x39c8]);
  FUN_00497360();
  free_buffer_triple(&w[0x39c1]);
  free_buffer_triple(&w[0x39bd]);

  FUN_004e4460();
  FUN_004e4410();
  FUN_004bcbf0(reinterpret_cast<void*>(&w[0x3980])); // embedded list (ctor inits vtbl here)
  FUN_00497360();

  free_buffer_triple(&w[0x3978]);
  FUN_004e7200();
  FUN_004e7200();
  free_buffer_triple(&w[0x3953]);
  free_buffer_triple(&w[0x394f]);
  free_buffer_triple(&w[0x394b]);

  FUN_004e72f0();
  FUN_00497360();
  free_buffer_triple(&w[0x15]);

  FUN_004e72c0();
  FUN_004e7290();
}
