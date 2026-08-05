# Review B (skeptical / adversarial): `aa_00531bd0` CVOGMission_EnsurePendingObjectiveState_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531bd0` |
| **VA** | `0x00531bd0` |
| **Canonical name** | `CVOGMission_EnsurePendingObjectiveState_Inferred` (Ghidra `FUN_00531bd0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00531bd0_CVOGMission_EnsurePendingObjectiveState_Inferred.md` |
| **System** | `missions-progression` |
| **Live tools** | Independent `force_decompile` + `read_memory` + caller decompile site + `A_aa_00531b00` / `A_aa_0053c760` cross-check |
| **Verdict** | **accept-with-gaps** — accept A's CF; reject “full AddActiveObjective twin” / “always insert” claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** `AddActiveObjective` / same body | **Falsified** — no `+0x548`, no evaluator loop, no dirty; different arity (3 vs 2 args) |
| 2 | Always inserts into pending hash | **Falsified** — insert only when lookup miss (`isNew`) |
| 3 | Writes only def pointer into node | **Falsified** — copies **4** dwords from `param_3` into `node+4..+0x10` |
| 4 | Runs on all objectives | **Falsified** — early-out if evaluator vector empty (same emptiness test as AddActiveObjective non-dirty path) |
| 5 | Dirty `char+0x634` | **Falsified** — no write to `+0x634` |
| 6 | Insert ECX is implicit / global | **Falsified** — asm reloads `[char+0x55c]` into ECX; decompiler drops it |
| 7 | Multi-caller API | **Falsified** — single static xref from ApplyCreateFromPacket |
| 8 | Scaffold alias `Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_*` proves semantics | **Partial** — caller identity **High**; English name still inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + `+0x55c` lookup key | **High** | Wrong mission state path |
| Node 0x14 + 4-slot write | **High** | Packet rehydrate wrong size |
| Insert-only-if-new | **High** | Double-insert / leak on port |
| Not AddActiveObjective | **High** | Port runs evaluator side effects twice |
| Product name | **None** | Registry pollution |
| OOM null-node write | **High (bug shape)** | Crash on OOM if taken |

---

## 3. Decompiler pitfalls

1. `FUN_0053c760(key, node, 0)` printed without hash `this` — binary loads ECX from `[edi+0x55c]`.
2. `CNDHash_LookupByKey(*(void**)(param_1+0x55c), key)` shape is correct for lookup; insert twin must restore ECX the same way.
3. `bVar1 = true` set even if `operator_new` returns null — then stores through null if OOM (do not “fix” in port without matching retail).

---

## 4. CF challenge of Review A

- Force ≡ non-force body: **agree**
- Sibling contrast table: **agree High**
- accept-with-gaps: **agree**
- Reject full-grant / always-insert: **agree**

**Verdict:** **accept-with-gaps**
