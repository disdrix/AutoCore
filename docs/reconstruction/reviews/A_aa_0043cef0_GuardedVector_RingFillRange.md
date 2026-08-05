# Review A (reconstruction fidelity): `aa_0043cef0` GuardedVector_RingFillRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cef0` |
| **VA** | `0x0043cef0`–`0x0043cf38` (**73 B**) |
| **Canonical name** | `GuardedVector_RingFillRange` (**Inferred**) |
| **Ghidra name** | `FUN_0043cef0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-D) |
| **Counterpart** | `reviews/B_aa_0043cef0_GuardedVector_RingFillRange.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; caller `0043cb00` ×3; leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf fill of half-open absolute ring index range:

1. While `(container_from, idx_from) != (container_to, idx_to)`.
2. Map `idx → (page, sub)` with `page = idx>>2`, `sub = idx % 4`.
3. Wrap page by subtracting `[container+0x08]` when `page >= capacity`.
4. Store `*EBX` into `slots[page][sub]`.
5. `idx_from++`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.md` (+ 2026-07-29 W28-D append) |
| Annotated | `docs/reconstruction/raw/aa_0043cef0_FUN_0043cef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingFillRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cef0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043cef0_FUN_0043cef0.md` |
| Named record | `docs/reconstruction/functions/aa_0043cef0_GuardedVector_RingFillRange.md` |
| Live | decompile ≡ raw; `read_memory` 73 B; leaf; body end `0x0043cf38` before `FUN_0043cf40` |
| Context | parent grow/insert `FUN_0043cb00`; same map layout as RingCopyRange / EraseRange family |

---

## 3. Signature (sealed)

```c
// EBX=&fill_dword; 4 stack args; plain RET (caller cleans 0x10)
void GuardedVector_RingFillRange(
    GuardedVectorHeader* container_from, uint32_t idx_from,
    GuardedVectorHeader* container_to,   uint32_t idx_to,
    const uint32_t* fill /*EBX*/);
```

| Slot | Source | Conf |
|---|---|---|
| container_from | Stack[+4] | **High** |
| idx_from | Stack[+8] | **High** |
| container_to | Stack[+0xc] | **High** |
| idx_to | Stack[+0x10] | **High** |
| fill | **EBX** (`MOV ESI,[EBX]`) | **High** |
| cleanup | plain `RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
loop:
  if container_from==container_to && idx_from==idx_to: break
  page = idx>>2; sub = idx - page*4
  if page >= [c+8]: page -= [c+8]
  page_ptr = ([c+4])[page]
  [page_ptr + sub*4] = *EBX
  idx++
  jmp loop
RET
```

| Stage | Match | Conf |
|---|---|---|
| Half-open dual-iterator exit | **Yes** | **High** |
| page wrap via capacity | **Yes** | **High** |
| 4-dword page subslot | **Yes** | **High** |
| Leaf (0 callees) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
8B 54 24 08 55 8B 6C 24 14 56 57 8B 7C 24 10 90 …
```

Store: `8B 33 89 34 88` (`*EBX` → `[page_ptr+sub*4]`).  
Epilogue: `5F 5E 5D C3`.  
Body length **73 B** (`0x0043cef0`–`0x0043cf38`).

Full hex:

```
8b542408558b6c241456578b7c2410903b7c241875043bd5742b8bc2c1e8028d0c85000000008bf18bca2bce8b77083bf077022bc68b77048b04868b3389348883c201ebcb5f5e5dc3
```

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural).
- Runtime golden under full insert parent (unowned `FUN_0043cb00`).

---

## 7. Verdict

Full leaf body, ABI (stack+EBX), and page-map fill math sealed from live decompile + bytes + exclusive parent. Naming residual only → **accept**.
