# Review A (reconstruction fidelity): `aa_0043d420` GuardedVector_AssignDwordIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d420` |
| **VA** | `0x0043d420`–`0x0043d430` (**17 B**) |
| **Canonical name** | `GuardedVector_AssignDwordIfNonNull` (**Inferred**) |
| **Ghidra name** | `FUN_0043d420` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-F) |
| **Counterpart** | `reviews/B_aa_0043d420_GuardedVector_AssignDwordIfNonNull.md` |
| **System** | STL / guarded ring-deque element store |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 17 B) + callers/callees; 2 callers (push pair); no callees |
| **Verdict** | **accept** |

---

## 1. Purpose

Null-checked POD dword assign: if `dst != 0` then `*dst = *src`. Element-store leaf for thiscall GuardedVector push_back / push_front.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043d420_FUN_0043d420.md` (+ 2026-07-29 W32-F append) |
| Annotated | `docs/reconstruction/raw/aa_0043d420_FUN_0043d420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignDwordIfNonNull.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d420.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043d420_FUN_0043d420.md` |
| Named record | `docs/reconstruction/functions/aa_0043d420_GuardedVector_AssignDwordIfNonNull.md` |
| Live | decompile ≡ raw CF; full 17 B hex; plain RET; 2 callers |

---

## 3. Signature (sealed)

```c
// stack dst*, src*; plain RET (cdecl)
void GuardedVector_AssignDwordIfNonNull(uint32_t* dst, const uint32_t* src);
```

| Slot | Source | Conf |
|---|---|---|
| dst* | Stack[+4] (`MOV EAX,[ESP+4]`) | **High** |
| src* | Stack[+8] (`MOV ECX,[ESP+8]`) | **High** |
| cleanup | plain `RET` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if dst == 0: return
*dst = *src
return
```

| Stage | Match | Conf |
|---|---|---|
| Null dst gate | **Yes** | **High** |
| Single dword load/store | **Yes** | **High** |
| No callees / no this | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
8B 44 24 04 85 C0 74 08 8B 4C 24 08 8B 11 89 10 C3
```

Body **17 B**; pad `CC` after. Live decompile 2026-07-29 ≡ raw 2026-07-23.

---

## 6. Gaps (non-blocking)

- Product/PDB English.  
- Runtime / bit-exact.  
- Null-check rationale after lazy page alloc (defensive residual).

---

## 7. Verdict

Fidelity pass seals ABI, CF, and role as push assign leaf. Product residual only → **accept**.
