# Function record: FourCCFnPtrMap_TryInsert_DAT_00d21958

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444850` |
| **Canonical name** | `FourCCFnPtrMap_TryInsert_DAT_00d21958` |
| **Ghidra name** | `FUN_00444850` |
| **Address** | `0x00444850`–`0x00444874` exclusive (**36 B** / `0x24`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir FourCC→handler registry |
| **Completion status** | **Dual-sealed W35-H** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | wrapper |

## Alias

- Ghidra: `FUN_00444850`
- Reject scaffold: `Named_CalleeOf_Named_Palantir_00444850` as exclusive product English (caller is Palantir, unit is generic map insert)

## Purpose

Register a **FourCC → function pointer** into global tree-map **`DAT_00d21958`** via `FUN_00458510` (find / insert-if-absent). Discards the out-pair. Used during Palantir device start for `'EFCT'` and `'MRPH'`.

## Signature (sealed)

```c
// EAX=FourCC; ECX=handler*; bare RET; void
void FourCCFnPtrMap_TryInsert_DAT_00d21958(
    /*eax*/ uint32_t tag,
    /*ecx*/ void* handler);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00444850_FUN_00444850.md`
- Annotated: `docs/reconstruction/raw/aa_00444850_FUN_00444850.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FourCCFnPtrMap_TryInsert_DAT_00d21958.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00444850.cpp`
- A: `docs/reconstruction/reviews/A_aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md`
- B: `docs/reconstruction/reviews/B_aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md`
- Scratch: `docs/reconstruction/tmp/a_00444850.md`

## Callers / callees

| Dir | Target |
|-----|--------|
| Caller | `FUN_00754680` @ `0x0075482f` (`'EFCT'`→`0x00990540`), `@ 0x0075483e` (`'MRPH'`→`0x009906e0`) |
| Callee | `FUN_00458510` |
| Map | `DAT_00d21958` |
| Sibling | `FUN_00444880` → map `DAT_00d21964` |

## Confidence

| Claim | Level |
|---|---|
| EAX tag + ECX handler | **High** (caller sites) |
| Map `DAT_00d21958` | **High** |
| Insert side-effect / discard out | **High** |
| Callee full tree semantics | Residual |
| Product map English | Low |

## Gaps

1. Unowned `FUN_00458510` / node layout dual.
2. Value-update-on-hit policy.
3. Handler function product names.
4. Runtime / bit-exact.

