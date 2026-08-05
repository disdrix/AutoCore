# Function record: RefCountedSlot_ReleaseAndClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437150` |
| **Canonical name** | `RefCountedSlot_ReleaseAndClear` |
| **Prior scaffold** | `FUN_00437150` |
| **Address** | `0x00437150` |
| **Body** | `0x00437150`–`0x004371b3` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared intrusive-refcount smart slot / SEH cleanup |
| **Completion status** | **Dual A/B sealed** (W23-A, 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Prior human note: `Named_CalleeOf_Named_phyCPDefinition_00437150` — one consumer family only; not exclusive.

## Purpose

Release the object held in a **pointer slot** (`void**`): decrement intrusive refcount at `object+4`; if zero, call **vtbl+8**; then **clear the slot** to null. SEH-framed. Used as direct cleanup and as SEH unwind helper.

## Signature (machine-sealed)

```c
void __stdcall RefCountedSlot_ReleaseAndClear(void **slot);  /* RET 4 */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00437150_FUN_00437150.md`
- Annotated: `docs/reconstruction/raw/aa_00437150_FUN_00437150.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/RefCountedSlot_ReleaseAndClear.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00437150.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00437150_RefCountedSlot_ReleaseAndClear.md`
- Review B: `docs/reconstruction/reviews/B_aa_00437150_RefCountedSlot_ReleaseAndClear.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callees | indirect only: `obj->vtbl[+8]` |
| Callers | `Phy_CPConnectionPair_ReleaseClear` (`0x0044adc0`) ×2; `FUN_00439f00`; `Unwind@009b*`; `FUN_0095e3e0`; `FUN_00989850` |

## Confidence

| Claim | Level |
|---|---|
| stdcall + RET 4 + slot arg | **High** (bytes) |
| refcount @+4, vtbl+8 destroy | **High** (bytes) |
| *slot = 0 after phase1 | **High** |
| Phase2 always residual after clear | **High** for normal CF |
| Product type name of T | **Open** |
| vtbl+8 = COM Release vs delete | **Open** (role sealed as destroy-on-zero) |
