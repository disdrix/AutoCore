# Review A (reconstruction fidelity): `aa_00421b50` StdTree_Max_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421b50` |
| **VA** | `0x00421b50`–`0x00421b6c` exclusive (**28 B**) |
| **Canonical name** | `StdTree_Max_Isnil29_Inferred` |
| **Ghidra name** | `FUN_00421b50` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00421b50_StdTree_Max_Isnil29_Inferred.md` |
| **System** | MSVC std `_Tree` / map erase helpers |
| **Agent** | WQ9D-G OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/return/isnil sealed from bytes; product demangle open |

---

## 1. Purpose

**Rightmost non-nil node** of a red-black tree subtree (MSVC `_Tree_max`) for the **isnil@+0x29** node family. Used by map erase clones to recompute `head->right` when the erased node was rightmost.

```c
// __cdecl; EAX = node*
int32_t *StdTree_Max_Isnil29_Inferred(int32_t *node);
```

Not insert, not find, not Val12 (`StdTree_Max_Val12` isnil@`+0x19`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00421b50_FUN_00421b50.md` |
| Annotated | `docs/reconstruction/raw/aa_00421b50_FUN_00421b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil29_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00421b50.cpp` |
| Live Ghidra | `batch_decompile` / `analyze_function_complete` / `read_memory` / callers / xrefs |
| Peer | `StdTree_Max_Val12` (`0x00418bf0`) |
| Twin min | `FUN_0051b5d0` (OWN WQ9D-B) |
| Erase consumer | `FUN_00409220` @ `0x0040930e` — `*(head+8) = Max(repl)` |

**Live re-decompile + body bytes performed.** No `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00421b50`–`0x00421b6c` excl. | **Confirmed** | function bounds + `C3` + `CC` |
| cdecl + plain RET | **Confirmed** | `8B 44 24 04` load; `C3` |
| EAX = rightmost / start | **Confirmed** | leave EAX; call-site `mov [head+8],eax` |
| Walk right `@+8` while non-nil | **Confirmed** | loop `mov eax,ecx; mov ecx,[eax+8]` |
| isnil `@+0x29` | **Confirmed** | `80 79 29 00` |
| Empty-right → return start | **Confirmed** | early `jne` to `ret` with EAX=start |
| Leaf | **Confirmed** | no callees |
| 5 callers / 5 xrefs | **Confirmed** | all erase rightmost recompute |
| Decompiler void | **Rejected** | defect |
| Product C++ name | **Inferred** | `_Inferred` |

---

## 4. Control flow (bytes)

```
right = node->right
if right.isnil: return node
loop:
  node = right
  right = node->right
  if !right.isnil: continue
return node
```

### Erase integration (`FUN_00409220` pattern)

```
if head->rightmost == erased:
  if !repl.isnil: head->rightmost = StdTree_Max_Isnil29(repl)
  else: head->rightmost = parent
```

Symmetric leftmost uses `FUN_0051b5d0` on `*head`.

---

## 5. Gaps (acceptable)

1. Product English / MSVC demangle for map value_type of this node size.  
2. Dual of twin min `FUN_0051b5d0` is separate OWN (WQ9D-B).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF (display) | **Pass** |
| Bytes seal return over decompiler void | **Pass** |
| isnil offset sealed | **Pass** |
| Erase rightmost role sealed | **Pass** |
| Clean meaningful names | **Pass** |
| Verdict | **accept-with-gaps** |
