# Review B (skeptical / adversarial): `aa_004ec430` Anim_CollectAllAnimationPreloads

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ec430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004ec430_Anim_CollectAllAnimationPreloads.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Physics RB collect | Falsified — animation |
| 2 | Runtime anim tick | Falsified — preload collect |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type +0x38 map | High | Missing anim assets |
| Path build | Medium | Failed open |

---

## 3. Cross-check against raw

```
CollectAllAnimationPreloads(cb): name+0x188; type+0x38 branches; enqueue.
```

---

## 4. Surviving contract for AutoCore

```
Client anim preload list builder. Pair with Phy_CollectAllPhysicsPreloads.
```

---

## 5. Open questions

1. Diff one vehicle clonebase anim list vs retail.

**Verdict:** **accept-with-gaps**
