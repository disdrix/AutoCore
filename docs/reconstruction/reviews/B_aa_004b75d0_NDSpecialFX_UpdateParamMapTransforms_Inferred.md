# Review B (skeptical / adversarial): `aa_004b75d0` NDSpecialFX_UpdateParamMapTransforms_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b75d0` |
| **VA** | `0x004b75d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004b75d0_NDSpecialFX_UpdateParamMapTransforms_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Physics / rigid-body integrator | Heavy float math | **Falsified** — FX map walk; no PhysX; callers are weapon/interact FX |
| 2 | Always processes every entry | Gate always open | **Falsified** — state0 / null host / null TFID (for non-special modes) / null provider skips |
| 3 | Mode 1 and 4 identical | Shared aim-cache prelude | **Distinct tail** — 1 normalizes direction; 4 collapses to length |
| 4 | Requires target TFID always | Resolve always | **Falsified** — modes 0/1/4/5/6 may proceed with null target (zero delta / host-only paths) |
| 5 | Writes only entry storage | No host mutation | **Falsified** — modes update **`this+0x80` aim cache** and `entry+0x20` state |
| 6 | `004e8bf0` is inverse transform | Could be Rᵀ | **Falsified** — peer dual seals forward `pos+R·v` |
| 7 | Packet-dispatch leaf | Scaffold name | **Falsified** — geometry resolve worker; dispatch is caller-side |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Map walk + mode switch CF | **High** | Wrong FX aim |
| Skip when state==0 | **High** | Recompute before set |
| Host/target slot coupling | **High** | Mis-order SetHost/SetTarget/Update |
| Mode English labels | **Probable** | Wrong script authoring docs |
| Hardpoint API names | Open | Cosmetic |
| Server need | Low likelihood | Wasted work if ported headless |

---

## 3. Surviving contract

```
// Order for weapon fire (observed):
//   SetHost (004b73c0) → SetParam×N (004b7550) → SetTarget (004b68c0) → Update (004b75d0)
UpdateParamMapTransforms(fx):
  for entry in fx.map:
    if !ready(entry, fx): continue
    src = frame(entry.hardpoint, fx.host)
    delta = targetPos(fx.targetTfid) - src   // or 0
    switch entry.mode: ... update aim cache / entry.v ...
    entry.v = scale(postprocess(delta_or_dir))
```

---

## 4. Falsifications locked in

- **Reject** physics-step classification.
- **Reject** “state 0 means active and ready.”
- **Reject** treating as packet dispatcher.
- **Reject** assuming all modes need live target object.

---

## 5. Residual uncertainty

| # | Item | Blocks CF seal? |
|---|---|---|
| R1 | Product symbol | No |
| R2 | Mode 4 magnitude storage detail (x-only vs broadcast) | Mild — decompile assigns SQRT into `fStack_e0` then postprocess |
| R3 | `FUN_004e88e0` exact | Mild |
| R4 | Runtime float order | Mild |

**Verdict:** **accept-with-gaps**
