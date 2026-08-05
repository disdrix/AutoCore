# Review A (reconstruction fidelity): `aa_004370b0` stoChunkReader_EnterChunkScope

| Field | Value |
|---|---|
| **Stable ID** | `aa_004370b0` |
| **VA** | `0x004370b0`–`0x0043711a` |
| **Canonical name** | `stoChunkReader_EnterChunkScope` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004370b0_stoChunkReader_EnterChunkScope.md` |
| **System** | `storage` / arda2 `stoChunk` (scoped enter used by Unserialize paths) |
| **Verdict** | **accept-with-gaps** — ABI, scope layout, ring index math, OpenChunk ok-flag sealed; full ring-element product layout / absolute-pos English name open |

**Tools:** Ghidra `decompile_function` ×3 (`force_decompile` refresh) + `read_memory` body / call sites + `get_function_by_address` / callees / callers. No `disassemble_bytes`. Own VA only. No ledgers.

---

## 1. Purpose

RAII-style **chunk scope enter** used at the top of nearly every `Unserialize` path:

1. Bind caller's stack **scope** object to a `stoChunkReader*`.
2. Call `stoChunkReader_OpenChunk` on that reader (push next header onto the chunk ring).
3. Fill scope fields: **okFlag**, **stream absolute position**, **tag** (FOURCC), **version** from the ring's newest entry.
4. Return the scope pointer.

Callers then compare `scope.tag` to expected FOURCCs (`VERT`/`INDX`/`GPCE`/`PBON`/…), branch on `scope.version`, and on exit call leave (`FUN_00769e40` via okFlag gate) when `okFlag != 0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004370b0_FUN_004370b0.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004370b0_FUN_004370b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_EnterChunkScope.cpp` |
| Function record | `docs/reconstruction/functions/aa_004370b0_stoChunkReader_EnterChunkScope.md` |
| Live decompile | Ghidra `decompile_function` / `force_decompile` `0x004370b0` — **≡** raw body |
| Live bytes | `read_memory` `0x004370b0` length 128; tail `@0x00437100` |
| Function meta | body `004370b0`–`0043711a` |
| Callee | `stoChunkReader_OpenChunk` `0x0076a2c0` only |
| Call sites (ABI) | `FUN_0045e280` `@0x0045e290`, `FUN_00989850` `@0x00989860` |
| Sibling context (not owned) | OpenChunk dual `A/B_aa_0076a2c0`; leave `FUN_00769e40` `0x00769e40`; okFlag thunk `@0x00437120` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: **scope\*** in **ECX** |
| Stack args | **1** dword: **`stoChunkReader* reader`** |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | **scope\*** in **EAX** (`mov eax, esi`) |
| Body | `0x004370b0`–`0x0043711a` |

```c
// Canonical sealed signature
ChunkScope* __thiscall stoChunkReader_EnterChunkScope(
    ChunkScope* scope,          /* ECX */
    stoChunkReader* reader);    /* [esp+4], cleaned by RET 4 */
```

**Entry bytes (`read_memory` @ `0x004370b0`):**

```
56                 push  esi
8B F1              mov   esi, ecx           ; scope
8B 4C 24 08        mov   ecx, [esp+8]       ; reader (after push esi)
57                 push  edi
89 0E              mov   [esi], ecx         ; scope->reader = reader
E8 …               call  OpenChunk          ; ECX still = reader
…
8B C6              mov   eax, esi
5E                 pop   esi
C2 04 00           ret   4
```

**Call-site proof (`FUN_0045e280` @ `0x0045e290`):**

```
83 EC 14           sub   esp, 0x14          ; scope storage (0x14 bytes)
56                 push  esi
8B F1              mov   esi, ecx
57                 push  edi                ; stack arg = reader
8D 4C 24 08        lea   ecx, [esp+8]       ; this = scope
E8 …               call  EnterChunkScope
81 7C 24 10 …      cmp   [esp+0x10], 'KEYR' ; scope.tag (after return layout)
```

**Call-site proof (`FUN_00989850` @ `0x00989860`):**

```
83 EC 20           sub   esp, 0x20
56                 push  esi
53                 push  ebx                ; reader
8D 4C 24 14        lea   ecx, [esp+0x14]    ; scope
E8 …               call  EnterChunkScope
81 7C 24 1C 47 44 50 43   cmp [esp+0x1c], 'CPDG'
```

Ghidra prototype display is often `void` / single-arg at call sites — **bytes + RET 4 + lea ecx scope** own the ABI.

### 3.2 Scope object layout — **SEALED** (size **0x14**)

| Off | Width | Field | How filled |
|---:|---|---|---|
| `+0x00` | `ptr` | `reader` | `*scope = reader` before OpenChunk |
| `+0x04` | `u32` | `absPos` (plate: endPos) | `reader[+0x1c] + reader[+0x18]` |
| `+0x08` | `u8` | `okFlag` | `setge` from OpenChunk return (`signed >= 0`) |
| `+0x09..0x0b` | pad | — | not written |
| `+0x0c` | `u32` | `tag` FOURCC | `*ringEntry` (entry dword 0) |
| `+0x10` | `u32` | `version` | `*(ringEntry + 8)` |

Callers allocate **`sub esp, 0x14`** (or larger frames with scope embedded) and read tag/version/okFlag at these offsets.

### 3.3 OpenChunk interaction — **SEALED**

```
scope->reader = reader;
hr = stoChunkReader_OpenChunk(reader);   // thiscall ECX=reader
scope->okFlag = (int)hr >= 0;            // setge; OpenChunk: 0 ok, -1 fail
```

- Does **not** early-out on fail: still computes absPos / tag / version from ring state after OpenChunk returns.
- `okFlag` is the gate callers use before `FUN_00769e40` leave (`if (local_ok) leave(reader)`).

### 3.4 Ring index math — **SEALED**

Ring object base = `reader + 0x4030` (matches OpenChunk dual):

| Ring rel | Absolute | Role in this unit |
|---:|---:|---|
| `+0x04` | `reader+0x4034` | pointer array of ring entries |
| `+0x08` | `reader+0x4038` | capacity (wrap modulus) |
| `+0x0c` | `reader+0x403c` | base / start index |
| `+0x10` | `reader+0x4040` | write / depth index |

```
idx = (reader[+0x4040] + reader[+0x403c]) - 1;
if (idx >= reader[+0x4038]) idx -= reader[+0x4038];
entry = *(ptr*)( *(reader[+0x4034]) + idx*4 );  // array of entry*
tag     = *(u32*)entry;        // +0
version = *(u32*)(entry + 8);  // +8
```

Computed **twice** (identical formula) for tag then version — not a shared local in retail code.

### 3.5 Stream absolute position — **SEALED formula**, name **Probable**

```
scope[+4] = *(reader+0x1c) + *(reader+0x18);
```

Same stream partners OpenChunk uses for cursor/base (`+0x18` cursor, `+0x1c` base partner). Plate labels field **endPos**; after OpenChunk binary path the cursor sits past the 16-byte header, so this is **absolute stream position at enter** (body start after header), not necessarily chunk-end. Leave uses ring entry `+0x10` for seek target (not this field) — English name kept as plate `endPos` / docs `absPos`.

### 3.6 Control flow — **SEALED** (linear)

```
ECX=scope, stack=reader
scope.reader = reader
OpenChunk(reader) → okFlag
absPos = reader.base + reader.cursor
ring = reader+0x4030
idx = wrap(ring.write + ring.base - 1, ring.capacity)
scope.tag = *entries[idx]
idx = wrap(...) again
scope.version = entries[idx]->version (+8)
return scope
```

No branches except the two capacity-wrap `ja` / `sub` pairs. No SEH in this leaf.

### 3.7 Three-rep CF fidelity

| Pass | Source | Match |
|---|---|---|
| Raw 2026-07-23 | `raw/aa_004370b0_FUN_004370b0.md` | baseline |
| Live re-decompile 2026-07-29 | `decompile_function` | **≡** raw |
| Force refresh 2026-07-29 | `force_decompile` | **≡** raw |
| Bytes | `read_memory` full body | ABI + offsets + wrap + RET 4 sealed |

---

## 4. Call graph (inventory only)

| Direction | Symbol | VA | Note |
|---|---|---|---|
| Callee | `stoChunkReader_OpenChunk` | `0x0076a2c0` | sole call |
| Callers | many Unserialize / asset loaders | (30+ from first page of `get_function_callers`) | e.g. `gfxGeometryPiece_Unserialize`, `gfxIndexBufferImpl_Unserialize`, `gfxVertexBufferImpl_Unserialize`, `phyBone_unserialize`, `effEffect_Unserialize`, KEYR/CPDG readers, … |

Full caller enumeration not required for accept-with-gaps on this leaf helper.

---

## 5. Gaps / open

1. Full **ring entry** struct (size **0x14** Probable from OpenChunk dual): this unit only reads `+0` tag and `+8` version; size/reserved/end at other slots not touched here.
2. Product English name for `scope[+4]` (endPos vs bodyStart vs cursorAbs).
3. Whether OpenChunk fail leaves a valid ring top (tag/version still read unconditionally — fail-path ring contents **Probable** stale/empty).
4. Runtime live verification / bit-exact image diff.
5. Leave-scope pairing contract owned by `FUN_00769e40` / thunk `0x00437120` (sibling).

---

## 6. Verdict

**accept-with-gaps** — dual-ready sealed ABI + scope layout + ring wrap + OpenChunk ok mapping; naming of absPos and full entry layout remain gaps.
