// =============================================================================
// Phy_CPConnection_AssertConnectionPoint
// -----------------------------------------------------------------------------
// Purpose:  Bind (assert) a connection-point smart pointer for a physics owner.
//           Looks up connection-point id on owner+0x64; AddRef/Release swap into
//           a caller's smart-pointer slot; logs on miss (phyCPConnection.h).
//
// Address:  0x0044af00  (autoassault.exe, image base 0x400000)
// Stable:   aa_0044af00
// System:   physics
//
// String evidence:
//   "..\\palantir/physics/phyCPConnection.h"
//   "Connection point not found!"
//
// Exactness: Behavior-preserving rewrite from machine (read_memory + decompile).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0044af00.cpp; FUN_* left intact as raw scaffold twin.
//
// ABI (multi-register — Ghidra residual in_EAX / unaff_EBX / unaff_EDI):
//   EAX = connectionPointId  (int; -1 = explicit none / clear slot)
//   ECX = owner*
//   EBX = RefCountedObject**  (smart-pointer slot)
//   EDI = void**              (owner-out mirror)
//   return EAX: 0 success, 0xffffffff not found
//   ret (no stack arg cleanup)
// =============================================================================

// Callee: FindConnectionPointById @ 0x0040d4b0 (thiscall registry, id) —
// returns pointer to list-node payload object* field, or null.
extern "C" void* __thiscall FUN_0040d4b0(void* registry /*ecx*/, int connectionPointId);
extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

struct RefCountedObject {
  void** vtable;   // +0x00
  int refCount;    // +0x04
  // vtable+0x04: first-acquire (called only when refCount becomes 1 after ++)
  // vtable+0x08: last-release / destroy (called when refCount hits 0 after --)
};

static void ReleaseSlot(RefCountedObject** pSmartSlot) {
  RefCountedObject* old = *pSmartSlot;
  if (old != nullptr) {
    old->refCount -= 1;
    if (old->refCount == 0) {
      // thiscall-ish: ECX=old; call [vtable+8]
      ((void(__thiscall*)(RefCountedObject*))(old->vtable[2]))(old);
    }
  }
  *pSmartSlot = nullptr;
}

static void AddRefFirstAcquire(RefCountedObject* obj) {
  if (obj == nullptr) {
    return;
  }
  obj->refCount += 1;
  if (obj->refCount == 1) {
    ((void(__thiscall*)(RefCountedObject*))(obj->vtable[1]))(obj);
  }
}

// Portable illustration of machine multi-reg formals.
// Retail passes id/owner/slots in EAX/ECX/EBX/EDI (not a standard MSVC prototype).
int Phy_CPConnection_AssertConnectionPoint(
    int connectionPointId /*EAX*/,
    void* owner /*ECX*/,
    RefCountedObject** pSmartSlot /*EBX*/,
    void** pOutOwner /*EDI*/)
{
  // --- explicit none: connId == -1 ---
  if (connectionPointId == -1) {
    *pOutOwner = owner;
    // Machine: add [old+4], eax with eax still -1  (equiv. refCount--)
    ReleaseSlot(pSmartSlot);
    return 0;
  }

  // --- lookup on owner+0x64 registry ---
  void* hit = FUN_0040d4b0(reinterpret_cast<char*>(owner) + 0x64, connectionPointId);
  if (hit != nullptr) {
    *pOutOwner = owner;
    // hit is node+2 from list find; machine: mov esi, [eax]
    RefCountedObject* obj = *reinterpret_cast<RefCountedObject**>(hit);
    AddRefFirstAcquire(obj);

    RefCountedObject* old = *pSmartSlot;
    if (old != nullptr) {
      old->refCount -= 1;
      if (old->refCount == 0) {
        ((void(__thiscall*)(RefCountedObject*))(old->vtable[2]))(old);
      }
    }
    *pSmartSlot = obj;
    return 0;
  }

  // --- not found ---
  vog_LogMessage("..\\palantir/physics/phyCPConnection.h", 0x8f, 3,
                 "Connection point not found!");
  *pOutOwner = nullptr;
  ReleaseSlot(pSmartSlot);
  return -1;  // 0xffffffff
}
