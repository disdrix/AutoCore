# Review A (reconstruction fidelity): `aa_0051a980` Skill_EnsureLoadedInTree

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a980` |
| **VA** | `0x0051a980` |
| **Canonical name** | `Skill_EnsureLoadedInTree` |
| **Review date** | `2026-07-29` (dual strengthen) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051a980_Skill_EnsureLoadedInTree.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Lazy-ensure a **skill runtime** is present in the owner object's skill-tree **CNDHash** at **`this+0x70`**, keyed by **integer skill id**.

Control flow (byte-sealed from function body at `0x0051a980`):

1. If `nSkillId <= 0` → return (void).
2. `skill* = CNDHash_LookupByKey(*(this+0x70), nSkillId)`.
3. **Miss:** materialize via `CVOGReaction_ResolveSkillTargets(skillId, rank)` (`0x0054c570`).  
   - Non-null → `FUN_0051e6d0` insert into same hash (`this+0x70`, key=skillId, value=skill*, flag=`0`).  
   - Null → `FUN_007a4480(0, "AddSkillToTree, unable to find skill #%d, level %d", skillId, (int)rank)`.
4. **Hit:** if `*(short*)(skill+0x5f6) < sRank` → `Skill_SetRankAndReevaluate(skill, sRank)`; else no-op (equal/higher rank leaves instance alone).

**Return type is `void`.** Callers that need the pointer re-lookup (e.g. vtable `+0x234` on the caster after ensure) — they do **not** consume a return value from this unit.

String at `0x009cec5c`: `"AddSkillToTree, unable to find skill #%d, level %d"` (confirms product intent name **AddSkillToTree** / ensure-into-tree).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051a980_Skill_EnsureLoadedInTree.md` |
| Annotated | `docs/reconstruction/raw/aa_0051a980_Skill_EnsureLoadedInTree.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_EnsureLoadedInTree.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051a980_Skill_EnsureLoadedInTree.md` |
| Materialize dual | `reviews/A_aa_0054c570_CVOGReaction_ResolveSkillTargets.md` |
| Live Ghidra | decompile + basic pcode + `read_memory` body `0x0051a980` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=owner; stack `int skillId`, rank word; `ret 8` | **High** | body ends `C2 08 00` × all exits |
| Guard `skillId > 0` | **High** | `TEST ESI; JLE exit` |
| Hash at `owner+0x70` | **High** | `MOV ECX,[EDI+0x70]` both lookup + insert |
| Hash **key = skill id** (not cbid) | **High** | same int pushed to Lookup/Insert/log; callers pass skill ids |
| Miss → materialize `0x0054c570` then insert `FUN_0051e6d0` | **High** | call order + insert signature |
| Insert flag arg literal `0` | **High** | `PUSH 0` before insert |
| Hit rank field `skill+0x5f6` (s16) | **High** | `CMP [EAX+0x5f6], CX`; cross-unit sealed |
| Upgrade only if **strictly lower** rank | **High** | `JGE` skip SetRank |
| SetRank is thiscall + **one** stack rank arg | **High** | callee `0x005535a0` `RET 4`; no DI rank |
| `unaff_DI` / `_sRank` / `in_stack_0000000a` | **Falsified as real args** | decomp phantoms; rank is stack |
| Return is **void** (not skill*) | **High** | no EAX return use; plate was wrong |
| `FUN_007a4480` = NDError-style log | **High** | body + path string; flag `0` may soft-skip emit |
| `FUN_0051e6d0` = hash **insert** (tree owns) | **High** | callee decomp + post-materialize call |
| Not cast validate / not target list | **High** | scope vs LocalCastValidate / ResolveTargetList |
| Distinct from bulk `aa_004c8a60` | **High** | alias unit only; product is this VA |
| Callers: status, summon HB, loadout bulk, NPC spawn skills, … | **High** | 17 xrefs; sample decomp sites |

---

## 4. Control flow: clean ≡ raw ≡ body bytes

| Stage | Match |
|---|---|
| `skillId<=0` early out | **Yes** |
| Lookup hash `+0x70` by skillId | **Yes** |
| Miss → materialize → insert or log | **Yes** |
| Hit → rank cmp → optional SetRank | **Yes** |
| No invented cast send / target resolve | **Yes** |
| Clean return-as-pointer claim | **No** — clean/raw plate overstates return; **void** sealed |
| Clean `_sRank` / `unaff_DI` | **Decomp noise** — treat as stack rank only |

---

## 5. Sealed contract

```
// __thiscall  ret 8
void Skill_EnsureLoadedInTree(Owner* this, int skillId, short rank)
{
  if (skillId <= 0) return;
  CNDHash* tree = *(this + 0x70);
  SkillRuntime* s = CNDHash_LookupByKey(tree, skillId);
  if (s == null) {
    s = CVOGReaction_ResolveSkillTargets(skillId, rank);  // materialize 0x630 or null
    if (s) FUN_0051e6d0(tree, skillId, s, /*flag*/0);    // insert; tree owns
    else   FUN_007a4480(0, "AddSkillToTree, unable to find skill #%d, level %d",
                        skillId, (int)rank);
    return;
  }
  if (*(short*)(s + 0x5f6) < rank)
    Skill_SetRankAndReevaluate(s, rank);  // stores +0x5f6, reevaluates
}
```

**Caller pattern (ApplyStatusEffectLocal non-item):**  
`EnsureLoadedInTree(caster, packet.skillId, 0)` then re-fetch via vfunc `+0x234(skillId)`; if still null → fail path.

**Ownership:** on successful miss path, **tree owns** the materialized runtime (contrast item/outpost paths that materialize then `operator_delete`).

---

## 6. Gaps / open

1. Product name for `FUN_0051e6d0` (hash insert; leave FUN until rename batch).
2. Exact type of object hosting `+0x70` skill hash (creature/character skill component layout beyond this offset).
3. Whether log flag `0` ever surfaces in retail builds (emit gated on flag==1 in `FUN_007a4480`).
4. Runtime / bit-exact / image diff still open.
5. Clean/raw still carry decomp phantoms (`_sRank`, `unaff_DI`) — CF correct, presentation noisy.

**Verdict:** **accept-with-gaps** — CF, ABI, key identity, rank gate, and void return sealed via body bytes + callees. Residual naming/layout only.
