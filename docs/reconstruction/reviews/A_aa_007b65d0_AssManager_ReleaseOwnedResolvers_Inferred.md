# Review A (reconstruction fidelity): `aa_007b65d0` AssManager_ReleaseOwnedResolvers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b65d0` |
| **VA** | `0x007b65d0`–`0x007b66a3` (**211** B) |
| **Canonical name** | `AssManager_ReleaseOwnedResolvers_Inferred` |
| **Ghidra name** | `FUN_007b65d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-D) |
| **Counterpart** | `reviews/B_aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md` |
| **System** | assManager / asset resolver teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 211 B); callers/callees. **No** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destructor body: if slot **+8** / **+0xc** hold resolver interfaces, remove them from the global assManager resolver list (and prune a side string vector on arm A), invoke scalar-deleting dtor `(1)`, null the slot. Arm B logs `"Removing resolver not found"` from `assManager.cpp:0x27b` when GuardedVector find fails.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b65d0_FUN_007b65d0.md` (+ W29-D append) |
| Annotated | `docs/reconstruction/raw/aa_007b65d0_FUN_007b65d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_ReleaseOwnedResolvers_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007b65d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md` |
| Live | decompile ≡ raw CF; body hex sealed; strings @ `0x00a9e930` / `0x00a9e888` |
| Related dual | `aa_0043c550` GuardedVector_EraseFirstEqual (W28-C) — callee of arm B |

---

## 3. Signature (sealed)

```c
// EBX=this; plain RET; void
void AssManager_ReleaseOwnedResolvers_Inferred(AssManagerResolverEntry* self);
```

| Slot | Source | Conf |
|---|---|---|
| this | **EBX** | **High** |
| formals | none | **High** |
| cleanup | plain `ret` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Arm A gate `[ebx+8]` | **Yes** | **High** |
| `FUN_00423e00` with ECX=`*DAT_00d1f058` | **Yes** | **High** |
| Scalar delete + null +8 | **Yes** | **High** |
| 0x14 × erase-first on `*DAT_00d1f1fc` (0x1c stride) | **Yes** | **High** |
| Arm B key=`[ebx+0xc]`; ESI=manager+0x58 | **Yes** | **High** |
| Find `FUN_0043e5b0` / erase `FUN_0043c550` / log | **Yes** | **High** |
| Scalar delete + null +0xc | **Yes** | **High** |
| Product class / iface type | shape only | **Medium** |

---

## 5. Machine bytes (`read_memory`)

Full **211 B** hex sealed in raw append. Entry `51 8B 43 08 85 C0 56 74 6A`. Epilogue `5E 59 C3`. Pad `CC` then `FUN_007b66b0`.

---

## 6. Gaps

- Product/PDB class English beyond file path.
- Resolver interface vtable product name.
- Unowned `FUN_00423e00` / `FUN_0043e5b0` / `FUN_0044d4e0` full duals.
- Why arm A uses max-20 first-erases vs single clear.
- Runtime / multi-thread concurrent remove.

---

## 7. Verdict

ABI, dual-arm CF, assManager strings, GuardedVector +0x58 path, and erase/log trichotomy sealed from live decompile + full body bytes. Nested list helpers + product English residual → **accept-with-gaps**.
