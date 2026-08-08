# Review A (reconstruction fidelity): `aa_00408640` StdVector_InsertN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408640` |
| **VA** | `0x00408640`–`0x0040887c` exclusive (**572 B** / `0x23C`) |
| **Canonical name** | `StdVector_InsertN_Elem0x10_Inferred` |
| **Ghidra name** | `FUN_00408640` |
| **Review date** | `2026-08-04` (WQ9H-H dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9H-H) |
| **Counterpart** | `reviews/B_aa_00408640_StdVector_InsertN_Elem0x10_Inferred.md` |
| **System** | util / container (generic) |
| **Evidence pass** | Live decompile + `read_memory` (prolog/body/ret) + analyze + xrefs + assembly context + callee peeks |
| **Verdict** | **accept-with-gaps** under `_Inferred` product method name |

**Tools:** decompile + read_memory (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

MSVC-style `std::vector<T>` **insert-n** for **16-byte** elements. Inserts `count` copies of `*value` at iterator `where`, growing capacity when needed (1.5× with exact-fit floor). Generic container infrastructure. **Not** domain / input-poll logic despite scaffold call-chain name.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00408640_FUN_00408640.md` (+ WQ9H-H append) |
| Annotated | `docs/reconstruction/raw/aa_00408640_FUN_00408640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408640.cpp` |
| Function records | `aa_00408640_FUN_00408640.md`, named record |
| Live decompile | ≡ raw body (insert-N spine) |
| Image | `read_memory` — SEH prolog; `C2 08 00` ret; `C1 F8 04` / `C1 E0 04` stride |
| Caller | `FUN_00930360` @ `0x009305c5` — `MOV ECX,1`; push value/where; `LEA EDX,vec` |
| Callee peeks | `FUN_00407000` (construct-N `*0x10`); `FUN_00409b60` → `FUN_0040a670` |
| Twin | dword InsertN `0x004073a0` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live decompile | **High** | CF spine identical |
| **ECX** = count | **High** | entry `MOV ESI,ECX`; site `MOV ECX,1` |
| **EDX** = vector* | **High** | entry `MOV EBX,EDX`; triad `+4/+8/+0xC` |
| Stack where + value* | **High** | value 4 dwords copied; **RET 8** |
| Element stride **0x10** | **High** | all `>>4` / `<<4` / `*0x10` |
| 1.5× growth + exact floor | **High** | body exact; max `0x0FFFFFFF` |
| Realloc path three-way relocate | **High** | copy prefix / fill / copy suffix / delete old |
| In-place two sub-cases | **High** | distance-to-end vs count |
| Overflow via `FUN_00418130` | **High** | shared throw helper |
| Product English demangle | **Inferred** | no string/RTTI on VA |
| Element domain type | **Open** | 16-byte POD bag |

---

## 4. Signature (sealed)

```c
void __fastcall StdVector_InsertN_Elem0x10_Inferred(
    uint32_t count,           // ECX
    VectorElem0x10 *vec,      // EDX; +4 begin, +8 end, +0xC capEnd
    uint8_t *where,           // stack
    const VecElem0x10 *value);// stack; 4 dwords; RET 8
```

---

## 5. Gaps / open

1. Exact MSVC demangled name (`std::vector<…>::_Insert_n` template args).
2. Dual seal of relocate/fill callees (`00409b60`, `00407000`, `0040a670`, `0045f050`, `00465bc0`).
3. Bit-exact / runtime / image diff.
4. Product 16-byte POD English type.

**Verdict:** **accept-with-gaps** — role + growth + triad + ABI/stride sealed; keep `_Inferred`.
