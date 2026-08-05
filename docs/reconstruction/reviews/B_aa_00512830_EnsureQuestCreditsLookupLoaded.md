# Review B (skeptical / adversarial): `aa_00512830` EnsureQuestCreditsLookupLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512830` |
| **VA** | `0x00512830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory`, xrefs/globals only (no Launcher) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Body early-returns if already loaded | Plate comment asserts it; asm is linear enter→load→leave | **Falsified** — no flag test in `0x00512830..6d` |
| 2 | Body sets `g_nQuestCreditsLookupLoaded_Inferred` | Plate “sets flag”; no store to `0x00b04260` | **Falsified** for this unit |
| 3 | Single-arg `Load(&map)` matches binary | Decompiler/clean show one arg | **Falsified as complete ABI** — ECX loads `*[0x00b0469c]` and stack pushes map |
| 4 | Function is the credit calculator | Name proximity to mission credits | **Falsified** — pure load wrapper; math is `0x0059df20` |
| 5 | Fail stops process | `"VOG_DEBUG_STOP"` looks fatal | **Unproven** — only proves `FUN_007a4480(0, str)` call; severity owned by logger |
| 6 | One-shot without re-entry cost | “Ensure” naming | **Weak** — re-entry always re-calls Load unless **caller** gates on `0x00b04260` |
| 7 | Map global is only state | Map root only | **Incomplete** — end sentinel `0x00b0425c` + loaded dword `0x00b04260` form a 12-byte block |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wrapper control flow | **High** | Broken mission credit bring-up |
| Map address `0x00b04258` | **High** | Wrong table keyed by CreditsIndex |
| DB ctx `0x00b0469c` | **High** | Load path uses wrong this |
| Loaded-flag writer | **Low** (outside unit) | Infinite re-load or never-ready depending on caller |
| Enter/leave = critical section | **Medium** | They are connection refcount helpers, not CS; wrong sync model if ported as mutex |
| Plate retail curve (0→0 … 10→2.0) | **Out of unit** | Owned by Load plate; do not seal from Ensure alone |

---

## 3. Cross-check against raw / clean

```
EnsureQuestCreditsLookupLoaded:
  ECX = *DAT_00b0469c
  FUN_007e1d80(ECX)
  ECX = *DAT_00b0469c; push &g_map@00b04258
  status = LoadQuestCreditsLookupFromWad(...)
  ECX = *DAT_00b0469c; FUN_007b7df0(ECX)
  if status < 0: FUN_007a4480(0, "VOG_DEBUG_STOP")
  return

Clean/raw omit ECX plumbing and over-trust plate early-out/flag-set language.
Sibling 0x00512870 is same skeleton with map 0x00b04264 (BaseCredits).
```

---

## 4. Surviving contract for AutoCore

```
Before lower_bound on tQuestCreditsLookup (CreditsIndex → rlLevelCredits @ row+0x10):
  ensure table is loaded via same WAD path LoadQuestCreditsLookupFromWad uses
  (xpath //tQuestCreditsLookup/row — sealed on loader unit).

Client lazy path: Mission_ComputeObjectiveCredits checks g_nQuestCreditsLookupLoaded
then calls this ensure. Boot path FUN_0094a6a0 also calls this ensure during table init.

This function does NOT implement credit math, does NOT award currency, and does NOT
itself write the loaded flag in the sealed body.
```

---

## 5. Open questions

1. Exact instruction that stores non-zero to `0x00b04260` (loader residual).
2. Load error code domain (`<0` HRESULT vs custom).
3. Whether `FUN_007a4480` level `0` is non-fatal debug-only.
4. Server-side table source parity for AutoCore mission credit grants.

**Verdict:** **accept-with-gaps**
