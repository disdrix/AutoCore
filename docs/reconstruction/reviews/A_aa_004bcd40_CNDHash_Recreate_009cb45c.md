# Review A (reconstruction fidelity): `aa_004bcd40` CNDHash_Recreate_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcd40` |
| **VA** | `0x004bcd40`–`0x004bcd94` (**84 B / `0x54`**) |
| **Canonical name** | `CNDHash_Recreate_009cb45c` (Ghidra `FUN_004bcd40`; stamp-qualified) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-G) |
| **Counterpart** | `reviews/B_aa_004bcd40_CNDHash_Recreate_009cb45c.md` |
| **System** | container / CNDHash (COList hashA/hashB; object vtbl `009cb45c`) |
| **Evidence pass** | Live Ghidra decompile + full-body `read_memory` + meta/callers/callees/xrefs. Parallel: `CNDHash_Recreate` W25-F/medal `0051d230`; twin `004bcce0`. Alloc sealed W29-K. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CNDHash **Recreate** for stamp family `009cb45c`:

```text
// thiscall; stack log2; ret 4
if (+0x1D lock) log Recreate-locked + VOG_DEBUG_STOP  // continue
FUN_004bcca0(this)          // FreeBuckets twin
+0x1C = log2; +0x18 = 0; +0x08 = 1<<log2; +0x14 = 0
FUN_004bc840(this)          // AllocBucketTable_009cb350 → mask N-1
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-G) | `docs/reconstruction/raw/aa_004bcd40_FUN_004bcd40.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcd40_FUN_004bcd40.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_Recreate_009cb45c.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bcd40.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bcd40_CNDHash_Recreate_009cb45c.md` |
| Alloc sealed | `aa_004bc840` CNDHash_AllocBucketTable_009cb350 (W29-K) |
| Ctor sealed | `aa_004bcf90` CNDHash_Ctor_009cb45c (W28-J) |
| Parallel | `aa_0051d230` CNDHash_Recreate |
| Live | decompile ≡ raw; 84 B; exit `C2 04 00` |

---

## 3. Signature (sealed)

```c
void __thiscall CNDHash_Recreate_009cb45c(void *thisHash, uint8_t log2);
// ECX=this; ret 4
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004bcd40`–`004bcd94` = **84 B** | **High** |
| thiscall | `56 8B F1` | **High** |
| ret 4 | `C2 04 00` | **High** |
| Free callee | `E8` → `0x004bcca0` | **High** |
| Alloc callee | `E8` → `0x004bc840` @ `0x004bcd8c` | **High** |
| log2 polarity | `B8 01… D3 E0` then store +0x08 | **High** |
| Static callers | zero xrefs | **High** |

---

## 4. Control flow (sealed)

```
lock check → dual log (no abort)
call FreeBuckets FUN_004bcca0
load log2; N = 1 << log2
store +0x1C / +0x18=0 / +0x08=N / +0x14=0
call Alloc FUN_004bc840
pop esi; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Lock fall-through | **Yes** (je skips logs only) | **High** |
| Field store set | **Yes** (bytes + decompile) | **High** |
| Live decompile ≡ scaffold raw | **Yes** | **High** |
| Parallel medal Recreate template | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `56 8B F1 80 7E 1D 00 74 1B` |
| Free | `8B CE E8 35 FF FF FF` → `004bcca0` |
| N shift | `8A 4C 24 08 B8 01 00 00 00 D3 E0` |
| Stores | `88 4E 1C` / `C7 46 18 0` / `89 46 08` / `C7 46 14 0` |
| Alloc | `E8 AF FA FF FF` → `004bc840` |
| Exit | `5E C2 04 00` + `CC` pad |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | **none** |
| Callees | Free `004bcca0`, Alloc `004bc840`, log `007a4480` |
| Twin | `CNDHash_Recreate_009cb450` / `FUN_004bcce0` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / CF / log2 / ret 4 | **High** |
| CNDHash Recreate classification | **High** (string + twin Free/Alloc chain) |
| Stamp-qualified name | **Inferred** |
| Runtime / bit-exact / why zero callers | **Open** |

---

## 8. Gaps

1. Product / PDB English beyond Recreate string + family stamps.
2. FreeBuckets body `FUN_004bcca0` not OWN.
3. Zero static callers — dead vs dynamic-only open.
4. Runtime hit verification.

---

## Verdict

**accept-with-gaps** — ABI, CF, lock-warn semantics, Free→size→Alloc chain, and family stamp sealed High. Residual is FreeBuckets OWN, product English, zero-caller explanation, verification depth.
