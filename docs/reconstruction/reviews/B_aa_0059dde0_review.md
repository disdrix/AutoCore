# Review B (skeptical / adversarial): `aa_0059dde0` Mission_ComputeObjectiveXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dde0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen) |
| **Counterpart** | `reviews/A_aa_0059dde0_review.md` |
| **Scratch** | `tmp/a_0059dde0.md` |
| **Verdict** | **accept-with-gaps** — formula + map/call residual sealed; table payloads / runtime open |

---

## 1. Claims under attack

| # | Claim | Attack result (2026-07-29 strengthen) |
|---|---|---|
| 1 | Used for every objective advance | **Falsified** — no advance xref; grant XP only on CompleteObjective final branch |
| 2 | Returns nearest-int XP | **Falsified for this function** — trunc cast only; ±0.5001f is CompleteObjective grant path |
| 3 | Sole caller is CompleteObjective | **Falsified as exclusivity** — also toast×2 + `FUN_0051f510` (presentation). **Grant** write still sole CompleteObjective |
| 4 | Missing map row yields small XP / lower_bound nearest | **Falsified** — helpers gate `key < node.key → end`; body miss → **0** |
| 5 | L-1 path needs double-deref / mis-decomp | **Falsified** — image: `*[out_it]` is node*; payload `+0x10` same as L |
| 6 | `unaff_EDI` / 4th map arg is live | **Falsified** — helpers `ret 8`; body never supplies 4th stack arg |
| 7 | Bias is applied inside `0x0059dde0` | **Falsified** — no `0x00aaa6d0` load in body; confirmed at grant call site |
| 8 | TargetLevel==1 span is full threshold | **True per body** — no L-1 subtract when `L <= 1` |
| 9 | Product order is Scaler × frac × Balance | **Falsified order claim** — image is Balance × frac × Scaler (`+0x144`, node+0x10, `+0x140`) |
| 10 | Worked example XP=320 from body alone | **Unproven as image fact** — arithmetic holds **if** table values match XP.md; payloads not in this VA |
| 11 | Presentation path grants XP | **Falsified** — toast/`FUN_0051f510` only format chat/floater; no AddExperience |

---

## 2. Surviving formula (port contract)

```
// Pure calculator — no character mutation, no round bias
if missionDef(obj+0x14c) == null: return 0

frac = exact_find(tQuestXPLookup, (short)obj+0x13c)   // node+0x10 float; miss→0
spanMult = fXPBalanceScaler(+0x144) * frac * fXPScaler(+0x140)

L = (short)missionDef+0x11c
cum = exact_find(tExperienceLevel, L)                 // node+0x10 int; miss→0
span = cum
if L > 1:
  prev = exact_find(tExperienceLevel, L-1)
  if prev hit: span = cum - prev

return (int)((float)span * spanMult)                  // trunc toward zero HERE

// GRANT path only (CompleteObjective final):
//   f = (float)ret; f += (f>=0 ? +0.5001f : -0.5001f); AddExperience((int)f, PacketOrNonKill)
// PRESENTATION (toast / FUN_0051f510): call calculator for display only
```

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Boundary / pure calc | High | Wrong ownership of grant |
| CF + trunc | High | Off-by-one XP |
| Map exact-key miss→0 | High | Silent wrong XP on bad index |
| Node +0x10 payload | High | Wrong frac/threshold read |
| Product order | High | Float non-associativity edge (rare) |
| Bias 0.5001f caller-only | High | Double-round or no-round on server port |
| Caller partition grant vs UI | High | Grant on advance or toast double-grant |
| Table row payloads (R2) | Open / data-plane | Wrong absolute XP numbers |
| Ensure* / global names | Probable labels | Doc-only |
| Runtime complete measurement | Open | Unvalidated vs live client |

---

## 4. Competing stories rejected

| Story | Why dead |
|---|---|
| Iterator needs `**node` / second deref | Body `mov edi,[eax]` then `[edi+0x10]` |
| lower_bound nearest-key grant | Exact gate after walk; miss → end → 0 |
| Bias inside calculator | No bias global in body; CompleteObjective ±bias |
| Final-only is body invariant | Presentation also calls; “final only” is **grant convention** |
| Advance grants mission XP | Advance branch: skill/attrib only; no this call |

---

## 5. Open questions (post-strengthen)

1. **R2** Table float/int payloads for economy worked examples (XP.md is supporting data, not image seal).
2. **R4** Negative scalers → negative XP before caller bias (body allows it).
3. AutoCore table load parity with retail wad keys / ready-flag write sites.
4. **R5** Runtime complete measurement (calc + bias vs observed grant).
5. Bit-exact harness.

**Verdict:** Safe to port formula with caller-side round bias on **grant** path only; do not call for grant on advance; toast may call for display. **accept-with-gaps.**
