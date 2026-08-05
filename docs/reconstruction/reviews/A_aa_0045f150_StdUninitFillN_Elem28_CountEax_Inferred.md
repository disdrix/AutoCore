# Review A (reconstruction fidelity): `aa_0045f150` StdUninitFillN_Elem28_CountEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045f150` |
| **VA** | `0x0045f150`–`0x0045f198` (**73 B** / `0x49`) |
| **Canonical name** | `StdUninitFillN_Elem28_CountEax_Inferred` |
| **Ghidra name** | `FUN_0045f150` |
| **Review date** | `2026-07-29` (W35-L dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-L) |
| **Counterpart** | `reviews/B_aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md` |
| **System** | stl-helpers / POD uninit fill-n (elem 0x1c) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 73 B) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Leaf uninit fill-n for POD T size **0x1c**:

1. If `count == 0` (EAX, unsigned `JBE`), return.
2. Else loop count times: if dest (EDX) non-null, copy 7 dwords from template (ECX); always `dest += 0x1c`; decrement count.
3. Bare `RET`.

Used by `StdVector_InsertN_Pod28` (`FUN_0045cd30`) on realloc fill and in-place hole fill.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-L append) | `docs/reconstruction/raw/aa_0045f150_FUN_0045f150.md` |
| Annotated | `docs/reconstruction/raw/aa_0045f150_FUN_0045f150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_Elem28_CountEax_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045f150.cpp` |
| Function records | `functions/aa_0045f150_FUN_0045f150.md`, `functions/aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md` |
| Live | decompile ≡ bytes; 2 call sites in `FUN_0045cd30` |
| Pair | `StdCopyBackward_Elem28_Inferred` (`0x0046a240`) |

---

## 3. Signature (sealed — bytes win)

```c
// Register ABI; bare RET; leaf
// Decompiler: void __fastcall (template* ECX, dest* EDX) + phantom in_EAX
void StdUninitFillN_Elem28_CountEax_Inferred(
    uint32_t count /*EAX*/,
    const Elem28* tmpl /*ECX*/,
    Elem28* dest /*EDX*/);
```

| Slot | Source | Conf |
|---|---|---|
| count | EAX → ESI | **High** |
| template* | ECX | **High** |
| dest* | EDX | **High** |
| RET | bare `C3` | **High** |
| stack formals | **none** | **High** |
| stride | `ADD …, 0x1C` ×2 + 7 stores | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if count == 0: return
loop:
  if dest != null: copy 7 dwords from tmpl
  dest += 1 element (0x1c)
  count--
  if count != 0: goto loop
return
```

| Stage | Match | Conf |
|---|---|---|
| Zero-count early out | **Yes** (`TEST ESI` / `JBE`) | **High** |
| Null-safe store | **Yes** (`TEST EDX` / `JZ`) | **High** |
| Always advance dest | **Yes** | **High** |
| Template not advanced | **Yes** | **High** |
| Leaf | **Yes** (0 callees) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 73 B hex:

```
568bf085f676408d421457eb038d490085d274278b39893a8b79048978f08b79088978f48b790c8978f88b79108978fc8b791489388b791889780483c21c83c01c83ee0175ca5f5ec3
```

Entry: `PUSH ESI; MOV ESI,EAX; TEST ESI,ESI; JBE done`.  
Epilogue: `POP EDI; POP ESI; RET`. Pad `CC` then next @ `0x0045f1a0`.

Call site (`0x0045ceae`): `LEA ECX,[ebp-0x30]; MOV EAX,ESI; MOV EDX,EDI; CALL`.

---

## 6. Gaps / open

1. Product/MSVC demangle English.
2. Concrete POD T for the 0x1c element.
3. Runtime / bit-exact / differential.

Fidelity pass seals full 73 B body, register ABI, null gate, stride, and leaf classification. Residual product English is non-blocking → **accept**.
