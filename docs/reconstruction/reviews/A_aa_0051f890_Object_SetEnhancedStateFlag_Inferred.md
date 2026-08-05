# Review A (reconstruction fidelity): `aa_0051f890` Object_SetEnhancedStateFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f890` |
| **VA** | `0x0051f890`–`0x0051f89c` (13 B; pad `CC` after) |
| **Canonical name** | `Object_SetEnhancedStateFlag_Inferred` (Ghidra `FUN_0051f890`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W28-G) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` |
| **System** | object / character status |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Context: parent dual W27-F `Object_ActivatePlayerEnqueueHB_Inferred`; string/readers for `+0x6b9` from sibling units (not owned).

---

## 1. Purpose

**Leaf enhanced-state flag setter.** Write the single stack byte into `this+0x6b9` and return. No branches, no callees, no validation.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0051f890_FUN_0051f890.md` | Append re-verify |
| Annotated | `docs/reconstruction/raw/aa_0051f890_FUN_0051f890.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_SetEnhancedStateFlag_Inferred.cpp` | New |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_0051f890.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_0051f890_FUN_0051f890.md` | Updated |
| Live decompile | Ghidra @ `0x0051f890` | ≡ raw |
| Live bytes | `read_memory` 16 B | full leaf + pad |
| Xrefs / callers | `analyze_function_complete` | 2 code sites |

**Not performed:** Launcher, runtime golden, dual of parent activate / drive readers.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this (character/object)
// stack: uint8_t fEnhanced
// ret 4
// void
void Object_SetEnhancedStateFlag_Inferred(void *this, uint8_t fEnhanced);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | store via `[ecx+0x6b9]` | **High** |
| One stack byte | `mov al,[esp+4]` | **High** |
| Epilogue `ret 4` | `C2 04 00` | **High** |
| Offset `+0x6b9` | imm `B9 06 00 00` | **High** |
| Void (no EAX result use) | bare ret after store | **High** |
| Enhanced-state role | sibling string `"in your enhanced state."`; drive/skill/UI gates | **High** (role) |
| Product method spelling | structural only | **Inferred** |

---

## 4. Byte seal (`read_memory` @ `0x0051f890`)

```
0051f890  8A 44 24 04           mov al, [esp+4]
0051f894  88 81 B9 06 00 00     mov [ecx+0x6b9], al
0051f89a  C2 04 00              ret 4
0051f89d  CC…                   int3 pad
```

Hex body: `8a4424048881b9060000c20400`

---

## 5. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Load stack byte | **Yes** |
| Store `this+0x6b9` | **Yes** |
| `ret 4` | **Yes** |
| No branches / callees | **Yes** |

---

## 6. Call sites

| Site | Container | Arg | Role |
|---|---|---|---|
| `0x00626916` | `FUN_00626890` | `1` | set on player during activate |
| `0x0062667b` | **no** Ghidra function | `0` (bytes `push 0`) | clear; undelimited region |

---

## 7. Gaps / open

1. Product/PDB English for method name.
2. Full writer catalog beyond two static CALL sites.
3. Neighboring status bytes `+0x6b8/+0x6ba/+0x6bb` semantics (parent writes some).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept** — 13-byte CF + ABI + offset fully sealed; naming is structural `_Inferred` only.
