# Review A (reconstruction fidelity): `aa_004271c0` StdVector_DestroyRuns_0x80_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004271c0` |
| **VA** | `0x004271c0`–`0x00427204` inclusive (**69 B** / `0x45`) |
| **Canonical name** | `StdVector_DestroyRuns_0x80_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004271c0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-128) |
| **Counterpart** | `reviews/B_aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` |
| **System** | skills-abilities / UI text-layout vector tidy |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (80 B) + callers/xrefs + callee decompile `FUN_00426f70` + call-site disasm `FUN_00797d70`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

EBX-this **vector tidy** for elements of stride **0x80**:

1. If begin null → zero begin/end/cap and return.
2. Else for each elem in `[begin,end)`: `FUN_00426f70` (ECX=elem) destroys embedded `wstring` @+0x0C.
3. `operator_delete(begin)`; zero triple; return.

Used by dualed `UiTextLayout_CompleteDtor_Inferred` to tear the run vector at `layout+0x80`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-128 append) | `docs/reconstruction/raw/aa_004271c0_FUN_004271c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004271c0_FUN_004271c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRuns_0x80_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004271c0.cpp` |
| Function | `aa_004271c0_FUN_004271c0.md`, `aa_004271c0_StdVector_DestroyRuns_0x80_Inferred.md` |
| Parent dual | WQ9L-F `aa_00797d70` UiTextLayout_CompleteDtor_Inferred |
| Live | decompile ≡ CF; 69 B hex; thunk JMP; `FUN_00426f70` trampoline; call site `LEA EBX,[ESI+0x80]` |

---

## 3. Signature (sealed)

```c
// EBX = vector*; void; RET (C3)
void StdVector_DestroyRuns_0x80_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| vector* | EBX (`unaff_EBX`; caller `LEA EBX`) | **High** |
| cleanup | `C3` @ `0x00427204` | **High** |
| ECX thiscall vector | **not used** | **High** |

---

## 4. Control flow (bytes authority)

```
ESI=[EBX+4]
if ESI==0: zero +4/+8/+0xC; RET
EDI=[EBX+8]
while ESI!=EDI: ECX=ESI; CALL FUN_00426f70; ESI+=0x80
operator_delete([EBX+4]); zero +4/+8/+0xC; RET
```

| Stage | Match | Conf |
|---|---|---|
| Body 69 B | Yes | **High** |
| Stride `ADD ESI,0x80` | Yes | **High** |
| Elem dtor via ECX | Yes (`MOV ECX,ESI`) | **High** |
| Post-delete zero triple | Yes (decompiler missed) | **High** |
| Thunk `00427040` → here | Yes | **High** |
| Sole CALL from `00797df0` | Yes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (69 B):

```
568b730485f67426578b7b083bf774118bcee899fdffff81c6800000003bf775ef8b430450e83826060083c4045fc7430400000000c7430800000000c7430c000000005ec3
```

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00797d70` @ `0x00797df0`; thunk `0x00427040` |
| Callees | `FUN_00426f70`; `operator_delete` @ `0x00489822` |

---

## 7. Gaps

1. Product element type English beyond `wstring@+0x0C` (hence `_Inferred` / "runs").  
2. Full dual of trampoline `FUN_00426f70` (unowned; body sealed as 2-insn `ADD ECX,0xC; JMP IAT`).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Full 69 B hex seals ABI, stride, destroy loop, free, and zero. Sole CALL site matches dualed UiTextLayout complete dtor plate. Residual gaps are naming only → **accept**.
