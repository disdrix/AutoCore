# Review A (reconstruction fidelity): `aa_0040aff0` Object_CopyTfid16At228_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040aff0` |
| **VA** | `0x0040aff0`–`0x0040b016` |
| **Canonical name (Ghidra)** | `FUN_0040aff0` |
| **Proposed name** | `Object_CopyTfid16At228_Inferred` |
| **Review date** | `2026-08-04` (WQ9R-B OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0040aff0_Object_CopyTfid16At228_Inferred.md` |
| **System** | identity / TFID |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **TFID_16 out-copy** from object field **`+0x228`**. Not equality (`TFID_EqualsObjectId`), not resolve (`Object_ResolveFromTFID`), not position (`Object_GetWorldPositionPtr`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `decompile_function` @ `0x0040aff0` |
| Bytes | `read_memory` 48 B @ entry |
| Meta | `get_function_by_address` body `0040aff0`–`0040b016` |
| Callers | `get_function_callers` / `get_function_xrefs` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0040aff0` |
| Peer duals | `TFID_EqualsObjectId` `aa_00404aa0`; identity climb notes `aa_004bb070` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Signature

```c
TFID_16* __thiscall Object_CopyTfid16At228_Inferred(void *thisObj, TFID_16 *out);
// ret 4; EAX = out
```

| Item | Evidence |
|---|---|
| Convention | `ret 4` @ end of body |
| Offset | `add ecx, 0x228` |
| Width | four `mov` dword pairs → 16 B |
| Leaf | no CALL in body |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Four dword copy +0x228..+0x234 | Yes |
| No branches | Yes |
| No callees | Yes |
| ret 4 | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 16 B copy from +0x228 | **High** | bytes + decompile |
| Out buffer = TFID_16 role | **High** | callers feed TFID_* |
| Product English name | **Tentative** | `_Inferred` |
| Exact RTTI of `this` | **Probable** | identity/object with TFID@228 |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. Full formal type of `this` without caller-specific cast.  
3. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/offset High; name role-sealed Inferred.
