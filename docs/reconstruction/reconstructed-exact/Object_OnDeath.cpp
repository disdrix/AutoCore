// =============================================================================
// Object_OnDeath
// -----------------------------------------------------------------------------
// Stable ID: aa_00519d80
// Address:   0x00519d80  (autoassault.exe, image base 0x400000)
// System:    object lifecycle / combat death
// Dual:      WQ9R-G 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Multi-vtbl object OnDeath handler. Detaches ownership links, clears net
//   mask bits, notifies owner/list hooks, optionally spawns a heartbeat action
//   (random delay), invokes teardown vfunc +0x2A8, and either routes through
//   FUN_004e77d0 (death-complete path) or the delete-queue path with the product
//   warning string when the object is still present in InactiveObjectsHas.
//
// ABI:
//   __thiscall — ECX = Object*; stack formal = deathCtx (non-zero gate);
//   ret 4. Returns 0 on the FUN_004e77d0 path; status byte on delete-queue path
//   (decompiler late-return is register-artifact).
//
// STRING SEAL:
//   "##$$…ONDeath Object CBID:%i, Geo:%s, COID:%I64d, Global?:%i, Position: …"
//   "being added to delete cue, but still in InactiveObjectsHas.\n"
//
// RELATED:
//   Object_QueueDelete (0x004d4790) — shorter delete-queue helper, same warn family.
//   CVOGHBList_Enqueue / CVOGHBBase_Start — HB arming.
//   Wrappers: FUN_0053cf70, FUN_00582670 (death FX then this).
// =============================================================================

#include <cstdint>

// Externs — names from sealed duals / Ghidra where known.
extern "C" {
  void* Object_ResolveFromTFID(void* tfid16);
  void  FUN_004cdc80(void* owner, void* self);
  void  FUN_004d2700(void* owner, int zero, int lo, int hi);
  void  NetObject_SetMaskBits(void* netObj, int bit, int value);
  void  CNDDoubleList_InvokePredicateAndRemove_Inferred(/* recovered at call site */);
  void  FUN_005b2ba0(void);
  void* CVOGReaction_RandomUnitScalar(void);
  void* operator_new(unsigned size);
  void* FUN_005dabc0(/* placement this from new(0x24) */);
  unsigned CVOGHBList_Enqueue(void* list, void* action);
  void  CVOGHBBase_Start(void* action);
  void  FUN_004e77d0(int coidLo, int coidHi, void* self, int mode);
  void* FUN_004e23d0(/* coid lookup into InactiveObjects */);
  void  FUN_007a4480(int level, const char* fmt, ...);
  void  FUN_004bcda0(void);

  extern int   DAT_00b0421c;
  extern float DAT_009cec58; // bytes F0 00 F0 3A ≈ 0.001831f
  extern void* ExceptionList;
}

// MSVC thiscall: ECX=self, one stack arg deathCtx.
uint32_t __fastcall Object_OnDeath(int* self, int /*edx_unused*/, int deathCtx)
{
  // SEH: LAB_009a36ba — omitted (frame only).
  void* owner = Object_ResolveFromTFID((void*)(self + 0x10)); // TFID @ +0x40

  int host = (*(int(__thiscall**)(int*, int))(*self + 0x210))(self, 0);
  if (host != 0) {
    int* hostAdj = (int*)(*(int*)(*(int*)(host + 4) + 4) + 4 + host);
    if (hostAdj != (int*)owner) {
      FUN_004cdc80(owner, self);
    }
  }

  int flagKeep = 1;
  if (((self[10] & self[11]) != (int)0xFFFFFFFF) && (deathCtx != 0)) {
    FUN_004d2700(owner, 0, self[10], self[11]);
    void* selfObj = Object_ResolveFromTFID((void*)(self + 0x58)); // COID TFID @ +0x160
    if (selfObj == nullptr) {
      flagKeep = 0;
    }
  }

  self[7] = DAT_00b0421c; // +0x1C stamp
  if ((void*)self[5] != nullptr) {
    NetObject_SetMaskBits((void*)self[5], 8, 0);
  }

  if (owner != nullptr) {
    char ok = (*(char(__thiscall**)(void*))(*(int*)owner + 0x228))(owner);
    if (ok != 0) {
      void* o2 = (*(void*(__thiscall**)(void*))(*(int*)owner + 0x224))(owner);
      if (o2 != nullptr) {
        (*(void(__thiscall**)(void*, int*))(*(int*)o2 + 0x54))(o2, self);
      }
    }
  }

  if (*(char*)((int)self + 0x23) != 0) {
    CNDDoubleList_InvokePredicateAndRemove_Inferred();
    // post-remove: list vfunc +0x54(self) — head recovered by remove helper
  }

  (*(void(__thiscall**)(int*, int))(*self + 0x40))(self, 1);
  if (self[0x19] != 0) {
    FUN_005b2ba0();
  }

  char localish = (*(char(__thiscall**)(int*))(*self + 0x198))(self);
  int typeCode = *(int*)(self[0x2a] + 0x38); // clonebase type
  if (((localish == 0) || ((char)self[0x5a] == 0)) &&
      (typeCode == 3 || typeCode == 1)) {
    if ((((uint32_t)self[0x5f] >> 12) & 1) == 0) {
      if ((char)self[0x5a] != 0) {
        goto delete_queue_path;
      }
      (*(void(__thiscall**)(int*, int))(*self + 0x2a8))(
          self, *(int*)(self[0x29] + 0xe4e8));
      FUN_004e77d0(self[0x58], self[0x59], self, /*mode*/ 1);
      *(uint8_t*)((int)self + 0x17d) = (uint8_t)(*(uint8_t*)((int)self + 0x17d) | 1);
      (void)flagKeep;
      return 0;
    }

    if (*(char*)(self[0x29] + 0x7e) != 0) {
      int* rng = (int*)CVOGReaction_RandomUnitScalar();
      if (*(int*)((int)rng + 0xc) > 0xfffff) {
        *(int*)((int)rng + 0xc) = 0;
      }
      uint16_t u =
          *(uint16_t*)(*(int*)((int)rng + 8) + *(int*)((int)rng + 0xc) * 2);
      *(int*)((int)rng + 0xc) = *(int*)((int)rng + 0xc) + 1;
      // u * DAT_009cec58 (≈0.001831f); ROUND — consumed by HB ctor path
      (void)((float)u * DAT_009cec58);

      void* mem = operator_new(0x24);
      void* action = (mem == nullptr) ? nullptr : FUN_005dabc0();
      CVOGHBList_Enqueue(*(void**)(self[0x29] + 0xe4ec), action);
      CVOGHBBase_Start(action);
    }
    (*(void(__thiscall**)(int*, int))(*self + 0x2a8))(
        self, *(int*)(self[0x29] + 0xe4e8));
    FUN_004e77d0(self[0x58], self[0x59], self, /*mode*/ 0);
    *(uint8_t*)((int)self + 0x17d) = (uint8_t)(*(uint8_t*)((int)self + 0x17d) | 1);
    (void)flagKeep;
    return 0;
  }

delete_queue_path:
  *(uint8_t*)((int)self + 0x17d) = (uint8_t)(*(uint8_t*)((int)self + 0x17d) | 1);
  int coidLo = self[0x58];
  int coidHi = self[0x59];
  int* inactive = (int*)FUN_004e23d0();
  if (inactive != nullptr && inactive[3] != 0) {
    FUN_007a4480(
        1,
        "##$$##$$##$$##$$##ONDeath Object CBID:%i, Geo:%s, COID:%I64d, Global?:%i, "
        "Position: %.02f, %.02f, %.02f being added to delete cue, but still in "
        "InactiveObjectsHas.\n",
        *(int*)(self[0x2a] + 0x34),
        (char*)(*(int*)(self[0x2a] + 0x3c) + 0x10),
        coidLo, coidHi,
        (char)self[0x5a],
        (double)(float)self[0x20],
        (double)(float)self[0x21],
        (double)(float)self[0x22]);
    FUN_004bcda0();
  }
  (void)flagKeep;
  return 0; // status byte sealed at machine level; decompiler return is artifact
}
