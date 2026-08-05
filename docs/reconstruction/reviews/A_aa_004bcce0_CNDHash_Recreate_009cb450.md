# Review A (reconstruction fidelity): `aa_004bcce0` CNDHash_Recreate_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcce0` |
| **VA** | `0x004bcce0`–`0x004bcd34` (**84 B / `0x54`**) |
| **Canonical name** | `CNDHash_Recreate_009cb450` (Ghidra `FUN_004bcce0`; stamp-qualified) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-G) |
| **Counterpart** | `reviews/B_aa_004bcce0_CNDHash_Recreate_009cb450.md` |
| **System** | container / CNDHash (COList tableC; object vtbl `009cb450`) |
| **Evidence pass** | Live Ghidra decompile + full-body `read_memory` + meta/callers/callees/xrefs. Twin `004bcd40`; Alloc W29-K; Ctor W28-J. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CNDHash **Recreate** for stamp family `009cb450`:

```text
// thiscall; stack log2; ret 4
if (+0x1D lock) log Recreate-locked + VOG_DEBUG_STOP  // continue
FUN_004bcc60(this)          // FreeBuckets twin
+0x1C = log2; +0x18 = 0; +0x08 = 1<<log2; +0x14 = 0
FUN_004bc7a0(this)          // AllocBucketTable_009cb348 → mask N-1
```

**Sole static caller:** `FUN_004bbeb0` @ `0x004bbeb8` always **`Recreate(5)`** → N=32 → mask 31 after Alloc (matches COList tableC always-log2=5 from W28-J ctor path).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-G) | `docs/reconstruction/raw/aa_004bcce0_FUN_004bcce0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcce0_FUN_004bcce0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_Recreate_009cb450.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bcce0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bcce0_CNDHash_Recreate_009cb450.md` |
| Alloc sealed | `aa_004bc7a0` CNDHash_AllocBucketTable_009cb348 (W29-K) |
| Ctor sealed | `aa_004bce90` CNDHash_Ctor_009cb450 (W28-J) |
| Caller | `FUN_004bbeb0` decompile — first call `FUN_004bcce0(5)` |
| Live | decompile ≡ raw; 84 B; exit `C2 04 00` |

---

## 3. Signature (sealed)

```c
void __thiscall CNDHash_Recreate_009cb450(void *thisHash, uint8_t log2);
// ECX=this; ret 4
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004bcce0`–`004bcd34` = **84 B** | **High** |
| thiscall + ret 4 | `56 8B F1` … `C2 04 00` | **High** |
| Free callee | `E8` → `0x004bcc60` | **High** |
| Alloc callee | `E8` → `0x004bc7a0` @ `0x004bcd2c` | **High** |
| Caller log2=5 | `FUN_004bcce0(5)` in `004bbeb0` | **High** |

---

## 4. Control flow (sealed)

Identical template to twin `004bcd40` with Free `004bcc60` + Alloc `004bc7a0`.

| Stage | Match | Conf |
|---|---|---|
| Lock fall-through | **Yes** | **High** |
| Live ≡ raw | **Yes** | **High** |
| Twin structural-only diff | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `56 8B F1 80 7E 1D 00 74 1B` |
| Free | `E8 55 FF FF FF` → `004bcc60` |
| N / stores | same as twin |
| Alloc | `E8 6F FA FF FF` → `004bc7a0` |
| Exit | `5E C2 04 00` + `CC` pad |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | UNCONDITIONAL_CALL from `FUN_004bbeb0` @ `004bbeb8` |
| Callees | Free `004bcc60`, Alloc `004bc7a0`, log `007a4480` |
| Twin | `CNDHash_Recreate_009cb45c` / `FUN_004bcd40` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / CF / log2 / ret 4 | **High** |
| Sole caller always bits=5 | **High** |
| Stamp-qualified name | **Inferred** |
| Host `FUN_004bbeb0` product English | **Open** (not OWN) |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English; FreeBuckets `FUN_004bcc60` not OWN.
2. Full semantics of host `FUN_004bbeb0` (clear/recreate path) not OWN.
3. Runtime verification.

---

## Verdict

**accept-with-gaps** — ABI, CF, Free→size→Alloc chain, sole caller log2=5, and tableC stamp sealed High. Residual is FreeBuckets OWN + host product English + verification depth.
