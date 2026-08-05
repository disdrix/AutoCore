# Review A (reconstruction fidelity): `aa_0096c8e0` EffTextureImpl_ReleaseGpu_Unaccount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096c8e0` |
| **VA** | `0x0096c8e0`–`0x0096ca5a` exclusive (**378 B**) |
| **Canonical name** | `EffTextureImpl_ReleaseGpu_Unaccount_Inferred` |
| **Ghidra name** | `FUN_0096c8e0` |
| **Prior scaffold** | `FUN_0096c8e0` / `Named_CalleeOf_Named_gfxDevice_0096c8e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W38-AB) |
| **Counterpart** | `reviews/B_aa_0096c8e0_EffTextureImpl_ReleaseGpu_Unaccount_Inferred.md` |
| **System** | palantir graphics Effects — effTextureImpl |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + Reset call-site bytes. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Release GPU COM resources on an effect-texture implementation object and reverse the memory/count accounting performed at the end of create (`FUN_0096cad0`):

1. If `self+0x10` (primary D3D texture) is non-null, subtract bytes/counts from optional stats host `DAT_00d1f614` by type/flag bank.
2. `IUnknown::Release` + null on `+0x10`, `+0x14` (RT surface), `+0x18` (depth stencil).

**Not** a full object destructor (no heap free / vtbl clear), not factory list walk, not create.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0096c8e0` (2026-08-04) ≡ raw scaffold |
| Bytes | `read_memory` — full **378 B** body; prolog `53 55 56 57 8B F9`; epilogue `5F 5E 5D 5B C3` |
| Call-site | Reset `0x0075f110`: `mov ecx,[esi+8]; cmp [ecx+0x30],0; call` |
| Create mirror | `FUN_0096cad0` decompile — same offsets, opposite `+`/`-` |
| Callees | `FUN_0096c730`, `FUN_0096c810`, `FUN_0096bb20`, vtbl[+8] |
| Callers | 6 functions / 7 xrefs including Reset + create |
| Raw / annotated / clean | `aa_0096c8e0_*`, named + twin cleans |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// __thiscall ECX=self; plain RET; void
void EffTextureImpl_ReleaseGpu_Unaccount_Inferred(EffTextureImpl* self);
```

| Formal | Source | Conf |
|---|---|---|
| self* | ECX (`mov edi,ecx`) | **Confirmed** |
| RET 0 | `C3` | **Confirmed** |
| void | no useful EAX contract | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Gate `+0x10 != 0` before unaccount | **Yes** | **Confirmed** |
| Flag `0x1000` → `c810` vs else `c730` | **Yes** | **Confirmed** |
| Type 2/4/else counter banks | **Yes** | **Confirmed** |
| RT path `+0x14` / depth `+0x18` + `bb20` | **Yes** | **Confirmed** |
| Release+null trio always | **Yes** | **Confirmed** |
| Body 378 B / pad to `0096ca60` | **Yes** | **Confirmed** |

### Stats banks (sealed offsets)

| Path | Count | Bytes |
|---|---|---|
| 2D (else, no RT) | `+0x350` | `+0x398` |
| cube (type2, no RT) | `+0x358` | `+0x3a0` |
| volume (type4, no RT) | `+0x360` | `+0x3a8` |
| RT | `+0x364` | `+0x3ac` |
| depth (with RT) | `+0x368` | `+0x3b0` |
| alt 2D (`0x1000`) | `+0x34c` | `+0x394` |
| alt cube | `+0x354` | `+0x39c` |
| alt volume | `+0x35c` | `+0x3a4` |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thiscall release+unaccount worker | **Confirmed** | bytes + callers |
| Stats offsets mirror create | **Confirmed** | `FUN_0096cad0` pair |
| Type nibble vs CreateTexture/Cube/Volume | **High** | create low-nibble branch |
| Flag `0x1000` product English | **Open** | structural only |
| Nested size helper plates | **Open** | not owned |
| Product demangle | **Open** | `_Inferred` |
| Runtime | **Open** | |

---

## 6. Gaps (explicit)

- Product/MSVC demangle method name.
- Exact product meaning of `0x1000` / managed pool bank labels.
- Duals for `FUN_0096c730` / `FUN_0096c810` / `FUN_0096bb20` / full `FUN_0096cad0`.
- Runtime / bit-exact / differential.

---

## 7. Verdict rationale

CF, ABI, COM Release trio, and stats-bank inverse of create are sealed from live decompile + body hex + create pair + Reset call-site. Product English and nested helpers remain open → **accept-with-gaps**.
