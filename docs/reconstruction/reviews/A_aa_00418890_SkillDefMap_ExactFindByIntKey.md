# Review A (reconstruction fidelity): `aa_00418890` SkillDefMap_ExactFindByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418890` |
| **VA** | `0x00418890`–`0x004188d8` |
| **Canonical name** | `SkillDefMap_ExactFindByIntKey` (INFERRED structural; Ghidra still `FUN_00418890`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (map exact find) |
| **Counterpart** | `reviews/B_aa_00418890_SkillDefMap_ExactFindByIntKey.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **ordered-map exact find** for the global **skill-definition** tree rooted at `DAT_00b04734`.

`__thiscall(this=mapHeader, pOutNode, pKey)` with **`ret 8`**.

Walks via callee `FUN_00418c70` (lower-bound-shaped tree walk; nil flag **`node+0x641`**, int key at **`node+0x0C` / `node[3]`**). Then **accepts only exact match**: candidate ≠ end (`*(this+4)`) **and** `node.key <= *pKey` (with walk invariant ⇒ equality). On miss, writes **end** into `*pOutNode`.

**Read-only** — no insert/erase/allocation. Payload for callers starts at **`node+0x10`** (skill template blob; `0x18c` dwords = `0x630` bytes when materializing runtime).

Primary consumers: `CVOGReaction_ResolveSkillTargets` (`0x0054c570`), `FUN_0054a290` (skill def install), `Client_RecvSkillStatusEffect`, plus skill-tree helpers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00418890_FUN_00418890.md` |
| Annotated | `docs/reconstruction/raw/aa_00418890_FUN_00418890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00418890.cpp` (+ named alias cpp) |
| Function record | `docs/reconstruction/functions/aa_00418890_FUN_00418890.md` |
| Live Ghidra | `batch_decompile` / `analyze_function_complete` / `decompile_function` @ `0x00418890`, `0x00418c70` |
| Bytes | `read_memory` @ `0x00418890` — ends **`C2 08 00`** (`ret 8`); key compare `3B 48 0C` / `JL` miss |
| Parent dual | `reviews/A\|B_aa_0054c570_CVOGReaction_ResolveSkillTargets.md` — `MOV ECX,0xb04734` before call |
| Callers | 6 named: `CVOGReaction_ResolveSkillTargets`, `Client_RecvSkillStatusEffect`, `FUN_0054a290`, `FUN_0054a260`, `FUN_00542790`, `FUN_005408f0` |

---

## 3. Signature (sealed)

```c
// void __thiscall SkillDefMap_ExactFindByIntKey(MapHeader *this, Node **pOut, int *pKey)
// ret 8  — two stack formals; this in ECX
// *pOut = hit node, or end = *(this+4)  (global end often DAT_00b04738)
```

| Slot | Role |
|---|---|
| ECX | map header (`DAT_00b04734` in materialize path) |
| Stack[0x4] | `Node **` out-iterator |
| Stack[0x8] | `int *` skill-id key |

Decompiler may print `void` return; body only writes `*pOut` (EAX not product return).

---

## 4. Control flow (sealed)

```
cand = FUN_00418c70(this, pKey)   // lower-bound walk; nil @ node+0x641
end  = *(this + 4)                // _Myhead / end sentinel
if (cand != end && cand->key <= *pKey):   // key @ +0x0C
    *pOut = cand                  // exact hit
else:
    *pOut = end                   // miss
```

### Layout family (distinct)

| Helper | Nil | Key | Op |
|---|---|---|---|
| `Map_LowerBoundFindByIntKey` `0x0050f940` | `+0x15` | int `node[3]` | lower_bound+≤ |
| `StdMap_LowerBoundByIntKey` `0x004054f0` | `+0x1d` | int | lower_bound+≤ |
| `Map_ExactFindByIntKey` `0x0051c150` | `+0x29` | int `+0x10` | exact |
| **`SkillDefMap_ExactFindByIntKey` `0x00418890`** | **`+0x641`** | **int `+0x0C`** | **exact via 00418c70** |

Do **not** reuse smaller-node int-map helpers on this tree — nil offset **`0x641`** is skill-def node scale (~0x640+ header).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `ret 8` / two stack args + thiscall | **Confirmed** | bytes `C2 08 00` |
| End = `*(this+4)` | **Confirmed** | body both arms |
| Exact find (not open lower_bound API) | **Confirmed** | ≤ gate after walk |
| Int key at `node+0x0C` | **Confirmed** | `cmp` / decompile |
| Nil at `node+0x641` (via `00418c70`) | **Confirmed** | callee bytes `80 B9 41 06 00 00 00` |
| Read-only find | **Confirmed** | no alloc/link writes |
| Map this often `DAT_00b04734` | **High** | parent asm + `FUN_0054b480` returns `&DAT_00b04734` |
| End sentinel often `DAT_00b04738` | **High** | parent compare + init clear |
| Product STL / RTTI name | **Open** | structural name kept |
| Full node schema beyond key/links/nil | **Open** | value at `+0x10` sealed only as copy source |

---

## 6. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Call `00418c70` with key | **Yes** |
| Compare cand to end `this+4` | **Yes** |
| Exact ≤ gate on `+0x0C` | **Yes** |
| Write hit or end to `*pOut` | **Yes** |
| No invent insert/mutate | **Yes** |
| Clean still scaffold names (`FUN_*`) | **Yes** CF; rename is dual-only |

---

## 7. Gaps

1. Product name / RTTI for map type.
2. Full skill-def node layout (beyond key/`+0x10` payload/`+0x641` nil).
3. Whether any caller uses non-`DAT_00b04734` map headers with same nil layout.
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
