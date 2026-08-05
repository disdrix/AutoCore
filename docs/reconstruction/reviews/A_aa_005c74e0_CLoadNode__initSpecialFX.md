# Review A (reconstruction fidelity): `aa_005c74e0` CLoadNode__initSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c74e0` |
| **VA** | `0x005c74e0`–`0x005c76ed` |
| **Canonical name** | `CLoadNode__initSpecialFX` |
| **Ghidra name** | `FUN_005c74e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-G) |
| **Counterpart** | `reviews/B_aa_005c74e0_CLoadNode__initSpecialFX.md` |
| **System** | client load / CLoadNode / special FX |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; caller `FUN_005c7cd0` |
| **Verdict** | **accept** |

---

## 1. Purpose

`CLoadNode::_initSpecialFX` — load-stage special FX init:

1. MI-adjust node; gate on feature byte `*(adj+0xA8)+0xF5` and hash `adj+0x74`.
2. Lock hash traversal (`+0x1d`).
3. For each entry: live `FUN_00542790(id,4,1,0…)` or offline map lookup + optional `FUN_004a6390` → return 0.
4. Unlock; clear stage flag `host+0x62`; return 1.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c74e0_FUN_005c74e0.md` (+ W23-G append) |
| Annotated | `docs/reconstruction/raw/aa_005c74e0_FUN_005c74e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initSpecialFX.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005c74e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c74e0_FUN_005c74e0.md` |
| Caller | `FUN_005c7cd0` |
| Live | string @ `0x009da074`; body 525 B; `C2 04 00`; ECX save; stack node load |

---

## 3. Signature (sealed)

```c
// RET 0x4
uint32_t CLoadNode__initSpecialFX(void* flagHost /*ecx*/, void* node /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| flagHost | ECX saved; `+0x62` cleared | **High** |
| node | stack0; MI +4 chain | **High** |
| return | EAX 1/0 | **High** |
| cleanup | `RET 0x4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Profiler string | **Yes** | **High** |
| MI adjust + feature gate | **Yes** | **High** |
| Hash lock / unlock +0x1d | **Yes** | **High** |
| Offline map + LoadMaster → 0 | **Yes** | **High** |
| Live FxCache_ApplyWithNfxEnsure | **Yes** | **High** |
| Clear host+0x62; return 1 | **Yes** (ECX residual filled) | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue:
```
6aff68296e9a00...81ec0c040000...894c24186874a09d00...8bbc242c0400008b47048b48048d0439...
```

Epilogue:
```
b801000000...c20400
```

---

## 6. Gaps

- English for `DAT_00d1f050+0x6c` mode.
- Full hash iterator type (`FUN_00411900`).
- Runtime / bit-exact.

Minor gaps only; primary CF/ABI/name sealed → **accept**.
