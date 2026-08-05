# Review A (reconstruction fidelity): `aa_004301f0` StringVec_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_004301f0` |
| **VA** | `0x004301f0`–`0x00430278` exclusive (**136 B**) |
| **Canonical name** | `StringVec_PushBack` |
| **Ghidra name** | `FUN_004301f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-D) |
| **Counterpart** | `reviews/B_aa_004301f0_StringVec_PushBack.md` |
| **System** | `vector<basic_string>` push_back (stride 0x1c) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 136 B) + nested `FUN_00431700` / `FUN_00430310` decompile for callee roles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Append exactly one `basic_string` element (stride `0x1c`) to a `StringVecShell`. Prefer in-place construction at `end` when capacity remains; otherwise delegate to `StringVec_InsertOne` at `end` (grow path).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-D append) | `docs/reconstruction/raw/aa_004301f0_FUN_004301f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004301f0_FUN_004301f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_PushBack.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004301f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004301f0_StringVec_PushBack.md` |
| Nested insert-one | `aa_00430310` (W32-A) |
| Nested grow | `FUN_004306b0` (W32-B) |
| Live | decompile + 136 B hex |

---

## 3. Signature (sealed)

```c
// __thiscall ECX=self; RET 0x04; void
void StringVec_PushBack(StringVecShell* self, const void* value_string);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F9`) | **High** |
| value | stack0 after reg saves (`[esp+0x10]`) | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
begin = [this+4]
size  = begin? (end-begin)/0x1c : 0
if begin != null AND size < (capEnd-begin)/0x1c:
  FUN_00431700(end, 1, value)   // cdecl; ADD ESP,0x14
  end += 0x1c
  ret 4
// else:
FUN_00430310(this, &out_scratch, end, value)  // @ 0x0043026d
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| thiscall EDI=this | `8B F9` | **High** |
| stride magic `/0x1c` | `B8 93 24 49 92` ×2 | **High** |
| count=1 on fast path | `6A 01` | **High** |
| call construct-n | `E8 B2 14 00 00` → `00431700` | **High** |
| call insert-one | `E8 9E 00 00 00` @ `0043026d` → `00430310` | **High** |
| RET 4 | `C2 04 00` ×2 epilogues | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (136 B) — see raw W33-D append.

Entry: `53 56 57 8B F9`.  
Epilogues: `5F 5E 5B C2 04 00` (both paths).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | path/listing push sites (`FUN_009839b0`, `FUN_009841d0`, `FUN_00984340`, `FUN_009697a0`, …) |
| Callees | `FUN_00431700`, `FUN_00430310` |

---

## 7. Gaps

1. Nested `FUN_00431700` product English / dual not owned.  
2. Product/MSVC demangle for exact `push_back` plate.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

CF, ABI, capacity gate, and dual-path push_back sealed against full-body hex and prior insert-one dual → **accept-with-gaps**.
