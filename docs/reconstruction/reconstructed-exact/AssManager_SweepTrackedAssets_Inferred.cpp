// =============================================================================
// AssManager_SweepTrackedAssets_Inferred
// -----------------------------------------------------------------------------
// Purpose:  assManager worker: walk the tracked-asset list at this+0x08 under
//           mode 0/1/2. Mode 1 collects keys+asset* into stack vectors (and may
//           push keys into optional secondary host at this+0x6c via stride-2
//           GuardedVector push). Mode 2 age-purges idle assets older than
//           ageThreshold. Other modes hard-unload idle assets and rescan until
//           a pass destroys none. Logs assManager.cpp:0x1BB on timed destroy.
//
// Address:  0x0075de80  (autoassault.exe, image base 0x400000)
// Body:     0x0075de80–0x0075e2ce exclusive (1358 B / 0x54E)
// Stable:   aa_0075de80
// System:   assets / assManager
// Ghidra:   FUN_0075de80
//
// ABI:      __thiscall; ECX=assManager*; stack mode (int) + ageThreshold (float);
//           RET 8. Prologue 8B F1; epilogue C2 08 00.
// String:   "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp" L 0x1BB
//
// Exactness: CF mirrors raw + live decompile; nested helpers not re-implemented.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W32-O seal).
// =============================================================================

#include <stdint.h>

struct AssManager;
struct AssListNode;
struct AssAsset;

extern float FUN_0076c330(void); /* current time */
extern void EnterCriticalSection(void *cs);
extern void LeaveCriticalSection(void *cs);
extern void FUN_0043e8f0(void); /* key materialize / pack (EAX/stack per site) */
extern void FUN_0043e7f0(void); /* optional-CS GuardedVector push wrapper */
extern void FUN_0043e9e0(void); /* GuardedVector_PushBack_Stride2_U32U8 (EAX=cont) */
extern void FUN_0043bcc0(void); /* list unlink / erase node */
extern void FUN_0043bfb0(void); /* vector grow (keys) */
extern void FUN_00436ef0(void); /* trivial store advance helper */
extern void FUN_00456960(void); /* vector grow (ptrs) */
extern uint8_t FUN_00971a20(void); /* secondary key presence probe */
extern uint32_t FUN_0076cec0(void); /* log format helper */
extern void vog_LogMessage(const char *file, int line, int level, uint32_t msg);
extern void FUN_00745f80(void); /* pre-release hook on asset path */
extern void FUN_0044e8c0(void); /* post-collect remap / lookup */
extern void *FUN_0043c6f0(void); /* pack triple from keys */
extern void FUN_0043ba40(void); /* reinsert into host structure */
extern void operator_delete(void *p);

/*
 * Behavioral reconstruction (control-flow faithful; types structural).
 * Stack vector / SEH frame details omitted as mechanical MSVC noise.
 */
void AssManager_SweepTrackedAssets_Inferred(AssManager *self /*ECX*/,
                                            int mode /*stack*/,
                                            float ageThreshold /*stack*/)
{
  float now = FUN_0076c330();

  /* stack: key_vec begin/end/cap; asset_vec begin/end/cap — zeroed at entry */

  for (;;) {
    uint32_t destroyed = 0;
    AssListNode *node = *(AssListNode **)(*(uint32_t *)((uint8_t *)self + 0x08));
    AssListNode *sentinel = *(AssListNode **)((uint8_t *)self + 0x08);

    if (node != sentinel) {
      do {
        AssAsset *asset = *(AssAsset **)((uint8_t *)node + 0x0C); /* node[3] */
        uint32_t key = *(uint32_t *)((uint8_t *)node + 0x08);     /* node[2] */
        (void)key;

        if (mode == 2 && asset != 0) {
          float stamp = *(float *)((uint8_t *)asset + 0x1C); /* asset[7] */
          if (ageThreshold <= now - stamp) {
            uint8_t cs_on = *((uint8_t *)asset + 0x38); /* asset+0xE dwords */
            if (cs_on) {
              EnterCriticalSection((uint8_t *)asset + 0x20);
            }
            void *state = *(void **)((uint8_t *)asset + 0x10); /* asset[4] */
            if (cs_on) {
              LeaveCriticalSection((uint8_t *)asset + 0x20);
            }
            if (state == 0) {
              void *secondary = *(void **)((uint8_t *)self + 0x6c);
              if (secondary != 0) {
                /* FUN_0043e8f0 + FUN_0043e7f0 erase/push-secondary path */
                FUN_0043e8f0();
                FUN_0043e7f0();
              }
              vog_LogMessage(
                  "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",
                  0x1bb, 1, FUN_0076cec0());
              FUN_00745f80();
              (**(void (***)(AssAsset *))asset)(asset); /* vtbl[0] */
              *(AssAsset **)((uint8_t *)node + 0x0C) = 0;
              asset = 0;
            }
            /* fall into shared mode handling below */
          } else {
            node = *(AssListNode **)node; /* next */
            continue;
          }
        }

        /* shared path (mode 1 collect / unload) */
        uint8_t keep = 1;
        if (*(uint32_t *)((uint8_t *)node + 0x10) == 0) { /* node[4] */
          keep = 0;
          if (asset == 0 && *(void **)((uint8_t *)self + 0x6c) != 0) {
            keep = FUN_00971a20();
          }
        }

        if (mode == 1) {
          void *secondary = *(void **)((uint8_t *)self + 0x6c);
          if (secondary != 0) {
            FUN_0043e8f0();
            /* optional CS at secondary+0xC0 if flag secondary+0xD8 */
            FUN_0043e9e0(); /* EAX = secondary container (W31-J) */
          }
          node = *(AssListNode **)node;
          FUN_0043bcc0(); /* unlink prior */
          /* push key into key_vec; push asset* into asset_vec (grow helpers) */
          (void)FUN_0043bfb0;
          (void)FUN_00436ef0;
          (void)FUN_00456960;
        } else {
          if (keep) {
            node = *(AssListNode **)node;
            continue;
          }
          if (asset == 0) {
            void *secondary = *(void **)((uint8_t *)self + 0x6c);
            if (secondary != 0) {
              FUN_0043e8f0();
              FUN_0043e7f0();
            }
            node = *(AssListNode **)node;
            FUN_0043bcc0();
          } else {
            uint8_t cs_on = *((uint8_t *)asset + 0x38);
            if (cs_on) {
              EnterCriticalSection((uint8_t *)asset + 0x20);
            }
            void *state = *(void **)((uint8_t *)asset + 0x10);
            if (cs_on) {
              LeaveCriticalSection((uint8_t *)asset + 0x20);
            }
            if (state != 0) {
              node = *(AssListNode **)node;
              continue;
            }
            void *secondary = *(void **)((uint8_t *)self + 0x6c);
            if (secondary != 0) {
              FUN_0043e8f0();
              FUN_0043e7f0();
            }
            FUN_00745f80();
            (**(void (***)(AssAsset *))asset)(asset);
            node = *(AssListNode **)node;
            FUN_0043bcc0();
            destroyed++;
          }
        }
      } while (node != sentinel);
    }

    if (mode == 2 || (int)destroyed < 1) {
      /* post-pass: for each collected (key,asset*) pair → FUN_0044e8c0;
         conditional FUN_0043c6f0 + FUN_0043ba40 reinsert; free vectors */
      (void)FUN_0044e8c0;
      (void)FUN_0043c6f0;
      (void)FUN_0043ba40;
      (void)operator_delete;
      return;
    }
    /* mode != 2 and destroyed ≥ 1 → outer rescan */
  }
}
