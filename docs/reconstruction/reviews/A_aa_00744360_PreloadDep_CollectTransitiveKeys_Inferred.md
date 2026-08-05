# Review A (reconstruction fidelity): `aa_00744360` PreloadDep_CollectTransitiveKeys_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00744360` |
| **VA** | `0x00744360`–`0x0074445c` inclusive (**253 B**) |
| **Canonical name** | `PreloadDep_CollectTransitiveKeys_Inferred` |
| **Ghidra name** | `FUN_00744360` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-L) |
| **Counterpart** | `reviews/B_aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md` |
| **System** | preload / asset dependency graph |
| **Evidence pass** | Live Ghidra `batch_decompile` + `get_function_by_address` + `read_memory` (body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Given a dependency-tree host (ECX) and a key, walk the tree equal-range at `host+0x10` and push each not-yet-present node key into an out `GuardedVector` ring — **recursing first**, then `GuardedVector_PushFront_Thiscall` — yielding a transitive dependency key set.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-L append) | `docs/reconstruction/raw/aa_00744360_FUN_00744360.md` |
| Annotated | `docs/reconstruction/raw/aa_00744360_FUN_00744360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PreloadDep_CollectTransitiveKeys_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00744360.cpp` |
| Function record | `docs/reconstruction/functions/aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md` |
| Consumers | `FillPreloadList` (W32-L); AssPreloader `IsKeyTrackedRecursive` (W31-K) |
| Nested dual | `GuardedVector_PushFront_Thiscall` `0x0043e3d0` (W31-I) |
| Live | decompile ≡ raw CF; bytes seal ABI RET 8 + ECX host |

---

## 3. Signature (sealed)

```c
// ECX = dep-tree host; stack (key*, ring*); RET 8; void
void __fastcall PreloadDep_CollectTransitiveKeys_Inferred(
    void* host, const int* key, GuardedVectorHeader* ring);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`8B F1`) | **High** |
| key | stack arg0; used as key-view / node+0x18 | **High** |
| ring | stack arg1; membership + PushFront this | **High** |
| cleanup | `ADD ESP,18; C2 08 00` | **High** |

---

## 4. Control flow (bytes authority)

```
sub esp,18; push ebx/esi; mov esi, ecx
FUN_00426f60(key-view)
FUN_0044d960(host+0x10) → [it, end)
if it==end: ret 8
loop:
  node_key = it+0x18
  scan ring back-to-front for *node_key (page wrap)
  if found: goto advance
  push ring; push node_key; mov ecx, host; call self
  push node_key; mov ecx, ring; call PushFront_Thiscall
advance:
  map/set successor via nil@+0x25, L/R/P links
  if it!=end: loop
ret 8
```

| Stage | Match | Conf |
|---|---|---|
| RET 8 | `C2 08 00` | **High** |
| equal_range helpers | calls `00426f60` / `0044d960` | **High** |
| Ring layout + scan | decompile ≡ GuardedVector family | **High** |
| Recurse then push_front | call order bytes | **High** |
| Multi callers (Fill + AssPreloader) | xrefs | **High** |

---

## 5. Gaps

1. Product/PDB host class and dependency-edge English.  
2. Nested dual for `FUN_00426f60` / `FUN_0044d960`.  
3. Runtime / bit-exact / cycles beyond membership skip.

**Verdict:** **accept-with-gaps** — CF/ABI/ring/tree walk **sealed**.
