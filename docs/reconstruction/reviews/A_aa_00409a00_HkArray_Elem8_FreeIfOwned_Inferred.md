# Review A (reconstruction fidelity): `aa_00409a00` HkArray_Elem8_FreeIfOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409a00` |
| **VA** | `0x00409a00` |
| **Body** | `0x00409a00`–`0x00409a28` exclusive (**40** B / `0x28`) |
| **Canonical name** | `HkArray_Elem8_FreeIfOwned_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00409a00` |
| **Review date** | `2026-08-05` (WQ9J-J OWN-ONLY dual) |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md` |
| **System** | allocator / hkArray-style free (elem size 8) |
| **Live tools** | decompile + read_memory + analyze + callers/xrefs + disassemble_function (**no** disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

thiscall free-if-owned helper for a 12-byte array triple with **element size 8**. SEH unwind tables JMP here with ECX pointing at a stack triple. Matches the tagged-free half of dualed `LocalWorklist_Release_Inferred` (`0x0055f4c0`) without arena slab return.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9J-J append) | `docs/reconstruction/raw/aa_00409a00_FUN_00409a00.md` |
| Annotated | `docs/reconstruction/raw/aa_00409a00_FUN_00409a00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HkArray_Elem8_FreeIfOwned_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00409a00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md` |
| Peer free | `aa_0055f4c0` LocalWorklist_Release_Inferred (W27-N) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `8B D1` — `MOV EDX,ECX` |
| Cap load | `8B 42 08` — capacity `@+8` |
| Owned gate | `TEST EAX,EAX` / `JS` early RET when signed `< 0` |
| Allocator | `8B 0D 60 50 B0 00` — `DAT_00b05060` |
| Mask | `25 FF FF FF 7F` — **`AND 0x7FFFFFFF`** |
| Scale | three `03 C0` → `*8` |
| Tag | `6A 12` — push **`0x12`** |
| Free | `FF 56 14` — `CALL [vtbl+0x14]` |
| RET | `C3` plain |
| Body end | exclusive `0x00409a28`; pad `CC` to `0x00409a2f` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size 40 B | **pass** |
| thiscall ECX + plain RET | **pass** |
| Owned gate on capacity | **pass** |
| Mask + *8 + tag 0x12 | **pass** (machine; decomp omits mask) |
| SEH-only callers | **pass** (2 unwind JMPs) |
| Product value_type English | **gap** |
| Runtime | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + free contract | **High** | full leaf sealed |
| Role free-if-owned elem8 | **High** | matches hkArray / worklist family |
| Name `_Inferred` | **Inferred** | no product string on VA |
| Runtime | Open | no Launcher |

---

## 6. Gaps (acceptable)

1. Product demangle for allocator + concrete elem type.  
2. Runtime / bit-exact.  
3. Whether any non-SEH direct CALL exists (xrefs show only 2 unwind JMPs).
