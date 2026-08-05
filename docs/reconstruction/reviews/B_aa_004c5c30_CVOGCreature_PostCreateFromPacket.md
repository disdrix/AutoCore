# Review B (skeptical / adversarial): `aa_004c5c30` CVOGCreature_PostCreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c5c30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004c5c30_CVOGCreature_PostCreateFromPacket.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on dual-base field names |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always requires HBAI | **Falsified — logs only under conditions** |
| 2 | Always applies elite FX | **Falsified — flag gated** |
| 3 | Portable positive-this layout | **Falsified — negative dual-base** |
| 4 | Finished exact | **Overstated — large FUN_* surface** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual-base negative offsets | High | Corrupt post-create |
| Elite FX gate | High | Missing elite chrome |
| Owner bind type 0x12 | Tentative | Wrong pet/owner link |
| HBAI warn conditions | Tentative | Noise or miss |

---

## 3. Cross-check against raw

```
optional FUN_005c93f0(param_7);
graphics/interact gates via dual-base;
type 0x12 owner/map branches;
elite generic_elite FX if flag;
warn if no HBAI under TFID sentinel.
Clean ≡ raw CF; names partial.
```

---

## 4. Surviving contract for AutoCore

```
PostCreateFromPacket(creature dual-base, packet, mode, ...):
  run post-create graphics/interact hooks
  type-0x12 owner/map special cases
  attach generic_elite FX when elite flag set
  log if creature created without HBAI (specific TFID sentinel)
Port must preserve dual-base this adjustment; do not flatten to simple object*.
```

---

## 5. Open questions

1. Named field map for −0x4f8/−0x500/−0x1f5/−0x304.
2. param_3/6/7 semantic plate.
3. Cross-check CreateCreature height path.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on dual-base field names
