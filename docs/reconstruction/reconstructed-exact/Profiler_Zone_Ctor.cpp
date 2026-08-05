// =============================================================================
// Profiler_Zone_Ctor  (named contract for aa_00786280)
// -----------------------------------------------------------------------------
// Stable ID: aa_00786280
// Address:   0x00786280
// See FUN_00786280.cpp for SEH / Ghidra-shaped scaffold.
// =============================================================================

#include <cstdint>
#include <cstring>

struct ProfilerTimerBlock;

struct ProfilerZone {
  const char *name;              // +0x00
  ProfilerTimerBlock *timer;     // +0x04
  ProfilerZone *parent;          // +0x08
  // +0x0c unwritten
  void *childVec[3];             // +0x10 begin/end/cap
  // +0x1c map base; +0x20 head; +0x24 size
  // +0x28..+0x54 stats (nest @ +0x3c; hierarchical @ +0x28 per sibling duals)
  // +0x58 flag = 1
};

extern "C" void *FUN_0044e100(void);
extern "C" ProfilerTimerBlock *Profiler_TimerBlock_Ctor(ProfilerTimerBlock *self /* ESI */);
extern "C" void *operator_new(unsigned size);

// ECX=parent, stack0=self, stack1=name, ret 8, EAX=self
ProfilerZone *Profiler_Zone_Ctor(
    ProfilerZone *parent /* ECX */,
    ProfilerZone *self /* stack0 */,
    const char *name /* stack1 */)
{
  char *base = reinterpret_cast<char *>(self);

  self->name = name;
  self->timer = nullptr;
  self->parent = parent;
  self->childVec[0] = self->childVec[1] = self->childVec[2] = nullptr;

  void *head = FUN_0044e100();
  *reinterpret_cast<void **>(base + 0x20) = head;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(head) + 0x2d) = 1;
  *reinterpret_cast<void **>(head) = head;
  *reinterpret_cast<void **>(reinterpret_cast<char *>(head) + 4) = head;
  *reinterpret_cast<void **>(reinterpret_cast<char *>(head) + 8) = head;
  *reinterpret_cast<uint32_t *>(base + 0x24) = 0;

  std::memset(base + 0x28, 0, 0x30); // +0x28 .. +0x57 inclusive region through flag prep
  *reinterpret_cast<uint8_t *>(base + 0x58) = 1;

  void *mem = operator_new(0x30);
  if (!mem) {
    self->timer = nullptr;
  } else {
    self->timer = Profiler_TimerBlock_Ctor(static_cast<ProfilerTimerBlock *>(mem));
  }
  return self;
}
