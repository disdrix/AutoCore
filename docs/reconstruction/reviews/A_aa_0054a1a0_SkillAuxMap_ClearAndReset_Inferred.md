# Review A (reconstruction fidelity): `aa_0054a1a0` SkillAuxMap_ClearAndReset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054a1a0` |
| **VA** | `0x0054a1a0`–`0x0054a25b` |
| **Canonical name** | `SkillAuxMap_ClearAndReset` (INFERRED; Ghidra `FUN_0054a1a0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (skill-def bootstrap nested) |
| **Counterpart** | `reviews/B_aa_0054a1a0_SkillAuxMap_ClearAndReset_Inferred.md` |
| **System** | `skills-abilities` |
| **Parent chain** | `CVOGReaction_ResolveSkillTargets` → `SkillDefMap_EnsureInitialized` `0x0054b2c0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clear / reset the **secondary skill-related ordered map** rooted at global **`DAT_00b04744`** (size/count **`DAT_00b04748`**).

Sole live caller: `SkillDefMap_EnsureInitialized` (`0x0054b2c0`) — runs as early sub-init before factory register (`FUN_0054a640`) and skill-blob install (`FUN_0054a290`).

Node family is the **small-nil** map layout (**nil flag `node+0x15`**), **not** the skill-def tree with nil at `+0x641`. Payload pointer at **`node[4]`** is `operator_delete`'d when non-null during the walk. After walk, head is re-linked to self and count zeroed.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054a1a0_FUN_0054a1a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0054a1a0_FUN_0054a1a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0054a1a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054a1a0_FUN_0054a1a0.md` |
| Live Ghidra | `decompile_function` / `get_function_by_address` / `get_function_callers` @ `0x0054a1a0` |
| Parent dual | `reviews/A_aa_0054b2c0_SkillDefMap_EnsureInitialized.md` |
| Sibling tree free | `FUN_0054d7c0` (subtree free of root child) |

---

## 3. Signature (sealed)

```c
void SkillAuxMap_ClearAndReset(void);  // no args; plain ret
```

| Global | Role |
|---|---|
| `DAT_00b04744` | map head / sentinel node pointer |
| `DAT_00b04748` | element count (set **0** on reset) |

---

## 4. Control flow (sealed structure)

```
it = *DAT_00b04744
while it != DAT_00b04744:
    if it[4] != null: operator_delete(it[4])   // payload free
    advance MSVC inorder successor (nil @ +0x15; left/right/parent links)
// free remaining non-nil root child via FUN_0054d7c0 + delete
DAT_00b04744[1] = DAT_00b04744
DAT_00b04748 = 0
*DAT_00b04744 = DAT_00b04744
DAT_00b04744[2] = DAT_00b04744
return
```

**Layout contrast:** nil `+0x15` (this unit) vs skill-def map nil `+0x641` (`00418c70` / `0054d780`). Do not merge the two map families.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Called only from EnsureInitialized | **Confirmed** | callers list size 1 |
| Clears map at `DAT_00b04744`, zeros `DAT_00b04748` | **Confirmed** | body tail stores |
| Nil flag at `node+0x15` | **Confirmed** | decompile compares |
| Payload free at `node[4]` | **Confirmed** | delete before advance |
| Product name of map / payload type | **Open** | structural |
| Decompiler “does not return” on `operator_delete` | **Noise** | CRT returns; SEH annotation |

---

## 6. Gaps

1. Product identity of the `DAT_00b04744` map (cooldown categories? rank tables? string→id?).
2. Whether node bodies themselves are freed in a path the decompiler collapsed (payload-only free is sealed; full node free via `0054d7c0` path sealed for root child).
3. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
