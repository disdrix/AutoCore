# Review A (reconstruction fidelity): `aa_005b7db0` Elem0x28_DefaultCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7db0` |
| **VA** | `0x005b7db0`–`0x005b7dee` exclusive (**62 B** / `0x3E`) |
| **Canonical name** | `Elem0x28_DefaultCtor` |
| **Ghidra name** | `FUN_005b7db0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-L) |
| **Counterpart** | `reviews/B_aa_005b7db0_Elem0x28_DefaultCtor.md` |
| **System** | class / cookie-vector element default ctor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs` + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Element **default constructor** for **0x28-byte** vector elements used by `Host_RebuildElem0x28ArrayFromMap_Inferred`:

1. Zero buffer triple @ `+0x4/+0x8/+0xc`.
2. Zero list-ptr vector triple @ `+0x14/+0x18/+0x1c`.
3. Zero owned @ `+0x24`.

Not a vtbl slot; not the complete dtor; not host-level logic.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-L re-verify) | `docs/reconstruction/raw/aa_005b7db0_FUN_005b7db0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b7db0_FUN_005b7db0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Elem0x28_DefaultCtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b7db0.cpp` |
| Function records | `functions/aa_005b7db0_FUN_005b7db0.md`, `functions/aa_005b7db0_Elem0x28_DefaultCtor.md` |
| Peer dtor | `Elem0x28_CompleteDtor` (`aa_005b8000`, W29-F) |
| Registration site | `Host_RebuildElem0x28ArrayFromMap_Inferred` (`aa_004941b0`, W30-Q) @ `0x004942db` |
| Live | decompile ≡ raw CF; full-body hex seals SEH + seven stores + bare RET |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=element; bare RET; void
void __thiscall Elem0x28_DefaultCtor(void* elem);
```

| Formal | Source | Conf |
|---|---|---|
| elem | ECX (`8B C1`) | **High** |
| return | void | **High** |
| stride | **0x28** at sole registration | **High** |

---

## 4. Control flow (clean ≡ raw; SEH from bytes)

```
SEH install (LAB_009a6ad8)
eax = ecx (elem)
xor ecx, ecx
[eax+4]=0; [eax+8]=0; [eax+0xc]=0
[eax+0x14]=0; [eax+0x18]=0; [eax+0x1c]=0
[eax+0x24]=0
SEH restore; add esp,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Seven zero-stores | **Yes** (decomp + bytes) | **High** |
| No write +0/+0x10/+0x20 | **Yes** | **High** |
| Body size / bare RET | **Yes** (bytes) | **High** |
| SEH frame present | **Yes** (bytes; decomp omits) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Full body (62 B) | `6A FF 68 D8 6A 9A 00 64 A1 … 51 8B C1 33 C9 89 48 04 … 89 48 24 … 83 C4 10 C3` |
| Pad | `CC CC`; next fn @ `0x005b7df0` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs (1) | DATA `0x004942db` in `FUN_004941b0` |
| Callees | none |
| Classification | leaf |

---

## 7. Confidence

| Claim | Level |
|---|---|
| Element default ctor / stride 0x28 | **High** |
| Offsets zeroed | **High** |
| Pair with CompleteDtor | **High** |
| Product type English | **Low** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English / demangle for element type.
2. Semantic meaning of untouched +0 / +0x10 / +0x20.
3. Runtime / bit-exact / differential.

---

## 9. Verdict

Fidelity pass seals ABI, body size, zero-set, SEH, and sole DATA registration. Residual product naming only → **accept-with-gaps**.
