# Function record: Object_SetTFID_ApplyPhysMode_Rebind

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4880` |
| **Canonical name** | `Object_SetTFID_ApplyPhysMode_Rebind` |
| **Ghidra name** | `FUN_004c4880` |
| **Address** | `0x004c4880`–`0x004c48f1` (**114 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / TFID / phys rebind |
| **Completion status** | **Dual-sealed 2026-07-29 W26-F** — raw append + annotated + clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Store **TFID_16** (16 B) at `object+0x108`, then if phys child `object+8` is non-null set `phys+0x28` to mode **0xB** (invalid TFID) or **10** (assigned) and call **WorldObj_RebindActivate** (`FUN_00560e90`).

## Signature (sealed)

```c
// thiscall; RET 4
void Object_SetTFID_ApplyPhysMode_Rebind(int this, uint32_t src_tfid[4]);
```

| Formal | Role | Conf |
|---|---|---|
| ECX `this` | Object owning TFID @+0x108 and phys @+8 | **High** |
| stack `src_tfid` | Source 4×uint32 TFID_16 | **High** |
| return | void | **High** |

## Control flow

1. Copy `src[0..3]` → `this+0x108..+0x114`.
2. `phys = *(this+8)`; if null → return.
3. If `(tfid.lo & tfid.hi)==~0 && (char)tfid.w2==0` → `*(phys+0x28)=0xB` else `=10`.
4. `FUN_00560e90(phys, 1)` (manager ECX recovered in bytes; surface omits manager).

## Callers / callees

| Dir | Symbol | VA |
|---|---|---|
| Caller | `FUN_00626890` | call @ `0x0062690d` |
| Callee | `WorldObj_RebindActivate_Inferred` | `0x00560e90` |

## Related siblings

| VA | Role |
|---|---|
| `0x004c4440` | Load TFID_16 + `Object_ResolveFromTFID` when valid |
| `0x004c4620` | Pure mode leaf 0xB vs 10 (identical predicate) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c4880_FUN_004c4880.md` (+ W26-F append)
- Annotated: `docs/reconstruction/raw/aa_004c4880_FUN_004c4880.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_SetTFID_ApplyPhysMode_Rebind.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c4880.cpp`
- Reviews: `A_aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md`, `B_aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 4 thiscall | **High** (bytes + decompile) |
| TFID_16 @ +0x108 layout | **High** (sibling 004c4440) |
| Mode 10 vs 0xB predicate | **High** (sibling 004c4620 + body) |
| Rebind callee role | **High** (dual-sealed 00560e90) |
| Product English for modes | **Medium / residual** |
| Runtime | **Open** |
