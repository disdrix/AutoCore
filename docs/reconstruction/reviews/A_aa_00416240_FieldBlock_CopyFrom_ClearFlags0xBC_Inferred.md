# Review A (reconstruction fidelity): `aa_00416240` FieldBlock_CopyFrom_ClearFlags0xBC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416240` |
| **VA** | `0x00416240`–`0x0041625d` exclusive (**29 B** / `0x1D`) |
| **Canonical name** | `FieldBlock_CopyFrom_ClearFlags0xBC_Inferred` |
| **Ghidra name** | `FUN_00416240` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9I-H) |
| **Counterpart** | `reviews/B_aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md` |
| **System** | field-block selective assign wrapper |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thiscall wrapper: zero dest flag dword at **`+0xBC`**, then call selective field-block copy `FUN_00416160(dest, src)`, return dest. Used by object nested-block swap (`FUN_00833160`) and a mesh-related path (`FUN_00634c50`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9I-H append) | `docs/reconstruction/raw/aa_00416240_FUN_00416240.md` |
| Annotated | `docs/reconstruction/raw/aa_00416240_FUN_00416240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00416240.cpp` |
| Function record | `docs/reconstruction/functions/aa_00416240_FieldBlock_CopyFrom_ClearFlags0xBC_Inferred.md` |
| Callee (not OWN) | `FUN_00416160` @ `0x00416160` (WQ9I-G) |
| Live | decompile ≡ 29 B hex; RET 4 sealed |

---

## 3. Signature (sealed)

```c
// ECX=dest; stack src; RET 4; returns dest*
void* __thiscall FieldBlock_CopyFrom_ClearFlags0xBC_Inferred(void* dest, const void* src);
```

| Formal | Source | Conf |
|---|---|---|
| dest | ECX (`8B F1` after PUSH ESI) | **High** |
| src | stack (`8B 44 24 04` / PUSH EAX) | **High** |
| return | EAX = ESI = dest | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
EAX = src
ESI = dest
PUSH src
[dest+0xBC] = 0
CALL FUN_00416160   // thiscall ECX=dest
return dest         // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Clear flags then copy | decompile ≡ 29 B hex | **High** |
| Single callee | `FUN_00416160` only | **High** |
| Return dest | `MOV EAX,ESI` | **High** |
| 2 call sites | `00634ce5`, `00833249` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (29 B):

```
8b442404568bf150c786bc00000000000000e809ffffff8bc65ec20400
```

Pad `CC CC CC` then next unit.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper |
| Callers | `FUN_00634c50` @ `0x00634ce5`; `FUN_00833160` @ `0x00833249` |
| Callees | `FUN_00416160` |
| Caller pattern | temp dest + src push; swap path pairs with raw `FUN_00416160` |

---

## 7. Gaps

1. Product English for ~0xC0 field-block (scaffold shopveh/phySkeleton names unproven at this VA).  
2. Full flag-bit map lives in undualed-here `FUN_00416160` (WQ9I-G).  
3. Pre-clear vs overwrite interaction product intent open.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI/CF, clear `+0xBC` + `FUN_00416160` + RET 4 + 2 callers sealed. Residual product layout + callee dual → **accept-with-gaps**.
