# Review B (skeptical / adversarial): `aa_007a6de0` StringPool_ApplyModeAndRingStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6de0` |
| **VA** | `0x007a6de0`–`0x007a70d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_007a6de0_StringPool_ApplyModeAndRingStore_Inferred.md` |
| **System** | client UI / string temp-pool |
| **Verdict** | **accept-with-gaps** on OWN CF + ABI + mode-4 structure; **needs-more-evidence** on modes 1–3 English and product class name |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Free function / no `this` | **Falsified** | ECX saved as pool; layout writes `+0xc0` / `+4+idx*4`; `ret 8` stack cleanup only for two args |
| 2 | Pure strcpy / identity | **Falsified** | Mode switch; mode 4 mutates orthography; 1–3 call transform helpers |
| 3 | Always returns a new heap string the caller must free | **Falsified** | Returns ring slot or original `src`; no free on success path for caller |
| 4 | Empty and `"0"` treated the same | **Falsified** | Empty short-circuits before strcmp; `"0"` is **strcmp** equal to `DAT_00a32460` only |
| 5 | Sentinel is empty C-string / null object | **Falsified** | Sentinel is literal **`"0"`** (`0x30 0x00`) |
| 6 | Mode `-1` means “no transform” | **Falsified** | `-1` loads **default mode** at `pool+0x2c` (often production mode 0/1/…) |
| 7 | Mode 4 is “leet” / ROT13 / uppercasing | **Falsified** | Vowel table `a e i o u y` + suffixes **`ay`** / **`yay`** = **pig-latin** |
| 8 | Modes 1–3 sealed as “localization” | **Overstated** | Only call order sealed; helper bodies out of OWN scope |
| 9 | Plate `Named_CalleeOf_Client_RecvDestroyObject_*` is role | **Falsified** | Parent-seed scaffold; hundreds of UI/auth/mission callers — generic string pool |
| 10 | Safe to keep returned pointer indefinitely | **Falsified** | Ring size **10**; later successful calls recycle slots |
| 11 | Mode ≥5 impossible / trapped | **Falsified as trap** | No default handler; still advances ring and returns current slot (stale OK risk) |
| 12 | Runtime / bit-exact verified | **Falsified** | Open / deferred |
| 13 | Canonical name is product-confirmed | **Overstated** | `_Inferred` only; no RTTI/string on OWN body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + `src`/`mode` + `ret 8` | **High** | Wrong stack cleanup / missing ECX → crash |
| Early-outs null / empty / `"0"` | **High** | Wrong UI for zero-ish placeholders |
| Ring 10 + return previous index slot | **High** | Use-after-recycle bugs in ports |
| Mode `-1` → `+0x2c` | **High** | Ignoring default mode breaks locale/debug modes |
| Mode 0 strcpy path (after helper) | **High CF** | Helper side effects unknown |
| Mode 1–3 product meaning | **Low–Medium** | Mislabel as i18n without helper duals |
| Mode 4 pig-latin structure | **High** | Easter-egg language mode; wrong suffix breaks only mode 4 |
| Capacity grow formula `2*strlen` | **High** | Truncation / heap thrash if under-allocated |
| Callee ensure/lookup English | **Out of scope** | Do not invent locale table claims |
| Global vs instance pool | **Open** | Multi-thread / multi-UI races if assumed singleton |

---

## 3. Surviving contract

```
// ECX = pool; stack: src, mode; ret 8
char *StringPool_ApplyModeAndRingStore(pool, src, mode):
  if src == null OR src[0] == 0: return src
  if strcmp(src, "0") == 0: return src          // DAT_00a32460

  m = (mode == -1) ? pool->defaultMode@+0x2c : mode

  switch m:
    case 0:
      FUN_007a62c0(pool…)                      // residual
      strcpy(pool->slot[pool->idx], src)
    case 1,2,3:
      FUN_007a6490; FUN_007a6410                // residual
      if mode == -1:  // original arg, not m
        FUN_007a62c0; strcpy(slot, src)
      else:
        FUN_007a6310(m, pool); FUN_007a6610()   // residual
    case 4:
      ensure_cap(slot, 2*strlen(src))
      zero(slot, cap)
      pig_latin_words(src → slot)               // aeiouy / ay / yay
    default:
      // no write — still fall into ring advance

  old = pool->idx@+0xc0
  pool->idx = (old + 1 == 10) ? 0 : old + 1
  return pool->slot[old]                        // +4 + old*4
```

**Port rules that survive adversarial review:**

1. Always pass a live pool in ECX; never treat as free `char*(const char*, int)`.
2. Treat return as **borrowed temp** — copy if needed beyond ~10 subsequent stores.
3. Implement `"0"` bypass separately from empty-string bypass.
4. Honor `mode == -1` default field; do not hardcode mode 0 at all call sites.
5. Mode 4 must keep pig-latin constants if parity with retail debug/easter-egg language is required.
6. Leave modes 1–3 as opaque hooks until helper duals land.

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs `raw/aa_007a6de0_*.md` | **Match** body CF |
| Clean scaffold vs raw | **Match** (scaffold; not modernization) |
| Annotated | Scaffold notes only; dual seals ABI/constants |
| Epilog `ret 8` | **Match** `read_memory` |
| DAT vowel / suffix tables | **Match** `read_memory` |

---

## 5. Open questions (OWN residual only)

1. Product class name / PDB for the pool object (RTTI not on OWN body).
2. English labels for modes 0–3 and field `+0x2c` (settings UI? language pack? “none”?).
3. Why strcmp **`"0"`** is privileged (placeholder token vs numeric display).
4. Whether any caller depends on mode≥5 returning a **stale** slot vs always using 0–4.
5. Identity of ECX at hot call sites (one global `DAT_*` pool vs per-dialog).
6. Helper duals for `FUN_007a62c0` family.
7. Runtime / differential / bit-exact.

**Verdict:** **accept-with-gaps** — OWN control flow, ABI, ring lifetime, `"0"` sentinel, and mode-4 pig-latin structure are **High**; modes 1–3 and product naming remain **residual**. Safe behavioral map for AutoCore UI string temps once ring/ephemeral rules and mode `-1` default are honored.
