# Review A (reconstruction fidelity): `aa_0052db50` SkillTree_RemoveBySkillId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052db50` |
| **VA** | `0x0052db50` |
| **Body** | `0x0052db50`–`0x0052dc15` |
| **Canonical name** | `SkillTree_RemoveBySkillId_Inferred` |
| **Prior / alias** | `FUN_0052db50` |
| **Review date** | `2026-07-29` (W20-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md` |
| **System** | `skills-abilities` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Skill-tree vector remove-by-id**: walk 12-byte elements in `[this+0x550, this+0x554)`. On match `skill+0x5fc == nSkillId`:

1. MI this-adjust → cast-list host (`adj+4`).
2. `Skill_SiblingCastClear(host, skillId, hostTFID, **flag=1**)` — clears skill cast HBs **and** OKToCastAgain.
3. `operator_delete(skill)`.
4. Erase element (slide tail, `end -= 0xC`); continue without index advance.

Not hash refresh (`0x00517400`). Not generic vector erase without cast clear.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052db50_FUN_0052db50.md` |
| Annotated | `docs/reconstruction/raw/aa_0052db50_FUN_0052db50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillTree_RemoveBySkillId_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0052db50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052db50_SkillTree_RemoveBySkillId_Inferred.md` |
| Live decompile | match + SiblingCastClear + delete (erase **missing**) |
| Live bytes | full body incl. slide loop + `add [esi+0x554], -0xC` + `ret 4` |
| Sibling dual | `aa_00514e20` Skill_SiblingCastClear |
| Caller | `FUN_00623a20` — `mov ecx, edi` after `vtbl+0x210(0)` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`; `ret 4` | **High** | ECX=this; `c2 04 00` |
| Vector begin/end `+0x550/+0x554` | **High** | loads |
| Element stride **12** | **High** | `+3` dwords / `add edi,0xC` |
| Match key `skill+0x5fc` | **High** | cmp |
| MI adjust `this + *(*(this+4)+4)` | **High** | lea sequence |
| SiblingCastClear ECX = `adj+4` | **High** | `lea ecx,[eax+4]` |
| TFID at `adj+0x164` ≡ host `+0x160` | **High** | resolves prior dual gap |
| Flag **1** | **High** | `push 1` |
| `operator_delete` returns; erase follows | **High** | bytes; decomp wrong |
| Slide + `end-=0xC`; no advance on match | **High** | `eb 03` skips `add edi,0xC` |
| Sole caller family `FUN_00623a20` | **High** | 3 xrefs |
| Product/PDB name | **Open** | |
| Element +4/+8 fields | **Open** | only bulk-moved |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Empty range early return | **Yes** |
| Match → clear(flag1) → delete → erase → continue | **Yes** (erase from **bytes**, not raw decomp alone) |
| Non-match advance 0xC | **Yes** |
| No invented second container | **Yes** |

Raw decompile alone is **insufficient** — clean must include erase. Annotated documents the correction.

---

## 5. Gaps / open

1. Product demangled name / owning class of `+0x550`.
2. Element `+4`/`+8` semantics.
3. Duplicate skillId policy (loop allows multi-remove).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, match, SiblingCastClear flag1 + host adjust, delete+erase sealed; product English open.
