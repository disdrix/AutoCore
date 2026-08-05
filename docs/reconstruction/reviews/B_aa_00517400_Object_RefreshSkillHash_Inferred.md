# Review B (skeptical / adversarial): `aa_00517400` Object_RefreshSkillHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-T) |
| **Counterpart** | `reviews/A_aa_00517400_Object_RefreshSkillHash_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function is only a debug-stop / error stub (`Named_VOG_DEBUG_STOP`) | **Falsified** — strings only on lock misuse; real work is full skill hash refresh |
| 2 | `__thiscall` with host in ECX | **Falsified** — both formals on stack; bare `ret` not `ret 4` |
| 3 | Calls `Skill_SiblingCastClear` (`0x00514e20`) | **Falsified as direct call** — **inlines** same predicate/list pack with flag 0 |
| 4 | Sibling clear always runs | **Falsified** — needs gate vfuncs + `skill+0x615&1` |
| 5 | Always reloads skill defs | **Falsified** — gated by `param_2` |
| 6 | Decompiler list-less `InvokePredicateAndRemove` is complete | **Falsified** — ECX=`*(host+0xB0)` at call site |
| 7 | Same unit as skill-tree vector remove `0x0052db50` | **Falsified** — different container (hash vs `+0x550` vector) |
| 8 | Returns meaningful status in EAX | **Unfounded** — void-shaped; no sealed return contract |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + bare ret | **High** | wrong port ABI / stack smash |
| Hash lock/traverse offsets | **High** | skip skills / reentrancy corruption |
| Inline sibling clear flag **0** | **High** | wrongly clear OKToCastAgain (flag 1 is remove path) |
| Name write `skill+0x1a5` | **High** | UI/name desync |
| Product English name | **Open** | catalog only |
| Wide buffer mapping | **Medium** | name copy wrong source |

---

## 3. Cross-check against raw + bytes

```
// must preserve:
lock hash+0x1d;
for each skill in hash chain:
  maybe InvokePredicateAndRemove(list@+0xB0, pred 0x00512bb0, ctx flag0);
  if bReload: load+install def;
  Skill_ReevaluateForCurrentRank(skill);
  WideCharToMultiByte → FUN_0054f430(skill, mb);  // skill+0x1a5
unlock;
maybe FUN_00516a00(0);
```

Any clean plate that uses `ret 4`, calls `0x00514e20` instead of inlining, or forces flag=1 is **wrong** for this VA.

---

## 4. Surviving contract for AutoCore

```c
// Port:
void Object_RefreshSkillHash_Inferred(Object* host, bool reloadDefs);

// - Traverse skill hash under lock (same errors as other HashError sites).
// - Sibling cast clear uses flag 0 (SkillBase HBs only).
// - Always reevaluate rank; always refresh MB name at skill+0x1a5.
// - Do not invent network or skill-tree vector mutation here.
```

---

## 5. Open questions

1. PDB symbol.
2. When callers pass `bReloadSkillDef=1` vs `0` (only `FUN_00517df0` — flag sourcing partially noisy).
3. Whether ports should share one helper with `FUN_00516a00` traverse loop.

**Verdict:** **accept-with-gaps**
