# Review A (reconstruction fidelity): `aa_0043ce90` GuardedVector_RingCopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ce90` |
| **VA** | `0x0043ce90`–`0x0043cebe` |
| **Canonical name** | `GuardedVector_RingCopyRange` |
| **Ghidra name** | `FUN_0043ce90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-B) |
| **Counterpart** | `reviews/B_aa_0043ce90_GuardedVector_RingCopyRange.md` |
| **System** | STL / guarded container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; parent dual W26-G |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Nested **ring-copy entry** for unlocked vector assign:

1. Reshape parent’s 6 stack args + `ESI` out-pair into `FUN_0043d390`’s expected layout.
2. Call `FUN_0043d390` (ring-aware element walk).
3. Return `ESI` in `EAX`; clean internal pushes (`ADD ESP,0x24`).

Exclusive parent: `GuardedVector_CopyAssign` — fit path (`0x0043c76e`) and grow path (`0x0043c7aa`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ce90_FUN_0043ce90.md` (+ 2026-07-29 W27-B append) |
| Annotated | `docs/reconstruction/raw/aa_0043ce90_FUN_0043ce90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingCopyRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ce90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ce90_FUN_0043ce90.md` |
| Named record | `docs/reconstruction/functions/aa_0043ce90_GuardedVector_RingCopyRange.md` |
| Live | decompile high-level ≡ raw; body 47 B; callee rel32 → `0x0043d390` |

---

## 3. Signature (sealed at this unit’s boundary)

```c
// Parent pushes 6 args; ESI = int outPair[2]
// Returns outPair in EAX; internal ADD ESP,0x24
void* GuardedVector_RingCopyRange(void);
```

| Item | Evidence | Conf |
|---|---|---|
| Sole callee `FUN_0043d390` | bytes `E8 D7 04 00 00` | **High** |
| EAX = ESI | `8B C6` | **High** |
| Clean 0x24 | `83 C4 24` | **High** |
| Parent ×2 exclusive | xrefs | **High** |
| Exact reshape formal order | body hex only | **Medium** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
reshape stack (push/reload)
push esi
call FUN_0043d390
mov eax, esi
add esp, 0x24
ret
```

| Stage | Match | Conf |
|---|---|---|
| Decompile single-call CF | **Yes** | **High** |
| Callee address | **Yes** | **High** |
| Return ESI | **Yes** | **High** |
| Role in fit+grow assign | **Yes** (parent dual) | **High** |
| Full `FUN_0043d390` arithmetic | **Not OWN** | gap |

---

## 5. Machine bytes (`read_memory`)

```
51 8B 04 24 8B 4C 24 1C 8B 54 24 18 50 8B 44 24
18 51 8B 4C 24 18 52 8B 54 24 18 50 8B 44 24 18
51 52 50 56 E8 D7 04 00 00 8B C6 83 C4 24 C3
```

Body exclusive end `0x0043cebe`.

---

## 6. Gaps

- Product/PDB English for GuardedVector / ring header.
- Full formal map of reshaped args into `FUN_0043d390` (unowned).
- Runtime wraparound bit-exact — open.
- Downstream fit (`FUN_0043c8c0`) / grow (`FUN_0043cec0`) residual (W27-C partition).

---

## 7. Verdict

Boundary CF/ABI, exclusive parent, sole callee sealed. Unowned callee formal detail → **accept-with-gaps**.
