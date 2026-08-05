# Review A (reconstruction fidelity): `aa_0064de50` hkDefaultSuspension_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064de50` |
| **VA** | `0x0064de50` |
| **Canonical name** | `hkDefaultSuspension_update` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064de50_hkDefaultSuspension_update.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Suspension force child update. Per wheel: if not in contact (**wheel+0x80** flag) force=0; else spring/damper using rest length table **+0x28**, current length **wheel+0xB0**, compression vel **+0xB4**, choose damper table **+0x5c** vs **+0x50** by sign of +0xB4, scale by inv mass from chassis. **Anti-sink chassis lift is NOT here** — that is applyAction step scanning min **+0xB0**. ~109-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064de50_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064de50_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultSuspension_update.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064de50_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Spring/damper force per wheel` | High | Body |
| `wheel+0xB0 current length` | High | 0.4-suspension |
| `Anti-sink not in this fn` | High | Verified applyAction |
| `Damper table split by +0xB4 sign` | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| per-wheel force out; skip if no contact | Yes |
| No invent position anti-sink write | Yes |

---

## 5. Gaps / open

1. Name force output array +0x34 consumers in postTick.

**Verdict:** accept-with-gaps
