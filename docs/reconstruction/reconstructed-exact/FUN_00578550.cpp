// =============================================================================
// FUN_00578550  (alias twin of CVOGHBBase_AppendRemainingText)
// -----------------------------------------------------------------------------
// Stable ID: aa_00578550
// Address:   0x00578550 – 0x005786ee  (autoassault.exe, image base 0x400000)
// System:    heartbeat / timed-actions UI tooltip
// Generated: 2026-07-29 W23-R dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// See CVOGHBBase_AppendRemainingText.cpp for named plate. This twin keeps the
// Ghidra symbol for coverage / FUN_* index links.
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

struct CVOGHBBase {
    std::uint8_t _pad[0x10];
    int nPeriodCounter; // +0x10
};

extern "C" float __fastcall CVOGHBBase_GetRemainingSeconds(CVOGHBBase *self);
extern "C" void *FUN_007a69d0(void);
extern "C" char *__thiscall FUN_007a6de0(void *loc, const char *key, int mode);
extern "C" long double FUN_00578140(float v);
extern "C" long double FUN_00412c60(float v);

static constexpr float kDayThresh  = 86400.0f;
static constexpr float kHourThresh = 3600.0f;
static constexpr float kMinThresh  = 60.0f;
static constexpr float kInvDay     = 1.0f / 86400.0f;
static constexpr float kInvHour    = 1.0f / 3600.0f;
static constexpr float kInvMin     = 1.0f / 60.0f;

extern "C" std::uint8_t __thiscall FUN_00578550(
    CVOGHBBase *self,
    char *dest,
    void * /*unused_a*/,
    void * /*unused_b*/,
    char enable)
{
    void *loc = FUN_007a69d0();
    if (enable == 0 || self->nPeriodCounter == -1000) {
        return 0;
    }

    float rem = CVOGHBBase_GetRemainingSeconds(self);
    char buf[1024];
    char *label;
    char *unit;
    double value;

    if (!(rem <= kDayThresh)) {
        label = FUN_007a6de0(loc, "Remaining", -1);
        unit  = FUN_007a6de0(loc, "days", -1);
        value = static_cast<double>(FUN_00578140(rem * kInvDay));
        std::sprintf(buf, "%g %s %s\n", value, unit, label);
    } else if (!(rem <= kHourThresh)) {
        label = FUN_007a6de0(loc, "Remaining", -1);
        unit  = FUN_007a6de0(loc, "hrs", -1);
        value = static_cast<double>(FUN_00412c60(rem * kInvHour));
        std::sprintf(buf, "%g %s %s\n", value, unit, label);
    } else if (!(rem <= kMinThresh)) {
        label = FUN_007a6de0(loc, "Remaining", -1);
        unit  = FUN_007a6de0(loc, "min", -1);
        value = static_cast<double>(FUN_00412c60(rem * kInvMin));
        std::sprintf(buf, "%g %s %s\n", value, unit, label);
    } else {
        label = FUN_007a6de0(loc, "Remaining", -1);
        unit  = FUN_007a6de0(loc, "sec", -1);
        value = static_cast<double>(rem);
        std::sprintf(buf, "%.0f %s %s\n", value, unit, label);
    }

    std::strcat(dest, buf);
    return 1;
}
