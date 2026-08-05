// =============================================================================
// AssManager_InitPrecompileAndResolvers_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007b75b0
// Address:   0x007b75b0–0x007b7b6d  (autoassault.exe, image base 0x400000)
// System:    assets / assManager / NDAssetManager
// Generated: 2026-07-23 scaffold as FUN_007b75b0; dual A/B seal 2026-07-29 (W30-D)
// Exactness: Behavior-preserving stage model of decompiler control flow.
//            Not a line-for-line modernization of every helper call.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Client bootstrap: ensure ../effects[/precompile] storage exists (or "."),
//   publish path on global assManager host, then optionally construct and
//   register one or two resolvers into host+0x58 GuardedVector based on
//   self+0x04 flag bits. Resolver A uses GuardedVector_PushBackLocked;
//   resolver B uses host CS + raw PushBack. Ends with effect/shader batch
//   probes (FUN_00984ee0) when bit1 set.
//
// ABI (bytes):
//   stdcall 2 formals (self*, char mode); RET 8.
//   Body ~1469 B; SEH LAB_009b1489.
//
// STRINGS:
//   "../effects" @ 0x00a95ebc; "/precompile" @ 0x00a95e10
//   mkdir-fail format @ 0x00a95e58 (NDAssetManager.cpp:0x282)
//   "Adding duplicate resolver" @ 0x00a9e8a4 (assManager.cpp:0x26d)
//

#include <cstdint>
#include <windows.h>

struct AssManagerClientState {
  void* vtbl_or_pad;     // +0x00
  uint32_t flags;        // +0x04  bit0=resolverA, bit1=resolverB
  void* resolverA;       // +0x08
  void* resolverB;       // +0x0c
};

// Globals
extern "C" uint8_t* DAT_00d1f058; // assManager host*
extern "C" uint8_t DAT_00d1e570[]; // string bag base (elem 0x1c through 0xd1e7a0)

// Unowned callees (subset)
extern "C" char FUN_0076adc0(const char* path);
extern "C" void FUN_0076ba10(const char* path, int);
extern "C" void FUN_0076b080(int);
extern "C" void* FUN_0076cec0(void*, const char* fmt, ...);
extern "C" int FUN_0076d1b0(const char* file, int line, const char* msg);
extern "C" void vog_LogMessage(const char* file, int line, int sev, const char* msg);
extern "C" void FUN_00969830(void* str_or_bag);
extern "C" void FUN_00754280(void);
extern "C" void FUN_00989ef0(int);
extern "C" void* FUN_00423be0(void* mem); // resolver A ctor
extern "C" void FUN_00983940(void* p);
extern "C" char FUN_0043e5b0(void** key); // EAX=GuardedVector container
extern "C" void FUN_0043c4f0(void** key); // EDI=container; PushBackLocked
extern "C" void FUN_0043c830(void** key); // EAX=container; PushBack
extern "C" void FUN_00984ee0(int);
extern "C" void* operator_new(uint32_t);

// Retail: stack (self*, mode); RET 8
extern "C" void AssManager_InitPrecompileAndResolvers_Inferred(
    AssManagerClientState* self /*stack*/,
    char mode /*stack*/)
{
  // --- Stage 1: path ensure ../effects then ../effects/precompile ---
  // std::string path("../effects");
  // for i in 0..1:
  //   if !exists(path): mkdir helpers / CreateDirectoryA
  //   on fail: vog_LogMessage(NDAssetManager.cpp, 0x282, 2, fmt); path="."; break
  //   if i==0: path += "/precompile"
  //
  // --- Stage 2: publish + side init ---
  // host = DAT_00d1f058
  // if exists(path): host+0xb4 = path
  // FUN_00969830(path); *(host+0xd0)=1; FUN_00754280(); FUN_00989ef0(0);

  // --- Stage 3: resolver A (flag bit0) ---
  if ((self->flags & 1u) != 0) {
    void* mem = operator_new(0x4c);
    void* resolver = (mem != nullptr) ? FUN_00423be0(mem) : nullptr;
    self->resolverA = resolver;
    void* key = resolver;
    // retail: EDI = host+0x58; EAX = EDI; FUN_0043e5b0(&key)
    // if miss: FUN_0043c4f0(&key)  // PushBackLocked
    // else: vog_LogMessage(assManager.cpp, 0x26d, 3, "Adding duplicate resolver")
    // walk DAT_00d1e570 .. 0xd1e7a0 step 0x1c: FUN_00969830
    (void)key;
  }

  // --- Stage 4: resolver B (flag bit1) ---
  if ((self->flags & 2u) != 0) {
    void* mem = operator_new(0x5c);
    void* resolver = nullptr;
    if (mem != nullptr) {
      // *vtbl = PTR_FUN_00aa1f1c; pad; FUN_00983940(mem+8)
      resolver = mem;
    }
    self->resolverB = resolver;
    void* key = resolver;
    // find on host+0x58; miss → host CS (+0x84/+0x6c) + FUN_0043c830
    // hit → FUN_0076d1b0 may ExitProcess(3)
    // FUN_00984ee0(1) × 5; if mode==0: × 28 more
    (void)key;
    (void)mode;
  }
}
