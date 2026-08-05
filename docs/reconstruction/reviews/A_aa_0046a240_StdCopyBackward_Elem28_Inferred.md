# Review A (reconstruction fidelity): `aa_0046a240` StdCopyBackward_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a240` |
| **VA** | `0x0046a240`–`0x0046a25d` (**30 B** / `0x1E`) |
| **Canonical name** | `StdCopyBackward_Elem28_Inferred` |
| **Ghidra name** | `FUN_0046a240` |
| **Review date** | `2026-07-29` (W35-L dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-L) |
| **Counterpart** | `reviews/B_aa_0046a240_StdCopyBackward_Elem28_Inferred.md` |
| **System** | stl-helpers / POD copy_backward (elem 0x1c) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 30 B) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Leaf MSVC-style `std::copy_backward` for POD T size **0x1c**:

1. If `src_begin == src_end` (EBX == EDX), return.
2. Else loop: `src_end -= 0x1c`; `dest_end -= 0x1c`; `REP MOVSD` 7 dwords; until src_end reaches src_begin.
3. Bare `RET`.

Used by elem-28 insert-n mid-shift arms (`FUN_0045cd30`, `FUN_00466ea0`, `FUN_00469f50`) for overlap-safe tail relocation.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-L append) | `docs/reconstruction/raw/aa_0046a240_FUN_0046a240.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a240_FUN_0046a240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdCopyBackward_Elem28_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0046a240.cpp` |
| Function records | `functions/aa_0046a240_FUN_0046a240.md`, `functions/aa_0046a240_StdCopyBackward_Elem28_Inferred.md` |
| Live | decompile ≡ bytes; 3 callers |
| Pair | `StdUninitFillN_Elem28_CountEax_Inferred` (`0x0045f150`) |

---

## 3. Signature (sealed — bytes win)

```c
// Register ABI; bare RET; leaf
// Decompiler: void __fastcall (phantom param_1, src_end* EDX) + in_EAX + unaff_EBX
void StdCopyBackward_Elem28_Inferred(
    Elem28* dest_end /*EAX*/,
    Elem28* src_end /*EDX*/,
    const Elem28* src_begin /*EBX*/);
```

| Slot | Source | Conf |
|---|---|---|
| dest_end* | EAX | **High** |
| src_end* | EDX | **High** |
| src_begin* | EBX | **High** |
| ECX | clobber (`MOV ECX,7`) | **High** (not formal) |
| decompiler param_1 | unused phantom | **High** (not formal) |
| RET | bare `C3` | **High** |
| stride | `SUB …,0x1C` + `MOV ECX,7` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if src_begin == src_end: return
loop:
  src_end  -= 1 element
  dest_end -= 1 element
  copy 7 dwords src_end → dest_end
  if src_end != src_begin: goto loop
return
```

| Stage | Match | Conf |
|---|---|---|
| Empty-range early out | **Yes** (`CMP EBX,EDX` / `JE`) | **High** |
| Backward step 0x1c | **Yes** | **High** |
| 7-dword element copy | **Yes** (`REP MOVSD`) | **High** |
| Flags from CMP survive REP | **Yes** (MOVS no flag clobber) | **High** |
| Leaf | **Yes** (0 callees) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 30 B hex:

```
3bda7419565783ea1c83e81c3bd3b9070000008bf28bf8f3a575eb5f5ec3
```

Entry: `CMP EBX,EDX; JE done; PUSH ESI; PUSH EDI`.  
Epilogue: `POP EDI; POP ESI; RET`. Pad `CC` then `FUN_0046a260` @ `0x0046a260`.

Call site (`0x00467150` in `FUN_00466ea0`): `MOV EDX,EBX; MOV EBX,ESI; MOV EAX,…; CALL`.

---

## 6. Gaps / open

1. Product/MSVC demangle English.
2. Concrete POD T for the 0x1c element.
3. Runtime / bit-exact / differential.

Fidelity pass seals full 30 B body, three-register ABI, stride, and leaf classification. Residual product English is non-blocking → **accept**.
