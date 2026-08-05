# Review A (reconstruction fidelity): `aa_00442c80` HostAux14_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00442c80` |
| **VA** | `0x00442c80`–`0x00442cba` exclusive (**58 B** / `0x3A`) |
| **Canonical name** | `HostAux14_Ctor_Inferred` |
| **Ghidra name** | `FUN_00442c80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-S) |
| **Counterpart** | `reviews/B_aa_00442c80_HostAux14_Ctor_Inferred.md` |
| **System** | client / host-base aux |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + sole-caller site. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf constructor of the **0x14-byte** object stored at `host+8` by `HostBase_EnsureAuxPtrs_Inferred`:

1. `*self = PTR_FUN_00a9f49c` (vtbl).
2. Zero dwords at `+8`, `+0xc`, `+0x10`.
3. Leave `+4` untouched.
4. Return `self` in EAX (`RET 4`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-S) | `docs/reconstruction/raw/aa_00442c80_FUN_00442c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00442c80_FUN_00442c80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/HostAux14_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00442c80.cpp` |
| Function records | `functions/aa_00442c80_FUN_00442c80.md`, `functions/aa_00442c80_HostAux14_Ctor_Inferred.md` |
| Related | `HostBase_EnsureAuxPtrs_Inferred` (W32-Q sole caller) |
| Live | body hex sealed; SEH `0x009bcb48`; `C2 04 00` |

---

## 3. Signature (sealed)

```c
// Stack formal self* (not ECX thiscall entry); RET 4; returns self in EAX
void *HostAux14_Ctor_Inferred(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | stack `[esp+4]` / after SEH `[esp+0x10]` in EAX | **High** |
| return | EAX = self (untouched through field stores) | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH frame (handler 0x009bcb48)
eax = self
[eax+0] = PTR_FUN_00a9f49c
[eax+8] = [eax+0xc] = [eax+0x10] = 0
// +4 not written
unwind SEH; RET 4  (EAX still self)
```

| Stage | Match | Conf |
|---|---|---|
| Body size 0x3A / RET 4 | **Yes** | **High** |
| Vtbl + three zeros | **Yes** | **High** |
| +4 untouched | **Yes** | **High** |
| Sole caller store `[host+8]=eax` | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |

---

## 5. Gaps

- Product / PDB class English for `PTR_FUN_00a9f49c`.
- Vtable method product roles.
- Semantic meaning of reserved/untouched `+4`.
- Runtime / bit-exact (product residual only).

---

## 6. Verdict

Reconstruction fidelity fully sealed for ABI, layout, and sole-caller contract. Residual is product English only → **accept**.
