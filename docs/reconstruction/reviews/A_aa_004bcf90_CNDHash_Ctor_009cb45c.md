# Review A (reconstruction fidelity): `aa_004bcf90` CNDHash_Ctor_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcf90` |
| **VA** | `0x004bcf90`–`0x004bd001` (**114 B / `0x72`) |
| **Canonical name** | `CNDHash_Ctor_009cb45c` (Ghidra `FUN_004bcf90`; **Inferred** stamp-qualified) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-J) |
| **Counterpart** | `reviews/B_aa_004bcf90_CNDHash_Ctor_009cb45c.md` |
| **System** | container / CNDHash (COList nested hashA/hashB; object vtbl `009cb45c`) |
| **Evidence pass** | Live Ghidra `decompile_function` + full-body `read_memory` (114 B) + `get_function_by_address` + callers/callees/xrefs + vtbl rdata. Parallel: `CNDHash_Ctor_009ce1a0` W26-P; twin `CNDHash_Ctor_009cb450`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CNDHash constructor for stamp `009cb45c`:

```text
// thiscall; stack log2; returns this; ret 4
*this = &PTR_FUN_009cb45c
zero fields; +0x08 = 1 << log2; +0x1C = log2; +0x1D = 0
// +0x24 not written
FUN_004bc840(this)  // AllocBucketTable → mask + table + sentinels 009cb350
return this
```

**Caller:** COList_Constructor `FUN_004bbfb0` for optional host +0x04 / +0x08 after `operator_new(0x34)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W28-J) | `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb45c.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bcf90.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bcf90_CNDHash_Ctor_009cb45c.md` |
| Parallel ctor | `aa_0051db60` CNDHash_Ctor_009ce1a0 (W26-P) |
| Host caller | `aa_004bbfb0` COList_Constructor (W27-L) |
| Live | decompile ≡ raw; 114 B; exit `C2 04 00` |

---

## 3. Signature (sealed)

```c
void *__thiscall CNDHash_Ctor_009cb45c(void *thisHash, uint8_t log2);
// ECX=this; ret 4; EAX=this
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004bcf90`–`004bd001` = **114 B** | **High** |
| thiscall | `56 8B F1` | **High** |
| ret 4 | `C2 04 00` | **High** |
| vtbl imm | `C7 06 5C B4 9C 00` → `009cb45c` | **High** |
| Alloc callee | `E8` → `0x004bc840` | **High** |
| sizeof | COList `operator_new(0x34)` | **High** |

---

## 4. Control flow (sealed)

```
SEH LAB_009a16eb
ESI = this
CL = log2; EDX = 1 << CL
*this = 009cb45c
zero +0x04/+0x0C/+0x10/+0x14/+0x18/+0x20/+0x28/+0x2C/+0x30
+0x08 = EDX (N); +0x1C = log2; +0x1D = 0
// no +0x24 store
call FUN_004bc840(this)
return this; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Field init order | **Yes** (bytes + decompile) | **High** |
| Unwritten +0x24 | **Yes** | **High** |
| Live decompile ≡ scaffold raw | **Yes** | **High** |
| Parallel to medal CNDHash ctor | **Yes** (same template) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `6A FF 68 EB 16 9A 00 … 56 8B F1` |
| vtbl | `C7 06 5C B4 9C 00` |
| N shift | `BA 01 00 00 00 D3 E2` / `89 56 08` |
| Call | `8B CE E8 51 F8 FF FF` → `004bc840` |
| Exit | `8B C6 … 83 C4 10 C2 04 00` |
| Pad | `CC` after body |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | UNCONDITIONAL_CALL from `FUN_004bbfb0` @ `004bc042`, `004bc07b` |
| Callees | `FUN_004bc840` only |
| Twin stamp | `CNDHash_Ctor_009cb450` / `FUN_004bce90` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / CF / field init / ret 4 | **High** |
| CNDHash family classification | **High** (layout + HashError siblings + sealed ctor parallels) |
| Stamp-qualified name | **Inferred** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product / PDB English beyond CNDHash stamp.
2. Full vtbl method matrix at `009cb45c` (OWN does not include dtor/RemoveAll bodies).
3. Semantic of unwritten `+0x24`.
4. AllocBucketTable body (`FUN_004bc840`) not OWN — post-condition mask=`N-1` from sibling pattern.
5. Runtime hit verification.

---

## Verdict

**accept-with-gaps** — ABI, field init, vtbl stamp, Alloc handoff, and sole COList caller sealed High. Residual is product English + non-OWN Alloc/vtbl methods + verification depth.
