# Review A (reconstruction fidelity): `aa_00517b90` Skill_ClearActiveCastCounterAndQueueId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517b90` |
| **VA** | `0x00517b90` |
| **Canonical name** | `Skill_ClearActiveCastCounterAndQueueId` |
| **Review date** | `2026-07-29` (residual refresh; prior 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Post-cast / cast-release bookkeeping on the **lazy busy/cast slot** (`FUN_005169c0` → `*(this+0x64)` → 0x14 block):

1. If slot counter **`+0x10` ≥ 1**: **decrement** counter; when it hits **0**, zero **`+0xC`** (queue-id / head linkage INFERRED).
2. **Always** push `nSkillId` onto the deferred cast ring via `Skill_QueueDeferredCastId` with **slot** as `this`.
3. Return **AL = 1** if counter was ≥ 1 at entry, else **0**.

Not validation, not power/range, not network send. Name says “Clear” but body is **dec + conditional zero of +0xC**, not force-zero of counter.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.md` |
| Annotated | `docs/reconstruction/raw/aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ClearActiveCastCounterAndQueueId.cpp` |
| Function record | `docs/reconstruction/functions/aa_00517b90_Skill_ClearActiveCastCounterAndQueueId.md` |
| Residual scratch | `docs/reconstruction/reviews/a_00517b90.md` |
| Pair filter (xref only) | `FUN_005169c0` `0x005169c0`; `Skill_QueueDeferredCastId` `0x0051d3b0` |
| Callers (Ghidra xrefs, 4) | `Skill_ApplyStatusEffectLocal` `0x0051aa00` @ `0x0051ac5e`; `Client_QuickBarActivateSkillSlot` `0x00921b50` @ `0x00921cdf`; `Client_RequestCastSkill` `0x00941590` @ `0x0094170d`; `Client_StanceOrGadgetActivatePath` `0x0093a3d0` @ `0x0093a501` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| **ABI:** ECX = owner `this`; stack `nSkillId`; `RET 4` | **High** | asm `MOV ESI,ECX` + `RET 0x4`; Ghidra label `__stdcall` is incomplete |
| Slot via `FUN_005169c0` three times | **High** | `0x00517b96`, `0x00517ba3`, `0x00517bcd` |
| Counter field **slot+0x10** | **High** | `CMP [EAX+0x10],1` / store back |
| Gate is **counter ≥ 1** (`CMP …,1` / `JC`) | **High** | ≡ nonzero for non-negative; decomp `!= 0` OK |
| **Decrement** not force-clear of +0x10 | **High** | `ADD ECX,-1` + store |
| Zero **slot+0xC** only when post-dec == 0 | **High** | `MOV [EAX+0xc],EBX` under JZ path |
| Return **AL = was-counter-live** (1/0) | **High** | `XOR EBX,EBX` → optional `MOV BL,1` → `MOV AL,BL` — not merely INFERRED |
| Always `Skill_QueueDeferredCastId(slot, &nSkillId)` | **High** | third lazy-get → `MOV ECX,EAX`; push `&nSkillId` |
| Queue `this` is **slot block**, not outer owner | **High** | `CALL FUN_005169c0` then `MOV ECX,EAX` before Queue |
| Not cast validate / not C2S | **High** | no packet, no LocalCastValidate |
| Callers use return for StartCastAgain gate | **Falsified** | all 4 sites: no `TEST AL` / consume; side-effect only then check skill `+0x61c` |
| Product English for +0xC / outer type of ECX | **INFERRED / open** | counter-like +0x10 paired with LocalCastValidate busy code 6 |

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| Save `this` (ESI); BL=0 | Yes (asm; decomp omits explicit this) |
| slot = lazy-get; if +0x10 < 1 → skip dec | Yes |
| Re-get slot; if +0x10 != 0: dec; if 0 clear +0xC | Yes |
| BL = 1 on live-counter path | Yes |
| Always queue nSkillId on slot | Yes |
| `return AL` | Yes |
| No invented network / validate | Yes |

**Decomp caveat (sealed):** third site displays as `FUN_005169c0(piVar4); Skill_QueueDeferredCastId(piVar4)` — **wrong arg picture**. Asm: `PUSH &nSkillId; MOV ECX,this; CALL FUN_005169c0; MOV ECX,EAX; CALL Skill_QueueDeferredCastId`.

---

## 5. Sealed residual (2026-07-29)

Full asm + caller matrix in `reviews/a_00517b90.md`.

| Offset / symbol | Role |
|---|---|
| Outer `this` (ECX) | Owner of lazy ptr at **`+0x64`** (same object `FUN_005169c0` expects) |
| `FUN_005169c0` | Lazy alloc/get **0x14** slot; zero +4/+8/+0xC/+0x10 on first use |
| **slot+0x10** | Active-cast / busy **refcount** (LocalCastValidate: nonzero → eSkillResponses **6**) |
| **slot+0xC** | Cleared when refcount hits 0 — queue-id / deferred-head **INFERRED** |
| `Skill_QueueDeferredCastId` | Ring push of `*param_2` (skill id); uses slot +4/+8/+0xC/+0x10 |

---

## 6. Gaps / open

1. Product / PDB name for outer `this` type and slot fields (+0x0 unused? +4/+8 ring bases).
2. Who **increments** +0x10 (pairing producer not this unit).
3. Runtime / bit-exact / image diff (matrix policy).
4. Canonical name “Clear…” slightly overstates (dec + clear +0xC); keep registry name unless rename pass.

**Verdict:** **accept-with-gaps** — CF/ABI/offsets/return **sealed High**; product type names + incrementer open.
