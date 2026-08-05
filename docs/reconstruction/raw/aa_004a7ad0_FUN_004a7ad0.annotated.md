# Annotated low-level: StdVector_InsertN_BasicStringW (`FUN_004a7ad0`)

| Field | Value |
|---|---|
| Stable ID | `aa_004a7ad0` |
| VA | `0x004a7ad0`–`0x004a7df7` exclusive (**807 B**) |
| System | MSVC `vector<basic_string<wchar_t>>` insert-n |
| Date | 2026-07-29 (W34-R) |

## Machine-level notes

- Source: raw capture + W34-R `read_memory` seal.
- Prefer assembly when decompiler conflicts — **bytes win** on RET / magic.
- **ABI:** `__thiscall` ECX=vec; stack where*, count, value*; **`C2 0C 00`**.
- **Stride 0x1c**, max **`0x9249249`**, growth **1.5×**.
- Wide twin of `StdVector_InsertN_BasicString` (`0x004306b0`).
- Reject scaffold `Named_CalleeOf_*` plate.

## Sealed algorithm

1. Local wstring copy of `*value` (IAT ctor, SEH `LAB_009a11e9`).
2. `count==0` → dtor local; return.
3. size/cap via `(end-begin)/0x1c` / `(capEnd-begin)/0x1c`.
4. `size+count > max` → `FUN_004a6820`.
5. Grow: 1.5× floor; new; relocate+fill; destroy-range + delete; rebind.
6. In-place: hole arm or mid-shift arm.
7. Dtor local; **RET 0x0C**.

## Callers

- `FUN_004a7ff0` @ `0x004a8043` — insert-one rebind (`count=1`).

## Pseudocode (annotated)

See raw W34-R append + clean `StdVector_InsertN_BasicStringW.cpp`.
