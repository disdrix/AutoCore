// =============================================================================
// FUN_00786280 / Profiler_Zone_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00786280
// Address:   0x00786280  (autoassault.exe, image base 0x400000)
// System:    client instrumentation / profiler internals
// Generated: 2026-07-29 W17-S dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + body-byte ABI. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static dual only).
// =============================================================================

// PURPOSE:
// In-place construct a 0x5c profiler zone node:
//   name, parent, empty child vector, empty name→child map, zeroed stats,
//   flag(+0x58)=1, timer = new(0x30)+FUN_00780730 (or null on OOM).
// Callers: FindOrCreateChildZone (parent=current), EnsureThreadSlot (parent=NULL, name="Hermann").

// ABI (assembly-backed; Ghidra thiscall naming is parent-in-ECX):
//   ECX    = Zone* parent (nullable)
//   stack0 = Zone* self   (pre-allocated 0x5c)
//   stack1 = const char* name
//   ret 8; EAX = self

#include <cstdint>
#include <cstring>

struct TimerBlock; // 0x30 — see FUN_00780730 / Profiler_TimerBlock_Ctor

// Ghidra names retained for callees not dual-sealed in this task.
extern "C" int FUN_0044e100(void);          // RB-tree header node allocator (0x30)
extern "C" TimerBlock *FUN_00780730(void);  // ESI = timer this
extern "C" void *operator_new(unsigned size);
extern "C" void *ExceptionList;
extern "C" unsigned char LAB_009ac29c;

struct ZoneNode {
  const char *name;       // +0x00
  TimerBlock *timer;      // +0x04
  ZoneNode *parent;       // +0x08
  uint32_t unk_0c;        // +0x0c — NOT written by ctor
  void *childBegin;       // +0x10
  void *childEnd;         // +0x14
  void *childCap;         // +0x18
  uint32_t mapPad_1c;     // +0x1c — map object base (insert uses this+)
  void *mapHead;          // +0x20
  uint32_t mapSize;       // +0x24
  uint32_t zero_28[11];   // +0x28 .. +0x54 inclusive (11 dwords)
  uint8_t flag_58;        // +0x58
  // pad to 0x5c
};

// Decompiler shape (param_1=ECX parent, param_2=self, param_3=name).
uint32_t *__thiscall FUN_00786280(uint32_t parent, uint32_t *self, uint32_t name)
{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  puStack_8 = &LAB_009ac29c;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  self[0] = name;                 // +0x00
  self[1] = 0;                    // +0x04 timer
  self[2] = parent;               // +0x08
  self[4] = 0;                    // +0x10 vector
  self[5] = 0;                    // +0x14
  self[6] = 0;                    // +0x18
  local_4 = 0;

  int head = FUN_0044e100();
  self[8] = static_cast<uint32_t>(head);  // +0x20
  *reinterpret_cast<uint8_t *>(head + 0x2d) = 1;
  *reinterpret_cast<uint32_t *>(self[8] + 4) = self[8];
  *reinterpret_cast<uint32_t *>(self[8]) = self[8];
  *reinterpret_cast<uint32_t *>(self[8] + 8) = self[8];
  self[9] = 0;                    // +0x24 size

  local_4 = (local_4 & 0xFFFFFF00u) | 1u;

  self[10] = 0;  // +0x28
  self[0xb] = 0;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0xe] = 0;
  self[0xf] = 0;   // +0x3c nest
  self[0x10] = 0;
  self[0x11] = 0;
  self[0x12] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;  // +0x54
  *reinterpret_cast<uint8_t *>(self + 0x16) = 1;  // +0x58

  void *pv = operator_new(0x30);
  if (pv == nullptr) {
    self[1] = 0;
  } else {
    // Caller of FUN_00780730 must place pv in ESI (body convention).
    uint32_t t = reinterpret_cast<uint32_t>(FUN_00780730());
    self[1] = t;
  }

  ExceptionList = local_c;
  return self;
}
