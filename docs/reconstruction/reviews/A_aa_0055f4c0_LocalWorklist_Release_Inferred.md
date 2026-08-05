# Review A (reconstruction fidelity): `aa_0055f4c0` LocalWorklist_Release_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f4c0` |
| **VA** | `0x0055f4c0`–`0x0055f51b` |
| **Body** | **92 bytes** (`0x5C`) |
| **Canonical name** | `LocalWorklist_Release_Inferred` |
| **Ghidra name** | `FUN_0055f4c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-N) |
| **Counterpart** | `reviews/B_aa_0055f4c0_LocalWorklist_Release_Inferred.md` |
| **System** | allocator / local worklist teardown |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Release a **local worklist / stack alloc descriptor** (`ECX`):

1. Compute aligned slab bytes: `(desc[+0x10]*8 + 0xf) & ~0xf`.
2. If size==0 OR (slab ≠ arena-current AND arena-current ≠ 0): bump `DAT_00b05060` counters; else vcall `vtbl+0x28`.
3. If `(int)desc[+0x8] >= 0`: vcall `vtbl+0x14(*desc, (count&0x7fffffff)*8, 0x12)`.

Always run at end of bind/unbind manager paths (and siblings).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055f4c0_FUN_0055f4c0.md` (+ 2026-07-29 W27-N append) |
| Annotated | `docs/reconstruction/raw/aa_0055f4c0_FUN_0055f4c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LocalWorklist_Release_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055f4c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055f4c0_FUN_0055f4c0.md` |
| Named record | `docs/reconstruction/functions/aa_0055f4c0_LocalWorklist_Release_Inferred.md` |
| Live | decompile ≡ raw CF; `read_memory` prologue `56 8B F1...` + epilogue `5F 5E C3` |
| Caller duals | W26-D Unbind / W26-E Bind (always teardown) |

---

## 3. Signature (sealed)

```c
// __fastcall/thiscall; ECX = desc; ret 0; void
void LocalWorklist_Release_Inferred(std::uint32_t *desc /*ECX*/);
```

| Formal | Source | Conf |
|---|---|---|
| desc | ECX (`MOV ESI,ECX`) | **High** |
| return | void | **High** |
| cleanup | plain `ret` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
size = (desc[4]*8 + 0xf) & ~0xf
if size==0 or (desc[3]!=arena[5] and arena[5]!=0):
  arena[2]-=size; arena[3]+=size
else:
  arena->vtbl[0x28](desc[3], size)
if (int)desc[2] >= 0:
  arena->vtbl[0x14](*desc, (desc[2]&0x7fffffff)*8, 0x12)
ret
```

| Stage | Match | Conf |
|---|---|---|
| Aligned size | **Yes** | **High** |
| Slab bump vs free branch | **Yes** | **High** |
| Tag free with mask | **Yes** (machine) | **High** |
| ECX-only ret | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

- Entry `0x0055f4c0`: `56 8B F1 8B 46 10 8B 56 0C 8B 0D 60 50 B0 00`.
- Tag path uses `AND EAX,0x7FFFFFFF` then three left-shifts-by-add (`*8`); `PUSH 0x12`.
- Exit `0x0055f519`: `5F 5E C3` then `CC` pad.
- Body **92 B**.

---

## 6. Gaps

- Product English for `DAT_00b05060` allocator.
- Full stack descriptor field map beyond sealed offsets.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, teardown role vs bind/unbind callers sealed. Machine mask correction folded into clean. Naming **INFERRED**. → **accept**.
