# Review A (reconstruction fidelity): `aa_005b2ba0` GuardedVector_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2ba0` |
| **VA** | `0x005b2ba0`–`0x005b2c05` (**102 B** / `0x66`) |
| **Canonical name** | `GuardedVector_Dtor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_005b2ba0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-D) |
| **Counterpart** | `reviews/B_aa_005b2ba0_GuardedVector_Dtor_Inferred.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 102 B) + `analyze_function_complete` (callers/callees/xrefs); **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Storage destructor for GuardedVector: drain element count, free all page blocks and the page map, zero map/capacity. Header object itself is not freed.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.md` (+ W37-D append) |
| Annotated | `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b2ba0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b2ba0_FUN_005b2ba0.md` |
| Named record | `docs/reconstruction/functions/aa_005b2ba0_GuardedVector_Dtor_Inferred.md` |
| Live | decompile ≡ scaffold CF; full body hex; both `operator_delete` → `0x00489822` |

---

## 3. Signature (sealed)

```c
// ECX=container; 0 stack formals; plain RET; void
void GuardedVector_Dtor_Inferred(GuardedVectorHeader* container /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ECX** (`MOV ESI,ECX` then `[ESI+…]`) | **High** |
| stack formals | none | **High** |
| cleanup | plain `RET` (`C3`) | **High** |
| return | void (no intentional EAX out) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
// size drain
while size != 0:
  size--
  if size == 0: begin = 0

// free pages[capacity-1 .. 0]
for i = capacity; i > 0; --i:
  p = pages[i-1]
  if p: operator_delete(p)

// free map + always zero
if pages: operator_delete(pages)
capacity = 0
pages = 0
```

| Stage | Match | Conf |
|---|---|---|
| size drain + begin=0 on empty | **Yes** | **High** |
| page free walk by capacity | **Yes** | **High** |
| map free if non-null | **Yes** | **High** |
| always capacity=pages=0 after | **Yes (bytes)** | **High** |
| No per-element dtor | **Yes** | **High** |
| No CS | **Yes** | **High** |

**Decompile caveat:** Ghidra marks `operator_delete` as non-returning and **omits** the trailing `capacity=0; pages=0` on the non-null map path. Bytes always fall through both stores after the optional map free (`89 5E 08  89 5E 04`). Clean/annotated correct this.

---

## 5. Machine bytes (`read_memory`)

Full body (102 B):

```
53 56 8B F1 33 DB 39 5E 10 74 1E EB 03 8D 49 00
8B 46 10 3B C3 74 0D 83 C0 FF 3B C3 89 46 10 75
03 89 5E 0C 39 5E 10 75 E7 57 8B 7E 08 3B FB 76
1B 8B 46 04 8B 44 B8 FC 83 EF 01 3B C3 74 09 50
E8 3D 6C ED FF 83 C4 04 3B FB 77 E5 8B 46 04 3B
C3 5F 74 09 50 E8 28 6C ED FF 83 C4 04 89 5E 08
89 5E 04 5E 5B C3
```

Key decode:

| Bytes | Meaning |
|-------|---------|
| `8B F1` | ESI = ECX (this) |
| `33 DB` | EBX = 0 |
| `[ESI+0x10]` loop | drain size; `89 5E 0C` begin=0 when hits 0 |
| `[ESI+0x08]` / `[ESI+0x04+EDI*4-4]` | capacity walk + page load |
| `E8 …` ×2 | `operator_delete` @ `0x00489822` |
| `89 5E 08  89 5E 04` | capacity=0; pages=0 (always) |
| `C3` | RET |

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural only).
- Callers with non-POD element ownership must destroy elements separately (not this body's job).
- Thunk/copy at `0x0043d640` not owned.
- Runtime / bit-exact / differential — open.
- Terminal coverage: **false** (agent report; no parent ledger).

---

## 7. Verdict

CF/ABI/storage-free contract sealed by decompile + full hex; decompiler post-delete store miss corrected from bytes → **accept-with-gaps** (naming + runtime residual).
