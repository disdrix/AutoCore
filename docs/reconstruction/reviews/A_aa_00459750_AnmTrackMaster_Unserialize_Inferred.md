# Review A (reconstruction fidelity): `aa_00459750` AnmTrackMaster_Unserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00459750` |
| **VA** | `0x00459750`–`0x00459a5a` (**779 B** / `0x30B`) |
| **Canonical name** | `AnmTrackMaster_Unserialize_Inferred` |
| **Ghidra name** | `FUN_00459750` |
| **Review date** | `2026-07-29` (W36-M dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-M) |
| **Counterpart** | `reviews/B_aa_00459750_AnmTrackMaster_Unserialize_Inferred.md` |
| **System** | palantir/animation — `anmTrackMaster_inl` chunk unserialize |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body hex) + `analyze_function_complete` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Worker unserialize for animation track-master chunks:

1. SEH frame + `stoChunkReader_EnterChunkScope`.
2. Accept host tags **PBAM** (`0x5042414D`) or **TRAK** (`0x5452414B`); else log `anmTrackMaster_inl.h` → fail **-1**.
3. Dual I/O via `*(ctx+0x4044)` (legacy `FUN_004*` vs modern `FUN_007*`).
4. Version gates; optional subchunk / vtable fourCC → type at **`this+0x10`** (**EFCT** or **SKEL**).
5. String reads → `FUN_00989e00` hashes at **`this+0x14` / `+0x18`**.
6. Int reads; **count** → resize **Pod28** vector at **`this+0x1C`** via sealed `StdVector_Resize_Pod28` (`FUN_0045c4b0`).
7. If count &gt; 0, `FUN_0045dd60` element path; success **0**, mid-fail **-2**, else **-1**.
8. `RET 4`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-M append) | `docs/reconstruction/raw/aa_00459750_FUN_00459750.md` |
| Annotated | `docs/reconstruction/raw/aa_00459750_FUN_00459750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnmTrackMaster_Unserialize_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00459750.cpp` |
| Function records | `functions/aa_00459750_FUN_00459750.md`, `functions/aa_00459750_AnmTrackMaster_Unserialize_Inferred.md` |
| Live | decompile ≡ tag/resize/return sites in bytes |
| Pair | `StdUninitFillN_Elem28_CountEcx_Inferred` (`0x0046a260`) — same dual wave |

---

## 3. Signature (sealed — bytes win)

```c
// thiscall; one stack formal; RET 4
uint32_t __thiscall AnmTrackMaster_Unserialize_Inferred(
    void* self /*ECX*/,
    void* ctx /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| this | ECX → EBX | **High** |
| ctx* | stack formal; used as `ctx+0x4044` | **High** |
| RET | `C2 04 00` | **High** |
| returns | 0 / `0xFFFFFFFE` / `0xFFFFFFFF` | **High** |
| vec | `this+0x1C` before `FUN_0045c4b0` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes highlights)

```
enter_chunk_scope
if tag ∉ {PBAM, TRAK}: log → cleanup → -1
version / dual-I/O field reads
type fourCC: (read == 0x4B455556) ? EFCT : SKEL → this+0x10
strings → hashes this+0x14 / +0x18
ints; count = …
StdVector_Resize_Pod28(this+0x1C, count, value_blob_0x1c)
if count > 0:
  if FUN_0045dd60 fails-or-zero-path: cleanup → 0 or continue
cleanup; return 0 / -1 / -2
```

| Stage | Match | Conf |
|---|---|---|
| Tag immediates in bytes | **Yes** (`CMP EAX, 'MABP'/'KART'` LE imm) | **High** |
| Path string log | **Yes** | **High** |
| Resize call site @ `0x004599bf` | **Yes** → `0045c4b0` | **High** |
| EFCT/SKEL select arith | **Yes** (`SUB 0x4B455556` / mask / `ADD EFCT`) | **High** |
| Nested helper formal maps | residual | **Med** |

---

## 5. Machine bytes (`read_memory`)

Full 779 B hex: raw W36-M append.

Key seals:

- Entry SEH: `6A FF 68 CA EF 9B 00 …`
- Tags: `3D 4D 41 42 50` / `3D 4B 41 52 54`
- Resize: `83 EC 1C; 83 C3 1C; 8B CE; E8 EC 2A 00 00` → `FUN_0045c4b0`
- Success epilog: `33 C0 … C2 04 00`
- Fail epilog: `83 C8 FF … C2 04 00`

---

## 6. Gaps (do not block structural seal)

- Product/PDB demangle English for class/method.
- Full track-object field map beyond sealed offsets.
- Nested duals (`FUN_0045dd60`, I/O readers, hash) unowned.
- DATA slot `0x00aa3d54` owner table not dual-owned.
- Runtime / bit-exact / differential.

---

## 7. Verdict

ABI, tags, resize site, returns, and dual-I/O shape sealed → **accept-with-gaps**.
