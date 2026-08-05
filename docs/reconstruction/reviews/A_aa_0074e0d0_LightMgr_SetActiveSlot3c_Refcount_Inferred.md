# Review A (reconstruction fidelity): `aa_0074e0d0` LightMgr_SetActiveSlot3c_Refcount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e0d0` |
| **VA** | `0x0074e0d0`–`0x0074e107` exclusive (**55 B**) |
| **Canonical name** | `LightMgr_SetActiveSlot3c_Refcount_Inferred` |
| **Ghidra name** | `FUN_0074e0d0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AE) |
| **Counterpart** | `reviews/B_aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md` |
| **System** | Palantir light manager active slot |
| **Evidence pass** | Live Ghidra `decompile_function` + `get_function_by_address` + `get_xrefs_to` + `read_memory` (55 B body). **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Set `host[+0x3c]` to a new refcounted object (or null) with symmetric AddRef/Release via vtbl[+4]/[+8].

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AE append) | `docs/reconstruction/raw/aa_0074e0d0_FUN_0074e0d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e0d0_FUN_0074e0d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LightMgr_SetActiveSlot3c_Refcount_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0074e0d0.cpp` |
| Function records | `functions/aa_0074e0d0_FUN_0074e0d0.md`, `functions/aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md` |
| Live | decompile ≡ raw CF; 55 B hex; 3 CODE xrefs |
| Peers | W34-T TearDefaultLights; W32-R RebuildDefaultLights |

---

## 3. Signature (sealed)

```c
void __thiscall LightMgr_SetActiveSlot3c_Refcount_Inferred(void* host /*ECX*/, void* new_obj /*stack*/);
// RET 4
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX → EDI (`MOV EDI,ECX`) | **High** |
| new_obj | `[ESP+8]` → ESI | **High** |
| cleanup | `RET 4` (`C2 04 00`) | **High** |

---

## 4. Control flow (bytes authority)

```
if (new) { new.ref++; if (new.ref==1) new.vtbl[+4](); }
old = host[+0x3c]
if (old) { old.ref--; if (old.ref==0) old.vtbl[+8](); }
host[+0x3c] = new
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| AddRef-before-Release order | bytes + decompile | **High** |
| Slot +0x3c | `MOV [EDI+0x3C],ESI` | **High** |
| Null new skips AddRef | `TEST ESI` / `JZ` | **High** |
| Null old skips Release | `TEST ECX` / `JZ` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 55 B hex:

`568b74240885f6578bf9741183460401837e040175078b068bceff50048b4f3c85c9740b834104ff75058b11ff520889773c5f5ec20400`

Epilogue: `5F 5E C2 04 00`. Pad: `CC`.

**Decompile ≡ bytes** for CF and ABI.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers (3) | RebuildDefaultLights `0048f370`; TearDefaultLights `0048eb10` (arg 0); `00792600` Directional |
| Callees | virtual only |

---

## 7. Gaps

1. Product C++ class name for the light manager host (structural `_Inferred` kept).  
2. Exact product type of objects stored at +0x3c (light-related; peer uses `+0x8c` inner).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept** — body, ABI, refcount protocol, slot +0x3c, and light-domain callers sealed High; residual naming only (does not block port of the swap contract).
