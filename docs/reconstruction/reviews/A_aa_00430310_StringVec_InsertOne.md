# Review A (reconstruction fidelity): `aa_00430310` StringVec_InsertOne

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430310` |
| **VA** | `0x00430310`–`0x00430383` exclusive (**115 B**) |
| **Canonical name** | `StringVec_InsertOne` |
| **Ghidra name** | `FUN_00430310` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-A) |
| **Counterpart** | `reviews/B_aa_00430310_StringVec_InsertOne.md` |
| **System** | `vector<basic_string>` insert-one (stride 0x1c) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 115 B) + nested `FUN_004306b0` decompile for callee role. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert exactly one `basic_string` element (stride `0x1c`) at a given position in a `StringVecShell`, then write an iterator to the inserted element into an out-parameter. Index is captured before nested insert so the iterator survives reallocation.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-A append) | `docs/reconstruction/raw/aa_00430310_FUN_00430310.md` |
| Annotated | `docs/reconstruction/raw/aa_00430310_FUN_00430310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_InsertOne.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00430310.cpp` |
| Function record | `docs/reconstruction/functions/aa_00430310_StringVec_InsertOne.md` |
| Parent dual | `aa_00969830` (push_front uses this at begin) |
| Nested | `FUN_004306b0` (W32-B) insert-N / grow |
| Live | decompile + 115 B hex |

---

## 3. Signature (sealed)

```c
// __thiscall ECX=self; RET 0x0C; void
void StringVec_InsertOne(StringVecShell* self,
                         uint8_t** out_iterator,
                         uint8_t* pos,
                         const void* value_string);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F9`) | **High** |
| out_iterator | stack0 (`[esp+…]` store `89 08`) | **High** |
| pos | stack (EBX load from `[esp+0x0C]` at entry) | **High** |
| value | stack (pushed before call to `FUN_004306b0`) | **High** |
| cleanup | `C2 0C 00` | **High** |

---

## 4. Control flow (bytes authority)

```
begin = [this+4]
if begin==null OR (end-begin)/0x1c==0:
  index = 0
else:
  index = (pos-begin)/0x1c
FUN_004306b0(this, pos, count=1, value)   // may realloc
*out = [this+4] + index*0x1c
ret 12
```

| Stage | Match | Conf |
|---|---|---|
| thiscall EDI=this | `8B F9` | **High** |
| stride magic `/0x1c` | `B8 93 24 49 92` + `SAR 4` | **High** |
| count=1 | `6A 01` | **High** |
| call grow insert | `E8 48 03 00 00` → `004306b0` | **High** |
| out rebuild | `8B 47 04` + `lea` scale | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (115 B) — see raw W32-A append.

Entry: `53 8B 5C 24 0C 56 57 8B F9`.  
Epilogue: `C2 0C 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004301f0` (insert at end when cap full); `FUN_00969830` (insert at begin) |
| Callees | `FUN_004306b0` |

---

## 7. Gaps

1. Nested `FUN_004306b0` dual owned by W32-B — grow math not re-sealed here.  
2. Product English for the path-list container.  
3. Ghidra typed `param_4` as bare `undefined4` — clean uses `const void*` / string*.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

thiscall ABI, single-element insert, 0x1c stride, and post-realloc iterator rebuild are sealed. Nested grow + product English open → **accept-with-gaps**.
