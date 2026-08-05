# Review A (reconstruction fidelity): `aa_0076a900` stoChunkReader_PeekChunkTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a900` |
| **VA** | `0x0076a900`–`0x0076aac9` |
| **Canonical name (Ghidra)** | `FUN_0076a900` |
| **Proposed name** | `stoChunkReader_PeekChunkTag` (**High** role; plate absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_gfxBodyMassageMachine_0076a900` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W19-R) |
| **Reviewer role** | Reconstruction fidelity (chunk stream peek) |
| **Counterpart** | `reviews/B_aa_0076a900_stoChunkReader_PeekChunkTag.md` |
| **System** | storage / arda2 `stoChunk` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Peek the next chunk FOURCC on a `stoChunkReader` without permanently consuming the stream.**

Body:

1. Save absolute cursor (`+0x1c + +0x18`) and pending string (`+0x404c`).
2. **Binary** (`+0x4044==0`): `OpenChunk` → read ring tag → nest--.
3. **Text** (`+0x4044==1`): parse token, require `"CHUNK"`, read 4-char tag, pack BE FOURCC.
4. Restore cursor window + pending string.
5. Return tag dword (0 if fail / other mode).

### Primary use

Unserialize loops (`effEffect_Unserialize`, `phyBoneSharedData_unserialize`, mesh/chunk walkers) branch on upcoming tags (`'PARM'`, etc.) before a real `OpenChunk`.

**Not** `stoChunkReader_OpenChunk` (consumes; this in **ECX**).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076a900_FUN_0076a900.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0076a900_FUN_0076a900.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_PeekChunkTag.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076a900_stoChunkReader_PeekChunkTag.md` |
| Live Ghidra | `decompile_function` `0x0076a900`; `analyze_function_complete`; `read_memory` body span; sites `0x00970350`, `0x00437b00` |
| Sibling | dual `stoChunkReader_OpenChunk` `0x0076a2c0` |
| Ring helper | decompile `FUN_00436220` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// this in ESI; 0 stack args; plain RET; EAX = FOURCC or 0
uint32_t stoChunkReader_PeekChunkTag(void *self /* ESI */);
```

| Item | Evidence |
|---|---|
| this = ESI | prologue `mov ebp,[esi+0x1c]`; callers `mov esi, edi` before CALL |
| 0 stack args | epilogue `add esp,0x4c; ret` (no `ret n`) |
| return tag | `mov eax, local_tag`; sites `cmp eax, 'PARM'` |
| mode gate | `mov eax,[esi+0x4044]; sub eax,0 / jz binary; dec / jnz skip text` |

**Decompiler trap:** `unaff_ESI` — not missing this; custom register this.

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Save cursor + pending copy | **Yes** |
| Mode 0 OpenChunk + ring tag + nest-- | **Yes** |
| Mode 1 CHUNK + 4-char pack | **Yes** |
| Cursor restore to saved abs | **Yes** |
| Restore pending + return tag | **Yes** |
| No permanent consume | **Yes** (restore + nest undo) |

**Body:** 458 B through final `C3` (hex in raw append).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Peek (non-destructive) | **High** | save/restore + nest-- |
| ESI this ABI | **High** | bytes + callers |
| Mode 0/1 paths | **High** | decompile ≡ bytes |
| FOURCC return | **High** | `'PARM'` site |
| Product name string | **Probable** | no plate |
| Full ring undo vs depth-only | **Probable** | nest fields sealed; storage free open |
| Text endian pack | **High** at byte ops / **Probable** vs all binary LE tags |

---

## 6. Gaps / open

1. Plate / PDB English name.
2. Whether nest-- fully pops ring storage or only depth.
3. `FUN_00767840` / `FUN_00769b70` product names.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF/ABI/peek contract High; nested product names + full ring identity open.
