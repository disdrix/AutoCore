// =============================================================================
// CVOGHBBase_AppendRemainingText
// -----------------------------------------------------------------------------
// Stable ID: aa_00578550
// Address:   0x00578550 – 0x005786ee  (autoassault.exe, image base 0x400000)
// System:    heartbeat / timed-actions UI tooltip
// Generated: 2026-07-29 W23-R dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   When enable && nPeriodCounter != -1000, format remaining HB time as
//   "<value> <unit> Remaining\n" (localized) and append onto dest C-string.
//   Unit cascade: days (>86400s) / hrs (>3600) / min (>60) / sec.
//
// ABI:
//   __thiscall; stack (dest, unused, unused, enable); ret 0x10; AL = 1 if appended.
//
// CALLEES:
//   FUN_007a69d0 loc context; FUN_007a6de0 localize;
//   CVOGHBBase_GetRemainingSeconds; FUN_00578140 / FUN_00412c60 quantize; sprintf.
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

struct CVOGHBBase {
    // ...
    // +0x10 int nPeriodCounter;
    std::uint8_t _pad[0x10];
    int nPeriodCounter;
};

// Sealed: docs/reconstruction/reconstructed-exact/CVOGHBBase_GetRemainingSeconds.cpp
extern "C" float __fastcall CVOGHBBase_GetRemainingSeconds(CVOGHBBase *self);

// Loc singleton + lookup (FUN_007a69d0 / FUN_007a6de0)
extern "C" void *FUN_007a69d0(void);
extern "C" char *__thiscall FUN_007a6de0(void *loc, const char *key, int mode);

// Display quantizers
extern "C" long double FUN_00578140(float v); // ~ round to 0.01
extern "C" long double FUN_00412c60(float v); // ~ round to 0.1

// Thresholds / scales (image)
static constexpr float kDayThresh  = 86400.0f; // 0x009d3fd0
static constexpr float kHourThresh = 3600.0f;  // 0x00aaaba4
static constexpr float kMinThresh  = 60.0f;    // 0x00aaa9f0
static constexpr float kInvDay     = 1.0f / 86400.0f; // 0x009d3fc0
static constexpr float kInvHour    = 1.0f / 3600.0f;  // 0x009d3fbc
static constexpr float kInvMin     = 1.0f / 60.0f;    // 0x00aaa9ec

extern "C" std::uint8_t __thiscall CVOGHBBase_AppendRemainingText(
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

    const char *fmt;
    const char *unitKey;
    double value;

    if (!(rem <= kDayThresh)) {
        // rem > 86400 → days
        char *label = FUN_007a6de0(loc, "Remaining", -1);
        char *unit  = FUN_007a6de0(loc, "days", -1);
        value = static_cast<double>(FUN_00578140(rem * kInvDay));
        fmt = "%g %s %s\n";
        char buf[1024];
        std::sprintf(buf, fmt, value, unit, label);
        std::strcat(dest, buf);
        return 1;
    }
    if (!(rem <= kHourThresh)) {
        char *label = FUN_007a6de0(loc, "Remaining", -1);
        char *unit  = FUN_007a6de0(loc, "hrs", -1);
        value = static_cast<double>(FUN_00412c60(rem * kInvHour));
        fmt = "%g %s %s\n";
        char buf[1024];
        std::sprintf(buf, fmt, value, unit, label);
        std::strcat(dest, buf);
        return 1;
    }
    if (!(rem <= kMinThresh)) {
        char *label = FUN_007a6de0(loc, "Remaining", -1);
        char *unit  = FUN_007a6de0(loc, "min", -1);
        value = static_cast<double>(FUN_00412c60(rem * kInvMin));
        fmt = "%g %s %s\n";
        char buf[1024];
        std::sprintf(buf, fmt, value, unit, label);
        std::strcat(dest, buf);
        return 1;
    }

    // seconds path
    char *label = FUN_007a6de0(loc, "Remaining", -1);
    char *unit  = FUN_007a6de0(loc, "sec", -1);
    value = static_cast<double>(rem);
    fmt = "%.0f %s %s\n";
    char buf[1024];
    std::sprintf(buf, fmt, value, unit, label);
    std::strcat(dest, buf);
    return 1;
}

// Ghidra name alias
extern "C" std::uint8_t __thiscall FUN_00578550(
    CVOGHBBase *self,
    char *dest,
    void *a,
    void *b,
    char enable)
{
    return CVOGHBBase_AppendRemainingText(self, dest, a, b, enable);
}
