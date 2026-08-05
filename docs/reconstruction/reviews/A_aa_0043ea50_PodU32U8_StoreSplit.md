# Review A (reconstruction fidelity): `aa_0043ea50` PodU32U8_StoreSplit

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ea50` |
| **VA** | `0x0043ea50`–`0x0043ea5f` (**16 B**) |
| **Canonical name** | `PodU32U8_StoreSplit` (**Inferred**) |
| **Ghidra name** | `FUN_0043ea50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-M) |
| **Counterpart** | `reviews/B_aa_0043ea50_PodU32U8_StoreSplit.md` |
| **System** | POD store helper (split-source u32+u8) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (20 B) + `get_function_by_address` + `analyze_function_complete`; 1 caller / 1 xref; leaf; adapter `0043e8f0` bytes |
| **Verdict** | **accept** |

---

## 1. Purpose

Write `*pU32` and `*pU8` into `dest` at offsets +0 / +4 with **no** null check. Split-source ABI used by thin adapter `FUN_0043e8f0` (stack-laid values → pointers; ESI=dest).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ea50_FUN_0043ea50.md` (+ 2026-07-29 W32-M append) |
| Annotated | `docs/reconstruction/raw/aa_0043ea50_FUN_0043ea50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodU32U8_StoreSplit.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ea50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ea50_FUN_0043ea50.md` |
| Named record | `docs/reconstruction/functions/aa_0043ea50_PodU32U8_StoreSplit.md` |
| Live | decompile CF; full body hex; RET 4; leaf; caller adapter hex |

---

## 3. Signature (sealed)

```c
// EAX=dest; ECX=const uint32_t* pU32; stack=const uint8_t* pU8; RET 0x4
void PodU32U8_StoreSplit(void* dest /*EAX*/,
                         const uint32_t* pU32 /*ECX*/,
                         const uint8_t* pU8 /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| dest | **EAX** (stores `[EAX]` / `[EAX+4]`) | **High** |
| pU32 | **ECX** (first load `[ECX]`) | **High** |
| pU8 | Stack `[ESP+4]` | **High** |
| cleanup | `RET 0x4` (`C2 04 00`) | **High** |
| return | void | **High** |

Decompiler `__thiscall` is **partial** (ECX formal only). **Bytes win** for EAX dest + stack pU8.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
*(u32*)dest = *pU32
*((u8*)dest + 4) = *pU8
return   // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| No null gate | **Yes** | **High** |
| Split pointers (not contiguous POD*) | **Yes** | **High** |
| 5-byte write width | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
8B 11 8B 4C 24 04 89 10 8A 11 88 50 04 C2 04 00
```

Body length **16 B**. Immediate next function: `FUN_0043ea60` (GrowBlockMap_Stride2). Full hex: raw W32-M append.

Adapter `FUN_0043e8f0` (context only):

```
8D 44 24 08 50 8D 4C 24 08 8B C6 E8 50 01 00 00 8B C6 C3
; LEA/PUSH &stack+8; LEA ECX,&stack+4; MOV EAX,ESI; CALL 0043ea50
```

---

## 6. Gaps

- Product/PDB English / field names for the u32+u8 pair.
- Parent adapter `0043e8f0` dual free.
- Runtime / bit-exact under resource-cache / ass-preloader parents.

---

## 7. Verdict

ABI, split sources, 5-byte write, and `RET 4` sealed from live decompile + full-body `read_memory` + sole-caller adapter → **accept**.
