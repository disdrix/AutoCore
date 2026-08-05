# Review A (reconstruction fidelity): `aa_00438040` StdVector_Resize_Elem8_ViaInsertN_00438d80

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438040` |
| **VA** | `0x00438040` |
| **Body** | `0x00438040`–`0x004380EA` inclusive (**171 B** / `0xAB`); pad `CC` |
| **Canonical name** | `StdVector_Resize_Elem8_ViaInsertN_00438d80` (**Inferred**); Ghidra `FUN_00438040` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00438040_StdVector_Resize_Elem8_ViaInsertN_00438d80.md` |
| **System** | STL / container utility (8-byte element vectors) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/`ret 8`/stride-8 grow+shrink sealed; product element type open |
| **Dual status** | **Present (W38-G)** |

---

## 1. Purpose

**Resize** a MSVC-style vector of **8-byte** elements. Control block consumed here:

| Offset | Role |
|---|---|
| `vec+0x04` | begin (`T*`) |
| `vec+0x08` | end (`T*`) |
| `vec+0x0C` | capacity end (grow callee only) |

```
size = (begin == 0) ? 0 : (end - begin) >> 3;

if (size < newCount):
  FUN_00438d80(vec, end, newCount - size, &fill);  // insert-N at end
else if (begin != 0 && newCount < size):
  FUN_00438d00(vec, &tmp, begin + newCount*8, end); // erase range + element dtors
// equal -> no-op
// then destroy by-value fill if fill.rep != null (refcount-- / vtbl+8)
```

**ABI:** `__fastcall`; **ECX = newCount**, **EDX = vec\***; stack **8-byte fill by value**; **`ret 8`**.

Distinct from dword resize twins (`0x00410420` / `0x004367f0`): those are **thiscall** + stride 4; this unit is **fastcall** + stride 8 + non-POD shrink + fill-rep release.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x00438040` (2026-08-04) — **≡ raw CF** |
| Complete analysis | 3 xrefs; callees `FUN_00438d80`, `FUN_00438d00`; callers `FUN_00437ce0`, `FUN_00765740` |
| Machine | `read_memory` `0x00438040` length 171 → body **171 B** ends `c2 08 00` |
| Grow callee | `FUN_00438d80` (insert-N; capacity 1.5× / `operator_new(n*8)`) |
| Shrink callee | `FUN_00438d00` (walk elements stride 8; call dtor `(**elem)(0)`) |
| Caller sites | `00437ce0` proxy fill `{0xa9da78,0}`; `00765740` `lea edx,[esi+0x128]` |
| Scaffold | `raw/aa_00438040_*`, prior `reconstructed-exact/FUN_00438040.cpp` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| ECX = newCount | `8b f1` (`mov esi, ecx`) | **Confirmed** |
| EDX = vector; begin/end | `8b 42 04` / `8b 4a 08` | **Confirmed** |
| size `>> 3` (elem 8) | `c1 f9 03` | **Confirmed** |
| Grow `call FUN_00438d80` + `&fill` | `8d 7c 24 1c; 57` … `e8 …` | **Confirmed** |
| Shrink `*8` + `call FUN_00438d00` | `8d 04 f0` / call | **Confirmed** |
| Exit `ret 8` | `c2 08 00` | **Confirmed** |
| Fill-rep release | `01 41 04` / `ff 52 08` when arg1 ≠ 0 | **Confirmed** |
| Body length 171 B | last `c2 08 00` @ end of 171 B dump | **Confirmed** |
| Equal size no-op | fall-through to release without grow/shrink call | **Confirmed** |

Full hex (171 B):

```
6aff6878e19b0064a10000000050648925000000005156578bf1c7442414000000008b420485c0750433c9eb088b4a082bc8c1f9033bce732485c0750433c9eb088b4a082bc8c1f9038b42088d7c241c572bf1565052e8e50c0000eb2285c0741e8b7a088bcf2bc8c1f9033bf17310578d04f0508d4424105052e8410c000083c8ff894424148b4c242085c95f5e740a01410475058b11ff52088b4c240464890d0000000083c410c20800
```

---

## 4. Gaps

- Product / MSVC demangle for element type (shared_ptr-shaped vs custom).
- Unowned insert/erase engine internals.
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — resize CF, fastcall ABI, stride 8, grow/shrink wiring, and fill-rep epilogue sealed; product element English open.
