# Review B (skeptical / adversarial): `aa_004149d0` CVOGReaction_FailMissionNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_004149d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen — pure push seal) |
| **Counterpart** | `reviews/A_aa_004149d0_CVOGReaction_FailMissionNotify.md` |
| **Product alias (sealed)** | **`Vector_PushDword`** |
| **Dual status** | **Present and strengthened** (supersedes 2026-07-23) |
| **Verdict** | **accept** on pure push CF; **reject** all mission-fail / UX claims about this unit |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Fails the active mission here | **Falsified** — store dword + advance end only |
| 2 | Shows fail dialog / toast | **Falsified** — no UI callees |
| 3 | Sends packets / mutates dirty bits | **Falsified** — no `0x634` / net in body (callers own dirty) |
| 4 | Always grows via `FUN_0040dbf0` | **Falsified** — fast path when capacity remains |
| 5 | Element is always mission id | **Falsified** — freelist ptrs, medals, stack journal temps |
| 6 | `this` is always `char+0x560` | **Falsified** — journal `ESP+0x24/0x34`, freelist vectors |
| 7 | Name proves reaction-system exclusive API | **Falsified** — **40** callers / **51** sites across domains |
| 8 | Clean invents mission logic | **Falsified** — clean ≡ raw ≡ image |
| 9 | Thread-safe | **Unfounded** — no locks |
| 10 | Ready for product-English rename-only residual | **Partial** — CF sealed; registry rename optional |

---

## 2. Decisive dataflow (image-backed)

```
// ECX = vec object; stack arg0 = uint32_t* pValue
// triad: begin@+4, end@+8, cap@+0xc   (element size 4)

size = (begin == 0) ? 0 : (end - begin) >> 2
cap  = (capPtr - begin) >> 2          // only if begin != 0

if (begin != 0 && size < cap):
  *end = *pValue
  end += 4
  return                              // RET 4
else:
  FUN_0040dbf0(this, &argSlot, end, pValue)   // → FUN_004073a0 insert/grow
  return                              // RET 4
```

Live decompile `0x004149d0` ≡ 2026-07-23 raw. Image `read_memory` seals `SAR …,2`, fast `MOV [EAX],EDX` / `ADD EAX,4` / `MOV [ECX+8],EAX`, and `E8` to `0x0040dbf0`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vector push CF | **High** | Mis-documented container API |
| Capacity math (`>>2`) | **High** | Overrun / wrong element width |
| Grow callee chain | **High** | Missed OOM / relocate behavior |
| No fail UX in body | **High** | AutoCore invents phantom notify |
| Multi-caller generic | **High** | Mission-only over-specialization |
| Element product type at each site | **Site-dependent** | Wrong drain interpretation |
| `FUN_004073a0` English name | **Probable** | Naming only |
| Runtime multi-thread races | **Open** | Unobserved |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Hidden mission fail side channel | Extra CALL / store? | **No** — only `FUN_0040dbf0` on grow |
| Dirty bit written here | `0x634`? | **No** — FailMission caller ORs `0x10` *after* return |
| Element stride not 4 | byte/word vector? | **No** — all length math `SAR 2`; stores dword |
| `this+0` is begin | triad starts at 0? | **No** — begin at `+4` (wrapper/header dword before triad) |
| Journal “FailMissionNotify” fails missions | name implies fail? | **No** — dual `aa_008ae130` sealed Active/New push only |
| Single-purpose end-quest helper | few callers? | **No** — 51 call sites |

### 4.1 Counterexamples (name poison)

| Site | Why not “fail notify” |
|------|------------------------|
| `Client_UpdateMissionJournal` | Pushes ids into **UI temp** Active/New vectors |
| `FUN_00414cd0` / freelist family | Pushes **slab pointers** after `_aligned_malloc` |
| `FUN_00530550` | Medal/id list + caller dirty `\|0x20` (not fail `0x10`) |
| `CVOGReaction_FailMission` | **One** legitimate end-quest enqueue user — still just push |

---

## 5. Surviving contract for AutoCore

```
Vector_PushDword(vec, pDword):
  append one uint32 to growable vector at vec+4/+8/+0xc
  grow via FUN_0040dbf0 → FUN_004073a0 when full or unallocated
  void; __thiscall; RET 4

NOT:
  mission fail state machine
  UI toast / journal rebuild
  hash erase / packet I/O
  dirty-bit writer

Callers own:
  element meaning (mission id | freelist ptr | medal id | …)
  any dirty bits, drain (e.g. FUN_005307e0), UI
```

**Historical name:** keep `CVOGReaction_FailMissionNotify` as registry alias for continuity; treat **`Vector_PushDword`** as the sealed product role in new docs / ports.

---

## 6. Residual uncertainty

1. Optional rename commit in Ghidra + `NAMING_REGISTRY` primary column.
2. Own duals for `aa_0040dbf0` / `aa_004073a0` (growth English).
3. Full 51-site element taxonomy (classes sealed; tail open).
4. Runtime / bit-exact verification.

**Verdict: accept** on pure `Vector_PushDword`. Mission-fail semantics belong exclusively to callers (e.g. `CVOGReaction_FailMission`), never this body.
