# Review A (reconstruction fidelity): `aa_0074ac40` gfxGeometryPiece_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ac40` |
| **VA** | `0x0074ac40` |
| **Canonical name** | `gfxGeometryPiece_Serialize` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual-w6-gfxser) |
| **Counterpart** | `reviews/B_aa_0074ac40_gfxGeometryPiece_Serialize.md` |
| **System** | `graphics / gfx` (asset I/O — sto chunk tree) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Serialize one mesh section (`gfxGeometryPiece`) into a **GPCE** sto chunk (**file tag bytes `ECPG`**, Ghidra dword `0x47504345`), **version 10**. One GPCE per section under a GBOD (`DOBG`) root. Body writes, in order: has-effect byte → **EFCT** effect subtree → **INDX** (optional) → **VERT** (plain or morph path) → optional vfunc → **BBOX** → name strings / scalar tail → **USDA** key/value tail → `stoChunkWriter_EndChunk`. Return value is the **bitwise OR** of all writer status bits collected along the path.

Source plate (Ghidra): `palantir\graphics\gfxGeometryPiece.cpp`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0074ac40_gfxGeometryPiece_Serialize.md` |
| Annotated | `docs/reconstruction/raw/aa_0074ac40_gfxGeometryPiece_Serialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxGeometryPiece_Serialize.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074ac40_gfxGeometryPiece_Serialize.md` |
| Live decompile | Ghidra MCP `decompile_function` @ `0x0074ac40` (2026-07-29) |
| Body | `0x0074ac40`–`0x0074af5a` |
| Entry bytes | `read_memory` @ `0x0074ac40` — `push 10; push 'ECPG'` before `stoChunkWriter_BeginChunk` |
| Callees (batch) | `0x004399a0`, `0x0096f890`, `0x0074bda0`, `0x00748800`, `0x00439810`, `0x00439870`, `0x00436f80` |
| Xrefs | `FUN_00739a60` @ `0x00739a9f`, `FUN_00999040` @ `0x0099907b` (+ vtbl/data refs) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name `gfxGeometryPiece_Serialize` / GPCE asset path | **High** | Ghidra symbol + plate path + chunk tag |
| `BeginChunk(0x47504345 /*GPCE/ECPG*/, 10)` | **High** | Decompile + entry `6a 0a 68 45 43 50 47` |
| Has-effect byte via `FUN_004399a0` (1-byte writer) | **High** | Callee decompile: vtbl+0x18 write size 1; asm loads `(this+0xbc)>>6 & 1` into stack byte |
| Effect at `this+0x20` → `FUN_0096f890` → **EFCT** `0x45464354` v3 | **High** | `param_1 + 8` dword index; callee BeginChunk EFCT/3 |
| Index: null `this+0x0c` (`param_1[3]`) → status `1`; else `gfxIndexBufferImpl_Serialize` | **High** | Raw CF |
| Vertex: null morph `this+0x1c` (`param_1[7]`) → plain `this+0x14` (`param_1[5]`) serialize or status `1` | **High** | Raw CF |
| Morph path uses temp buffer, `FUN_00746910`/`FUN_00747390`, `FUN_00414c20`, dual `FUN_0044bbc0` on `this+0x10`/`this+0x18`, forces `uVar5=1` | **High** CF; morph **semantics Probable** | Exact morph math not sealed here |
| Optional `vtbl+0x5c` when `*(byte*)(this+0xbc) & 1` | **High** gate; **Tentative** English | Raw: `param_1 + 0x2f` as int* → byte @ `+0xbc` |
| `FUN_0074bda0` → **BBOX** `0x42424f58` v2 | **High** | Callee BeginChunk XOBB/2 + 3× float-ish writes + color helper |
| Three strings: `this+0x58`, `+0x90`, `+0x94` (`[0x16]`,`[0x24]`,`[0x25]`) via `FUN_00436f80` / text `FUN_00767160("%s")` | **High** offsets; **Probable** names | Null → empty-string fallback `PTR_DAT_00afa2bc` → `""` |
| Writer dual-mode: `param_2[7]==0` binary path vs text path + `\r\n` (`DAT_00a97b84`) | **High** | Repeated pattern; `DAT_00a9d6f8` = `"%s"` |
| `FUN_00748800(this)` → **USDA** `0x55534441` v1 key/value from `this+0x9c`/`+0xa0` | **High** | Callee decompile; plate “LODLevel” key is source comment (not re-proven in this VA) |
| Interleaved `FUN_00439810` (u32) / `FUN_00439870` (f32-ish) around name tail | **High** that they write 4-byte scalars; **Tentative** which piece fields (EAX lost) | Decompiler register helpers |
| `EndChunk` + OR of all status words | **High** | Return expression |
| Clean ≡ raw control flow | **High** | Clean is raw-faithful (warnings only) |
| Bit-exact file emit / runtime golden | **Open** | Not run |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH prolog / `BeginChunk(GPCE,10)` | **Yes** |
| Has-effect byte + EFCT at `this+0x20` | **Yes** |
| INDX null-or-serialize | **Yes** |
| VERT plain vs morph branch | **Yes** |
| Optional vtbl+0x5c | **Yes** |
| BBOX + three strings + USDA + scalar tail | **Yes** |
| `EndChunk` + OR return | **Yes** |
| No invented modern packing | **Yes** |

---

## 5. Object / writer layout (this VA only)

| Offset (byte) | Decompiler form | Role (sealed vs inferred) |
|---|---|---|
| `+0x00` | `*param_1` | vtbl — `+0x5c` optional serialize hook |
| `+0x0c` | `param_1[3]` | Index buffer impl* — null → skip INDX status=1 |
| `+0x10` / `+0x18` | `param_1+4` / `+6` | Morph path `FUN_0044bbc0` targets |
| `+0x14` | `param_1[5]` | Vertex buffer impl* (+`+0x18` used in morph) |
| `+0x1c` | `param_1[7]` | Morph source* (`+0x24` into `FUN_004451c0`) |
| `+0x20` | `param_1+8` | Effect object for EFCT serialize |
| `+0x58` | `param_1[0x16]` | Name string* |
| `+0x90` | `param_1[0x24]` | Name string* |
| `+0x94` | `param_1[0x25]` | Name string* |
| `+0x9c` / `+0xa0` | (via USDA callee) | USDA pair vector begin/end |
| `+0xbc` | byte @ `param_1+0x2f` | Flags: bit0 → vtbl+0x5c; asm also `(dword>>6)&1` for has-effect |

| Writer (`param_2`) | Role |
|---|---|
| `[0]` | Stream vtbl* — `+0x18` write primitive |
| `[1]` | Accumulated status (OR’d) |
| `[7]` | Mode: 0 = binary, non-0 = text |
| `[8]` | Cleared on text string write path |

---

## 6. Chunk contract (callee-proven tags)

| Tag dword | ASCII (LE file) | Ver | Producer in this path |
|---|---|---|---|
| `0x47504345` | `ECPG` / GPCE | 10 | this function |
| `0x45464354` | `TCFE` / EFCT | 3 | `FUN_0096f890` |
| `0x42424f58` | `XOBB` / BBOX | 2 | `FUN_0074bda0` |
| `0x55534441` | `ADSU` / USDA | 1 | `FUN_00748800` |
| (INDX/VERT) | named callees | — | `gfxIndexBufferImpl_Serialize` / `gfxVertexBufferImpl_Serialize` |

---

## 7. Gaps / open

1. Exact English names of the three strings (`+0x58/+0x90/+0x94`) — plate says “name strings”; not PDB-sealed here.
2. Which piece fields feed the EAX-based `FUN_00439810` / `FUN_00439870` calls (decompiler drops addresses).
3. Morph-path callees (`FUN_004451c0`, `FUN_00746910`, `FUN_00747390`, `FUN_00414c20`, `FUN_0044bbc0`, `FUN_00414b60`) — CF sealed, body ownership elsewhere.
4. Has-effect bit `(this+0xbc)>>6&1` vs plate “has-effect” — asm-proven; full flag register not mapped.
5. Pair with Unserialize `0x0074af60` for bit-exact round-trip (separate OWN VA).
6. Runtime / golden GPCE dump; no Launcher/runtime in this dual.

**Verdict:** **accept-with-gaps** — CF, chunk tags, and major `this` offsets High; residual morph internals + scalar EAX fields + string English names.
