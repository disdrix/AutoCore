# Review A (reconstruction fidelity): `aa_00418c70` SkillDefMap_LowerBoundByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418c70` |
| **VA** | `0x00418c70`–`0x00418c9e` |
| **Canonical name** | `SkillDefMap_LowerBoundByIntKey` (INFERRED; Ghidra `FUN_00418c70`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (skill-def tree walk) |
| **Counterpart** | `reviews/B_aa_00418c70_SkillDefMap_LowerBoundByIntKey_Inferred.md` |
| **System** | `skills-abilities` |
| **Parent chain** | `ResolveSkillTargets` → ExactFind `00418890` → **this** |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **lower_bound** walk for the **skill-definition** map (nil **`node+0x641`**, int key **`node+0x0C`**).

Sole caller: `SkillDefMap_ExactFindByIntKey` (`0x00418890`), which then applies exact-match gate.

```
// __thiscall this=mapHeader; stack: int *pKey; ret 4
rootLike = *( *(this+4) + 4 )   // header→_Parent typically
if root is nil: return header-side node
// loop while candidate not nil:
//   if node.key < *pKey: go right ([+8]), keep previous
//   else: go left ([+0]), update candidate
return candidate  // lower_bound position
```

Bytes (`read_memory`):

```
8B 41 04             mov eax, [ecx+4]      ; _Myhead
8B 48 04             mov ecx, [eax+4]      ; root
80 B9 41 06 00 00 00 cmp byte [ecx+641h],0
75 1D                jnz done
8B 54 24 04          mov edx, [esp+4]
8B 12                mov edx, [edx]        ; *pKey
39 51 0C             cmp [ecx+0Ch], edx    ; node.key ? *pKey
7D 05                jge go_left           ; key >= *pKey → left
8B 49 08             mov ecx, [ecx+8]      ; right
EB 04
8B C1                mov eax, ecx          ; save cand
8B 09                mov ecx, [ecx]        ; left
... loop ...
C2 04 00             ret 4
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_00418c70_*` |
| Live Ghidra | `decompile_function`, `read_memory`, callers |
| Parent dual | `A_aa_00418890_SkillDefMap_ExactFindByIntKey` (documents this walk) |
| Layout family table | parent dual §4 |

---

## 3. Signature (sealed)

```c
SkillDefNode * __thiscall SkillDefMap_LowerBoundByIntKey(MapHeader *this, int *pKey);
// RET 4 — one stack formal; this in ECX
// Returns node* lower_bound candidate (not yet exact-checked)
```

| Offset | Role |
|---|---|
| map `this+4` | `_Myhead` / end sentinel holder |
| node `+0` | left |
| node `+8` | right |
| node `+0x0C` | int key (skill id) |
| node `+0x641` | nil flag |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller ExactFind | **Confirmed** | callers |
| Nil `+0x641`, key `+0x0C` | **Confirmed** | bytes |
| `ret 4` thiscall + pKey | **Confirmed** | `C2 04 00` |
| Lower_bound (not exact) | **Confirmed** | parent applies ≤ gate |
| Read-only | **Confirmed** | no writes |

---

## 5. Gaps

1. Product STL typedef / RTTI name.
2. Full node size beyond links/key/nil.

**Verdict:** **accept**
