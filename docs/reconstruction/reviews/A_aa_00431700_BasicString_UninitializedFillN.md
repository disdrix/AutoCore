# Review A (reconstruction fidelity): `aa_00431700` BasicString_UninitializedFillN

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431700` |
| **VA** | `0x00431700`–`0x0043178c` exclusive (**140 B** / `0x8C`) |
| **Canonical name** | `BasicString_UninitializedFillN` |
| **Ghidra name** | `FUN_00431700` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-H) |
| **Counterpart** | `reviews/B_aa_00431700_BasicString_UninitializedFillN.md` |
| **System** | MSVC-style uninit_fill_n for `basic_string` (stride `0x1c`) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 140 B) + xrefs + IAT `read_memory` + `_CxxThrowException` decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

SEH-protected loop: construct `count` `basic_string` copies from one `value` into uninitialized storage at `dest`, stride **0x1c**. Nested body of string-vector fill/push helpers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-H append) | `docs/reconstruction/raw/aa_00431700_FUN_00431700.md` |
| Annotated | `docs/reconstruction/raw/aa_00431700_FUN_00431700.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/BasicString_UninitializedFillN.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431700.cpp` |
| Function records | `functions/aa_00431700_FUN_00431700.md`, named twin |
| Callers | W33-D `StringVec_PushBack`; W33-G `StdUninitFillN_BasicString` |
| IAT | `[0x009c62ec]`→`0x006ead80` copy-ctor; `[0x009c62f4]`→`0x006eace6` dtor |
| Live | decompile happy-path ≡ bytes; bare `C3`; EH residual in bytes |

---

## 3. Signature (sealed — call-site + bytes win)

```c
// cdecl bare C3. Callers: 5 pushes + ADD ESP,0x14. Body uses dest/count/value.
void BasicString_UninitializedFillN(
    BasicString_0x1c* dest,   // [ebp+8]
    int count,                // [ebp+0xc]
    const BasicString_0x1c* value // [ebp+0x10]
    /* , void* alloc, const BasicString_0x1c* value_echo — unused in body */);
```

| Formal | Source | Conf |
|---|---|---|
| dest / count / value | `[ebp+8/+0xc/+0x10]` | **High** |
| cdecl bare C3 | epilog `C3` | **High** |
| 5-arg call-site residue | parent `ADD ESP,0x14` | **High** |
| return void | no EAX produce | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH prolog LAB_009bc2c1
if count==0: goto done
loop:
  state = constructing
  if dest != null: IAT copy-ctor(dest, value)
  count--; dest += 0x1c
  state = idle
  if count: loop
done:
SEH epilog; ret   // C3

// EH residual:
// destroy [start, dest) via IAT dtor stride 0x1c
// _CxxThrowException(0, 0)
```

| Stage | Match | Conf |
|---|---|---|
| count loop + 0x1c stride | **Yes** | **High** |
| null-dest skip construct | **Yes** | **High** |
| IAT copy-ctor | **Yes** (`FF 15 EC 62 9C 00`) | **High** |
| EH dtor + rethrow | **Yes** (bytes; decompile omits residual) | **High** |
| Decompiler 3-arg is complete ABI story | **No** — callers pass 5 | **High** (call-site) |

---

## 5. Gaps

- Product demangle (`std::_Uninit_fill_n` / allocator English).
- Exact purpose of unused 4th/5th formals at call sites.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals cdecl body, 0x1c fill loop, IAT copy/dtor, EH rethrow, and caller linkage. Product demangle residual → **accept-with-gaps**.
