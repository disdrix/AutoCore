# Review A (reconstruction fidelity): `aa_005304a0` CVOGCharacter_UpsertSkillRankAndReapply_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005304a0` |
| **VA** | `0x005304a0` |
| **Canonical name (Ghidra)** | `FUN_005304a0` |
| **Proposed name** | `CVOGCharacter_UpsertSkillRankAndReapply_Inferred` (**High** role; product English open) |
| **Prior scaffold alias** | `Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_005304a0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W16-R) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live; bytes override decomp phantoms) |
| **Counterpart** | `reviews/B_aa_005304a0_CVOGCharacter_UpsertSkillRankAndReapply_Inferred.md` |
| **System** | `skills-abilities` / character skill bag |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Character **skill-bag upsert + local re-apply**:

1. Linear search bag range `[this+0x550, this+0x554)` with **stride 0xC**.
2. Match when `*(skillRuntime + 0x5fc) == skillId`.
3. **Hit:** set rank on existing runtime; write `param_4` into `entry+4`; re-apply local effects for `skillId`.
4. **Miss:** materialize ranked runtime via `CVOGReaction_ResolveSkillTargets(skillId, rank)`; on success push `{skill*, param_4, flag=1}` onto vector at `this+0x54c`; re-apply. On materialize **null**, no bag change / no reapply.

**Not** medal inventory. **Not** wire cast validate. **Not** global skill-def map owner (that is ResolveSkillTargets).

Used from medal award chain (`def+0x14` skill id, `def+0x18` rank, meta 0), create-from-packet, and multi-slot helper `FUN_00623960`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005304a0` |
| Bytes | `read_memory` 160 B @ entry + tail through `RET 0xC` |
| Callees decomp | `ResolveSkillTargets`, `Skill_SetRankAndReevaluate`, `FUN_0053aea0`, `FUN_00514e70` |
| Callers | `get_function_callers` → `00534bd0`, `00530550`, `00623960` |
| Medal dual | `A\|B_aa_00530550_CVOGCharacter_AwardMedalById` (chains this) |
| Materialize dual | `A\|B_aa_0054c570_CVOGReaction_ResolveSkillTargets` |
| Reapply dual | `A\|B_aa_00514e70_Skill_ApplyLocalById_Inferred` (lists this as caller) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005304a0` |
| Function record | `docs/reconstruction/functions/aa_005304a0_FUN_005304a0.md` |

**This pass:** decompile + read_memory + callers/callees + related duals. **Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledger edits.

---

## 3. Signature

```c
void __thiscall CVOGCharacter_UpsertSkillRankAndReapply_Inferred(
    void *character,    // ECX — bag at +0x54c/+0x550/+0x554
    void *skillId,      // stack0 — key vs skill+0x5fc
    void *rankPacked,   // stack1 — rank for SetRank / materialize
    int   param_4);     // stack2 — entry+4 meta (medal/create often 0)
// RET 0xC
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` + **RET 0xC** | both paths end `ADD ESP,0xC; RET 0xC` | **High** |
| ECX = character | medal site `MOV ECX,ESI`; bag offsets on EDI | **High** |
| 3 stack formals | `RET 0xC`; medal `PUSH 0; PUSH rank; PUSH skillId` | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Hit/miss CF + stride 0xC | **High** | bytes loop |
| Key at `skill+0x5fc` | **High** CF | English “skill id” **Probable** (medal def+0x14) |
| Miss → ResolveSkillTargets then vector push | **High** | |
| Vector this = `character+0x54c` | **High** | `LEA ECX,[EDI+0x54c]` |
| Insert triple `{skill, param_4, 1}` | **High** | stack locals |
| SetRank one stack arg; **no `unaff_DI`** | **High** | phantom falsified |
| Reapply via `FUN_00514e70` after both paths | **High** | |
| this-adjust before reapply | **High** bytes | type story **Tentative** |
| `param_4` product meaning | **Tentative** | always 0 at medal/00623960 samples |
| clean CF ≡ raw | **High** | ABI notes corrected in clean |
| Product English name | **Open** | |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Walk begin/end stride 0xC | Yes |
| Match `+0x5fc` | Yes |
| Miss: materialize / null abort | Yes |
| Miss: push triple + reapply | Yes (clean shows vector this explicitly) |
| Hit: SetRank + meta + reapply | Yes |
| `unaff_DI` third SetRank arg | **No in bytes** — clean drops it |

### Sealed contract

```
UpsertSkillRankAndReapply(character, skillId, rank, meta):
  for e in bag[begin,end) step 0xC:
    if e.skill->idAt5fc == skillId:
      SetRank(e.skill, rank)
      e.meta = meta
      ApplyLocalById(host_adjust(character), skillId)
      return
  skill = MaterializeSkillRuntime(skillId, rank)  // ResolveSkillTargets
  if !skill: return
  bag.push({skill, meta, flag=1})
  ApplyLocalById(host_adjust(character), skillId)
```

---

## 6. Callers / callees

| Callee | Role |
|---|---|
| `CVOGReaction_ResolveSkillTargets` | miss → new 0x630 runtime or null |
| `FUN_0053aea0` | vector push_back 0xC at `+0x54c` |
| `Skill_SetRankAndReevaluate` | hit → `skill+0x5f6` + reevaluate |
| `FUN_00514e70` | local re-apply by skill id |

| Caller | Role |
|---|---|
| `CVOGCharacter_AwardMedalById` | optional skill grant from medal def |
| `CVOGCharacter_ApplyCreateFromPacket` | create-time skill bag fill |
| `FUN_00623960` | multi skill-id upsert with shared rank short |

---

## 7. Gaps / open

1. Product names (bag type, `param_4`, this-adjust base).
2. Skill runtime full layout beyond `+0x5f6` rank / `+0x5fc` key / `+0x615` active bit (from reapply dual).
3. Teardown / free of bag skill pointers.
4. Whether miss path can double-insert same id under races (no lock in body).
5. Runtime / bit-exact open.

**Verdict:** CF + ABI sealed with decomp phantom corrected. **accept-with-gaps.**
