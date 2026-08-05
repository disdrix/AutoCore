# Review B (skeptical / adversarial): `aa_0076a900` stoChunkReader_PeekChunkTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076a900_stoChunkReader_PeekChunkTag.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `stoChunkReader_OpenChunk` | OpenChunk consumes + returns 0/−1; this restores cursor and returns tag | **Falsified** merge |
| 2 | this in ECX like OpenChunk | Prologue uses **ESI** immediately; sites `mov esi, reader` | **Falsified** |
| 3 | Always parses text `CHUNK` | Binary path (`+0x4044==0`) never compares `"CHUNK"` | **Falsified** |
| 4 | Mode gate is non-zero = text (OpenChunk plate) | Body requires **exactly 1** for text; other non-zero → tag 0 | **Partial** — stricter than OpenChunk |
| 5 | Destructive open | Cursor restore + nest decrement after OpenChunk | **Falsified** as durable consume |
| 6 | Returns success bool | Callers `cmp eax, 'PARM'` / use as FOURCC key | **Falsified** bool |
| 7 | Tag is always LE memory dword | Text path byte-reverses into register FOURCC | **Survives** as pack; binary is `*slot` |
| 8 | No string side effects | Saves/restores `+0x404c` pending | **Falsified** “no string touch” |
| 9 | Scaffold name implies massage-machine-only | 11 callers across effect/physics/chunk | **Falsified** narrow ownership |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches 2026-07-23 raw control flow. `read_memory` prologue shows ESI field loads; epilogue `add esp,0x4c; ret`. Callers (11) / xrefs (18) match analysis API. `FUN_00436220` confirms ring slot → tag dword load.

---

## 3. Surviving contract

```
// this = ESI
// save cursor = +0x1c + +0x18; save pending +0x404c
// if mode+0x4044==0: OpenChunk; tag=*RingTop(); nest--
// else if mode==1: require "CHUNK"; read 4-char tag; pack BE FOURCC
// restore cursor window; restore pending
// return tag (0 on fail)
```

**Gaps kept:** product name; nest vs full ring pop; text/binary tag endian equivalence at runtime; callee English names.

**Verdict:** **accept-with-gaps**.
