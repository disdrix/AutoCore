# Review A (reconstruction fidelity): `aa_00636d10` CVOGHBMoveVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636d10` |
| **VA** | `0x00636d10` |
| **Body span** | `0x00636d10`–`0x00636d2d` inclusive (**30** bytes / `0x1E`; exclusive end `0x00636d2e` → `cc cc` then `0x00636d30`) |
| **Canonical name** | `CVOGHBMoveVehicle_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00636d10` |
| **Review date** | `2026-08-05` (OWN-ONLY **R11-024**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ machine bytes) |
| **Counterpart** | `reviews/B_aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md` |
| **System** | `input-drive-control` / MSVC scalar-deleting dtor |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / `get_function_callers` / `get_xrefs_to` + `read_memory` (body, vtbl, RTTI). **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

**MSVC scalar-deleting destructor (vtbl[0])** for product class **CVOGHBMoveVehicle** (`PTR_FUN_009e3b70`):

```text
// ECX = this; stack flags; RET 4; returns this*
FUN_00636b90(this)                 // complete/body
if (flags & 1) operator_delete(this)
return this
```

Complete body restores `PTR_FUN_009e3b70` and chains `FUN_00508390` (CVOGHBBase complete). RTTI `.?AVCVOGHBMoveVehicle@@` seals product English — no `_Inferred` suffix.

**Not** the complete body, not a vector-deleting form, not shared with ToMouse scalar shell.

**Machine proof (`read_memory` len 48 @ entry, first 30 B body):**

```text
0x00636d10:  56                   push  esi
0x00636d11:  8B F1                mov   esi, ecx
0x00636d13:  E8 78 FE FF FF       call  0x00636b90   ; complete/body
0x00636d18:  F6 44 24 08 01       test  byte ptr [esp+8], 1
0x00636d1d:  74 09                jz    0x00636d28
0x00636d1f:  56                   push  esi
0x00636d20:  E8 FD 2A E5 FF       call  0x00489822   ; operator_delete
0x00636d25:  83 C4 04             add   esp, 4
0x00636d28:  8B C6                mov   eax, esi
0x00636d2a:  5E                   pop   esi
0x00636d2b:  C2 04 00             ret   4
```

Hex: `568bf1e878fefffff644240801740956e8fd2ae5ff83c4048bc65ec20400`

Call targets: rel32 decode → `00636b90`, `00489822` (**High**).

**Calling convention:** MSVC `__thiscall` — object in **ECX**; flags on stack; **`RET 4`**; **EAX = this**.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00636d10_FUN_00636d10.md` | R11-024 append |
| Annotated | `docs/reconstruction/raw/aa_00636d10_FUN_00636d10.annotated.md` | Refresh |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_ScalarDeletingDtor.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636d10.cpp` | Updated |
| Function FUN | `docs/reconstruction/functions/aa_00636d10_FUN_00636d10.md` | Updated |
| Function named | `docs/reconstruction/functions/aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md` | New |
| Live decompile | Ghidra `0x00636d10` | if/call ≡ raw; delete noreturn warning |
| Live bytes | `read_memory` | ≡ instruction map (30 B) |
| Live xrefs | DATA `009e3b70` only | no code callers |
| RTTI | type desc `0x00af33c0` | `.?AVCVOGHBMoveVehicle@@` |
| Vtbl contrast | `009d5590` dword0 | `005996a0` (ToMouse — different) |
| Body callee | `FUN_00636b90` | restore vtbl + base chain |
| Family pattern | `CVOGHBBase_ScalarDeletingDtor` / CVOGMenu scalar | same CF shape |
| Partition | `WAVE_2026-08-05_r11_residual_partition_map.md` | R11-024 |

**Not performed:** Launcher, runtime golden, bit-exact package diff, dual of complete body `00636b90` (other VA).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 30 B / end `0x00636d2d` | **High** | bytes + next `cc` / next fn `00636d30` |
| `this` in ECX | **High** | `MOV ESI,ECX` |
| CALL complete `00636b90` first | **High** | rel32 decode |
| flags bit0 → operator_delete | **High** | `TEST [esp+8],1` + push ESI |
| Always return this; RET 4 | **High** | `MOV EAX,ESI; RET 4` |
| vtbl[0] @ `009e3b70` | **High** | DATA xref + dword read |
| Product name CVOGHBMoveVehicle | **High** | RTTI type desc |
| Scalar not vector | **High** | only bit0; no count |
| Complete body English | Residual | not OWN |
| Runtime / bit-exact | Open | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ESI=this; CALL `FUN_00636b90` | **Yes** |
| flags&1 → operator_delete + ADD ESP,4 | **Yes** (bytes; decompiler may omit ADD under noreturn) |
| Always return this; RET 4 | **Yes** |
| Invented branches | **None** |
| Decompiler “delete noreturn” | **Ignored** (bytes prove epilogue) |
| Product name from RTTI | **Yes** — `.?AVCVOGHBMoveVehicle@@` |

---

## 5. Gaps

- Complete body `FUN_00636b90` dual residual (other VA; not OWN).
- Vtbl slots [1+] English beyond dualed OnEnd / residual fire (not owned here).
- Runtime / bit-exact / differential.
- PDB method symbol beyond RTTI + MSVC scalar-deleting convention.

None of the gaps threaten CF/ABI/name seal for this unit.

---

## 6. Verdict

**accept** — classic scalar-deleting CF/ABI/vtbl[0]/RTTI product name sealed. Complete callee identified (residual dual). Not reject.
