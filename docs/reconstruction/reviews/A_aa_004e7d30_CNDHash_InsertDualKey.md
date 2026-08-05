# Review A (reconstruction fidelity): `aa_004e7d30` CNDHash_InsertDualKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7d30` |
| **VA** | `0x004e7d30`–`0x004e7e5d` |
| **Canonical name** | `CNDHash_InsertDualKey` |
| **Ghidra name** | `FUN_004e7d30` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-L) |
| **Counterpart** | `reviews/B_aa_004e7d30_CNDHash_InsertDualKey.md` |
| **System** | client world object hash / CNDHash |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` 302 B + xrefs; caller dual `aa_004dbef0` |
| **Verdict** | **accept** |

---

## 1. Purpose

CNDHash **dual-u32-key insert**:

1. Reject null value → `E_POINTER` (`0x80004003`).
2. If traversal-locked (`table+0x1d`): log HashError + `VOG_DEBUG_STOP` (continues).
3. Soft mode: existing payload → return `1` (skip).
4. Hard duplicate → log + `E_FAIL` (`0x80004005`).
5. Freelist-pop node, init vtbl/key/value, link bucket + global DLL, `count++`, return `0`.

Sole caller: capacity/register path of object hash via `CVOGReaction_RegisterObjectHashEntry_Inferred`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e7d30_FUN_004e7d30.md` (+ 2026-07-29 W23-L append) |
| Annotated | `docs/reconstruction/raw/aa_004e7d30_FUN_004e7d30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_InsertDualKey.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e7d30.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e7d30_FUN_004e7d30.md` |
| Caller review | `A_aa_004dbef0_CVOGReaction_RegisterObjectHashEntry_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` 302 B; all epilogs `C2 10 00` |

---

## 3. Signature (sealed)

```c
// stack formals x4; ECX = table*; RET 0x10
uint32_t CNDHash_InsertDualKey(void *table, uint32_t keyLo, uint32_t keyHi, void *value, char soft);
```

| Formal | Source | Conf |
|---|---|---|
| table | ECX → EDI | **High** |
| keyLo | Stack[0x4] | **High** |
| keyHi | Stack[0x8] | **High** |
| value | Stack[0xC] | **High** |
| soft | Stack[0x10] | **High** |
| cleanup | `RET 0x10` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Null value → 0x80004003 | **Yes** | **High** |
| Lock flag log (no early return) | **Yes** | **High** |
| Soft exists → return 1 | **Yes** | **High** |
| Hard duplicate → 0x80004005 | **Yes** | **High** |
| Freelist pop table+0x20 | **Yes** | **High** |
| Bucket index = keyLo & mask | **Yes** | **High** |
| DLL tail insert / empty head | **Yes** | **High** |
| count++ | **Yes** | **High** |
| Sole caller RegisterObjectHashEntry | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body size **302** B. Immediate returns:

| Path | Bytes |
|---|---|
| E_POINTER | `B8 03 40 00 80` + `C2 10 00` |
| soft hit | `B8 01 00 00 00` + `C2 10 00` |
| E_FAIL | `B8 05 40 00 80` + `C2 10 00` |
| success | `33 C0` + `C2 10 00` |

Strings confirmed via `read_memory` @ `0x00a64c18`, `0x00a15844`, `0x00a64bf0`.

---

## 6. Gaps

- Product English distinguishing this node vtbl (`PTR_FUN_009cc208`) from mission/medal insert twins.
- Soft-mode live caller (sealed sole caller always soft=0).
- Full freelist slab policy (owned by `FUN_00589890`).
- Runtime / bit-exact.

---

## 7. Verdict

CF/ABI/HRESULT returns/string evidence sealed; reject bad `VOG_DEBUG_STOP` alias → **accept**.
