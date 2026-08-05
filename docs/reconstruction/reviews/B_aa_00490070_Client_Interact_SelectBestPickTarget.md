# Review B (skeptical / adversarial): `aa_00490070` SelectBestPickTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_00490070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00490070_Client_Interact_SelectBestPickTarget.md` |
| **Residual scratch** | `reviews/a_00490070.md` |
| **System** | `interaction-activation` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on score CF + constants; **reject** “nearest-only” / “always returns under-cursor” / UseObject-in-body |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns nearest object only | **Falsified** — priority dominates; distance only on tie |
| 2 | Single enumerator pass | **Falsified** — `local_5c=2`, flag toggles 0↔1 |
| 3 | Sends UseObject / interact packet | **Falsified** — no send callees; return pointer only |
| 4 | Always picks under exact pixel | **Overstated** — walk of enumerator + soft gates; parent may ray/gather if NULL |
| 5 | Types 0x1E/0x36/0x38 are high priority | **Falsified** — explicit skip to next |
| 6 | Type 10 always returns the leaf object | **Falsified** — if `obj[0x2B]` set, **retargets** to parent at pri 0x5A |
| 7 | Mission check uses only ForInteract | **Falsified** — ForInteract then ForPick (`00524520` then `005245d0`) |
| 8 | `param_3` is required filter | **Falsified** — unused in body |
| 9 | `DAT_00aaa630` is 0 or 1.0 | **Falsified** — `7F7FFFFF` FLT_MAX |
| 10 | Scaffold dual quality was already sealed | **Falsified** — 2026-07-23 scaffold only; this dual supersedes |
| 11 | Ready for bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow (SEALED)

```
if !client.viewA(+0xC0) || !client.viewB(+0xBC): return NULL
unproject(screen → ray locals)
best = NULL; bestPri = 0; bestDist = FLT_MAX
for pass in {0,1}:
  for obj in Enumerate(flag=pass):
    if !eligible(bit6, blob, distProbe): continue
    pri = 0
    apply flag bits → maybe 0x50 / 0x46
    switch cloneType:
      1,3: mission/owner heuristics → 0x3C / 0x14
      10,0xC,0x10,0x1C: parent retarget → 0x5A else 0x46
      0xE: maybe skip self; → 0x5A
      0x12: maybe skip self; creature cast → 0x3C / 0x32 / 0x64
      0x14 / default: maybe skip self; → 0x28
      0x16: → 0x64
      0x1E,0x36,0x38: continue
    if pri > bestPri or (pri == bestPri and dist < bestDist):
      best = obj; update pri/dist
return best
```

Live decompile ≡ raw 2026-07-23 body. Entry bytes seal Client this + dual view gate. `read_memory` seals FLT_MAX.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Priority-over-distance | **High** | Wrong multi-object click |
| Two-pass enum | **High** | Miss half of candidates |
| Parent retarget type 10 family | **High** | Click container leaf vs host |
| Self-owned skip when param_4==0 | **High** | Click self/vehicle false interact |
| FLT_MAX init | **Confirmed** | Broken min-dist |
| Enumerator host object | **Tentative** | Wrong list port |
| Runtime golden | **Open** | Residual |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Nearest-only selection | Compatible? | **No** — `bVar2 < local_75` promotes pri first |
| One pass only | Compatible? | **No** — `local_5c` countdown from 2 |
| UseObject inside | Hidden? | **No** — no 00916740/00930d70 calls |
| Type 0x16 pri 0x50 | Compatible? | **No** — sets 100 (`0x64`) |
| Mission only 00524520 | Compatible? | **No** — second call 005245d0 |
| DAT is gather radius | Compatible? | **No** — FLT_MAX sentinel for min |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `aa_009247b0` InteractClickPickTarget | **Caller** — uses this as primary; soft ray/gather if NULL |
| `aa_0075c340` Unproject | Screen → world ray buffers |
| `aa_00524520` / `aa_005245d0` | Mission boost on types 1/3 |
| `aa_0040b1b0` | Type 0x12 secondary gate |
| `aa_004bae00` | Enumerator step (host residual) |

---

## 6. Verdict

**accept-with-gaps.** Score ladder, two-pass walk, parent retarget, and FLT_MAX selection are **sealed**. Enumerator host ECX, unproject view choice, and runtime click goldens remain open. Parent gap “product name for FUN_00490070” is **closed** to a probable canonical (`Client_Interact_SelectBestPickTarget`).
