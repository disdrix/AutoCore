# Review A (reconstruction fidelity): `aa_0054c570` CVOGReaction_ResolveSkillTargets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054c570` |
| **VA** | `0x0054c570` |
| **Canonical name** | `CVOGReaction_ResolveSkillTargets` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0054c570_CVOGReaction_ResolveSkillTargets.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Lookup skill **definition** by integer skill ID in global map `DAT_00b04734`. On hit: allocate **0x630**-byte skill runtime, construct, copy **0x18c dwords** from `node+0x10`, apply rank via `Skill_SetRankAndReevaluate` (`skill+0x5f6`), return buffer. On miss (iterator == `DAT_00b04738`): return **null**.

**Naming note (High):** Despite “ResolveSkillTargets”, body **materializes a ranked skill runtime** from the def map — not a TFID target-list builder. Target lists are `Skill_ResolveTargetList` / `Skill_GatherTargetsInArea`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054c570_CVOGReaction_ResolveSkillTargets.md` |
| Annotated | `docs/reconstruction/raw/aa_0054c570_CVOGReaction_ResolveSkillTargets.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_ResolveSkillTargets.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054c570_CVOGReaction_ResolveSkillTargets.md` |
| Fresh asm | Ghidra `disassemble_function` @ `0x0054c570`, `0x005535a0` (2026-07-29) |
| Callers (sample) | EnsureLoadedInTree, ApplyStatusEffectLocal, Outpost cast, RecvSkillStatusEffect |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| SEH frame + lazy init `DAT_00b04724` → `FUN_0054b2c0` | **High** | asm |
| Lookup `FUN_00418890` with **this = `0xb04734`** | **High** | `MOV ECX,0xb04734` |
| Miss when node == `DAT_00b04738` → null | **High** | end/head sentinel; not “cache hit” |
| `operator_new(0x630)` + ctor `FUN_0054f3c0(ECX=alloc)` | **High** | asm |
| `REP MOVSD` count `0x18c` from `node+0x10` | **High** | asm; `0x18c*4=0x630` |
| Rank = **stack arg1** word → `Skill_SetRankAndReevaluate` | **High** | callee `RET 4`; stores `+0x5f6` |
| `unaff_DI` is real rank arg | **Falsified** | decomp phantom after REP MOVSD |
| Symbol = TFID target resolve | **Falsified** | body is materialize |
| Map helper product names | **Tentative** | leave FUN_* |
| Full 0x630 field layout | **Partial** | ctor zeros +0x5f0, +0x184…; rank +0x5f6 sealed |

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| Flag init | **Yes** |
| Map find + sentinel branch | **Yes** |
| Alloc / construct / copy / rank | **Yes** |
| Null return path | **Yes** |
| SetRank args (this + rank dword only) | **Yes** after 2026-07-29 clean fix (drop phantom DI) |
| SEH fidelity in clean | **Partial** (ExceptionList simplified) |

---

## 5. Sealed contract

```
// __cdecl
SkillRuntime* CVOGReaction_ResolveSkillTargets(int skillId, int rankPacked)
  // rank used as word → skill+0x5f6
  ensure skill map init (DAT_00b04724)
  it = map_find(DAT_00b04734, skillId)
  if *it == DAT_00b04738: return null          // miss
  buf = new 0x630; FUN_0054f3c0(buf)
  memcpy 0x630 from (*it)+0x10
  Skill_SetRankAndReevaluate(buf, (short)rankPacked)
  return buf
```

Prefer AutoCore port name: `MaterializeSkillRuntime` / `CloneSkillTemplateByRank` (keep Ghidra symbol as index).

---

## 6. Gaps

1. Product names for map/ctor/init helpers.
2. Complete skill-runtime struct beyond +0x5f0/+0x5f6 and ctor zero spans.
3. Free/own policy is **caller-owned** (tree insert vs delete) — not inside this unit.
4. Runtime capture / bit-exact open.

**Verdict:** CF + ABI sealed via asm. **accept-with-gaps.**
