# Review A (reconstruction fidelity): `aa_0043c7e0` GuardedVector_Resize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c7e0` |
| **VA** | `0x0043c7e0`–`0x0043c829` (**74 B**) |
| **Canonical name** | `GuardedVector_Resize` (**Inferred**) |
| **Ghidra name** | `FUN_0043c7e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-D) |
| **Counterpart** | `reviews/B_aa_0043c7e0_GuardedVector_Resize.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; caller `0043c660`; callees `0043cb00`/`0043c8c0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Resize ring container to absolute `new_size`:

1. Read `size` from `[EAX+0x10]`; seed stack fill dword `= 0`.
2. If `size < new_size` → grow: `ECX = new_size - size`, call `FUN_0043cb00(container, container, begin+size, &fill0)` with count in **ECX**.
3. Else if `new_size < size` → shrink: `GuardedVector_EraseRange([begin+new_size, begin+size))`.
4. Else no-op.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c7e0_FUN_0043c7e0.md` (+ 2026-07-29 W28-D append) |
| Annotated | `docs/reconstruction/raw/aa_0043c7e0_FUN_0043c7e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Resize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c7e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c7e0_FUN_0043c7e0.md` |
| Named record | `docs/reconstruction/functions/aa_0043c7e0_GuardedVector_Resize.md` |
| Live | decompile ≡ raw CF; `read_memory` 74 B; 1 caller; body end `0x0043c829` |
| Context | parent clear-before-swap `FUN_0043c660`; shrink callee sealed W27-C EraseRange |

---

## 3. Signature (sealed)

```c
// EAX=container; ECX=new_size; plain RET; SUB/ADD ESP,8
void GuardedVector_Resize(uint32_t new_size /*ECX*/,
                          GuardedVectorHeader* container /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** (`MOV ESI,[EAX+0x10]` size load) | **High** |
| new_size | **ECX** (`CMP ECX,ESI`) | **High** |
| fill seed | stack local `= 0` | **High** |
| cleanup | plain `RET` (no `RET N`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
size = [EAX+0x10]; fill0 = 0
if size < new_size:
  ECX = new_size - size
  CALL FUN_0043cb00 (stack: cont, cont, begin+size, &fill0)
  RET
if new_size < size:
  CALL FUN_0043c8c0 EraseRange [begin+new_size, begin+size)
RET
```

| Stage | Match | Conf |
|---|---|---|
| Grow/shrink/equal trichotomy | **Yes** | **High** |
| Grow fill seed 0 | **Yes** | **High** |
| Shrink uses EraseRange absolute ends | **Yes** | **High** |
| Nested `FUN_0043cb00` free | shape only | **Medium** |
| Decompiler grow-arg list | incomplete vs bytes | **bytes win** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
83 EC 08 56 8B 70 10 3B CE C7 44 24 04 00 00 00 00 76 1B …
```

Grow epilogue: `5F 5E 83 C4 08 C3`.  
Shrink epilogue: `5E 83 C4 08 C3`.  
Callee targets: grow → `0043cb00`, shrink → `0043c8c0`.  
Body length **74 B** (`0x0043c7e0`–`0x0043c829`).

Full hex:

```
83ec08568b70103bcec744240400000000761b8b500c578d7c24085703d652502bce50e8f80200005f5e83c408c373158b500c03f2565003d152508d4c241451e89b0000005e83c408c3
```

---

## 6. Gaps

- Nested grow/insert free inside unowned `FUN_0043cb00` (construct + `RingFillRange` + move helpers).
- Product/PDB class English (`GuardedVector_*` structural from parent dual family).
- Runtime / bit-exact / differential.
- Sole known caller only exercises `new_size=0` (clear); grow arm sealed from body but not live-call-site exercised.

---

## 7. Verdict

ABI, trichotomy CF, fill-0 grow seed, and shrink→EraseRange sealed from live decompile + bytes + sole caller. Nested grow residual → **accept-with-gaps**.
