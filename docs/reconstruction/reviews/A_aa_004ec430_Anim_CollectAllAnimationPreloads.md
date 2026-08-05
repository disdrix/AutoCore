# Review A (reconstruction fidelity): `aa_004ec430` Anim_CollectAllAnimationPreloads

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ec430` |
| **VA** | `0x004ec430` |
| **Canonical name** | `Anim_CollectAllAnimationPreloads` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004ec430_Anim_CollectAllAnimationPreloads.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Animation **preload path collect** (`CollectAllAnimationPreloads`). `__fastcall(clonebase*)`. Copies name from **+0x188**, branches on type **+0x38** (**0xc**, **0x12**, …) with path builders `FUN_007b6a20` / `FUN_007b6730` / `FUN_00989e00` and enqueue helpers `FUN_0043d670` / `FUN_004c3320`. Sibling role to `Phy_CollectAllPhysicsPreloads` for anim assets during client load.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ec430_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004ec430_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Anim_CollectAllAnimationPreloads.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ec430_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name source +0x188 | High | Body |
| Type gate +0x38 (0xc / 0x12 …) | High | Body |
| Path/open helpers shared with phy preload family | High | FUN_00989e00 |
| Full type matrix sealed | Medium | Long switch residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| copy name → type branch → path exists? → enqueue preload | Yes |

---

## 5. Gaps / open

1. Complete type→extension table.
2. When called from CLoadNode preload stage.

**Verdict:** **accept-with-gaps**
