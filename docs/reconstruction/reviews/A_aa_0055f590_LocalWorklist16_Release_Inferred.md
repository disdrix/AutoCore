# Review A (reconstruction fidelity): `aa_0055f590` LocalWorklist16_Release_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f590` |
| **VA** | `0x0055f590`–`0x0055f5e7` |
| **Body** | **88 bytes** (`0x58`) |
| **Canonical name** | `LocalWorklist16_Release_Inferred` |
| **Ghidra name** | `FUN_0055f590` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-R) |
| **Counterpart** | `reviews/B_aa_0055f590_LocalWorklist16_Release_Inferred.md` |
| **System** | allocator / local worklist teardown (stride 0x10) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Release a **local worklist / stack alloc descriptor** (`ECX`) for **16-byte elements**:

1. Compute aligned slab bytes: `(desc[+0x10]*0x10 + 0xf) & ~0xf`.
2. If size==0 OR (slab ≠ arena-current AND arena-current ≠ 0): bump `DAT_00b05060` counters; else vcall `vtbl+0x28`.
3. If `(int)desc[+0x8] >= 0`: vcall `vtbl+0x14(*desc, (count&0x7fffffff)<<4, 0x12)`.

Always run at end of `Phys_CommitPairListStorage` after stride-16 worklist use. Sibling of `LocalWorklist_Release_Inferred` (*8 at `0x0055f4c0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055f590_FUN_0055f590.md` (+ 2026-07-29 W28-R append) |
| Annotated | `docs/reconstruction/raw/aa_0055f590_FUN_0055f590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LocalWorklist16_Release_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055f590.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055f590_FUN_0055f590.md` |
| Named record | `docs/reconstruction/functions/aa_0055f590_LocalWorklist16_Release_Inferred.md` |
| Live | decompile ≡ raw CF; prologue `56 8B F1...` + epilogue `5F 5E C3`; tag path `25 FF FF FF 7F 6A 12 C1 E0 04` |
| Caller dual | W27-M `Phys_CommitPairListStorage` (always teardown after init) |
| Sibling | W27-N `LocalWorklist_Release_Inferred` (*8) — same CF shape, different stride |

---

## 3. Signature (sealed)

```c
// __fastcall/thiscall; ECX = desc; ret 0; void
void LocalWorklist16_Release_Inferred(std::uint32_t *desc /*ECX*/);
```

| Formal | Source | Conf |
|---|---|---|
| desc | ECX (`MOV ESI,ECX`) | **High** |
| return | void | **High** |
| cleanup | plain `ret` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
size = (desc[4]*0x10 + 0xf) & ~0xf
if size==0 or (desc[3]!=arena[5] and arena[5]!=0):
  arena[2]-=size; arena[3]+=size
else:
  arena->vtbl[0x28](desc[3], size)
if (int)desc[2] >= 0:
  arena->vtbl[0x14](*desc, (desc[2]&0x7fffffff)<<4, 0x12)
ret
```

| Stage | Match | Conf |
|---|---|---|
| Aligned size | **Yes** (machine; decomp bare *0x10) | **High** |
| Slab bump vs free branch | **Yes** | **High** |
| Tag free with mask | **Yes** (machine) | **High** |
| ECX-only ret | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

- Entry `0x0055f590`: `56 8B F1 8B 46 10 8B 56 0C 8B 0D 60 50 B0 00 C1 E0 04 83 C0 0F 83 E0 F0`.
- Tag path: `AND EAX,0x7FFFFFFF`; `PUSH 0x12`; `SHL EAX,4`; `CALL [EDX+0x14]`.
- Exit `0x0055f5e5`: `5F 5E C3` then `CC` pad.
- Body **88 B**.

---

## 6. Gaps

- Product English for `DAT_00b05060` allocator.
- Full stack descriptor field map beyond sealed offsets.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, teardown role vs pair-list caller sealed. Machine align16 + mask correction folded into clean. Naming **INFERRED**. → **accept**.
