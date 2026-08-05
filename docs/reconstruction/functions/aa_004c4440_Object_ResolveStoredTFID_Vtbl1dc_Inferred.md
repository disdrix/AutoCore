# Function record: Object_ResolveStoredTFID_Vtbl1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4440` |
| **Canonical name** | `Object_ResolveStoredTFID_Vtbl1dc_Inferred` |
| **Ghidra name** | `FUN_004c4440` |
| **Address** | `0x004c4440`–`0x004c44bc` (**125 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / TFID resolve / vtbl query |
| **Completion status** | **Dual-sealed 2026-07-29 W27-G** — raw append + annotated + clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

If stored **TFID_16** at `object+0x108` is **not** the shared invalid pattern, resolve it via **`Object_ResolveFromTFID`** (manager ctx in ECX) and invoke the resolved object's virtual at **vtbl+0x1dc**. Return that result when nonzero; else **0**.

## Signature (sealed)

```c
// thiscall; RET 0; EAX = 0 | vtbl+0x1dc result
int Object_ResolveStoredTFID_Vtbl1dc_Inferred(int this);
```

| Formal | Role | Conf |
|---|---|---|
| ECX `this` | Object owning TFID_16 @ +0x108 | **High** |
| return EAX | 0 or result of resolved→vtbl+0x1dc | **High** |

## Control flow

1. Load TFID dwords at `this+0x108..+0x114`.
2. If `(lo&hi)==~0 && (char)w2==0` → return **0** (invalid).
3. Else copy TFID_16 local; rebuild resolve ctx (`+0xA8` / `+0xE4E8`); `Object_ResolveFromTFID`.
4. If obj non-null: `r = obj->vtbl[+0x1dc]()`; if `r!=0` return `r`.
5. Return **0**.

## Callers / callees

| Dir | Symbol | VA / note |
|---|---|---|
| Callee | `Object_ResolveFromTFID` | `0x004bb950` (call @ `0x004c449d`) |
| Callers | (none static CALL) | DATA xrefs `0x009cbf30`, `0x009cfe50` |

## Related siblings

| VA | Role |
|---|---|
| `0x004c4620` | Pure mode leaf 0xB vs 10 (same invalid predicate) |
| `0x004c4880` | Store TFID + write mode + WorldObj rebind |
| `0x004bb950` | TFID → object* unwrap (dual-sealed) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c4440_FUN_004c4440.md` (+ W27-G append)
- Annotated: `docs/reconstruction/raw/aa_004c4440_FUN_004c4440.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ResolveStoredTFID_Vtbl1dc_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c4440.cpp`
- Reviews: `A_aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md`, `B_aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI thiscall RET 0 | **High** (bytes + decompile) |
| TFID_16 @ +0x108 layout | **High** (Ghidra type + siblings) |
| Invalid predicate family | **High** (≡ 004c4620 / 004c4880) |
| Callee Object_ResolveFromTFID | **High** (rel32 → 0x004bb950) |
| Manager ECX residual vs surface | **High** (bytes; known 004bb950 contract) |
| Product English for vtbl+0x1dc | **Medium / residual** |
| Runtime | **Open** |
