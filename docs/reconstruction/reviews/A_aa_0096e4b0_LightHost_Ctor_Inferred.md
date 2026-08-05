# Review A (reconstruction fidelity): `aa_0096e4b0` LightHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e4b0` |
| **VA** | `0x0096e4b0`–`0x0096e4d1` exclusive (**33 B** / `0x21`) |
| **Canonical name** | `LightHost_Ctor_Inferred` (Ghidra `FUN_0096e4b0`) |
| **Review date** | `2026-08-04` (W37-AB) |
| **Reviewer role** | Reconstruction fidelity (light-host ctor) |
| **Counterpart** | `reviews/B_aa_0096e4b0_LightHost_Ctor_Inferred.md` |
| **System** | client / effect light host |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs. Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: W32-R `PalantirEnv_RebuildDefaultLights_Inferred`, `FUN_0058f780`, base `FUN_0096d830`, scalar dtor `0x004493d0`.

---

## 1. Purpose

**Construct** a light-host object:

1. Base ctor `FUN_0096d830(this)` (base vtable `PTR_FUN_00aa0824` + POD init).
2. Zero `this+0x8c` and `this+0x90` (effect-core slots).
3. Install derived vtable `PTR_FUN_00aa0394`.
4. Return `this`.

Does **not** set light type string, colors, or direction — callers do that after `operator_new(0x94)` + this ctor.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AB) | `docs/reconstruction/raw/aa_0096e4b0_FUN_0096e4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096e4b0_FUN_0096e4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LightHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096e4b0.cpp` |
| Function records | `functions/aa_0096e4b0_FUN_0096e4b0.md`, `functions/aa_0096e4b0_LightHost_Ctor_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; body 33 B hex; 3 xrefs; 2 caller functions |
| Callers | `FUN_0048f370` (dir/hemi), `FUN_0058f780` (Point) |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, writes to unowned VAs.

---

## 3. Signature

```c
// __thiscall; ECX=self*; returns self in EAX; bare RET
LightHost* __fastcall LightHost_Ctor_Inferred(LightHost* self);
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX`; epilogue `MOV EAX,ESI; POP ESI; RET` |
| Base call | rel `E8` → `FUN_0096d830` with `PUSH ESI` |
| Zeros | `MOV [ESI+0x8C],0` / `MOV [ESI+0x90],0` |
| Vtable | imm `0x00AA0394` store to `[ESI]` |
| Body range | entry `0096e4b0`, exclusive end `0096e4d1` |
| Xrefs | **3** |

---

## 4. Control flow (sealed)

```
ESI = this
FUN_0096d830(this)
*(this+0x8C) = 0
*(this+0x90) = 0
*(this+0) = PTR_FUN_00aa0394
return this
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| thiscall prologue | **Yes** — `56 8B F1` |
| Base ctor | **Yes** — rel call to `0x0096d830` |
| Zero +0x8c / +0x90 | **Yes** — `89 86 8C/90 00 00 00` after `XOR EAX,EAX` |
| Vtable install | **Yes** — `C7 06 94 03 AA 00` |
| Return this | **Yes** — `8B C6 5E C3` |
| No branches | **Yes** — straight-line 33 B |

**Thread safety:** none claimed.

---

## 5. Machine bytes (`read_memory` @ `0x0096e4b0`, 33 B)

Hex:  
`568bf156e877f3ffff33c089868c000000898690000000c7069403aa008bc65ec3`

---

## 6. Callers / callees

| Callee | Role |
|--------|------|
| `FUN_0096d830` | base effect-host ctor |

| Caller | Sites | Context |
|--------|-------|---------|
| `FUN_0048f370` | `0048f3b1`, `0048f5a0` | `new(0x94)` → env `+0x108` / `+0x104` |
| `FUN_0058f780` | `0058fac1` | `new(0x94)` → geom `+0x91c` + `"Point"` |

Vtable slot0 `0x004493d0`: scalar-deleting dtor (`FUN_004492e0` + optional `operator_delete`).

---

## 7. Gaps

- Product / MSVC demangle for class of `PTR_FUN_00aa0394`.
- English for field `+0x90`.
- Complete dtor `FUN_004492e0` (unowned).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Ctor CF, ABI, offsets, vtable, size-via-callers, and 3 xrefs **sealed**. Product plate open → **accept-with-gaps**.
