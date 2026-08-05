# Review A (reconstruction fidelity): `aa_0054d780` SkillDefTree_DestroySubtree

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054d780` |
| **VA** | `0x0054d780`–`0x0054d7ba` |
| **Canonical name** | `SkillDefTree_DestroySubtree` (INFERRED; Ghidra `FUN_0054d780`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (skill-def tree teardown) |
| **Counterpart** | `reviews/B_aa_0054d780_SkillDefTree_DestroySubtree_Inferred.md` |
| **System** | `skills-abilities` |
| **Parent chain** | `ResolveSkillTargets` → `SkillDefMap_EnsureInitialized` (+ self, `FUN_0054ec60`) |
| **Verdict** | **accept** (bytes seal CF; decompiler incomplete) |

---

## 1. Purpose

Destroy a **skill-def ordered-map subtree** whose nodes use nil flag **`node+0x641`** (same family as `SkillDefMap_LowerBoundByIntKey` / ExactFind).

**Machine CF (prefer bytes over decompiler):**

```
// ret 4 — one stack arg (node*)
// space-efficient tree free:
while node is not nil (+0x641 == 0 means live? wait: cmp [node+0x641],0; jnz done):
    // jnz skip when is_nil != 0 → nil sentinel stops
    recursive DestroySubtree(node.right)   // [node+8]
    left = node.left                       // [node+0]
    operator_delete(node)
    node = left
```

Bytes @ `0x0054d780` (`read_memory` 64 B):

```
53 56 57                push ebx,esi,edi
8B 7C 24 10            mov edi, [esp+10h]   ; node
80 BF 41 06 00 00 00   cmp byte ptr [edi+641h], 0
8B D9                  mov ebx, ecx
8B F7                  mov esi, edi
75 21                  jnz epilogue          ; nil → done
8B 46 08               mov eax, [esi+8]      ; right
50                     push eax
8B CB                  mov ecx, ebx
E8 E1 FF FF FF         call self             ; free right spine recursively
8B 36                  mov esi, [esi]        ; left
57                     push edi
E8 ..                  call operator_delete
83 C4 04
80 BE 41 06 00 00 00   cmp byte ptr [esi+641h], 0
8B FE                  mov edi, esi
74 DF                  jz loop               ; continue on live left
5F 5E 5B C2 04 00      pop*; ret 4
```

Decompiler only showed recursive right + delete — **missed left-iterative loop**. Dual seals **bytes**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_0054d780_*` (decompiler incomplete) |
| Live Ghidra | `decompile_function`, `read_memory` @ `0x0054d780`, callers |
| Sibling layout | `00418c70` nil `+0x641`, key `+0x0C`, links left/right |
| Parent | EnsureInitialized mode teardown paths |

---

## 3. Signature (sealed)

```c
// stdcall / thiscall-with-unused-ECX: cleans 4 bytes
void __stdcall SkillDefTree_DestroySubtree(SkillDefNode *node);
// ECX preserved across recursion (mov ebx,ecx / mov ecx,ebx) but not used as object fields
// RET 4
```

| Offset | Role |
|---|---|
| `+0` | left child |
| `+8` | right child |
| `+0x641` | nil / sentinel flag (nonzero = stop) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `ret 4` one stack node* | **Confirmed** | bytes `C2 04 00` |
| Nil at `+0x641` | **Confirmed** | `80 BF 41 06 00 00 00` |
| Right recursive + left iterative free | **Confirmed** | bytes loop |
| Decompiler incomplete vs retail | **Confirmed** | B must cite bytes |
| Same node family as ExactFind tree | **High** | shared nil offset |
| Does not free payload-at-+0x10 separately | **High** | only `operator_delete(node)` |

---

## 5. Gaps

1. Whether node `operator_delete` size matches full skill-def node alloc.
2. Call-site which root is passed from EnsureInitialized (mode-1 path).
3. Product STL typedef name.

**Verdict:** **accept**
