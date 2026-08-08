# Review A (reconstruction fidelity): `aa_00426f70` RunElem_WStringDtor_Plus0C_Trampoline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00426f70` |
| **VA** | `0x00426f70`–`0x00426f78` inclusive (**9 B** / `0x9`) |
| **Canonical name** | `RunElem_WStringDtor_Plus0C_Trampoline_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00426f70` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R10-026) |
| **Counterpart** | `reviews/B_aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` |
| **System** | skills-abilities / UI text-layout run element member dtor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (32 B) + callers/xrefs + `analyze_data_region` IAT `0x009c62ac` + parent/caller decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

ECX-this **member dtor trampoline**:

1. `ADD ECX, 0x0C` — adjust this to embedded field at element+0x0C.
2. `JMP DWORD PTR [0x009C62AC]` — tail into MSVC `~basic_string<wchar_t>`.

Used by dualed `StdVector_DestroyRuns_0x80_Inferred` (and destroy-range twin) when tearing 0x80-stride run elements under UiTextLayout.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R10-026 append) | `docs/reconstruction/raw/aa_00426f70_FUN_00426f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00426f70_FUN_00426f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RunElem_WStringDtor_Plus0C_Trampoline_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00426f70.cpp` |
| Function | `aa_00426f70_FUN_00426f70.md`, `aa_00426f70_RunElem_WStringDtor_Plus0C_Trampoline_Inferred.md` |
| Parent dual | MEGA-128 `aa_004271c0` StdVector_DestroyRuns_0x80_Inferred |
| Live | decompile ≡ CF intent; 9 B hex; IAT PTR name; callers sealed |

---

## 3. Signature (sealed)

```c
// ECX = element base*; void; tail-JMP IAT (no local RET)
void __fastcall RunElem_WStringDtor_Plus0C_Trampoline_Inferred(void* elem /* ECX */);
```

| Formal | Source | Conf |
|---|---|---|
| elem / this | ECX (`param_1` / register) | **High** |
| offset | `ADD ECX, 0x0C` imm | **High** |
| target | IAT `0x009c62ac` `PTR_~basic_string<wchar_t,...>` | **High** |
| local RET | none (tail JMP) | **High** |

---

## 4. Control flow (bytes authority)

```
ADD ECX, 0x0C
JMP DWORD PTR [0x009C62AC]   // ~basic_string<wchar_t>
```

| Stage | Match | Conf |
|---|---|---|
| Body 9 B | Yes | **High** |
| +0x0C adjust | Yes (`83 C1 0C`) | **High** |
| IAT JMP not CALL | Yes (`FF 25`) | **High** |
| wchar_t string dtor | Yes (IAT PTR name) | **High** |
| Parent CALL with ECX=elem | Yes (`FUN_004271c0`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (9 B):

```
83c10cff25ac629c00
```

Pad sample after body: `cccccccccccccc` then next code.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | stub (Ghidra); structural trampoline |
| Code callers | `FUN_004271c0`, `FUN_00427590`, `FUN_005ac510` |
| SEH | 4× `Unwind@*` |
| Callees | IAT only (no direct CALL) |

---

## 7. Gaps

1. Product element type English beyond dualed "run" / 0x80 layout (hence `_Inferred`).  
2. Non-wstring fields of the 0x80 element (unowned).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Full 9 B hex seals ABI, offset, and IAT target class. Parent dual already depended on this plate. Residual gaps are naming/product English only → **accept**.
