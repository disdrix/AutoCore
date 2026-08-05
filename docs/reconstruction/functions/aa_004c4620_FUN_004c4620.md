# Function record: Object_PhysModeFromStoredTFID

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4620` |
| **Canonical name** | `Object_PhysModeFromStoredTFID` |
| **Ghidra name** | `FUN_004c4620` |
| **Address** | `0x004c4620`–`0x004c4658` (**57 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / TFID / phys mode |
| **Completion status** | **Dual-sealed 2026-07-29 W27-G** — raw append + annotated + clean + A/B |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Pure leaf: classify stored **TFID_16** at `object+0x108` into phys mode **0xB** (invalid/unassigned TFID) or **10** (assigned). No callees, no stores.

## Signature (sealed)

```c
// thiscall; RET 0; EAX = 0xB | 10
uint32_t Object_PhysModeFromStoredTFID(int this);
```

| Formal | Role | Conf |
|---|---|---|
| ECX `this` | Object owning TFID_16 @ +0x108 | **High** |
| return EAX | mode 0xB or 10 | **High** |

## Control flow

1. Point at `this+0x108`; load lo/hi/w2/(w3 unused for test).
2. If `(lo&hi)==~0 && (char)w2==0` → return **0xB**.
3. Else return **10**.

## Callers / callees

| Dir | Symbol | VA / note |
|---|---|---|
| Callees | none | leaf |
| Callers | (none static CALL) | DATA xref `0x009cbe8c` |

## Related siblings

| VA | Role |
|---|---|
| `0x004c4440` | Resolve path when TFID **valid** (inverse gate) |
| `0x004c4880` | Writes this mode to `phys+0x28` after TFID store |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c4620_FUN_004c4620.md` (+ W27-G append)
- Annotated: `docs/reconstruction/raw/aa_004c4620_FUN_004c4620.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_PhysModeFromStoredTFID.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c4620.cpp`
- Reviews: `A_aa_004c4620_Object_PhysModeFromStoredTFID.md`, `B_aa_004c4620_Object_PhysModeFromStoredTFID.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI thiscall RET 0 | **High** (bytes + decompile) |
| Mode 0xB vs 10 predicate | **High** (≡ 004c4880 writer) |
| Leaf / no side effects | **High** |
| Product English for modes | **Medium / residual** |
| Runtime | **Open** |
