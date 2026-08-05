# Review A (reconstruction fidelity): `aa_004bce90` CNDHash_Ctor_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bce90` |
| **VA** | `0x004bce90`–`0x004bcf01` (**114 B / `0x72`) |
| **Canonical name** | `CNDHash_Ctor_009cb450` (Ghidra `FUN_004bce90`; **Inferred** stamp-qualified) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-J) |
| **Counterpart** | `reviews/B_aa_004bce90_CNDHash_Ctor_009cb450.md` |
| **System** | container / CNDHash (COList nested tableC; object vtbl `009cb450`) |
| **Evidence pass** | Live Ghidra `decompile_function` + full-body `read_memory` (114 B) + `get_function_by_address` + callers/callees/xrefs + vtbl rdata. Twin `CNDHash_Ctor_009cb45c`; host COList_Constructor. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CNDHash constructor for stamp `009cb450`:

```text
// thiscall; stack log2; returns this; ret 4
*this = &PTR_FUN_009cb450
zero fields; +0x08 = 1 << log2; +0x1C = log2; +0x1D = 0
// +0x24 not written
FUN_004bc7a0(this)  // AllocBucketTable → mask + table + sentinels 009cb348
return this
```

**Caller:** COList_Constructor `FUN_004bbfb0` @ `0x004bc0b0` — **always** `operator_new(0x34)` + this ctor with **fixed log2 = 5** → host `+0x18`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W28-J) | `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.md` |
| Annotated | `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb450.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bce90.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bce90_CNDHash_Ctor_009cb450.md` |
| Twin ctor | `aa_004bcf90` CNDHash_Ctor_009cb45c (same wave) |
| Host caller | `aa_004bbfb0` COList_Constructor (W27-L) |
| Live | decompile ≡ raw; 114 B; exit `C2 04 00` |

---

## 3. Signature (sealed)

```c
void *__thiscall CNDHash_Ctor_009cb450(void *thisHash, uint8_t log2);
// ECX=this; ret 4; EAX=this
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004bce90`–`004bcf01` = **114 B** | **High** |
| thiscall | `56 8B F1` | **High** |
| ret 4 | `C2 04 00` | **High** |
| vtbl imm | `C7 06 50 B4 9C 00` → `009cb450` | **High** |
| Alloc callee | `E8` → `0x004bc7a0` | **High** |
| Production log2 | COList site pushes **5** | **High** |
| sizeof | COList `operator_new(0x34)` | **High** |

---

## 4. Control flow (sealed)

Byte-identical to `CNDHash_Ctor_009cb45c` except:

| Diff | This unit | Twin `004bcf90` |
|---|---|---|
| vtbl | `009cb450` | `009cb45c` |
| Alloc | `FUN_004bc7a0` | `FUN_004bc840` |

| Stage | Match | Conf |
|---|---|---|
| Field init incl. unwritten +0x24 | **Yes** | **High** |
| Live decompile ≡ scaffold raw | **Yes** | **High** |
| Twin-diff only two imms | **Yes** (full-body hex compare) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `6A FF 68 EB 16 9A 00 … 56 8B F1` (same SEH as twin) |
| vtbl | `C7 06 50 B4 9C 00` |
| Call | `8B CE E8 B1 F8 FF FF` → `004bc7a0` |
| Exit | `8B C6 … 83 C4 10 C2 04 00` |
| Pad | `CC` after body |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | UNCONDITIONAL_CALL from `FUN_004bbfb0` @ `004bc0b0` only |
| Callees | `FUN_004bc7a0` only |
| Twin stamp | `CNDHash_Ctor_009cb45c` / `FUN_004bcf90` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / CF / field init / ret 4 | **High** |
| Distinct from hashA/hashB stamp | **High** |
| Fixed production log2=5 at COList | **High** |
| Stamp-qualified name | **Inferred** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product / PDB English beyond CNDHash stamp.
2. Full vtbl method matrix at `009cb450`.
3. Semantic of unwritten `+0x24`.
4. AllocBucketTable body (`FUN_004bc7a0`) not OWN.
5. Runtime hit verification.

---

## Verdict

**accept-with-gaps** — ABI, field init, vtbl stamp, Alloc handoff, fixed COList(5) caller sealed High. Residual is product English + non-OWN Alloc/vtbl methods + verification depth.
