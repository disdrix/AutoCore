# Review A (reconstruction fidelity): `aa_008aa560` MissionDialog_ClearResponseButtonSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa560` |
| **VA** | `0x008aa560` |
| **Canonical name** | `MissionDialog_ClearResponseButtonSlots_Inferred` (Ghidra `FUN_008aa560`) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Pre-rebuild wipe** of mission-dialog response-button chrome:

1. For each of **8** slots: TFID pair at `dialog+0x518+i*8` ← `(−1,−1)`.
2. If widget at `dialog+0x708+i*4` non-null: host **vtbl+0xBC**(widget), then zero pointer.

Sole caller `FUN_008ac110` (`i_d_npc_2d_btn_response.xml` rebuild) calls this immediately after entry guard, then recreates buttons for `i < dialog+0x510`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra | `batch_decompile` + `analyze_function_complete` @ `0x008aa560` |
| Body bounds | `get_function_by_address` → `008aa560`–`008aa5a6` |
| Full bytes | `read_memory` length 70 (+ ret) |
| Caller framing | `get_assembly_context` @ `008ac138`; decompile `FUN_008ac110` |
| Raw | `docs/reconstruction/raw/aa_008aa560_FUN_008aa560.md` (+ WQ7R-C append) |
| Annotated | `docs/reconstruction/raw/aa_008aa560_FUN_008aa560.annotated.md` |
| Clean | `reconstructed-exact/MissionDialog_ClearResponseButtonSlots_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_008aa560.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 70 B / `0x46` | **High** | bounds + full hex + `CC` pad |
| EBX = dialog host | **High** | caller `MOV EBX,EDI` @ `008ac136` |
| No stack args / plain RET | **High** | bytes end `5F 5E 5D C3`; no `RET n` |
| Fixed 8 iterations | **High** | `mov ebp,8` |
| `+0x518` TFID pairs −1/−1 | **High** | `lea edi,[ebx+0x518]`; dual dword stores |
| `+0x708` widget bank | **High** | `lea esi,[ebx+0x708]` |
| vtbl+0xBC destroy | **High** role | `call [edx+0xbc]` with ECX=EBX |
| Sole xref `FUN_008ac110` | **High** | xrefs count 1 |
| Product vtbl name | **Tentative** | ordinal only |
| Product function name | **Open** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live | Clean |
|---|---|---|---|
| Setup cursors + count=8 | Yes | Yes | Yes |
| Clear TFID pair | Yes | Yes | Yes |
| Conditional destroy + zero | Yes | Yes | Yes |
| Advance + loop | Yes | Yes | Yes |
| Invented branches | — | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra.

---

## 5. Assembly seals (no disassemble_bytes)

| Bytes | Meaning |
|---|---|
| `8D B3 08 07 00 00` | `lea esi,[ebx+0x708]` |
| `8D BB 18 05 00 00` | `lea edi,[ebx+0x518]` |
| `BD 08 00 00 00` | `mov ebp,8` |
| `C7 07 FF…` / `C7 47 04 FF…` | store −1, −1 |
| `FF 92 BC 00 00 00` | `call [edx+0xBC]` |
| `83 C7 08` / `83 C6 04` | stride TFID+8, widget+4 |
| `83 ED 01` / `75 D1` | loop |

### Caller seal

```
008ac136  MOV EBX, EDI     ; dialog
008ac138  CALL 0x008aa560
008ac13d  CMP [EDI+0x640], 0
…
008ac152  CMP [EDI+0x510], EBX  ; rebuild count
```

---

## 6. Gaps

1. Product/PDB name.
2. Product name for vtbl+0xBC.
3. TFID pair field semantics (external HandleButton).
4. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — 8-slot clear, EBX ABI, offsets, and sole-caller pre-rebuild role sealed; product English open.
