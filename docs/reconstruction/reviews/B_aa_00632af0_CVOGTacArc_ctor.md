# Review B (skeptical / adversarial): `aa_00632af0` CVOGTacArc_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632af0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00632af0_CVOGTacArc_ctor.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on embed helpers |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server-side hit cone | **Falsified — client visual ctor only** |
| 2 | No vtbl / no color seed | **Falsified — vtbl + RGBA pack** |
| 3 | Finished FUN_0096* names | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vtbl + color default pack | High | Wrong UI colors |
| Sub-object init order | High | Dtor mismatch |
| Segment count 0x32 | Tentative | Mesh density wrong |
| FUN_0096ef70 role | Tentative | Leak / bad embed |

---

## 3. Cross-check against raw

```
SEH; *this=TacArcVtbl; fill color FF; FUN_0096ef70 x2; FUN_0096f530;
seed overheat frac + zeros + color defaults; return this.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
TacArc_ctor:
  client weapon-arc visual; vtbl → vdtor
  color bytes +0x30.. palette; mesh ptrs zero until Initialize
  do not use as combat LOS or server cone
  pair Initialize / InitializeMesh / UpdateMesh / SetStateColor
```

---

## 5. Open questions

1. Name FUN_0096ef70 / FUN_0096f530.
2. Publish TacArc layout offsets.
3. Confirm segment 0x32 vs mesh build.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on embed helpers
