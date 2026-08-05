# Review A (reconstruction fidelity): `aa_00754320` Palantir_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754320` |
| **VA** | `0x00754320`–`0x007543A9` exclusive (**137 B**) |
| **Canonical name** | `Palantir_CompleteDtor` |
| **Ghidra name** | `FUN_00754320` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-K) |
| **Counterpart** | `reviews/B_aa_00754320_Palantir_CompleteDtor.md` |
| **System** | client / Palantir host complete destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 137 B) + vtbl peer decompile (`0x00754480`) + scalar wrapper (`0x004447e0`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC complete destructor for the Palantir host object: install dtor-phase vtbl, destroy string at `+0xB4`, tidy path shell at `+0xA0` and clear `DAT_00d1f1fc`, destroy nested subobjects at `+0x30` and `+0x10`, clear host global `DAT_00d1f058`. Does **not** free `this` (scalar wrapper `FUN_004447e0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-K append) | `docs/reconstruction/raw/aa_00754320_FUN_00754320.md` |
| Annotated | `docs/reconstruction/raw/aa_00754320_FUN_00754320.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_CompleteDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00754320.cpp` |
| Function records | `functions/aa_00754320_FUN_00754320.md`, `functions/aa_00754320_Palantir_CompleteDtor.md` |
| Path-list helper | `aa_00444810` StringVecShell_TidyAndClearGlobal |
| Nested tidy | `StringVec_Tidy` W33-D |
| Live | decompile + 137 B hex + vtbl + scalar dtor |

---

## 3. Signature (sealed)

```c
// ECX=this; bare RET; void; no operator_delete
void Palantir_CompleteDtor(Palantir* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| cleanup | `C3` | **High** |
| stack args | none | **High** |
| free this | not in body (wrapper `FUN_004447e0`) | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = ECX
[self] = PTR_FUN_00a9f76c
~basic_string(self+0xB4)           // IAT
StringVec_Tidy(self+0xA0)          // LEA ECX,[ESI+0xA0]
DAT_00d1f1fc = 0
FUN_0075d8e0(self+0x30)            // PUSH; CALL cdecl
FUN_00964d00(self+0x10)            // PUSH; CALL cdecl
DAT_00d1f058 = 0
RET
```

| Stage | Match | Conf |
|---|---|---|
| ECX→ESI this | `8B F1` | **High** |
| vtbl install | `C7 06 6C F7 A9 00` | **High** |
| string @ `+0xB4` | `8D 8E B4 00 00 00` | **High** |
| tidy @ `+0xA0` + global | `LEA ECX,[ESI+0xA0]` + store `DAT_00d1f1fc` | **High** |
| nested `+0x30` / `+0x10` | stack pushes | **High** |
| host global clear | `DAT_00d1f058=0` | **High** |
| product class Palantir | vtbl[1] log string | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (137 B) — see raw W34-K append.

Entry: `6A FF 68 1C FD 9A 00 64 A1 … 8B F1`  
Epilogue: `C7 05 58 F0 D1 00 00… 5E 64 89 0D… 83 C4 14 C3`  
Pad: `CC` from `0x007543A9`; next `FUN_007543b0` @ `0x007543B0`.

**Decompile ≢ bytes:** false `ExceptionList = param_1`; missing explicit `LEA ECX,[ESI+0xA0]`; nested args look like pointer arithmetic only. **Bytes win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004447e0` (scalar), Unwind `@009b0038`/`@009b0065` |
| Callees | IAT `~basic_string`, `StringVec_Tidy`, `FUN_0075d8e0`, `FUN_00964d00` |
| Vtbl | `PTR_FUN_00a9f76c` |

---

## 7. Gaps

1. Nested duals for `FUN_0075d8e0` / `FUN_00964d00` (product member types at `+0x30` / `+0x10`).  
2. Exact MSVC demangle plate for Palantir dtor.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

Stage order, ABI, globals, and product class identity sealed by full-body hex + vtbl peer string; nested subobject plates open → **accept-with-gaps**.
