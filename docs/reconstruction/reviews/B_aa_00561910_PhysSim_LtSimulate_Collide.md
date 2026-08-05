# Review B (skeptical / adversarial): `aa_00561910` PhysSim_LtSimulate_Collide

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-L) |
| **Counterpart** | `reviews/A_aa_00561910_PhysSim_LtSimulate_Collide.md` |
| **Scratch** | `tmp/a_00561910.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This function runs applyAction / vehicle step | **Falsified** — no action list walk; applyAction is under `FUN_00628f70` from integrate half `FUN_00561b60` |
| 2 | `FUN_00629d90` is "island integrate" | **Falsified** — profile `LtBroadPhase`; collide-only |
| 3 | Decompiler call `FUN_00629d90(ctx, stepBlock)` is complete | **Overstated** — missing ECX=sub-island; bytes seal true thiscall |
| 4 | Decompiler void/unknown ABI | **Overstated** — `RET 4`, ECX=this, one stack float* |
| 5 | Many callers | **Falsified** — exactly 2 xrefs (StepTo, FUN_00562bf0) |
| 6 | Name `PhysSim_LtSimulate_Collide` is retail | **Overstated** — inferred from timer string + role; Ghidra still `FUN_00561910` |
| 7 | Stores only dt at +0x150 | **Partial** — also inv_dt, agent copy, scaled block, flags |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Install stepInfo + collide loop CF | **High** | Wrong substep timing / missed contacts |
| Collide-only role (not applyAction) | **High** | Broken vehicle drive chain attribution |
| Sub-island this for broadphase | **High** | Wrong collision island |
| ABI thiscall + RET 4 | **High** | Stack smash |
| Two callers only | **High** | Missed entry path |
| Product type English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
island = ECX; stepInfo = stack0
store dt/inv_dt + agent + scales
flag busy; optional flush
for each sub: broadphase(sub); optional post-collide CB
clear busy; deferred deletes; StPostCollideCB
RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean fixes only the documented `FUN_00629d90` this residual.

---

## 4. Surviving contract for AutoCore

```
// Per substep collide half — pair with PhysSim_LtSimulate_Integrate (FUN_00561b60)
PhysSim_LtSimulate_Collide(island, &stepInfo);  // stepInfo = {substep_dt, 1/substep_dt}
// After return: contacts generated; applyAction NOT yet run
// island+0x150 must remain substep_dt for later applyAction(param = island+0x150)
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/role sealed; decompiler residual documented and fixed in clean; residual is type English only → **accept**.
