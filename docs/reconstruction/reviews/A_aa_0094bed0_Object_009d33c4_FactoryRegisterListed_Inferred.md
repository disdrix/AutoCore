# Review A (reconstruction fidelity): `aa_0094bed0` Object_009d33c4_FactoryRegisterListed_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094bed0` |
| **VA** | `0x0094bed0`–`0x0094bf8d` (**190 B** / `0xBE`; pad `CC` after) |
| **Canonical name** | `Object_009d33c4_FactoryRegisterListed_Inferred` (Ghidra `FUN_0094bed0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W30-K) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md` |
| **System** | object factory / host listing registration |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_xrefs_to` / callers / callees. **No** `disassemble_bytes`. Callee duals W29-H (`00575440`), W19-E (`004bc180`).

---

## 1. Purpose

Host-side factory for the `009d33c4` object family:

1. SEH frame + `operator_new(0x210)`.
2. Complete ctor `Object_009d33c4_Ctor` when non-null.
3. Virtual init `vtbl+8(DAT_00af30f4, host+0xe04, 1)`.
4. `Object_SetCoidIdentity(obj, coid_lo, coid_hi, 1)`.
5. Virtual `vtbl+0x218(host+0xe04)`.
6. `Object_RegisterListed(*(host+0xd34), obj)`; on HRESULT `< 0` scalar-delete `vtbl[0](1)` and return null; else return object.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.md` | Append live re-verify |
| Annotated | `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_009d33c4_FactoryRegisterListed_Inferred.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0094bed0.cpp` | Refined |
| Function named | `docs/reconstruction/functions/aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_0094bed0_FUN_0094bed0.md` | Updated |
| Live decompile | Ghidra @ `0x0094bed0` | surface residuals noted |
| Live bytes | `read_memory` 200 B | body sealed |
| Xrefs | complete / callers | 1 CALL |

**Not performed:** Launcher, runtime golden, dual of `FUN_008119c0` / `vtbl+8` / `+0x218`.

---

## 3. Signature (image-sealed)

```c
// EDI = host; stack (coid_lo, coid_hi); ret 8; object* or NULL
void *Object_009d33c4_FactoryRegisterListed_Inferred(
    void *host /*EDI*/, uint32_t coid_lo, uint32_t coid_hi);
```

| Item | Evidence | Conf |
|---|---|---|
| Body 190 B + `ret 8` both exits | `read_memory` / `C2 08 00` | **High** |
| EDI host + stack COID pair | `[edi+…]` uses; caller push `[esi+8]/[esi+0xc]` | **High** |
| new 0x210 → ctor `00575440` | relative `E8` math | **High** |
| SetCoidIdentity args = stack formals | `[esp+0x18]/[esp+0x1c]` after frame | **High** |
| Register on `host+0xd34` | `8B 8F 34 0D 00 00` | **High** |
| Fail path scalar-delete | `FF 12` with push 1 | **High** |
| Product type English | structural from W29-H vtbl | **Low** |
| Decompiler void surface alone | incomplete | **Low** as sole source |

---

## 4. Control flow: clean ≡ bytes (prefer) ≡ raw append

| Stage | Match |
|---|---|
| SEH + new(0x210) + optional ctor | **Yes** |
| vtbl+8(global, host+e04, 1) | **Yes** |
| SetCoidIdentity(stack COIDs, 1) | **Yes** (bytes; decompiler wrong) |
| vtbl+0x218(host+e04) | **Yes** |
| RegisterListed; hr&lt;0 → delete/NULL | **Yes** |
| ret 8 both paths | **Yes** |

---

## 5. Gaps

- Product/PDB demangle for object + host types.
- English for `vtbl+8` / `+0x218` and host `+0xe04`.
- OOM (null new) is not guarded after ctor branch — image undefined.
- Runtime / bit-exact / differential open.
- Parent `FUN_008119c0` ownership story not dualled here.

---

## 6. Verdict

Reconstruction fidelity is **high** for ABI/CF/callee graph; product English and virtual semantics remain open → **accept-with-gaps**.
