# Review A (reconstruction fidelity): `aa_0043ece0` Pod8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ece0` |
| **VA** | `0x0043ece0`–`0x0043ecee` (**15 B**) |
| **Canonical name** | `Pod8_CopyIfNonNull` (**Inferred**) |
| **Ghidra name** | `FUN_0043ece0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-M) |
| **Counterpart** | `reviews/B_aa_0043ece0_Pod8_CopyIfNonNull.md` |
| **System** | POD store / GuardedVector stride-2 helpers |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (16 B) + `get_function_by_address` + `analyze_function_complete`; 1 caller / 1 xref; leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Null-safe copy of two consecutive dwords (8-byte POD) from `src` (ECX) to `dest` (EAX). Sole store helper for `GuardedVector_PushBack_Stride2_U32x2`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ece0_FUN_0043ece0.md` (+ 2026-07-29 W32-M append) |
| Annotated | `docs/reconstruction/raw/aa_0043ece0_FUN_0043ece0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Pod8_CopyIfNonNull.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ece0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ece0_FUN_0043ece0.md` |
| Named record | `docs/reconstruction/functions/aa_0043ece0_Pod8_CopyIfNonNull.md` |
| Live | decompile ≡ raw CF; full body hex; bare RET; leaf |

---

## 3. Signature (sealed)

```c
// EAX=dest (nullable); ECX=const PodU32x2* src; bare RET
void Pod8_CopyIfNonNull(PodU32x2* dest /*EAX*/, const PodU32x2* src /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| dest | **EAX** (`TEST EAX` / stores) | **High** |
| src | **ECX** (`[ECX]` / `[ECX+4]`) | **High** |
| cleanup | bare `RET` (`C3`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if dest == null: return
dest.a = src.a
dest.b = src.b
return
```

| Stage | Match | Conf |
|---|---|---|
| Null gate on dest | **Yes** | **High** |
| Two-dword copy only | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
85 C0 74 0A 8B 11 89 10 8B 49 04 89 48 04 C3
```

Body length **15 B**. Pad `CC` then `FUN_0043ecf0`. Full hex: raw W32-M append.

---

## 6. Gaps

- Product/PDB English.
- Runtime / bit-exact under parent push paths.
- Sibling `0043ecf0` owned elsewhere (W32-N).

---

## 7. Verdict

ABI, null gate, and 8-byte store sealed from live decompile + full-body `read_memory` + sole-caller site → **accept**.
