# Review A (reconstruction fidelity): `aa_0044e4f0` GuardedVector_AssignLinearRangeAt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e4f0` |
| **VA** | `0x0044e4f0`–`0x0044e553` (**100 B**) |
| **Canonical name** | `GuardedVector_AssignLinearRangeAt` (**Inferred**) |
| **Ghidra name** | `FUN_0044e4f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-L) |
| **Counterpart** | `reviews/B_aa_0044e4f0_GuardedVector_AssignLinearRangeAt.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 100 B) + xrefs/callers; sole parent InsertRange ×3; leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Assign linear dword range `[first, last)` into GuardedVector ring slots starting at absolute `dest_idx`:

1. For each source element: map `page = idx>>2`, wrap if `capacity <= page`, `sub = idx - page*4`.
2. If mapped slot ≠ source pointer: `*slot = *src`.
3. Advance `dest_idx`; publish out iterator `{container, end_idx}`.

Used by `GuardedVector_InsertRange` after shorter-side grow/move opens a gap (W32-G residual).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044e4f0_FUN_0044e4f0.md` (+ 2026-07-29 W33-L append) |
| Annotated | `docs/reconstruction/raw/aa_0044e4f0_FUN_0044e4f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignLinearRangeAt.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044e4f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044e4f0_FUN_0044e4f0.md` |
| Named record | `docs/reconstruction/functions/aa_0044e4f0_GuardedVector_AssignLinearRangeAt.md` |
| Live | decompile ≡ raw CF; full 100 B hex; plain RET; 0 callees |
| Context | parent W32-G InsertRange assign fallthrough |

---

## 3. Signature (sealed)

```c
// cdecl; plain RET; 5 live formals
// Call sites may push 6th residual (ADD ESP,0x18) — unread by body
void GuardedVector_AssignLinearRangeAt(
    GuardedVectorIteratorPair* out,
    const uint32_t* first,
    const uint32_t* last,
    GuardedVectorHeader* container,
    uint32_t dest_idx);
```

| Slot | Source | Conf |
|---|---|---|
| out* | Stack[+4] | **High** |
| first* | Stack[+8] (`ESI`) | **High** |
| last* | Stack[+0xc] (`EAX`) | **High** |
| container | Stack[+0x10] (`EBP`) | **High** |
| dest_idx | Stack[+0x14] (`EDI`) | **High** |
| cleanup | plain `RET` (`C3`) | **High** |
| 6th residual | caller-only | **High** (unread) |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if first == last: goto publish
loop:
  page = dest_idx >> 2
  sub  = dest_idx - page*4
  if capacity <= page: page -= capacity
  slot = pages[page] + sub
  if slot != first: *slot = *first
  first += 1; dest_idx += 1
  if first != last: loop
publish:
  out->index = dest_idx
  out->container = container
  RET
```

| Stage | Match | Conf |
|---|---|---|
| Linear walk first→last | **Yes** | **High** |
| Page map `>>2` + wrap | **Yes** | **High** |
| Self-assign skip | **Yes** | **High** |
| Out iterator publish | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| Empty range early | **Yes** (`JE` after cmp) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 100 B hex:

```
8b44240c558b6c2414568b7424103bf0578b7c2420744053eb068d9b000000008bcfc1e9028d148d000000008bda8bd72bd38b5d083bd977022bcb8b5d048b0c8b8d0c913bce74048b16891183c60483c7013bf075ca5b8b4424108978045f5e89285dc3
```

Key: `SHR ECX,2` page; `CMP [EBP+8],ECX` / wrap; `LEA ECX,[ECX+EDX*4]` slot; `CMP ECX,ESI` / skip store; epilogue `MOV [EAX+4],EDI; MOV [EAX],EBP; RET`.

---

## 6. Gaps (non-blocking)

- Product/PDB English.  
- Exact product role of 6th stack formal at InsertRange call sites.  
- Runtime / bit-exact under overlapping self-assign.

---

## 7. Verdict

Fidelity pass seals full leaf CF, page map, ABI, and InsertRange role. Product / 6th-arg residual only → **accept**.
