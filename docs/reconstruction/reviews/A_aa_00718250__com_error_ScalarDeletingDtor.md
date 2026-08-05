# Review A (reconstruction fidelity): `aa_00718250` `_com_error_ScalarDeletingDtor`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00718250` |
| **VA** | `0x00718250` |
| **Body span** | `00718250`–`0071827b` exclusive (43 B) |
| **Canonical name** | `FUN_00718250` / `_com_error_ScalarDeletingDtor` |
| **System** | `crt-com` / MSVC COM support (`comdef` / `_com_error`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W25-P) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00718250__com_error_ScalarDeletingDtor.md` |
| **Dual status** | **Present (first dual seal)** |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + xrefs + callees |
| **Verdict** | **accept** — library scalar deleting dtor sealed; not game logic |

---

## 1. Purpose

MSVC `_com_error` **scalar deleting destructor** (vftable slot0):

1. Call body virtual dtor `_com_error::~_com_error` @ `0x007182e0`
2. If `(flags & 1) != 0` → `operator_delete(this)`
3. Return `this` in EAX

Does **not** implement Release/LocalFree itself — that is the body dtor dual (`aa_007182e0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00718250_FUN_00718250.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_00718250_FUN_00718250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/_com_error_ScalarDeletingDtor.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00718250.cpp` |
| Function records | `functions/aa_00718250_FUN_00718250.md`, `functions/aa_00718250__com_error_ScalarDeletingDtor.md` |
| Live decompile | Ghidra `FUN_00718250` → `~_com_error` + conditional `operator_delete` |
| Sibling | `A_aa_007182e0__com_error_dtor.md` (body dtor; predicted this VA) |

---

## 3. Seal: body bytes + CF (High)

Body range: **`00718250`–`0071827b`**.

`read_memory` @ `0x00718250`:

```
55 8B EC 51 89 4D FC             ; prologue; this → [ebp-4]
8B 4D FC E8 81 00 00 00          ; call 0x007182e0  (~_com_error)
8B 45 08 83 E0 01 74 0C          ; if ((flags & 1) == 0) skip
8B 4D FC 51 E8 … 83 C4 04        ; operator_delete(this); add esp,4
8B 45 FC 8B E5 5D C2 04 00       ; return this; ret 4
CC …
```

Hex (executed body):

```
558bec51894dfc8b4dfce8810000008b450883e001740c8b4dfc51e8b215d7ff83c4048b45fc8be55dc20400
```

| Claim | Evidence | Conf |
|---|---|---|
| Call body dtor `007182e0` | rel32 `E8 81 00 00 00` from `0071825f` | **Confirmed** |
| Conditional `operator_delete` on bit0 | `83 E0 01` / `74 0C` | **Confirmed** |
| Return this | `8B 45 FC` before leave | **Confirmed** |
| thiscall + `ret 4` | `C2 04 00` | **Confirmed** |
| Vftable slot0 | dword @ `00a14034` = `00718250` | **Confirmed** |
| Clean ≡ raw ≡ live | three-rep | **High** |
| Not game domain | CRT COM | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name / role = scalar deleting dtor | **Confirmed** | bytes + vftable + MSVC shape |
| Body dtor is sibling `007182e0` | **Confirmed** | callees + rel call |
| Decomp “does not return” on delete | **Residual / falsified as fatal** | control returns; EAX set |
| Port for server | **N/A** | client COM |

---

## 5. Xrefs / callees

- **DATA:** `0x00a14034` → this (vftable slot0)
- **Callees:** `~_com_error` @ `007182e0`; `operator_delete` @ `00489822` family

---

## 6. Gaps

1. Runtime / bit-exact deferred.
2. No vector-deleting (`flags & 2` array) path on this VA — expected for scalar-only slot.

**Verdict:** **accept** — sealed MSVC `_com_error` scalar deleting dtor; dual complete for OWN unit.
