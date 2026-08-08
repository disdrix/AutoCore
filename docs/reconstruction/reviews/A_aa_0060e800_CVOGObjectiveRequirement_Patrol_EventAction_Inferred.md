# Review A (reconstruction fidelity): `aa_0060e800` CVOGObjectiveRequirement_Patrol_EventAction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e800` |
| **VA** | `0x0060e800` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_EventAction_Inferred` |
| **Review date** | `2026-08-05` (MEGA-031) |
| **Reviewer role** | Path A — reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0060e800_CVOGObjectiveRequirement_Patrol_EventAction_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Patrol requirement **event-driven Action** (`vtable+0x04` under `PTR_FUN_009e0404`):

| `eventType` | Arm | Effect | AL |
|:-----------:|-----|--------|:--:|
| `0x0C` | AutoFail flag | if `req+0x18` → `FailMission(**(req+4)+0x14c)` | 0 |
| `0x0B` | Pad proximity | match current pad COID; AutoComplete slot+=1 or AutoFail-by-distance | 0\|1 |
| other | — | fallthrough | 0 |

Does **not** compute progress fraction (`0x0060e120`) or Eval complete gate (`0x0060e0f0`). Does **not** drain after FailMission.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw (+ MEGA-031 re-verify append) | `raw/aa_0060e800_FUN_0060e800.md` |
| Annotated | `raw/aa_0060e800_FUN_0060e800.annotated.md` |
| Clean named | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_EventAction_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_0060e800.cpp` |
| Field dictionary peer | dualed GetFlags `0x0060e260` |
| Progress peer (do not merge) | dualed `Patrol_Action` `0x0060e120` |
| FailMission consumer table | dualed `0x0052da30` |
| Live tools | decompile + analyze_function_complete + disassemble_function + analyze_control_flow + callers/xrefs + read_memory |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x0060e800`–`0x0060e9d0`, 467 B | **High** | `analyze_control_flow` + last `RET 0x1C` |
| `__thiscall` + **RET 0x1C** (7 stack args) | **High** | image `C2 1C 00` ×3 exits |
| ECX = Patrol req*; vtable slot **+0x04** | **High** | DATA `009e0408`; ctor installs `009e0404` |
| event at `[EBP+0x10]` is int `0x0B`/`0x0C` | **High** | `CMP EAX,0xC` / `CMP EAX,0xB` |
| entity at `[EBP+0x20]` | **High** | `MOV ESI,[EBP+0x20]` |
| AutoComplete `+0x10` / dist `+0x14` | **High** | GetFlags strings + this body |
| AutoFail `+0x18` / dist `+0x1c` | **High** | GetFlags strings + this body |
| targets `+0x30` step 8; count `+0xd0`; Laps `+0x24` | **High** | shared with Eval/GetTarget |
| slot float `progress+4+slot*4` += 1.0 | **High** | `ADDSS` `g_flOne` |
| `DAT_00aaa688 = 5.0f` slop | **High** | `read_memory` `00 00 A0 40` |
| FailMission ×2, **no drain** | **High** | call sites + FailMission dual table |
| Static CALL callers | **High** | none — virtual-only |
| Clean CF ≡ raw/image | **High** | arms preserved; ABI corrected |
| Product event English 0x0B/0x0C | **Tentative** | numeric sealed only |
| Virtuals +0x144 / +0x1a0 / +0x198 English | **Tentative** | offsets sealed |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw / image

| Stage | Match |
|---|---|
| event 0x0C AutoFail → FailMission → AL=0 | **Yes** |
| event ≠ 0x0B early out | **Yes** |
| padCount / laps×count / modulo idx | **Yes** |
| COID pair match | **Yes** |
| entity +0x144 + pos load + complex +0x1a0 | **Yes** |
| 3D sqrt distance | **Yes** |
| AutoComplete dist < complete+5 → slot+=1, AL=1 | **Yes** |
| AutoFail dist > fail−5 → FailMission | **Yes** |
| AutoFail inside-band + complex+0x198 → FailMission | **Yes** |
| Default AL=0 / RET 0x1C | **Yes** |

---

## 5. Gaps (remaining)

1. Product English for event codes **0x0B** / **0x0C**.
2. Product names for entity `vtbl+0x144`, character-complex `+0x1a0` / `+0x198`.
3. Static 7-arg Action dispatcher residual (shared with Collect_Action).
4. Runtime / bit-exact / differential (policy open this wave).
5. Name uses `_Inferred` — class High; method English not PDB-demangled.

**Verdict:** **accept-with-gaps** — CF/ABI/vtable/fields/FailMission arms sealed; product event dictionary + virtual English residual.
