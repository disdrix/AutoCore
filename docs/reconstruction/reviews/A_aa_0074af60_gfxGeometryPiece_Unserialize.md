# Review A (reconstruction fidelity): `aa_0074af60` gfxGeometryPiece_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074af60` |
| **VA** | `0x0074af60` |
| **Canonical name** | `gfxGeometryPiece_Unserialize` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B create) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0074af60_gfxGeometryPiece_Unserialize.md` |
| **System** | `graphics / gfx` (asset I/O — GPCE chunk) |
| **Dual status** | **Present** (A + B modern pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`gfxGeometryPiece::Unserialize` — read one **GPCE** chunk (`0x47504345` = file bytes **ECPG**) from a `stoChunkReader` into a geometry-piece object.

1. `stoChunkReader_EnterChunkScope(reader)` → scope `{okFlag, tag, version}` on stack.
2. Require `tag == 0x47504345`; else log `gfxGeometryPiece.cpp:0xd6` and return **−1**.
3. If `FUN_00767120()` non-zero → scope cleanup and return **0** (soft skip; not hard fail).
4. Dispatch on **version** `local_80`:
   - **10** — modern path (matches current Serialize write version).
   - **9** — shared with 8 after a flags/read prelude.
   - **8** — falls into shared v8/v9 body.
   - else — log `…:0x164` invalid version → **−1**.
5. Shared success tail: effect + index (+ vertex or dual-temp vertex path) + post hooks + name/string hashes + USDA-like tail helpers; return reader status mapped to **0 / −1**.

Source plate (Ghidra): `palantir\graphics\gfxGeometryPiece.cpp` lines **0xd6** / **0x164**.

Does **not** write GPCE (that is `gfxGeometryPiece_Serialize` `0x0074ac40`, always **version 10**).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0074af60_gfxGeometryPiece_Unserialize.md` |
| Annotated | `docs/reconstruction/raw/aa_0074af60_gfxGeometryPiece_Unserialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxGeometryPiece_Unserialize.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074af60_gfxGeometryPiece_Unserialize.md` |
| Fresh decompile | Ghidra MCP `decompile_function` @ `0x0074af60` (2026-07-29) — CF ≡ 2026-07-23 raw |
| Full analysis | `analyze_function_complete` — 3 xrefs, 2 callers, callee set listed |
| Memory | `read_memory` @ `0x0074af9b` — `CMP [esp+0x1c], 0x47504345` bytes `45 43 50 47` (**ECPG**) |
| Scope helper | decompile `stoChunkReader_EnterChunkScope` `0x004370b0` (tag/version fill) |
| Serialize twin | raw `aa_0074ac40` (BeginChunk GPCE v10; offset mirror) |
| Callers (named) | `FUN_00739c80` / morphed piece; `FUN_009991b0` / skinned piece |

**Not performed:** `disassemble_bytes`, Launcher, live asset load, binary diff, deep callee duals for every FUN_*.

---

## 3. Sealed facts (body + helpers)

### 3.1 Signature / convention

| Claim | Evidence | Conf |
|---|---|---|
| **`__thiscall`**, piece in ECX (`param_1`), reader stack formal (`param_2`) | Decompiler prototype; locals use `param_1+…` stores; scope enter takes reader | **High** |
| Return **int**: **−1** fail, **0** success or soft-skip | Explicit `return -1` / `return 0`; success `iVar8 = (-1 < *(reader+0x402c)) - 1` → **0** if status ≥ 0 else **−1** | **High** |
| `param_1` is **this+4** relative to Serialize’s `int *this` | Unserialize stores/vtbl via `param_1-4`; Serialize uses full-object indices (`[0x16]`→+0x58 ≡ unserialize `+0x54`, etc.) | **High** |
| SEH frame `LAB_009b3065` | Standard C++ EH prologue/epilogue around scope | **High** |

### 3.2 Tag / version / scope locals

`EnterChunkScope` fills scope: reader, endPos, **okFlag** (byte), **tag** (u32 4CC), **version** (u32). In this body:

| Local | Stack | Role | Conf |
|---|---|---|---|
| `local_88` | `Stack[-0x88]` | scope **okFlag** (byte); gates `FUN_00769e40` leave | **High** |
| `local_84` | `Stack[-0x84]` | scope **tag**; must be `0x47504345` | **High** |
| `local_80` | `Stack[-0x80]` | scope **version**; accept 8 / 9 / 10 | **High** |
| `local_98` | `Stack[-0x98]` | flags / mode dword after `FUN_00439a50` + `FUN_00437990` | **Probable** |

Imm at CMP site sealed by `read_memory`: **`0x47504345`**.

### 3.3 Control flow (clean ≡ raw ≡ live decomp)

```
EnterChunkScope(reader)
if tag != GPCE(0x47504345): log :0xd6 → return -1
if FUN_00767120(): return 0          // soft skip
if version == 10:
  read flags; effect@+0x1c; index@+4; vertex@+0xc; post; string tail → success
else if version == 9:
  read flags prelude; fall into v8/v9 body
else if version == 8:
  fall into v8/v9 body
else:
  log :0x164 → return -1

v8/v9 body:
  effect_Unserialize(+0x1c); index FUN_009a00d0(+4);
  if local_98 == 2: dual-temp vertex path (stack objects) else FUN_009a0000(+0xc)
  vtbl[+0x78](effect); FUN_0074ce60; flag +0x50 → clear or |1 at +0xb8
  string/hash tail (same stores as v10) → success

success:
  ret = (reader[+0x402c] >= 0) ? 0 : -1
  dtor temps; leave scope; return ret

effect/index fail / hard paths → LAB_0074b044 return -1
```

| Stage | Raw | Clean | Live | Match |
|---|---|---|---|---|
| Tag gate + line 0xd6 log | Yes | Yes | Yes | **Yes** |
| Soft skip via `FUN_00767120` → 0 | Yes | Yes | Yes | **Yes** |
| Versions 8 / 9 / 10 only | Yes | Yes | Yes | **Yes** |
| v10: effect → index → vertex (no dual-temp) | Yes | Yes | Yes | **Yes** |
| v8/v9: `local_98==2` dual-temp vs direct vertex | Yes | Yes | Yes | **Yes** |
| Success map `reader+0x402c` | Yes | Yes | Yes | **Yes** |
| No invented version 11+ | — | None | — | **Yes** |

### 3.4 Piece field offsets (Unserialize `param_1` = Serialize this+4)

| Offset (param_1) | Object (Serialize this) | Role | Conf |
|---|---|---|---|
| `−4` | `+0` | vptr; virtuals `+0x78`, `+0x64` (100) | **High** |
| `+4` | `+8` | index-buffer object / unserialize target (`FUN_009a00d0`) | **High** (pair w/ Serialize index) |
| `+0xc` | `+0x10` | vertex-buffer object (`FUN_009a0000`) | **High** |
| `+0x1c` | `+0x20` | effect object (`effEffect_Unserialize`) | **High** |
| `+0x50` | `+0x54` | char gate: 0 → `FUN_00414b20(0)`; else set bit | **High** CF; product name **open** |
| `+0x54` | `+0x58` | u32 from `FUN_00989e00` on first string | **High** store; semantic **Probable** (name hash) |
| `+0x70` | `+0x74` | store from post-`FUN_00436900` (decomp `unaff_EBX`) | **Probable** (value source residual) |
| `+0x8c` | `+0x90` | u32 from second string hash | **High** store |
| `+0x90` | `+0x94` | u32 from third string hash | **High** store |
| `+0xb8` | `+0xbc` | flags `|= 1` when `+0x50` non-zero | **High** |

Serialize mirror: `BeginChunk(0x47504345, 10)`; string slots `param_1[0x16]`, `[0x24]`, `[0x25]`; flag bit at `*(byte*)(param_1+0x2f) & 1` ↔ unserialize `+0xb8` bit 0.

### 3.5 Notable callees (boundary roles only)

| Callee | Role in this body | Conf |
|---|---|---|
| `stoChunkReader_EnterChunkScope` | Open current chunk into stack scope | **High** |
| `FUN_00767120` | Soft-skip predicate → return 0 | **High** CF; English **open** |
| `FUN_00439a50` / `FUN_00437990` | Read piece flags / mode into `local_98` | **Probable** |
| `effEffect_Unserialize` | EFCT under piece (`+0x1c`) | **High** |
| `FUN_009a00d0` | Index buffer unserialize (`+4`) | **High** (INDX sibling per Serialize plate) |
| `FUN_009a0000` | Vertex buffer unserialize (`+0xc` or stack temps) | **High** (VERT sibling) |
| `FUN_00439a20` / `FUN_00439a00` / `FUN_00436900` | Reader string / blob helpers for name tail | **Probable** |
| `FUN_00989e00` | Hash/pack string → dword stored on piece | **Probable** |
| `FUN_007496c0` | Post-name piece fixup | **Tentative** |
| `FUN_0074ce60` | Post-effect/vertex piece hook | **Tentative** |
| `vog_LogMessage` | Invalid tag / version | **High** |
| `FUN_00769e40` | Leave chunk scope when okFlag set | **High** CF |

### 3.6 Callers (static)

| Caller | Sites | Notes |
|---|---|---|
| `FUN_00739c80` (`Named_gfxGeometryPieceMorphed`) | `0x00739d5f`, `0x00739e3e` | Two unserialize calls in morph path |
| `FUN_009991b0` (`Named_gfxGeometryPieceSkinned`) | `0x0099927e` | Skinned piece path |

Xref count **3** (matches complete analysis). No other Ghidra xrefs at dual time.

---

## 4. Clean vs raw fidelity

- Clean plate CF **mirrors** raw / live decompile; typing comments only (`uint32_t` width notes).
- Plate comment (effect@+0x1c, index@+4, vertex@+0xc, GPCE v8–10, disk tail bodyName / pieceName / ADSU LODLevel) is **consistent** with body order and Serialize twin; ADSU key English is **plate-level Probable** (not re-proven from this body’s immediates).
- Residual decompiler noise: `unaff_EBX`, over-starred string SSO temps, virtual call arg packaging — CF still sealed.

---

## 5. Open questions (do not block accept-with-gaps)

1. Exact product name of `FUN_00767120` soft-skip (empty child? wrong nesting?).
2. Full English for `local_98 == 2` dual-temp vertex branch (legacy split VERT?).
3. Precise identity of string fields at `+0x54/+0x8c/+0x90` (bodyName / numeric / pieceName) — Serialize order + plate suggest three names; not re-read from string literals in this dual.
4. Virtuals at vtbl `+0x78` and `+100` product names.
5. Runtime / bit-exact asset round-trip not run.

---

## 6. Verdict

**accept-with-gaps**

- **High:** GPCE tag, versions 8/9/10, return codes, effect/index/vertex order, key piece offsets, this+4 vs Serialize, caller set, clean≡raw CF.
- **Gaps:** soft-skip helper English, `local_98==2` semantics, string field product names, several FUN_* / vtbl slot names, no runtime proof.
