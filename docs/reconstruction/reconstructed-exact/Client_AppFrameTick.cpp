// =============================================================================
// Client_AppFrameTick  (was FUN_0094b520)
// -----------------------------------------------------------------------------
// Stable ID: aa_0094b520
// Address:   0x0094b520 – 0x0094b9b5  (autoassault.exe, image base 0x400000)
// System:    client / main-loop frame
// Generated: 2026-07-29 W20-A OWN dual A/B seal
//            three-rep: raw 2026-07-23 ≡ live decompile ≡ read_memory prologue/epilogue
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte-sealed ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
// Per-iteration body of the Win32 client message pump (sole caller FUN_0094b9c0):
// gate on client master flag, optional focus/UI poll early-out, then ordered subsystem
// ticks (input/HB/session/UI event queue/…), optional frametime log, Sleep(0).
// Always returns 1.
//
// ABI: __fastcall / __thiscall shape — client* in ECX; bare ret; EAX = 1.
// Large stack: SEH + chkstk frame (~0x186a4 / cleanup 0x186b0) for 100000-byte log buffer.
//
// STRINGS (this unit):
//   "..\\logs\\frametime.txt" @ 0x00a2cfc0
//   "LoadQueue test, focus = %d" @ 0x00a2cfdc
//
// NAMED SEALED CALLEES (other duals):
//   Client_Input_FocusGateAndUiPoll_Inferred  FUN_0093a5c0(0)
//   CVOGHBList_Tick(client+0xd38, 0)
//   Client_DispatchUiEventQueue               FUN_00946c00
//

#include <cstdint>
#include <cstdio>
#include <windows.h>

// --- globals (image) ---
extern int32_t DAT_00d09874;           // timer / profile root*
extern int32_t DAT_00d1f07c;           // FILE* frametime log (lazy)
extern int32_t DAT_00d218d8;           // last LoadQueue focus bool
extern uint32_t DAT_00d218dc;          // once-init bitmask (bit0)
extern float g_flZero;                 // 0.0f
extern float g_flMsToSeconds_Inferred; // 0.001f

// SEH registration (MSVC)
extern void *ExceptionList;
extern uint8_t LAB_009bbf33[];

// --- callees (not all dualed here) ---
extern void FUN_0094b3a0(void);
extern void FUN_0079a120(int32_t profileId);
extern void FUN_0079a1c0(int32_t profileId);
extern int32_t __fastcall FUN_0093a5c0(int32_t mode /* stack */); // FocusGateAndUiPoll
extern void FUN_0079a0d0(void);
extern void __fastcall FUN_00932c80(void *client);
extern void __thiscall CVOGHBList_Tick(void *list, int32_t forcedDeltaMs);
extern void FUN_0093da30(void);
extern void __fastcall FUN_00938380(void *client);
extern void FUN_00821650(void *obj);
extern void FUN_0092c640(uint32_t timerField);
extern void FUN_00495600(void *session);
extern char __fastcall FUN_0040ace0(void *client);
extern void FUN_007a4480(int32_t a, const char *fmt, ...);
extern void FUN_004bfe10(uint32_t loadQueueConst /* 0x3b888889 */);
extern void FUN_00542e20(void *sessionField);
extern void FUN_004cd7c0(float dt);
extern void FUN_007b6a20(int32_t z);
extern void FUN_007b7000(uint32_t z);
extern void FUN_00933480(void);
extern void FUN_00942e20(void);
extern void FUN_00806b90(int32_t a, int32_t b);
extern void FUN_004d18a0(float dt);
extern void FUN_00944770(void);
extern void __fastcall FUN_00946c00(void *client); // Client_DispatchUiEventQueue
extern void FUN_0076ca60(char *buf, uint32_t *cap, int32_t mode);
extern void FUN_0079a9f0(void);
extern void FUN_0092cd20(void);

// Float imm used as LoadQueue drain argument: 0x3b888889 ≈ 0.0041666667f (1/240).
static constexpr uint32_t kLoadQueueFloatBits = 0x3b888889u;

uint32_t __fastcall Client_AppFrameTick(void *client /* ECX */)
{
  char focusNow;
  int32_t timerRoot;
  uint32_t zeroU;
  uint32_t stackScratch;
  char logBuf[100000];
  void *savedExc;
  uint8_t *sehHandler;
  uint32_t sehState;

  timerRoot = DAT_00d09874;
  sehState = 0xffffffffu;
  sehHandler = LAB_009bbf33;
  savedExc = ExceptionList;

  // Outer master enable: client+0x13
  if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0x13) != '\0') {
    ExceptionList = &savedExc;

    // Nested timer/profile gate A @ DAT+0x25; QPC stamp DAT+0x170
    if (*reinterpret_cast<char *>(DAT_00d09874 + 0x25) == '\0') {
      ExceptionList = &savedExc;
      QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(DAT_00d09874 + 0x170));
    }
    *reinterpret_cast<char *>(timerRoot + 0x25) =
        static_cast<char>(*reinterpret_cast<char *>(timerRoot + 0x25) + 1);

    FUN_0094b3a0();
    FUN_0079a120(5);

    timerRoot = DAT_00d09874;

    // Gate: client+0xf40 non-null
    if (*reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xf40) != 0) {
      // Nested timer/profile gate B @ DAT+0x27; QPC stamp DAT+0x180
      if (*reinterpret_cast<char *>(DAT_00d09874 + 0x27) == '\0') {
        QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(DAT_00d09874 + 0x180));
      }
      *reinterpret_cast<char *>(timerRoot + 0x27) =
          static_cast<char>(*reinterpret_cast<char *>(timerRoot + 0x27) + 1);

      // Focus / UI poll gate — mode 0 from this caller. Non-zero => skip frame body.
      if (FUN_0093a5c0(0) == 0) {
        FUN_0079a120(7);

        // client+0xa1 clear => early input-ish path
        if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xa1) == '\0') {
          FUN_0079a0d0();
        }

        // client+0xb7 set => "sim / focused" cluster
        if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') {
          FUN_0079a1c0(9);
          FUN_00932c80(client);
          FUN_0079a120(9);

          if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') {
            if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xa1) == '\0') {
              FUN_0079a1c0(6);
              CVOGHBList_Tick(
                  *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(client) + 0xd38),
                  0);
              FUN_0079a120(6);
            }
            if ((*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') &&
                (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xa1) == '\0')) {
              FUN_0093da30();
            }
          }
        }

        FUN_0079a1c0(8);
        FUN_00938380(client);
        FUN_0079a120(8);

        // Optional object @ client+0xdec: vcall slot +8
        if (*reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xdec) != 0) {
          FUN_0079a1c0(10);
          {
            int32_t *obj =
                *reinterpret_cast<int32_t **>(reinterpret_cast<uint8_t *>(client) + 0xdec);
            int32_t *vtbl = *reinterpret_cast<int32_t **>(obj);
            reinterpret_cast<void(__fastcall *)(int32_t *)>(vtbl[2])(obj); // slot +8
          }
          if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') {
            FUN_00821650(
                *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(client) + 0xdec));
          }
          FUN_0079a120(10);
        }

        if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') {
          FUN_0079a1c0(0xb);
          if (*reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0x4d0) != 0) {
            stackScratch = *reinterpret_cast<uint32_t *>(DAT_00d09874 + 0x30);
            FUN_0092c640(stackScratch);
          }
          FUN_0079a120(0xb);
        }

        // Session root client+0xe04
        if (*reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xe04) != 0) {
          FUN_0079a1c0(0xc);
          FUN_00495600(
              *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(client) + 0xe04));

          if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') {
            // focusNow = !( *(client+0xde8)+5 == 0 && FUN_0040ace0(client) == 0 )
            if ((*reinterpret_cast<char *>(
                     *reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xde8) +
                     5) == '\0') &&
                (focusNow = FUN_0040ace0(client), focusNow == '\0')) {
              focusNow = '\0';
            } else {
              focusNow = '\x01';
            }

            if ((DAT_00d218dc & 1) == 0) {
              DAT_00d218dc = DAT_00d218dc | 1;
              DAT_00d218d8 = (focusNow == '\0');
              sehState = 0xffffffffu;
            }
            if (DAT_00d218d8 != focusNow) {
              FUN_007a4480(0, "LoadQueue test, focus = %d", focusNow);
            }
            DAT_00d218d8 = focusNow;
            if (focusNow != '\0') {
              FUN_004bfe10(kLoadQueueFloatBits);
            }
          }
          FUN_0079a120(0xc);
        }

        if (*reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xe04) != 0) {
          FUN_00542e20(*reinterpret_cast<void **>(
              *reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xe04) +
              0xe4e8));
        }

        if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') {
          if (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xa1) == '\0') {
            FUN_004cd7c0(*reinterpret_cast<float *>(DAT_00d09874 + 0x30) /
                         *reinterpret_cast<float *>(reinterpret_cast<uint8_t *>(client) + 0x9b0));
          }
          if ((*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') &&
              (*reinterpret_cast<int32_t **>(reinterpret_cast<uint8_t *>(client) + 0xf40) !=
               nullptr) &&
              (**reinterpret_cast<int32_t **>(reinterpret_cast<uint8_t *>(client) + 0xf40) ==
               *reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xf38))) {
            zeroU = 0;
            FUN_007b6a20(0);
            FUN_007b7000(zeroU);
          }
        }

        if (*reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0xc80) != 0) {
          FUN_00933480();
        }

        FUN_0079a1c0(1);
        FUN_00942e20();
        FUN_0079a120(1);

        if (*reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(client) + 0x4f4) != 0) {
          FUN_00806b90(0, 5);
        }

        if ((*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xb7) != '\0') &&
            (*reinterpret_cast<char *>(reinterpret_cast<uint8_t *>(client) + 0xa1) == '\0')) {
          FUN_004d18a0(*reinterpret_cast<float *>(DAT_00d09874 + 0x30) /
                       *reinterpret_cast<float *>(reinterpret_cast<uint8_t *>(client) + 0x9b0));
        }

        FUN_00944770();
        FUN_00946c00(client); // Client_DispatchUiEventQueue
        FUN_0079a120(0);

        // Optional frametime log arm
        if ((g_flZero < *reinterpret_cast<float *>(reinterpret_cast<uint8_t *>(client) + 0xac)) &&
            (*reinterpret_cast<float *>(reinterpret_cast<uint8_t *>(client) + 0xac) *
                 g_flMsToSeconds_Inferred <
             *reinterpret_cast<float *>(DAT_00d09874 + 0x30)) &&
            ((DAT_00d1f07c != 0) ||
             (DAT_00d1f07c = reinterpret_cast<int32_t>(
                  std::fopen("..\\logs\\frametime.txt", "wt")),
              reinterpret_cast<FILE *>(DAT_00d1f07c) != nullptr))) {
          stackScratch = 100000;
          FUN_0076ca60(logBuf, &stackScratch, 0);
          std::fputs(logBuf, reinterpret_cast<FILE *>(DAT_00d1f07c));
          std::fflush(reinterpret_cast<FILE *>(DAT_00d1f07c));
        }

        Sleep(0);
        FUN_0079a1c0(0);
        FUN_0079a9f0();
        FUN_0092cd20();
      }
    }
  }

  ExceptionList = savedExc;
  return 1;
}

// Ghidra alias
extern "C" uint32_t __fastcall FUN_0094b520(void *param_1)
{
  return Client_AppFrameTick(param_1);
}
