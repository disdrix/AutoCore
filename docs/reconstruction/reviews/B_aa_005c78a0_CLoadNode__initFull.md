# Review B (skeptical / adversarial): `aa_005c78a0` CLoadNode__initFull

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c78a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c78a0_CLoadNode__initFull.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same wait key as physics +0x14c | Falsified — +0x160 |
| 2 | Always calls FUN_00516be0 | Falsified — gated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stage key +0x160 | High | Wrong asset wait |
| 0xE gate | Medium | Extra/missing full work |

---

## 3. Cross-check against raw

```
_initFull: wait +0x160; +0x63=0; maybe FUN_00516be0; optional vtbls; 0|3.
```

---

## 4. Surviving contract for AutoCore

```
Late full-init stage after physics/anim/preload.
```

---

## 5. Open questions

1. Order relative to _initPhysics/_initAnim in dispatcher.

**Verdict:** **accept-with-gaps**
