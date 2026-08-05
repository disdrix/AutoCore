# Review A (reconstruction fidelity): `aa_00613910` CVOGObjectiveRequirement_Kill_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613910` |
| **VA** | `0x00613910` |
| **Canonical name** | `CVOGObjectiveRequirement_Kill_Eval` |
| **Review date** | `2026-07-29` (dual residual strengthen; prior `2026-07-23`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` |
| **Verdict** | **accept** (formula + provenance sealed; runtime/diff open) |
| **Scratch** | `tmp/a_00613910.md` |

---

## 1. Purpose

Kill requirement **eval** (vtable **+0x8** on Kill requirement vtable `0x009e19e4`). Completes when progress slot float **≥** required kill count (int@req+0x18 converted to float).

---

## 2. Inspected artifacts

| Artifact | Path / note |
|---|---|
| Raw | `raw/aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` (+ 2026-07-29 re-verify append) |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Kill_Eval.cpp` |
| Function record | `functions/aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` |
| Live Ghidra | `decompile_function` + `disassemble_function` @ `0x00613910` |
| Vtable DATA | `0x009e19ec` → Eval; base `0x009e19e4` |
| Sibling Precheck | `Kill_Precheck @ 0x00613b50` (not owned this pass) |
| Progress hub | `Client_RecvObjectiveState @ 0x00809460` (0x2071; cross-read only) |
| Isomorph | `UseItem_Eval @ 0x0060cfe0` (threshold +0x50) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `(float)req+0x18 <= state[+4+slot*4]` complete | **High / Confirmed** | decomp + asm COMISS/JC |
| Slot index byte@req+0x08 | **High / Confirmed** | `MOVZX [ECX+8]` |
| Required kills int@req+0x18 (CVTSI2SS) | **High / Confirmed** | not float load |
| param_2 unused by body | **High / Confirmed** | only `[ESP+8]` (state) loaded |
| Return 1 complete / 0 progress | **High / Confirmed** | AL=1 / XOR AL,AL; RET 8 |
| No mutate / no filter / no callees | **High / Confirmed** | 10 insns; call_count=0 |
| Clean ≡ raw CF | **High** | trivial body |
| Vtable +0x8 Eval; +0x4 Precheck | **High** | memory at `0x009e19e4` |
| Filters owned by Precheck only | **High** | body empty of match logic |
| Progress writers share `state+4+slot*4` | **High** | RecvObjectiveState absolute; Precheck += |
| Absolute vs delta **not** Eval concern | **High** | pure compare |

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| Load slot + required | **Yes** |
| Load progress float | **Yes** |
| Complete iff progress ≥ required | **Yes** (COMISS + not-JC) |
| Return polarity | **Yes** |

---

## 5. Gaps closed this residual pass

1. ~~Slot float absolute 0x2071 only vs Precheck increments~~ → **both writers**; Eval pure-reads either.
2. ~~Filter ownership~~ → **Precheck only** (body sealed empty).
3. ~~RecvObjectiveState same layout~~ → `state[1..4]` ≡ slots 0–3 at `+4+i*4`.
4. ~~Precheck already bumped~~ → next Eval pure-reads; Precheck also early-outs via vcall Eval when already complete.

---

## 6. Remaining gaps (policy / out-of-unit)

1. Runtime live capture; image bit-exact / binary diff.
2. Precheck credit addend (`+0.0` decomp suspicion) is **Precheck-owned**.

**Verdict:** **accept** — dual residual sealed for Eval body contract.
