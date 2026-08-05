# Review A (reconstruction fidelity): `aa_00436090` stoChunkReader_readF32Array

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436090` |
| **VA** | `0x00436090` |
| **Body span** | `00436090` – `00436127` |
| **Canonical name** | `stoChunkReader_readF32Array` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory` of body) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_00436090_stoChunkReader_readF32Array.md` |
| **System** | `sto-chunk` / asset serialize |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Read **N** little-endian **float32** values from a `stoChunkReader` stream into a caller-supplied destination array.

1. **N** arrives in **EAX** (not a stack/this param).
2. **Destination** pointer arrives in **ECX** (Ghidra `__thiscall` “this”).
3. **Reader** pointer is the sole stack argument (`ret 4`).
4. Branch on **`reader+0x4044`**:
   - **`== 0` (binary path):** if `N >= 16`, bulk-copy `N*4` bytes via `FUN_00435f30` on the stream subobject at **`reader+0x14`**; else element loop (0…15) with optional refill via `FUN_00435df0`.
   - **`!= 0` (non-binary path):** element loop calling `FUN_00767fd0(reader, dest_elem)` once per float (plate comment says “byte-swap”; callee role remains a residual — text/token path is plausible from sibling raw only).

Used heavily by physics/asset unserialize sites (e.g. `phyBoneSharedData_unserialize` for hkQsTransform components; multiple `FUN_0045d*` KEYR-style readers; `FUN_0074ce60` multi-vector reads).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00436090_stoChunkReader_readF32Array.md` |
| Annotated | `docs/reconstruction/raw/aa_00436090_stoChunkReader_readF32Array.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_readF32Array.cpp` |
| Function record | `docs/reconstruction/functions/aa_00436090_stoChunkReader_readF32Array.md` |

**This pass (live, OWN VA only):**

- Ghidra MCP `decompile_function` @ `0x00436090` — matches raw plate + body CF.
- Ghidra MCP `read_memory` @ `0x00436090` length 200 — body ends `C2 04 00` at `0x00436127`; three `E8` callees resolve to `FUN_00435df0`, `FUN_00435f30`, `FUN_00767fd0`.
- `get_xrefs_to` — 30+ call sites (physics/asset unserialize).
- **Not performed:** Launcher, runtime golden, bit-exact binary diff; **no ownership** of callee VAs `0x00435df0` / `0x00435f30` / `0x00767fd0`.

---

## 3. Calling convention (assembly-sealed on OWN body)

| Slot | Role | Evidence |
|---|---|---|
| **EAX** | `count` (signed `int`, number of f32) | `cmp eax, 10h` / `sub eax, 1` / loop counter from count |
| **ECX** | `float *dest` | `mov edi, ecx` then stores `[edi]`, `add edi, 4` |
| **[esp+4]** (pre-push) | `stoChunkReader *reader` | `mov esi, [esp+0xc]` after two pushes; `ret 4` |
| **Return** | `uint32` status | `xor eax,eax` → `0` on element paths; bulk path returns `FUN_00435f30` result |

Ghidra signature `undefined4 __thiscall (undefined4 *param_1 /*dest*/, int param_2 /*reader*/)` with `in_EAX` count is **behaviorally correct** for ports; semantic names should treat ECX as dest buffer, not “chunk reader this”.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `00436090`–`00436127`, `ret 4` | **High** | `read_memory` + function bounds |
| Count in EAX; dest ECX; reader stack | **High** | Own body asm |
| Mode gate `*(reader+0x4044)==0` binary vs non-zero alt | **High** | Live decompile ≡ asm `cmp [esi+0x4044],0` |
| Bulk threshold **signed** `count >= 16` (`jge` after `cmp eax,10h`) | **High** | Decompiler `0xf < in_EAX` ≡ same |
| Bulk: `FUN_00435f30(reader+0x14, dest, count*4)` | **High (asm)** | `lea ecx,[esi+0x14]`; push size; push dest — decompiler/clean collapse this to 2-arg form |
| Small binary loop only when `count > 0` | **High** | `sub eax,1` / `js` skip |
| Cursor at `reader+0x18`, end/avail at `reader+0x20`, stream helper base `reader+0x1c`, payload window `reader+0x2c+cursor` | **High** | After `add esi,0x14`, offsets `+4/+0xc/+8/+0x18` map back to `+0x18/+0x20/+0x1c/+0x2c` |
| Read guard: `(cursor+4 <= avail) \|\| (refill≥0 && avail > 3)` then store f32 + `cursor+=4` | **High** | Live decompile |
| Dest/count always advance even if guard fails (slot may stay unwritten) | **High CF** | Store is inside `if`; pointer++ outside |
| Non-binary loop: `FUN_00767fd0` with this=reader, stack=dest elem | **High CF (call shape)** | Asm `push edi; mov ecx,esi; call` |
| `FUN_00767fd0` is “byte-swap f32” | **Tentative** | Plate comment only; callee not owned this dual |
| Clean ≡ raw decompiler CF | **High** | Scaffold rewrite; no modernization |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 5. Control flow checklist (clean ≡ raw ≡ live)

| Stage | Match |
|---|---|
| Mode `+0x4044 == 0` | **Yes** |
| Binary bulk `count >= 16` → `FUN_00435f30` → return its status | **Yes** (arg packing residual: clean shows 2-arg) |
| Binary small: `count > 0` loop | **Yes** |
| Per-elem buffer guard + optional `FUN_00435df0` refill | **Yes** |
| Store LE dword @ `reader+0x2c+cursor`; `cursor += 4` | **Yes** |
| Always `dest++`, `count--` | **Yes** |
| Binary small success return `0` | **Yes** |
| Non-binary: `count > 0` loop `FUN_00767fd0` | **Yes** |
| Non-binary / empty count return `0` | **Yes** |
| No invent writes beyond dest stride / cursor | **Yes** |

---

## 6. Reader field map (this unit only)

| Offset | Role in this function | Confidence |
|---|---|---|
| `+0x4044` | Mode: 0 = binary f32 path; ≠0 = alt path | **High** |
| `+0x18` | Byte cursor into payload window | **High** |
| `+0x1c` | Refill base (passed into `FUN_00435df0` as `base+cursor`) | **High use; layout name Probable** |
| `+0x20` | Available/end bound vs cursor | **High** |
| `+0x2c` | Start of inline payload bytes (index by cursor) | **High** |
| `+0x14` | Base of stream subobject passed as `this` to bulk/refill helpers | **High (asm)** |

---

## 7. Gaps

1. **Bulk call packaging in clean/raw decompiler** omits explicit `this = reader+0x14` (assembly is authoritative).
2. **`FUN_00767fd0` semantics** (endian swap vs text parse vs other) not sealed on this dual — OWN VA only.
3. **Failed small-path guard** leaves `*dest` unchanged but still advances — intentional soft-fail vs bug is product-open.
4. **Negative count:** signed compares; values in `1..15` loop, `>=16` bulk, `<=0` no-op return 0 — no clamp.
5. Runtime / differential verification **Open**.

**Verdict:** **accept-with-gaps** — CF sealed High for AutoCore sto-chunk ports; treat bulk `this` adjustment and alt-path callee as residual evidence, not production codec names.
