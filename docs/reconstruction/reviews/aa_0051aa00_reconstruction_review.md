# Reconstruction review: `aa_0051aa00` Skill_ApplyStatusEffectLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aa00` |
| **VA** | `0x0051aa00` |
| **Canonical name** | `Skill_ApplyStatusEffectLocal` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_0051aa00_Skill_ApplyStatusEffectLocal.md` | Authoritative decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_0051aa00_Skill_ApplyStatusEffectLocal.annotated.md` | Human refine |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Skill_ApplyStatusEffectLocal.cpp` | Clean CF |
| Function record | `docs/reconstruction/functions/aa_0051aa00_Skill_ApplyStatusEffectLocal.md` | Summary |
| Callers | `Client_RecvSkillStatusEffect.cpp`, `CVOGReaction_CastSkillOnTarget.cpp` | Apply gates |
| Topic | `docs/topic-extractions/skill-cast.md` | 0x2031 field map |

**Primary claims under review:**

1. Item vs non-item path on `packet+0x38`.
2. Active binding cancel → return `0x11`.
3. Sim (`world+0x7e`) cast-again HB + clear counter.
4. Target strip: `(size-0x40)/0x18` × 16B from stride 0x18.
5. `lDelayTime < 1` immediate apply else delayed HB `0x674`.
6. Clean preserves raw CF including SEH frame and decompiler holes.

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw body | Raw capture | Full CF |
| Annotated | Annotated | Packet map, open questions |
| Clean | reconstructed-exact | Faithfulness |
| Topic field table | skill-cast.md | Cross-check offsets |
| CastSkillOnTarget | packer caller | When local apply is invoked |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Match |
|---|---|
| Entry status `local_4f8 = 2` | **Yes** |
| Non-item: vtbl `+0x234` skill lookup / EnsureLoaded / SetRank | **Yes** |
| Item: `CVOGReaction_ResolveSkillTargets` | **Yes** |
| Null skill → debug stop return status | **Yes** |
| Sim random rewrite of `+0x3c` | **Yes** |
| Binding lookup; status `0x11`; clear binding; early return conditions | **Yes** |
| Sim: StartCastAgainHeartbeat + ClearActiveCastCounter | **Yes** |
| Item: InsertCategoryCooldown | **Yes** |
| Target count formula + 16B copy from 0x18 stride | **Yes** |
| Delay branch immediate vs delayed HB | **Yes** |
| Non-local VFX cue `vtbl+0x238(3,...)` | **Yes** |
| Free list; non-item return; item `operator_delete(skill)` | **Yes** |

### 3.2 Packet size / target formula

`(size - 0x40) / 0x18` matches packer size `n*0x18+0x58` with header/trailer accounting (**consistent** with topic).

### 3.3 Type renames

`undefined*` → fixed widths; skill remains `CVOGHBBase*` mis-type as in raw (documented). Rank compare uses sealed `+0x5f6/+0x174` comment path — **partial** improvement over raw overlay; still noted as open equate.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Skill typed as CVOGHBBase | High for layout | Clean documents; some overlay offsets (`+0x130`) are **not sealed** skill fields |
| Rank compare rewritten to `+0x5f6/+0x174` | Medium | Cross-unit Probable; raw member expression not bit-identical |
| `unaff_EDI` / `extraout_var` / `nInferred` | Medium | Preserved holes |
| `operator_delete` noreturn warning | Medium | Preserved as free |
| FUN_* apply/HB helpers unnamed | Medium | Preserved |
| Binding TFID stack layout assumed 16B contiguous | Low | Matches LookupActiveCastBinding pattern elsewhere |

**Acceptable for fidelity review** with gaps called out. Prefer not silently treating overlay offsets as skill ABI.

---

## 5. What remains uncertain

1. True calling convention.
2. Exact skill fields under HB mis-type for cancel/CD branches.
3. Whether return `0x11` is observed by Recv as status or only local.
4. `FUN_005538a0` / `FUN_006061e0` identities.
5. Runtime of delayed HB vs `lDelayTime=0` server policy (topic notes server often sends 0).

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean reproduces item/non-item split, binding cancel `0x11`, sim cast-again, target strip formula, delay branch, and return status paths from raw without inventing network send.

**Gaps:** skill field overlays, helper names, convention, rank-sum equate.

**Not needs-revision** for structural raw parity; layout seal is a follow-up reconstruction pass.

---

## 7. Reviewer role statement

Faithfulness of clean to low-level CF. Does not endorse CVOGHBBase member names as skill runtime layout.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** (with documented rank-offset improve) |
| 0x11 cancel path preserved | **Pass** |
| Target strip formula preserved | **Pass** |
| Delay branch preserved | **Pass** |
| Skill layout sealed | **Open / Fail** |
| Verdict | **accept-with-gaps** |
