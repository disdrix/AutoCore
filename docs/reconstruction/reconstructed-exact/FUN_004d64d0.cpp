// =============================================================================
// FUN_004d64d0  (scaffold twin of CVOGSectorMap_Destructor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004d64d0
// Address:   0x004d64d0–0x004d6c77  (1960 B, autoassault.exe base 0x400000)
// System:    client / CVOGSectorMap
// Generated: 2026-07-29 W26-J dual A/B
// Canonical: CVOGSectorMap_Destructor.cpp
// Exactness: Sequential CF model; avoids decompiler noreturn nesting on delete.
// =============================================================================

#include <cstdint>

extern void* PTR_FUN_009cc770;
extern uint32_t _DAT_00b037e4;
extern void** DAT_00b05060;

extern "C" void* __fastcall FUN_0040b020(void* list);
extern "C" void FUN_00497360(void);
extern "C" void __fastcall FUN_004bcbf0(void* list);
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

static void vdel(uint32_t* slot) {
  if (*slot != 0) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(*slot);
    (**(void(__thiscall***)(uint32_t*, int))*obj)(obj, 1);
    *slot = 0;
  }
}

static void free3(uint32_t* s) {
  if (s[0] != 0) operator_delete(reinterpret_cast<void*>(s[0]));
  s[0] = s[1] = s[2] = 0;
}

void __fastcall FUN_004d64d0(uint32_t* param_1)
{
  *param_1 = (uint32_t)(uintptr_t)&PTR_FUN_009cc770;
  param_1[0x3a04] = 0;
  _DAT_00b037e4 = _DAT_00b037e4 - 1;

  free3(&param_1[0x3a1d]);
  vdel(&param_1[0x3a45]);

  // Hash destroy loop @ param_1[0x3971] (see named clean / annotated for full lock CF)
  {
    uint8_t* hash = reinterpret_cast<uint8_t*>(param_1[0x3971]);
    if (hash[0x1d] != 0) {
      FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    hash[0x1d] = 1;
    int node = 0;
    for (;;) {
      hash = reinterpret_cast<uint8_t*>(param_1[0x3971]);
      if (hash[0x1d] == 0) {
        FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      node = (node == 0) ? *reinterpret_cast<int*>(hash + 0x14)
                         : *reinterpret_cast<int*>(node + 0x14);
      uint32_t* payload = (node == 0) ? nullptr
                                      : *reinterpret_cast<uint32_t**>(node + 8);
      if (payload == nullptr) break;
      if (reinterpret_cast<uint8_t*>(param_1[0x3971])[0x1d] != 0) {
        FUN_007a4480(0, "HashError:Destroy, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      void* tmp = nullptr;
      if (FUN_004e3610(payload[0], &tmp) >= 0) operator_delete(tmp);
    }
    reinterpret_cast<uint8_t*>(param_1[0x3971])[0x1d] = 0;
    vdel(&param_1[0x3971]);
  }

  vdel(&param_1[0x3973]);
  vdel(&param_1[0x3974]);
  vdel(&param_1[0x3975]);
  vdel(&param_1[0x3976]);
  vdel(&param_1[0x3972]);
  vdel(&param_1[0x3947]);
  vdel(&param_1[0x3949]);
  vdel(&param_1[0x3970]);
  vdel(&param_1[0x3948]);

  if (param_1[0x3942] != 0) {
    FUN_005b0680();
    operator_delete(reinterpret_cast<void*>(param_1[0x3942]));
  }
  param_1[0x3942] = 0;

  if (param_1[0x397f] != 0) {
    void* list = reinterpret_cast<void*>(param_1[0x397f]);
    while (FUN_0040b020(list) != nullptr) {
    }
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(list) + 0xC) = 0;
    vdel(&param_1[0x397f]);
  }

  if (param_1[0x3991] != 0) {
    void* list = reinterpret_cast<void*>(param_1[0x3991]);
    uint32_t* item = reinterpret_cast<uint32_t*>(FUN_0040b020(list));
    while (item != nullptr) {
      (**(void(__thiscall***)(uint32_t*, int))*item)(item, 1);
      item = reinterpret_cast<uint32_t*>(FUN_0040b020(list));
    }
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(list) + 0xC) = 0;
    vdel(&param_1[0x3991]);
  }

  vdel(&param_1[0x3992]);
  vdel(&param_1[0x3993]);
  vdel(&param_1[0x397e]);
  FUN_004d2970();
  vdel(&param_1[0x3943]);
  FUN_005bf720();
  vdel(&param_1[0x3a3d]);
  vdel(&param_1[0x3a26]);

  if (param_1[0x3a27] != 0) {
    *reinterpret_cast<uint32_t*>(param_1[0x3a27] + 0x2e4) = 0;
    uint32_t* inner = *reinterpret_cast<uint32_t**>(param_1[0x3a27] + 0x2c);
    (**(void(__thiscall***)(uint32_t*))(*inner + 0x10))(inner);
  }

  vdel(&param_1[0x3a25]);
  vdel(&param_1[0x3a24]);
  free3(&param_1[0x3a42]);
  FUN_004e7380();
  FUN_00497360();
  FUN_00497360();
  free3(&param_1[0x3a33]);
  free3(&param_1[0x3a2f]);
  free3(&param_1[0x3a2a]);
  free3(&param_1[0x3a21]);
  free3(&param_1[0x3a1d]);
  free3(&param_1[0x3a19]);
  FUN_004e7350();
  FUN_004e7350();

  if (static_cast<int>(param_1[0x3a05]) >= 0) {
    (**(void(__thiscall***)(void*, uint32_t, uint32_t, uint32_t))(*DAT_00b05060 + 0x14))(
        DAT_00b05060, param_1[0x3a03], param_1[0x3a05] * 4, 0x12);
  }

  free3(&param_1[0x39ff]);
  free3(&param_1[0x39ea]);
  free3(&param_1[0x39e6]);
  free3(&param_1[0x39e2]);
  FUN_00497360();
  free3(&param_1[0x39db]);
  free3(&param_1[0x39d7]);
  free3(&param_1[0x39d3]);
  FUN_004e7320();
  free3(&param_1[0x39cc]);
  free3(&param_1[0x39c8]);
  FUN_00497360();
  free3(&param_1[0x39c1]);
  free3(&param_1[0x39bd]);
  FUN_004e4460();
  FUN_004e4410();
  FUN_004bcbf0(reinterpret_cast<void*>(&param_1[0x3980]));
  FUN_00497360();
  free3(&param_1[0x3978]);
  FUN_004e7200();
  FUN_004e7200();
  free3(&param_1[0x3953]);
  free3(&param_1[0x394f]);
  free3(&param_1[0x394b]);
  FUN_004e72f0();
  FUN_00497360();
  free3(&param_1[0x15]);
  FUN_004e72c0();
  FUN_004e7290();
}
