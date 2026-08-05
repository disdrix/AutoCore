# Function record: Vector_InsertN_0x10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbfc0` |
| **Canonical name** | `Vector_InsertN_0x10` |
| **Ghidra name** | `FUN_004cbfc0` |
| **Address** | `0x004cbfc0`–`0x004cc21c` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC STL / POD vector insert (stride 0x10) |
| **Completion status** | **Dual A/B sealed (W25-M)** — raw append + annotated + clean + reviews |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004cbfc0`
- Prior scaffold alias chain (ignore for naming): `Named_CalleeOf_…_004cbfc0`
- Role: `std::vector<T>::_Insert_n` for `sizeof(T)==16`

## Purpose

Insert `count` copies of a 16-byte value at `insertAt` in a begin/end/cap vector (`+4/+8/+0xc`), reallocating with 1.5× growth when needed; throw `"vector<T> too long"` on size overflow.

## Signature (sealed)

```c
void __thiscall Vector_InsertN_0x10(
    void* this,           // vector object*
    void* insertAt,
    unsigned count,
    const void* value);   // 16-byte POD*; ret 0xc
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cbfc0_FUN_004cbfc0.md` (+ W25-M append)
- Annotated: `docs/reconstruction/raw/aa_004cbfc0_FUN_004cbfc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vector_InsertN_0x10.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004cbfc0.cpp`
- Dual: `reviews/A_aa_004cbfc0_Vector_InsertN_0x10.md`, `reviews/B_aa_004cbfc0_Vector_InsertN_0x10.md`
- Scaffold record: `functions/aa_004cbfc0_FUN_004cbfc0.md`

## Callers / callees

| Direction | Target |
|---|---|
| Callers | `FUN_006061e0` (CVOGHBWakeupSkill_ctor), `FUN_004cc470`, `FUN_005de1b0`, `FUN_005dcc40` |
| Callees | `FUN_004cb1d0`, `operator_new`/`delete`, `FUN_005dd920`, `FUN_00608720`, `FUN_0041d5a0`, `FUN_004cb2e0`, `FUN_0051b6e0` |

## Confidence

| Claim | Level |
|---|---|
| Layout +4/+8/+0xc; stride 0x10 | **High** |
| Grow 1.5× + forced fit | **High** |
| Throw string `vector<T> too long` | **High** (`FUN_004cb1d0`) |
| ABI thiscall + ret 0xc | **High** |
| Product element type English | **Open** (often TFID-sized at sites) |
