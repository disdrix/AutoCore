# Reconstruction review: `aa_004d09a0` CVOGReaction_CastSkillOnTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d09a0` |
| **VA** | `0x004d09a0` |
| **Canonical name** | `CVOGReaction_CastSkillOnTarget` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` | Authoritative decompile; `0x2031` packer plate |
| Annotated low-level | `docs/reconstruction/raw/aa_004d09a0_CVOGReaction_CastSkillOnTarget.annotated.md` | Scaffold |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGReaction_CastSkillOnTarget.cpp` | Clean CF |
| Function record | `docs/reconstruction/functions/aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` | Partial scaffold |
| Topic extraction | `docs/topic-extractions/skill-cast.md` | Field map, size formula, status codes |
| System map | `docs/reconstruction/systems/skills-abilities.md` | Cast reaction entry |

**Primary claims under review:**

1. Gate: `param_1+0x7e != 0`, `param_2 != 0`, `param_3 != 0`
2. Optional rematerialize `param_4` via vtable `+0x19c` for modes `0xe/0x12/0x14/0x3`
3. Alloc packet buffer `0x9a0`; write opcode `0x2031`; fill skill id, level, delay, status, source TFID, item flag, position
4. If no target list: `Skill_ResolveTargetList`; map flags to local codes `0xd`/`0xe`/…
5. Walk TFID list; resolve objects; write 0x18-byte target slots + mana shorts; terminator; size `n*0x18+0x58`
6. Conditional `Skill_ApplyStatusEffectLocal`; `operator_delete` packet

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw body | Raw capture | Full CF |
| Annotated | Annotated | Parity |
| Clean | reconstructed-exact | Faithfulness |
| Topic extraction field table | skill-cast.md | Cross-check plate claims vs stores |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Match |
|---|---|
| Entry gate on `+0x7e` / skill / source | **Yes** |
| Mode-based `param_4` remap | **Yes** |
| Packet alloc `0x9a0`, opcode `0x2031` | **Yes** |
| Skill id `param_2+0x5fc` → `pPacket[2]` | **Yes** |
| Source TFID from `param_3+0x160..0x16c` → `pPacket[10..0xd]` | **Yes** |
| Level short sum `+0x5f6 + +0x174` | **Yes** |
| Status byte `-(param_10!=0)&99` (`0` or `99`/`'c'`) | **Yes** |
| Remaining delay `max(0, skill+0x14 - param_11)` | **Yes** |
| Position from `param_7` | **Yes** |
| Optional field `param_8` → `pPacket[0xf]` | **Yes** |
| `Skill_ResolveTargetList` when `param_6 == null` | **Yes** |
| Error flag collapse to `0xd`/`0xe`/other in `local_8` | **Yes** |
| Target walk + `Object_ResolveFromTFID` + mana shorts | **Yes** |
| Terminator invalid TFID; size short formula | **Yes** |
| Conditional `Skill_ApplyStatusEffectLocal` | **Yes** |
| `operator_delete(pPacket)` | **Yes** |
| Return `0` | **Yes** |

### 3.2 Size formula check

Plate: `size = nTargets*0x18 + 0x58`.  
Body: `*(short*)(pPacket+1) = (short)(nTargets*3)*8 + 0x58` → `n*24+0x58`. **Matches.** Clean preserves formula.

### 3.3 Type renames

`undefined4` → `uint32_t`; TFID struct fields retained. No modernization of target loop.

---

## 4. Discrepancies or improvements needed

Shared scaffold defects (clean ≡ raw):

| Item | Severity | Notes |
|---|---|---|
| No network send of `0x2031` in body | High for *role* | Pack + optional local apply + delete; “packer” may be local buffer builder only in this decompile |
| Ghidra “Subroutine does not return” on `operator_delete` | Medium | False noreturn contamination risk; clean preserves call |
| `local_8` range/target codes never written into `pPacket` status | High for plate field map | Status set only from `param_10` → 0/`'c'`; resolve errors stored in `local_8` then overwritten by ApplyStatusEffectLocal return |
| Param names `param_1..11` unrecovered | High for API | Faithful to raw |
| Item flag store as `*(bool*)(pPacket+0xe) = (param_5==0)` | Medium | Polarity inverted vs naive “param_5 is flag” reading — preserved |
| Possible null `pPacket` if alloc fails then write | Medium | Raw same |

**No revision required** for clean-vs-raw fidelity.

---

## 5. What remains uncertain

1. Whether a send exists outside this function or was lost by decompiler.
2. Full formal names (world, skill, source, target owner, …).
3. Whether `local_8` errors affect status elsewhere.
4. Relationship to server `SkillStatusEffect` builder vs client local path (`param_1+0x7e` gate suggests sim/server mode).
5. Runtime of multi-target mana packing.

---

## 6. Verdict

### **accept-with-gaps**

Clean reproduces the full raw packer CF, field stores, target walk, size formula, and local apply gate without inventing a send or modern packet API.

**Gaps:** no send in decompile; unresolved params; status vs resolve-error disconnect; noreturn warning artifact.

**Not needs-revision** for raw parity.

---

## 7. Reviewer role statement

Faithfulness of clean C++ to low-level only. Does not certify that this function alone implements retail network SkillStatusEffect emission.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Opcode `0x2031` + size formula | **Pass** |
| Target slot stride 6 dwords / 0x18 | **Pass** |
| No invented send | **Pass** (absent in raw too) |
| Status field vs resolve errors sealed | **Open** |
| Verdict | **accept-with-gaps** |
