# Dual A/B report — W38-B OWN `aa_00457cc0` + `aa_0096a630`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-B  
**Scope:** VAs `0x00457cc0`, `0x0096a630` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-B).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00457cc0` StdTree_IteratorIncrement_Isnil19 | **accept** — EDX iterator ABI + successor CF + isnil@+0x19 + leaf sealed (75 B) |
| `aa_0096a630` AssKey_FormatAssIdLogString_Inferred | **accept-with-gaps** — thiscall/RET4/`assId: [%s]`/null→empty sealed (177 B); product key class English open |

---

## VA `0x00457cc0` — sealed facts

1. **Body:** `0x00457cc0`–`0x00457d0b` exclusive (**75 B** / `0x4B`; final `C3` @ `0x00457d0a`; pad `CC`).
2. **ABI:** **`EDX = node**`** (iterator); plain **`RET`** (`C3`). Entry `MOV EAX,[EDX]`. Call sites `LEA EDX,[ESP+…]` then `CALL`. ECX unused (decompiler phantom).
3. **Semantics:** MSVC `_Tree` **iterator successor** (`operator++`) in place:
   - Nil-at-current (`isnil@+0x19`) → no-op.
   - Else if right non-nil → **leftmost** of right subtree (`+8` then walk left `+0`).
   - Else climb parents (`+4`) while current was **right** child; store ancestor.
4. **Layout:** L`+0` / P`+4` / R`+8` / isnil`+0x19` (Val12 family).
5. **Classification:** **leaf** (0 callees).
6. **Callers (9):** `FUN_0040b440`, `FUN_0043be60`, `FUN_0043d7d0`, `FUN_00447350`, `FUN_0046c450`, `FUN_0046f6e0`, `FUN_00970e50`, `FUN_00971050`, `FUN_00971480`.
7. **Name:** `StdTree_IteratorIncrement_Isnil19` (Ghidra `FUN_00457cc0`). **Reject** scaffold `Named_CalleeOf_Named_assPreloader_00457cc0` (multi-caller shared util).
8. **Family:** twins `StdTree_IteratorIncrement_Inferred` (`+0x29`), `StdTree_IteratorIncrement_Isnil49` (`+0x49`, **ECX** ABI); decrement peer `StdTree_IteratorDecrement` (also **EDX**).
9. **Decompile ≡ bytes** for full CF and isnil displacements.  
   Full hex: `8b028078190075428b480880791900751c8b018078190075118da424000000008bc88b018078190074f6890ac38b40048078190075128b0a3b4808750b89028b40048078190074ee8902c3`

### Gaps

- Per-caller map value product English.  
- Color bit unused by this unit.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00457cc0_FUN_00457cc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00457cc0_FUN_00457cc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil19.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457cc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00457cc0_FUN_00457cc0.md` |
| Function named | `docs/reconstruction/functions/aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md` |

---

## VA `0x0096a630` — sealed facts

1. **Body:** `0x0096a630`–`0x0096a6e1` exclusive (**177 B** / `0xB1`; final `RET 4` @ `0x0096a6de`–`0x0096a6e0`; pad `CC`).
2. **ABI:** **`__thiscall`** — **ECX = key\*** (`MOV ESI,ECX`); stack **out `basic_string*`**; **`RET 4`**; returns **out** in **EAX**.
3. **Semantics:**
   - SEH `LAB_009ab872`; local `basic_string` + 260-byte sprintf buffer.
   - `name = *key`; if null → **`PTR_DAT_00afa2bc`** → empty `""` @ `0x00a1419b`.
   - `sprintf(buf, "assId: [%s]", name)` — format @ **`0x00aa1c18`**.
   - Assign local ← buf; copy-construct out ← local; dtor local; return out.
4. **Classification:** **worker** (string format helper).
5. **Callees:** `sprintf`; `std::basic_string` default ctor / `operator=` / copy-ctor / dtor (IAT).
6. **Callers:** 27+ functions / **39** xrefs — AssPreloader (`00970e50`, `00971050`, `00971280`, `00971480`, …), gfx load (`00581e20`, `00583fa0`, …), media/geometry helpers.
7. **Name:** `AssKey_FormatAssIdLogString_Inferred` (Ghidra `FUN_0096a630`; **Inferred** product key type). **Reject** scaffold `Named_CalleeOf_Named_gfxBody_0096a630`.
8. **Decompile ≡ bytes** for format path, null gate, RET 4.  
   Full hex: `6aff6872b89a0064a100000000506489250000000081ec24010000568bf18d4c2408c744240400000000ff1588629c00c7842430010000010000008b0685c07505a1bca2af00508d44242868181caa0050ff1554669c0083c40c8d4c2424518d4c240cff15c8639c008bb424380100008d542408528bceff15ec629c008d4c2408c744240401000000c684243001000000ff15f4629c008b8c24280100008bc65e64890d0000000081c430010000c20400`

### Gaps

- Product/PDB key class English (only first-dword `char*` sealed).  
- Exhaustive key-layout audit across all 39 xrefs.  
- SSO/`basic_string` bit-exact vs port `std::string`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096a630_FUN_0096a630.md` |
| Annotated | `docs/reconstruction/raw/aa_0096a630_FUN_0096a630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssKey_FormatAssIdLogString_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096a630.cpp` |
| Function | `docs/reconstruction/functions/aa_0096a630_FUN_0096a630.md` |
| Function named | `docs/reconstruction/functions/aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00457cc0` | Port as **Val12-family tree iterator ++**: **EDX=`node**`**, plain **RET**, isnil@**+0x19**. Do **not** use ECX ABI of Isnil49 twin. Do **not** merge with isnil `+0x29`/`+0x49` bodies. Do **not** treat as AssPreloader-private (9 callers). |
| `0096a630` | Port as **log string formatter only**: thiscall key, stack out string, **RET 4**, format **`assId: [%s]`**, null→empty. Do **not** treat as preload/load engine. Key first field = `char*`. Optional on server unless matching client diagnostics. |
| Shared | Co-owned only by partition; both appear on AssPreloader walk/log paths (`00970e50` / `00971480`) but are independent utilities (tree step vs string format). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref/call-site helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` on unproven key class; structural `StdTree_IteratorIncrement_Isnil19` from sealed isnil family continuum.  
- Rejected scaffold AssPreloader/gfxBody ownership names.  
- Avoided bare `undefined4` in clean (used `int32_t` / explicit key view).
