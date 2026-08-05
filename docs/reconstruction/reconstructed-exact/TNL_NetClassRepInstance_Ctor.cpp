// =============================================================================
// TNL_NetClassRepInstance_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2410
// Address:   0x005a2410  (autoassault.exe, image base 0x400000)
// Body:      0x005a2410–0x005a2466 (87 B through ret 0x10)
// System:    tnl / NetClassRep
// Generated: 2026-07-29 W21-K dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept (2026-07-29).
// =============================================================================
//
// PURPOSE:
//   Construct a TNL::NetClassRepInstance-style ClassRep object in-place:
//     base ClassRep init → NetClassRepInstance vtbl → strdup name →
//     store group/type/version → zero classId[4] → prepend to global ClassList.
//
// ABI: MSVC __thiscall
//   ECX = this
//   stack: className, classGroupMask, classType, classVersion
//   epilogue: ret 0x10
//
// CALLEES: FUN_0042aea0 (base ClassRep init), _strdup (CRT)
// GLOBALS: PTR_FUN_009d7bf4 (vtbl), DAT_00d179a4 (ClassList head)
// SIBLING: FUN_005a2470 dtor frees name and restores base vtbl 009d7af4
//
// Product alignment (TNL.NET NetClassRepInstance ctor):
//   NetClassRepInstance(string className, uint groupMask, NetClassType classType, int classVersion)
//   + ClassList.Add(this)
//
// CRT example (GuaranteedOrdered RPC ClassRep @ DAT_00b04f40):
//   push 0; push 2; push 1; push "RPC_TNLConnection_rpcMsgGuaranteedOrdered";
//   ecx = &DAT_00b04f40; call this

#include <cstdint>
#include <cstring>

// External symbols (image)
extern "C" void __fastcall FUN_0042aea0(void* self);
extern "C" char* _strdup(const char* s);
extern void* PTR_FUN_009d7bf4;   // NetClassRepInstance vtbl @ 0x009d7bf4
extern void* DAT_00d179a4;      // ClassList head @ 0x00d179a4

struct NetClassRepInstance {
  void* vtbl;                 // +0x00
  uint32_t classGroupMask;    // +0x04
  uint32_t classVersion;      // +0x08
  uint32_t classType;         // +0x0C
  uint32_t classId[4];        // +0x10 .. +0x1C  (NetClassGroupCount seed)
  char* className;            // +0x20
  // base counters / pads via FUN_0042aea0 at +0x24..+0x30
  uint32_t _pad_base[4];      // +0x24 .. +0x30 (set by base init, not this body)
  NetClassRepInstance* next;  // +0x34  ClassList link
};

static_assert(sizeof(NetClassRepInstance) >= 0x38, "ClassRep storage span 0x38");

NetClassRepInstance* __thiscall TNL_NetClassRepInstance_Ctor(
    NetClassRepInstance* self,
    char* className,
    uint32_t classGroupMask,
    uint32_t classType,
    uint32_t classVersion)
{
  char* nameCopy;

  FUN_0042aea0(self);
  self->vtbl = &PTR_FUN_009d7bf4;
  nameCopy = _strdup(className);
  self->className = nameCopy;
  self->classVersion = classVersion;
  self->classType = classType;
  self->classGroupMask = classGroupMask;
  self->classId[0] = 0;
  self->classId[1] = 0;
  self->classId[2] = 0;
  self->classId[3] = 0;
  self->next = reinterpret_cast<NetClassRepInstance*>(DAT_00d179a4);
  DAT_00d179a4 = self;
  return self;
}
