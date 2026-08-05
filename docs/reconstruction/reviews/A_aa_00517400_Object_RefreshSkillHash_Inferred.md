# Review A (reconstruction fidelity): `aa_00517400` Object_RefreshSkillHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517400` |
| **VA** | `0x00517400` |
| **Body** | `0x00517400`–`0x00517675` |
| **Canonical name** | `Object_RefreshSkillHash_Inferred` |
| **Prior / alias** | `FUN_00517400`; `Named_VOG_DEBUG_STOP_00517400` (**misleading** — string is error path only) |
| **Review date** | `2026-07-29` (W20-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00517400_Object_RefreshSkillHash_Inferred.md` |
| **System** | `skills-abilities` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host-side **skill-hash full refresh**: lock `*(host+0x70)` hash for traversal, visit every skill node, per skill:

1. If host player/vehicle-style gates pass and `skill+0x615&1`: **inline** sibling cast clear (predicate flag **0**, list `*(host+0xB0)`, TFID `host+0x160`).
2. If `bReloadSkillDef≠0`: load skill-def for `skill+0x5fc` and install (`FUN_007e26e0` + `FUN_0054a290` family).
3. `Skill_ReevaluateForCurrentRank(skill)`.
4. Convert wide display name → MB; `FUN_0054f430(skill, mb)` → **`skill+0x1a5`**.

On end of chain: unlock; optionally `FUN_00516a00(0)` when gates pass.

Not skill-tree vector remove (`0x0052db50`). Not wire I/O. Not rank train UI.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00517400_FUN_00517400.md` |
| Annotated | `docs/reconstruction/raw/aa_00517400_FUN_00517400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_RefreshSkillHash_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00517400.cpp` |
| Function record | `docs/reconstruction/functions/aa_00517400_Object_RefreshSkillHash_Inferred.md` |
| Live decompile | hash lock + per-skill path + reevaluate + name |
| Live bytes | entry SEH; sibling site `mov ecx,[esi+0xB0]`; epilogue bare `c3` |
| Sibling duals | `aa_00514e20`, `aa_00512bb0`, `aa_004e2600` |
| Reevaluate dual | `aa_00553390` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__cdecl` (host*, char); bare `ret` | **High** | stack formals; `c3` epilogue |
| Null host early-out | **High** | decomp |
| Hash at `host+0x70`; lock `+0x1d` | **High** | strings + offsets |
| Chain: head `hash+0x14`, next `node+0x14`, skill `node+8` | **High** | decomp |
| List `*(host+0xB0)` for sibling clear | **High** | `read_memory` call site |
| Predicate `0x00512bb0`; flag **0** | **High** | push imm + ctx store |
| TFID from `host+0x160` (`[0x58..]`) | **High** | decomp + sibling dual |
| Gate: `vtbl+0x210(0)` / `+0x214` | **High** role; English open | call pattern |
| `skill+0x615&1` gates cast clear | **High** | decomp |
| Optional def reload when `param_2≠0` | **High** CF; product of callees open | |
| `Skill_ReevaluateForCurrentRank` always | **High** | named callee |
| MB name → `skill+0x1a5` via `FUN_0054f430` | **High** | callee body + ECX=skill |
| End → `FUN_00516a00(0)` under gates | **High** | decomp |
| Sole caller `FUN_00517df0` | **High** | xrefs |
| Product/PDB symbol | **Open** | structural `_Inferred` |
| Wide buffer exact origin | **Open** | large stack WCHAR |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null check → lock → loop | **Yes** |
| Inlined sibling clear (flag 0) not call to `00514e20` | **Yes** |
| Optional def reload | **Yes** |
| Reevaluate + name copy | **Yes** |
| Unlock + optional `00516a00` | **Yes** |
| No invented wire/train/XP | **Yes** |
| List this restored (decomp omitted) | **Yes** (asm) |

---

## 5. Gaps / open

1. Product demangled name.
2. English for `vtbl+0x210` / `+0x214`.
3. Wide-name buffer provenance after reevaluate.
4. Exact size/role of `FUN_007e26e0` load buffer in this path.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, hash traverse, sibling-clear inline, reevaluate+name, and caller sealed; product English open.
