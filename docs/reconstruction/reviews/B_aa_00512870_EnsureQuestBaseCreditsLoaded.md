# Review B (skeptical / adversarial): `aa_00512870` EnsureQuestBaseCreditsLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512870` |
| **VA** | `0x00512870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00512870_EnsureQuestBaseCreditsLoaded.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory`, xrefs/globals only (no Launcher) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Body early-returns if already loaded | Plate comment asserts it; asm is linear enter→load→leave | **Falsified** — no flag test in `0x00512870..ad` |
| 2 | Body sets `g_nQuestBaseCreditsLoaded_Inferred` | Plate “sets flag”; no store to `0x00b0426c` | **Falsified** for this unit |
| 3 | Single-arg `Load(&map)` matches binary | Decompiler/clean v1 show one arg | **Falsified as complete ABI** — ECX loads `*[0x00b0469c]` and stack pushes map |
| 4 | Function is the credit calculator | Name proximity to mission credits | **Falsified** — pure load wrapper; math is `0x0059df20` |
| 5 | Fail stops process | `"VOG_DEBUG_STOP"` looks fatal | **Unproven** — only proves `FUN_007a4480(0, str)` call; severity owned by logger |
| 6 | One-shot without re-entry cost | “Ensure” naming | **Weak** — re-entry always re-calls Load unless **caller** gates on `0x00b0426c` |
| 7 | Map global is only state | Map root only | **Incomplete** — end sentinel `0x00b04268` + loaded dword `0x00b0426c` form a 12-byte block |
| 8 | Map address confusable with Lookup sibling | Contiguous BSS block | **Sealed** — this body pushes `0x00b04264` only; Lookup uses `0x00b04258` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wrapper control flow | **High** | Broken mission credit bring-up |
| Map address `0x00b04264` | **High** | Wrong table keyed by TargetLevel |
| DB ctx `0x00b0469c` | **High** | Load path uses wrong this |
| Loaded-flag writer | **Low** (outside unit) | Infinite re-load or never-ready depending on caller |
| Enter/leave = critical section | **Medium** | They are connection refcount helpers, not CS; wrong sync model if ported as mutex |
| Plate retail samples (L1=3 …) | **Out of unit** | Owned by Load plate; do not seal from Ensure alone |
| Sibling byte-isomorphism | **High** | Safe template if deltas (map/load) are preserved |

---

## 3. Cross-check against raw / clean

```
EnsureQuestBaseCreditsLoaded:
  ECX = *DAT_00b0469c
  FUN_007e1d80(ECX)
  ECX = *DAT_00b0469c; push &g_map@00b04264
  status = LoadQuestBaseCreditsFromWad(...)   ; 0x007cc810
  ECX = *DAT_00b0469c; FUN_007b7df0(ECX)
  if status < 0: FUN_007a4480(0, "VOG_DEBUG_STOP")
  return

Raw v1 plate over-trusts early-out/flag-set language; decompiler hides ECX.
Clean post-dual documents ECX plumbing. Sibling 0x00512830 is same skeleton
with map 0x00b04258 (CreditsLookup).
```

---

## 4. Surviving contract for AutoCore

```
Before lower_bound on tQuestBaseCredits (TargetLevel → intBaseCredits @ row+0x10):
  ensure table is loaded via same WAD path LoadQuestBaseCreditsFromWad uses
  (xpath //tQuestBaseCredits/row — sealed on loader unit plate).

Client lazy path: Mission_ComputeObjectiveCredits checks g_nQuestBaseCreditsLoaded
@ 0x00b0426c then calls this ensure. Boot path FUN_0094a6a0 also calls this ensure
during table init.

This function does NOT implement credit math, does NOT award currency, and does NOT
itself write the loaded flag in the sealed body.
```

---

## 5. Open questions

1. Exact instruction that stores non-zero to `0x00b0426c` (loader residual).
2. Load error code domain (`<0` HRESULT vs custom).
3. Whether `FUN_007a4480` level `0` is non-fatal debug-only.
4. Server-side table source parity for AutoCore mission credit grants.

**Verdict:** **accept-with-gaps**
