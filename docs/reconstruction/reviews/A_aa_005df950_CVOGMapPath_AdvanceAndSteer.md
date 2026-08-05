# Review A (reconstruction fidelity): `aa_005df950` CVOGMapPath_AdvanceAndSteer

| Field | Value |
|---|---|
| **Stable ID** | `aa_005df950` |
| **VA** | `0x005df950` |
| **Canonical name** | `CVOGMapPath_AdvanceAndSteer` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005df950_CVOGMapPath_AdvanceAndSteer.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Advance AI along `CVOGMapPath` points (**stride 0x20**). Empty path → log + return 0. Index out of range → 0. Index **0xFFFFFFFF** → pick nearest point by squared distance. Else fetch point via vtbl **+0x2c0**. If outside accept radius `point[3]`, steer via vtbl **+0x2c4**; if inside radius, may `ResolveObjectTarget` on point COID slots **[4],[5]** and fire reaction / advance index. Supports reverse wrap (`path+0x68` / finished flag out). Outputs aim/steer floats to out params. Core of NPC path follow / ReturnToNormalLocation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005df950_CVOGMapPath_AdvanceAndSteer.md` |
| Annotated | `docs/reconstruction/raw/aa_005df950_CVOGMapPath_AdvanceAndSteer.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMapPath_AdvanceAndSteer.cpp` |
| Function record | `docs/reconstruction/functions/aa_005df950_CVOGMapPath_AdvanceAndSteer.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Empty path log + return 0` | **High** | Entry |
| `Point stride 0x20 (>>5 count)` | **High** | Count math |
| `Index OOB → 0` | **High** | Gate |
| `0xFFFFFFFF → nearest-point scan` | **High** | Init path |
| `Accept radius = point float [3]` | **High** | Dist vs r^2 |
| `Outside: vtbl+0x2c4 steer toward index` | **High** | Aim |
| `Inside: ResolveObjectTarget(point[4],point[5]) path` | **High** | Reaction COID |
| `Reverse / finish flags param_6 + path+0x68` | **High** | Wrap |
| `Used by HBAI ReturnToNormalLocation / drivers` | **High** | Callers |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Empty/OOB/nearest/radius/steer/advance | **Yes** |
| No invented physics drive | **Yes** |

---

## 5. Gaps / open

1. Full point layout beyond pose[0..2] radius[3] COID[4..5].
2. Exact steer out param semantics (heading vs world aim).
3. Curvature radius residual from NPC.md notes.
4. unaff_EBX / decomp noise in clean.

**Verdict:** **accept-with-gaps**
