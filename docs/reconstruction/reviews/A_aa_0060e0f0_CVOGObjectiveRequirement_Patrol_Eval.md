# Review A (reconstruction fidelity): `aa_0060e0f0` CVOGObjectiveRequirement_Patrol_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e0f0` |
| **VA** | `0x0060e0f0` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_Eval` |
| **Review date** | `2026-07-23` (residual refresh `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060e0f0_CVOGObjectiveRequirement_Patrol_Eval.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Patrol **eval** (vtable **+0x8**). Completes when slot float ≥ **(targetCount × Laps)** with ints at `req+0xd0` and `req+0x24`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060e0f0_CVOGObjectiveRequirement_Patrol_Eval.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_Eval.cpp` |
| GetTarget | `0x0060e370` — same product for done; modulo `+0xd0` only |
| GetFlags | `0x0060e260` — `<Laps>` from `+0x24` (image `mov eax,[esi+0x24]`) |
| Residual scratch | `reviews/a_0060e0f0.md` |
| Live re-decompile | Ghidra 2026-07-29 ≡ frozen raw |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Product threshold `req+0xd0 * req+0x24` | **High** | raw + `imul` image |
| `+0xd0` = waypoint/target count | **High** | GetFlags GenericTarget loop |
| `+0x24` = **Laps** | **High** | GetFlags `<Laps>` push `[esi+0x24]` |
| Slot float at `state+4+slot*4` | **High** | shared layout; `movss` image |
| `<=` completes (equal passes) | **High** | `comiss` + `jb` only on below |
| Slot is **absolute pad count** | **High** | GetTarget int cast; server BuildPatrolPadCount |
| Clean ≡ raw | **High** | trivial CF |
| Zero product → complete if slot ≥ 0 | **High** | arithmetic edge |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Multiply threshold | **Yes** |
| Compare/return | **Yes** |

---

## 5. Gaps (remaining)

1. Runtime / bit-exact / full image diff (policy open).
2. Server normalizes `Laps≤0`→1 and `targets==0`→needed 1; client Eval uses raw product (port caution only).

**Verdict:** accept-with-gaps — dual residual field names + absolute-float convention **sealed**.
