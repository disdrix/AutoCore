# Function record: Object_CopyTfidVectorAtE7f8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e5810` |
| **Canonical name** | `Object_CopyTfidVectorAtE7f8_Inferred` |
| **Ghidra name** | `FUN_004e5810` |
| **Address** | `0x004e5810`–`0x004e5833` exclusive (**35 B** / `0x23`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer — materialize object TFID vector @ `+0xe7f8` |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/callers/offset sealed; product demangle + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md`, `reviews/B_aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md` (2026-08-05 R13-026) |
| **Last reviewed** | `2026-08-05` |
| **Runtime Confirmed** | **Never claimed** |
| **Partition** | R13-026; parent dual `0x0052eb90`; dual start 2686; Terminal **false** |

## Alias

- `FUN_004e5810` (Ghidra / scaffold)
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_004e5810` (**retired** — chain-of-caller plate)

## Purpose

**Thin thiscall wrapper** on a host object: copy-construct a caller-owned `std::vector`-style shell from the member at **`this+0xe7f8`** (8-byte TFID pair elements). Returns the out shell. Callers use the copy to count elements (`(end-begin)>>3`) and index TFID pairs for `CVOGReaction_ResolveObjectTarget`.

## Signature

```c
// Machine: __thiscall, ECX=Object*, stack VectorU64Shell* out, EAX=out, RET 4
VectorU64Shell *__thiscall Object_CopyTfidVectorAtE7f8_Inferred(
    void *self, VectorU64Shell *out);
```

## Algorithm

```
src = self + 0xe7f8
FUN_004e53e0(out, src)   // vector copy-construct, elem size 8
return out
RET 4
```

## Offsets / constants

| Item | Role | Conf |
|---|---|---|
| `self+0xe7f8` | source TFID pair vector member | **High** (`ADD ECX,0xe7f8`) |
| vector `+4/+8/+0xc` | begin / end / capacity (via callee + callers) | **High** |
| elem stride **8** | `(end-begin)>>3` at all 4 call sites | **High** |
| `RET 4` / thiscall | ABI | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e5810_FUN_004e5810.md`
- Annotated: `docs/reconstruction/raw/aa_004e5810_FUN_004e5810.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_CopyTfidVectorAtE7f8_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004e5810.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004e5810_FUN_004e5810.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e5810-r13-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x0052eb90` @ `0052ec12`, `0052ec6b` | `Character_Craft_HasMatchingStationInRange_Inferred` (parent dual R12-021) |
| Caller | `0x004dd940` @ `004ddb67`, `004ddbb7` | station subtype TFID walk (`0xD/0xE/0xF` → `FUN_004db740`) |
| Callee | `0x004e53e0` | vector copy-construct worker (8-byte elems) |

## Confidence

| Claim | Level |
|---|---|
| Body 35 B + RET 4 + thiscall | **High** (bytes) |
| Offset `+0xe7f8` source | **High** |
| Returns out shell | **High** |
| TFID 8-byte pair elem (from caller SAR 3 + resolve) | **High** (structural) |
| Product English for member | **Open** → `_Inferred` |
| Runtime / bit-exact / diff | **Open** |
