# Review B (skeptical / adversarial): `aa_0074ac40` gfxGeometryPiece_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ac40` |
| **VA** | `0x0074ac40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0074ac40_gfxGeometryPiece_Serialize.md` |
| **System** | `graphics / gfx` |
| **Verdict** | **accept-with-gaps** on CF/chunk tags; **needs-more-evidence** on morph body + scalar field map |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | “Just writes vertices” / no container chunk | Entry must call BeginChunk with concrete tag | **Falsified** — `push 10; push 0x47504345 ('ECPG')` then `stoChunkWriter_BeginChunk` |
| 2 | Chunk version arbitrary / v1 | Version immediate | **Falsified** — version **10** hard-coded |
| 3 | Effect always written as free-form blob | Separate EFCT subtree | **Falsified** — `FUN_0096f890` opens `0x45464354` v3 |
| 4 | Index/vertex always present | Null checks | **Falsified** — null `this+0x0c` / `this+0x14` → status `1` skip, not crash |
| 5 | Single vertex path | Morph branch | **Falsified** — `this+0x1c != 0` takes multi-helper morph path and **forces** vertex status `1` without `gfxVertexBufferImpl_Serialize` |
| 6 | BBOX is free floats in GPCE payload | Nested chunk | **Falsified** — `FUN_0074bda0` BeginChunk `0x42424f58` v2 |
| 7 | USDA is free-form trailer only when LOD set | Always called | **Partially attacked** — `FUN_00748800` **always** BeginChunk USDA; empty vector still emits empty USDA v1 |
| 8 | “LODLevel” key proven in this function | Plate comment only | **Overstated if claimed sealed here** — key name lives in USDA data / writer of pairs, not in this VA’s immediates |
| 9 | Clean plate modernizes order | Diff vs raw | **Falsified** — clean mirrors raw (extra blank lines only) |
| 10 | Return is success bool 0/1 | OR of many statuses | **Falsified** — multi-term `\|` of status words |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| GPCE tag + version 10 | **High** | Wrong root chunk → loaders reject mesh |
| Child order: effect byte → EFCT → INDX → VERT → (vfunc) → BBOX → strings/scalars → USDA | **High** | Sibling order breaks Unserialize pair |
| INDX/VERT null skip = status 1 | **High** | Spurious hard fail on empty piece |
| Morph path skips `gfxVertexBufferImpl_Serialize` | **High** CF | Wrong if AutoCore always emits VERT child |
| Has-effect from `(this+0xbc)>>6&1` | **High** (asm) | Wrong flag → missing/extra effect path on loaders that key off byte |
| Three string slots + empty fallback | **High** offsets | Corrupt name table |
| Binary vs text writer mode `param_2[7]` | **High** | Text/binary format desync |
| Morph helper semantics | **Tentative** | Bad morph export if reimplemented |
| EAX scalar field identities | **Tentative** | Wrong float/int interleave vs Unserialize |
| Plate “exactly one VERT+INDX per piece” | **Probable** (sibling contract) | Not enforced inside this function when nulls skip |

---

## 3. Cross-check against raw / memory

```
// Entry (read_memory 0x0074ac40):
//   6a 0a          push 10
//   68 45 43 50 47 push 'ECPG'  ; 0x47504345 GPCE
//   call stoChunkWriter_BeginChunk

// Has-effect (read_memory 0x0074ac70 region):
//   mov eax, [ebx+0xbc]
//   shr eax, 6
//   and al, 1
//   → FUN_004399a0 (1-byte write)

// EFCT:
//   lea ecx, [ebx+0x20] → FUN_0096f890 → BeginChunk(0x45464354, 3)

// BBOX callee 0x0074bda0: BeginChunk(0x42424f58, 2)
// USDA callee 0x00748800: BeginChunk(0x55534441, 1); pairs [this+0x9c, this+0xa0)

// Strings: this+0x58 / +0x90 / +0x94; null → PTR empty ""
// DAT_00a9d6f8 = "%s"; DAT_00a97b84 = "\r\n"

// Return: OR of all collected writer statuses after EndChunk
```

Decompiler warnings (unreachable `0x0074ad67/ad81/ad87`) are SEH/morph cleanup noise — **do not** invent extra branches from them.

Callers (xrefs): `FUN_00739a60`, `FUN_00999040` — both serialize larger gfx trees and pass the same writer; confirms this is a **piece child emitter**, not a free-standing file root.

---

## 4. Surviving contract for AutoCore

```
gfxGeometryPiece_Serialize(piece, writer) -> status_or:
  BeginChunk(GPCE / 0x47504345, version=10)
  write u8 hasEffect = (piece.flags0xbc >> 6) & 1
  serialize EFCT v3 from piece.effect @ +0x20   // FUN_0096f890
  if piece.index @ +0x0c:  serialize INDX else status |= 1
  if piece.morph @ +0x1c:
      morph-export path (helpers; do not call plain VERT serialize)
      status_vert = 1
  else if piece.vertex @ +0x14:
      gfxVertexBufferImpl_Serialize(writer)
  else status_vert = 1
  if (piece.flags0xbc & 1): piece.vtbl[+0x5c]()
  serialize BBOX v2                                 // FUN_0074bda0
  writeString(+0x58); write u32/f32 tail helpers
  writeString(+0x90); writeString(+0x94)
  serialize USDA v1 from keyvals [+0x9c,+0xa0)      // FUN_00748800
  write remaining u32/f32 helpers
  EndChunk
  return OR(all writer statuses)

Pair with gfxGeometryPiece_Unserialize (0x0074af60) before claiming bit-exact.
Do not invent LODLevel string inside this VA — emit USDA pairs as stored.
Do not require VERT/INDX children when pointers null (status 1 is success-ish skip).
```

---

## 5. What would falsify this dual

1. Entry immediates not `10` / `0x47504345` on a different build.
2. Unserialize sibling reading a different child order or version.
3. Evidence that morph path still emits a VERT chunk via an un-decompiled helper (would overturn “forces uVar5=1 without VERT serialize”).
4. `param_2[7]` mode meaning inverted vs other sto writers (would break string dual-path).

None of (1)–(2) observed on live Ghidra autoassault.exe decompile 2026-07-29.

---

## 6. Open questions

1. Seal morph-path helpers under their own duals if AutoCore must emit morph pieces.
2. Recover EAX sources for `FUN_00439810`/`FUN_00439870` (dataflow / Unserialize dual).
3. Map full `+0xbc` flag bitfield (has-effect bit6 vs vfunc bit0).
4. Golden GPCE hex from shipped assets vs this writer.
5. Rename residual `FUN_*` in clean plate only after callee duals land (not this task).

**Verdict:** **accept-with-gaps** on CF, GPCE/EFCT/BBOX/USDA tags, and major offsets; **needs-more-evidence** before claiming morph-complete or scalar-field-complete emit.
