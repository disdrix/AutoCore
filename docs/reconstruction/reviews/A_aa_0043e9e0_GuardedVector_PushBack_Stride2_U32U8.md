# Review A (reconstruction fidelity): `aa_0043e9e0` GuardedVector_PushBack_Stride2_U32U8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e9e0` |
| **VA** | `0x0043e9e0`–`0x0043ea4d` (**110 B**) |
| **Canonical name** | `GuardedVector_PushBack_Stride2_U32U8` (**Inferred**) |
| **Ghidra name** | `FUN_0043e9e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-J) |
| **Counterpart** | `reviews/B_aa_0043e9e0_GuardedVector_PushBack_Stride2_U32U8.md` |
| **System** | STL / guarded ring-deque (stride-2) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 110 B + store helper) + `get_function_by_address` + `analyze_function_complete`; 2 callers / 2 xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Ring-deque **push_back** of one **dword+byte** POD into 8-byte slots: same stride-2 grow/page/alloc as U32x2 sibling; store via `FUN_0043ecf0`; `size++` only.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e9e0_FUN_0043e9e0.md` (+ 2026-07-29 W31-J append) |
| Annotated | `docs/reconstruction/raw/aa_0043e9e0_FUN_0043e9e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBack_Stride2_U32U8.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e9e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e9e0_FUN_0043e9e0.md` |
| Named record | `docs/reconstruction/functions/aa_0043e9e0_GuardedVector_PushBack_Stride2_U32U8.md` |
| Live | decompile ≡ raw CF; full body hex; twin-delta only store CALL |

---

## 3. Signature (sealed)

```c
// EAX=container; stdcall 1 stack formal (value*); RET 0x4
void GuardedVector_PushBack_Stride2_U32U8(GuardedVectorHeader* container /*EAX*/,
                                          const PodU32U8* value /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| container | **EAX** | **High** |
| value* | Stack → ECX for store helper | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

Identical to `aa_0043e970` except final store:

```
… grow / page / new(0x10) / LEA *8 …
Pod5_CopyIfNonNull(slot, value)  // FUN_0043ecf0: u32 + u8
size++
```

| Stage | Match | Conf |
|---|---|---|
| Grow/page/alloc ≡ U32x2 twin | **Yes** (byte-diff only rel32) | **High** |
| 5-byte store helper | **Yes** | **High** |
| size++ only | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (110 B) in raw W31-J append. Store tail:

```
83 E6 01 8D 04 F0 E8 AC 02 00 00   ; AND ESI,1; LEA; CALL 0043ecf0
83 43 10 01 5F 5E 5B C2 04 00
```

Store helper `0043ecf0`:

```
85 C0 74 0A 8B 11 89 10 8A 49 04 88 48 04 C3
```

Next after pad: `FUN_0043ea50` (related non-null 5-byte store; not owned).

---

## 6. Gaps

- Product/PDB element struct English.
- Trailing 3 bytes of each 8-byte slot not written (padding residual).
- Runtime / bit-exact; nested free of CS wrapper `0043e7f0` / parent `0075de80`.

---

## 7. Verdict

ABI, polarity, stride-2 math, and dword+byte store sealed; bit-twin of U32x2 with single store-helper delta → **accept**.
