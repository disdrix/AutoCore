# Review A (reconstruction fidelity): `aa_005996a0` CVOGHBMoveVehicleToMouse_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005996a0` |
| **VA** | `0x005996a0` |
| **Body span** | `0x005996a0`–`0x005996bd` inclusive (**30** bytes / `0x1E`; exclusive end `0x005996be` → `cc cc` then `c3`/pad) |
| **Canonical name** | `CVOGHBMoveVehicleToMouse_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_005996a0` |
| **Review date** | `2026-08-05` (OWN-ONLY **R12-028**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ machine bytes) |
| **Counterpart** | `reviews/B_aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md` |
| **System** | `input-drive-control` / MSVC scalar-deleting dtor |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / `get_function_callers` / `get_xrefs_to` + `read_memory` (body, vtbl, RTTI). **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

**MSVC scalar-deleting destructor (vtbl[0])** for product class **CVOGHBMoveVehicleToMouse** (`PTR_FUN_009d5590`):

```text
// ECX = this; stack flags; RET 4; returns this*
FUN_00599570(this)                 // ToMouse complete/body
if (flags & 1) operator_delete(this)
return this
```

Complete body restores `PTR_FUN_009d5590` and chains `FUN_00636b90` (MoveVehicle complete → base). RTTI `.?AVCVOGHBMoveVehicleToMouse@@` seals product English — no `_Inferred` suffix.

**Not** the complete body, not a vector-deleting form, not shared with base MoveVehicle scalar shell `0x00636d10`.

**Machine proof (`read_memory` len 48 @ entry, first 30 B body):**

```text
0x005996a0:  56                   push  esi
0x005996a1:  8B F1                mov   esi, ecx
0x005996a3:  E8 C8 FE FF FF       call  0x00599570   ; ToMouse complete/body
0x005996a8:  F6 44 24 08 01       test  byte ptr [esp+8], 1
0x005996ad:  74 09                jz    0x005996b8
0x005996af:  56                   push  esi
0x005996b0:  E8 6D 01 EF FF       call  0x00489822   ; operator_delete
0x005996b5:  83 C4 04             add   esp, 4
0x005996b8:  8B C6                mov   eax, esi
0x005996ba:  5E                   pop   esi
0x005996bb:  C2 04 00             ret   4
```

Hex: `568bf1e8c8fefffff644240801740956e86d01efff83c4048bc65ec20400`

Call targets: rel32 decode → `00599570`, `00489822` (**High**).

**Calling convention:** MSVC `__thiscall` — object in **ECX**; flags on stack; **`RET 4`**; **EAX = this**.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005996a0_FUN_005996a0.md` | R12-028 append |
| Annotated | `docs/reconstruction/raw/aa_005996a0_FUN_005996a0.annotated.md` | Refresh |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005996a0.cpp` | Updated |
| Function FUN | `docs/reconstruction/functions/aa_005996a0_FUN_005996a0.md` | Updated |
| Function named | `docs/reconstruction/functions/aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md` | New |
| Live decompile | Ghidra `0x005996a0` | if/call ≡ raw; delete noreturn warning |
| Live bytes | `read_memory` | ≡ instruction map (30 B) |
| Live xrefs | DATA `009d5590` only | no code callers |
| RTTI | type desc `0x00af33e0` | `.?AVCVOGHBMoveVehicleToMouse@@` |
| Vtbl contrast | `009e3b70` dword0 | `00636d10` (MoveVehicle — different; parent R11-024) |
| Body callee | `FUN_00599570` | restore ToMouse vtbl + chain MoveVehicle complete |
| Family pattern | `CVOGHBMoveVehicle_ScalarDeletingDtor` / `CVOGHBBase_ScalarDeletingDtor` | same CF shape |
| Partition | `WAVE_2026-08-05_r12_residual_partition_map.md` | R12-028 |

**Not performed:** Launcher, runtime golden, bit-exact package diff, dual of complete body `00599570` (other VA).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 30 B / end `0x005996bd` | **High** | bytes + next `cc` pad |
| `this` in ECX | **High** | `MOV ESI,ECX` |
| CALL complete `00599570` first | **High** | rel32 decode |
| flags bit0 → operator_delete | **High** | `TEST [esp+8],1` + push ESI |
| Always return this; RET 4 | **High** | `MOV EAX,ESI; RET 4` |
| vtbl[0] @ `009d5590` | **High** | DATA xref + dword read |
| Product name CVOGHBMoveVehicleToMouse | **High** | RTTI type desc |
| Scalar not vector | **High** | only bit0; no count |
| Complete body English | Residual | not OWN |
| Runtime / bit-exact | Open | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ESI=this; CALL `FUN_00599570` | **Yes** |
| flags&1 → operator_delete + ADD ESP,4 | **Yes** (bytes; decompiler/disasm may omit ADD under noreturn) |
| Always return this; RET 4 | **Yes** |
| Invented branches | **None** |
| Decompiler “delete noreturn” | **Ignored** (bytes prove epilogue) |
| Product name from RTTI | **Yes** — `.?AVCVOGHBMoveVehicleToMouse@@` |

---

## 5. Gaps

- Complete body `FUN_00599570` dual residual (other VA; not OWN).
- Vtbl slots [1+] English beyond shared dualed OnEnd / OnHeartBeat (not owned here).
- Runtime / bit-exact / differential.
- PDB method symbol beyond RTTI + MSVC scalar-deleting convention.

None of the gaps threaten CF/ABI/name seal for this unit.

---

## 6. Verdict

**accept** — classic scalar-deleting CF/ABI/vtbl[0]/RTTI product name sealed. Complete callee identified (residual dual). Not reject.
