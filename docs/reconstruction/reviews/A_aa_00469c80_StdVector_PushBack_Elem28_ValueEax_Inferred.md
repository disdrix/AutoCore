# Review A (reconstruction fidelity): `aa_00469c80` StdVector_PushBack_Elem28_ValueEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469c80` |
| **VA** | `0x00469c80`–`0x00469d04` exclusive (**132 B**) |
| **Canonical name** | `StdVector_PushBack_Elem28_ValueEax_Inferred` |
| **Ghidra name** | `FUN_00469c80` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-C) |
| **Counterpart** | `reviews/B_aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` |
| **System** | MSVC `vector::push_back`, POD elem **0x1c** |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full body) + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Append one POD-0x1c element to a three-pointer vector (`begin/end/cap_end` at +4/+8/+c). Spare capacity uses sealed fill-n count=1; full capacity uses sealed insert-one-at-end.

Closes W36-Q residual: parent of `00469e20` was unowned; also sole single-append parent of `0046a260` noted in W36-M.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-C append) | `docs/reconstruction/raw/aa_00469c80_FUN_00469c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00469c80_FUN_00469c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem28_ValueEax_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00469c80.cpp` |
| Function record | `docs/reconstruction/functions/aa_00469c80_StdVector_PushBack_Elem28_ValueEax_Inferred.md` |
| Fill-n dual | W36-M `aa_0046a260` |
| Insert-one dual | W36-Q `aa_00469e20` |
| Live | decompile ≡ scaffold CF; body hex 132 B; 3 callers |

---

## 3. Signature (sealed)

```c
// ECX=vec*, EAX=value*; bare RET
void StdVector_PushBack_Elem28_ValueEax_Inferred(
    StdVectorElem28* vec,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | **ECX** → `mov edi,ecx` | **High** |
| value* | **EAX** → `mov ebx,eax` | **High** |
| cleanup | `C3` @ end of both paths | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| size via `/0x1c` magic `0x92492493` | decompile + bytes | **High** |
| spare: fill-n count=1 at end, end+=0x1c | `B9 01…` + call `0046a260` + `83 C6 1C` | **High** |
| full: insert-one EDI=vec, where=end, value* | push EBX/where/outIt + call `00469e20` | **High** |
| Live decompile ≡ raw scaffold | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (132 B) — raw W37-C append.

Entry: `51 53 55 56 57 8B F9 8B 6F 04 85 ED 8B D8 …`  
Fast call site: `B9 01 00 00 00 8B C6 E8 80 05 00 00` → `0046a260`.  
Slow call site: `53 50 8D 4C 24 18 51 E8 22 01 00 00` → `00469e20`.  
Both epilogues: `5F 5E 5D 5B 59 C3`. Pad `CC` @ `0x00469d04`.

---

## 6. Gaps

- Product T English / PDB demangle.
- Caller-side container product names (`0071a4a0` / `00983350` / `009847c0` not OWN).
- Dead stack push of vec before fill-n (cleaned `add esp,4`; fill-n register-only per W36-M).
- Runtime / bit-exact / differential.

---

## Verdict

**accept-with-gaps** — push_back router ABI/CF sealed against dualed fill-n + insert-one; POD family (not RC).
