# Review A (reconstruction fidelity): `aa_00421a60` StdTree_Max_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421a60` |
| **VA** | `0x00421a60`–`0x00421a7c` exclusive (**28 B**) |
| **Canonical name** | `StdTree_Max_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00421a60` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00421a60_StdTree_Max_Isnil21_Inferred.md` |
| **System** | MSVC std `_Tree` / map erase helpers (partition skills-abilities) |
| **Agent** | R13-001 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/return/isnil sealed from bytes; product demangle open |

---

## 1. Purpose

**Rightmost non-nil node** of a red-black tree subtree (MSVC `_Tree_max`) for the **isnil@+0x21** node family. Used by map erase clones to recompute `head->right` when the erased node was rightmost.

```c
// __cdecl; EAX = node*
int32_t *StdTree_Max_Isnil21_Inferred(int32_t *node);
```

Not insert, not find, not min/leftmost, not Val12 (`StdTree_Max_Val12` isnil@`+0x19`), not isnil29 Max (`0x00421b50`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00421a60_FUN_00421a60.md` |
| Annotated | `docs/reconstruction/raw/aa_00421a60_FUN_00421a60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil21_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00421a60.cpp` |
| Live Ghidra | `decompile_function` / `analyze_function_complete` / `disassemble_function` / `read_memory` / callers / xrefs / `get_assembly_context` |
| Peer | `StdTree_Max_Isnil29_Inferred` (`0x00421b50`); `StdTree_Max_Val12` (`0x00418bf0`); `StdTree_Max_Isnil31` (`0x004043e0`) |
| Twin min | `FUN_004cb2c0` (residual R13-002) |
| Erase consumer | `FUN_00405650` @ `0x0040573e` — `*(head+8) = Max(repl)` after `ADD ESP,4` |

**Live re-decompile + body bytes performed.** No `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00421a60`–`0x00421a7c` excl. | **Confirmed** | function bounds + `C3` + `CC` |
| cdecl + plain RET | **Confirmed** | `8B 44 24 04` load; `C3`; call-site `ADD ESP,4` |
| EAX = rightmost / start | **Confirmed** | leave EAX; call-site `mov [head+8],eax` |
| Walk right `@+8` while non-nil | **Confirmed** | loop `mov eax,ecx; mov ecx,[eax+8]` |
| isnil `@+0x21` | **Confirmed** | `80 79 21 00` |
| Empty-right → return start | **Confirmed** | early `jne` to `ret` with EAX=start |
| Leaf | **Confirmed** | no callees |
| 7 callers / 7 xrefs | **Confirmed** | all isnil21 erase rightmost recompute |
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

### Disassembly (Ghidra `disassemble_function`)

```
00421a60: MOV EAX, [ESP+4]
00421a64: MOV ECX, [EAX+8]
00421a67: CMP byte ptr [ECX+0x21], 0
00421a6b: JNZ 0x00421a7b
00421a6d: LEA ECX, [ECX]
00421a70: MOV EAX, ECX
00421a72: MOV ECX, [EAX+8]
00421a75: CMP byte ptr [ECX+0x21], 0
00421a79: JZ  0x00421a70
00421a7b: RET
```

### Erase integration (`FUN_00405650` pattern @ `0x0040573e`)

```
if head->rightmost == erased:
  if !repl.isnil: head->rightmost = StdTree_Max_Isnil21(repl)
  else: head->rightmost = parent
```

Symmetric leftmost uses residual `FUN_004cb2c0` on `*head`.

---

## 5. Gaps (acceptable)

1. Product English / MSVC demangle for map value_type of this node size.  
2. Dual of twin min `FUN_004cb2c0` is separate OWN (R13-002).  
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
