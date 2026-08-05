# Review A (reconstruction fidelity): `aa_0043e8f0` PodU32U8_StoreByValue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e8f0` |
| **VA** | `0x0043e8f0`–`0x0043e902` (**19 B**) |
| **Canonical name** | `PodU32U8_StoreByValue` (**Inferred**) |
| **Ghidra name** | `FUN_0043e8f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-M) |
| **Counterpart** | `reviews/B_aa_0043e8f0_PodU32U8_StoreByValue.md` |
| **System** | POD store adapter (by-value → split store) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (20 B) + `get_function_by_address` + `analyze_function_complete` + `disassemble_function` listing; 9 xrefs / 6 callers; nested W32-M StoreSplit |
| **Verdict** | **accept** |

**Tools:** decompile + `read_memory` + function helpers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Adapter that stores a by-value `(u32, u8)` pair into `dest` by taking addresses of the stack formals and calling sealed `PodU32U8_StoreSplit`. Returns `dest`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043e8f0_FUN_0043e8f0.md` (+ W33-M append) |
| Annotated | `docs/reconstruction/raw/aa_0043e8f0_FUN_0043e8f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodU32U8_StoreByValue.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e8f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043e8f0_FUN_0043e8f0.md` |
| Named record | `docs/reconstruction/functions/aa_0043e8f0_PodU32U8_StoreByValue.md` |
| Live | decompile plate incomplete; full 19 B hex; listing; caller `ADD ESP,8` |

---

## 3. Signature (sealed)

```c
// ESI=dest; stack u32_val, u8_val; bare RET (cdecl); returns dest in EAX
void* PodU32U8_StoreByValue(void* dest /*ESI*/,
                            uint32_t u32_val /*stack*/,
                            uint32_t u8_val /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| dest | **ESI** (`MOV EAX,ESI` pre-call + post-call) | **High** |
| u32_val | Stack `[ESP+4]`; `LEA ECX,[ESP+8]` after one push | **High** |
| u8_val | Stack `[ESP+8]`; `LEA EAX,[ESP+8]; PUSH` at entry | **High** |
| cleanup | bare **`RET`** + caller `ADD ESP,8` | **High** |
| return | **EAX = ESI** | **High** |

Decompiler `void FUN_0043e8f0(void)` is **wrong**. **Bytes win.**

---

## 4. Control flow (clean ≡ bytes)

```
pU8  = &stack_u8
push pU8
pU32 = &stack_u32
EAX  = ESI
CALL PodU32U8_StoreSplit   // writes 5 B at dest
EAX  = ESI
RET
```

| Stage | Match | Conf |
|---|---|---|
| Dual LEA of stack formals | **Yes** | **High** |
| Sole callee `0043ea50` | **Yes** (rel32) | **High** |
| No null gate | **Yes** | **High** |
| Body 19 B sealed | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
8D 44 24 08 50 8D 4C 24 08 8B C6 E8 50 01 00 00 8B C6 C3
```

Body length **19 B**. Pad `CC`. Next related store family units follow nearby.

---

## 6. Gaps

- Product/PDB field English for the u32+u8 pair.
- Runtime / bit-exact under NDResourceCache / ass parents.
- Parent wrappers `00970b20` / `00970b60` dual free (W33-N).

---

## 7. Verdict

ABI, by-value→split adapt, return dest, and 19 B body sealed from live decompile + full-body `read_memory` + caller cleanup evidence → **accept**.
