# Review A (reconstruction fidelity): `aa_004d64d0` CVOGSectorMap_Destructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d64d0` |
| **VA** | `0x004d64d0`–`0x004d6c77` |
| **Canonical name** | `CVOGSectorMap_Destructor` |
| **Ghidra name** | `FUN_004d64d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-J) |
| **Counterpart** | `reviews/B_aa_004d64d0_CVOGSectorMap_Destructor.md` |
| **System** | client / CVOGSectorMap |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` full body (1960 B) + `get_function_by_address` / callers / callees / xrefs. Twin ctor `aa_004d8a10`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy a **CVOGSectorMap** instance: reinstall class vtbl, decrement construction counter, tear down hash tables / owned members / subsystem helpers / buffer triples for the `0xE920` object.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W26-J) | `docs/reconstruction/raw/aa_004d64d0_FUN_004d64d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004d64d0_FUN_004d64d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_Destructor.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004d64d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d64d0_CVOGSectorMap_Destructor.md` |
| Twin | `aa_004d8a10` CVOGSectorMap_Constructor (vtbl + `_DAT_00b037e4++`) |
| Live | decompile ≡ raw; body 1960 B; epilogue `5E 5B 83 C4 08 C3` |

---

## 3. Signature (sealed)

```c
void __thiscall CVOGSectorMap_Destructor(CVOGSectorMap* this);
// ECX=this; sub/add esp,8; bare ret; void
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004d64d0`–`004d6c77` = **1960 B** | **High** |
| Vtbl install | `C7 06 70 C7 9C 00` → `0x009cc770` | **High** |
| Counter | `83 2D E4 37 B0 00 01` → `_DAT_00b037e4--` | **High** |
| Product class | ctor twin + `@@new CVOGSectorMap` | **High** |

---

## 4. Control flow (sealed high-level)

```
vtbl = PTR_FUN_009cc770
flag[0x3a04]=0; counter--
free buffer[0x3a1d]; vdel[0x3a45]
lock-traverse hash[0x3971] → FUN_004e3610 destroy loop → unlock → vdel hash
vdel cascade (0x3973…0x3948…)
optional FUN_005b0680 + delete [0x3942]
drain list[0x397f] PopFront discard; drain list[0x3991] PopFront+vdel payload
subsystem FUN_004d2970 / FUN_005bf720 / peer clear [0x3a27]
buffer frees + FUN_004e7380 / FUN_00497360 / FUN_004e7350
resource free via DAT_00b05060 vtbl+0x14 if [0x3a05]>=0
more buffer frees + FUN_004e7320 / FUN_004e4460 / FUN_004e4410
FUN_004bcbf0 embedded list; FUN_004e7200×2 / FUN_004e72f0 / FUN_004e72c0 / FUN_004e7290
ret
```

| Stage | Match | Conf |
|---|---|---|
| Entry vtbl + counter | **Yes** | **High** |
| Hash destroy + HashError strings | **Yes** | **High** |
| PopFront list drains | **Yes** | **High** |
| Subsystem helper order | **Yes** (decomp) | **High** |
| Sequential free (not noreturn ladder) | **Yes** (bytes) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry 16 B | `83 EC 08 53 56 8B F1 33 DB C7 06 70 C7 9C 00` |
| Exit 6 B | `5E 5B 83 C4 08 C3` |
| Full body | 1960 B @ `0x004d64d0` (live 2026-07-29) |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Caller | `Catch@0094b325` @ `0x0094b34e` only |
| Role | InitInstance failure cleanup of sector map at client+`0xe04` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / vtbl / class / counter | **High** |
| CF phases + callees | **High** |
| Full field English for 0xE920 | **Partial / Open** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps (do not block structural seal)

1. Exhaustive product field names (shared with ctor gap).
2. Whether any live vtbl slot points here vs Catch-only path.
3. Runtime construction/destruction differential.

**Verdict:** **accept-with-gaps** — destructor ABI, class identity, and teardown structure sealed; field-level English incomplete.
