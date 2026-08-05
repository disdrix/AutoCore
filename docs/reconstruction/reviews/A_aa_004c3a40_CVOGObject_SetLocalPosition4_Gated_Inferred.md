# Review A (reconstruction fidelity): `aa_004c3a40` CVOGObject_SetLocalPosition4_Gated_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3a40` |
| **VA** | `0x004c3a40` |
| **Body span** | `004c3a40` – `004c3ab0` (**113** bytes; exclusive end `004c3ab1`) |
| **Canonical name** | `FUN_004c3a40` (Ghidra) |
| **Proposed name** | `CVOGObject_SetLocalPosition4_Gated_Inferred` (**Probable** role; product string absent) |
| **Prior scaffold alias** | `Named_VOG_DEBUG_STOP_004c3a40` — **misleading as primary name** (string is NaN trap only) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B; DriveControlTick callee) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ instructions) |
| **Counterpart** | `reviews/B_aa_004c3a40_CVOGObject_SetLocalPosition4_Gated_Inferred.md` |
| **Scratch** | `reviews/a_004c3a40.md` |
| **System** | `input-drive-control` (DCT callee) + object pose |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Gated writer of a **4-float** block into **`this+0x240..+0x24c`** (local position override / pose slot), after a **xyz NaN trap**:

1. `_isnan` on `in[0]`, `in[1]`, `in[2]` (promoted f32→f64). **W / `in[3]` is not NaN-checked.**
2. If any of xyz is NaN → `FUN_007a4480(0, "VOG_DEBUG_STOP")` then **fall through** (does not return early).
3. Gate: `typeOff = *(*(this+4)+4)`; allow store only if `(*(u8*)(this + typeOff + 0xb8) & 0xC7) == 0`.
4. On allow: `FUN_004cb3e0(this, in)` copies **four** dwords → `this+0x240, +0x244, +0x248, +0x24c`.

**Calling convention:** MSVC `__thiscall` — object in **ECX**, float* stack arg, **`ret 4`**.

**Not** a steer/thr axis setter. Distinct gate from `VehicleEntity_SetSteerInput` (pointer-at-`+0xb0` then `wobj+0xb4`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c3a40_FUN_004c3a40.md` |
| Annotated | `docs/reconstruction/raw/aa_004c3a40_FUN_004c3a40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004c3a40.cpp` |
| Named scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_004c3a40.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c3a40_FUN_004c3a40.md` |
| Store leaf | `FUN_004cb3e0` @ `0x004cb3e0` (live decompile + `read_memory`) |
| Sibling getter | `FUN_004c3ac0` @ `0x004c3ac0` (returns `this+0x240` when flags`&7==0`) |
| Debug trap | `FUN_007a4480` @ `0x007a4480` |
| Callers | DriveControlTick `0x009223b0`, `FUN_0091a5f0`, `FUN_005cc7c0` |
| System map | `docs/reconstruction/systems/input-drive-control.md` (look / `FUN_0091a5f0` residual) |

**This pass (live):** Ghidra `decompile_function` + `force_decompile` + `disassemble_function` @ `0x004c3a40` (three-rep CF); `read_memory` body + store leaf + string `0x00a15844`; `get_function_xrefs` / `get_assembly_context` on all four call sites; sibling `004c3ac0` / trap `007a4480` decompiles. **Not performed:** Launcher, runtime, bit-exact image diff, ledger updates.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `004c3a40`–`004c3ab0` (113 B, `ret 4`) | **High** | `disassemble_function` + `read_memory` |
| Thiscall ECX=object, stack=`float*` | **High** | `mov edi,ecx`; `mov esi,[esp+0xc]`; `ret 4` |
| NaN check on **xyz only** (`[0],[1],[2]`) | **High** | Three `fld`/`_isnan`; no `[esi+0xc]` |
| On NaN: call trap then **continue** (no early ret) | **High** | Fall-through to gate at `LAB_004c3a93` |
| Trap string `"VOG_DEBUG_STOP"` @ `0x00a15844` | **High** | `read_memory` ASCII |
| Trap arg0=`0` → **no log** (`FUN_007a4480` logs only if arg0==1) | **High** | Live decompile of trap body |
| Gate byte at `this + *(*(this+4)+4) + 0xb8` | **High** | `test byte [ecx+edi*1+0xb8],0xc7` |
| Mask immediate **`0xC7`** (199) | **High** | Instruction imm8 — not decompiler fiction |
| Closed gate → skip store, retain prior | **High** | `jnz` to epilogue |
| Store via `FUN_004cb3e0` → `+0x240..+0x24c` (4×u32) | **High** | Leaf bytes `mov [ecx+0x240]…+0x24c` |
| W stored even if unchecked for NaN | **High** | Leaf always copies dword3 |
| Sibling getter prefers `+0x240` when `(flags&7)==0` | **High** | Live `FUN_004c3ac0` |
| Gate **≠** SetSteer chain (`+0xb0` ptr → `wobj+0xb4`) | **High** | Direct component flag byte vs linked wobj |
| Callers: DCT ×1, `0091a5f0` ×2, `005cc7c0` ×1 | **High** | Live xrefs (4 sites / 3 functions) |
| DCT applies post-terrain helper then sets `object+0x304=1` | **High CF** | Asm context @ `0x00922866` |
| `FUN_0091a5f0` applies look-rotated position (then zero-look arm) | **High CF** | Live decompile + dual call sites |
| Product English class / method name | **Tentative** | No RTTI/string on body; `_Inferred` |
| Per-bit meaning of `0xC7` / `+0xb8` producers | **Open** | Mask sealed; UF — do not invent |
| Full consumer inventory of `+0x240` beyond getter | **Partial** | Getter sealed; other readers open |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ instructions

| Stage | Match |
|---|---|
| Load IAT `_isnan` into EBX | **Yes** (`mov ebx,[0x009c655c]`) |
| NaN xyz cascade; any hit → trap | **Yes** |
| Trap always followed by gate (no early return) | **Yes** |
| `typeOff=*(*(this+4)+4)`; `test [this+typeOff+0xb8],0xC7` | **Yes** |
| Open → push float*, `thiscall FUN_004cb3e0` | **Yes** |
| Closed → epilogue only | **Yes** |
| `ret 4` | **Yes** |
| No thr/steer/HB / no controller push | **Yes** |

### 4.1 Pseudocode (sealed)

```c
// __thiscall  ECX=object,  stack: float *in  (vec4; NaN on xyz only)
void CVOGObject_SetLocalPosition4_Gated_Inferred(Object *self, float *in)
{
    if (_isnan(in[0]) || _isnan(in[1]) || _isnan(in[2]))
        FUN_007a4480(0, "VOG_DEBUG_STOP");   // arg0==0 → no-op logger

    int typeOff = *(*(int **)(self + 4) + 1);  // *(*(self+4)+4)
    if ((*(uint8_t *)((uint8_t *)self + typeOff + 0xb8) & 0xC7) == 0)
        FUN_004cb3e0(self, in);               // self+0x240..0x24c = in[0..3]
}
```

### 4.2 Store leaf (`FUN_004cb3e0` @ `0x004cb3e0`)

```
mov eax, [esp+4]          ; in
mov edx, [eax]    ; → [ecx+0x240]
mov edx, [eax+4]  ; → [ecx+0x244]
mov edx, [eax+8]  ; → [ecx+0x248]
mov eax, [eax+0xc]; → [ecx+0x24c]
ret 4
```

Body of leaf ends `ret 4`; sole unconditional callers of leaf: **this function** + `FUN_005cd3b0` (bypass path — not dualed here).

### 4.3 Sibling getter contrast (`FUN_004c3ac0`)

| Path | Condition | Returns |
|------|-----------|---------|
| Local override | `(comp+0xb8 & 7) == 0` | `this + 0x240` |
| Phys body pos | else if `this+8 != 0` | `*(this+8)+0x3c + 0xb0` (rb world pos) |
| Embedded | else | `this + typeOff + 0x84` |

Write gate uses **`0xC7`** (bits 0–2 **and** 6–7); read selector uses **`7`** (bits 0–2 only). Consistent: when low bits clear, local `+0x240` is the active source **and** writable under full mask.

### 4.4 Gate vs SetSteerInput (do not collapse)

| Setter | Resolve | Flag | Store |
|--------|---------|------|-------|
| `SetSteerInput` `0x004f5620` | `wobj = *(this+typeOff+0xb0)` ptr | `wobj+0xb4 & 0xC7` (null allows write) | `this+0x618` f32 |
| **This unit** | **byte at `this+typeOff+0xb8`** | **same mask 0xC7** (no null-ptr arm) | **`this+0x240..24c` via leaf** |

Same **mask constant**, different **flag home** and **payload**.

---

## 5. Callers (live xrefs 2026-07-29)

| Function | VA | Sites | Role (CF) |
|----------|-----|-------|-----------|
| `Client_Input_DriveControlTick` | `0x009223b0` | `0x00922866` | After `FUN_004cff70` terrain-step helper; `ECX=object`, push stack vec4; then `object+0x304 = 1` |
| `FUN_0091a5f0` | `0x0091a5f0` | `0x0091a960`, `0x0091aa07` | Look helper: `FUN_004e8bf0` builds world pos from basis+look vec → set; second site zeros xyzw after forward scale when look xz==0 |
| `FUN_005cc7c0` | `0x005cc7c0` | `0x005cc7df` | Sets `*(host+0x64)+0x304=1`, `thiscall` on `*(host+0x64)` with arg vec |

**4** `UNCONDITIONAL_CALL` sites / **3** caller functions.

---

## 6. Gaps / open

1. Product method name / RTTI (remain `_Inferred`).
2. Full English meaning of component `+0xb8` bits and producers of `0xC7` (**UF — not invented**).
3. Exhaustive readers of `+0x240` beyond `FUN_004c3ac0` (and any other writers beyond leaf callers).
4. Runtime / differential under forced NaN and forced gate bits.
5. Deep dual of `FUN_0091a5f0` / `FUN_004cff70` / `FUN_005cc7c0` (out of OWN scope).
6. Whether `+0x240` is pure position vs padded vec4 (W often 0 at zero-look arm; leaf always copies 4).

**Verdict:** **accept-with-gaps** — body CF, NaN trap semantics, gate imm, store leaf layout, caller inventory, sibling getter linkage sealed static; package **not complete** (runtime / product name / bit producers).
