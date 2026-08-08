# Function record: StdVector_InsertN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004082f0` |
| **Canonical name** | `StdVector_InsertN_Elem12_Inferred` |
| **Ghidra name** | `FUN_004082f0` |
| **Address** | `0x004082f0` |
| **Body range** | `0x004082f0` – `0x00408587` (**663 B** / `0x297`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **thiscall** ECX=`VecPod12*`; stack `Pod12* where`, `uint count`, `const Pod12* value`; **`ret 0xC`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9H-B 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_004082f0_StdVector_InsertN_Elem12_Inferred.md` |
| **Dual B** | `reviews/B_aa_004082f0_StdVector_InsertN_Elem12_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9H-B) |

## Alias

- Ghidra: `FUN_004082f0`
- Scaffold record: `functions/aa_004082f0_FUN_004082f0.md`
- Reject: domain-specific names — generic POD InsertN for elem 0xC

## Purpose

MSVC-style `std::vector<T>::_Insert_n` (inferred) for **12-byte POD**: insert `count` copies of `*value` at iterator `where`. Capacity triad at `+4/+8/+0xC`. Growth **1.5×** then exact-fit floor. Max elems **`0x15555555`**.

## Signature

```c
void __thiscall StdVector_InsertN_Elem12_Inferred(
    VecPod12 *this,
    Pod12 *where,
    uint32_t count,
    const Pod12 *value);
/* ret 0xC */
```

## Behavioral summary

1. Snap `*value` three dwords into locals (alias-safe during realloc).
2. If `count==0` return.
3. If `size+count` overflows max → `FUN_00418130`.
4. If capacity insufficient: grow 1.5× or `size+count`; `operator_new`; uninit_copy prefix; Ufill N; uninit_copy suffix; delete old; rebind triad; return.
5. Else in-place: near-end path (tail < count) or far path (copy_backward + assign-fill).

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | uninit_copy `00409b40`/`0040a590`; Ufill `00406ee0` (WQ9G-I); copy_backward `00480fb0`; assign-fill `0042ac90`; size `00480c80`; overflow `00418130`; new/delete |
| **Callers** | `FUN_00406e70` InsertOne rebind only (1 UNCONDITIONAL_CALL) |
| **Wrapper** | `aa_00406e70` forces count=1 then rebinds out-iterator by saved index |
| **Twins** | `00408050` InsertN 0x28; `004073a0`/`00419880` InsertN dword |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004082f0_FUN_004082f0.md` (+ WQ9H-B append)
- Annotated: `docs/reconstruction/raw/aa_004082f0_FUN_004082f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem12_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004082f0.cpp`

## Confidence

| Claim | Level |
|---|---|
| Body size + ret 0xC | **Confirmed** |
| thiscall + triad + stride 0xC | **Confirmed** |
| 1.5× growth CF | **Confirmed** |
| Three-way relocate on grow | **Confirmed** |
| In-place dual sub-cases | **Confirmed** (CF; helper packing High) |
| Sole caller InsertOne | **Confirmed** (1 xref) |
| Product demangle | **Inferred** |
| Runtime / bit-exact | **Open** |
